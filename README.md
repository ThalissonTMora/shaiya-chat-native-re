# Shaiya — Native Chat (RE)

Stock chat flow mapping **client ↔ server**: Ghidra-decompiled code, address manifests, and opcode tables.

| Target | Functions |
|--------|-----------|
| `Game.exe` | 132 + 11 crypto |
| `ps_game.exe` | 114 + 7 crypto |

## Start here

**[`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)** — opcodes, handlers, vtables, VAs, and `.c` paths.

**[`PACKET_SPEC.md`](PACKET_SPEC.md)** — wire layouts (send/recv), server validation, TCP envelope.

**[`WIRE_CRYPTO.md`](WIRE_CRYPTO.md)** — AES-CTR, handshake, crypto context struct, encrypted send/recv pipeline.

## Folders

| Folder | Contents |
|--------|----------|
| [`game-chat-native/`](game-chat-native/) | Client — decompiled `.c` files + README |
| `psgame-chat-native/` | Server — decompiled `.c` files |
| `tools/ghidra/` | Manifests + scripts (`decompile-*-chat.sh`, `decompile-crypto.sh`) |

Contributions and validations are welcome.
