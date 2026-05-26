# Binaries (`bin/` — not versioned)

Place symlinks or copies here to regenerate `.c` files with Ghidra:

| File | Expected MD5 |
|------|--------------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` |
| `ps_login.exe` | `de5b348cca36e0585f06be93f013fa6d` |

Typical layout (from Paradise tree):

```
bin/Game.exe      → .features/Shaiya-Core-V7/Game.exe
bin/ps_game.exe   → .features/Shaiya-Core-V7/server/ps_game.exe
bin/ps_login.exe  → .features/Shaiya-Core-V7/server/ps_login.exe
```

Regenerate exports — see [`GHIDRA.md`](GHIDRA.md).
