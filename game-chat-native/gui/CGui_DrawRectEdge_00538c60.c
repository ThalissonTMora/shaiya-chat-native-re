/*
 * Game.exe — CGui_DrawRectEdge
 * Requested VA: 0x00538C60
 * Entry Ghidra:  00538c60
 * Ghidra name:   FUN_00538c60
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: gui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00538c60(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    FUN_0057b990(0xffffffff,param_2,param_3,4,4,0,_DAT_0074815c,_DAT_00748160,_DAT_00748164);
    return;
  }
  FUN_0057b990(0xffffffff,param_2,param_3,4,4,_DAT_0074815c,_DAT_00748160,_DAT_00748160,
               _DAT_00748164);
  return;
}

