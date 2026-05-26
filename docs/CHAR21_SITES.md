# `char[21]` name field — site inventory (static RE)

Binaries: `Game.exe` MD5 `c1edd96639ad81835624b9c4516ac781`, `ps_game.exe` MD5 `91b212afbe6623382713772489dc82ce`, ImageBase `0x00400000`.

Offsets below are **plaintext payload bytes after `u16` LE opcode** (tap at `SConnection_Send` / post-decrypt recv). See [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) for breakpoints.

---

## Client recv — `PacketRead_String` @ `0x005F4780` (`count = 0x15`)

| Opcode | Handler VA | File | Read target | Pattern |
|--------|------------|------|-------------|---------|
| `0x1102` | `0x005E5180` | `game-chat-native/handlers/Handler_ChatWhisper_005e5180.c` | `&local_9c` after 1 B `dir` | **C** |
| `0x1103` | `0x005E5250` | `Handler_ChatTrade_005e5250.c` | `local_a0+1` | **B** |
| `0x1104` | `0x005E5310` | `Handler_ChatGuild_005e5310.c` | `local_a0+1` | **B** |
| `0x1108` | `0x005E5540` | `Handler_ChatMegaphone_005e5540.c` | `local_a0+1` | **B** |
| `0x1111` | `0x005E57D0` | `Handler_Chat_Area_1111_005e57d0.c` | `local_a0+1` | **B** |
| `0xF102` | `0x005E5920` | `Handler_Chat_Admin_F102_005e5920.c` | `&local_9c` after `dir` | **C** |
| `0xF103` | `0x005E59F0` | `Handler_Chat_Admin_F103_005e59f0.c` | `local_a0+1` | **B** |
| `0xF104` | `0x005E5AB0` | `Handler_Chat_Admin_F104_005e5ab0.c` | `local_a0+1` | **B** |
| `0xF107` | `0x005DE950` | `Handler_Chat_Admin_F107_005de950.c` | `&local_1c` only | bind (S→C notify) |
| `0xF109` | `0x005DE9B0` | `Handler_Chat_Admin_F109_005de9b0.c` | `&local_1c` only | clear (S→C notify) |

Server S→C send (pattern **H**, size `0x17`): `AdminChat_ProcessIncoming` @ `0x004803C7` (F107) · `Chat_AdminWhisperHelper` @ `0x0047F390` (F109) — see [`psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md`](../psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md).

**Not `0x15`:** `0x1101`, `0x1105`, `0x1107` (u32 id); `0x1109` (pattern D); `0x110A` (u32+u16); `0x110B` (`0x20` label); `0xF105`/`0xF106`/`0x1112` (other layouts).

**Handler pre-init (pattern B recv):** `Handler_ChatGuild` zeroes `local_a0[1..5]` and `local_88` before read — trailing **local** bytes after a short on-wire name may still be zero until overwritten by wire garbage (`Handler_ChatGuild_005e5310.c` L24–29).

**UI:** `ChatWhisperTradeGuildZoneMega_vfn` @ `0x0059BDB0` compares `param_4` with byte loop until `'\0'` (`ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` L58–72). No explicit strip of wire tail.

---

## Client send

| Path | VA | File | Name on wire? |
|------|-----|------|----------------|
| Whisper only | `0x005ED160` | `PacketSend_Whisper_005ed160.c` | **Yes** — `param_2[0..4]` + `*(param_2+5)` → 21 B @ `+0x02`; size `msg_len+0x18` |
| `PacketSend_Chat` | `0x005ED060` | `PacketSend_Chat_005ed060.c` | **No** — `opcode + u8 len + text` (`msg_len+3`) |
| `PacketSend_Guild` | `0x005ED220` | `PacketSend_Guild_005ed220.c` | **No** |
| `PacketSend_Party` | `0x005ED2B0` | `PacketSend_Party_005ed2b0.c` | **No** |
| `PacketSend_Zone` | `0x005ED340` | `PacketSend_Zone_005ed340.c` | **No** |

