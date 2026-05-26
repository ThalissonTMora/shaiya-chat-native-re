# Native chat reference — `Game.exe` + `ps_game.exe`

Address tables and decompiled files. Base: `0x00400000` · client MD5 `c1edd96639ad81835624b9c4516ac781`.

**Convention:** client `.c` paths are `game-chat-native/{folder}/…` · server in `psgame-chat-native/`.

## Repository layout

| Folder / file | Contents |
|---------------|----------|
| **`docs/`** | All `.md` specs (this file, `PACKET_SPEC`, `WIRE_CRYPTO`, …) |
| **`game-chat-native/`** | Client `.c` + `game-chat-functions.manifest` |
| **`psgame-chat-native/`** | World server `.c` + `psgame-chat-functions.manifest` |
| **`pslogin-chat-native/`** | Login `0xA101` send path (15 `.c`) |
| **`tools/ghidra/`** | Canonical manifests + decompile scripts |

| Global | VA / value |
|--------|------------|
| Chat singleton | `DAT_022fa2f0` |
| Vtable (`.rdata`) | `0x00747544` |
| Regenerate `.c` | `./tools/ghidra/decompile-game-chat.sh` *(binaries in `bin/`)* |
| Manifest (client) | `game-chat-native/game-chat-functions.manifest` |
| Manifest (server) | `psgame-chat-native/psgame-chat-functions.manifest` |

---

## 1. Flow overview

| Direction | Main steps |
|-----------|------------|
| **Send** | `InputCapture` → `SubmitChatInput` → `PacketSend_*` → `NetworkSend` |
| **Recv** | `GameSocketWndProc` → decrypt → `PacketDispatcher` → handler → vtable → buffer/format → `DrawText` / `SysMsg` → `ChatWindow_Render` |
| **World / entity** | Notify (`0xE05`/`0xE06`), speech balloon (`4126D0`), nameplate (`56C650`), position FX |

---

## 2. Received packets (`0x11xx` and related)

Routing source: `game-chat-native/recv/PacketDispatcher_005f1e10.c` (chat opcodes ~L917; crypto `0xA101` ~L1193).

