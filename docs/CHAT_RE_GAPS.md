# Chat RE — lacunas e roadmap (Shaiya Core V9)

Atualizado: **maio 2026** · binários em `bin/` · baseline: `Game.exe` `c1edd966…`, `ps_game.exe` `91b212af…`.

Objetivo deste documento: fechar o que falta para **chat 100%** (wire + server rules + pipeline cliente), **sem reabrir** `0xA101` client recv / `ps_login` send (já fechados em `WIRE_CRYPTO.md` / `pslogin-chat-native/`).

---

## Summary

| Prioridade | Tema | Status após esta rodada |
|------------|------|-------------------------|
| **P0** | `char[21]` recv/send + padding wire | **INFERRED ~99%** tail = lixo de stack (não zeros); captura 1× guild fecha P0-1 — ver `PADDING_SIMULATION.md` |
| **P0** | Admin recv `0xF102`–`0xF109` | **Fechado** — 7× `.c` + vtable `+0x334` / stubs `+0x344`/`+0x348` |
| **P1** | Balloon gates `DAT_*` → map §8 | **Fechado** — `+0x1D0` = cinematic suppress CONFIRMED; `DAT_007c0d8c` = `[VIDEO] WATER` |
| **P1** | `Chat_BroadcastNamed` / megaphone `0x1108` | **Fechado** — stub → `World_BroadcastTradeCore` queue mode **3** view **7** |
| **P1** | Whisper server patch `+0x0B` | **Fechado** — byte **`0x16`** cleared; Pattern C `dir` 0/1 CONFIRMED |
| **P1** | Balloon `0x1101`/`0x1107` recv path | **CONFIRMED** cadeia vtable → balloon create @ `0x4126D0` → tick `0x412780` |
| **P1** | `NativeChatSendUI` vs submit | **CONFIRMED** — FX 3D vs `ChatWindow_SubmitChatInput` → `PacketSend_*` |
| **P1** | Server push `0x1109`–`0x110B` | **Fechado** — 4× builders em `psgame-chat-native/send/`; layouts D/E/G em `PACKET_SPEC` |
| **P2** | UI pixel-perfect / hooks render | Parcial — fora do mínimo wire-compat |
| **P2** | `0xF107`/`0xF109` client effect | **Fechado** — stub vfn; server bind @ `CUser+0x5810`; chain doc |
| **P1** | `0xF108` bound whisper relay | **Fechado** — C→S Pattern I @ `0x00480462`; S→C dual `0xF102`; doc [`ADMIN_F108_WHISPER_RELAY.md`](ADMIN_F108_WHISPER_RELAY.md) |
| **P1** | `DAT_022aa816` faction global | **CONFIRMED** — single write @ `0x0048BFEA` from local `entity+0xBF4` |

---

## Scope

| Artefato | Escopo desta análise |
|----------|----------------------|
| Client | `game-chat-native/handlers/*`, `vtable/*`, `balloon/*`, `send/*`, `ui/*` |
| Server | `psgame-chat-native/handlers/Chat_ProcessIncoming_0047f400.c`, `broadcast/*` |
| Fora de escopo | `0xA101`/`0xA102` game client, `ps_login` key blob, crypto counter wire |

---

## Findings

### 1. `char[21]` — CONFIRMED

#### Client recv — `PacketRead_String` com `count = 0x15` (21)

| Opcode | Handler VA | Evidência |
|--------|------------|-----------|
| `0x1102` Whisper | `0x005E5180` | `FUN_005f4780(&local_9c, 0x15)` após `PacketRead_Scalar` 1 B dir — `Handler_ChatWhisper_005e5180.c` |
| `0x1103` Trade | `0x005E5250` | `FUN_005f4780(local_a0+1, 0x15)` — `Handler_ChatTrade_005e5250.c` |
| `0x1104` Guild | `0x005E5310` | idem — `Handler_ChatGuild_005e5310.c` |
| `0x1108` Megaphone | `0x005E5540` | idem — `Handler_ChatMegaphone_005e5540.c` |
| `0x1111` Area | `0x005E57D0` | idem — `Handler_Chat_Area_1111_005e57d0.c` |

