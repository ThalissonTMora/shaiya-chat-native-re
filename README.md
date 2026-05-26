# Shaiya — Chat nativo (RE)

Mapeamento do fluxo de chat stock **cliente ↔ servidor**: código decompilado (Ghidra), manifestos de endereços e tabela de opcodes.

| Alvo | Funções |
|------|---------|
| `Game.exe` | 131 |
| `ps_game.exe` | 114 |

## Comece aqui

**[`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)** — opcodes, handlers, vtables, VAs e caminhos dos `.c`.

## Pastas

| Pasta | Conteúdo |
|-------|----------|
| `game-chat-native/` | Cliente — `.c` decompilados |
| `psgame-chat-native/` | Servidor — `.c` decompilados |
| `tools/ghidra/` | Manifests + scripts para regenerar exports |

Contribuições e validações são bem-vindas.
