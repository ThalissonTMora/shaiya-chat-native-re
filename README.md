# Shaiya — Native Chat (RE)

Stock chat flow mapping **client ↔ world server ↔ login handshake**: Ghidra decompilations, manifests, and wire specs.

Binaries under [`bin/`](bin/) come from [Shaiya-Core](https://github.com/Spelunkern/Shaiya-Core/) (V9).

| Target | Folder | Role | Functions (manifest) | `.c` in repo |
|--------|--------|------|----------------------|--------------|
| `Game.exe` | [`game-chat-native/`](game-chat-native/) | Client chat + recv `0xA101` | **160** | **167** |
| `ps_game.exe` | [`psgame-chat-native/`](psgame-chat-native/) | World server chat `0x11xx` | **136** | **143** |
| `ps_login.exe` | [`pslogin-chat-native/`](pslogin-chat-native/) | Sends outbound `0xA101` key blob | **17** | **17** |
| **Total** | — | Chat-related RE corpus | **313** | **329** |

Counts come from [`tools/ghidra/*-functions.manifest`](tools/ghidra/) (Ghidra decompile targets) and matching `.c` files under each folder. Extra `.c` files (e.g. client crypto helpers, `psgame-chat-native/script/` cluster) are decompiled beyond a single manifest line but still chat-related.

| Target | Top manifest categories |
|--------|---------------------------|
| `Game.exe` | `ui` 32 · `handlers` 27 · `vtable` 16 · `buffer` 14 · `recv` 11 |
| `ps_game.exe` | `queue` 26 · `broadcast` 17 · `network` 14 · `pipeline` 12 · `handlers` 12 |
| `ps_login.exe` | `keypath` 6 · `pipeline` 4 · `crypto` 2 · `network` 2 |

## Documentation

**All guides and specs:** [`docs/README.md`](docs/README.md)

| | |
|--|--|
| Opcodes & handlers | [`docs/CHAT_CHANNEL_MAP.md`](docs/CHAT_CHANNEL_MAP.md) |
| Wire layouts | [`docs/PACKET_SPEC.md`](docs/PACKET_SPEC.md) · [`docs/CHAR21_SITES.md`](docs/CHAR21_SITES.md) |
| Script VM hashes | [`docs/SCRIPT_OPCODE_HASHES.md`](docs/SCRIPT_OPCODE_HASHES.md) |
| Zone messages (`cn_string.DB`) | [`docs/ZONECHAT_MESSAGE_TABLE.md`](docs/ZONECHAT_MESSAGE_TABLE.md) |
| Pattern B padding | [`docs/PADDING_SIMULATION.md`](docs/PADDING_SIMULATION.md) |
| Crypto / handshake | [`docs/WIRE_CRYPTO.md`](docs/WIRE_CRYPTO.md) · [`docs/CRYPTO_COUNTER.md`](docs/CRYPTO_COUNTER.md) · [`docs/LOGIN_A101_BODY_MAP.md`](docs/LOGIN_A101_BODY_MAP.md) |
| Counter derivation | [`docs/CRYPTO_COUNTER.md`](docs/CRYPTO_COUNTER.md) |
| Login key blob RE | [`docs/SERVER_KEY_BLOB_RE.md`](docs/SERVER_KEY_BLOB_RE.md) |
| Ghidra & `bin/` | [`docs/GHIDRA.md`](docs/GHIDRA.md) · [`docs/BINARIES.md`](docs/BINARIES.md) · [`bin/README.md`](bin/README.md) (Shaiya Core V9) |

## Reimplementation confidence - AI Vision:

| Goal | Confidence |
|------|------------|
| Hook chat send/recv (plaintext) | **~95%** |
| Server emulator + stock client | **~85%** |
| Wire-compatible proxy | **~82%** |
| Standalone cipher clone | **~80%** (counter pre-`CounterLoad` may need capture) |

Regenerate `.c` files: see [`docs/GHIDRA.md`](docs/GHIDRA.md).

Contributions and validations are welcome.
