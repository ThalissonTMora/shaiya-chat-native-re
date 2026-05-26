/*
 * Game.exe — Login_XORStream
 * Requested VA: 0x00401000
 * Entry Ghidra:  00401000
 * Ghidra name:   FUN_00401000
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __fastcall FUN_00401000(byte *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0x80000fff;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffff000) + 1;
  }
  if (0 < (int)param_2) {
    do {
      *param_1 = *param_1 ^ (&DAT_023027e0)[uVar1];
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
      if (0xfff < (int)uVar1) {
        uVar1 = 0;
      }
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}

