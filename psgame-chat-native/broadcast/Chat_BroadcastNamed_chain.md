# Chat_BroadcastNamed @ `0x004D55B0` — call chain (megaphone / `0x1108`)

Binary: `ps_game.exe` MD5 `91b212afbe6623382713772489dc82ce` · ImageBase `0x00400000`.

## Stub (CONFIRMED)

`Chat_BroadcastNamed_004d55b0.c` — only callee:

```c
FUN_00419240(*(undefined4 *)(in_EAX + 0xdc), 0, 7);
```

`in_EAX` = broadcast context object (same layout as `Chat_BroadcastShout` / `Chat_BroadcastNormal`): packet buffer @ `+0xD0`, zone @ `+0xE0`, country/group id @ `+0xDC`.

## Callee: `World_BroadcastTradeCore` @ `0x00419240` (CONFIRMED)

Iterates `DAT_00587960` world instance table (`stride 0x98` per slot):

| Step | VA | Action |
|------|-----|--------|
| 1 | `0x00419240` | `FUN_004f3dc0` — alloc/ref send buffer |
| 2 | per slot | `CUser_SendQueueEnqueue` @ `0x00426DD0` with **mode `3`**, `param_3=0`, `param_4=7` |
| 3 | overflow | `CWorld_InstanceSendEnqueue` @ `0x00413350` — same mode/args |

`param_4=7` is the **view/filter id** stored in queue slot `[7]` (not `Chat_BroadcastViewMode7` @ `0x004D56D0`, which uses spatial arg **`5`** in `Zone_PSendViewCells`).

## Flush: mode `3` → `SendQueue_Mode3_ZoneGroup` (CONFIRMED)

`CUser_SendQueueFlush` @ `0x00426EC0` case `3`:

```c
FUN_00427b20(param_1, piVar4[5], piVar4[6], piVar4[7]);
```

`SendQueue_Mode3_ZoneGroup` @ `0x00427B20` — zone-linked user list @ `CUser+0x184`, match `CUser+0xDC` against `param_2`/`param_3`, send via `SConnection_SendEx` @ `0x004ED0B0` or backpressure `CUser_SendBackpressure` @ `0x004F6F00`.

## Contrast: immediate spatial (normal / shout)

| Path | Entry | Spatial | View arg |
|------|--------|---------|----------|
| Normal `0x1101` | `Chat_BroadcastNormal` `0x004D5710` | `Zone_PSendViewCells` `0x00427CF0` | **7** (`_DAT_00574164`) |
| Shout `0x1107` | `Chat_BroadcastShout` `0x004D5600` | same | **5** (`param_3` / `_DAT_00574178`) |
| Megaphone `0x1108` | `Chat_BroadcastNamed` `0x004D55B0` | **queued** mode **3** | **7** (enqueue `param_4`) |
| Other | `Chat_BroadcastViewMode7` `0x004D56D0` | `Zone_PSendViewCells` | **5** (caller `Dispatch_Packet0200` @ `0x00476070`) |

## `Chat_ProcessIncoming` megaphone ingress (CONFIRMED)

| Trigger | VA | Out packet | Broadcast |
|---------|-----|------------|-----------|
| `0x1101` + `CUser+0x58DC != 0` | `0x0047F400` L80–96 | Repack **`0x1108`** Pattern B (`name[21]` from `CUser+0x184`, text from client) | `FUN_004d55b0(&local_14c, len+0x18)` |
| `0x1108` + megaphone cooldown | `0x0047F400` L241–264 | `0x1108` | same |

Reproduce: Ghidra xref to `0x004D55B0` from `FUN_0047f400`; decompile manifest `psgame-chat-functions.manifest`.
