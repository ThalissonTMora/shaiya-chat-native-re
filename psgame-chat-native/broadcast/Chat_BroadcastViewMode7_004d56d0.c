/*
 * server/ps_game.exe — Chat_BroadcastViewMode7
 * VA solicitado: 0x004D56D0
 * Entry Ghidra:  004d56d0
 * Ghidra name:   FUN_004d56d0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004d56d0(undefined4 param_1_00,undefined4 param_2_00,undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xe0) != 0) {
    FUN_00427cf0(*(int *)(in_EAX + 0xe0),param_1,param_2,in_EAX + 0xd0,_DAT_00574168,
                 *(undefined4 *)(in_EAX + 0xdc),param_2_00,5);
  }
  return;
}

