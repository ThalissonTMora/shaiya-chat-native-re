# Native chat RE — status (Shaiya Core V9)

**Last updated:** May 2026 · binaries in [`bin/`](../bin/) · repo [`shaiya-chat-native-re`](../README.md).

This is the **milestone snapshot** for static RE. Dynamic validation items are listed at the end.

---

## Static coverage (closed)

| Area | Status | Primary docs |
|------|--------|----------------|
| Client recv/send `0x11xx` + admin `0xF102`–`0xF109` | **Closed** | [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md), [`PACKET_SPEC.md`](PACKET_SPEC.md) |
| Server `Chat_ProcessIncoming` + broadcast queue | **Closed** | `psgame-chat-native/handlers/`, `broadcast/` |
| Script push `0x1109`–`0x110B` + opcode hashes | **Closed** | [`SCRIPT_OPCODE_HASHES.md`](SCRIPT_OPCODE_HASHES.md) |
| Zone message table (`cn_string.DB` format) | **Closed** (format only) | [`ZONECHAT_MESSAGE_TABLE.md`](ZONECHAT_MESSAGE_TABLE.md) |
| `char[21]` sites + padding (static) | **~99% INFERRED** stack tail | [`CHAR21_SITES.md`](CHAR21_SITES.md), [`PADDING_SIMULATION.md`](PADDING_SIMULATION.md) |
| Balloon / cinematic gates | **Closed** | `CHAT_CHANNEL_MAP` §8, `UIShell_*` decomps |
| Admin F107/F109 bind | **Closed** | [`Chat_AdminWhisper_F107_F109_chain.md`](../psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md) |
| Admin F108 bound whisper relay | **Closed** | [`ADMIN_F108_WHISPER_RELAY.md`](ADMIN_F108_WHISPER_RELAY.md) |
| Client `0xA101` recv + counter derivation | **Closed** (static) | [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) |
| Server `0xA101` send (`ps_login`) | **Closed** (layout + key table) | [`LOGIN_A101_BODY_MAP.md`](LOGIN_A101_BODY_MAP.md), [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md) |
| `KeyTable_SlotInit` bignum pipeline | **Closed** (INFERRED RSA-like) | `pslogin-chat-native/crypto/BigInt_*`, `KeyTable_*` |

### Corpus size

| Binary | Manifest entries | `.c` files |
|--------|------------------|------------|
| `Game.exe` | 160 | 169 |
| `ps_game.exe` | 136 | 143 |
| `ps_login.exe` | 17 (+ extended BigInt decomps) | 47+ |
| **Total (chat manifests)** | **313** | **329+** |

Regenerate: [`GHIDRA.md`](GHIDRA.md).

---

## Tools (offline)

| Tool | Purpose |
|------|---------|
| [`tools/padding/build_pattern_b_packet.py`](../tools/padding/build_pattern_b_packet.py) | Build guild Pattern B packets |
| [`tools/padding/scan_pattern_b_sends.py`](../tools/padding/scan_pattern_b_sends.py) | Scan PE for memset before send |
| [`tools/zonechat/parse_cn_string_db.py`](../tools/zonechat/parse_cn_string_db.py) | Parse `data/cn_string.DB` |
| [`tools/crypto/validate_a101_counter.py`](../tools/crypto/validate_a101_counter.py) | Verify `0xA101` HMAC/counter |
| [`tools/wire/extract_plaintext_opcodes.py`](../tools/wire/extract_plaintext_opcodes.py) | Find opcodes in plaintext dumps |

Synthetic fixture (parser test only): [`test/fixtures/cn_string_sample.db`](../test/fixtures/cn_string_sample.db).

---

## Still requires runtime / external files

| ID | Item | How to close |
|----|------|----------------|
| **D1** | `char[21]` wire tail CONFIRMED | 1× guild `0x1104` capture — [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) §3 |
| **D2** | `cn_string.DB` content | Copy from stock server → `parse_cn_string_db.py` |
| **D3** | `0xA101` counter end-to-end | tcpdump login + `--prng-hex` in `validate_a101_counter.py` |
| **D4** | NPC script push wire | `SConnection_Send` @ `0x004ED0E0` during script |
| **D5** | F108 C→S sender binary | GM tool outside `Game.exe` |

---

## Confidence (reimplementation)

| Goal | Static confidence |
|------|-------------------|
| Hook chat send/recv (plaintext) | **~95%** |
| Server emulator + stock client | **~88%** (D2 zone strings optional for scripts) |
| Wire-compatible proxy | **~85%** |
| Standalone cipher clone | **~82%** (D3 PRNG seed at handshake) |
| Login key blob replay | **~90%** with 16 captured KeyTable slots |

See root [`README.md`](../README.md) for the short table.

---

## Roadmap doc

Detailed gaps P0/P1/P2: [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md).
