# Referência do chat nativo — `Game.exe`

Tabelas de endereços e arquivos decompilados. Base: `0x00400000` · MD5 `c1edd96639ad81835624b9c4516ac781`.

## Estrutura deste repositório

| Pasta / arquivo | Conteúdo |
|-----------------|----------|
| **`game-chat-native/`** (esta pasta) | **131** `.c` + este `CHAT_CHANNEL_MAP.md` + `game-chat-functions.manifest` |
| **`psgame-chat-native/`** | **114** `.c` servidor + `psgame-chat-functions.manifest` + `README.md` |
| **`tools/ghidra/`** | Manifests canônicos + scripts para regenerar exports |

| Global | VA / valor |
|--------|------------|
| Singleton chat | `DAT_022fa2f0` |
| Vtable (`.rdata`) | `0x00746744` |
| Regenerar `.c` | `./tools/ghidra/decompile-game-chat.sh` *(binários em `bin/`)* |
| Manifesto (cliente) | `game-chat-functions.manifest` *(nesta pasta)* |
| Manifesto (servidor) | `../psgame-chat-native/psgame-chat-functions.manifest` |

---

## 1. Fluxo resumido

| Direção | Passos principais |
|---------|-------------------|
| **Envio** | `InputCapture` → `SubmitChatInput` → `PacketSend_*` → `NetworkSend` |
| **Recepção** | `GameSocketWndProc` → decrypt → `PacketDispatcher` → handler → vtable → buffer/format → `DrawText` / `SysMsg` → `ChatWindow_Render` |
| **Mundo / entidade** | Notify (`0xE05`/`0xE06`), balão de fala (`4126D0`), nameplate (`56C650`), FX posição |

---

## 2. Pacotes recebidos (`0x11xx` e afins)

Fonte do roteamento: `recv/PacketDispatcher_005f1e10.c` (~L917).