`PacketRead_String` @ `0x005F4780`: `memcpy` fixo até `param_2` bytes; **sem** null no wire (`recv/PacketRead_String_005f4780.c`).

**Não usam `char[21]`:** `0x1101`, `0x1105`, `0x1107` (pattern A: `u32` + `u8 len`); `0x1109` (pattern D); `0x110A` (`u32` + `u16`); `0x110B` (`char[32]` @ `0x20`).

#### Client send — Whisper `0x1102`

`PacketSend_Whisper` @ `0x005ED160`: copia `param_2[0..4]` (5×`u32`) + `*(param_2+5)` → **21 bytes**; `NetworkSend` size `param_3 + 0x18` (24 = opcode + 21 + len byte + …) — `send/PacketSend_Whisper_005ed160.c`.

**INFERRED:** campo “nome” no send é o mesmo layout de 21 B que no recv (5 dwords + byte), não string length-prefixed.

#### Server broadcast — null-terminated copy into `char[21]`

| Site | VA | Evidência |
|------|-----|-----------|
| Guild + alliance `0x812` | `0x00432530` | `char local_a2[21]`, `char acStack_13e[21]`; loop `do { *dst = *src; } while (*src++ != '\0')` — `broadcast/Chat_BroadcastGuild_00432530.c` |
| Megaphone repack `0x1108` | `0x0047F400` case `0x1101` | copia `CUser+0x184` → buffer; `FUN_004d55b0(&local_14c, bVar1 + 0x18)` — `handlers/Chat_ProcessIncoming_0047f400.c` L81–91 |
| Trade `0x1103` | `0x0047F400` | mesmo padrão de cópia de `param_1+0x184` L157–165 |
| Whisper forward | `0x0047F400` case `0x1102` | patch byte wire **`+0x16`** (`*(unaff_EBX+0xb)=0` como `u16*`); S→C Pattern C `dir=0` alvo / `dir=1` echo L138 |

Tamanho wire name+text: **`len + 0x18`** (24 = 2 opcode + 21 name + 1 len) — CONFIRMED em `FUN_004d55b0(..., bVar1+0x18)`.

#### Padding / charset no wire

- **CONFIRMED:** leitura cliente sempre **21 bytes fixos** (não lê até null).
- **CONFIRMED:** servidor preenche nome via cópia até `'\0'` em buffer stack `[21]`; **sem** `memset` da cauda antes de `SConnection_Send` (`Chat_BroadcastGuild` asm `0x004325B0`–`0x00432615`).
- **HYPOTHESIS:** bytes `[strlen..20]` no wire = lixo de stack (captura `0x1104` obrigatória). **INFERRED:** emulador deve `memset(name,0,21)` antes do copy — ver [`CHAR21_SITES.md`](CHAR21_SITES.md), [`PACKET_SPEC.md`](PACKET_SPEC.md) § `char[21]`.
- **Validação:** captura Wireshark em guild/megaphone; comparar bytes `name[ strlen..20 ]`.

---

### 2. Balloon gates `0x1101` / `0x1107` — CONFIRMED call path

```text
PacketDispatcher → Handler_ChatNormal/Shout/Party
  → vtable+0x324 ChatNormalParty_vfn @ 0x0059C380  (1101, 1105, F101)
  → vtable+0x32C ChatShout_vfn @ 0x0059AA10       (1107)
       → FUN_004126d0(entity, text)   // manifest: ChatString_Sanitize; balloon create
            → FUN_0041fcc0(text)       // ChatBalloon_CreateStaticText
            → entity+0x288 = balloon, +0x28C = timer (_DAT_00747538)

Entity_Render @ 0x00453ED0 (when DAT_007c0e60 != 0)
  → FUN_00412780(entity)               // Entity_ChatBalloon_Tick
       → gates below → FUN_00420010    // ChatBalloon_DrawProjected
```

