# Binaries (`bin/`)

The files in [`bin/`](../bin/) are the **Shaiya Core V9** executables used for Ghidra decompilation in this repo. They are versioned in git (see [`bin/README.md`](../bin/README.md)).

Built from the [Shaiya-Core](https://github.com/Spelunkern/Shaiya-Core/) distribution (`Game.exe`, `ps_game.exe`, `ps_login.exe`).

| File | Role | MD5 |
|------|------|-----|
| `Game.exe` | Client | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | World server | `91b212afbe6623382713772489dc82ce` |
| `ps_login.exe` | Login server (outbound `0xA101`) | `de5b348cca36e0585f06be93f013fa6d` |

Regenerate `.c` exports — see [`GHIDRA.md`](GHIDRA.md).
