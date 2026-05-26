# Login server — `ps_login.exe`

Ghidra exports for the **`0xA101` key-blob send path** (not in `ps_game.exe`). Manifest: [`pslogin-crypto-functions.manifest`](pslogin-crypto-functions.manifest).

| Field | Value |
|-------|-------|
| MD5 | `de5b348cca36e0585f06be93f013fa6d` |
| ImageBase | `0x00400000` |

**Docs:** [`../docs/SERVER_KEY_BLOB_RE.md`](../docs/SERVER_KEY_BLOB_RE.md) · [`../docs/GHIDRA.md`](../docs/GHIDRA.md)

Binary: `../bin/ps_login.exe` (symlink, not versioned).

Regenerate: `../tools/ghidra/decompile-pslogin-crypto.sh`
