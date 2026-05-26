# Index de Documentação — Shaiya Chat Native RE

Todos os documentos de engenharia reversa do chat nativo de Shaiya Core V9 estão localizados na pasta **`docs/`**. O arquivo [`README.md`](../README.md) na raiz do repositório é apenas o ponto de entrada rápido.

---

## 1. Especificações do Wire & Protocolo (Comece aqui)

| Documento | Conteúdo |
|:---|:---|
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Opcodes, handlers, vtables, endereços virtuais (VAs) e caminhos `.c` (cliente + servidor). |
| [`PACKET_SPEC.md`](PACKET_SPEC.md) | Layouts do wire (send/recv), validações e estrutura do envelope TCP. |
| [`CHAR21_SITES.md`](CHAR21_SITES.md) | Inventário de todos os pontos onde o layout `char[21]` (nome do jogador) é lido ou gravado no wire. |
| [`PADDING_SIMULATION.md`](PADDING_SIMULATION.md) | Simulação do preenchimento Pattern B (cauda não-zerada da stack) e ferramentas de teste. |
| [`GM_NOTICE_COMMANDS.md`](GM_NOTICE_COMMANDS.md) | Mapeamento completo dos comandos de notice GM (`/gmnotice`, `/wnotice`, `/bnotice`, etc.), estruturas de pacote e jump table do servidor. |

---

## 2. Handshake & Criptografia (Deep-Dive)

| Documento | Conteúdo |
|:---|:---|
| [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) | Pipeline de criptografia AES-CTR, handshake `0xA101`/`0xA102` e fluxo seguro do socket. |
| [`CRYPTO_COUNTER.md`](CRYPTO_COUNTER.md) | Derivação do counter do AES-CTR usando HMAC-SHA256 e carregamento da chave. |
| [`LOGIN_A101_BODY_MAP.md`](LOGIN_A101_BODY_MAP.md) | Mapeamento byte-a-byte do pacote `0xA101` entre o remetente e o receptor do cliente. |
| [`SERVER_KEY_BLOB_RE.md`](SERVER_KEY_BLOB_RE.md) | Emissão do `0xA101` a partir do `ps_login.exe` (não do `ps_game.exe`). |

---

## 3. Scripts, Mensagens & Dados

| Documento | Conteúdo |
|:---|:---|
| [`SCRIPT_OPCODE_HASHES.md`](SCRIPT_OPCODE_HASHES.md) | Mapeamento dos hashes da VM de script do servidor que disparam os builders `0x1109`–`0x110B`. |
| [`ZONECHAT_MESSAGE_TABLE.md`](ZONECHAT_MESSAGE_TABLE.md) | Estrutura de dados e parser do banco `data/cn_string.DB` para mensagens de zona controladas por scripts. |
| [`ADMIN_F108_WHISPER_RELAY.md`](ADMIN_F108_WHISPER_RELAY.md) | Pipeline de redirecionamento de whisper administrativo C→S `0xF108` para S→C `0xF102`. |

---

## 4. Estado da Pesquisa & Validação

| Documento | Conteúdo |
|:---|:---|
| [`CHAT_RE_STATUS.md`](CHAT_RE_STATUS.md) | Snapshot do progresso estático e artefatos de runtime. |
| [`CHAT_RE_GAPS.md`](CHAT_RE_GAPS.md) | Lacunas identificadas para alcançar 100% de compatibilidade (Prioridades P0/P1/P2). |
| [`MISSING_ARTIFACTS_SEARCH.md`](MISSING_ARTIFACTS_SEARCH.md) | Resultados da varredura automatizada de PCAPs e arquivos no ambiente. |
| [`MISSING_CONTENT_INVENTORY.md`](MISSING_CONTENT_INVENTORY.md) | Inventário completo consolidado do que foi fechado e do que resta de importante para emuladores. |
| [`LIVE_CAPTURE_WINDOWS.md`](LIVE_CAPTURE_WINDOWS.md) | Receitas detalhadas para captura live no Windows usando Wireshark e x64dbg. |
| [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) | Guia de captura passo a passo para triggers de diálogos NPC e notices. |

---

## 5. Corpora de Código Descompilado

| Caminho da Pasta | Executável de Origem | Papel no Pipeline |
|:---|:---|:---|
| [`../game-chat-native/`](../game-chat-native/) | `Game.exe` | Cliente do jogo (Handlers de renderização e rede). |
| [`../psgame-chat-native/`](../psgame-chat-native/) | `ps_game.exe` | Servidor de zona / mundo (Processamento e broadcast). |
| [`../pslogin-chat-native/`](../pslogin-chat-native/) | `ps_login.exe` | Servidor de autenticação (Handshake de criptografia). |

---

## 6. Ferramentas Integradas (Offline)

- [`tools/padding/build_pattern_b_packet.py`](../tools/padding/build_pattern_b_packet.py): Construtor de pacotes simulated Pattern B.
- [`tools/padding/scan_pattern_b_sends.py`](../tools/padding/scan_pattern_b_sends.py): Varre binários em busca de `memset(21)` antes do envio.
- [`tools/zonechat/parse_cn_string_db.py`](../tools/zonechat/parse_cn_string_db.py): Parser offline para bases `cn_string.DB`.
- [`tools/crypto/validate_a101_counter.py`](../tools/crypto/validate_a101_counter.py): Validador offline de HMAC-SHA256 e counter do socket.
- [`tools/wire/emit_session_capture.py`](../tools/wire/emit_session_capture.py): Emissor de sessões de captura baseadas na análise estática.
- [`tools/wire/validate_d1_padding.py`](../tools/wire/validate_d1_padding.py): Validador de preenchimento de stack no wire.
