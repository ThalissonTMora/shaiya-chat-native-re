# Shaiya — Native Chat (RE)

Stock chat flow mapping **client ↔ world server ↔ login handshake**: Ghidra decompilations, manifests, and wire specs.

| Target | Folder | Role |
|--------|--------|------|
| `Game.exe` | [`game-chat-native/`](game-chat-native/) | Client chat + recv `0xA101` |
| `ps_game.exe` | [`psgame-chat-native/`](psgame-chat-native/) | World server chat `0x11xx` |
| `ps_login.exe` | [`pslogin-chat-native/`](pslogin-chat-native/) | Sends outbound `0xA101` key blob |

## Documentation

**All guides and specs:** [`docs/README.md`](docs/README.md)

| | |
|--|--|
| Opcodes & handlers | [`docs/CHAT_CHANNEL_MAP.md`](docs/CHAT_CHANNEL_MAP.md) |
| Wire layouts | [`docs/PACKET_SPEC.md`](docs/PACKET_SPEC.md) |
| Crypto / handshake | [`docs/WIRE_CRYPTO.md`](docs/WIRE_CRYPTO.md) |
| Counter derivation | [`docs/CRYPTO_COUNTER.md`](docs/CRYPTO_COUNTER.md) |
| Login key blob RE | [`docs/SERVER_KEY_BLOB_RE.md`](docs/SERVER_KEY_BLOB_RE.md) |
| Ghidra & `bin/` | [`docs/GHIDRA.md`](docs/GHIDRA.md) · [`docs/BINARIES.md`](docs/BINARIES.md) |

## Reimplementation confidence - AI Vision:

| Goal | Confidence |
|------|------------|
| Hook chat send/recv (plaintext) | **~95%** |
| Server emulator + stock client | **~85%** |
| Wire-compatible proxy | **~82%** |
| Standalone cipher clone | **~80%** (counter pre-`CounterLoad` may need capture) |

Regenerate `.c` files: see [`docs/GHIDRA.md`](docs/GHIDRA.md).

Contributions and validations are welcome.
