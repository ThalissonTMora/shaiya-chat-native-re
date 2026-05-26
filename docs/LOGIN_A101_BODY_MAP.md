# Login `0xA101` body map — server build ↔ client parse

Evidence: `ps_login.exe` `MD5=de5b348cca36e0585f06be93f013fa6d`, `Game.exe` `MD5=c1edd96639ad81835624b9c4516ac781`, `ImageBase=0x00400000` both.  
Companion: [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md), [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md), [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md).

Regenerate decomps: `./tools/ghidra/decompile-pslogin-crypto.sh`, `./tools/ghidra/decompile-crypto.sh`

---

## Scope

| Side | Function | VA | Artifact |
|------|----------|-----|----------|
| Server send | `SendKeyBlob_A101` | `0x00404DA0` | `pslogin-chat-native/keypath/SendKeyBlob_A101_00404da0.c` |
| Client recv | `Handler_Packet_A101_KeyMaterial` | `0x005E3D60` | `game-chat-native/handlers/Handler_Packet_A101_KeyMaterial_005e3d60.c` |
| Client crypto | `Crypto_ProcessKeyPacket` | `0x00401100` | `game-chat-native/crypto/Crypto_ProcessKeyPacket_00401100.c` |
| Key table | `DAT_00454C74` stride `0x84` | — | `pslogin-chat-native/crypto/KeyTable_SlotInit_00409ae0.c` |

---

## Wire record (plaintext, pre-login XOR)

| Layer | Size | Notes |
|-------|------|-------|
| TCP envelope | `u16 wire_len` + payload | See [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) Step 1 |
| Plaintext payload | **197 B** | `push 0xC5` @ `0x404DDE` → `Connection_Send` @ `0x410AE0` |
| Opcode | 2 B | `mov word [esp+0x10], 0xA101` @ `0x404DCE` |
| Body | **195 B** | Handler reads via five `PacketRead` @ `0x005F4700` |

Send buffer pointer passed to `Connection_Send`: **`lea ecx,[esp+0x14]` @ `0x404E33`**, which equals **frame+0x10** after accounting for the intervening **`push 0xC5`** (@ `0x404DDE`).

---

## Byte-a-byte map (server → client)

Stack frame in `SendKeyBlob_A101`: **`sub esp,0xD4`** @ `0x404DA6`. Below, **`F`** = value of `esp` after the prologue (before `push 0xC5`). **`W`** = wire offset from send base **`F+0x10`**.

| W off | F off | Size | Wire field | Server write (VA) | Client read (VA) | Client local | Semantics |
|------:|------:|-----:|------------|-------------------|------------------|--------------|-----------|
| `+0x00` | `+0x10` | 2 | `opcode` | `mov word [F+0x10],0xA101` @ `0x404DCE` | dispatcher @ `0x005F1E10` | — | **`0x00A101` LE** |
| `+0x02` | `+0x12` | 1 | `field_0` | `mov byte [F+0x12],0` @ `0x404DD5` | `PacketRead` 1 @ `0x005E3D85` | `local_d0` | **Always 0** on server → recv `CounterLoad` path @ `0x40116C` |
| `+0x03` | `+0x13` | 1 | `field_1` | `mov [F+0x13],dl` @ `0x404E2C` *(esp after `push 0xC5`)* | `PacketRead` 1 @ `0x005E3D93` | `local_cc` | **`(u8)(slot[+0x04] × 4)`** — block_a byte length (low byte) |
| `+0x04` | `+0x14` | 1 | `field_2` | `mov [F+0x14],bl` @ `0x404E3A` *(after `push 0xC5` + `push ecx`)* | `PacketRead` 1 @ `0x005E3DA1` | `local_c8` | **`(u8)(slot[+0x1C] × 4)`** — block_b byte length (low byte) |
| `+0x05` … `+0x44` | `+0x15` … `+0x54` | 64 | `block_a[0..63]` | `rep movsd/movsb` from `[slot+0x08]` @ `0x404DF4–0x404E0F` | `PacketRead 0x40` @ `0x005E3DAF` | `local_c4[64]` | Fixed **64 B** wire slot; copy length = `slot[+0x04]×4` (typically 64) |
| `+0x45` … `+0xC4` | `+0x55` … `+0xD4` | 128 | `block_b[0..127]` | `rep movsd/movsb` from `[slot+0x20]` @ `0x404E11–0x404E2A` | `PacketRead 0x80` @ `0x005E3DBE` | `local_84[128]` | Fixed **128 B** wire slot; copy length = `slot[+0x1C]×4` (typically 128) |

