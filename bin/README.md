# Binários (local — não versionados)

Coloque aqui os executáveis alvo para regenerar os `.c` com Ghidra:

| Arquivo | MD5 esperado |
|---------|--------------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` |

Depois:

```bash
./tools/ghidra/decompile-game-chat.sh
./tools/ghidra/decompile-psgame-chat.sh
```
