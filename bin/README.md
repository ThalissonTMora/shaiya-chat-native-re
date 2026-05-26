# Binaries (`bin/`)

**Shaiya Core V9 support** — these executables are **versioned in git** for reproducible Ghidra exports and MD5 verification.

| File | Role | MD5 |
|------|------|-----|
| `Game.exe` | Client | `c1edd96639ad81835624b9c4516ac781` |
| `ps_game.exe` | World server | `91b212afbe6623382713772489dc82ce` |
| `ps_login.exe` | Login server (outbound `0xA101`) | `de5b348cca36e0585f06be93f013fa6d` |

When replacing builds from a newer **Shaiya Core V9** tree, overwrite these files and update the MD5 table here and in [`../docs/BINARIES.md`](../docs/BINARIES.md).

Verify after update:

```bash
md5sum bin/Game.exe bin/ps_game.exe bin/ps_login.exe
```

Ghidra scripts read directly from `bin/`. See [`../docs/GHIDRA.md`](../docs/GHIDRA.md).