| Opcode | Channel | Handler `0x…` | Handler file | VTable `+off` / `0x…` | VTable file | Main effect |
|--------|---------|---------------|--------------|----------------------|-------------|-------------|
| `0x0E05` | Notify A | `005E5000` | `handlers/Handler_ChatNotify_E05_005e5000.c` | `+0x31C` / `00595690` | `vtable/ChatNotify_vfn_0x31C_00595690.c` | Entity FX / position (no chat box) |
| `0x0E06` | Notify B | `005E5070` | `handlers/Handler_ChatNotify_E06_005e5070.c` | `+0x320` / `005957E0` | `vtable/ChatNotify_vfn_0x320_005957e0.c` | Entity FX / position (no chat box) |
| `0x0F02` | Admin monitor | `005E4E30` | `handlers/Handler_AdminChatMonitor_005e4e30.c` | `+0x308` / `00595570` | `vtable/AdminChatMonitor_vfn_0x308_00595570.c` | Monitor flag or `SysMsg` |
| `0x0502` | Entity spawn | `005E0CF0` | `handlers/Handler_Packet_0502_005e0cf0.c` | `+0xF0` / `00593970` | `vtable/ChatEntitySpawn_vfn_0xF0_00593970.c` | World entity update (no chat box) |
| `0xA101` | Key material | `005E3D60` | `handlers/Handler_Packet_A101_KeyMaterial_005e3d60.c` | `+0x254` / `005A4D50` | `crypto/Connection_OnKeyMaterial_005a4d50.c` | Crypto handshake (see WIRE_CRYPTO) |
| `0x1101` | Normal | `005E50E0` | `handlers/Handler_ChatNormal_005e50e0.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Chat box + 3D balloon |
| `0x1102` | Whisper | `005E5180` | `handlers/Handler_ChatWhisper_005e5180.c` | `+0x328` case `0` / `0059BDB0` | `vtable/ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` | Chat box + whisper highlight |
| `0x1103` | Trade | `005E5250` | `handlers/Handler_ChatTrade_005e5250.c` | `+0x328` case `1` | same | Chat box (`SysMsg`) |
| `0x1104` | Guild | `005E5310` | `handlers/Handler_ChatGuild_005e5310.c` | `+0x328` case `2` | same | Chat box (`SysMsg`) |
| `0x1105` | Party | `005E53D0` | `handlers/Handler_ChatParty_005e53d0.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Chat box + 3D balloon |
| `0x1106` | Error | `005E5470` | `handlers/Handler_ChatError_005e5470.c` | `+0x340` / `0059ABA0` | `vtable/ChatError_vfn_0x340_0059aba0.c` | Chat box (fixed `SysMsg`) |
| `0x1107` | Shout | `005E54A0` | `handlers/Handler_ChatShout_005e54a0.c` | `+0x32C` / `0059AA10` | `vtable/ChatShout_vfn_0x32C_0059aa10.c` | Chat box + 3D balloon |
| `0x1108` | Megaphone | `005E5540` | `handlers/Handler_ChatMegaphone_005e5540.c` | `+0x328` case `3` | `vtable/ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` | Chat box (`SysMsg`) |
| `0x1109` | Zone | `005E5600` | `handlers/Handler_ChatZone_005e5600.c` | `+0x328` case `4`/`5` | same | Chat box (`DrawText`) |
| `0x110A` | Union | `005E56F0` | `handlers/Handler_ChatUnion_005e56f0.c` | `+0x34C` / `0059A940` | `vtable/ChatUnion_vfn_0x34C_0059a940.c` | Chat box (`DrawText` + name) |
| `0x110B` | Channel link | `005E5740` | `handlers/Handler_Chat_110B_005e5740.c` | `+0x350` / `0059A9D0` | `vtable/ChatChannel_vfn_0x350_0059a9d0.c` | Text → entity nameplate (`56C650`) |
| `0x1111` | Area (alt) | `005E57D0` | `handlers/Handler_Chat_Area_1111_005e57d0.c` | `+0x330` / `0059A900` | `vtable/ChatArea_vfn_0x330_0059a900.c` | Chat box (`SysMsg` `0x31`) |
| `0x1112` | Long text | `005E88D0` | `handlers/Handler_Chat_LongText_1112_005e88d0.c` | `+0x578` / `0059BD00` | `vtable/ChatLongMsg_vfn_0x578_0059bd00.c` | Chat box (`SysMsg`, buf `0x400`) |
| `0xF101` | Party notify | `005E5880` | `handlers/Handler_Chat_PartyNotify_F101_005e5880.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Party chat box (`param_1=1`) |
| `0xF102` | Admin whisper | `005E5920` | `handlers/Handler_Chat_Admin_F102_005e5920.c` | `+0x328` / `0059BDB0` | `vtable/ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` | Pattern **C** · vfn `(dir,1,0,name,len,text)` · SysMsg `0x162` / highlight |
| `0xF103` | Admin trade/shout | `005E59F0` | `handlers/Handler_Chat_Admin_F103_005e59f0.c` | `+0x328` case `1` | same | Pattern **B** · vfn `(0,1,1,…)` · SysMsg `0x163` |
| `0xF104` | Admin guild | `005E5AB0` | `handlers/Handler_Chat_Admin_F104_005e5ab0.c` | `+0x328` case `2` | same | Pattern **B** · vfn `(0,1,2,…)` · SysMsg `0x172` |
| `0xF105` | Admin party | `005E5B70` | `handlers/Handler_Chat_Admin_F105_005e5b70.c` | `+0x324` / `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | Pattern **A** · vfn `(1,1,id,len,text)` · party SysMsg |
| `0xF106` | Admin long/sys | `005E5C10` | `handlers/Handler_Chat_Admin_F106_005e5c10.c` | `+0x334` / `0059ABC0` | `vtable/ChatAdminLong_vfn_0x334_0059abc0.c` | `u16le len` · text (max **0x7D0**) · SysMsg `0x164` · optional `EVENTMSG-` prefix |
| `0xF107` | Whisper target set | `005DE950` | `handlers/Handler_Chat_Admin_F107_005de950.c` | `+0x344` / `0056BCB0` | `vtable/ChatWhisperTarget_vfn_0x344_0056bcb0.c` | `char[21]` only · **vfn stub (no-op)** on client |
| `0xF109` | Whisper target clear | `005DE9B0` | `handlers/Handler_Chat_Admin_F109_005de9b0.c` | `+0x348` / `0056BCB0` | same (alias slot) | `char[21]` only · **vfn stub (no-op)** on client |
| `0xF10A` | Admin long | `005E88D0` | `handlers/Handler_Chat_LongText_1112_005e88d0.c` | `+0x578` | `ChatLongMsg_vfn` | Same handler as `0x1112` |

