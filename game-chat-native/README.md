# Cliente — `Game.exe`

Código decompilado Ghidra do chat nativo do cliente. **131** funções.

| Campo | Valor |
|-------|-------|
| MD5 | `c1edd96639ad81835624b9c4516ac781` |
| ImageBase | `0x00400000` |
| Manifesto | [`game-chat-functions.manifest`](game-chat-functions.manifest) |

## Referência

Tabela de opcodes, handlers, vtables e caminhos dos `.c`:

**[`../CHAT_CHANNEL_MAP.md`](../CHAT_CHANNEL_MAP.md)**

## Pastas

| Pasta | Conteúdo |
|-------|----------|
| `send/` | `NetworkSend`, `PacketSend_*` |
| `recv/` | `PacketDispatcher`, decrypt, socket |
| `handlers/` | Handlers recv `0x11xx` |
| `vtable/` | Métodos virtuais do singleton chat |
| `ui/` | Render, input, DrawText |
| `buffer/` | ChatBox, formatação de linhas |
| `balloon/` | Balão de fala 3D (`entity+0x288`) |
| `hooks/` | Landmarks para hooks (hide-native) |

Não editar os `.c` manualmente — regenerar com `../tools/ghidra/decompile-game-chat.sh`.
