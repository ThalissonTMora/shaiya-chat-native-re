/*
 * server/ps_login.exe — BigInt_cmp
 * Requested VA: 0x004236B0
 * Entry Ghidra:  004236b0
 * Ghidra name:   FUN_004236b0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __cdecl FUN_004236b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint auStack_40 [5];
  undefined4 uStack_2c;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  undefined *local_8;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(param_3 + 4);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar3 = iVar1;
  if (iVar1 <= iVar2) {
    iVar3 = iVar2;
  }
  iVar3 = iVar3 + 1;
  if ((iVar1 != 0) && ((iVar2 != 1 || (**(int **)(param_3 + 8) != 1)))) {
    local_1c = iVar3;
    uStack_2c = 0x423709;
    local_10 = iVar3;
    local_14 = (int *)(&stack0xffffffd8 + iVar3 * -4);
    auStack_40[5 - iVar3] = 0x42371d;
    local_8 = &stack0xffffffd8 + iVar3 * -8;
    auStack_40[iVar3 * -2 + 5] = param_3;
    auStack_40[iVar3 * -2 + 4] = param_2;
    auStack_40[iVar3 * -2 + 3] = 0;
    auStack_40[iVar3 * -2 + 2] = (uint)&local_10;
    auStack_40[iVar3 * -2 + 1] = (uint)&local_1c;
    auStack_40[iVar3 * -2] = 0x423736;
    FUN_00427360((int *)auStack_40[iVar3 * -2 + 1],(int *)auStack_40[iVar3 * -2 + 2],
                 (int *)auStack_40[iVar3 * -2 + 3],auStack_40[iVar3 * -2 + 4],
                 auStack_40[iVar3 * -2 + 5]);
    if ((local_18 == 1) && (*local_14 == 1)) {
      if (-1 < local_c) {
        auStack_40[iVar3 * -2 + 5] = (uint)&local_10;
        auStack_40[iVar3 * -2 + 4] = param_1;
        auStack_40[iVar3 * -2 + 3] = 0x4237a3;
        FUN_004239e0((int *)auStack_40[iVar3 * -2 + 4],auStack_40[iVar3 * -2 + 5]);
        return 1;
      }
      iVar1 = *(int *)(param_3 + 4);
      auStack_40[iVar3 * -2 + 5] = param_3;
      if (iVar1 < 0) {
        auStack_40[iVar3 * -2 + 4] = (uint)&local_10;
        auStack_40[iVar3 * -2 + 3] = param_1;
        auStack_40[iVar3 * -2 + 2] = 0x423765;
        FUN_00423510((int *)auStack_40[iVar3 * -2 + 3],auStack_40[iVar3 * -2 + 4],
                     auStack_40[iVar3 * -2 + 5]);
        return 1;
      }
      auStack_40[iVar3 * -2 + 4] = (uint)&local_10;
      auStack_40[iVar3 * -2 + 3] = param_1;
      auStack_40[iVar3 * -2 + 2] = 0x423784;
      FUN_00422770((int *)auStack_40[iVar3 * -2 + 3],auStack_40[iVar3 * -2 + 4],
                   auStack_40[iVar3 * -2 + 5]);
      return 1;
    }
  }
  return 0;
}

