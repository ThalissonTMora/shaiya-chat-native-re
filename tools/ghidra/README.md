# Ghidra — export código nativo de chat

**Sempre separar servidor e cliente.**

| Script | Binário (`bin/`) | Saída |
|--------|------------------|-------|
| `./decompile-psgame-chat.sh` | `ps_game.exe` | `psgame-chat-native/` |
| `./decompile-game-chat.sh` | `Game.exe` | `game-chat-native/` |

## Pré-requisitos (`~/tools`)

- JDK 21: `~/tools/jdk-21.0.6+7`
- Ghidra 11.2.1: `~/tools/ghidra_11.2.1_PUBLIC`

```bash
export JAVA_HOME=~/tools/jdk-21.0.6+7
export GHIDRA_HOME=~/tools/ghidra_11.2.1_PUBLIC
```

## Adicionar funções

Edite o manifest correspondente (`psgame-chat-functions.manifest` ou `game-chat-functions.manifest`):

```
categoria	SymbolName	0x0047F400
```

Reexecute o script de export.

## Regra

- **Nunca** misturar `.c` de `ps_game.exe` e `Game.exe` na mesma pasta.
- Headers nos `.c` identificam binário + MD5 (via linha `# binary=...` no manifest).
