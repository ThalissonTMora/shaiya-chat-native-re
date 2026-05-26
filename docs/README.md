# Documentation index

All project markdown lives in **`docs/`**. The repo root [`README.md`](../README.md) is a short entry point.

## Specs (start here)

| Doc | Contents |
|-----|----------|
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Opcodes, handlers, vtables, VAs, `.c` paths (client + server) |
| [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) | Lacunas chat 100%, roadmap P0/P1/P2 |
| [`PACKET_SPEC.md`](PACKET_SPEC.md) | Wire layouts (send/recv), validation, TCP envelope |
| [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) | AES-CTR, handshake `0xA101`/`0xA102`, encrypted pipeline |
| [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) | Receitas Wireshark/x64dbg: `char[21]` padding, push `0x1109`–`0x110B` |
| [`CHAR21_SITES.md`](CHAR21_SITES.md) | Inventário estático de todos os sites `char[21]` (send/recv/admin) |
| [`SCRIPT_OPCODE_HASHES.md`](SCRIPT_OPCODE_HASHES.md) | `Script_OpcodeDispatch` hashes → builders `0x1109`–`0x110B` |
| [`ZONECHAT_MESSAGE_TABLE.md`](ZONECHAT_MESSAGE_TABLE.md) | `cn_string.DB` → `std::map` · resolver `0x1109`/`0x110A` |
| [`PADDING_SIMULATION.md`](PADDING_SIMULATION.md) | Pattern B tail + `tools/padding/*.py` |

## Deep-dive RE

| Doc | Contents |
|-----|----------|
| [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) | Client `0xA101` body → HMAC → `ctx+0xF4` counter |
| [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md) | Outbound `0xA101` on `ps_login.exe` (not `ps_game.exe`) |
| [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) | Lacunas chat + roadmap P0/P1/P2 (atualizado) |

## Tooling

| Doc | Contents |
|-----|----------|
| [`GHIDRA.md`](GHIDRA.md) | Decompile scripts, manifests, prerequisites |
| [`BINARIES.md`](BINARIES.md) | Shaiya Core V9 executables in `bin/` (MD5 table) |
| [`../bin/README.md`](../bin/README.md) | Same — versioned `bin/*.exe` |
| [`../tools/padding/`](../tools/padding/) | Pattern B packet builders / send-site scan |
| [`../tools/zonechat/parse_cn_string_db.py`](../tools/zonechat/parse_cn_string_db.py) | Parser `data/cn_string.DB` (when available) |
| [`../psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md`](../psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md) | Admin whisper bind/clear wire |

## Decompiled corpora (`.c` only)

| Folder | Binary |
|--------|--------|
| [`../game-chat-native/`](../game-chat-native/) | `Game.exe` — client chat + crypto |
| [`../psgame-chat-native/`](../psgame-chat-native/) | `ps_game.exe` — world server |
| [`../pslogin-chat-native/`](../pslogin-chat-native/) | `ps_login.exe` — login key handshake |

Each corpus folder has a minimal README pointing back here.
