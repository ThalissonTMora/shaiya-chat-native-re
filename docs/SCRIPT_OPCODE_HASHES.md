# Script opcode hashes — `Script_OpcodeDispatch` @ `0x004A2210`

Evidence from `psgame-chat-native/script/Script_OpcodeDispatch_004a2210.c` (Ghidra) cross-checked with `objdump -d bin/ps_game.exe` (MD5 `91b212afbe6623382713772489dc82ce`).

**Scope:** hashed script VM opcodes routed through vtable slot `+4` on the NPC/script object (`CMob` ctor writes `0x00572530` @ `0x004A0802`). Chat impact = client chat box, `SysMsg`, or zone push (`0x11xx` S→C).

**Regenerate:** `./tools/ghidra/decompile-psgame-chat.sh` (full) or subset manifests under `tools/ghidra/psgame-chat-script-chain.manifest` + `psgame-chat-script-opcode-cluster.manifest`.

---

## Chat-relevant paths (CONFIRMED)

Only **two** hashes in `Script_OpcodeDispatch` reach `SConnection_Send` with opcode `0x1109`. Opcodes `0x110A` / `0x110B` use **builtin handler slots** (`.data` table), not hashed opcodes.

| Hash | Call site | Builder VA | Symbol / file | Wire opcode | Script args (via `Script_ArgFetcher` @ `0x004A3000`) | Client recv |
|------|-----------|------------|---------------|-------------|------------------------------------------------------|-------------|
| `0x0B8820F2` | `0x004A22C6` | `0x004C6A80` | `Chat_PacketBuilder_1109_A` · `send/Chat_PacketBuilder_1109_A_004c6a80.c` | **`0x1109`** · flag **`0`** | 1× operand → `message_id` @ `+4` → `ZoneChat_MessageResolver` | `Handler_ChatZone` · vfn `+0x328` case `4`/`5` |
| `0x7C8C3F64` | `0x004A2640` | `0x004C6F50` | `Chat_PacketBuilder_1109_B` · `send/Chat_PacketBuilder_1109_B_004c6f50.c` | **`0x1109`** · flag **`1`** | 1× radius @ `+4`, then 1× `message_id` @ `+4` → spatial cell loop | same |

**Wire (both builders):** `u16le opcode=0x1109` · `u8 flag` · `u32 charId` (`CUser+0x88`) · `u8 len` · `text[len]` (len **1..0x7F** after resolver).

**Tail:** `ZoneChat_MessageResolver` @ `0x004C6970` · party path → `CParty_BroadcastPacket` @ `0x0044E950` · spatial path → per-user `SConnection_Send` @ `0x004ED0E0`.

---

## Builtin wrappers (not hashed — CONFIRMED)

Reached when `Script_ExecuteTick` @ `0x004A4710` finds `instr+0x60 != NULL` and calls the function pointer (not vtable `+4`).

| Builtin slot (`.data`) | Wrapper VA | Builder VA | Opcode | File |
|------------------------|------------|------------|--------|------|
| `0x00581F34` | `0x004CB3D0` | `0x004C8310` | **`0x110A`** | `script/Chat_ScriptWrapper_110A_004cb3d0.c` |
| `0x00581F3C` | `0x004CB430` | `0x004C8520` | **`0x110B`** | `script/Chat_ScriptWrapper_110B_004cb430.c` |

Direct `call rel32` xrefs: `0x004CB41F` → `0x004C8310` · `0x004CB45E` → `0x004C8520`.

---

## `0x004C6xxx` cluster — hashes in dispatch (excluded from chat)

Six additional hashes call functions in the `0x004C5xxx`–`0x004C6xxx` range. **None** emit `0x11xx` or use `SConnection_Send` @ `0x004ED0E0` (verified: `objdump` scan + Ghidra decomp under `psgame-chat-native/script/`).

