# Código nativo decompilado — SERVIDOR (`ps_game.exe`)

Export literal Ghidra. **Não editar** os `.c` — regenerar com o script.

| Campo | Valor |
|-------|-------|
| Binário | `server/ps_game.exe` |
| MD5 | `91b212afbe6623382713772489dc82ce` |
| ImageBase | `0x00400000` |
| VAs | `Shaiya-Core-v1/sdev/include/shaiya/PsGameChatAddresses.h` |
| Cliente (separado) | [`../game-chat-native/`](../game-chat-native/) |

## Regenerar

```bash
cd .features/Shaiya-Core-V7
./tools/ghidra/decompile-psgame-chat.sh
```

Manifesto: [`psgame-chat-functions.manifest`](psgame-chat-functions.manifest) *(cópia local; canônico em `tools/ghidra/`)*

## Pastas

| Pasta | Conteúdo |
|-------|----------|
| `pipeline/` | Recv → Dispatch |
| `handlers/` | Chat_ProcessIncoming, admin, F502, GameLog |
| `broadcast/` | Normal, shout, trade, guild, party, zone |
| `spatial/` | CCell, raios, distância |
| `queue/` | Fila async, modes 1–5 |
| `lookup/` | FindUserById/Name |
| `network/` | SConnection_Send |
| `megaphone/` | ItemUseNSend |
| `party/` | CParty lock |
| `util/` | String copy |
| `hooks/` | Genesis dispatch hooks (ZoneEnter/Leave) |

Convenção: `Symbol_0047f400.c`
