# Wire cryptography — Shaiya native chat

Companion to [`PACKET_SPEC.md`](PACKET_SPEC.md) and [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md).  
**Step-by-step** decode (client ↔ server), validated by cross-binary disassembly — May 2026.

| Binary | MD5 | ImageBase |
|--------|-----|-----------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` | `0x00400000` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` | `0x00400000` |
| `ps_login.exe` | *(server tree; login handshake)* | `0x00400000` |

Regenerate crypto `.c`: `./tools/ghidra/decompile-crypto.sh`

---

## Step 1 — TCP envelope (plaintext underneath)

```
┌─────────────────┬──────────────────────────────────┐
│ wire_len  u16   │  encrypted payload (wire_len − 2)  │
│ LE, CLEAR TEXT  │  opcode + body XOR stream          │
└─────────────────┴──────────────────────────────────┘
```

| Field | Size | Rule |
|-------|------|------|
| `wire_len` | 2 | **Not encrypted.** `= plaintext_size + 2` |
| ciphertext | `wire_len − 2` | Stream cipher (game mode) or login XOR |

**Client send** (`NetworkSend` @ `0x005EA9A0`):

1. Build local buffer: `[u16 len][plaintext…]`
2. `PacketPayload_Encrypt` @ `0x00401040` — encrypts plaintext only (from `+2`)
3. `send()` transmits `len + 2` bytes total

**Client recv** (`NetworkRecv_SocketPump` @ `0x005F438E`):

1. Read `wire_len`, allocate `wire_len − 2` bytes
2. `PacketPayload_Decrypt` @ `0x00401080` — decrypt in-place
3. `PacketDispatcher` reads `opcode u16` at plaintext start

**Server recv** (`Recv_Wrapper` @ `0x004748E0`):

1. If `SConnection+0x57f0 != 0`: call `PacketStream_XOR` @ `0x004E4180` on `(payload+2, len−2)` **before** dispatch
2. Plaintext at `packet+2`; opcode at `[+2..+3]`

**Server send** (`Connection_EncryptOutbound` @ `0x00464F20`):

1. If `conn+0x231 != 0`: `PacketStream_XOR` in-place on send buffer (plaintext → ciphertext)
2. If `conn+0x232 != 0`: alternate XOR with static table (`0x005868C0` + index) — mirror of client login mode

---

## Step 2 — Cipher modes (dispatcher)

### Client — `PacketPayload_Decrypt` / `PacketPayload_Encrypt`

| Global | Address | Role |
|--------|---------|------|
| `DAT_023037e8` | login gate | `!= 0` → login XOR mode |
| `DAT_023037e4` | login submode | `== 2` → table XOR |
| `DAT_023037ea` | game cipher on | enables AES-CTR after handshake |
| `DAT_023037e9` | encrypt send | outbound encrypt gate |
| `DAT_023037e0` | ctx selector | `0` → recv ctx; `!= 0` → alt send ctx |

**Decrypt** (`0x00401080`):

```
if (login_gate) {
  if (mode == 2) Login_XORStream(buf, len);  // 0x00401000
} else if (game_cipher) {
  if (ctx_sel == 0) StreamCrypt_XOR(0x23037F0, buf, len);  // 0x00404DF0
  else              StreamCrypt_AltCtx(0x2303908, buf, len); // 0x00401640
}
```

**Encrypt** (`0x00401040`): mirror — same functions, gate `DAT_023037e9`.

### Login XOR (`Login_XORStream` @ `0x00401000`)

- Table: `0x0023027E0` (4096 bytes, wrap `eax &= 0xFFF`)
- `cipher[i] = plain[i] ^ table[index++]`
- Used only while `DAT_023037e8` active and `DAT_023037e4 == 2`

### Server — per-connection flags (`SConnection` / `CUser` socket blob)

