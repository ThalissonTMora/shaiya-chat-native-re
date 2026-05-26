# Missing content inventory — May 2026

Consolidated scan: manifests, PE grep, docs, runtime session (UI + GM notices), cross-ref `feat server/analise_wnotice_ntplayer/`.

**Chat stock `0x11xx`:** milestone **closed** ([`CHAT_RE_STATUS.md`](CHAT_RE_STATUS.md)). This list is what remains **important** for emulator, GM tooling, or 100% wire fidelity.

---

## Summary

| Tier | Count | Blocks |
|------|-------|--------|
| **A — Closed** | ~15 areas | Stock chat send/recv, admin F102–F109, script push builders, padding D1 static, cn_string D2 |
| **B — Important gap** | **6** | GM notice `0xF901`–`0xF90C` server decomp + spec doc; client recv; F901–F905 semantics |
| **C — Runtime only** | **3** | D3 A101+PRNG, D4 script wire, D5 F108 sender binary |
| **D — Assets** | **1** | `sysmsg-uni.txt` not vendored (related, not `cn_string.DB`) |
| **E — Optional** | **4** | Live padding hex, quest→opcode map, UI pixel-perfect, `0x812` live sample |

---

## A — Closed (no further RE required for stock chat)

| Item | Evidence |
|------|----------|
| Manifest ↔ `.c` (game / psgame / pslogin) | **0 missing** (160 / 136 / 17 entries) |
| `0x1101`–`0x1111`, `0xF102`–`0xF109` client handlers | `game-chat-native/handlers/` |
| Server `Chat_ProcessIncoming` + broadcasts | `psgame-chat-native/` |
| `char[21]` padding D1 | Static CONFIRMED + [`test/captures/ui_session_20260526_static.log`](../test/captures/ui_session_20260526_static.log) |
| `cn_string.DB` D2 | [`test/fixtures/cn_string_stock.db`](../test/fixtures/cn_string_stock.db) |
| Script `0x1109`–`0x110B` builders | `psgame-chat-native/send/` |
| Crypto `0xA101` client + `ps_login` layout | [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md), [`LOGIN_A101_BODY_MAP.md`](LOGIN_A101_BODY_MAP.md) |

---

## B — Important gaps (documented poorly or absent in repo)

### B1 — GM notice family `0xF901`–`0xF90C` (your in-game tests)

**Runtime:** you ran `/gmnotice`, `/cnotice`, `/wnotice`, `/notice`, `/znotice`; `/bnotice` needs Korean faction token (`빛` / `어둠`).

**Client (CONFIRMED in `GmCommand_Dispatch` @ `0x0047FFD0`):**

| Command | C→S opcode | Send VA | Args (stock) |
|---------|------------|---------|----------------|
| `/gmnotice` | `0xF906` | `0x005EE240` | `<message>` |
| `/cnotice` | `0xF907` | `0x005EDF70` | `<mapId> <message>` |
| `/wnotice` | `0xF908` | `0x005EDE90` | `<playerName> <message>` |
| `/notice` | `0xF90B` | `0x005EE190` | `<mapId> <message>` |
| `/znotice` | `0xF909` | `0x005EE020` | `<mapId> <message>` |
| `/bnotice` | `0xF90A` | `0x005EE0D0` | `<빛\|어둠> <mapId> <message>` |

**`0xF908` wire (CONFIRMED asm @ `0x005EDE90`):**

```text
+0x00  u16   opcode = 0xF908
+0x02  u8[21] player field (5×u32 + u8 from target struct)
+0x17  u16   unknown (often 0)
+0x19  u8    msg_len
+0x1A  char[] message
size = 0x1A + msg_len (+1)
```

**Server (CONFIRMED dispatch, NOT decompiled in repo):**

- Main dispatcher: `CUser` packet path @ **`0x0047509F`** — `cmp eax, 0xF900` → handler **`0x00482630`**
- Jump table @ **`0x004833F4`**: opcodes **`0xF901`–`0xF90C`** → handlers `0x004826C1` … `0x004832C2`
- Example: **`0xF908`** @ `0x00482FB1` — `World_FindUserByName` @ `0x00414D40`, relay to target user

**Missing deliverables:**

- [ ] `docs/GM_NOTICE_COMMANDS.md` (command table + layouts + bnotice Korean tokens)
- [ ] Ghidra decomp: `psgame-chat-native/notice/CUser_NoticeDispatch_00482630.c` + per-opcode handlers
- [ ] Client **recv** handlers for `0xF901`–`0xF90C` (display path — separate from `0x11xx`)
- [ ] Opcodes **`0xF901`–`0xF905`**, **`0xF90C`**: purpose (jump table has stubs @ `0x004833BE` for F902/F903)

