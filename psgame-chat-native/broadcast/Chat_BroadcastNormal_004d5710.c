/*
 * server/ps_game.exe — Chat_BroadcastNormal
 * Requested VA: 0x004D5710
 * Entry Ghidra:  004d5710
 * Ghidra name:   FUN_004d5710
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d5710(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xe0) != 0) {
    FUN_00427cf0(*(int *)(in_EAX + 0xe0),param_1,param_2,in_EAX + 0xd0,_DAT_00574164,
                 *(undefined4 *)(in_EAX + 0xdc),0,7);
  }
  return;
}

