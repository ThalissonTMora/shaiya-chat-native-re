# Admin whisper relay — `0xF108` (C→S, server-only opcode)

Binary: `ps_game.exe` MD5 `91b212afbe6623382713772489dc82ce` · ImageBase `0x00400000`  
Companion: [`psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md`](../psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md) (bind/clear).

**Summary:** `0xF108` is a **C→S-only** admin opcode handled in `AdminChat_ProcessIncoming` @ `0x0047FD10`. It sends whisper **text** to the partner already bound via **`0xF107`** (`CUser+0x5810`). The server **never emits** `0xF108` on the wire; it relays to both parties as S→C **`0xF102`** (Pattern **C**, same as admin whisper). Stock `Game.exe` has **no** recv handler and **no** send site for `0xF108`.

---

## Scope

| Artifact | Range |
|----------|--------|
| Server handler | `AdminChat_ProcessIncoming` case `0xF108` @ asm **`0x00480462`** |
| Jump table | `.text+0x805E4` index **7** → `0x00480462` (opcode − `0xF101`) |
| Dispatch entry | `CUser_DispatchPacket_Main` @ `0x00474940` — `(opcode & 0xFF00) == 0xF100` → `AdminChat_ProcessIncoming` |
| Client | `PacketDispatcher` @ `0x005F1E10` — routes `F101`–`F107`, `F109`, `F10A`; **skips `F108`** |
| Not present | `Chat_ProcessIncoming` @ `0x0047F400` (no `0xF108` case) |

---

## Wire layout

### C→S `0xF108` — Pattern **I** (short admin text)

```
+0x00  u16  opcode (0xF108)
+0x02  u8   msg_len
+0x03  u8   text[msg_len]
```

| Field | Size | Notes |
|-------|------|-------|
| Plaintext size | **`len + 3`** | No target name on wire — partner from `CUser+0x5810` |
| `msg_len` | 1 | **2 ≤ len ≤ 0x80** (128); `len ≤ 1` → silent drop; `len > 0x80` → kick @ `0x004805AF` |

Evidence: `AdminChat_ProcessIncoming_0047fd10.c` L272–316; asm `0x00480470` (`mov 0x2(%ebx),%cl` / `cmp $0x80`) · `0x004804D0` (`push %edi` → `memcpy` from `ebx+3`).

### S→C relay — **`0xF102`** Pattern **C** (not `0xF108`)

Server builds admin whisper recv packets (mirror of `0x1102` / `F102`):

```
+0x00  u16  opcode (0xF102)
+0x02  u8   dir            // 0 = to bound partner; 1 = echo to admin
+0x03  char[21] name       // null-terminated copy from sender CUser+0x184
+0x18  u8   len
+0x19  u8   text[len]
```

| Send | VA | Recipient | `dir` |
|------|-----|-----------|-------|
| 1st | `0x00480497` (`mov $0xF102`) → `SConnection_Send` @ `0x004804FC` | Bound user (`World_FindUserById`) | **0** |
| 2nd | `0x0048054C` (`movb $0x1,0xDE(%esp)`) → `SConnection_Send` @ `0x00480572` | Admin (`this` CUser) | **1** |

Plaintext size each: **`len + 0x19`** (25). Evidence: `add $0x19,%edi` @ `0x004804EC` / `0x00480564`.

**Client recv:** existing `Handler_Chat_Admin_F102` @ `0x005E5920` → vtable `+0x328` case `0` — normal admin whisper UI (SysMsg `0x162` / highlight).

---

## Preconditions & server state

| Offset | Type | Role |
|--------|------|------|
| `CUser+0x5810` | `u32` | Bound partner id — **must be non-zero** (set by C→S `0xF107`) |
| `CUser+0x128` | `u32` | Character/session id stored at bind time |
| `CUser+0x184` | `char[]` | Display name copied into S→C Pattern C |
| `CUser+0x5820` | `u32` | GM monitor session target id — when non-zero and online, enables `Chat_BuildOutgoing_F502` log @ `0x0047F260` |

**Bind workflow (required before F108):**

1. Admin sends C→S **`0xF107`** + `char[21]` target name → server sets `admin+0x5810 = target+0x128`, dual S→C `0xF107` notify.
2. Admin sends C→S **`0xF108`** + text → server relays as dual S→C **`0xF102`**.
3. Admin sends C→S **`0xF109`** (opcode only) → `Chat_AdminWhisperHelper` clears bind, dual S→C `0xF109`.

---

## Call path / packet flow

```
C→S 0xF108 (admin GM client / tool — not stock Game.exe)
  └─ CUser_DispatchPacket_Main @ 0x00474940
       └─ (opcode & 0xFF00 == 0xF100) && CUser+0x1818 != 0
            └─ AdminChat_ProcessIncoming @ 0x0047FD10
                 case 0xF108 @ 0x00480462
                   ├─ if admin+0x5810 == 0  → SConnection_Send 0x1106 size 3 @ 0x00480587
                   ├─ validate 2 ≤ len ≤ 0x80
                   ├─ bound = World_FindUserById @ 0x00414D10(admin+0x5810)
                   ├─ if bound == NULL       → SConnection_Send 0x1106 size 3
                   ├─ build 0xF102 dir=0 + admin name + text → SConnection_Send(bound, len+0x19)
                   ├─ optional Chat_BuildOutgoing_F502 @ 0x0047F260 (monitor)
                   ├─ build 0xF102 dir=1 + bound name + text → SConnection_Send(admin, len+0x19)
                   └─ Chat_LogGameLogA @ 0x0047F0E0(admin, channel=2, text)
```

