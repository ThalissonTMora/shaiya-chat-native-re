# Admin whisper bind — `0xF107` / `0xF109` (server → client)

Binary: `ps_game.exe` MD5 `91b212afbe6623382713772489dc82ce` · ImageBase `0x00400000`.

**Direction:** stock `Game.exe` has **recv handlers only** (no `mov $0xF107` / `$0xF109` in `.text`). Outbound opcodes below are **server-only** (`objdump` on `bin/ps_game.exe` finds exactly two opcode loads: `0x4803C7`, `0x47F390`). Inbound admin bind/clear is handled in `AdminChat_ProcessIncoming` @ `0x0047FD10` (C→S).

---

## Wire layout (S→C) — CONFIRMED

Both opcodes share pattern **H** (name-only):

```
+0x00  u16  opcode (0xF107 bind · 0xF109 clear)
+0x02  char[21] name    // null-terminated copy from CUser+0x184; fixed 21 B region on wire
```

| Field | Size | Notes |
|-------|------|-------|
| Plaintext size | **0x17** (23) | `push 0x17` before every `SConnection_Send` @ `0x004ED0E0` |
| `name` | 21 | `do/while` copy until `'\0'` — same idiom as guild broadcast; no tail `memset` |

Client recv: `Handler_Chat_Admin_F107` @ `0x005DE950` / `F109` @ `0x005DE9B0` → `PacketRead_String(..., 0x15)` → vfn `+0x344` / `+0x348` @ **`0x0056BCB0`** (`ret 4` stub — no UI).

---

## CUser state — CONFIRMED

| Offset | Type | Role |
|--------|------|------|
| `+0x5810` | `u32` | Admin **whisper-bind target id** — set to resolved target `CUser+0x128`; cleared to `0` on F109 |
| `+0x128` | `u32` | Character/session id used for bind comparison and `World_FindUserById` @ `0x00414D10` (F108 relay) |
| `+0x184` | `char[]` | Character display name (source for wire `name[21]`) |

---

## C→S — admin commands (server recv)

### `0xF107` — bind whisper target by name

Handler: `AdminChat_ProcessIncoming` case @ asm **`0x0048038E`** (`AdminChat_ProcessIncoming_0047fd10.c` L241–271).

```
AdminChat_ProcessIncoming (CUser* admin, u16* packet)
  ├─ movb $0, packet+0x16          @ 0x00480391  (clear last byte of name region)
  ├─ World_FindUserByName @ 0x00414D40  (name @ packet+0x02)
  ├─ if not found → SConnection_Send opcode 0x1106, size 3, to admin
  └─ if admin+0x5810 != target+0x128:
        ├─ if admin+0x5810 != 0 → Chat_AdminWhisperHelper @ 0x0047F350  (pre-clear)
        ├─ admin+0x5810 = target+0x128
        ├─ build F107 + admin name → SConnection_Send(..., 0x17) to **target** (ecx=target CUser)
        └─ build F107 + target name → SConnection_Send(..., 0x17) to **admin** (ecx=admin CUser)
```

### `0xF109` — clear bind

Handler: case @ **`0x004803??`** / decomp L317–318 — **no extra payload read**; calls `Chat_AdminWhisperHelper` only.

---

## S→C send sites — CONFIRMED (`objdump`)

| Opcode | VA | Function | Recipients |
|--------|-----|----------|------------|
| `0xF107` | `0x004803C7` | `AdminChat_ProcessIncoming` | Dual: target then admin (see asm `0x00480406` / `0x00480436`) |
| `0xF109` | `0x0047F390` | `Chat_AdminWhisperHelper` @ `0x0047F350` | Dual: bound user then admin (`0x0047F3B9` / `0x0047F3E3`) |

### `Chat_AdminWhisperHelper` @ `0x0047F350`

```
if (admin+0x5810 == 0) return
bound = World_FindUserById(admin+0x5810) @ 0x00415480
admin+0x5810 = 0
if (bound == 0) return
build F109 + admin name  → SConnection_Send(bound, 0x17)
build F109 + bound name  → SConnection_Send(admin, 0x17)
```

Evidence: `psgame-chat-native/handlers/Chat_AdminWhisperHelper_0047f350.c` · asm `0x0047F350`–`0x0047F3F7`.

---

## Client recv — CONFIRMED no side effects beyond packet consume

| Handler | VA | Sequence |
|---------|-----|----------|
| F107 | `0x005DE950` | zero stack · `PacketRead_String` 0x15 · `call [vtable+0x344]` |
| F109 | `0x005DE9B0` | same · `call [vtable+0x348]` |

Asm: `objdump -d --start-address=0x5de950 --stop-address=0x5dea10 bin/Game.exe`

- **No** write to chat window `+0x198` (`ChatWindow_SetWhisperTarget` @ `0x0047C690` is UI-only, not called from handlers).
- **No** global mutation in handler bodies.
- vfn @ `0x0056BCB0`: `ret 4` only.

Whisper target UI on client is driven locally via `ChatWindow_SetWhisperTarget` / `PacketSend_Whisper` (`+0x198`), **not** by S→C F107/F109 on stock client.

---

## Reproduce

```bash
# Server outbound opcode sites (expect exactly 2 hits)
objdump -d bin/ps_game.exe | grep -E 'mov.*\$0xf107|mov.*\$0xf109'

# Server F107 dual-send tail
objdump -d --start-address=0x4803c0 --stop-address=0x480440 bin/ps_game.exe

# Client handlers + stub vfn
objdump -d --start-address=0x5de950 --stop-address=0x5dea10 bin/Game.exe
objdump -d --start-address=0x56bcb0 --stop-address=0x56bcc0 bin/Game.exe
```
