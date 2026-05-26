/*
 * server/ps_login.exe — BigInt_copy
 * Requested VA: 0x004239E0
 * Entry Ghidra:  004239e0
 * Ghidra name:   FUN_004239e0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_004239e0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar5 = iVar1;
  if (iVar1 < 0) {
    iVar5 = -iVar1;
  }
  if (*param_1 < iVar5) {
    FUN_00423dc0(param_1,iVar5);
  }
  puVar3 = (undefined4 *)param_1[2];
  puVar4 = *(undefined4 **)(param_2 + 8);
  if (iVar5 != 0) {
    uVar2 = *puVar4;
    while (iVar5 = iVar5 + -1, iVar5 != 0) {
      puVar4 = puVar4 + 1;
      *puVar3 = uVar2;
      uVar2 = *puVar4;
      puVar3 = puVar3 + 1;
    }
    *puVar3 = uVar2;
  }
  param_1[1] = iVar1;
  return;
}

