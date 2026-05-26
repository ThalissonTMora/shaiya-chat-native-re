# Ghidra — native chat code export

**Always keep server and client separate.**

| Script | Binary (`bin/`) | Output |
|--------|-------------------|--------|
| `./decompile-psgame-chat.sh` | `ps_game.exe` | `psgame-chat-native/` |
| `./decompile-game-chat.sh` | `Game.exe` | `game-chat-native/` |
| `./decompile-crypto.sh` | both | `*/crypto/` subset |

## Prerequisites (`~/tools`)

- JDK 21: `~/tools/jdk-21.0.6+7`
- Ghidra 11.2.1: `~/tools/ghidra_11.2.1_PUBLIC`

```bash
export JAVA_HOME=~/tools/jdk-21.0.6+7
export GHIDRA_HOME=~/tools/ghidra_11.2.1_PUBLIC
```

## Adding functions

Edit the matching manifest (`psgame-chat-functions.manifest` or `game-chat-functions.manifest`):

```
category	SymbolName	0x0047F400
```

Re-run the export script.

## Rules

- **Never** mix `.c` files from `ps_game.exe` and `Game.exe` in the same folder.
- Headers in `.c` files identify binary + MD5 (via `# binary=...` line in the manifest).
