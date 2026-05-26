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

## 3. `char[21]` padding (`0x1104` guild) — P0-1

**Goal:** CONFIRM or reject HYPOTHESIS in `CHAT_RE_GAPS.md` (bytes after first `NUL` in name field).

**Steps:**

1. Two accounts in same guild; sender posts one message with a **short name** (e.g. 3 chars) so `strlen(name) << 21`.
2. Capture **server → client** `0x1104` (Pattern B: `opcode` · `name[21]` · `u8 len` · `text`).
3. Hexdump offset `+2` for **21 bytes**; label bytes `[strlen..20]`.

| Outcome | Label |
|---------|--------|
| All zeros after `NUL` | CONFIRMED zero-fill |
| Stack garbage / non-zero | CONFIRMED junk — emulator must zero-fill on send |
| Mixed across sessions | Document per build |

**Server build evidence (static):** `Chat_BroadcastGuild` @ `0x00432530` null-terminates into stack `char[21]`; does not memset tail — padding on wire is **HYPOTHESIS** until capture.

**Client read:** `PacketRead_String` @ `0x005F4780` always reads **21** bytes (`0x15`) — trailing garbage affects UI if not stripped in vtable.

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

| Direction | Layout | Notes |
|-----------|--------|-------|
| C→S | `u16` · `target[21]` @ `+0x02` · `u8 len` @ `+0x17` · text | `PacketSend_Whisper` @ `0x005ED160` |
| S→C | Pattern **C**: `u8 dir` · `char[21]` · `u8 len` · text | Server patch + dual `SConnection_Send` @ `0x0047F400` |

Server clears **wire offset `0x16`** before forward (Ghidra: `*(unaff_EBX+0xb)=0` as `u16*` index → byte **22** / **`0x16`**). See `CHAT_RE_GAPS.md` § whisper.

Capture: one whisper A→B; expect **two** S→C `0x1102` (target `dir=0`, sender echo `dir=1`).

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