Whisper UI source: `ChatWindow_SendMessage` @ `0x0047A5F0` passes `param_1_00+0x198` to `PacketSend_Whisper` (channel case 1). Target set: `ChatWindow_SetWhisperTarget` @ `0x0047C690` null-terminated copy into `+0x198`.

---

## Server outbound — null-terminated copy into stack `char[21]`, fixed send size

| Opcode / pattern | Function VA | File | Name source | `SConnection_Send` size |
|------------------|-------------|------|-------------|-------------------------|
| `0x1103` trade | `0x004192F0` → queue | `Chat_BroadcastTrade_004192f0.c` | via `Chat_ProcessIncoming` @ `0x0047F400` | `len+0x18` |
| `0x1104` guild | `0x00432530` | `Chat_BroadcastGuild_00432530.c` | `param_2` (`CUser+0x184`) → `local_a2[21]` | `len+0x18` @ `0x004ED0E0` |
| `0x0812` alliance | same | same | → `acStack_13e[21]` | `len+0x1C` @ `0x004ED2D0` |
| `0x1108` megaphone | `0x004D55B0` | `Chat_BroadcastNamed_004d55b0.c` | `Chat_ProcessIncoming` repack | `len+0x18` |
| `0x1111` area | `0x00427090` | `Chat_BroadcastZone_00427090.c` | `Chat_ProcessIncoming` → `local_aa[21]` | (zone fanout) |
| `0x1102` whisper S→C | `0x0047F400` | `Chat_ProcessIncoming_0047f400.c` | sender `CUser+0x184` / target `+0x184` | `len+0x19` (×2) |
| `0xF104` admin guild | `0x00432770` | `AdminChat_BuildGuildPacket_00432770.c` | same as guild | `len+0x18` |
| Admin mirror | `0x0047FD10` | `AdminChat_ProcessIncoming_0047fd10.c` | same patterns | same |

**Copy idiom (CONFIRMED):** `do { *dst++ = *src++; } while (*src != '\0');` — no `memset` of tail before send (`Chat_BroadcastGuild` asm `0x004325B0`–`0x00432615`: no `rep stos` between copy and `call 0x004ED0E0`).

---

## Server inbound (C→S) — whisper `target[21]`

| Step | VA | Evidence |
|------|-----|----------|
| Clear wire byte `+0x16` | `0x0047F608` | `movb $0x0, 0x16(%ebx)` (`Chat_ProcessIncoming` case `0x1102`) |
| Text slice | `0x0047F661` | `lea 0x18(%ebx),%esi` → `memcpy` (Ghidra `+0xc` is wrong for this build) |
| Lookup | `0x0047F60C` | `World_FindUserByName` after `lea 0x2(%ebx)` |

---

## Padding verdict (static — P0 May 2026)

Scan: `python3 tools/padding/scan_pattern_b_sends.py bin/ps_game.exe` · sim: [`PADDING_SIMULATION.md`](PADDING_SIMULATION.md).

| Claim | Tag |
|-------|-----|
| Send includes full 21 name bytes (not strlen) | **CONFIRMED** (`len+0x18` / `len+0x19` sizes) |
| Server does not zero-fill after `'\0'` before send | **CONFIRMED** — **5/5** chat Pattern B `SConnection_Send` sites: no `memset(21)`/`rep stos` in 80-insn window |
| MSVC stack frame not zeroed before copy | **CONFIRMED absent** — `sub esp` + cookie only in all builders |
| Client recv pre-zeros local 21 B | **CONFIRMED** — `Handler_ChatGuild` @ `0x005E5324`–`0x005E5342` before read |
| Client recv post-read tail strip | **CONFIRMED absent** |
| Tail bytes on wire are stack residue (not zeros) | **INFERRED (~99% static)** — capture still pins exact bytes |
| Emulator should `memset(name,0,21)` then strcpy | **INFERRED** (safe interop; **not** stock-identical) |

Reproduce guild send: `objdump -d --start-address=0x432530 --stop-address=0x432620 bin/ps_game.exe`