**Shared vtable `+0x328` (`0059BDB0`)** — sub-channel via `param_3`:

| case | Channel | Called functions |
|------|---------|------------------|
| `0` | Whisper | `AppendSuffix` `420C10`, `SysMsg` `423150`, opt. `WhisperHighlight` `47F970` |
| `1` | Trade | `AppendSuffix`, `SysMsg` |
| `2` | Guild | same |
| `3` | Megaphone | same |
| `4` | Zone | lookup + `DrawText` `422B90` |
| `5` | Zone (alt) | same |

**Admin recv wire (`0xF102`–`0xF109`)** — evidence: `game-chat-native/handlers/Handler_Chat_Admin_F*.c`

| Opcode | Mirror | Payload (after opcode) | Handler read sequence |
|--------|--------|--------------------------|------------------------|
| `0xF102` | `0x1102` | **C** `u8 dir` · `char[21]` · `u8 len` · `text[len]` | `Scalar×1` · `String 0x15` · `Scalar×1` · `String len` |
| `0xF103` | `0x1103` | **B** `char[21]` · `u8 len` · `text[len]` | `String 0x15` · `Scalar×1` · `String len` |
| `0xF104` | `0x1104` | **B** (same) | same |
| `0xF105` | `0x1105` / `0xF101` | **A** `u32 id` · `u8 len` · `text[len]` | `Scalar×4` · `Scalar×1` · `String len` |
| `0xF106` | *(unique)* | `u16le len` · `text[len]` (buf **0x7D0**) | `Scalar×2` · `String (len&0xFFFF)` |
| `0xF107` | server whisper bind | `char[21]` | `String 0x15` only |
| `0xF109` | server whisper clear | `char[21]` | `String 0x15` only |

`0xF108` — **not routed** in client `PacketDispatcher` @ `0x005F1E10` (server-only relay in `AdminChat_ProcessIncoming`).

---

## 3. Chat object vtable (`DAT_022fa2f0`)