| Opcode | Canal | Handler `0x…` | Arquivo handler | VTable `+off` / `0x…` | Arquivo vtable | Efeito principal |
|--------|-------|---------------|-----------------|----------------------|----------------|------------------|
| `0x0E05` | Notify A | `005E5000` | `handlers/Handler_ChatNotify_E05_005e5000.c` | `+0x31C` / `00595690` | `vtable/ChatNotify_vfn_0x31C_00595690.c` | FX / posição entidade (sem chat box) |
| `0x0E06` | Notify B | `005E5070` | `handlers/Handler_ChatNotify_E06_005e5070.c` | `+0x320` / `005957E0` | `vtable/ChatNotify_vfn_0x320_005957e0.c` | FX / posição entidade (sem chat box) |
| `0x0F02` | Admin monitor | `005E4E30` | `handlers/Handler_AdminChatMonitor_005e4e30.c` | `+0x308` / `00595570` | `vtable/AdminChatMonitor_vfn_0x308_00595570.c` | Flag monitor ou `SysMsg` |
| `0x0502` | Misc | `005E0CF0` | `handlers/Handler_Packet_0502_005e0cf0.c` | — | — | Pacote genérico (case `0x502` no dispatcher) |
| `0x1101` | Normal | `005E50E0` | `handlers/Handler_ChatNormal_005e50e0.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Chat box + balão 3D |
| `0x1102` | Whisper | `005E5180` | `handlers/Handler_ChatWhisper_005e5180.c` | `+0x328` case `0` / `0059BDB0` | `vtable/ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` | Chat box + highlight whisper |
| `0x1103` | Trade | `005E5250` | `handlers/Handler_ChatTrade_005e5250.c` | `+0x328` case `1` | idem | Chat box (`SysMsg`) |
| `0x1104` | Guild | `005E5310` | `handlers/Handler_ChatGuild_005e5310.c` | `+0x328` case `2` | idem | Chat box (`SysMsg`) |
| `0x1105` | Party | `005E53D0` | `handlers/Handler_ChatParty_005e53d0.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Chat box + balão 3D |
| `0x1106` | Erro | `005E5470` | `handlers/Handler_ChatError_005e5470.c` | `+0x340` / `0059ABA0` | `vtable/ChatError_vfn_0x340_0059aba0.c` | Chat box (`SysMsg` fixo) |
| `0x1107` | Shout | `005E54A0` | `handlers/Handler_ChatShout_005e54a0.c` | `+0x32C` / `0059AA10` | `vtable/ChatShout_vfn_0x32C_0059aa10.c` | Chat box + balão 3D |
| `0x1108` | Megaphone | `005E5540` | `handlers/Handler_ChatMegaphone_005e5540.c` | `+0x328` case `3` | `vtable/ChatWhisperTradeGuildZoneMega…` | Chat box (`SysMsg`) |
| `0x1109` | Zone | `005E5600` | `handlers/Handler_ChatZone_005e5600.c` | `+0x328` case `4`/`5` | idem | Chat box (`DrawText`) |
| `0x110A` | Union | `005E56F0` | `handlers/Handler_ChatUnion_005e56f0.c` | `+0x34C` / `0059A940` | `vtable/ChatUnion_vfn_0x34C_0059a940.c` | Chat box (`DrawText` + nome) |
| `0x110B` | Canal link | `005E5740` | `handlers/Handler_Chat_110B_005e5740.c` | `+0x350` / `0059A9D0` | `vtable/ChatChannel_vfn_0x350_0059a9d0.c` | Texto → nameplate entidade (`56C650`) |
| `0x1111` | Area (alt) | `005E57D0` | `handlers/Handler_Chat_Area_1111_005e57d0.c` | `+0x330` / `0059A900` | `vtable/ChatArea_vfn_0x330_0059a900.c` | Chat box (`SysMsg` `0x31`) |
| `0x1112` | Texto longo | `005E88D0` | `handlers/Handler_Chat_LongText_1112_005e88d0.c` | `+0x578` / `0059BD00` | `vtable/ChatLongMsg_vfn_0x578_0059bd00.c` | Chat box (`SysMsg`, buf `0x400`) |
| `0xF101` | Party notify | `005E5880` | `handlers/Handler_Chat_PartyNotify_F101_005e5880.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Chat box party (`param_1=1`) |

**VTable compartilhada `+0x328` (`0059BDB0`)** — sub-canal via `param_3`:

| case | Canal | Funções chamadas |
|------|-------|------------------|
| `0` | Whisper | `AppendSuffix` `420C10`, `SysMsg` `423150`, opc. `WhisperHighlight` `47F970` |
| `1` | Trade | `AppendSuffix`, `SysMsg` |
| `2` | Guild | idem |
| `3` | Megaphone | idem |
| `4` | Zone | lookup + `DrawText` `422B90` |
| `5` | Zone (alt) | idem |

---

## 3. VTable do objeto chat (`DAT_022fa2f0`)

| Offset | Símbolo | VA | Arquivo | Usado por (recv) |
|--------|---------|-----|---------|------------------|
| `+0x308` | `AdminChatMonitor_vfn` | `00595570` | `vtable/AdminChatMonitor_vfn_0x308_00595570.c` | `0x0F02` |
| `+0x31C` | `ChatNotify_vfn` | `00595690` | `vtable/ChatNotify_vfn_0x31C_00595690.c` | `0x0E05` |
| `+0x320` | `ChatNotify_vfn` | `005957E0` | `vtable/ChatNotify_vfn_0x320_005957e0.c` | `0x0E06` |
| `+0x324` | `ChatNormalParty_vfn` | `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | `0x1101`, `0x1105`, `0xF101` |
| `+0x328` | `ChatWhisperTradeGuildZoneMega_vfn` | `0059BDB0` | `vtable/ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` | `0x1102`–`0x1104`, `0x1108`, `0x1109` |
| `+0x32C` | `ChatShout_vfn` | `0059AA10` | `vtable/ChatShout_vfn_0x32C_0059aa10.c` | `0x1107` |
| `+0x330` | `ChatArea_vfn` | `0059A900` | `vtable/ChatArea_vfn_0x330_0059a900.c` | `0x1111` |
| `+0x340` | `ChatError_vfn` | `0059ABA0` | `vtable/ChatError_vfn_0x340_0059aba0.c` | `0x1106` |
| `+0x34C` | `ChatUnion_vfn` | `0059A940` | `vtable/ChatUnion_vfn_0x34C_0059a940.c` | `0x110A` |
| `+0x350` | `ChatChannel_vfn` | `0059A9D0` | `vtable/ChatChannel_vfn_0x350_0059a9d0.c` | `0x110B` |
| `+0x578` | `ChatLongMsg_vfn` | `0059BD00` | `vtable/ChatLongMsg_vfn_0x578_0059bd00.c` | `0x1112`, `0xF10A` |
| `+0x680` | `ChatObject_PacketUnderflow` | `00598DC0` | `vtable/ChatObject_PacketUnderflow_vfn680_00598dc0.c` | recv genérico |
| `+0x684` | `ChatObject_GenericPacketHandler` | `00599C30` | `vtable/ChatObject_GenericPacketHandler_vfn684_00599c30.c` | recv genérico |

