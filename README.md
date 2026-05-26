# Shaiya — Native Chat (RE)

Stock chat flow mapping **client ↔ server**: decompiled code (Ghidra), address manifests, and opcode table.

| Target | Functions |
|------|---------|
| `Game.exe` | 131 |
| `ps_game.exe` | 114 |

## Start here

**[`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)** — opcodes, handlers, vtables, VAs, and `.c` paths.

**[`PACKET_SPEC.md`](PACKET_SPEC.md)** — wire layouts (send/recv), server validation, TCP envelope.

## Folders

| Folder | Contents |
|-------|----------|
| [`game-chat-native/`](game-chat-native/) | Client — decompiled `.c` files + README |
| `psgame-chat-native/` | Server — decompiled `.c` files |
| `tools/ghidra/` | Manifests + scripts to regenerate exports |

Contributions and validations are welcome.
