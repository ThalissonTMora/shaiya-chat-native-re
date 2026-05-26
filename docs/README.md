# Documentation index

All project markdown lives in **`docs/`**. The repo root [`README.md`](../README.md) is a short entry point.

## Specs (start here)

| Doc | Contents |
|-----|----------|
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Opcodes, handlers, vtables, VAs, `.c` paths (client + server) |
| [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) | Lacunas chat 100%, roadmap P0/P1/P2 |
| [`PACKET_SPEC.md`](PACKET_SPEC.md) | Wire layouts (send/recv), validation, TCP envelope |
| [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) | AES-CTR, handshake `0xA101`/`0xA102`, encrypted pipeline |

## Deep-dive RE

| Doc | Contents |
|-----|----------|
| [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) | Client `0xA101` body → HMAC → `ctx+0xF4` counter |
| [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md) | Outbound `0xA101` on `ps_login.exe` (not `ps_game.exe`) |
| [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) | Lacunas chat + roadmap P0/P1/P2 (atualizado) |

## Tooling

| Doc | Contents |
|-----|----------|
| [`GHIDRA.md`](GHIDRA.md) | Decompile scripts, manifests, prerequisites |
| [`BINARIES.md`](BINARIES.md) | Shaiya Core V9 executables in `bin/` (MD5 table) |
| [`../bin/README.md`](../bin/README.md) | Same — versioned `bin/*.exe` |

## Decompiled corpora (`.c` only)

| Folder | Binary |
|--------|--------|
| [`../game-chat-native/`](../game-chat-native/) | `Game.exe` — client chat + crypto |
| [`../psgame-chat-native/`](../psgame-chat-native/) | `ps_game.exe` — world server |
| [`../pslogin-chat-native/`](../pslogin-chat-native/) | `ps_login.exe` — login key handshake |

Each corpus folder has a minimal README pointing back here.