| Offset | Role |
|--------|------|
| `+0x230` | recv stream on → `Connection_DecryptInbound` @ `0x00464FA0` |
| `+0x231` | send AES stream → `Connection_EncryptOutbound` AES path |
| `+0x232` | send login XOR (table `0x005868C0`) |
| `+0x118` | **Crypto context** (layout below) — mirror of client `0x23037F0` |

---

## Step 3 — AES-128 counter mode (CTR-like)

Inferred algorithm: **AES-128 ECB on counter block → keystream; XOR with data**.  
Encrypt and decrypt use **the same** XOR routine (`PacketStream_XOR`) — symmetric.

### AES core (T-tables)

| Role | Client VA | Server VA | T-tables |
|------|-----------|-----------|----------|
| Keystream block | `AES_BlockKeystream` `0x00404830` | `AES_BlockKeystream` `0x004E3450` | `0x00567D00`… |
| Key schedule | `(via SHA256→expand)` | `AES_KeyExpand` `0x004E4350` | — |
| Counter load | — | `Crypto_CounterInit` `0x004E4000` | copies 16 B → `ctx+0xF4` |

### Context struct (~0x118 bytes minimum)

Offsets relative to context pointer (`esi` / `this`):

| Offset | Field | Description |
|--------|-------|-------------|
| `+0xF4` | `counter[0..3]` | 128-bit LE nonce/counter; incremented per block |
| `+0x104` | `partial` | Bytes already consumed from current keystream (0..15) |
| `+0x108` | `keystream[16]` | Output of `AES_BlockKeystream(counter)` |
| `+0x??` | `round_keys[]` | AES-128 key schedule (44 uint32) |

### `PacketStream_XOR` loop @ `0x004E4180` (client `0x00404DF0` identical)

```
partial = ctx+0x104
if (partial > 0):
  xor until 16 bytes complete or input exhausted
while (len >= 16):
  AES_BlockKeystream(ctx+0x108)   // encrypt counter block
  increment counter @ ctx+0xF4 (uint128 LE +1 with carry)
  out[0..15] = in[0..15] ^ keystream[0..15]
if (len > 0):
  AES_BlockKeystream(...)
  increment counter
  xor remaining bytes → partial = len
```

**Confidence:** layout `+0xF4/+0x104/+0x108` **high** (decompiled + disassembly); AES-128 **high** (T-table rounds); exact CTR vs CFB **medium-high** (observed behavior = CTR).

---

## Step 4 — Handshake / key derivation

### Inbound key blob — opcode `0x00A101` (client recv)

Validated chain (Game.exe disassembly + PE read):

```
NetworkRecv_SocketPump @ 0x5F438E
  → PacketPayload_Decrypt @ 0x401080
  → PacketDispatcher @ 0x5F1E10  (cmp opcode == 0xA101)
       → Handler_Packet_A101_KeyMaterial @ 0x5E3D60
            reads body (see layout below)
            → [DAT_022fa2f0 vtable + 0x254]  (slot VA 0x747798)
                 → Connection_OnKeyMaterial @ 0x5A4D50
                      → Crypto_ProcessKeyPacket @ 0x401100
                      → NetworkSendKeyFollowUp @ 0x5EC5A0
                      → Crypto_EnableGameCipher @ 0x401310
                      → conn+0x224 = 1
```

**Payload layout** (after opcode `u16`, handler @ `0x5E3D60`):

```
+0x00  u8   field_0    // ctx selector (0 = recv CounterLoad path)
+0x01  u8   field_1    // block_b slice length (append/HMAC — INFERRED)
+0x02  u8   field_2    // block_a slice length (append — CONFIRMED)
+0x03  u8[64]  block_a
+0x43  u8[128] block_b          // total body = 195 bytes
```

Full counter/HMAC chain: [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md).

### Post-login derive path (client)

