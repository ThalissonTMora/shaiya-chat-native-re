# Especificação de pacotes — chat nativo Shaiya

Complemento ao [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md). Layouts inferidos dos handlers decompilados — **não editar manualmente**; regenerar `.c` via `tools/ghidra/`.

| Binário | MD5 | ImageBase |
|---------|-----|-----------|
| `Game.exe` | `c1edd96639ad81835624b9c4516ac781` | `0x00400000` |
| `ps_game.exe` | `91b212afbe6623382713772489dc82ce` | `0x00400000` |

**Convenções:** offsets abaixo são **após o opcode `u16` LE**, salvo indicação. `(?)` = inferência parcial. LE = little-endian.

---

## 1. Envelope TCP (wire)

```
┌──────────────┬─────────────────────────────┐
│ wire_len u16 │  ciphertext (wire_len − 2)    │
│  (= plain+2) │  opcode + body cifrados       │
└──────────────┴─────────────────────────────┘
         │ decrypt (client: PacketPayload_Decrypt @ 401080)
         ▼
┌──────────┬──────────────────┐
│ opcode   │  body (handler)  │
│ u16 LE   │                  │
└──────────┴──────────────────┘
```

| Campo | Tamanho | Notas |
|-------|---------|-------|
| `wire_len` | 2 | `tamanho_plaintext + 2` |
| ciphertext | `wire_len − 2` | Cifra: `FUN_00401040` (send) / `PacketPayload_Decrypt` (recv) — algoritmo base **não exportado** |
| `opcode` | 2 | Primeiro campo do plaintext; roteado por `PacketDispatcher` |

**Leitores (cliente):** `PacketRead_Scalar` = memcpy N bytes; `PacketRead_String` = até N bytes (**sem** null no wire).

**Limites:** reader max `0x2000`; send server `< 0x801`.

---

## 2. Cliente → servidor (send)

### Layout comum (chat curto)

```
+0x00  u16  opcode
+0x02  u8   msg_len
+0x03  u8   msg[msg_len]
```

`NetworkSend` recebe `msg_len + 3`. Máx. wire: **255** bytes de texto (`u8`).

| Opcode | Emissor | Canal |
|--------|---------|-------|
| `0x1101` | `PacketSend_Chat(0,0,…)` | Normal |
| `0x1103` | `PacketSend_Chat(0,1,…)` ou `PacketSend_Party(0,…)` | Trade/Party send |
| `0x1104` | `PacketSend_Chat(0,2,…)` ou `PacketSend_Guild(0,…)` | Guild |
| `0x1105` | `PacketSend_Chat(0,3,…)` | Party |
| `0x1107` | `PacketSend_Chat(0,4,…)` | Shout |
| `0x1111` | `PacketSend_Zone` | Zone/Area |
| `0xF101`–`0xF105` | `PacketSend_Chat(1,…)` / Guild/Party com `param_1!=0` | Admin (+ `0xE000` no opcode) |

### Whisper

```
+0x00  u16  opcode (0x1102 / 0xF102)
+0x02  u8   target[21]     // 5×u32 + u8 copiados — semântica (?) nome
+0x17  u8   msg_len
+0x18  u8   msg[msg_len]
```

Tamanho plaintext: `msg_len + 0x18` (24).

---

## 3. Servidor → cliente (recv) — `0x1101`–`0x110A`

### Padrões wire

| Padrão | Opcodes | Layout após opcode |
|--------|---------|-------------------|
| **A** | `1101`, `1105`, `1107`, `F101` | `u32 id` · `u8 len` · `bytes[len]` |
| **B** | `1103`, `1104`, `1108`, `1111` | `char[21] nome` · `u8 len` · `bytes[len]` |
| **C** | `1102` | `u8 dir` · `char[21] nome` · `u8 len` · `bytes[len]` |
| **D** | `1109` | `u8 flag` · `u32 id` · `u8 len` · `bytes[len]` |
| **E** | `110A` | `u32 id` · `u16 id_mensagem` (sem texto — `GetMsg`) |
| **F** | `1106` | `u8 codigo` (ignorado na vtable — SysMsg fixo) |

### Tabela por canal

| Opcode | Canal | Payload (após opcode) | UI / efeito | Balão `4126D0` |
|--------|-------|----------------------|-------------|----------------|
| `0x1101` | Normal | A | `DrawText` estilo `0x22` | **Sim** (cond.) |
| `0x1102` | Whisper | C | `SysMsg` + highlight | Não |
| `0x1103` | Trade | B | `SysMsg` | Não |
| `0x1104` | Guild | B | `SysMsg` | Não |
| `0x1105` | Party | A | `SysMsg` party | Não |
| `0x1106` | Erro | F | SysMsg fixo `0x14B` | Não |
| `0x1107` | Shout | A | `DrawText` estilo `0x27` | **Sim** (cond.) |
| `0x1108` | Megafone | B | `SysMsg` banner `0x1E1` | Não |
| `0x1109` | Zone | D | `DrawText` | Não |
| `0x110A` | Union | E | `DrawText` + `GetMsg` | Não |

