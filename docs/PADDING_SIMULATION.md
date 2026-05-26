# Pattern B padding simulation — `char[21]` name tail

Static RE (May 2026) shows stock **server** builders copy name until `'\0'` only; send size is always `len + 0x18` (full 21 name bytes on wire). No `memset(21)` on any chat Pattern B path before `SConnection_Send` @ `0x004ED0E0`.

This doc + script help **validate wire tail bytes** before/after capture and compare emulator behavior vs stock client.

## Stock behavior (static)

| Path | Builder VA | Tail zeroed? |
|------|------------|--------------|
| Guild `0x1104` | `Chat_BroadcastGuild` @ `0x00432530` | **No** — copy @ `0x004325B0`, send @ `0x00432615` |
| Admin guild `0xF104` | `AdminChat_BuildGuildPacket` @ `0x00432770` | **No** — send @ `0x00432818` |
| GM guild relay | @ `0x004070BC` / `0x0040714E` | **No** |
| Megaphone `0x1108` | `Chat_ProcessIncoming` → `Chat_BroadcastNamed` | **No** — copy @ `0x0047F580`, `add edi,0x18` @ `0x0047F5A3` |
| Trade `0x1103` | `Chat_ProcessIncoming` case `0x1103` | **No** — copy @ `0x0047F760`, queue flush |
| Area `0x1111` | `Chat_ProcessIncoming` case `0x1111` | **No** — copy @ `0x0047FBD0` |
| Monitor `0xF502` | `Chat_BuildOutgoing_F502` @ `0x0047F260` | **No** — copy @ `0x0047F2B0`, send @ `0x0047F32C` |

**Client recv (`Handler_ChatGuild` @ `0x005E5310`):** pre-zeros 21 B local buffer (`xor eax` + 5×`mov [esp+…]` @ `0x005E5324`–`0x005E5342`) **before** `PacketRead_String(..., 0x15)`. No post-read tail normalization. UI vfn @ `0x0059BDB0` compares name as C-string (stops at first `NUL`).

## Script

```bash
python3 tools/padding/build_pattern_b_packet.py \
  --name "TestUser" \
  --text "hello" \
  --tail zero          # emulator: intentional zero pad
python3 tools/padding/build_pattern_b_packet.py \
  --name "TestUser" \
  --text "hello" \
  --tail garbage --seed 0xDEADBEEF
python3 tools/padding/build_pattern_b_packet.py \
  --name "TestUser" \
  --text "hello" \
  --tail stock         # simulate static stock (uninit tail pattern)
```

## Expected outcomes

| Tail mode | Bytes `[strlen..20]` | Stock server match? | Stock client UI |
|-----------|----------------------|---------------------|-----------------|
| `zero` | `0x00…` | **No** (stock does not memset) | OK (C-string) |
| `garbage` | non-zero random | **Yes** (static inference) | OK if `name[strlen]=='\\0'` |
| `stock` | repeating `0xCC`-like stack fill | Approximation | OK if early `NUL` |

**Capture validation:** hook `SConnection_Send` @ `0x004ED0E0`, filter `*(u16*)buf == 0x1104`, hexdump `buf+2` length 21. Compare with script output. See [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) §3.

## Reproduce static scan

```bash
# All direct Pattern B chat sends (add +0x18 within 80 insns before call)
python3 tools/padding/scan_pattern_b_sends.py bin/ps_game.exe

# Guild builder (no rep stos between copy and send)
objdump -d --start-address=0x432530 --stop-address=0x432620 bin/ps_game.exe

# Client recv pre-zero
objdump -d --start-address=0x5e5310 --stop-address=0x5e53a0 bin/Game.exe
```
