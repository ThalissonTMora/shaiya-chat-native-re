/*
 * Game.exe — Crypto_PRNGFill
 * Requested VA: 0x00404610
 * Entry Ghidra:  00404610
 * Ghidra name:   FUN_00404610
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00404610(void)

{
  int iVar1;
  uint *in_EAX;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0x20;
  do {
    uVar2 = _DAT_02303a8c * 0x343fd + 0x269ec3 & 0x7fffffff;
    _DAT_02303a8c = uVar2 * 0x343fd + 0x269ec3 & 0x7fffffff;
    iVar1 = _DAT_02303a8c * -0x7fff7fff;
    iVar3 = iVar3 + -1;
    *in_EAX = _DAT_02303a8c / 0xffff << 0x10 | uVar2 / 0xffff;
    in_EAX = in_EAX + 1;
  } while (iVar3 != 0);
  return iVar1;
}

