# Packet specification — Shaiya native chat

Companion to [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md). Layouts inferred from decompiled handlers — **do not edit manually**; regenerate `.c` via `tools/ghidra/`.

| Binary | MD5 | ImageBase |
|--------|-----|-----------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` | `0x00400000` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` | `0x00400000` |

**Conventions:** offsets below are **after the `u16` LE opcode**, unless noted. `(?)` = partial inference. LE = little-endian.

---

## 1. TCP envelope (wire)

```
┌──────────────┬─────────────────────────────┐
│ wire_len u16 │  ciphertext (wire_len − 2)    │
│  (= plain+2) │  encrypted opcode + body      │
└──────────────┴─────────────────────────────┘
         │ decrypt (client: PacketPayload_Decrypt @ 401080)
         ▼
┌──────────┬──────────────────┐
│ opcode   │  body (handler)  │
│ u16 LE   │                  │
└──────────┴──────────────────┘
```

| Field | Size | Notes |
|-------|------|-------|
| `wire_len` | 2 | `plaintext_size + 2` |
| ciphertext | `wire_len − 2` | AES-128 CTR-like — see [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) |
| `opcode` | 2 | First plaintext field; routed by `PacketDispatcher` |

**Readers (client):** `PacketRead_Scalar` = memcpy N bytes; `PacketRead_String` = up to N bytes (**no** null on wire).

**Limits:** reader max `0x2000`; server send `< 0x801`.

---

## 2. Client → server (send)

### Common layout (short chat)

```
+0x00  u16  opcode
+0x02  u8   msg_len
+0x03  u8   msg[msg_len]
```

`NetworkSend` takes `msg_len + 3`. Max wire text: **255** bytes (`u8`).

| Opcode | Sender | Channel |
|--------|--------|---------|
| `0x1101` | `PacketSend_Chat(0,0,…)` | Normal |
| `0x1103` | `PacketSend_Chat(0,1,…)` or `PacketSend_Party(0,…)` | Trade/Party send |
| `0x1104` | `PacketSend_Chat(0,2,…)` or `PacketSend_Guild(0,…)` | Guild |
| `0x1105` | `PacketSend_Chat(0,3,…)` | Party |
| `0x1107` | `PacketSend_Chat(0,4,…)` | Shout |
| `0x1111` | `PacketSend_Zone` | Zone/Area |
| `0xF101`–`0xF105` | `PacketSend_Chat(1,…)` / Guild/Party with `param_1!=0` | Admin (+ `0xE000` on opcode) |

### Whisper

```
+0x00  u16  opcode (0x1102 / 0xF102)
+0x02  u8   target[21]     // CONFIRMED: 5×u32 LE + u8 @ PacketSend_Whisper 0x005ED160 (21 B, not length-prefixed)
+0x17  u8   msg_len
+0x18  u8   msg[msg_len]
```

Plaintext size: `msg_len + 0x18` (24).

---

## 3. Server → client (recv) — `0x1101`–`0x110A`

### Wire patterns

| Pattern | Opcodes | Layout after opcode |
|---------|---------|---------------------|
| **A** | `1101`, `1105`, `1107`, `F101` | `u32 id` · `u8 len` · `bytes[len]` |
| **B** | `1103`, `1104`, `1108`, `1111` | `char[21] name` · `u8 len` · `bytes[len]` |
| **C** | `1102` | `u8 dir` · `char[21] name` · `u8 len` · `bytes[len]` |
| **D** | `1109` | `u8 flag` · `u32 id` · `u8 len` · `bytes[len]` |
| **E** | `110A` | `u32 id` · `u16 message_id` (no text — `GetMsg`) |
| **F** | `1106` | `u8 code` (ignored in vtable — fixed SysMsg) |
| **G** | `110B` | `u32 entity` · `char[32] label` (fixed 32 B on wire) |

### Per-channel table