**Total:** `2 + 1 + 1 + 1 + 64 + 128 = 197` bytes (`0xC5`).

### Stack-build order (CONFIRMED @ `0x404DA0`)

```
1. mov opcode, field_0
2. lea edi,[F+0x15]          ; block_a dest (absolute — before push 0xC5)
3. push 0xC5
4. index slot: rand()%DAT_454C70, stride 0x84 from DAT_454C74
5. rep movsd/movsb block_a → F+0x15
6. lea edi,[esp+0x59]        ; block_b dest = F+0x55 (esp = F-4)
7. rep movsd/movsb block_b → F+0x55
8. mov [F+0x13],dl           ; field_1 (esp still F-4)
9. lea ecx,[esp+0x14]        ; send ptr = F+0x10
10. push ecx
11. mov [F+0x14],bl          ; field_2 (esp = F-8 after step 10)
12. call Connection_Send
```

**Critical:** `field_1` / `field_2` stores use **different `esp` bases** (one vs two stack pushes after `push 0xC5`). Naïve `local_d5`/`local_d4` Ghidra names at `F+0x17`/`F+0x1C` are **wrong** for wire offsets — always use **`F+0x13` / `F+0x14`**.

---

## Client handler → crypto argument shuffle

Handler reads wire **sequentially** (`field_0`, `field_1`, `field_2`, `block_a`, `block_b`).  
`Connection_OnKeyMaterial` @ `0x005A4D50` reorders for `Crypto_ProcessKeyPacket` @ `0x00401100`:

| Wire field | `Connection_OnKeyMaterial` param | `ProcessKeyPacket` param | Role @ `0x401100` |
|------------|----------------------------------|--------------------------|-------------------|
| `field_0` | `param_2` | `param_3` → `DAT_023037e0` | Recv (`0`) vs send branch @ `0x40116C` |
| `field_1` | `param_4` | `param_6` | **`block_b` append** len @ `0x404F96` (`EBX` in `0x40404F90`) |
| `field_2` | `param_3` | `param_7` | **HMAC inner length** on **`block_b`** @ `0x404569`; **`block_a` append** len @ `0x404FEA` |
| `block_a` | `param_5` | `param_4` | 64 B wire blob (not HMAC message ptr) |
| `block_b` | `param_6` | `param_5` → `ECX` @ `0x40115C` | HMAC message base |

Shuffle evidence: handler vtable call `(field_0, field_1, field_2, block_a, block_b)` → `Connection_OnKeyMaterial` @ `0x005A4D50` → `Crypto_ProcessKeyPacket(..., field_0, block_a, field_1, block_b, field_2)` — see `Connection_OnKeyMaterial_005a4d50.c` L25.

Vtable dispatch: `[conn+0] + 0x254` @ **`0x00747798`** → **`0x005A4D50`**.

Typical slot (`slot[+0x04]=0x10`, `slot[+0x1C]=0x20`): server writes **`field_1=0x40`** (block_a byte count), **`field_2=0x80`** (block_b byte count) → client HMAC over **`block_b[0..0x7F]`** (`field_2`), ack vector appends **`block_b[0..field_1)` + `block_a[0..field_2)`** per `0x40404F90`.

---

## Key table `DAT_00454C74` (stride `0x84`)

| Item | Value | Evidence |
|------|-------|----------|
| Base | `0x00454C74` | `lea …,[0x454C74+idx*0x84]` @ `0x404DEA` |
| Stride | **`0x84` (132 B)** | `add esi,0x84` @ `0x4065E4` |
| Slot count | **`DAT_00454C70`** | `idiv [0x454C70]` @ `0x404DC4`; incremented in init loop @ `0x4065DE` |
| End sentinel | `0x004554B4` | `cmp esi,0x4554B4` @ `0x4065EA` → **16 slots** `(0x554B4−0x54C74)/0x84` |
| Per-connection back-ref | `conn[+0x18] = slot*` | `mov [esi+0x18],eax` @ `0x404DF1` (`param_1` = conn blob @ `+0x13C`) |

