/*
 * server/ps_game.exe — Chat_BroadcastNamed
 * Requested VA: 0x004D55B0
 * Entry Ghidra:  004d55b0
 * Ghidra name:   FUN_004d55b0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 *
 * Chain (megaphone / 0x1108): see broadcast/Chat_BroadcastNamed_chain.md
 *   -> World_BroadcastTradeCore @ 0x00419240 (CUser+0xDC, 0, view 7)
 *   -> CUser_SendQueueEnqueue mode 3 -> SendQueue_Mode3_ZoneGroup @ 0x00427B20
 */


void FUN_004d55b0(void)

{
  int in_EAX;
  
  FUN_00419240(*(undefined4 *)(in_EAX + 0xdc),0,7);
  return;
}