```
login tick @ 0x50C767: if conn+0x224 ∉ {0xFC,0xFD,0xFE,0xFF}
  → Crypto_DeriveSessionKeys @ 0x401320  (SHA256 @ 0x404390 over 0x23027C0)
  → credential check @ 0x5DE670
  → Crypto_EnableGameCipher @ 0x401310
  → conn+0x224 = 0
```

| VA | Name | Action |
|----|------|--------|
| `0x005E3D60` | `Handler_Packet_A101_KeyMaterial` | Recv handler; reads 195 B; calls vfn `+0x254` |
| `0x00401100` | `Crypto_ProcessKeyPacket` | HMAC/expand pipeline; populates `0x23027C0` and AES ctx |
| `0x00401320` | `Crypto_DeriveSessionKeys` | SHA256-like (`0x00404390`) over `0x23027C0`; expand keys |
| `0x00401310` | `Crypto_EnableGameCipher` | `DAT_023037e9 = 1`, `DAT_023037ea = 1` |
| `0x00404680` | `Crypto_CounterLoad` | AES key schedule init (first 16 B of derived block, byte-swapped) |
| `0x005A4D50` | `Connection_OnKeyMaterial` | vfn `+0x254`; calls `401100` + ack follow-up + enable |
| `0x005A4D30` | `Connection_SendKeyAck` | Sends client ack (see below) |
| `0x004D2B50` | `Login_OnSubmitCredentials` | Copies creds to `conn+0x27C` / `+0x29F`; calls `5A4D30`; sets `conn+0x224 = 0x11` |

Connection object vptr base: **`0x00747544`**. Handler slot **`+0x254`** → VA **`0x00747798`** → **`0x005A4D50`**.

### Client → server key ack (`Connection_SendKeyAck`)

Built by `NetworkSendKeyBlob` @ `0x005EC610`:

| Offset | Size | Field |
|--------|------|-------|
| `+0` | 2 | **`opcode = 0x00A102`** (LE) |
| `+2` | 2 | `0x0032` (50) — sub-field / length marker |
| `+4` | 34 | Payload copied from `conn+0x27C` (18 B) + `conn+0x29F` (16 B) |

Still encrypted with **login XOR** until `Crypto_EnableGameCipher` runs.

### Server mirror (`ps_game.exe`)

| VA | Name | Action |
|----|------|--------|
| `0x00464E60` | `Connection_InitStreamCrypto` | `AES_KeyExpand` on 16 B key; copy 16 B → `conn+0x118` ctx `+0xF4`; set `conn+0x230=1`, `conn+0x231=1` |
| `0x00464F00` | `Connection_EnableSendCipher` | `conn+0x231 = 1`, clear login XOR send (`+0x232`) |
| `0x00413CB5` | (zone-enter pipeline) | Calls `464E60` after copying 8×`u32` key material |

Called from **`ZoneCryptoInit` @ `0x413B30`** (callers `0x406C1B` / `0x406C52`), **not** from `Handler_Packet1201` @ `0x47FCC0` (that handler only calls `0x453CB0` for zone name).

**Server outbound `0xA101` key blob** (client recv equivalent): sent by **`ps_login.exe` `SendKeyBlob_A101` @ `0x404DA0`** (`mov [esp+0x10], 0xA101`, `push 0xC5`, `call 0x410AE0`); caller **`0x401CDF`**. **Not present in `ps_game.exe`.** See [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md).

### Initial counter (IV)

| Finding | Confidence |
|---------|------------|
| Server copies `[struct+0x10..0x1F]` literally into `ctx+0xF4..0x100` (`Connection_InitStreamCrypto`) | **High** |
| Client counter at `0x23037F0+0xF4` comes from **derived** material inside `0x401100` (HMAC/PRNG path), not a fixed offset in the `0xA101` wire body | **High** |
| Exact byte-for-byte formula payload → initial counter without runtime capture | **Not mapped** |

### Client global contexts

### Client → server key ack (`Connection_SendKeyAck`)