---

## 4. Envio (cliente → servidor)

| Símbolo | VA | Arquivo | Notas |
|---------|-----|---------|-------|
| `NetworkSend` | `005EA9A0` | `send/NetworkSend_005ea9a0.c` | Wire final (`__cdecl`) |
| `PacketSend_Chat` | `005ED060` | `send/PacketSend_Chat_005ed060.c` | Normal / shout vanilla |
| `PacketSend_Whisper` | `005ED160` | `send/PacketSend_Whisper_005ed160.c` | |
| `PacketSend_Guild` | `005ED220` | `send/PacketSend_Guild_005ed220.c` | |
| `PacketSend_Party` | `005ED2B0` | `send/PacketSend_Party_005ed2b0.c` | |
| `PacketSend_Zone` | `005ED340` | `send/PacketSend_Zone_005ed340.c` | |
| `ChatWindow_FormatOutgoing` | `005663B0` | `send/ChatWindow_FormatOutgoing_005663b0.c` | Monta payload |
| `ChatWindow_SubmitChatInput` | `0047A4B0` | `ui/ChatWindow_SubmitChatInput_0047a4b0.c` | Enter / submit |
| `ChatWindow_BeginSubmit` | `00564B60` | `ui/ChatWindow_BeginSubmit_00564b60.c` | |
| `ChatWindow_ChannelToMsgId` | `0047A420` | `ui/ChatWindow_ChannelToMsgId_0047a420.c` | Tab → msg id |
| `ChatWindow_SetActiveChannel` | `0047C1E0` | `ui/ChatWindow_SetActiveChannel_0047c1e0.c` | |
| `ChatWindow_ApplyChannelPrefix` | `0047C190` | `ui/ChatWindow_ApplyChannelPrefix_0047c190.c` | |
| `NativeChatSendUI` | `0045BBE0` | `ui/NativeChatSendUI_0045bbe0.c` | UI envio alternativa |

---

## 5. Rede e dispatch (recv)

| Símbolo | VA | Arquivo |
|---------|-----|---------|
| `Network_ConnectAndBindWndMsg` | `005DE780` | `init/Network_ConnectAndBindWndMsg_005de780.c` |
| `Network_GameSocketWndProc` | `005F1810` | `recv/Network_GameSocketWndProc_005f1810.c` |
| `PacketPayload_Decrypt` | `00401080` | `recv/PacketPayload_Decrypt_00401080.c` |
| `NetworkRecv_SocketPump` | `005F438E` | `recv/NetworkRecv_SocketPump_005f438e.c` |
| `PacketRecv_AttachBuffer` | `005F4680` | `recv/PacketRecv_AttachBuffer_005f4680.c` |
| `PacketRecv_OnCompleteReset` | `005F46E0` | `recv/PacketRecv_OnCompleteReset_005f46e0.c` |
| `PacketRead_Scalar` | `005F4700` | `recv/PacketRead_Scalar_005f4700.c` |
| `PacketRead_String` | `005F4780` | `recv/PacketRead_String_005f4780.c` |
| `PacketDispatcher` | `005F1E10` | `recv/PacketDispatcher_005f1e10.c` |
| `PacketDispatcher_Fallback` | `005F3A3B` | `recv/PacketDispatcher_Fallback_005f3a3b.c` |