### Slot layout (132 B stride) — CONFIRMED structure

Each table entry is a **dense array of ~11 GMP-style `bigint` objects** (12 B header each: `capacity`, `limb_count`, `limbs*`). `KeyTable_PreSlotInit` @ `0x00409750` zero-inits them before crypto (`FUN_00421dd0` × 11 @ `+0x00..+0x78`).

| Slot off | Ghidra index | Role in `KeyTable_SlotInit` | `SendKeyBlob` use |
|----------|--------------|-----------------------------|-------------------|
| `+0x00` | `in_EAX+0` | **Public exponent `e`** (random odd, trial-div loop vs `N`) | — |
| `+0x04` | limb count | **`word_count_a`** → `field_1 = (u8)(count×4)` | **CONFIRMED** @ `0x404DE2` |
| `+0x08` | `limbs*` | **`block_a` bytes** (`rep movsd` source) | **CONFIRMED** @ `0x404DF4` |
| `+0x0C` | `in_EAX+3` | **Modulus `N = p·q`** (`BigInt_modMul`) | not sent on wire |
| `+0x18` | `in_EAX+6` | **Wire blob #2** (filled by final `BigInt_modMul(p,q)` @ L78) | — |
| `+0x1C` | limb count | **`word_count_b`** → `field_2 = (u8)(count×4)` | **CONFIRMED** @ `0x404E1F` |
| `+0x20` | `limbs*` | **`block_b` bytes** (`rep movsd` source) | **CONFIRMED** @ `0x404E23` |
| `+0x24` | `in_EAX+9` | Temp prime candidate **`p`** | internal |
| `+0x30` | `in_EAX+0xC` | Temp prime candidate **`q`** | internal |
| `+0x3C` | `in_EAX+0xF` | Copy of **`p`** (`BigInt_exportCopy`, `+1`) | internal |
| `+0x48` | `in_EAX+0x12` | Copy of **`q`** (`BigInt_exportCopy`, `+1`) | internal |
| `+0x54` | `in_EAX+0x15` | Compared in `BigInt_cmp` vs `p`,`q` | internal |

**CONFIRMED:** `block_a` / `block_b` are **not separate `malloc` buffers** — they are the **limb arrays** (`+0x08`, `+0x20`) of the first and third `bigint` in the slot. `SendKeyBlob` copies `limb_count × 4` bytes little-endian into the stack frame.

**INFERRED wire semantics:** `block_a` ≈ **512-bit public exponent `e`** (16 limbs → 64 B); `block_b` ≈ **1024-bit composite** derived from **`p·q` pipeline** (32 limbs → 128 B). Client treats them as opaque octet strings for HMAC/ack (`CRYPTO_COUNTER.md`).

### `KeyTable_SlotInit` pipeline @ `0x00409AE0`

**Prototype (CONFIRMED disasm @ `0x409AEA`):** `void __fastcall KeyTable_SlotInit(int bit_param, int alt_seed)` — `EAX` = slot pointer; `bit_param` pushed (`0x400` at all call sites); `alt_seed` pushed (`0` in production).