| Opcode | Channel | Payload (after opcode) | UI / effect | Balloon `4126D0` |
|--------|---------|------------------------|-------------|------------------|
| `0x1101` | Normal | A | `DrawText` style `0x22` | **Yes** (cond.) |
| `0x1102` | Whisper | C | `SysMsg` + highlight | No |
| `0x1103` | Trade | B | `SysMsg` | No |
| `0x1104` | Guild | B | `SysMsg` | No |
| `0x1105` | Party | A | `SysMsg` party | No |
| `0x1106` | Error | F | Fixed SysMsg `0x14B` | No |
| `0x1107` | Shout | A | `DrawText` style `0x27` | **Yes** (cond.) |
| `0x1108` | Megaphone | B | `SysMsg` banner `0x1E1` | No |
| `0x1109` | Zone | D | `DrawText` | No |
| `0x110A` | Union | E | `DrawText` + `GetMsg` | No |
| `0x110B` | Channel link | G | Nameplate (`56C650`) | No |

### `0x0502` — entity spawn / state (not chat)

Handler: `Handler_Packet_0502` @ `0x005E0CF0` → vtable `+0xF0` → `ChatEntitySpawn_vfn` @ **`0x00593970`**.

```
+0x00  u8   kind          // entity type / spawn mode
+0x01  u32  field_a
+0x05  u32  field_b
+0x09  u16  field_c
+0x0B  u16  field_d
+0x0D  u16  field_e       // total body = 15 bytes after opcode
```

Effect: resolves entity via world mgr (`0x7C4A68`); may attach FX (`0x459D30`), update `entity+0x1EC..0x1F4`, call `EntityStateRefresh` @ `0x004153C0`. **No chat box.**

Evidence: `game-chat-native/vtable/ChatEntitySpawn_vfn_0xF0_00593970.c`

### `0x00A101` — key material (crypto handshake)

Handler: `Handler_Packet_A101_KeyMaterial` @ `0x005E3D60` → vfn `+0x254` → `Connection_OnKeyMaterial` @ `0x005A4D50` → `Crypto_ProcessKeyPacket` @ `0x401100`.

Routed by `PacketDispatcher` @ `0x5F1E10` (not a separate login socket path).

```
+0x00  u8   field_0    // ctx selector: 0 → recv CounterLoad @ 0x23037F0+0xF4 (CONFIRMED @ 0x40116C)
+0x01  u8   field_1    // block_b slice length → HMAC/ack vector (INFERRED; append @ 0x404F96)
+0x02  u8   field_2    // block_a slice length → ack vector (CONFIRMED @ 0x404F91/0x404FEA)
+0x03  u8[64]  block_a
+0x43  u8[128] block_b       // body = 195 bytes after opcode
```

Counter derivation, HMAC stages, and `Crypto_CounterLoad` byte-permute: [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md).

Client also sends follow-up **`0x00A101`** (131 B) via `NetworkSendKeyFollowUp` @ `0x5EC5A0`; login ack **`0x00A102`** — see [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md). Server outbound opcode for inbound blob: **not mapped**.

### Other recv opcodes (client)

| Opcode | Payload | Effect |
|--------|---------|--------|
| `0x0E05` / `0x0E06` | `u8 flags` · `u32 entity` · `u32 char` · `u16 fx` (11 B) | Entity FX, no chat box |
| `0x0F02` | `u8 mode` | GM monitor flag or SysMsg |
| `0x110B` | G (`u32 entity` · `char[32] label`) | Nameplate (`56C650`) |
| `0x1111` | B (name 21 + len + text) | Area SysMsg `0x31` |
| `0x1112` | `u32 rsv` · `u8 len` · `text` (buf `0x400`) | Long text SysMsg |
| `0xF101` | A + vfn `(1,0,…)` | Party notify color `0x29` |

---

## 4. Server — recv / send

### Common validation (`Chat_ProcessIncoming` / `AdminChat`)

- Text: **`2 ≤ len ≤ 128`** (`len ≥ 0x81` → kick).
- Global cooldown: `CUser+0x581c`.
- Shout cooldown: `+0x58e4` = now + 30s.
- Megaphone cooldown: `+0x58e0` = now + 30s.
- Megaphone flag: `+0x58dc` — next Normal becomes `0x1108`.

### Server flow by opcode (in → out)

