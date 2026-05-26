/*
 * Game.exe — ChatChannel_vfn_0x350
 * Requested VA: 0x0059A9D0
 * Entry Ghidra:  0059a9d0
 * Ghidra name:   FUN_0059a9d0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: vtable
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059a9d0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00452b90(param_1);
  if ((iVar1 != 0) && (param_2 != 0)) {
    FUN_0056c650(param_2,iVar1 + 4,_DAT_00746d60,0);
  }
  return;
}

