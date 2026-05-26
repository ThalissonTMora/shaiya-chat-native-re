/*
 * Game.exe — ChatBalloon_CreateStaticText
 * Requested VA: 0x0041FCC0
 * Entry Ghidra:  0041fcc0
 * Ghidra name:   FUN_0041fcc0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: balloon
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined4 * __thiscall FUN_0041fcc0(undefined4 *param_1_00,undefined4 param_1)

{
  undefined4 uVar1;
  
  param_1_00[3] = 0;
  *param_1_00 = CCharacterChat::vftable;
  uVar1 = FUN_0057c280(param_1);
  param_1_00[2] = uVar1;
  return param_1_00;
}