| In (client) | Broadcast out | Function |
|-------------|---------------|----------|
| `0x1101` Normal | `0x1101` `{opcode, charId, len, msg}` | `Chat_BroadcastNormal` (cells mode 7) |
| `0x1101` + megaphone flag | **`0x1108`** `{opcode, name[21], len, msg}` | `Chat_BroadcastNamed` (global) |
| `0x1102` Whisper | `0x1102` ×2 (target + echo) | `SConnection_Send` direct |
| `0x1103` Trade | `0x1103` name+text | `Chat_BroadcastTrade` |
| `0x1104` Guild | `0x1104` + `0x812` alliance | `Chat_BroadcastGuild` |
| `0x1105` Party | `0x1105` charId+text | `CParty_BroadcastPacket` |
| `0x1107` Shout | `0x1107` charId+text | `Chat_BroadcastShout` (mode 5) |
| `0x1108` Megaphone | `0x1108` name+text | `Chat_BroadcastNamed` |
| `0x1111` Area | `0x1111` name+text | `Chat_BroadcastZone` |
| `0x1112` Raid leader | `0x1112` charId+text | `CParty_BroadcastPacket` |
| `0xF101`–`0xF10A` | mirrored admin opcodes | `AdminChat_ProcessIncoming` |

**Client inbound (C→S):** `0x1109`, `0x110A`, `0x110B` → **kick** (`Chat_ProcessIncoming` default branch → `SConnection_Close(9,0)` @ `0x0047FC24`). These opcodes are **server push only** on the stock protocol.

### Server push — `0x1109` / `0x110A` / `0x110B` (S→C)

Evidence: `psgame-chat-native/send/Chat_PacketBuilder_*.c` · client recv handlers cross-checked.

| Opcode | Pattern | Plaintext size | Builder VA | Send path |
|--------|---------|----------------|------------|-----------|
| `0x1109` | **D** | `len + 8` | `0x004C6A80` (`flag=0`) · `0x004C6F50` (`flag=1`) | `SConnection_Send` @ `0x004ED0E0` or `CParty_BroadcastPacket` @ `0x0044E950` (1109_A, in-party) |
| `0x110A` | **E** | **8** | `0x004C8310` (`mov 0x110A` @ `0x4C8328`) | Spatial cell iteration → `SConnection_Send(..., 8)` |
| `0x110B` | **G** | **0x26** (38) | `0x004C8520` (landmark `0x004C8539`, `mov 0x110B` @ `0x4C8542`) | Spatial cell iteration → `SConnection_Send(..., 0x26)` |

**`0x1109` — Pattern D** (CONFIRMED server + client):

```
+0x00  u16  opcode (0x1109)
+0x02  u8   flag       // 0 @ 0x4C6AEB (1109_A); 1 @ 0x4C6F59 (1109_B)
+0x03  u32  charId     // *(CUser+0x88) — stack @ esp+0x13 in builder asm
+0x07  u8   len        // 1..0x7F (builder rejects len==0 or len>0x7F)
+0x08  u8   text[len]  // no null on wire; send size = len + 8
```

- **1109_A** (`0x004C6A80`): `flag=0`; if sender in party → `CParty_BroadcastPacket`; else direct `SConnection_Send`. Caller @ `0x004A22C6`.
- **1109_B** (`0x004C6F50`): `flag=1`; radius `param_2` (float); iterates zone cells (`Zone_FloorWorldToCellIndex` @ `0x005250C0`, stride `0x124`) and sends to users within `Math_DistanceRadiusCompare` @ `0x0041B8A0`. Caller @ `0x004A2640`.

**`0x110A` — Pattern E** (CONFIRMED):

```
+0x00  u16  opcode (0x110A)
+0x02  u32  charId     // CUser+0x88
+0x06  u16  message_id // script table id; client resolves via GetMsg @ 0x420DB0
```

Plaintext **8 B** (`SConnection_Send` size arg @ `0x4C8383`). Spatial broadcast (same cell loop as 1109_B). Caller @ `0x004CB41F` (wrapper @ `0x004CB3D0`).

**`0x110B` — Pattern G** (CONFIRMED):

```
+0x00  u16  opcode (0x110B)
+0x02  u32  entity     // CUser+0x88 (entity id for nameplate target)
+0x06  char label[32] // _strncpy(..., 0x20) + explicit NUL @ 0x4C8551
```

Plaintext **0x26** (38 B). Client reads `u32` + `PacketRead_String` **0x20** @ `Handler_Chat_110B` `0x005E5740`. Spatial broadcast. Caller @ `0x004CB45E` (wrapper @ `0x004CB430`).

