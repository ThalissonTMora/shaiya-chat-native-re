# AES counter derivation — opcode `0x00A101`

Evidence from `Game.exe` (`MD5=c1edd96639ad81835624b9c4516ac781`, `ImageBase=0x00400000`).  
Companion: [`PACKET_SPEC.md`](PACKET_SPEC.md), [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md).

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
| `field_1` @ +1 | `param_6` | **`block_b` slice length** in `0x00404F90` (`EBX` @ `0x404F96`) |
| `field_2` @ +2 | `param_7` | **`block_a` slice length** in `0x00404F90` (`EBP` @ `0x404FEA`); **HMAC inner message length** @ `0x404569` |
| `block_a` @ +3 | `param_4` | 64 B HMAC/vector input |
| `block_b` @ +67 | `param_5` | 128 B HMAC/vector input |

---

## `0xA101` body layout (after opcode)

```
+0x00  u8   field_0    // ctx selector: 0 = recv CounterLoad path (CONFIRMED @ 0x40116C)
+0x01  u8   field_1    // block_b effective length for ack vector append (CONFIRMED @ 0x404F96)
+0x02  u8   field_2    // block_a effective length for ack vector append (CONFIRMED @ 0x404FEA);
                       // HMAC inner update length on block_b (CONFIRMED @ 0x404569)
+0x03  u8[64]  block_a
+0x43  u8[128] block_b
```

Total body: **195 bytes**. Wire total (plaintext): **197 bytes** (`opcode` + body).

`field_1` and `field_2` are **independent** slice controls: HMAC uses `field_2` on `block_b`; the ack vector uses `field_1` on `block_b` and `field_2` on `block_a`.

---

## Closed formula (recv path, `field_0 == 0`)

Static chain @ `0x00401100` / `0x00404420` / `0x00404680`:

```c
// Phase A — PRNG + HMAC (common to recv/send)
uint8_t prng[128];                          // stack+0x58, Crypto_PRNGFill @ 0x00404610
Crypto_PRNGFill(prng);

uint8_t digest[32];                         // stack+0x38..0x57 (see stack note below)
{
    uint8_t key0[32] = SHA256(prng, 128);   // CONFIRMED @ 0x404434 push [esp+0x11c], len 0x80 @ 0x404441
    digest = HMAC_SHA256(
        key  = key0,
        msg  = block_b,
        len  = (size_t)(uint8_t)field_2     // CONFIRMED @ 0x404569 [esp+0x134], N=5 stack pushes
    );                                      // finalize → EBX = stack+0x38 @ 0x404575–0x404579
}

// Phase B — recv CounterLoad (field_0 == 0)
uint8_t counter_src[16] = digest[0..15];    // lea ecx,[esp+0x38] @ 0x401179 (post-HMAC esp)
Crypto_CounterLoad(counter_src, recv_ctx_0); // eax=0x023037F0 @ 0x401174
Crypto_CounterLoad(counter_src, recv_ctx_1); // eax=0x02303940 @ 0x401182

uint8_t key_seed[16] = digest[16..31];      // [esp+0x48..0x57] @ 0x401190–0x4011EB → globals
```

**CounterLoad input is not XORed with PRNG.** No extra 8-byte prefix: the apparent `stack+0x40` vs `stack+0x38` gap is the two `push`es before `call 0x40404420` (`0x401156`–`0x40115b`); after `add esp,8` @ `0x401169`, digest base aligns with `lea ecx,[esp+0x38]` @ `0x401179`.

Post-`CounterLoad` dword permute @ `0x40468D`–`0x40470C` (applied inside `Crypto_CounterLoad` before AES-128 key expansion):

```c
for (int i = 0; i < 4; i++) {
    uint32_t x = counter_src[i];  // as uint32le[4]
    uint32_t t = _rotr(x, 8) & 0xFF00FF00u;
    uint32_t u = _rotl(x, 8) & 0x00FF00FFu;
    ctx->counter_u32[i] = t | u;  // → ctx+0xF4
}
```

Runtime CTR increment: `StreamCrypt_XOR` @ `0x00404DF0` treats `ctx+0xF4..0x100` as 128-bit LE counter.

---

## `Crypto_ProcessKeyPacket` @ `0x00401100`

### Phase A — PRNG + HMAC (`field_0` path common)

1. **`DAT_023037e0 ← field_0`** @ `0x401140`
2. **`Crypto_PRNGFill` @ `0x00404610`** — LCG fills **128 B** at stack `esp+0x58` (seed `DAT_02303a8c`)
3. **`Crypto_HMAC_Derive` @ `0x00404420`**
   - Stack args (cdecl): `[esp+0x11c]` → PRNG buffer pointer; `[esp+0x120]` → zero-extended `field_2` (preserved through frame; read via `[esp+0x134]` @ `0x404569` with **N=5** outstanding pushes: `ebp/esi/edi` @ `0x40443B`–`0x40443D`, PRNG ptr @ `0x404440`, `block_b` @ `0x404568`)
   - `ECX` = `block_b`; `EBX` = digest out (`lea ebx,[esp+0x40]` @ `0x40115E` → caller `stack+0x38` after arg pops)
