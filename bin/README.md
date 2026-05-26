# Binaries (`bin/`)

**Shaiya Core V9 support** — this folder holds local symlinks (or copies) to the executables used by the Ghidra export scripts. The `.exe` files themselves are not versioned (see repo `.gitignore`).

## Expected files

| File | Role | Expected MD5 |
|------|------|----------------|
| `Game.exe` | Client | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | World server | `91b212afbe6623382713772489dc82ce` |
| `ps_login.exe` | Login server (outbound `0xA101`) | `de5b348cca36e0585f06be93f013fa6d` |

## Setup (Shaiya Core V9 tree)

From the repo root, point each name at your Core V9 build (adjust the source path if your layout differs):

```bash
cd bin
ln -sf ../../.features/Shaiya-Core-V9/Game.exe Game.exe
ln -sf ../../.features/Shaiya-Core-V9/server/ps_game.exe ps_game.exe
ln -sf ../../.features/Shaiya-Core-V9/server/ps_login.exe ps_login.exe
```

Verify MD5 after linking. Full notes: [`../docs/BINARIES.md`](../docs/BINARIES.md) · Ghidra: [`../docs/GHIDRA.md`](../docs/GHIDRA.md).