| Offset | Symbol | VA | File | Used by (recv) |
|--------|--------|-----|------|----------------|
| `+0xF0` | `ChatEntitySpawn_vfn` | `00593970` | `vtable/ChatEntitySpawn_vfn_0xF0_00593970.c` | `0x0502` |
| `+0x308` | `AdminChatMonitor_vfn` | `00595570` | `vtable/AdminChatMonitor_vfn_0x308_00595570.c` | `0x0F02` |
| `+0x31C` | `ChatNotify_vfn` | `00595690` | `vtable/ChatNotify_vfn_0x31C_00595690.c` | `0x0E05` |
| `+0x320` | `ChatNotify_vfn` | `005957E0` | `vtable/ChatNotify_vfn_0x320_005957e0.c` | `0x0E06` |
| `+0x324` | `ChatNormalParty_vfn` | `0059C380` | `vtable/ChatNormalParty_vfn_0x324_0059c380.c` | `0x1101`, `0x1105`, `0xF101` |
| `+0x328` | `ChatWhisperTradeGuildZoneMega_vfn` | `0059BDB0` | `vtable/ChatWhisperTradeGuildZoneMega_vfn_0x328_0059bdb0.c` | `0x1102`–`0x1104`, `0x1108`, `0x1109` |
| `+0x32C` | `ChatShout_vfn` | `0059AA10` | `vtable/ChatShout_vfn_0x32C_0059aa10.c` | `0x1107` |
| `+0x330` | `ChatArea_vfn` | `0059A900` | `vtable/ChatArea_vfn_0x330_0059a900.c` | `0x1111` |
| `+0x334` | `ChatAdminLong_vfn` | `0059ABC0` | `vtable/ChatAdminLong_vfn_0x334_0059abc0.c` | `0xF106` |
| `+0x340` | `ChatError_vfn` | `0059ABA0` | `vtable/ChatError_vfn_0x340_0059aba0.c` | `0x1106` |
| `+0x344` | `ChatWhisperTarget_vfn` | `0056BCB0` | `vtable/ChatWhisperTarget_vfn_0x344_0056bcb0.c` | `0xF107` *(stub)* |
| `+0x348` | `ChatWhisperTarget_vfn` *(alias)* | `0056BCB0` | same | `0xF109` *(stub)* |
| `+0x34C` | `ChatUnion_vfn` | `0059A940` | `vtable/ChatUnion_vfn_0x34C_0059a940.c` | `0x110A` |
| `+0x350` | `ChatChannel_vfn` | `0059A9D0` | `vtable/ChatChannel_vfn_0x350_0059a9d0.c` | `0x110B` |
| `+0x578` | `ChatLongMsg_vfn` | `0059BD00` | `vtable/ChatLongMsg_vfn_0x578_0059bd00.c` | `0x1112`, `0xF10A` |
| `+0x254` | `Connection_OnKeyMaterial_vfn` | `005A4D50` | `crypto/Connection_OnKeyMaterial_005a4d50.c` | `0xA101` key blob |
| `+0x680` | `ChatObject_PacketUnderflow` | `00598DC0` | `vtable/ChatObject_PacketUnderflow_vfn680_00598dc0.c` | generic recv |
| `+0x684` | `ChatObject_GenericPacketHandler` | `00599C30` | `vtable/ChatObject_GenericPacketHandler_vfn684_00599c30.c` | generic recv |

---

## 4. Send (client → server)

| Symbol | VA | File | Notes |
|--------|-----|------|-------|
| `NetworkSend` | `005EA9A0` | `send/NetworkSend_005ea9a0.c` | Final wire (`__cdecl`) |
| `PacketSend_Chat` | `005ED060` | `send/PacketSend_Chat_005ed060.c` | Normal / shout vanilla |
| `PacketSend_Whisper` | `005ED160` | `send/PacketSend_Whisper_005ed160.c` | |
| `PacketSend_Guild` | `005ED220` | `send/PacketSend_Guild_005ed220.c` | |
| `PacketSend_Party` | `005ED2B0` | `send/PacketSend_Party_005ed2b0.c` | |
| `PacketSend_Zone` | `005ED340` | `send/PacketSend_Zone_005ed340.c` | |
| `ChatWindow_FormatOutgoing` | `005663B0` | `send/ChatWindow_FormatOutgoing_005663b0.c` | Builds payload |
| `ChatWindow_SubmitChatInput` | `0047A4B0` | `ui/ChatWindow_SubmitChatInput_0047a4b0.c` | Enter / submit |
| `ChatWindow_BeginSubmit` | `00564B60` | `ui/ChatWindow_BeginSubmit_00564b60.c` | |
| `ChatWindow_ChannelToMsgId` | `0047A420` | `ui/ChatWindow_ChannelToMsgId_0047a420.c` | Tab → msg id |
| `ChatWindow_SetActiveChannel` | `0047C1E0` | `ui/ChatWindow_SetActiveChannel_0047c1e0.c` | |
| `ChatWindow_ApplyChannelPrefix` | `0047C190` | `ui/ChatWindow_ApplyChannelPrefix_0047c190.c` | |
| `NativeChatSendUI` | `0045BBE0` | `ui/NativeChatSendUI_0045bbe0.c` | World FX / 3D effect queue (**not** `PacketSend_*`) |