Compare **`0xF102`** C→S (admin whisper **by name**, same handler family):

```
C→S 0xF102: opcode + target[21] + len + text  → World_FindUserByName @ 0x00414D40
              clears packet+0x16 before lookup (same as 0x1102)
              S→C dual 0xF102 Pattern C
```

Compare **`0x1102`** (normal whisper, `Chat_ProcessIncoming`):

```
C→S 0x1102 → S→C dual 0x1102 Pattern C (not F102)
```

---

## F108 vs F102 vs 0x1102

| Aspect | `0x1102` | `0xF102` | `0xF108` |
|--------|----------|----------|----------|
| Handler | `Chat_ProcessIncoming` | `AdminChat_ProcessIncoming` | `AdminChat_ProcessIncoming` |
| C→S target | `target[21]` on wire | `target[21]` on wire | **None** — uses `+0x5810` bind |
| Lookup | `World_FindUserByName` | `World_FindUserByName` | `World_FindUserById` |
| Requires F107 bind | No | No | **Yes** |
| S→C opcode | `0x1102` | `0xF102` | **`0xF102`** (relay) |
| Client recv | `Handler_ChatWhisper` | `Handler_Chat_Admin_F102` | *(none — server never sends F108)* |
| Client send (stock) | `PacketSend_Whisper` | Admin chat send path | **Absent** |

---

## Client absence — CONFIRMED

| Check | Result |
|-------|--------|
| `PacketDispatcher` @ `0x005F1E10` | Cases `0xF107`, `0xF109`; **no `0xF108`** (`PacketDispatcher_005f1e10.c` L1350–1353) |
| `objdump -d bin/Game.exe \| grep 'mov.*\$0xf108'` | **Zero hits** |
| `objdump -d bin/ps_game.exe \| grep 'mov.*\$0xf108'` | **Zero hits** (recv-only; relay uses `mov $0xF102` @ `0x00480497`) |

**INFERRED:** C→S `0xF108` originates from a **GM/admin tool** (or patched client), not stock `Game.exe`. Emulators must accept F108 on the admin chat path after F107 bind.

---

## Error paths

| Condition | Action | Evidence |
|-----------|--------|----------|
| `admin+0x5810 == 0` | S→C `0x1106` plain size **3** to admin | asm `0x00480587` |
| `World_FindUserById` returns NULL | Same `0x1106` | asm `0x00480491` → `0x00480587` |
| `len > 0x80` | Kick `FUN_004ec760(9,0)` @ `0x004805AF` | shared admin validation |
| `len ≤ 1` | Silent return (no send) | asm `0x0048047F` → `0x004805B9` |

---

## Reproduce

```bash
# F108 case entry (jump table index 7)
objdump -d --start-address=0x480462 --stop-address=0x480590 bin/ps_game.exe

# S→C relay opcode load (F102, not F108)
objdump -d --start-address=0x480490 --stop-address=0x480510 bin/ps_game.exe

# Confirm no F108 mov in either binary
objdump -d bin/ps_game.exe | grep -E 'mov.*\$0xf108'
objdump -d bin/Game.exe    | grep -E 'mov.*\$0xf108'

# Client dispatcher gap (F107 then F109, no F108)
grep -n '0xf10' game-chat-native/recv/PacketDispatcher_005f1e10.c | tail -15
```

---

## Artifacts

| Path | Content |
|------|---------|
| `psgame-chat-native/handlers/AdminChat_ProcessIncoming_0047fd10.c` | Full handler; F108 @ L272–316 |
| `psgame-chat-native/pipeline/CUser_DispatchPacket_Main_00474940.c` | Route `0xF1xx` → admin chat |
| `game-chat-native/handlers/Handler_Chat_Admin_F102_005e5920.c` | Client recv for relayed whisper |
| `psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md` | Bind/clear (`0x5810`) |

---

## Assumptions & limitations

- Decompilation Ghidra 11.2; `FUN_*` names where PDB absent.
- GM tool that emits C→S `0xF108` not present in this repo — send path **HYPOTHESIS** until a capture or second binary is analyzed.
- Monitor log via `Chat_BuildOutgoing_F502` @ `0x0047F260` only when `CUser+0x5820` session is active (same guard as other admin chat opcodes).

---

## Next validation steps

1. Capture C→S `0xF108` from live GM session after F107 bind — confirm plain size `len+3` and no name field.
2. Capture dual S→C `0xF102` with `dir=0/1` immediately after F108 — match Pattern C sizes.
3. Xref binaries outside repo (admin panel, `ps_login`, custom launcher) for `mov $0xF108` send site.