**Cross-ref:** [`feat server/analise_wnotice_ntplayer/`](../../feat%20server/analise_wnotice_ntplayer/) (older analysis; not merged into this repo).

---

### B2 — Server global notice `/nt` → `0xF106`

- **Found:** `mov $0xF106` @ `0x00414E34` in `ps_game.exe` (not in chat manifest).
- **Missing:** handler decomp, S→C layout, relation to GM notices.

---

### B3 — Client admin send variants `0xF904` / `0xF905`

- **Found:** `mov $0xF904` / `$0xF905` in `Game.exe` @ `0x005EE678`, `0x005EE5D8` (admin chat send family).
- **Partial:** `PACKET_SPEC` lists `0xF101`–`0xF105`; **F904/F905** not fully laid out in spec.

---

### B4 — Alliance chat `0x812`

- **Static:** pattern B + `u32 guildId` in [`PACKET_SPEC.md`](PACKET_SPEC.md) § Alliance.
- **Missing:** live capture sample; handler `.c` naming in client recv table.

---

### B5 — Whisper C→S `0x1102` target field

- **INFERRED:** 21 B = 5×`u32` + `u8` @ `PacketSend_Whisper` — no live hex in repo.
- **Impact:** low if emulator copies stock send function.

---

### B6 — Genesis / Paradise `0x13xx` chat

- **Out of stock RE scope** but injected in production (`sdev.dll` → `0x00474AFC`).
- **Missing:** bridge doc in this repo (only in Shaiya-Core-V7 sources).

---

## C — Runtime validation (optional for stock chat milestone)

| ID | Item | Status | Close with |
|----|------|--------|------------|
| **D1** | Pattern B padding live bytes | Static **done** | Optional: `bp 004ED0E0` guild echo |
| **D3** | `0xA101` + PRNG end-to-end | Open | tcpdump login + `validate_a101_counter.py --prng-hex` |
| **D4** | `0x1109`–`0x110B` on wire | Open | NPC script + `SConnection_Send` filter |
| **D5** | C→S `0xF108` sender | Open | GM tool binary (not in `Game.exe`) |

---

## D — Related assets

| File | Status | Notes |
|------|--------|-------|
| `cn_string.DB` | **Vendored** | 31 entries |
| `sysmsg-uni.txt` | **Not in repo** | UTF-16 client sys strings; [`.features/Shaiya-Core-V7/sysmsg-uni.txt`](../../.features/Shaiya-Core-V7/sysmsg-uni.txt) |
| `chat_capture_live.log` | Generated (static) | [`emit_session_capture.py`](../tools/wire/emit_session_capture.py) |
| `.pcap` / login dumps | **None** | |

---

## E — Low priority (P2)

| Item | Notes |
|------|-------|
| UI pixel-perfect / `ChatWindow_Render` hooks | [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) P2 |
| Script VM quest → `0x1109` caller map | xref `Script_OpcodeDispatch` @ `0x004A2210` |
| `GmCommand_Dispatch` full command list | 3139-line decomp exists; only notice subset tested |
| `StaffCommand_Dispatch` @ `0x004867A1` | Separate staff UI path |

---

## Recommended next actions (ordered)

1. **B1** — Add `docs/GM_NOTICE_COMMANDS.md` + decompile server `0x00482630` cluster (highest value after your GM session).
2. **D3** — Only if building standalone cipher clone.
3. **D4 / D5** — Only if emulating script NPC chat or GM F108 panel.
4. **B2** — If server `/nt` global notice matters for ops.

---

## Helpers

```bash
# Manifest audit
python3 -c "..."  # see CHAT_RE_STATUS corpus table

# PE scan F90x on server
objdump -d bin/ps_game.exe | grep -E 'f90[0-9a-f]{2}'

# Static capture
python3 tools/wire/emit_session_capture.py --deploy /mnt/c/ShaiyaServer/PSM_Client/Bin/chat_capture_live.log

./tools/artifacts/find_missing.sh /mnt/c/ShaiyaServer/PSM_Client/Bin
```

---

## Cross-reference

- Milestone: [`CHAT_RE_STATUS.md`](CHAT_RE_STATUS.md)
- Artifacts search: [`MISSING_ARTIFACTS_SEARCH.md`](MISSING_ARTIFACTS_SEARCH.md) *(update D1 → static closed)*
- Live capture: [`LIVE_CAPTURE_WINDOWS.md`](LIVE_CAPTURE_WINDOWS.md)
