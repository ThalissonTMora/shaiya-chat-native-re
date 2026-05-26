/*
 * Game.exe — ChatUIFont_Acquire
 * Requested VA: 0x00565430
 * Entry Ghidra:  00565430
 * Ghidra name:   FUN_00565430
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined ** __fastcall FUN_00565430(int param_1)

{
  undefined **_Dst;
  int iVar1;
  undefined **ppuVar2;
  
  _Dst = (undefined **)(param_1 + 0x8e9);
  _memset(_Dst,0,0x800);
  iVar1 = FUN_005650f0(_Dst,0x800);
  ppuVar2 = &PTR_00746cf4;
  if (iVar1 != 0) {
    ppuVar2 = _Dst;
  }
  return ppuVar2;
}

