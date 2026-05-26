# Wire cryptography — Shaiya native chat

Companion to [`PACKET_SPEC.md`](PACKET_SPEC.md) and [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md).  
**Step-by-step** decode (client ↔ server), validated by cross-binary disassembly — May 2026.

| Binary | MD5 | ImageBase |
|--------|-----|-----------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` | `0x00400000` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` | `0x00400000` |

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

## Step 4 — Handshake / key derivation (client)

Observed post-login sequence:

| VA | Name | Action |
|----|------|--------|
| `0x00401310` | `Crypto_EnableGameCipher` | `DAT_023037e9 = 1`, `DAT_023037ea = 1` |
| `0x00401320` | `Crypto_DeriveSessionKeys` | SHA256-like (`0x00404390`) over buffer `0x23027C0`; fills round keys in `0x23037F0` / `0x2303A58` and send ctx `0x2303908` |
| `0x004012BC`… | (login callers) | Invoke expand + counter init before first game packet |

Client global contexts:

| Address | Use |
|---------|-----|
| `0x023037F0` | Main recv (`StreamCrypt_XOR`) |
| `0x02303908` | Alt send (`StreamCrypt_AltCtx`) |
| `0x02303A58` | Secondary recv |
| `0x023027E0` | Login XOR table |

**Open gap:** exact opcode of the packet that delivers key material (likely login/zone-enter ~ `0x0201`) — derivation requires wire capture + breakpoint at `0x401320`.

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

### Server (`psgame-chat-native/crypto/`)

| Name | VA | Role |
|------|-----|------|
| `PacketStream_XOR` | `0x004E4180` | Stream XOR (recv **and** send) |
| `AES_BlockKeystream` | `0x004E3450` | AES core |
| `AES_KeyExpand` | `0x004E4350` | Expand 128-bit key |
| `Crypto_CounterInit` | `0x004E4000` | Init 16 B counter |
| `Connection_EncryptOutbound` | `0x00464F20` | Encrypt buffer before socket |
| `Connection_DecryptInbound` | `0x00464FA0` | Decrypt after recv |
| `Recv_PacketDecrypt` | `0x004E4180` | Historical alias (= `PacketStream_XOR`) |

---

## Reimplementation confidence

| Goal | Before | Now |
|------|--------|-----|
| Hook chat send/recv (correct plaintext) | ~90% | **~95%** — envelope + opcodes |
| Wire-compatible proxy (no custom cipher) | ~40% | **~75%** — algorithm + ctx struct |
| Server emulator with stock client | ~80% | **~85%** |
| Cipher clone without handshake capture | ~40% | **~55%** — key packet missing |

**Still TODO:** opcode/handshake that fills `0x23027C0`; validate initial counter (IV/nonce); export vfn `+0xF0` (`0x0502`).

---

## Cross-reference

| Doc | Contents |
|-----|----------|
| [`PACKET_SPEC.md`](PACKET_SPEC.md) | Opcode/body layouts |
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Chat handlers |
| `game-chat-native/send/NetworkSend_*.c` | Encrypt call site |
| `psgame-chat-native/pipeline/Recv_Wrapper_*.c` | Decrypt call site |
| `tools/ghidra/decompile-crypto.sh` | Regenerate crypto `.c` |
