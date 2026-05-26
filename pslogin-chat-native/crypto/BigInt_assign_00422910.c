/*
 * server/ps_login.exe — BigInt_assign
 * Requested VA: 0x00422910
 * Entry Ghidra:  00422910
 * Ghidra name:   FUN_00422910
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_00422910(int *param_1,int param_2)

{
  uint uVar1;
  
  FUN_00423460(param_1,param_2,1);
  uVar1 = FUN_00424d40(param_1,5);
  while (uVar1 == 0) {
    FUN_00423460(param_1,(int)param_1,1);
    uVar1 = FUN_00424d40(param_1,5);
  }
  return;
}