#### `Entity_ChatBalloon_Tick` @ `0x00412780` — **Fechado (P1-2)**

Tabela completa: [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) §8.

**P1 addendum — `+0x1D0` (maio 2026):**

| Claim | Tag | Evidence |
|-------|-----|----------|
| `+0x1D0` = `cinematic_overlay_suppress` on UI shell (`DAT_007c0838`) | **CONFIRMED** | Writers `0x570FFA`/`0x57107A` (`UIShell_CinematicEnter`), `0x571766`/`0x571BC5` (`UIShell_CinematicEnterAlt`); init `0x56F515` (`UIShell_ctor`) |
| Gate: skip balloon when `+0x1D0==1` and `[VIDEO] WATER` enabled | **CONFIRMED** | `Entity_ChatBalloon_Tick` asm `0x412781`–`0x412799`; paired OR with `DAT_007c0d8c` |
| `DAT_007c0d8c` = `[VIDEO] WATER`, **not** `[SOUND] VOICE_NPC` | **CONFIRMED** | INI load @ `0x406A59`/`0x406A95` (`.rdata` `"WATER"`/`"VIDEO"`); VOICE_NPC → `DAT_007c0e34` @ options case 2 |
| Cinematic entry guarded when `+0x1D0!=0` | **CONFIRMED** | `UIShell_CinematicSceneHandler` @ `0x571C24`, `0x57227C` |

#### `ChatNormalParty_vfn` — quando chama balloon (INFERRED gates)

De `vtable/ChatNormalParty_vfn_0x324_0059c380.c` (recv normal, `param_1==0`):

- Resolve entidade: `FUN_00452b10(param_3)` (charId).
- Balloon path: `*(entity+0x2b7) == DAT_022aa816` (mesma facção/aliança).
- **`DAT_022aa816` — CONFIRMED local player faction:** único write @ **`0x0048BFEA`** (`mov al, entity+0xBF4` → global) no path de entrada de personagem/zona; leituras em `ChatNormalParty_vfn` @ `0x0059C463` e `ChatShout_vfn` comparam contra `entity+0x2B7` de entidades remotas. Repro: `objdump -d bin/Game.exe | grep 'a2 16 a8 2a 02'`.
- Texto: `FUN_004126d0(param_5)` ou após wrap `FUN_00422310` se `DAT_007ab0d4!=1 && DAT_007c0e58==1`.
- Chat box: sempre `DrawText` style `0x22` / party `0x29` quando `param_2!=0`.

`ChatShout_vfn` @ `0x0059AA10`: mesma `FUN_004126d0` para entidade shout; `DrawText` `0x27`.

**CONFIRMED:** `DAT_022aa816` = facção do jogador local (cache de `entity+0xBF4` @ write `0x0048BFEA`).

---

### 5. Admin whisper bind `0xF107` / `0xF109` — CONFIRMED (May 2026)

| Claim | Tag | Evidence |
|-------|-----|----------|
| Server sends F107/F109 (only two opcode loads in `ps_game.exe`) | **CONFIRMED** | `0x004803C7`, `0x0047F390` — `objdump` |
| Wire S→C: opcode + `char[21]`, size **0x17** | **CONFIRMED** | `push 0x17` @ `0x004803FA`, `0x0047F3B0` |
| Server stores bind @ `CUser+0x5810` = target `+0x128` | **CONFIRMED** | asm `0x004803CC` `mov edx, 0x128(esi)` → `0x5810(ebp)` |
| F109 C→S is opcode-only (no body) | **CONFIRMED** | `AdminChat_ProcessIncoming` case L317–318 |
| Client handler: read 21 B + stub vfn only | **CONFIRMED** | asm `0x005DE950`–`0x005DE999`; vfn `ret 4` @ `0x0056BCB0` |
| Client does **not** call `ChatWindow_SetWhisperTarget` / `+0x198` | **CONFIRMED** | zero xrefs from handlers; UI path separate @ `0x0047C690` |
| Stock `Game.exe` does **not** send F107/F109 | **CONFIRMED** | `objdump` — no `mov $0xF107`/`$0xF109` in client |

