# Shaiya — Native Chat (RE)

Stock chat flow mapping **client ↔ server**: Ghidra-decompiled code, address manifests, and opcode tables.

| Target | Folder | Exports |
|--------|--------|---------|
| `Game.exe` (client) | [`game-chat-native/`](game-chat-native/) | 144 manifest + crypto helpers |
| `ps_game.exe` (world) | [`psgame-chat-native/`](psgame-chat-native/) | 121 manifest (all `.c`) |
| `ps_login.exe` (handshake) | [`pslogin-chat-native/`](pslogin-chat-native/) | 15 key-path `.c` |

## Start here

**[`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)** — opcodes, handlers, vtables, VAs, and `.c` paths.

**[`PACKET_SPEC.md`](PACKET_SPEC.md)** — wire layouts (send/recv), server validation, TCP envelope.

**[`WIRE_CRYPTO.md`](WIRE_CRYPTO.md)** — AES-CTR, handshake, crypto context struct, encrypted send/recv pipeline.

**[`docs/CRYPTO_COUNTER.md`](docs/CRYPTO_COUNTER.md)** — `0xA101` body → HMAC → `ctx+0xF4` counter derivation.

**[`docs/SERVER_KEY_BLOB_RE.md`](docs/SERVER_KEY_BLOB_RE.md)** — outbound `0xA101` lives in `ps_login.exe`, not `ps_game.exe`.

## Current coverage

| Area | Status |
|------|--------|
| Chat opcodes + handlers (client + server) | Mapped with decompiled `.c` evidence |
| Wire layouts (`0x1101`–`0x110A`, send paths) | Documented in PACKET_SPEC |
| AES-128 stream cipher + TCP envelope | Documented in WIRE_CRYPTO |
| Handshake (key recv `0xA101`, ack `0xA102`) | Client mapped; server send @ `ps_login.exe` `SendKeyBlob_A101` `0x404DA0` |
| Vtable bases | Chat `0x747544`, connection state `0x747788` |

## Reimplementation confidence

| Goal | Confidence |
|------|------------|
| Hook chat send/recv (plaintext) | **~95%** |
| Server emulator + stock client | **~85%** |
| Wire-compatible proxy | **~82%** |
| Standalone cipher clone | **~80%** (counter pre-`CounterLoad` still needs capture) |

Details and known uncertainties: [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) · [`PACKET_SPEC.md`](PACKET_SPEC.md).

## Folders

| Folder | Contents |
|--------|----------|
| [`game-chat-native/`](game-chat-native/) | **Client** — `Game.exe` decomps + README |
| [`psgame-chat-native/`](psgame-chat-native/) | **World server** — `ps_game.exe` decomps |
| [`pslogin-chat-native/`](pslogin-chat-native/) | **Login server** — `ps_login.exe` (`0xA101` send path) |
| [`docs/`](docs/) | P0 RE reports (`CRYPTO_COUNTER`, `SERVER_KEY_BLOB_RE`) |
| `tools/ghidra/` | Manifests + `decompile-*` scripts |

**Why some `.md` stay at repo root:** `CHAT_CHANNEL_MAP`, `PACKET_SPEC`, and `WIRE_CRYPTO` are the canonical index (linked from Paradise tooling). Supplementary reports live under [`docs/`](docs/README.md).

Contributions and validations are welcome.