Built by `NetworkSendKeyBlob` @ `0x005EC610`:

| Offset | Size | Field |
|--------|------|-------|
| `+0` | 2 | **`opcode = 0x00A102`** (LE) |
| `+2` | 2 | `0x0032` (50) — sub-field / length marker |
| `+4` | 34 | Payload copied from `conn+0x27C` (18 B) + `conn+0x29F` (16 B) |

Still encrypted with **login XOR** until `Crypto_EnableGameCipher` runs.

### Server mirror (`ps_game.exe`)

| VA | Name | Action |
|----|------|--------|
| `0x00464E60` | `Connection_InitStreamCrypto` | `AES_KeyExpand` on 16 B key; copy 16 B counter → `conn+0x118` ctx; set `conn+0x230=1`, `conn+0x231=1` |
| `0x00464F00` | `Connection_EnableSendCipher` | `conn+0x231 = 1`, clear login XOR send (`+0x232`) |
| `0x00413CB5` | `ZoneCryptoInit` inner site | Calls `464E60` after copying 8×`u32` key material; parent **`0x413B30`** ← `0x406C1B` / `0x406C52` |

Called from **`ZoneCryptoInit` @ `0x413B30`**, **not** from `Handler_Packet1201` @ `0x47FCC0`. Outbound **`0xA101`**: **`ps_login.exe` @ `0x404DA0`** — see [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md).

### Initial counter (IV)

| Evidence | Detail |
|----------|--------|
| `Crypto_CounterLoad` @ `0x404680` | Loads **16 B** from stack (`esp+0x38` in `0x401100`); **custom dword permute** @ `0x40468D` + AES-128 expand → `ctx+0xF4` |
| Server `Connection_InitStreamCrypto` | Copies `[esi+0x10..0x1C]` (4×`u32`) → `ctx+0xF4..0x100`; `partial = 0` |
| Outbound `0xA101` | **`ps_login.exe` `SendKeyBlob_A101` @ `0x404DA0`** (`push 0xC5`, `call 0x410AE0`) |

### Client global contexts

| Address | Use |
|---------|-----|
| `0x023037F0` | Main recv (`StreamCrypt_XOR`) |
| `0x02303908` | Alt send (`StreamCrypt_AltCtx`) |
| `0x02303A58` | Secondary recv |
| `0x023027C0` | Key seed buffer (cleared after derive) |
| `0x023027E0` | Login XOR table |

---

## Step 5 — Server send pipeline (where encryption happens)

```
SConnection_AllocSendBuffer (plaintext)
  → write queue
  → SConnection_DrainWriteQueue @ 0x004F1CA0
       → vfn conn+0x59 → Connection_EncryptOutbound @ 0x00464F20
            → PacketStream_XOR if conn+0x231
  → WSASend (wire_len prefix clear)
```

Recv is symmetric in `Recv_Wrapper` @ `0x004748E0` (decrypt **before** `CUser_DispatchPacket_Main`).

---

## Step 6 — Megaphone: who sets `CUser+0x58dc`

| VA | Evidence |
|----|----------|
| **`0x004736C3`** | `mov byte [ebp+0x58dc], 1` — only `=1` writer in the binary |
| Parent function | `ItemUse_UIInventoryHandler` @ `0x004654C0` (item use switch) |
| Preconditions | `58dc==0`, cooldown `58e0 <= now`, then `call ItemUseNSend` @ `0x4728E0` |
| Consumption | `Chat_ProcessIncoming` @ `0x47F400` — if `58dc!=0` on next `0x1101`, broadcast `0x1108` and clear flag |

Confirmed flow: **megaphone item → set flag → client sends Normal → server repackages as Megaphone**.

---

## Step 7 — Exported function table

### Client (`game-chat-native/crypto/`)

