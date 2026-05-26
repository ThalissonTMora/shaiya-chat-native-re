# AES counter derivation — opcode `0x00A101`

Evidence from `Game.exe` (`MD5=c1edd96639ad81835624b9c4516ac781`, `ImageBase=0x00400000`).  
Companion: [`PACKET_SPEC.md`](../PACKET_SPEC.md), [`WIRE_CRYPTO.md`](../WIRE_CRYPTO.md).

Regenerate decomps: `./tools/ghidra/decompile-crypto.sh`

Decomp artifacts: `game-chat-native/crypto/Crypto_HMAC_Derive_00404420.c`, `Crypto_PRNGFill_00404610.c`, `Crypto_CounterAdvance_00401500.c`, `Crypto_KeyMaterialAppend_00404F90.c`, `Crypto_OutputPack_00405050.c`.

---

## Call chain (195 B body → `ctx+0xF4`)

```
PacketDispatcher @ 0x005F1E10  (cmp opcode == 0xA101)
  → Handler_Packet_A101_KeyMaterial @ 0x005E3D60
       PacketRead: u8×3 + u8[64] + u8[128]  (195 B after opcode)
       → [conn vtable + 0x254] @ 0x00747798
  → Connection_OnKeyMaterial @ 0x005A4D50
       Crypto_ProcessKeyPacket @ 0x00401100
         [field_0 == 0] Crypto_CounterLoad @ 0x00404680 ×2
       NetworkSendKeyFollowUp @ 0x005EC5A0
       Crypto_EnableGameCipher @ 0x00401310
```

Handler argument mapping (`Connection_OnKeyMaterial` → `Crypto_ProcessKeyPacket`):

| Handler read | `ProcessKeyPacket` param | Role |
|--------------|--------------------------|------|
| `field_0` @ +0 | `param_3` | Stored in `DAT_023037e0`; branch recv/send |
| `field_1` @ +1 | `param_5` | Passed in `EBX` to `0x00404F90` — **slice length for `block_b`** |
| `field_2` @ +2 | `param_7` | Saved in `EBP` inside `0x00404F90` — **slice length for `block_a`** |
| `block_a` @ +3 | `param_4` | 64 B HMAC/vector input |
| `block_b` @ +67 | `param_6` | 128 B HMAC/vector input |

---

## `0xA101` body layout (after opcode)

```
+0x00  u8   field_0    // ctx selector: 0 = recv CounterLoad path (CONFIRMED @ 0x40116C)
+0x01  u8   field_1    // block_b effective length for append/HMAC slice (INFERRED)
+0x02  u8   field_2    // block_a effective length for ack vector append (CONFIRMED @ 0x404F91/0x404FEA)
+0x03  u8[64]  block_a
+0x43  u8[128] block_b
```

Total body: **195 bytes**. Wire total (plaintext): **197 bytes** (`opcode` + body).

---

## `Crypto_ProcessKeyPacket` @ `0x00401100`

### Phase A — PRNG + HMAC (`field_0` path common)

1. **`DAT_023037e0 ← field_0`** @ `0x401140`
2. **`Crypto_PRNGFill` @ `0x00404610`** — LCG fills **128 B** at stack `esp+0x58` (seed `DAT_02303a8c`)
3. **`Crypto_HMAC_Derive` @ `0x00404420`** — HMAC-SHA256 pipeline (see below); 32 B digest → stack `esp+0x40` (`EBX` preserved from caller)
4. **Branch on `field_0`** @ `0x40116C`

### Phase B — recv path (`field_0 == 0`) → counter @ `ctx+0xF4`

Disassembly @ `0x401174`–`0x40118B`:

| Call | `EAX` (ctx base) | `ECX` (16 B source) | Effect |
|------|------------------|---------------------|--------|
| 1st `0x00404680` | `0x023037F0` | `esp+0x38` | Recv stream ctx: counter + AES-128 key schedule |
| 2nd `0x00404680` | `0x02303940` | `esp+0x38` | Secondary recv ctx (`0x23037F0 + 0x150`) |

Counter VA after load: **`0x023037F0 + 0xF4 = 0x023038E4`** (matches `StreamCrypt_XOR` @ `0x00404DF0`).

Stack `esp+0x48..0x54` (second 16 B of 32 B stack block) copied to key-seed globals `0x023027C0..0x023027CC` and mirrored to `0x023038E4`, `0x02303A34` counter copies @ `0x401190`–`0x4011EB`.

### Phase C — send path (`field_0 != 0`)

Copies 32 B key schedule to `0x02303908` / `0x02303A58`, calls **`Crypto_CounterAdvance` @ `0x00401500`** (LCG mutate `@ ctx+0xC`), sets partial-byte counters `0x02303938` / `0x02303A88` to 0. No direct `CounterLoad` on this branch.

### Phase D — ack material (`0x00404F90` + `0x00405050`)