Chain: [`psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md`](../psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md).

---

### 6. Admin bound whisper relay `0xF108` — CONFIRMED (May 2026)

| Claim | Tag | Evidence |
|-------|-----|----------|
| Handler only in `AdminChat_ProcessIncoming`, not `Chat_ProcessIncoming` | **CONFIRMED** | case @ L272; jump table index 7 → asm `0x00480462` |
| C→S wire: opcode + `u8 len` + text (plain `len+3`) | **CONFIRMED** | L287–290; asm `0x004804CA`–`0x004804E4` |
| Requires `CUser+0x5810 != 0` from F107 bind | **CONFIRMED** | asm `0x00480462`–`0x0048046A` |
| Partner lookup `World_FindUserById` @ `0x00414D10` | **CONFIRMED** | asm `0x00480486` |
| S→C relay as **`0xF102`** Pattern C (dual send), never `0xF108` | **CONFIRMED** | `mov $0xF102` @ `0x00480497`; sizes `len+0x19` |
| No bind / offline → `0x1106` size 3 | **CONFIRMED** | asm `0x00480587` |
| Client: no dispatcher case, no send site | **CONFIRMED** | `PacketDispatcher` L1350–1353; `objdump` zero `mov $0xF108` |
| GM tool send path for C→S F108 | **HYPOTHESIS** | absent from stock `Game.exe`; capture needed |

Chain: [`docs/ADMIN_F108_WHISPER_RELAY.md`](ADMIN_F108_WHISPER_RELAY.md).

---

### 3. `NativeChatSendUI` @ `0x0045BBE0` vs `ChatWindow_SubmitChatInput` @ `0x0047A4B0`

| | `ChatWindow_SubmitChatInput` | `NativeChatSendUI` |
|--|------------------------------|---------------------|
| **Role** | Submit da janela de chat (Enter) | Spawner de **efeitos 3D / fila de objetos** no mundo |
| **Network** | `ChatWindow_FormatOutgoing` → `PacketSend_*` → `NetworkSend` | **Nenhum** `NetworkSend` / `PacketSend_*` no corpo |
| **Entrada** | Canal em `param_1+0x194`; prefixos `! %s` etc. | `param_6` ∈ {5,6,7,…}: trails, projéteis; `param_3==0x222` estende timer |
| **Evidência** | `ui/ChatWindow_SubmitChatInput_0047a4b0.c` → `FUN_005663b0` | `ui/ChatWorldFX_SendUI_0045bbe0.c` → `FUN_004583d0` / `CreateObject` |

**CONFIRMED:** não são alternativas para o mesmo send de chat; renomear símbolo no manifest de “Alternate send UI” para **“World FX / speech effect UI”** evita confusão (P2 doc).

---

### 4. Megaphone `0x1108` — `Chat_BroadcastNamed` (P1-3 **Fechado**)

```text
Chat_ProcessIncoming @ 0x0047F400
  case 0x1101 + CUser+0x58DC: repack opcode 0x1108 (name @ CUser+0x184, Pattern B)
  case 0x1108 + cooldown: idem
       -> Chat_BroadcastNamed @ 0x004D55B0
            -> World_BroadcastTradeCore @ 0x00419240(zoneId=CUser+0xDC, 0, 7)
                 -> per world slot: CUser_SendQueueEnqueue(mode=3, view=7) @ 0x00426DD0
                 -> flush: SendQueue_Mode3_ZoneGroup @ 0x00427B20 -> SConnection_SendEx @ 0x004ED0B0
```

