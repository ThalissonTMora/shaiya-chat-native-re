/*
 * server/ps_login.exe — BigInt_trialInit
 * Requested VA: 0x00421DD0
 * Entry Ghidra:  00421dd0
 * Ghidra name:   FUN_00421dd0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_00421dd0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = 1;
  uVar1 = (*(code *)PTR_FUN_0044c098)(4);
  param_1[2] = uVar1;
  param_1[1] = 0;
  return;
}

