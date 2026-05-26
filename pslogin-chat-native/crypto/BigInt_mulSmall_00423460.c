/*
 * server/ps_login.exe — BigInt_mulSmall
 * Requested VA: 0x00423460
 * Entry Ghidra:  00423460
 * Ghidra name:   FUN_00423460
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_00423460(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar5 = iVar1;
  if (iVar1 < 0) {
    iVar5 = -iVar1;
  }
  if (*param_1 < iVar5 + 1) {
    FUN_00423dc0(param_1,iVar5 + 1);
  }
  puVar2 = *(uint **)(param_2 + 8);
  puVar3 = (uint *)param_1[2];
  if (iVar5 == 0) {
    *puVar3 = param_3;
    param_1[1] = (uint)(param_3 != 0);
    return;
  }
  if (-1 < iVar1) {
    uVar4 = FUN_00423eb0(puVar3,puVar2,iVar5,param_3);
    puVar3[iVar5] = uVar4;
    param_1[1] = uVar4 + iVar5;
    return;
  }
  if ((iVar5 == 1) && (*puVar2 < param_3)) {
    *puVar3 = param_3 - *puVar2;
    param_1[1] = 1;
    return;
  }
  FUN_00423e10(puVar3,puVar2,iVar5,param_3);
  param_1[1] = (uint)(puVar3[iVar5 + -1] == 0) - iVar5;
  return;
}

