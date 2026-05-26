/*
 * Game.exe — ChatWindow_DrawColoredText
 * VA solicitado: 0x00573E20
 * Entry Ghidra:  00573e20
 * Ghidra name:   FUN_00573e20
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall
FUN_00573e20(int param_1_00,undefined4 param_1,undefined4 param_2,undefined4 param_3,
            undefined4 param_4,int param_5)

{
  if ((*(int *)(param_1_00 + 0x3a4) != 0) && (param_5 == 1)) {
    FUN_0057d570((int *)(param_1_00 + 0x3a4),param_4,param_1,param_2,0,0,param_3);
    return;
  }
  FUN_0057d570(param_1_00 + 0x3a8,param_4,param_1,param_2,0,0,param_3);
  return;
}