---

## 6. Buffer e formatação de linhas

| Símbolo | VA | Arquivo |
|---------|-----|---------|
| `ChatBox_AddLine` | `00422630` | `buffer/ChatBox_AddLine_00422630.c` |
| `DrawText_ChatBox_Core` | `00422B90` | `ui/DrawText_ChatBox_Core_00422b90.c` |
| `DrawText_ChatBox_Wrapper` | `004231A0` | `ui/DrawText_ChatBox_Wrapper_004231a0.c` |
| `SysMsgToChatBox` | `00423150` | `ui/SysMsgToChatBox_00423150.c` |
| `ChatBox_AppendSuffix` | `00420C10` | `buffer/ChatBox_AppendSuffix_00420c10.c` |
| `ChatBox_FormatLineText` | `00421750` | `buffer/ChatBox_FormatLineText_00421750.c` |
| `ChatBox_WrapLineText` | `00422310` | `buffer/ChatBox_WrapLineText_00422310.c` |
| `ChatBox_BuildDisplaySegment` | `00420A70` | `buffer/ChatBox_BuildDisplaySegment_00420a70.c` |
| `ChatBox_ParseColorCode` | `00407F70` | `buffer/ChatBox_ParseColorCode_00407f70.c` |
| `ChatText_ParseInlineColor` | `0040FDE0` | `util/ChatText_ParseInlineColor_0040fde0.c` |
| `ChatString_Sanitize` | `004126D0` | `util/ChatString_Sanitize_004126d0.c` |
| `GetMsg` | `00420DB0` | `util/GetMsg_00420db0.c` |

---

## 7. Janela de chat (UI + render)

| Símbolo | VA | Arquivo |
|---------|-----|---------|
| `ChatObject_ctor` | `0040A840` | `init/ChatObject_ctor_0040a840.c` |
| `SetChatWindowSingleton` | `005DE770` | `init/SetChatWindowSingleton_005de770.c` |
| `ChatWindow_Render` | `0047DB70` | `ui/ChatWindow_Render_0047db70.c` |
| `ChatWindow_InputCapture` | `0047E8B0` | `ui/ChatWindow_InputCapture_0047e8b0.c` |
| `ChatWindow_SendMessage` | `0047A5F0` | `ui/ChatWindow_SendMessage_0047a5f0.c` |
| `ChatWindow_MainGuiHandler` | `0047FE20` | `ui/ChatWindow_MainGuiHandler_0047fe20.c` |
| `ChatWindow_ToggleOpenLayout` | `0047D203` | `ui/ChatWindow_ToggleOpenLayout_0047d203.c` |
| `ChatWindow_MouseWheelScroll` | `0047BEA0` | `ui/ChatWindow_MouseWheelScroll_0047bea0.c` |
| `ChatWindow_SetWhisperTarget` | `0047C690` | `ui/ChatWindow_SetWhisperTarget_0047c690.c` |
| `ChatWindow_WhisperHighlight` | `0047F970` | `ui/ChatWindow_WhisperHighlight_0047f970.c` |
| `ChatWindow_DrawColoredText` | `00573E20` | `ui/ChatWindow_DrawColoredText_00573e20.c` |
| `ChatWindow_DrawTextStyled` | `00573D70` | `ui/ChatWindow_DrawTextStyled_00573d70.c` |
| `ChatWindow_FormatDrawBuffer` | `00575610` | `ui/ChatWindow_FormatDrawBuffer_00575610.c` |
| `ChatWindow_DrawTabChrome` | `0057B990` | `ui/ChatWindow_DrawTabChrome_0057b990.c` |
| `ChatWindow_DrawChannelLabel` | `00575E90` | `ui/ChatWindow_DrawChannelLabel_00575e90.c` |
| `CGui_DrawRect` | `005388E0` | `gui/CGui_DrawRect_005388e0.c` |
| `CGui_DrawSprite` | `00555690` | `gui/CGui_DrawSprite_00555690.c` |
| `ChatUIFont_Acquire` | `00565430` | `ui/ChatUIFont_Acquire_00565430.c` |
| `ChatUIFont_ImeCompose` | `00565350` | `ui/ChatUIFont_ImeCompose_00565350.c` |

