# Binaries (`bin/` — not versioned)

**Shaiya Core V9 support.** The executables under [`bin/`](../bin/) are **versioned in git** (see [`bin/README.md`](../bin/README.md)).

Use these files to regenerate `.c` exports with Ghidra:

| File | Expected MD5 |
|------|--------------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` |
| `ps_login.exe` | `de5b348cca36e0585f06be93f013fa6d` |

Replace from a local Shaiya Core V9 build when upgrading:

```
.features/Shaiya-Core-V9/Game.exe           → bin/Game.exe
.features/Shaiya-Core-V9/server/ps_game.exe → bin/ps_game.exe
.features/Shaiya-Core-V9/server/ps_login.exe → bin/ps_login.exe
```

Regenerate exports — see [`GHIDRA.md`](GHIDRA.md).
