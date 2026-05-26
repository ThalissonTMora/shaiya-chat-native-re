/*
 * Game.exe — Crypto_CounterAdvance
 * Requested VA: 0x00401500
 * Entry Ghidra:  00401500
 * Ghidra name:   FUN_00401500
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


int __fastcall FUN_00401500(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  
  uVar1 = *param_1 * 0x343fd + 0x269ec3 & 0x7fffffff;
  *param_1 = uVar1;
  uVar2 = param_1[1] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[1] = uVar2;
  unaff_ESI[3] = uVar2 / 0xffff << 0x10 | uVar1 / 0xffff;
  uVar1 = param_1[2] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[2] = uVar1;
  uVar2 = param_1[3] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[3] = uVar2;
  unaff_ESI[2] = uVar2 / 0xffff << 0x10 | uVar1 / 0xffff;
  uVar1 = param_1[4] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[4] = uVar1;
  uVar2 = param_1[5] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[5] = uVar2;
  unaff_ESI[1] = uVar2 / 0xffff << 0x10 | uVar1 / 0xffff;
  uVar1 = param_1[6] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[6] = uVar1;
  uVar2 = param_1[7] * 0x343fd + 0x269ec3 & 0x7fffffff;
  param_1[7] = uVar2;
  *unaff_ESI = uVar2 / 0xffff << 0x10 | uVar1 / 0xffff;
  return uVar2 * -0x7fff7fff;
}