### Megaphone (item → chat)

1. `ItemUseNSend` (`4728E0`) — validates item `0x40–0x67` or `0xACA1–0xACA7`.
2. Emits `0x702`, `0x50A`, `0x40E` (inventory/slot).
3. Sets flag `CUser+0x58dc` in `ItemUse_UIInventoryHandler` @ **`0x004736C3`** (before `ItemUseNSend`).
4. Client sends text as `0x1101` → server repackages as **`0x1108`**.

### Outbound layouts (broadcast)

**Normal / Party / Shout (`1101`, `1105`, `1107`):**
```
u16 opcode · u32 charId · u8 len · bytes[len]     // size = len + 7
```

**Name + text (Megaphone, Guild, Trade, Area):**
```
u16 opcode · u8 name[21] · u8 len · bytes[len]      // size = len + 0x18
```

**Guild alliance:**
```
u16 0x812 · u8 name[21] · u8 len · bytes[len] · u32 guildId   // size = len + 0x1C
```

---

## 5. Reimplementation confidence

Current assessment (May 2026):

| Goal | Confidence | What this doc covers |
|------|------------|----------------------|
| Hook send/recv with correct opcodes and layouts | **High (~95%)** | Send/recv packet bodies, opcode routing |
| Server chat compatible with stock client | **High (~85%)** | Length validation, broadcasts, megaphone flow |
| End-to-end wire cryptography | **Medium-high (~85%)** | Envelope + `0xA101`/`0xA102`; see [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) |
| Standalone cipher without capture | **Medium-high (~75%)** | Inbound layout mapped; counter derivation not closed |
| Pixel-perfect UI clone | **Medium (~65%)** | Out of scope — vtables/UI |

### Known uncertainties

| Topic | Status |
|-------|--------|
| Server outbound opcode for client `0xA101` | **Not mapped** |
| Initial counter bytes (client) | Derived inside `0x401100` — wire mapping **not mapped** |
| `0xA101` `field_1` HMAC inner length | **INFERRED** — validate @ `0x404569` |
| `0xA101` counter bytes `stack+0x38` | **HYPOTHESIS** — 8 B pre-digest source unknown |
| `char[21]` fixed fields | **CONFIRMED** — see below |

### `char[21]` name fields (CONFIRMED May 2026)

| Direction | Opcodes / pattern | Evidence |
|-----------|-------------------|----------|
| Client recv | `1102`–`1104`, `1108`, `1111` (patterns B/C) | `PacketRead_String` @ `0x005F4780` with `count=0x15` in each handler (`Handler_ChatWhisper/Guild/Trade/Megaphone/Area_*.c`) — reads **21 B fixed**, no wire null |
| Client send | `1102` whisper | `PacketSend_Whisper` @ `0x005ED160`: `param_2[0..4]` + byte at `param_2+5` → 21 B; wire size `msg_len+0x18` |
| Server out | `1103`,`1104`,`1108`, megaphone `1108`, alliance `0x812` | Null-terminated copy from `CUser+0x184` into `char[21]` stack (`Chat_ProcessIncoming` @ `0x0047F400`, `Chat_BroadcastGuild` @ `0x00432530`); send size `len+0x18` |
| Client recv **not** 21 B | `1101`,`1105`,`1107` (u32 id); `1109` (pattern D); `110B` (`char[32]` @ read `0x20`) | Handler decomps |

**HYPOTHESIS (emulator):** zero-fill name bytes after `'\0'` through byte 20 on pattern B/C server sends. **Validate:** capture `0x1104` guild broadcast, hexdump name tail. Full gap list: [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md).

---

## 6. Cross-reference

| Doc | Contents |
|-----|----------|
| [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) | AES-CTR cipher, envelope, handshake, megaphone flag |
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Handler VA, vtable, `.c` file |
| [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) | Lacunas P0/P1/P2, balloon gates, admin recv |
| `game-chat-native/handlers/` | Client recv evidence |
| `psgame-chat-native/handlers/Chat_ProcessIncoming_0047f400.c` | Server evidence |
| `tools/ghidra/*.manifest` | Full VA list |
