# Wire capture guide — chat padding & server push (reproducible recipe)

**No live capture is performed here.** Use this checklist on your own client/server pair with the same binaries as `docs/BINARIES.md`.

Binaries: `Game.exe` `c1edd966…`, `ps_game.exe` `91b212af…` · game port typically **30800/tcp** (confirm in your `server.ini` / client `connect.cfg`).

---

## 1. Prerequisites

| Tool | Role |
|------|------|
| Wireshark / `tcpdump` | TCP payload after game handshake (post-`0xA101` if encryption enabled) |
| x64dbg on `ps_game.exe` or `Game.exe` | Hook plaintext at `SConnection_Send` / recv dispatch |
| Optional Frida / custom DLL | Stable logging of `[opcode, len, hex]` at `0x004ED0E0` |

**Plaintext tap (preferred for chat):** hook **after** `Connection_DecryptInbound` @ `0x00464FA0` (server) or client `PacketPayload_Decrypt` @ `0x00401080`, **before** `Chat_ProcessIncoming` @ `0x0047F400` / client `PacketDispatcher` @ `0x005F1E10`.

---

## 2. BPF / display filter (Wireshark)

Replace `SERVER_IP` and `PORT`:

```text
host SERVER_IP and tcp port PORT
```

After opcode map exists, display filter examples:

```text
tcp.payload[0:2] == 11:04    # guild 0x1104 LE — adjust if framing includes length prefix
```

If a **length-prefixed** outer frame exists (check `SConnection_EnqueueWrite` @ `0x004EF080`), strip that header in a Lua dissector before matching `0x11xx`.

---

## 3. `char[21]` padding — breakpoints & wire offsets (P0)

Tap **plaintext** at `SConnection_Send` @ `0x004ED0E0` (`ps_game.exe`) or after `PacketPayload_Decrypt` @ `0x00401080` (`Game.exe`) on recv. Offsets below = **bytes after `u16` LE opcode** at `payload[0]`.

### 3.1 x64dbg — `SConnection_Send` @ `0x004ED0E0`

```text
bp 004ED0E0
```

On hit (stdcall, 32-bit): `[ESP+4]` = `SConnection*`, `[ESP+8]` = **`payload`**, `[ESP+0xC]` = **`size`**.

Log for pattern match:

```text
?po payload
?po size
?by payload l min(size,40)
```

### 3.2 Fixed field offsets (CONFIRMED from builders/handlers)

| Opcode | Dir | `size` formula | Name region `[start..end]` | Len byte | Text start |
|--------|-----|----------------|----------------------------|----------|------------|
| `0x1104` guild | S→C | `len+0x18` | `payload+2` … `payload+22` (21 B) | `payload+23` (`0x17`) | `payload+24` (`0x18`) |
| `0x1103` trade | S→C | `len+0x18` | `payload+2` … `payload+22` | `payload+23` | `payload+24` |
| `0x1108` megaphone | S→C | `len+0x18` | `payload+2` … `payload+22` | `payload+23` | `payload+24` |
| `0x1111` area | S→C | `len+0x18` | `payload+2` … `payload+22` | `payload+23` | `payload+24` |
| `0x1102` whisper | S→C | `len+0x19` | `payload+3` … `payload+23` (21 B) | `payload+24` (`0x18`) | `payload+25` (`0x19`) |
| `0x1102` whisper | C→S | `len+0x18` | `payload+2` … `payload+22` (`target[21]`) | `payload+23` (`0x17`) | `payload+24` (`0x18`) |
| `0x0812` alliance | S→C | `len+0x1C` | `payload+2` … `payload+22` | `payload+23` | `payload+24`; `guildId` @ `payload+24+len` |

**Guild P0 capture:** break when `*(u16*)payload == 0x1104` and `size == 0x18 + *(payload+23)` (short message, e.g. `len=4` → `size=28`).

**Name-tail HW breakpoint (guild):** `bphws payload+3+strlen(name)`, 1, r (adjust `strlen` at runtime) — fires if anything reads first byte after `NUL` on wire.

**Whisper C→S patch check:** on server `Chat_ProcessIncoming` @ `0x0047F608`, byte `payload+22` (`0x16`) forced to `0` before forward.

### 3.3 Capture validation (P0-1) — padding HYPOTHESIS

1. Two guild chars; short display name (`strlen` 3–5).
2. S→C `0x1104`; hexdump **`payload+2` for 21 bytes**.
3. Classify bytes at indices `strlen(name)+1` … `20`:

