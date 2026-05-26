# Shaiya — Native Chat RE (Client ↔ Server)

Reverse-engineering package for Shaiya's stock native chat: decompiled C, symbol manifests, and channel/opcode maps.

| Target | MD5 | Functions |
|--------|-----|-----------|
| `Game.exe` (client) | `c1edd96639ad81835624b9c4516ac781` | **131** |
| `ps_game.exe` (server) | `91b212afbe6623382713772489dc82ce` | **114** |

ImageBase for both: `0x00400000`.

## Start here

| Doc | Purpose |
|-----|---------|
| [`game-chat-native/CHAT_CHANNEL_MAP.md`](game-chat-native/CHAT_CHANNEL_MAP.md) | **Main reference** — opcodes, handlers, vtables, VAs, `.c` paths |
| [`psgame-chat-native/README.md`](psgame-chat-native/README.md) | Server pipeline overview |
| [`tools/ghidra/`](tools/ghidra/) | Manifests + scripts to regenerate exports |

## Layout

```
game-chat-native/          # Client — 131 decompiled .c + CHAT_CHANNEL_MAP.md
psgame-chat-native/        # Server — 114 decompiled .c
tools/ghidra/              # Manifests, decompile scripts, Ghidra Java export
bin/                       # Place Game.exe / ps_game.exe here (not in git)
```

## Regenerate (optional)

Requires Ghidra 11.2 + JDK 21. See [`tools/ghidra/README.md`](tools/ghidra/README.md).

```bash
# copy binaries to bin/ first
chmod +x tools/ghidra/decompile-*.sh
./tools/ghidra/decompile-game-chat.sh
./tools/ghidra/decompile-psgame-chat.sh
```

## Highlights

- **End-to-end flow:** send (`PacketSend_*` → `NetworkSend`) and recv (`PacketDispatcher` → handler → vtable → UI).
- **3D talk balloons:** `ChatString_Sanitize` @ `0x4126D0` — only Normal, Party, Shout (`0x1101`/`0x1105`/`0x1107`).
- **VTable base (PE-validated):** `0x00746744` in `.rdata`.

Contributions, validation and forks welcome.
