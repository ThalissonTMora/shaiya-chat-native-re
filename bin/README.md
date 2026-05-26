# Binaries (local — not versioned)

Place target executables here to regenerate `.c` files with Ghidra:

| File | Expected MD5 |
|------|--------------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` |
| `ps_login.exe` | `de5b348cca36e0585f06be93f013fa6d` |

Then run:

```bash
./tools/ghidra/decompile-game-chat.sh
./tools/ghidra/decompile-psgame-chat.sh
./tools/ghidra/decompile-pslogin-crypto.sh
```