| Hash | Call site | Callee VA | Symbol / file | Role | Why excluded |
|------|-----------|-----------|---------------|------|--------------|
| `0x1FE5EC34` | `0x004A2397` | `0x004C69F0` | `Script_FlagSetter_2FC` · `script/Script_FlagSetter_2FC_004c69f0.c` | Writes `CMob+0x2FC` script flags | No network I/O |
| `0x2C14EF3C` | `0x004A237A` | `0x004C5D90` | `Script_SpatialEntityPush` · `script/Script_SpatialEntityPush_004c5d90.c` | Spatial user loop → `FUN_004B4010` entity effect + `FUN_004A0DB0` | Entity FX / AI push, not chat packet |
| `0x3246B754` | `0x004A23B6` | `0x004C6BA0` | `Script_SpatialRadiusEffect` · `script/Script_SpatialRadiusEffect_004c6ba0.c` | Radius scan → position write `+0xD2C` / `FUN_00425AF0` | NPC movement / aggro, not chat |
| `0x353AB14E` | `0x004A2494` | `0x004C6A20` | `Script_ZoneTableBroadcast` · `script/Script_ZoneTableBroadcast_004c6a20.c` | Zone table row → `FUN_00424A90` | Zone event table (no `0x11xx`) |
| `0x540B160F` | `0x004A250B` | `0x004C5FD0` | `Script_QuestDialogPush` · `script/Script_QuestDialogPush_004c5fd0.c` | `World_FindUserById` → `FUN_004B9280` | Quest/dialog UI push |
| `0x8A1FEEF8` | `0x004A272B` | `0x004C6EC0` | `Script_ZonePush_0610` · `script/Script_ZonePush_0610_004c6ec0.c` | `local_c = 0x610` → `Zone_PSendViewCells` @ `0x00427CF0` | Zone stat push **`0x0610`**, not chat |

---

## Full `Script_OpcodeDispatch` hash inventory

All `param_2 == 0x…` branches in `Script_OpcodeDispatch_004a2210.c`. **Chat** column: ✅ = affects chat box / SysMsg / zone chat push.

| Hash | Chat | Primary callee / effect |
|------|------|-------------------------|
| `0x0B8820F2` | ✅ | `Chat_PacketBuilder_1109_A` @ `0x004C6A80` |
| `0x7C8C3F64` | ✅ | `Chat_PacketBuilder_1109_B` @ `0x004C6F50` |
| `0x1FE5EC34` | — | `Script_FlagSetter_2FC` @ `0x004C69F0` |
| `0x2C14EF3C` | — | `Script_SpatialEntityPush` @ `0x004C5D90` |
| `0x3246B754` | — | `Script_SpatialRadiusEffect` @ `0x004C6BA0` |
| `0x353AB14E` | — | `Script_ZoneTableBroadcast` @ `0x004C6A20` |
| `0x540B160F` | — | `Script_QuestDialogPush` @ `0x004C5FD0` |
| `0x8A1FEEF8` | — | `Script_ZonePush_0610` @ `0x004C6EC0` |
| `0x7405AD04` | — | `World_FindUserByName` / `FUN_004B4010` (entity attach) |
| `0x335CFA6F` | — | Return script field @ `+0x2D6` via `FUN_004A15D0` |
| `0x0FF3A2FD` | — | Read byte `CMob+0x2D6` |
| `0x072A8C2F` | — | Store `CMob+0x2D8` |
| `0x08A6F4C3` | — | Store `CMob+700` |
| `0x0C726665` | — | `FUN_004B4C50` → return field |
| `0x327674E7` | — | Set bool `CMob+0x2E8` |
| `0x368302A7` | — | Return `CMob+0x1B0` if `+0x1AC` set |
| `0x36824CB7` | — | Return `CMob+0xD5C` |
| `0x38A1F081` | — | Store `CMob+0x2F8` |
| `0x59CCB87B` | — | Clear byte `CMob+0x2DC` |
| `0x603DACB4` | — | `_printf` debug |
| `0x6DD15366` | — | `CMob+0x2FC = 0x01010101` |
| `0xBBFC6D86` | — | Return clamped `CMob+0x2E0` |
| `0x8420F03A` | — | Store `CMob+0x2F0` |
| `0x74AB875E` | — | Random heading / `FUN_004A0330` (movement) |
| `0x899B2549` | — | Set byte `CMob+0x2DC` |
| `0xAE8B3FE1` | — | `FUN_004B4330` bool |
| `0x9602FF4F` | — | Store `CMob+0x2E4` |
| `0xA45C668B` | — | Read byte `CMob+0x2D5` |
| `0xAEC1B010` | — | One-shot flag `CMob+0x2D7` |
| `0xD0DFE84A` | — | Store `CMob+0x2EC` |
| `0xD06189BE` | — | Return float from `FUN_004A02E0` |
| `0xC0785271` | — | Float compare gate |
| `0xC78B4620` | — | HP ratio return |
| `0xD0DFE20B` | — | Store `CMob+0x2F4` + `FUN_004A0DB0` |
| `0xE9F3A815` | — | `_rand() % 100` |
| `0xEE13EBAD` | — | Copy position `+0x7C..+0x84` → `+0xD20` |
| `0xF0A049A9` | — | Clear `CMob+0x2E0` |

