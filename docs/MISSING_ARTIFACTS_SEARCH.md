# Missing artifacts search — May 2026

Automated search for runtime validation items **D1–D5** ([`CHAT_RE_STATUS.md`](CHAT_RE_STATUS.md)).  
Scope: `/home/Thalisson/shaiya-paradise`, `/home/Thalisson` (depth 6), `/mnt/c/Users` (depth 5), `.features/Shaiya-Core-V7` RAR byte scan.

---

## Summary

| ID | Item | Found in repo / WSL? | Notes |
|----|------|----------------------|-------|
| **D1** | Guild `0x1104` wire capture (padding) | **No** | No `.pcap` / hex dumps. Static + [`PADDING_SIMULATION.md`](PADDING_SIMULATION.md) only. |
| **D2** | `data/cn_string.DB` (zone script text) | **Yes** (Windows mount) | `/mnt/c/ShaiyaServer/PSM_Client/Bin/Data/cn_string.DB` (31 entries); vendored [`test/fixtures/cn_string_stock.db`](../test/fixtures/cn_string_stock.db) |
| **D2′** | Related: `sysmsg-uni.txt` (client sys messages) | **Yes** (outside RE repo) | [`.features/Shaiya-Core-V7/sysmsg-uni.txt`](../../.features/Shaiya-Core-V7/sysmsg-uni.txt) — **UTF-16**, tab format; **not** `cn_string.DB`. |
| **D3** | Login `0xA101` pcap + PRNG capture | **No** | No tcpdump/pcap in tree. |
| **D4** | NPC script `0x1109` wire capture | **No** | |
| **D5** | Binary that sends C→S `0xF108` | **No** in scanned PEs | `Game.exe` / `ps_game.exe` / `ps_login.exe`: **0** `mov $0xF108` send sites. Handler only on server. |

**Update:** Background scan of `/mnt/c` + `/mnt/d` found **`cn_string.DB`** (D2 closed for this machine). D1/D3/D4/D5 still missing.

**Conclusion:** D2 available from ShaiyaServer install paths; remaining items need in-game capture or GM tooling. D2′ is a **partial** client string table, different file/format.

---

## D2 — `cn_string.DB`

**Expected path (CONFIRMED in PE):**

- Server: `data/cn_string.DB` — `ps_game.exe` @ `ZoneChat_TableLoader` `0x00408C70`
- Client: same path string exists in `Game.exe` (zone lookup via `GetMsg` → `FUN_004163c0`)

**Searched:**

```text
/home/Thalisson/shaiya-paradise/**/cn_string.DB     → 0 (except test/fixtures/cn_string_sample.db)
/home/Thalisson/**/cn_string.DB (depth 6)          → 0
/mnt/c/Users/**/cn_string.DB (depth 5)             → 0
Shaiya-Core.rar / Shaiya-Core-v1.rar byte search   → string "cn_string.DB" NOT embedded in archive
```

**Parser ready when you have the file:**

```bash
python3 tools/zonechat/parse_cn_string_db.py /path/to/server/data/cn_string.DB --limit 50
```

---

## D2′ — `sysmsg-uni.txt` (related, not a substitute)

**Found:** `/home/Thalisson/shaiya-paradise/.features/Shaiya-Core-V7/sysmsg-uni.txt` (~1618 lines).

| Property | `sysmsg-uni.txt` | `cn_string.DB` |
|----------|------------------|----------------|
| Format | UTF-16 LE, `id TAB "text"` | ASCII/ANSI, `fscanf("%d\n")` + `fgets` line |
| Client path | `data/sysmsg-uni.txt` | `data/cn_string.DB` |
| Use | System/UI messages (`GetMsg` tags `<p>`, `<t>`, …) | Zone script / `0x1109` resolver |

Copy into server/client `data/` for runtime, but it **does not** replace `cn_string.DB` for NPC zone chat.

---

## D1 — padding capture

**Searched:** `*.pcap`, `*.pcapng`, `*capture*`, `*handshake*`, docs with guild hex dumps — **none** in `shaiya-paradise`.

**Best static proxy:** MSVC debug fill `0xCC` on simulated Pattern B — see `tools/padding/build_pattern_b_packet.py --tail stock`.

**To obtain (5 min in-game):** [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) §3 — `bp 004ED0E0` on `ps_game.exe`, guild chat, hexdump 21 B @ `payload+2`.

---

## D3 — login crypto capture

**Searched:** pcap, `*a101*`, handshake logs — **none**.

**To obtain:**

1. tcpdump login port during client connect.
2. x64dbg `Game.exe`: break @ `0x00404610` (`Crypto_PRNGFill`) → dump 128 B seed; break @ `0x005E3D60` → dump 197 B plaintext `0xA101`.
3. `python3 tools/crypto/validate_a101_counter.py --file dump.bin --offset N --prng-hex <256 hex chars>`

---

## D4 — script push capture

**Searched:** no script/NPC wire logs in repo.

**To obtain:** [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) §4 — `SConnection_Send` @ `0x004ED0E0`, filter `*(u16*)buf == 0x1109`.

---

## D5 — F108 sender

**Scanned PEs (disassembly grep `f108`):**

| Binary | C→S `mov $0xF108` | Role |
|--------|-------------------|------|
| `bin/Game.exe` | No | No dispatcher case |
| `bin/ps_game.exe` | No (recv handler only) | Relays to `0xF102` |
| `bin/ps_login.exe` | No | |
| `.features/Shaiya-Core-V7/server/*.exe` | No send | |

**INFERRED:** GM panel / admin tool not vendored in this monorepo. Server path documented in [`ADMIN_F108_WHISPER_RELAY.md`](ADMIN_F108_WHISPER_RELAY.md).

---

## Where to look next (manual)

Typical stock server layout on Windows:

```text
C:\Server\data\cn_string.DB
C:\Server\data\sysmsg-uni.txt
```

FTP staging in this monorepo: `infra/ftp/shaiya/` — **no `data/` subtree checked in** (empty of game DBs at search time).

If you have `Shaiya-Core.rar` extracted elsewhere, only **install/runtime `data/`** after first server start is likely to contain `cn_string.DB` (not inside the RAR string scan).

---

## Helper script

Run locally with extra paths:

```bash
./tools/artifacts/find_missing.sh /path/to/server/data /mnt/c/Server/data
```

---

## Cross-reference

- Milestone: [`CHAT_RE_STATUS.md`](CHAT_RE_STATUS.md)
- Gaps: [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md)
