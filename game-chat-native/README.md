# Client — `Game.exe`

Ghidra-decompiled native chat code for the client. **131** functions (+ 7 crypto in `crypto/`).

| Field | Value |
|-------|-------|
| MD5 | `c1edd96639ad81835624b9c4516ac781` |
| ImageBase | `0x00400000` |
| Manifest | [`game-chat-functions.manifest`](game-chat-functions.manifest) |

## Reference

Opcode table, handlers, vtables, and `.c` paths:

**[`../CHAT_CHANNEL_MAP.md`](../CHAT_CHANNEL_MAP.md)**

## Folders

| Folder | Contents |
|--------|----------|
| `send/` | `NetworkSend`, `PacketSend_*` |
| `recv/` | `PacketDispatcher`, decrypt, socket |
| `handlers/` | Recv handlers `0x11xx` |
| `vtable/` | Virtual methods on chat singleton |
| `ui/` | Render, input, DrawText |
| `buffer/` | ChatBox, line formatting |
| `balloon/` | 3D speech balloon (`entity+0x288`) |
| `crypto/` | Wire encryption / AES-CTR |
| `hooks/` | Landmarks for hooks (hide-native) |

Do not edit `.c` files manually — regenerate with `../tools/ghidra/decompile-game-chat.sh`.