---

## 5. Network and dispatch (recv)

| Symbol | VA | File |
|--------|-----|------|
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

Wire crypto: see [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md) and `game-chat-native/crypto/`.

---

## 6. Buffer and line formatting

| Symbol | VA | File |
|--------|-----|------|
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

## 7. Chat window (UI + render)

| Symbol | VA | File |
|--------|-----|------|
| `ChatObject_ctor` | `0040A840` | `init/ChatObject_ctor_0040a840.c` |
| `SetChatWindowSingleton` | `005DE770` | `init/SetChatWindowSingleton_005de770.c` |
| `ChatWindow_Render` | `0047DB70` | `ui/ChatWindow_Render_0047db70.c` |
| `ChatWindow_InputCapture` | `0047E8B0` | `ui/ChatWindow_InputCapture_0047e8b0.c` |
| `ChatWindow_SendMessage` | `0047A5F0` | `ui/ChatWindow_SendMessage_0047a5f0.c` |
| `ChatWindow_MainGuiHandler` | `0047FE20` | `ui/ChatWindow_MainGuiHandler_0047fe20.c` |
| `ChatWindow_ToggleOpenLayout` | `0047D1F0` | `ui/ChatWindow_ToggleOpenLayout_0047d1f0.c` |
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

**Hide-native UI hooks** — mid-function landmarks:

| Site | VA | File |
|------|-----|------|
| Gate | `0047DB8D` | `hooks/ChatWindow_Render_GateSite_0047db8d.c` |
| Continue | `0047DB99` | `hooks/ChatWindow_Render_Continue_0047db99.c` |
| Epilogue | `0047E871` | `hooks/ChatWindow_Render_Epilogue_0047e871.c` |

---

## 8. Static text and 3D projection

Used by speech balloon, nameplates, and other overlays.

| Symbol | VA | File |
|--------|-----|------|
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

| Entity field | Offset | Role |
|--------------|--------|------|
| Balloon pointer | `+0x288` | struct created in `4126D0` |
| Fade timer | `+0x28C` | decremented in `412780` |
| World position | `+0x10` … `+0x18` | used in `420010` |

---

## 9. Character lookup

| Symbol | VA | File |
|--------|-----|------|
| `CharNameFromId` | `00452B10` | `lookup/CharNameFromId_00452b10.c` |
| `CharNameFromIdAlt` | `00452B90` | `lookup/CharNameFromIdAlt_00452b90.c` |
| `PartyMemberName` | `004ED790` | `lookup/PartyMemberName_004ed790.c` |

---

## 10. Staff / GM

| Symbol | VA | File |
|--------|-----|------|
| `StaffCommand_Dispatch` | `004867A1` | `command/StaffCommand_Dispatch_004867a1.c` |
| `GmCommand_Dispatch` | `0047FFD0` | `command/GmCommand_Dispatch_0047ffd0.c` |
| `GmOverlay_AppendText` | `0047F8B0` | `command/GmOverlay_AppendText_0047f8b0.c` |

---

## Server

Mirror pipeline in [`psgame-chat-native/`](psgame-chat-native/README.md) · manifest `psgame-chat-native/psgame-chat-functions.manifest`. Wire crypto: [`WIRE_CRYPTO.md`](WIRE_CRYPTO.md).

