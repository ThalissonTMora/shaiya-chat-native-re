# GM Notice Command Mapping & Wire Specifications

During runtime testing, several GM notice commands were executed and validated on the client and server. This document details the mapping, command formats, network opcodes, packet layouts, and dispatching paths.

---

## 1. GM Notice Command Matrix

All GM notice commands are parsed on the client in `GmCommand_Dispatch` (`0x0047FFD0`) after verifying GM privileges.

| Command | Native Alias (KR) | Input Syntax | C→S Opcode | Client Send Function | Target Scope / Effect |
|:---|:---|:---|:---|:---|:---|
| `/gmnotice` | `/운영자공지` | `/gmnotice <msg>` | `0xF906` | `FUN_005EE240` | Global Admin Notice (orange text banner) |
| `/cnotice` | `/챗공지` | `/cnotice <mapId> <msg>` | `0xF907` | `FUN_005EDF70` | Chat-box Notice (specific map) |
| `/wnotice` | `/귓공지` | `/wnotice <player> <msg>` | `0xF908` | `FUN_005EDE90` | Whisper Notice (target individual only) |
| `/notice` | `/공지` | `/notice <mapId> <msg>` | `0xF90B` | `FUN_005EE190` | System Notice Type 0 |
| `/znotice` | `/맵공지` | `/znotice <mapId> <msg>` | `0xF909` | `FUN_005EE020` | Map/Zone Broadcast Notice |
| `/bnotice` | `/종족공지` | `/bnotice <빛|어둠> <mapId> <msg>` | `0xF90A` | `FUN_005EE0D0` | Faction/Union Specific Notice |

*Note: `<mapId>` is an optional integer parameter parsed via `FUN_0047AAF0` which extracts a leading decimal integer from the argument string. If omitted, it defaults to 0.*

---

## 2. Packet Wire Layouts

These packets are sent from the client (`Game.exe`) to the world server (`ps_game.exe`).

### A. Whisper Notice `/wnotice` (`0xF908`)
*Plaintext size:* `0x1A + msg_len`

```
+0x00  u16      opcode = 0xF908
+0x02  char[21] target_player_name (padded, uninitialized tail)
+0x17  u16      unknown (usually 0x0000)
+0x19  u8       msg_len (strlen + 1)
+0x1A  char[]   message_text (null-terminated)
```

### B. Faction Notice `/bnotice` (`0xF90A`)
*Plaintext size:* `0x0E + msg_len`

```
+0x00  u16      opcode = 0xF90A
+0x02  u8       faction_id (0 = 빛 / Light, 1 = 어둠 / Dark)
+0x03  u16      map_id (extracted via FUN_0047AAF0)
+0x05  u8       msg_len
+0x06  char[]   message_text (null-terminated)
```

### C. Standard notices (`0xF906`, `0xF907`, `0xF909`, `0xF90B`)
*Plaintext size:* `0x0D + msg_len` for map-based ones (`0xF907`, `0xF909`, `0xF90B`):

```
+0x00  u16      opcode = 0xF90x
+0x02  u8       unknown_flag (usually 0x00)
+0x03  u16      map_id
+0x05  u8       msg_len
+0x06  char[]   message_text
```

For `/gmnotice` (`0xF906`), map ID is absent:
*Plaintext size:* `0x03 + msg_len`
```
+0x00  u16      opcode = 0xF906
+0x02  u8       msg_len
+0x03  char[]   message_text
```

---

## 3. The `/bnotice` Parser Constraint

The reason `/bnotice` often fails in typical English clients is because **the command parser expects literal Korean faction strings** hardcoded inside `Game.exe` at `.rdata` offsets:

- **`0x0074D6F8`**: `빛` (Light) -> translates to Faction ID `0`
- **`0x0074D6F0`**: `어둠` (Dark) -> translates to Faction ID `1`

### Execution Syntax for `/bnotice`
If your client has these Korean string requirements, you must execute the command as follows (copying the Korean characters directly or using an IME):

```text
/bnotice 빛 0 Mensagem de teste para Aliança da Luz
/bnotice 어둠 0 Mensagem de teste para União das Trevas
```

Executing `/bnotice light` or `/bnotice dark` will result in the client executing error handler `FUN_00423150` and failing to send the packet.

---

## 4. Server-Side Dispatching (`ps_game.exe`)

When a client sends a packet beginning with `0xF900` series opcodes, the server processes it through its packet router.

### Entry Point
- **Main Dispatcher**: Processed inside the packet loop at **`0x0047509F`** via `cmp eax, 0xF900`.
- **Router Function**: Dispatches to router function **`0x00482630`**.

### Router Jump Table
At **`0x004826BA`**, the router utilizes a jump table located at **`0x004833F4`** to route the exact opcode to its respective sub-handler:

| Opcode | Handler VA | Server Behavior & Relaying |
|:---|:---|:---|
| `0xF901` | `0x004826C1` | Target case |
| `0xF902` | `0x004833BE` | Default stub (`ret 4`) |
| `0xF903` | `0x004833BE` | Default stub (`ret 4`) |
| `0xF904` | `0x004828D9` | Admin-level action |
| `0xF905` | `0x00482A37` | Admin-level action |
| `0xF906` | `0x00482E53` | Global `/gmnotice` broadcast |
| `0xF907` | `0x00482EC0` | Map-based `/cnotice` relay |
| `0xF908` | `0x00482FB1` | Whisper `/wnotice` player lookup and target send |
| `0xF909` | `0x004830C7` | Zone `/znotice` broadcast |
| `0xF90A` | `0x004831BD` | Faction-specific `/bnotice` broadcast |
| `0xF90B` | `0x004832C2` | System `/notice` handler |
| `0xF90C` | `0x00482BAA` | Final sub-case |

---

## 5. Potential for Emulator Implementation

Mapping these opcodes allows emulators to support fully-native client-side admin notifications without custom hook overlays.

1. **Relaying `/wnotice` (`0xF908`):** The emulator can intercept `0xF908`, find the player connection, and send the packet back directly to that player.
2. **Faction Notices (`0xF90A`):** Broadcasts notice only to players whose faction matches the faction byte (0 or 1).
3. **Map Notices (`0xF907`, `0xF909`, `0xF90B`):** Broadcasts system messages only to connections located on the targeted map ID.