Builds `std::vector`-like blob: **`memcpy(block_b, field_1)`** then **`memcpy(block_a, field_2)`** @ `0x00404F90`.  
`0x00405050` packs vector + PRNG buffer (`esp+0x58`) into 128 B client output → `NetworkSendKeyFollowUp` sends **`0x00A101`** / **0x83** bytes @ `0x005EC5A0`.

---

## HMAC-SHA256 @ `0x00404420` (partial — full chain not closed)

**CONFIRMED primitives** (disassembly @ `0x404456`–`0x404505`, `0x404150`, `0x4041F0`):

- Standard SHA-256 IV constants (`0x6A09E667`, …)
- 64-byte ipad/opad with `0x36` / `0x5C` XOR @ `0x4044F0`–`0x404504`
- Final 32-byte digest written big-endian byte-serialized @ `0x404286`–`0x4042D5` into `EDI`

**CONFIRMED first pass:** `SHA256(block_b[0..127])` — update length `0x80` @ `0x404441` before `0x404496`.

**INFERRED inner HMAC message length:** dword at `esp+0x134` inside `0x40404420` passed as update length @ `0x404569`–`0x404570`; stack layout ties this to **`field_1`** (same role as `block_b` slice in `0x00404F90`). **Validate with breakpoint at `0x404569` comparing `EAX` to `(uint8_t)field_1`.**

**HYPOTHESIS full formula** (needs runtime confirmation):

```
digest_key = SHA256(block_b[0..127])
T          = HMAC-SHA256(key=digest_key, msg=block_b[0..field_1])   // if inner len == field_1
stack[0x38..0x3F] = ???  // 8 bytes consumed by CounterLoad but not written by 0x404420 tail
stack[0x40..0x5F] = T    // 32 B @ 0x40115E → EBX; final outer HMAC EDI=EBX @ 0x404575
CounterLoad input = stack[0x38..0x47]  // 16 B → ctx+0xF4 after permute + key expand
stack[0x48..0x57] = T[16..31] or second half → 0x023027C0 seed
```

---

## `Crypto_CounterLoad` @ `0x00404680`

**Calling convention:** `__fastcall` — `ECX` = src `uint32[4]`, `EAX` = dst ctx pointer.

**CONFIRMED** @ `0x404693`: `ctx+0xF0 = 10` (AES-128 rounds).

**CONFIRMED** dword permute @ `0x40468D`–`0x40470C` (not a single `BSWAP`):

```c
// For each src[i], dst[i] at ctx+0xF4 + i*4:
uint32_t x = src[i];
uint32_t t = _rotr(x, 8) & 0xFF00FF00u;
uint32_t u = _rotl(x, 8) & 0x00FF00FFu;
dst[i] = t | u;
```

Then **AES-128 key expansion** (T-tables `0x00790760`, round constants `0x00791F64..`) writes round keys @ `ctx+0x100..`.

**Note:** `StreamCrypt_XOR` increments **`ctx+0xF4..0x100`** as 128-bit LE counter during CTR (@ `0x00404DF0`).

---

## Context map (recv, `field_0 == 0`)

| Global | Offset `+0xF4` (counter) | Set by |
|--------|--------------------------|--------|
| `0x023037F0` | `0x023038E4` | 1st `CounterLoad` |
| `0x02303940` | `0x02303A34` | 2nd `CounterLoad` |

Partial keystream offset: **`ctx+0x104`**, keystream block: **`ctx+0x108`** (`StreamCrypt_XOR` decomp).

---

## Reproduction checklist

1. Break `@ 0x005E3D60` — log `field_0..2`, `block_a[0..3]`, `block_b[0..3]`.
2. Break `@ 0x40117D` — dump 16 B at `ECX` (pre-permute counter material).
3. Break `@ 0x401740` after `CounterLoad` — dump `0x23038E4..0x23038F3` (initial CTR).
4. Break `@ 0x404569` — confirm inner HMAC length == `field_1`.
5. Compare with server `Connection_InitStreamCrypto` @ `ps_game.exe` `0x00464E60` (server-side counter copy).

---

## Confidence summary

| Claim | Tag |
|-------|-----|
| 195 B layout + handler → `0x401100` chain | **CONFIRMED** |
| `field_0==0` → `CounterLoad` → `0x23037F0+0xF4` | **CONFIRMED** (disasm `0x401174`–`0x40118B`) |
| `field_1` / `field_2` as slice lengths in `0x404F90` | **CONFIRMED** (disasm `0x404F91`, `0x404F96`, `0x404FEA`) |
| HMAC-SHA256 with SHA-256 IV + ipad/opad | **CONFIRMED** (`0x40404420`) |
| Dword permute formula @ `0x40404680` | **CONFIRMED** |
| Inner HMAC length == `field_1` | **INFERRED** |
| Full `stack[0x38..0x47]` composition | **HYPOTHESIS** |
| Server `0xA101` outbound opcode | **Not mapped** |