---

## Call graph (chat only)

```
Script_ExecuteTick @ 0x004A4710
  └─ [no instr+0x60 handler]
       call [obj+4] → Script_OpcodeDispatch @ 0x004A2210
         ├─ hash 0x0B8820F2 @ 0x004A22C6
         │    Script_ArgFetcher → Chat_PacketBuilder_1109_A @ 0x004C6A80
         │      ZoneChat_MessageResolver @ 0x004C6970 → SConnection_Send (0x1109, flag=0)
         └─ hash 0x7C8C3F64 @ 0x004A2640
              Script_ArgFetcher ×2 → Chat_PacketBuilder_1109_B @ 0x004C6F50
                ZoneChat_MessageResolver → spatial loop → SConnection_Send (0x1109, flag=1)

Script_ExecuteTick @ 0x004A4710
  └─ [instr+0x60 set]
       call builtin → Chat_ScriptWrapper_110A @ 0x004CB3D0 → Chat_PacketBuilder_110A @ 0x004C8310
       call builtin → Chat_ScriptWrapper_110B @ 0x004CB430 → Chat_PacketBuilder_110B @ 0x004C8520
```

---

## Reproduction

```bash
# Full script chain + cluster decomp
./tools/ghidra/decompile-psgame-chat.sh   # uses psgame-chat-functions.manifest

# Subset: script chain only
"$GHIDRA_HOME/support/analyzeHeadless" tools/ghidra/project-psgame PsGameChat \
  -scriptPath tools/ghidra/scripts -import bin/ps_game.exe \
  -processor 'x86:LE:32:default' -overwrite -deleteProject \
  -postScript ExportDecompileByAddress.java psgame-chat-native \
  tools/ghidra/psgame-chat-script-chain.manifest

# Subset: 0x004C6xxx cluster (non-chat callees)
# manifest: tools/ghidra/psgame-chat-script-opcode-cluster.manifest

# Verify chat xrefs (expect exactly two calls into 1109 builders from dispatch)
objdump -d bin/ps_game.exe | grep -E '4a22c6|4a2640|call.*4c6a80|call.*4c6f50'
```

---

## Assumptions & limitations

- Hash values are **build-specific** identifiers for script VM opcodes, not wire opcodes.
- No additional hashed chat paths found beyond the two `0x1109` entries; **`0x110A` / `0x110B` are not hashed**.
- `FUN_004B4010` (called from hash `0x7405AD04` and `Script_SpatialEntityPush`) is entity-effect plumbing — not classified as chat without a `0x11xx` send (confirmed absent).
- Dynamic validation: breakpoint on `SConnection_Send` @ `0x004ED0E0` with filter `*(u16*)buf == 0x1109` during NPC script ticks; backtrace should hit only `0x004C6A80` / `0x004C6F50` from `Script_OpcodeDispatch`.