### Outros opcodes recv (cliente)

| Opcode | Payload | Efeito |
|--------|---------|--------|
| `0x0E05` / `0x0E06` | `u8 flags` · `u32 entity` · `u32 char` · `u16 fx` (11 B) | FX entidade, sem chat box |
| `0x0F02` | `u8 mode` | Flag monitor GM ou SysMsg |
| `0x0502` | 15 B (6 campos fixos) | Genérico vfn `+0xF0` (não exportada) |
| `0x110B` | `u32 entity` · `char[32] label` | Nameplate |
| `0x1111` | B (nome 21 + len + text) | Area SysMsg `0x31` |
| `0x1112` | `u32 rsv` · `u8 len` · `text` (buf `0x400`) | Texto longo SysMsg |
| `0xF101` | A + vfn `(1,0,…)` | Party notify cor `0x29` |

---

## 4. Servidor — recv / send

### Validação comum (`Chat_ProcessIncoming` / `AdminChat`)

- Texto: **`2 ≤ len ≤ 128`** (`len ≥ 0x81` → kick).
- Cooldown global: `CUser+0x581c`.
- Shout cooldown: `+0x58e4` = now + 30s.
- Megafone cooldown: `+0x58e0` = now + 30s.
- Megafone flag: `+0x58dc` — próximo Normal vira `0x1108`.

### Fluxo servidor por opcode (entrada → saída)

| In (cliente) | Saída broadcast | Função |
|--------------|-----------------|--------|
| `0x1101` Normal | `0x1101` `{opcode, charId, len, msg}` | `Chat_BroadcastNormal` (cells mode 7) |
| `0x1101` + flag megafone | **`0x1108`** `{opcode, name[21], len, msg}` | `Chat_BroadcastNamed` (global) |
| `0x1102` Whisper | `0x1102` ×2 (alvo + eco) | `SConnection_Send` direto |
| `0x1103` Trade | `0x1103` nome+texto | `Chat_BroadcastTrade` |
| `0x1104` Guild | `0x1104` + `0x812` aliança | `Chat_BroadcastGuild` |
| `0x1105` Party | `0x1105` charId+texto | `CParty_BroadcastPacket` |
| `0x1107` Shout | `0x1107` charId+texto | `Chat_BroadcastShout` (mode 5) |
| `0x1108` Megafone | `0x1108` nome+texto | `Chat_BroadcastNamed` |
| `0x1111` Area | `0x1111` nome+texto | `Chat_BroadcastZone` |
| `0x1112` Raid leader | `0x1112` charId+texto | `CParty_BroadcastPacket` |
| `0xF101`–`0xF10A` | opcodes espelhados admin | `AdminChat_ProcessIncoming` |

**Ausentes no server handler:** `0x1109`, `0x110A`, `0x110B` → kick.

### Megafone (item → chat)

1. `ItemUseNSend` (`4728E0`) — valida item `0x40–0x67` ou `0xACA1–0xACA7`.
2. Emite `0x702`, `0x50A`, `0x40E` (inventário/slot).
3. Seta flag `CUser+0x58dc` `(?)` — leitura confirmada em `1101`/`1108`.
4. Cliente envia texto como `0x1101` → server reempacota **`0x1108`**.

### Layouts de saída (broadcast)

**Normal / Party / Shout (`1101`, `1105`, `1107`):**
```
u16 opcode · u32 charId · u8 len · bytes[len]     // tam = len + 7
```

**Nome + texto (Megafone, Guild, Trade, Area):**
```
u16 opcode · u8 name[21] · u8 len · bytes[len]      // tam = len + 0x18
```

**Guild aliança:**
```
u16 0x812 · u8 name[21] · u8 len · bytes[len] · u32 guildId   // tam = len + 0x1C
```

---

## 5. Confiança para reimplementação

| Objetivo | Confiança | O que este doc cobre |
|----------|-----------|----------------------|
| Hook send/recv com opcodes corretos | **Alta (~90%)** | Layouts send + recv principais |
| Servidor compatível com client stock | **Alta (~80%)** | Validação len, broadcasts, megafone |
| Clone UI pixel-perfect | **Média (~65%)** | Fora do escopo — ver vtables/UI |
| Criptografia end-to-end | **Baixa (~40%)** | Envelope documentado; algoritmo não exportado |

**Lacunas TODO:** decompilar `FUN_00401040` / `FUN_004e3450`; vfn `+0xF0` (`0x0502`); charset/padding campos fixos; quem seta `+0x58dc` após item.

---

## 6. Referência cruzada

| Doc | Conteúdo |
|-----|----------|
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | Handler VA, vtable, arquivo `.c` |
| `game-chat-native/handlers/` | Evidência recv cliente |
| `psgame-chat-native/handlers/Chat_ProcessIncoming_0047f400.c` | Evidência server |
| `tools/ghidra/*.manifest` | Lista completa de VAs |
