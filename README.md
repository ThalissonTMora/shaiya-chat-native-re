# Shaiya — Native Chat (RE)

Stock chat flow mapping **client ↔ server**: Ghidra-decompiled code, address manifests, and opcode tables.

| Target | Functions |
|--------|-----------|
| `Game.exe` | 132 + 11 crypto |
| `ps_game.exe` | 114 + 7 crypto |

## Start here

**[`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)** — opcodes, handlers, vtables, VAs, and `.c` paths.

**[`PACKET_SPEC.md`](PACKET_SPEC.md)** — wire layouts (send/recv), server validation, TCP envelope.

**[`WIRE_CRYPTO.md`](WIRE_CRYPTO.md)** — AES-CTR, handshake, crypto context struct, encrypted send/recv pipeline.

## Current coverage

| Area | Status |
|------|--------|
| Chat opcodes + handlers (client + server) | Mapped with decompiled `.c` evidence |
| Wire layouts (`0x1101`–`0x110A`, send paths) | Documented in PACKET_SPEC |
| AES-128 stream cipher + TCP envelope | Documented in WIRE_CRYPTO |
| Handshake (key recv `0xA101`, ack `0xA102`) | Mapped via `PacketDispatcher`; server outbound opcode not mapped |
| Vtable bases | Chat `0x747544`, connection state `0x747788` |

## Reimplementation confidence

| Goal | Confidence |
|------|------------|
| Hook chat send/recv (plaintext) | **~95%** |
| Server emulator + stock client | **~85%** |
| Wire-compatible proxy | **~75%** |
| Standalone cipher clone | **~75%** |

Details and known uncertainties: [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) · [`PACKET_SPEC.md`](PACKET_SPEC.md).

## Folders

| Folder | Contents |
|--------|----------|
| [`game-chat-native/`](game-chat-native/) | Client — decompiled `.c` files + README |
| `psgame-chat-native/` | Server — decompiled `.c` files |
| `tools/ghidra/` | Manifests + scripts (`decompile-*-chat.sh`, `decompile-crypto.sh`) |

Contributions and validations are welcome.
