# Captura ao vivo — Windows + DLLs injetadas (Paradise / sdev)

Use enquanto `ps_game.exe` + `Game.exe` rodam com **`sdev.dll`** (servidor) e DLL do cliente injetada.

Paths confirmados no WSL (`/mnt/c/ShaiyaServer`):

| Artefato | Caminho |
|----------|---------|
| Server bin | `PSM_Client/Bin/ps_game.exe` |
| Client `data/` | `PSM_Client/Bin/Data/cn_string.DB` (31 entradas — já vendido no repo) |
| DLL servidor | `PSM_Client/Bin/sdev.dll` |
| Logs servidor | `PSM_Client/Bin/Log/PS_GAME__system.log__*.log` |
| Capturas antigas (session MITM) | `ps_session_redis/captures/*.log` — **sem** opcodes `0x11xx` (só login/session) |

---

## O que falta vs o que você já tem na tela

Sessão de teste (UI) — **todos os canais visíveis** com texto `teste` / `olá`:

| Linha na UI | Opcode recv (S→C) | Pattern | Send cliente (C→S) |
|-------------|-------------------|---------|-------------------|
| `JACKSON : olá` / `teste` | `0x1101` | A | `PacketSend_Chat` |
| `[Whisper]JACKSON : teste` | `0x1102` | C | `PacketSend_Whisper` |
| `[Trade]JACKSON : teste` | `0x1103` | B (`char[21]` nome) | `PacketSend_Chat(0,1,…)` |
| `[area]JACKSON : teste` | `0x1111` | B | `PacketSend_Zone` |
| `[Guild]JACKSON : teste` | `0x1104` | B | `PacketSend_Guild` / `Chat(0,2,…)` |

Isso **valida handlers + UI** no cliente stock; **não** grava o wire. **D1** continua aberto até um hexdump dos **21 bytes do nome** em um S→C `0x1104` (ou `0x1103`/`0x1111`) em `SConnection_Send` @ `0x004ED0E0`.

| ID | Ainda falta no disco | Como fechar |
|----|---------------------|-------------|
| **D1** padding `char[21]` | Hex dos 21 B após opcode em S→C Pattern B | `bp 004ED0E0` + `?by [buf+2] l 21` no guild/trade/area echo |
| **D3** A101 + PRNG | Captura login | Wireshark porta login + `validate_a101_counter.py` |
| **D4** `0x1109`–`0x110B` | Evento script/NPC | Trigger zone script |
| **D5** F108 | Binário GM | Fora do `Game.exe` stock |

---

## 1. Captura rápida — pasta que o WSL lê

Enquanto joga, grave hex em arquivo compartilhado:

```text
C:\ShaiyaServer\PSM_Client\Bin\chat_capture_live.log
```

Formato sugerido (uma linha por pacote plaintext):

```text
TX opcode=0x1101 len=12 raw=...
RX opcode=0x1104 len=28 raw=...
```

No WSL (gerar captura estática a partir do RE + sessão UI):

```bash
python3 tools/wire/emit_session_capture.py --name JACKSON --text teste \
  --deploy /mnt/c/ShaiyaServer/PSM_Client/Bin/chat_capture_live.log
python3 tools/wire/validate_d1_padding.py test/captures/ui_session_20260526_static.log
python3 tools/wire/scan_capture_logs.py /mnt/c/ShaiyaServer/PSM_Client/Bin/chat_capture_live.log
```

---

## 2. x64dbg — servidor (`ps_game.exe`)

Attach após `connect dbagent`.

```text
bp 004ED0E0
```

No hit: `[ESP+8]` = buffer, `[ESP+C]` = size.

| Filtro | Condição |
|--------|----------|
| Guild S→C | `*(word ptr [buf]) == 1104h` |
| Normal C→S | `*(word ptr [buf]) == 1101h` |

Log guild name tail (D1):

```text
?by [buf+2] l 21
```

---

## 3. x64dbg — cliente (`Game.exe`)

| Alvo | VA |
|------|-----|
| Recv dispatch | `005F1E10` |
| Send chat | `005ED060` |
| PRNG handshake | `00404610` |
| Recv A101 | `005E3D60` |

Após login, break em `005ED060` ao enviar "teste" — confirma opcode `0x1101`.

---

## 4. DLLs injetadas (sdev / Paradise)

- **`sdev.dll`** no servidor: Genesis Chat (`GenesisChatEngine`) — opcodes **0x13xx** no emulador, não substitui wire stock `0x11xx` sem bridge explícita.
- **Cliente**: hooks em `custom_chat_native_bridge` (UI/render), **não** log automático de `NetworkSend` no repo atual.

Para log wire com DLL, adicione temporariamente em hook de send/recv (VAs em [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md)):

```cpp
// ps_game: log antes de SConnection_Send @ 0x004ED0E0
// Game: log após PacketPayload_Decrypt ou em NetworkSend @ 0x005EA9A0
```

Ou use **Wireshark** na interface loopback/NIC com filtro `tcp port 30800` (porta do world — conferir `Server.ini` / `connect.cfg`).

---

## 5. MITM session (login apenas)

Capturas em `ps_session_redis/captures/` cobrem **ps_session** (porta ~30900), **não** o canal de jogo com chat `0x11xx`.

Para login `0xA101`, reutilize `mitm_capture.py` ou Wireshark na porta do login.

---

## 6. Pós-sessão — varrer tudo

```bash
./tools/artifacts/find_missing.sh \
  /mnt/c/ShaiyaServer/PSM_Client/Bin \
  /mnt/c/ShaiyaServer/ps_session_redis/captures

python3 tools/wire/scan_capture_logs.py /mnt/c/ShaiyaServer/ps_session_redis/captures
```

Copie novos `.log` para o repo:

```bash
cp /mnt/c/ShaiyaServer/PSM_Client/Bin/chat_capture_live.log \
   test/captures/live_$(date +%Y%m%d).log
```

---

## Cross-reference

- [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md)
- [`MISSING_ARTIFACTS_SEARCH.md`](MISSING_ARTIFACTS_SEARCH.md)