| Name | VA | Role |
|------|-----|------|
| `PacketPayload_Encrypt` | `0x00401040` | Send encrypt dispatcher |
| `PacketPayload_Decrypt` | `0x00401080` | Recv decrypt dispatcher |
| `Login_XORStream` | `0x00401000` | Login XOR |
| `StreamCrypt_XOR` | `0x00404DF0` | AES-CTR XOR main ctx |
| `StreamCrypt_AltCtx` | `0x00401640` | AES-CTR XOR send ctx |
| `AES_BlockKeystream` | `0x00404830` | One AES block → 16 B keystream |
| `Crypto_EnableGameCipher` | `0x00401310` | Enable flags post-login |
| `Crypto_DeriveSessionKeys` | `0x00401320` | Derive session keys |
| `Crypto_ProcessKeyPacket` | `0x00401100` | Parse inbound key blob |
| `Crypto_CounterLoad` | `0x00404680` | Load 16 B counter into ctx |
| `Connection_OnKeyMaterial` | `0x005A4D50` | State-machine key handler |
| `Connection_SendKeyAck` | `0x005A4D30` | Send `0xA102` ack |

### Server (`psgame-chat-native/crypto/`)

| Name | VA | Role |
|------|-----|------|
| `PacketStream_XOR` | `0x004E4180` | Stream XOR (recv **and** send) |
| `AES_BlockKeystream` | `0x004E3450` | AES core |
| `AES_KeyExpand` | `0x004E4350` | Expand 128-bit key |
| `Crypto_CounterInit` | `0x004E4000` | Init 16 B counter |
| `Connection_EncryptOutbound` | `0x00464F20` | Encrypt buffer before socket |
| `Connection_DecryptInbound` | `0x00464FA0` | Decrypt after recv |
| `Connection_InitStreamCrypto` | `0x00464E60` | Expand key + init counter on connect |
| `Recv_PacketDecrypt` | `0x004E4180` | Historical alias (= `PacketStream_XOR`) |

---

## Reimplementation confidence

Current assessment (May 2026, validated against `Game.exe` + `ps_game.exe`):

| Goal | Confidence | Basis |
|------|------------|-------|
| Hook chat send/recv (plaintext after decrypt) | **High (~95%)** | TCP envelope, opcode dispatch, decrypt/encrypt gates mapped |
| Wire-compatible proxy (reuse stock cipher) | **Medium-high (~75%)** | AES-128 CTR-like stream, ctx struct, per-connection flags |
| Server emulator compatible with stock client | **High (~85%)** | Chat validation, broadcasts, megaphone, server crypto init |
| Standalone cipher clone (no wire capture) | **Medium-high (~75%)** | Inbound `0xA101` layout + ack `0xA102`; counter derivation inside `0x401100` not closed |
| Pixel-perfect UI clone | **Medium (~65%)** | Out of scope — vtables/UI not fully mapped |

### Known uncertainties

| Topic | Status |
|-------|--------|
| Server outbound `0xA101` key blob | **`ps_login.exe` @ `0x404DA0`** (confirmed); absent from `ps_game.exe` |
| Initial counter bytes (client) | Derived via HMAC/PRNG in `0x401100` — wire offset **not mapped** |
| `0xA101` `field_0/1/2` | `field_0` ctx branch **CONFIRMED**; `field_1/2` slice lengths **CONFIRMED/INFERRED** — see [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) |
| HMAC inner length vs `field_1` | **INFERRED** @ `0x404569` |
| Fixed-field charset/padding | `char[21]` name fields — partially inferred |

---

## Cross-reference

| Doc | Contents |
|-----|----------|
| [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) | `0xA101` → `ctx+0xF4`, HMAC, header bytes |
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Chat handlers |
| `game-chat-native/send/NetworkSend_*.c` | Encrypt call site |
| `psgame-chat-native/pipeline/Recv_Wrapper_*.c` | Decrypt call site |
| `tools/ghidra/decompile-crypto.sh` | Regenerate crypto `.c` |