| Step | VA / callee | Action | Tag |
|------|-------------|--------|-----|
| 0 | `KeyTable_PreSlotInit` @ `0x409750` | Optional; called before dynamic growth @ `0x40F3A5`, not in `GlobalInit` loop | CONFIRMED |
| 1 | `BigInt_ctor` @ `0x423430` → `BigInt_poolInit` @ `0x4272F0` | Stack RNG pool `local_14` (32 limbs capacity) | CONFIRMED |
| 2 | `__time32` @ `0x42D892` + `BigInt_seedTime` @ `0x422730` | Seeds pool with `time()` via `KeyTable_SlotAltInit` (single-limb store) | CONFIRMED |
| 3 | `bitlen = bit_param >> 1` | `0x400 → 0x200` bits per half-prime | CONFIRMED @ `0x409B09` |
| 4 | `BigInt_randBits` @ `0x4233D0` + `BigInt_sub` @ `0x4225A0` | Random at `slot+0x24` (`p`): clear bits `bitlen-1`, `bitlen-2`, `0` | CONFIRMED |
| 5 | `BigInt_assign` @ `0x422910` | Force odd / pass quick prime screen (`BigInt_bitTestMod5` @ `0x424D40`) | INFERRED |
| 6 | Repeat 4–5 at `slot+0x30` (`q`) | Second prime | CONFIRMED |
| 7 | `BigInt_exportCopy` @ `0x422100` | `slot+0x3C ← p+1`, `slot+0x48 ← q+1` (add limb `1`) | CONFIRMED |
| 8 | `BigInt_modMul` @ `0x421EF0` | **`N = p·q` → `slot+0x0C`** | CONFIRMED |
| 9a | `param_2 == 0` (production) | Random odd at `slot+0` (`e`); trial-div loop: `BigInt_mod` + while `BigInt_isZero(mod,1)≠0` → `e×=2` | CONFIRMED @ `0x409BA4–0x409C68` |
| 9b | `param_2 != 0` | `KeyTable_SlotAltInit(e, param_2)` — inject seed limb | CONFIRMED |
| 10 | `BigInt_cmp` @ `0x4236B0` ×2 | Guards before CRT step | CONFIRMED |
| 11 | `BigInt_powMod` @ `0x421E50` | CRT prep on `slot+0x3C`, `slot+0x48` vs `N` | INFERRED (opaque modexp) |
| 12 | `BigInt_modMul` @ `0x421EF0` | **`slot+0x18 ← p·q`** (overwrites bigint #2 → **`block_b` limbs**) | CONFIRMED |

**HYPOTHESIS:** Full math is **RSA-like key generation** (512-bit primes, 1024-bit `N`, coprime `e`). Exact semantic of final `powMod` + second `modMul` is **not required for wire replay** — only limb dumps at `+0x08` / `+0x20` matter.

**Dead / unused in this binary:** `KeyTable_SlotSerialize` @ `0x409CE0` — **0** direct `E8` xrefs (orphan). `KeyTable_SlotHelper` @ `0x409D60` — same.

### Callee map (regenerate)

```bash
./tools/ghidra/decompile-mini.sh pslogin tools/ghidra/keytable-slotinit-callees.manifest
./tools/ghidra/decompile-mini.sh pslogin tools/ghidra/keytable-slotinit-extra.manifest
```

| Symbol | VA | Artifact |
|--------|-----|----------|
| `KeyTable_SlotInit` | `0x00409AE0` | `crypto/KeyTable_SlotInit_00409ae0.c` |
| `KeyTable_PreSlotInit` | `0x00409750` | `crypto/KeyTable_PreSlotInit_00409750.c` |
| `BigInt_randBits` | `0x004233D0` | `crypto/BigInt_randBits_004233d0.c` |
| `BigInt_randFill` | `0x00426F90` | `crypto/BigInt_randFill_00426f90.c` |
| `BigInt_modMul` | `0x00421EF0` | `crypto/BigInt_modMul_00421ef0.c` |
| `BigInt_mod` | `0x004221B0` | `crypto/BigInt_mod_004221b0.c` |
| `BigInt_powMod` | `0x00421E50` | `crypto/BigInt_powMod_00421e50.c` |
| `BigInt_bitTestMod5` | `0x00424D40` | `crypto/BigInt_bitTestMod5_00424d40.c` |
| `KeyTable_GrowSlots` | `0x00406960` | `crypto/KeyTable_GrowSlots_00406960.c` |
| `KeyTable_AllocOne` | `0x004069D0` | `crypto/KeyTable_AllocOne_004069d0.c` |

### Who populates the table

| Phase | Function | VA | Action |
|-------|----------|-----|--------|
| Process startup | `KeyTable_GlobalInit` | `0x00406380` | After INI/session connect @ `0x406578`; `EAX=&DAT_00454C74`, loop `+0x84` until `0x4554B4` |
| Per slot | `KeyTable_SlotInit` | `0x00409AE0` | `KeyTable_SlotInit(0x400, 0)` — fills bigint limbs → **`+0x04/+0x08`**, **`+0x1C/+0x20`** |
| Dynamic growth | `KeyTable_GrowSlots` / `KeyTable_AllocOne` | `0x406960` / `0x4069D0` | Extra slots @ `parent+0x14`, `KeyTable_PreSlotInit` first @ `0x40F3A5` |
| Per send | `SendKeyBlob_A101` | `0x00404DA0` | `KeyDeriv_PRNG` @ `0x42D77E` → `idx = rand() % DAT_454C70`; **`rep movs*` limb copy** |
| Per send (state) | same | | `mov byte [conn+0x15],1` @ `0x404DCA` |

**SlotInit callers (CONFIRMED E8 scan):** `0x4065D9` (`GlobalInit`), `0x406979`/`0x4069B9`/`0x406A09` (growth), `0x40F3B6` (pre-init path).

### Emulator: must it regenerate blobs?

| Approach | Viable? | Notes |
|----------|---------|-------|
| **Replay fixed 16 slots** captured from real `ps_login` | **CONFIRMED yes** | Send path only reads `+0x04/+0x08/+0x1C/+0x20`; no per-connection re-roll |
| **Reimplement `KeyTable_SlotInit`** | **HYPOTHESIS** | Needs GMP-like layer (`BigInt_*`), `time()`-seeded pool, matching `rand()` if growth path runs |
| **Arbitrary 64+128 B** | **No** | Client `Crypto_ProcessKeyPacket` derives session keys/HMAC from exact bytes |

See [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md) — emulator slot reuse note.

---

## Reproduction checklist

```bash
# Server builder disasm
objdump -d --start-address=0x404DA0 --stop-address=0x404E50 \
  shaiya-chat-native-re/bin/ps_login.exe

# Client handler disasm
objdump -d --start-address=0x005E3D60 --stop-address=0x005E3DD0 \
  shaiya-chat-native-re/bin/Game.exe

# Key table init loop
objdump -d --start-address=0x4065B0 --stop-address=0x406600 \
  shaiya-chat-native-re/bin/ps_login.exe
```

Dynamic validation:

1. Break `@ 0x404E3E` — dump **`F+0x10..F+0xD4`** (197 B) before IOCP send.
2. Break `@ 0x005E3DA1` — confirm **`field_2`** byte matches server dump @ **`W+0x04`**.
3. Break `@ 0x401162` — **`ECX`** = `block_b`; stack arg = **`field_1`** (HMAC length).
4. Break `@ 0x404569` — **`EAX == (u8)field_1`**.

---

## Confidence summary

| Claim | Tag |
|-------|-----|
| 197 B wire record (`0xC5`) | **CONFIRMED** (`0x404DDE`, `0x404E3E`) |
| Body layout 3 + 64 + 128 | **CONFIRMED** (handler five reads @ `0x005E3D60`) |
| `field_1`/`field_2` at **`F+0x13`/`F+0x14`** (not `F+0x17`/`F+0x1C`) | **CONFIRMED** (push-adjusted `mov` @ `0x404E2C`/`0x404E3A`) |
| `block_a` @ **`W+0x05`**, `block_b` @ **`W+0x45`** | **CONFIRMED** (`lea`/`rep movs` @ `0x404DDA`–`0x404E2A`) |
| Slot stride **`0x84`**, **`rand()%count`** index | **CONFIRMED** |
| Slot init @ startup `KeyTable_GlobalInit` | **CONFIRMED** (`0x40657E`–`0x4065E4`) |
| `field_1` = HMAC len on **`block_b`** | **CONFIRMED** (`0x401156`/`0x404569`, `0x404F96`) |
| `block_a`/`block_b` = bigint limb arrays @ `+0x08`/`+0x20` | **CONFIRMED** (`SendKeyBlob` + `KeyTable_PreSlotInit` layout) |
| RSA-like pipeline (`p`,`q`, `N=p·q`, coprime `e`) | **INFERRED** (callee chain; `powMod` opaque) |
| Emulator can reuse precomputed 16 slots | **CONFIRMED** (no slot mutation on send) |
