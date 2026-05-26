/*
 * server/ps_login.exe — BigInt_isZero
 * Requested VA: 0x00421E00
 * Entry Ghidra:  00421e00
 * Ghidra name:   FUN_00421e00
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


int __cdecl FUN_00421e00(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    return -(uint)(param_2 != 0);
  }
  if (iVar1 == 1) {
    if (param_2 < **(uint **)(param_1 + 8)) {
      return 1;
    }
    return -(uint)(**(uint **)(param_1 + 8) < param_2);
  }
  return ((iVar1 < 1) - 1 & 2) - 1;
}

