# Server outbound key blob RE — P0 (May 2026)

Scope: `.features/Shaiya-Core-V7/server/*.exe`, focus `ps_game.exe` + cross-binary scan for client-recv equivalent `0xA101`.

| Binary | MD5 | ImageBase |
|--------|-----|-----------|
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` | `0x00400000` |
| `ps_login.exe` | `de5b348cca36e0585f06be93f013fa6d` | `0x00400000` |

Method: PE section map + static `E8` xref scan + `mov word [esp+disp], imm16` opcode-writer scan across all server `.exe`.

---

## CONFIRMED — outbound `0xA101` is sent by `ps_login.exe`, not `ps_game.exe`

| Item | Evidence |
|------|----------|
| **Only `mov word […], 0xA101` writer in server tree** | `ps_login.exe` @ **`0x00404DD3`** inside **`SendKeyBlob_A101` @ `0x00404DA0`** |
| **Payload size** | `push 0xC5` (**197** = `u16 opcode` + **195 B body**) — matches client `Handler_Packet_A101_KeyMaterial` @ `0x005E3D60` |
| **Send primitive** | `call Connection_Send @ 0x00410AE0` from `0x00404E3E` |
| **Caller** | **`0x00401CDF`** (connection state machine on login socket) |
| **`ps_game.exe`** | **Zero** `mov word [esp+disp], 0xA101` sites; `0xA101` byte hits are **pointer addresses** (e.g. `0x0109186C`), not opcodes |

### `SendKeyBlob_A101` @ `0x00404DA0` (ps_login.exe) — disassembly summary

Full byte-a-byte map (server stack **`F`** → wire **`W=F+0x10`**): [`LOGIN_A101_BODY_MAP.md`](LOGIN_A101_BODY_MAP.md).

```
00404DCE  mov word [F+0x10], 0xA101       ; W+0 opcode
00404DD5  mov byte [F+0x12], 0            ; W+2 field_0 (always 0)
00404DDA  lea  edi, [F+0x15]              ; block_a dest = W+5
00404DDE  push 0xC5                       ; total plaintext 197 B
00404DEA  lea  eax, [0x454C74 + idx*0x84] ; key-table slot (rand()%DAT_454C70)
00404DF1  mov [conn+0x18], eax            ; stash slot ptr on connection
00404DF4… rep movsd block_a ← [slot+0x08], len [slot+0x04]*4
00404E1F  lea  edi, [esp+0x59]            ; block_b dest = F+0x55 = W+0x45
00404E23… rep movsd block_b ← [slot+0x20], len [slot+0x1C]*4
00404E2C  mov [F+0x13], dl                ; W+3 field_1 = (u8)(block_a byte len)
00404E33  lea  ecx, [esp+0x14]            ; send ptr = F+0x10 (after push 0xC5)
00404E3A  mov [F+0x14], bl                ; W+4 field_2 (after push ecx; esp=F-8)
00404E3E  call Connection_Send @ 0x410AE0
00404E4A  call PostSend_StateTransition @ 0x42E427
```

Pre-send PRNG index: `KeyDeriv_PRNG` @ `0x0042D77E` (`call` @ `0x00404DBE`).

### Key table `DAT_00454C74` (stride `0x84`)

| Item | Evidence |
|------|----------|
| **16 slots** | Loop `0x454C74` … `< 0x4554B4` @ `0x4065E4`–`0x4065EA` |
| **Slot count** | `DAT_00454C70` incremented each init iteration @ `0x4065DE` |
| **Init** | `KeyTable_GlobalInit` @ `0x00406380` → `KeyTable_SlotInit(0x400,0)` @ `0x00409AE0` |
| **Send index** | `rand() % DAT_454C70` @ `0x404DC4` |

Slot fields used at send: **`+0x04/+0x08`** (block_a count/ptr), **`+0x1C/+0x20`** (block_b count/ptr). See [`LOGIN_A101_BODY_MAP.md`](LOGIN_A101_BODY_MAP.md).

### Ghidra decomp exports (2026-05-26)

Regenerate:

```bash
./tools/ghidra/decompile-pslogin-crypto.sh
```

| Category | Symbol | VA | Export |
|----------|--------|-----|--------|
| keypath | `SendKeyBlob_A101` | `0x00404DA0` | [`../pslogin-chat-native/keypath/SendKeyBlob_A101_00404da0.c`](../pslogin-chat-native/keypath/SendKeyBlob_A101_00404da0.c) |
| keypath | `Connection_Send` | `0x00410AE0` | [`../pslogin-chat-native/keypath/Connection_Send_00410ae0.c`](../pslogin-chat-native/keypath/Connection_Send_00410ae0.c) |
| keypath | `Caller_StateMachine` | `0x00401CDF` | [`../pslogin-chat-native/keypath/Caller_StateMachine_00401cdf.c`](../pslogin-chat-native/keypath/Caller_StateMachine_00401cdf.c) *(landmark; entry `0x401C70`)* |
| keypath | `Login_Dispatcher` | `0x00403810` | [`../pslogin-chat-native/keypath/Login_Dispatcher_00403810.c`](../pslogin-chat-native/keypath/Login_Dispatcher_00403810.c) |
| keypath | `Connection_EnqueueKeyBlob` | `0x00401C70` | [`../pslogin-chat-native/keypath/Connection_EnqueueKeyBlob_00401c70.c`](../pslogin-chat-native/keypath/Connection_EnqueueKeyBlob_00401c70.c) |
| handlers | `Login_OpcodeDispatch` | `0x004042F0` | [`../pslogin-chat-native/handlers/Login_OpcodeDispatch_004042f0.c`](../pslogin-chat-native/handlers/Login_OpcodeDispatch_004042f0.c) |
| crypto | `KeyDeriv_PRNG` | `0x0042D77E` | [`../pslogin-chat-native/crypto/KeyDeriv_PRNG_0042d77e.c`](../pslogin-chat-native/crypto/KeyDeriv_PRNG_0042d77e.c) |
| crypto | `KeyTable_SlotInit` | `0x00409AE0` | [`../pslogin-chat-native/crypto/KeyTable_SlotInit_00409ae0.c`](../pslogin-chat-native/crypto/KeyTable_SlotInit_00409ae0.c) |
| keypath | `KeyTable_GlobalInit` | `0x00406380` | [`../pslogin-chat-native/keypath/KeyTable_GlobalInit_00406380.c`](../pslogin-chat-native/keypath/KeyTable_GlobalInit_00406380.c) |
| keypath | `PostSend_StateTransition` | `0x0042E427` | [`../pslogin-chat-native/keypath/PostSend_StateTransition_0042e427.c`](../pslogin-chat-native/keypath/PostSend_StateTransition_0042e427.c) |
| pipeline | `Connection_RecvAppend` | `0x00403080` | [`../pslogin-chat-native/pipeline/Connection_RecvAppend_00403080.c`](../pslogin-chat-native/pipeline/Connection_RecvAppend_00403080.c) |

Manifest: [`tools/ghidra/pslogin-crypto-functions.manifest`](../tools/ghidra/pslogin-crypto-functions.manifest) (17 functions).

---

## CONFIRMED — `ps_login.exe` receives client `0xA102` ack

| VA | Role |
|----|------|
| `0x00403810` | Login packet dispatcher (handles inbound opcodes) |
| `0x00404375` | `cmp/sub` against **`0xA101`** (and branches for `0xA200`, `0xA100`) |
| `0x00404611`, `0x004049A5`, `0x004049F2` | **`mov word [esp+disp], 0xA102`** — outbound error/status replies inside dispatcher |
| `0x404375` context | Reads client ack body after opcode match |

No `mov word …, 0xA101` in `ps_session.exe`, `ps_dbAgent.exe`, or other server `.exe` — only `ps_login.exe`.

---

## CONFIRMED — `ps_game.exe` stream-crypto init xref chain (distinct from A101 wire send)

### `Connection_InitStreamCrypto` @ `0x00464E60`

| | |
|---|---|
| **Callers** | **1** — **`0x00413CB5`** only |
| **Action** | `AES_KeyExpand` (via `0x004E2CE0`); copy `[esi+0x10..0x1C]` → ctx `+0xF4`; mirror to `+0x20C`; set `conn+0x230=1`, `conn+0x231=1` |

### Site `0x00413CB5` (inside `ZoneCryptoInit` @ `0x00413B30`)

Immediately before `call 0x464E60`:

```
00413CA5  lea edi, [ebx+0x55C0]
00413CAD  mov ecx, 8
00413CB0  rep movsd                     ; copy 8×u32 (32 B) from stack → conn+0x588C
00413CB5  call Connection_InitStreamCrypto
```

Parent callers of **`0x00413B30`**: **`0x00406C1B`**, **`0x00406C52`** (large login/character orchestrator @ `~0x406000`).

**Not** called from `Handler_Packet1201` or `0x453CB0`.

### `Handler_Packet1201` @ `0x0047FCC0`

| | |
|---|---|
| **Callers** | **1** — **`0x00474ECC`** (`CUser_DispatchPacket_Main` — opcode **`0x1200`**) |
| **Body check** | `cmp word [eax], 0x1201` @ `0x0047FCC1` |
| **Callees** | `FUN_00453CB0` @ `0x0047FCFC` (zone-name processing) — **does not** call `0x464E60` or `0x413B30` |

---

## CONFIRMED — `0x004C6xxx` cluster `0x1109`–`0x110B` is chat send, not key path

| VA | Pattern | Conclusion |
|----|---------|------------|
| `0x004C6ADE` | `mov word [esp+0x10], 0x1109` | Chat/broadcast builder (`FUN_004C6A80`) |
| `0x004C6FC8` | `mov dword [esp+0x33], …; mov word [esp+0x30], 0x1109` | Chat builder (`FUN_004C6F50`) |
| `0x004C8543` | `mov ecx, 0x110B` | Same family |

No xref from these sites to `Connection_InitStreamCrypto`, `SendKeyBlob`, or key tables.

---

## Reproduction recipe

```bash
# Opcode-writer scan (all server EXEs)
python3 - <<'PY'
# see shaiya-chat-native-re/tools/ — pattern: 66 C7 44 24 ?? 01 A1
PY

# Static xrefs in ps_game.exe
python3 - <<'PY'
# E8 rel32 scan in .text for targets 0x464E60, 0x47FCC0, 0x413B30
PY

objdump -d .features/Shaiya-Core-V7/server/ps_login.exe | less  # VA 0x404DA0
./tools/ghidra/decompile-pslogin-crypto.sh                   # Ghidra → pslogin-chat-native/
objdump -d .features/Shaiya-Core-V7/server/ps_game.exe   | less  # VA 0x413CB5, 0x4C6ADE
```

---

## Cross-reference

- **Byte-a-byte body map (server build ↔ client parse):** [`LOGIN_A101_BODY_MAP.md`](LOGIN_A101_BODY_MAP.md)
- Client recv path (closed): [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) Step 4
- Client handler: `game-chat-native/handlers/Handler_Packet_A101_KeyMaterial_005e3d60.c`
- Server login key send: `pslogin-chat-native/keypath/SendKeyBlob_A101_00404da0.c`
- Server crypto init (ps_game): `psgame-chat-native/crypto/Connection_InitStreamCrypto_00464e60.c`
