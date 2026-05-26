/*
 * Game.exe — CGui_DrawIcon
 * Requested VA: 0x00551B40
 * Entry Ghidra:  00551b40
 * Ghidra name:   FUN_00551b40
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: gui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_00551b40(int param_1_00,int param_1,int param_2)

{
  *(int *)(param_1_00 + 0x38) = param_1;
  *(int *)(param_1_00 + 0x3c) = param_2;
  *(int *)(param_1_00 + 0x18) = *(int *)(param_1_00 + 0x10) + param_1;
  *(int *)(param_1_00 + 0x1c) = *(int *)(param_1_00 + 0x14) + param_2;
  FUN_00550a20();
  return;
}

