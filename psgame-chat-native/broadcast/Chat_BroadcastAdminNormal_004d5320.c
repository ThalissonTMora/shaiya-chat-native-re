/*
 * server/ps_game.exe — Chat_BroadcastAdminNormal
 * VA solicitado: 0x004D5320
 * Entry Ghidra:  004d5320
 * Ghidra name:   FUN_004d5320
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d5320(int param_1_00,undefined4 param_2,undefined4 param_1)

{
  if (*(int *)(param_1_00 + 0x10) != 0) {
    FUN_00427550(*(int *)(param_1_00 + 0x10),param_2,param_1,param_1_00,_DAT_00574164);
  }
  return;
}

