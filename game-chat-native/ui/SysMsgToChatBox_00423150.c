/*
 * Game.exe — SysMsgToChatBox
 * VA solicitado: 0x00423150
 * Entry Ghidra:  00423150
 * Ghidra name:   FUN_00423150
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00423150(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 2) {
    param_3 = 1;
  }
  iVar1 = FUN_00420db0(param_2);
  if (iVar1 != 0) {
    FUN_00422b90(param_1,&DAT_007c2740 + DAT_007c3b40 * 0x400,param_3);
  }
  return;
}

