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
+0x02  u8   target[21]     // 5×u32 + u8 copied — name semantics (?)
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

### Other recv opcodes (client)

| Opcode | Payload | Effect |
|--------|---------|--------|
| `0x0E05` / `0x0E06` | `u8 flags` · `u32 entity` · `u32 char` · `u16 fx` (11 B) | Entity FX, no chat box |
| `0x0F02` | `u8 mode` | GM monitor flag or SysMsg |
| `0x0502` | 15 B (6 fixed fields) | Generic vfn `+0xF0` (not exported) |
| `0x110B` | `u32 entity` · `char[32] label` | Nameplate |
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

**Not handled on server:** `0x1109`, `0x110A`, `0x110B` → kick.

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

| Goal | Confidence | What this doc covers |
|------|------------|----------------------|
| Hook send/recv with correct opcodes | **High (~90%)** | Main send + recv layouts |
| Server compatible with stock client | **High (~80%)** | Len validation, broadcasts, megaphone |
| Pixel-perfect UI clone | **Medium (~65%)** | Out of scope — see vtables/UI |
| End-to-end cryptography | **Medium (~75%)** | [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) — AES-CTR, ctx struct, send/recv paths |

**Open gaps:** post-login key packet opcode; initial IV/counter; vfn `+0xF0` (`0x0502`); charset/padding on fixed fields.

---

## 6. Cross-reference

| Doc | Contents |
|-----|----------|
| [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) | AES-CTR cipher, envelope, handshake, megaphone flag |
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Handler VA, vtable, `.c` file |
| `game-chat-native/handlers/` | Client recv evidence |
| `psgame-chat-native/handlers/Chat_ProcessIncoming_0047f400.c` | Server evidence |
| `tools/ghidra/*.manifest` | Full VA list |