4. **Branch on `field_0`** @ `0x40116C`

### Phase B — recv path (`field_0 == 0`) → counter @ `ctx+0xF4`

| Call | `EAX` (ctx base) | `ECX` (16 B source) | Effect |
|------|------------------|---------------------|--------|
| 1st `0x00404680` | `0x023037F0` | `esp+0x38` = `digest[0..15]` | Recv stream ctx: counter permute + AES-128 key schedule |
| 2nd `0x00404680` | `0x02303940` | same | Secondary recv ctx (`0x23037F0 + 0x150`) |

Counter VA after load: **`0x023037F0 + 0xF4 = 0x023038E4`** (matches `StreamCrypt_XOR` @ `0x00404DF0`).

`digest[16..31]` @ `esp+0x48..0x57` copied to key-seed globals `0x023027C0..0x023027CC` and mirrored to counter shadow copies @ `0x401190`–`0x4011EB`.

### Phase C — send path (`field_0 != 0`)

Copies full 32 B digest block to `0x02303908` / `0x02303A58`, calls **`Crypto_CounterAdvance` @ `0x00401500`** (LCG mutate `@ ctx+0xC`), sets partial-byte counters to 0. No direct `CounterLoad` on this branch.

### Phase D — ack material (`0x00404F90` + `0x00405050`)

Builds `std::vector`-like blob: **`memcpy(block_b, field_1)`** @ `0x404F96` then **`memcpy(block_a, field_2)`** @ `0x404FEA`.  
`0x00405050` packs vector + PRNG buffer (`esp+0x58`) into 128 B client output → `NetworkSendKeyFollowUp` sends **`0x00A101`** / **131 B** @ `0x005EC5A0`.

---

## HMAC-SHA256 @ `0x00404420`

**CONFIRMED pipeline** (disassembly):

| Stage | VA | Operation |
|-------|-----|-----------|
| Pre-key | `0x404434`–`0x404496` | `SHA256(prng[0..127])` — data ptr `[esp+0x11c]`, len `0x80` |
| ipad/opad | `0x4044F0`–`0x404504` | Standard `0x36` / `0x5C` XOR on 64 B blocks |
| Inner | `0x404506`–`0x404579` | `SHA256(ipad_key)` then `SHA256_update(block_b, field_2)` @ `0x404564`–`0x404570`; finalize 32 B → `EBX` |
| Outer | `0x40457E`–`0x4045E8` | `SHA256(opad_key)` + inner digest (`0x20` bytes) → final 32 B digest (same `EBX` buffer) |

Standard SHA-256 IV constants @ `0x404456`–`0x40448E`, `0x40451F`–`0x404557`, `0x404593`–`0x4045CB`.

---

## `Crypto_CounterLoad` @ `0x00404680`

**Calling convention:** `__fastcall` — `ECX` = src `uint32[4]`, `EAX` = dst ctx pointer.

**CONFIRMED** @ `0x404693`: `ctx+0xF0 = 10` (AES-128 rounds).

Then **AES-128 key expansion** (T-tables `0x00790760`, round constants `0x00791F64..`) writes round keys @ `ctx+0x100..`.

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
2. Break `@ 0x401162` (pre-HMAC) — confirm `ECX` = `block_b`, stack `[esp+4]` = PRNG ptr, `[esp+8]` = `(u32)field_2`.
3. Break `@ 0x404569` — confirm `EAX == (uint8_t)field_2` (inner HMAC length).
4. Break `@ 0x40117D` — dump 16 B at `ECX`; must equal first 16 B at `EBX`/stack+0x38 after HMAC (pre-permute).
5. Break `@ 0x401740` after `CounterLoad` — dump `0x23038E4..0x23038F3` (initial CTR after permute).
6. Compare with server `Connection_InitStreamCrypto` @ `ps_game.exe` `0x00464E60` (server-side counter copy).

---

## Confidence summary

| Claim | Tag |
|-------|-----|
| 195 B layout + handler → `0x401100` chain | **CONFIRMED** |
| `field_0==0` → `CounterLoad` → `0x23037F0+0xF4` | **CONFIRMED** (`0x401174`–`0x40118B`) |
| `field_1` / `field_2` as slice lengths in `0x404F90` | **CONFIRMED** (`0x404F96`, `0x404FEA`) |
| HMAC pre-key = `SHA256(PRNG[128])` | **CONFIRMED** (`0x404434`, len `0x80`) |
| HMAC inner msg = `block_b[0..field_2]` | **CONFIRMED** (`0x404564`–`0x404570`, `[esp+0x134]` → `field_2`) |
| `CounterLoad` input = HMAC digest `[0..15]` @ stack+0x38 | **CONFIRMED** (`0x40115E`/`0x401179`, no PRNG XOR) |
| Key-seed globals = HMAC digest `[16..31]` | **CONFIRMED** (`0x401190`–`0x4011EB`, stack+0x48) |
| HMAC-SHA256 with SHA-256 IV + ipad/opad | **CONFIRMED** (`0x40404420`) |
| Dword permute formula @ `0x40404680` | **CONFIRMED** |
| Server `0xA101` outbound opcode | **Not mapped** |
