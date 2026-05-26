# Documentation — native chat RE

This folder **is versioned in git** (not in `.gitignore`). Use it for deep-dive RE reports and binaries outside the main chat manifests (`game-chat-native/`, `psgame-chat-native/`).

## Layout

| Path | Purpose |
|------|---------|
| [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) | Client `0xA101` body → HMAC → AES-CTR `ctx+0xF4` |
| [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md) | Outbound `0xA101` on `ps_login.exe` (not `ps_game.exe`) |
| [`pslogin-native/`](pslogin-native/) | Ghidra exports for login-server key handshake (15 `.c`) |

## Root specs (stay at repo root)

These are the **primary entry points** and remain next to [`README.md`](../README.md):

- [`CHAT_CHANNEL_MAP.md`](../CHAT_CHANNEL_MAP.md) — opcodes, handlers, vtables
- [`PACKET_SPEC.md`](../PACKET_SPEC.md) — wire layouts
- [`WIRE_CRYPTO.md`](../WIRE_CRYPTO.md) — TCP envelope, AES-CTR, handshake overview

Regenerate login exports: `../tools/ghidra/decompile-pslogin-crypto.sh`
