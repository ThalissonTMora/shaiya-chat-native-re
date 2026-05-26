/*
 * server/ps_game.exe — Chat_BroadcastShout
 * Requested VA: 0x004D5600
 * Entry Ghidra:  004d5600
 * Ghidra name:   FUN_004d5600
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004d5600(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xe0) != 0) {
    FUN_00427cf0(*(int *)(in_EAX + 0xe0),param_1,param_2,in_EAX + 0xd0,param_3,
                 *(undefined4 *)(in_EAX + 0xdc),0,5);
  }
  return;
}