| Outcome | Tag |
|---------|-----|
| All `0x00` | **CONFIRMED** zero-fill on wire |
| Non-zero stable garbage | **CONFIRMED** stack junk — zero-fill in emulator |
| Varies per send | **HYPOTHESIS** — log multiple sends |

**Static (CONFIRMED):** `Chat_BroadcastGuild` @ `0x00432530` — null-term copy only; **no** tail `memset` before `call 0x004ED0E0` (`objdump` `0x004325B0`–`0x00432615`). See [`CHAR21_SITES.md`](CHAR21_SITES.md).

**Client read:** `PacketRead_String` @ `0x005F4780` — always **`push 0x15`** in handlers; UI vfn @ `0x0059BDB0` treats name as C-string (stops at first `NUL` in buffer, not on wire).

---

## 4. `0x1109` / `0x110A` / `0x110B` server push

Stock client **kicks** if it sends these (`Chat_ProcessIncoming` default → `SConnection_Close(9,0)` @ `0x0047FC24`). Captures must be **S→C** only.

### 4.1 Trigger in-game

| Opcode | Typical trigger | Builder VA |
|--------|-----------------|------------|
| `0x1109` | NPC/script zone chat | `0x004C6A80` / `0x004C6F50` |
| `0x110A` | Union message id | `0x004C8310` |
| `0x110B` | Channel label on entity | `0x004C8520` |

Script dispatch hub: `0x004A2210` · wrappers `0x004CB3D0` / `0x004CB430` (see `CHAT_CHANNEL_MAP.md` server push table).

### 4.2 Hook `SConnection_Send` @ `0x004ED0E0` (ps_game.exe)

x64dbg (32-bit):

```text
bp 004ED0E0
```

On hit (stdcall):

- `[ESP+4]` = `SConnection*`
- `[ESP+8]` = payload pointer
- `[ESP+0xC]` = **size** (`len+8` for 1109, `8` for 110A, `0x26` for 110B)

Log: `opcode = *(u16*)payload`, `size`, first `min(size,64)` bytes.

**1109 Pattern D (CONFIRMED builder):**

```text
+0x00 u16 opcode 0x1109
+0x02 u8  flag (0 = party path in 1109_A; 1 = spatial in 1109_B)
+0x03 u32 charId
+0x07 u8  len (1..0x7F)
+0x08 u8  text[len]
```

**110A:** `u32 charId` · `u16 message_id` — total **8** bytes payload after opcode.

**110B:** `u32 entity` · `char[32]` label — send size **`0x26`**.

### 4.3 Wireshark correlation

1. Note server port and player session time window.
2. Filter server → client payloads during NPC dialog / union notice.
3. Match opcode + size signature above; save `.pcapng` slice under `captures/` (gitignored) with build MD5 in filename.

---

## 5. Whisper C→S vs S→C (`0x1102`)

| Direction | Layout (after opcode) | `size` | Notes |
|-----------|----------------------|--------|-------|
| C→S | `target[21]` @ `+0x02` · `len` @ `+0x17` · `text` @ `+0x18` | `len+0x18` | `PacketSend_Whisper` @ `0x005ED160` |
| S→C | `dir` @ `+0x02` · `name[21]` @ `+0x03` · `len` @ `+0x18` · `text` @ `+0x19` | `len+0x19` | Dual send @ `0x0047F400` (`0x0047F685`, `0x0047F6F9`) |

**CONFIRMED:** server clears **`payload+0x16`** (last byte of C→S `target[21]`) @ `0x0047F608` before `World_FindUserByName`. C→S text starts @ **`payload+0x18`** (asm `lea 0x18(%ebx)` @ `0x0047F661`).

Capture: one whisper A→B; expect **two** S→C `0x1102` (`dir=0` to target, `dir=1` echo).

---

## 6. Artifact checklist

| Item | Path |
|------|------|
| Opcode tables | `docs/PACKET_SPEC.md`, `docs/CHAT_CHANNEL_MAP.md` |
| Server handler | `psgame-chat-native/handlers/Chat_ProcessIncoming_0047f400.c` |
| Push builders | `psgame-chat-native/send/Chat_PacketBuilder_*.c` |
| Megaphone chain | `psgame-chat-native/broadcast/Chat_BroadcastNamed_chain.md` |
| Regenerate decomps | `./tools/ghidra/decompile-psgame-chat.sh` |

---

## 7. Limitations

- Encrypted sessions: wire bytes are ciphertext unless you use SSLKEYLOG-style key export (not stock) or in-process hooks.
- NAT/port forwarding changes endpoint IPs; BPF must follow the actual TCP stream.
- Script-only opcodes require the right quest/NPC; empty captures usually mean wrong trigger, not wrong VA.