**Hide-native (Paradise)** — landmarks mid-function:

| Site | VA | Arquivo |
|------|-----|---------|
| Gate | `0047DB8D` | `hooks/ChatWindow_Render_GateSite_0047db8d.c` |
| Continue | `0047DB99` | `hooks/ChatWindow_Render_Continue_0047db99.c` |
| Epilogue | `0047E871` | `hooks/ChatWindow_Render_Epilogue_0047e871.c` |

---

## 8. Texto estático e projeção 3D

Usado pelo balão de fala, nameplates e outros overlays.

| Símbolo | VA | Arquivo |
|---------|-----|---------|
| `SStaticText_Create` | `0057C280` | `ui/SStaticText_Create_0057c280.c` |
| `SFloatingStaticText_Draw` | `0057CA20` | `ui/SFloatingStaticText_Draw_0057ca20.c` |
| `NativeText_Draw` | `00573C00` | `ui/NativeText_Draw_00573c00.c` |
| `MeasureTextWidth` | `00575740` | `ui/MeasureTextWidth_00575740.c` |
| `WorldToScreen_ProjectPoint` | `00573FF0` | `render/WorldToScreen_ProjectPoint_00573ff0.c` |
| `ChatString_Sanitize` | `004126D0` | `util/ChatString_Sanitize_004126d0.c` |
| `ChatBalloon_CreateStaticText` | `0041FCC0` | `balloon/ChatBalloon_CreateStaticText_0041fcc0.c` |
| `Entity_ChatBalloon_Tick` | `00412780` | `balloon/Entity_ChatBalloon_Tick_00412780.c` |
| `ChatBalloon_DrawProjected` | `00420010` | `balloon/ChatBalloon_DrawProjected_00420010.c` |
| `Entity_Render_BalloonTick_CallSite` | `00453ED0` | `render/Entity_Render_BalloonTick_CallSite_00453ed0.c` |
| `OptionsMenu_WriteTalkBalloonStrings` | `0051B220` | `ui/OptionsMenu_WriteTalkBalloonStrings_0051b220.c` |

| Campo entidade | Offset | Papel |
|----------------|--------|-------|
| Ponteiro balão | `+0x288` | struct criada em `4126D0` |
| Timer fade | `+0x28C` | decrementado em `412780` |
| Posição mundo | `+0x10` … `+0x18` | usada em `420010` |

---

## 9. Lookup de personagens

| Símbolo | VA | Arquivo |
|---------|-----|---------|
| `CharNameFromId` | `00452B10` | `lookup/CharNameFromId_00452b10.c` |
| `CharNameFromIdAlt` | `00452B90` | `lookup/CharNameFromIdAlt_00452b90.c` |
| `PartyMemberName` | `004ED790` | `lookup/PartyMemberName_004ed790.c` |

---

## 10. Staff / GM

| Símbolo | VA | Arquivo |
|---------|-----|---------|
| `StaffCommand_Dispatch` | `004867A1` | `command/StaffCommand_Dispatch_004867a1.c` |
| `GmCommand_Dispatch` | `0047FFD0` | `command/GmCommand_Dispatch_0047ffd0.c` |
| `GmOverlay_AppendText` | `0047F8B0` | `command/GmOverlay_AppendText_0047f8b0.c` |

---

## Servidor

Pipeline espelho em [`../psgame-chat-native/`](../psgame-chat-native/) · **114** funções · manifesto `psgame-chat-functions.manifest` na pasta do servidor.

Genesis (opcodes `0x930x` / `0x130x`): [`../genesis-chat-v1/README.md`](../genesis-chat-v1/README.md).
