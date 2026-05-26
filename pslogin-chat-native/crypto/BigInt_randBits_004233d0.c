/*
 * server/ps_login.exe — BigInt_randBits
 * Requested VA: 0x004233D0
 * Entry Ghidra:  004233d0
 * Ghidra name:   FUN_004233d0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_004233d0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = param_3 + 0x1f >> 5;
  if (*param_1 < (int)uVar3) {
    FUN_00423dc0(param_1,uVar3);
  }
  iVar1 = param_1[2];
  FUN_00426f90(iVar1,param_2,param_3);
  if (uVar3 != 0) {
    piVar2 = (int *)(iVar1 + -4 + uVar3 * 4);
    do {
      if (*piVar2 != 0) break;
      uVar3 = uVar3 - 1;
      piVar2 = piVar2 + -1;
    } while (0 < (int)uVar3);
  }
  param_1[1] = uVar3;
  return;
}

