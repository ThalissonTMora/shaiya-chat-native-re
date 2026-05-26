# Ghidra — native chat code export

**Always keep server, client, and login exports in separate folders.**

| Script | Binary (`bin/`) | Output |
|--------|-----------------|--------|
| `decompile-game-chat.sh` | `Game.exe` | `game-chat-native/` |
| `decompile-psgame-chat.sh` | `ps_game.exe` | `psgame-chat-native/` |
| `decompile-pslogin-crypto.sh` | `ps_login.exe` | `pslogin-chat-native/` |
| `decompile-crypto.sh` | `Game.exe` + `ps_game.exe` | `*/crypto/` subset |

Run from repo root: `./tools/ghidra/<script>.sh`

Binaries: [`BINARIES.md`](BINARIES.md)

## Prerequisites (`~/tools`)

- JDK 21: `~/tools/jdk-21.0.6+7`
- Ghidra 11.2.1: `~/tools/ghidra_11.2.1_PUBLIC`

```bash
export JAVA_HOME=~/tools/jdk-21.0.6+7
export GHIDRA_HOME=~/tools/ghidra_11.2.1_PUBLIC
```

## Adding functions

Edit the matching manifest under `tools/ghidra/`:

```
category	SymbolName	0x0047F400
```

Re-run the export script. A copy is written into the output folder when the script finishes.

## Rules

- **Never** mix `.c` files from different binaries in the same folder.
- Headers in `.c` files identify binary + MD5 (manifest metadata).
- Do not hand-edit generated `.c` — update manifests and regenerate.
