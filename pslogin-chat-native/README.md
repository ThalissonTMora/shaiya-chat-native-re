# ps_login.exe — key handshake exports

Ghidra decompilations for the **login server** path that sends client recv **`0xA101`** (not `ps_game.exe`).

| Binary | MD5 | ImageBase |
|--------|-----|-----------|
| `ps_login.exe` | `de5b348cca36e0585f06be93f013fa6d` | `0x00400000` |

Binary: symlink `../bin/ps_login.exe` (not versioned).

Regenerate: `../tools/ghidra/decompile-pslogin-crypto.sh`  
Manifest: [`pslogin-crypto-functions.manifest`](pslogin-crypto-functions.manifest)

See also: [`../docs/SERVER_KEY_BLOB_RE.md`](../docs/SERVER_KEY_BLOB_RE.md)
