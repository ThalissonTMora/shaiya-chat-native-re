# Decompiled native code — SERVER (`ps_game.exe`)

Literal Ghidra export. **Do not edit** `.c` files — regenerate with the script.

| Field | Value |
|-------|-------|
| Binary | `server/ps_game.exe` |
| MD5 | `91b212afbe6623382713772489dc82ce` |
| ImageBase | `0x00400000` |
| VAs | `Shaiya-Core-v1/sdev/include/shaiya/PsGameChatAddresses.h` |
| Client (separate) | [`../game-chat-native/`](../game-chat-native/) |

## Regenerate

```bash
cd shaiya-chat-native-re
./tools/ghidra/decompile-psgame-chat.sh
```

Manifest: [`psgame-chat-functions.manifest`](psgame-chat-functions.manifest) *(local copy; canonical in `tools/ghidra/`)*

## Folders

| Folder | Contents |
|--------|----------|
| `pipeline/` | Recv → dispatch |
| `handlers/` | Chat_ProcessIncoming, admin, F502, GameLog |
| `broadcast/` | Normal, shout, trade, guild, party, zone |
| `spatial/` | CCell, radius, distance |
| `queue/` | Async queue, modes 1–5 |
| `lookup/` | FindUserById/Name |
| `network/` | SConnection_Send, encrypt outbound |
| `crypto/` | Wire encryption / AES-CTR |
| `megaphone/` | ItemUseNSend |
| `party/` | CParty lock |
| `util/` | String copy |
| `hooks/` | Genesis dispatch hooks (ZoneEnter/Leave) |

Convention: `Symbol_0047f400.c`