**INFERRED:** view id **7** na fila equivale ao mesmo parâmetro **7** de `Chat_BroadcastNormal` → `Zone_PSendViewCells` (normal imediato), mas megaphone usa **fila diferida** mode **3**, não `Chat_BroadcastViewMode7` @ `0x004D56D0` (arg spatial **5**).

Detalhe: `psgame-chat-native/broadcast/Chat_BroadcastNamed_chain.md`.

---

## Structures / Opcodes (quick ref)

Ver [`PACKET_SPEC.md`](PACKET_SPEC.md) — patches nesta rodada na seção `char[21]` e whisper send.

| Pattern | Opcodes | Name field |
|---------|---------|------------|
| A | `1101`,`1105`,`1107` | `u32 charId` |
| B | `1103`,`1104`,`1108`,`1111` | `char[21]` |
| C | `1102` | `u8 dir` + `char[21]` |
| D | `1109` | `u8` + `u32` + text |
| Send whisper | `1102` | `u8 target[21]` (5×u32+u8) |

---

## Artifacts

| Path | Conteúdo |
|------|----------|
| `docs/CHAT_RE_GAPS.md` | Este roadmap |
| `docs/PACKET_SPEC.md` | Spec wire (atualizado `char[21]`) |
| `game-chat-native/handlers/Handler_Chat*_*.c` | Leituras `0x15` |
| `psgame-chat-native/broadcast/Chat_BroadcastGuild_00432530.c` | Null-term name |
| `game-chat-native/balloon/Entity_ChatBalloon_Tick_00412780.c` | Gates balloon |
| `game-chat-native/ui/UIShell_CinematicEnter_00570ff0.c` | `+0x1D0` writer (cinematic suppress) |
| `game-chat-native/init/UIShell_ctor_0056f470.c` | UI shell alloc; `+0x1D0` init |
| `game-chat-native/init/OptionsIni_LoadVideoWater_00406a40.c` | `DAT_007c0d8c` INI load |
| `psgame-chat-native/broadcast/Chat_BroadcastNamed_chain.md` | Megaphone `0x1108` queue path |
| `docs/WIRE_CAPTURE_GUIDE.md` | Captura `0x1104` padding + push `0x1109`–`0x110B` |
| `game-chat-native/vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Balloon trigger |
| `psgame-chat-native/send/Chat_AdminWhisper_F107_F109_chain.md` | Admin bind F107/F109 S→C + CUser+0x5810 |
| `docs/ADMIN_F108_WHISPER_RELAY.md` | Bound whisper relay F108 C→S → S→C F102 |

---

## Roadmap acionável (P0 / P1 / P2)

### P0 — bloqueia emulador / proxy 100% compat

| # | Tarefa | Reprodução | Entregável |
|---|--------|------------|------------|
| P0-1 | **Padding `char[21]` no wire** | Captura guild `0x1104` + hexdump offset name+strlen | Nota em `PACKET_SPEC` ou tabela CONFIRMED/HYPOTHESIS |
| P0-2 | **Decompilar admin recv `0xF102`–`0xF109`** | ✅ `game-chat-native/handlers/Handler_Chat_Admin_F*.c` |
| P0-3 | **Layouts recv admin** | ✅ `PACKET_SPEC` + `CHAT_CHANNEL_MAP` §2 admin table |

### P1 — chat funcional completo (stock behavior)

| # | Tarefa | Status |
|---|--------|--------|
| P1-1 | **Decompilar `Chat_PacketBuilder_1109/110A/110B`** | ✅ `psgame-chat-native/send/*.c` |
| P1-2 | **Balloon gates booleanos** | ✅ `CHAT_CHANNEL_MAP` §8 |
| P1-3 | **`Chat_BroadcastNamed` corpo real** | ✅ `Chat_BroadcastNamed_chain.md` |
| P1-4 | **Whisper server patch** | ✅ `PACKET_SPEC` § Whisper + handler L105/L138 |

### P2 — UI proprietária / polish

| # | Tarefa | Notas |
|---|--------|-------|
| P2-1 | Renomear `NativeChatSendUI` → `ChatWorldFX_SendUI` | ✅ manifest + `ui/ChatWorldFX_SendUI_0045bbe0.c` |
| P2-2 | Hooks `ChatWindow_Render_*` @ `0x47DB8D` | Esconder UI nativa — já há landmarks |
| P2-3 | `GmCommand_Dispatch` / staff overlay | Fora do wire mínimo |
| P2-4 | Pixel-perfect tabs/IME | `ChatUIFont_*`, `InputCapture` |

---

## Assumptions & Limitations

- Decompilações Ghidra 11.2; nomes `FUN_*` onde PDB ausente.
- `Chat_BroadcastNamed` @ `0x4D55B0` é stub para `World_BroadcastTradeCore` @ `0x419240` (fila mode **3**, view **7**); não é o mesmo entry que `Chat_BroadcastViewMode7` @ `0x4D56D0` (spatial imediato, arg **5**).
- Admin `F107`/`F109`: handlers leem `char[21]`; vfn @ `0x0056BCB0` stub; semântica server fechada em `Chat_AdminWhisper_F107_F109_chain.md`.
- **`0xF108`:** C→S relay fechado @ `0x00480462`; S→C como dual `0xF102`; ver `ADMIN_F108_WHISPER_RELAY.md`. Origem do send C→S (GM tool) ainda **HYPOTHESIS**.
- Balloon: símbolo `ChatString_Sanitize` @ `0x4126D0` é **create balloon**, não sanitização de string.

---

## Out-of-Scope Observations

- Crypto recv counter: **fechado estaticamente** em `CRYPTO_COUNTER.md` (`digest[0..15]` → `CounterLoad`); captura 1× sessão recomendada. Server outbound `0xA101` ainda em `SERVER_KEY_BLOB_RE.md`.
- `Chat_BroadcastTrade` delega para `World_BroadcastTradeCore` — spatial mode `4`, não monta pacote inline no `.c` exportado.
- `Handler_ChatZone` usa pattern D (`u8` + `u32`), não `char[21]`.

---

## Next Validation Steps (ordered) — **outro agente / captura**

1. **P0-1 Wire padding:** captura `0x1104` guild — hexdump 21 B do nome após `'\0'` (receita: [`WIRE_CAPTURE_GUIDE.md`](WIRE_CAPTURE_GUIDE.md) §3).
2. **NPC push wire:** hook `SConnection_Send` @ `0x004ED0E0` durante script — validar `0x1109`/`0x110A`/`0x110B` (§4 do guia).
3. **Script callers:** xref `0x004A2210` / `0x004CB3D0` — mapa quest→opcode (fora do mínimo estático).
4. ~~**Balloon UI+0x1D0:** breakpoint em writes a `DAT_007c0838+0x1D0`.~~ **Fechado** — `cinematic_overlay_suppress`; writers `UIShell_CinematicEnter` / `UIShell_CinematicEnterAlt`; ver `CHAT_CHANNEL_MAP` §8.
5. ~~**F107/F109:** confirmar se algum campo global muda apesar do stub vfn.~~ **Fechado** — nenhum efeito cliente; ver §5 em Findings.
6. **F108 C→S capture:** GM session pós-F107 bind — validar plain `len+3` e dual S→C `0xF102` (receita em `ADMIN_F108_WHISPER_RELAY.md` § Reproduce).

---

## Cross-reference

| Doc | Uso |
|-----|-----|
| [`CHAT_CHANNEL_MAP.md`](CHAT_CHANNEL_MAP.md) | VAs handlers/vtable |
| [`PACKET_SPEC.md`](PACKET_SPEC.md) | Layouts wire |
| [`.features/GAP_ANALYSIS_PROMPT.md`](../.features/GAP_ANALYSIS_PROMPT.md) | Prompt orquestração 100% |
