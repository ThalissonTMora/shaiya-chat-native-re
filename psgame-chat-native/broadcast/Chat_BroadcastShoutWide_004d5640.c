/*
 * server/ps_game.exe — Chat_BroadcastShoutWide
 * Requested VA: 0x004D5640
 * Entry Ghidra:  004d5640
 * Ghidra name:   FUN_004d5640
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall
FUN_004d5640(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xe0) != 0) {
    FUN_00427e30(*(int *)(in_EAX + 0xe0),param_3,param_4,in_EAX + 0xd0,param_5,param_6,
                 *(undefined4 *)(in_EAX + 0xdc),param_7,param_2);
  }
  return;
}

