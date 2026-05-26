# Shaiya — Chat nativo (RE)

Mapeamento do fluxo de chat stock **cliente ↔ servidor**: código decompilado (Ghidra), manifestos de endereços e tabela de opcodes.

| Alvo | Funções |
|------|---------|
| `Game.exe` | 131 |
| `ps_game.exe` | 114 |

## Comece aqui

**[`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)** — opcodes, handlers, vtables, VAs e caminhos dos `.c`.

**[`PACKET_SPEC.md`](PACKET_SPEC.md)** — layouts wire (send/recv), validação server, envelope TCP.

## Pastas

| Pasta | Conteúdo |
|-------|----------|
| [`game-chat-native/`](game-chat-native/) | Cliente — `.c` decompilados + README |
| `psgame-chat-native/` | Servidor — `.c` decompilados |
| `tools/ghidra/` | Manifests + scripts para regenerar exports |

Contribuições e validações são bem-vindas.