**Outbound `0x1109`–`0x110B` builders** (server → client push only; client sending these → kick @ `Chat_ProcessIncoming` `0x0047FC24`):

Regenerate: `./tools/ghidra/decompile-psgame-chat.sh` (or subset `tools/ghidra/psgame-chat-send-builders.manifest`).

| Opcode | Pattern | Builder entry | `.c` file | Wire (after opcode) | Plain size |
|--------|---------|---------------|-----------|---------------------|------------|
| `0x1109` | D | `0x004C6A80` | `send/Chat_PacketBuilder_1109_A_004c6a80.c` | `u8 flag=0` · `u32 charId` · `u8 len` · `text[len]` | `len+8` |
| `0x1109` | D | `0x004C6F50` | `send/Chat_PacketBuilder_1109_B_004c6f50.c` | `u8 flag=1` · `u32 charId` · `u8 len` · `text[len]` | `len+8` |
| `0x110A` | E | `0x004C8310` | `send/Chat_PacketBuilder_110A_004c8310.c` | `u32 charId` · `u16 message_id` | **8** |
| `0x110B` | G | `0x004C8520` *(landmark `0x004C8539`)* | `send/Chat_PacketBuilder_110B_004c8539.c` | `u32 entity` · `char[32] label` | **0x26** |

### Builder call path (S→C)

```
script/NPC dispatch @ 0x004A2210 ──call──► Chat_PacketBuilder_1109_A @ 0x004C6A80 ──► CParty_BroadcastPacket @ 0x0044E950 | SConnection_Send @ 0x004ED0E0
script/NPC dispatch @ 0x004A2210 ──call──► Chat_PacketBuilder_1109_B @ 0x004C6F50 ──► cell loop (0x124 stride) ──► SConnection_Send (per viewer in radius)
script wrapper     @ 0x004CB3D0 ──call──► Chat_PacketBuilder_110A @ 0x004C8310 ──► cell loop ──► SConnection_Send(..., 8)
script wrapper     @ 0x004CB430 ──call──► Chat_PacketBuilder_110B @ 0x004C8520 ──► cell loop ──► SConnection_Send(..., 0x26)
         │                              │
         └─ Zone_FloorWorldToCellIndex @ 0x005250C0
            Math_DistanceRadiusCompare @ 0x0041B8A0
            SConnection_EnqueueWrite   @ 0x004EF080 (via SConnection_Send)
```

### Client recv cross-check

| Opcode | Client handler | Client vtable | Server builder |
|--------|----------------|---------------|----------------|
| `0x1109` | `Handler_ChatZone` `0x005E5600` | `+0x328` case `4`/`5` @ `0x0059BDB0` | 1109_A / 1109_B |
| `0x110A` | `Handler_ChatUnion` `0x005E56F0` | `+0x34C` @ `0x0059A940` (`GetMsg` + `DrawText`) | 110A |
| `0x110B` | `Handler_Chat_110B` `0x005E5740` | `+0x350` @ `0x0059A9D0` → nameplate `0x0056C650` | 110B |

### Field notes

| Field | Evidence | Notes |
|-------|----------|-------|
| `charId` / `entity` | `*(CUser+0x88)` in all four builders | Same offset; 110B uses it as entity id for nameplate |
| `flag` (1109) | `movb $0x0` @ `0x4C6AEB` · `movb $0x1` @ `0x4C6F59` | **CONFIRMED** — selects party vs spatial path |
| Text `len` (1109) | `len - 1U < 0x7f` in both builders | **1..0x7F** (stricter than player chat inbound 2..128) |
| `message_id` (110A) | `local_a = param_2`; caller ORs `0xC00` @ `0x4CB402` | **INFERRED** — string-table index base |
| `label[32]` (110B) | `_strncpy(..., 0x20)` + NUL; send `0x26` | **CONFIRMED** — fixed 32 B on wire (client reads `0x20`) |
