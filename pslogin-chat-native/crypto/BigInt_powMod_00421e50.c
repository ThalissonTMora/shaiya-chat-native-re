/*
 * server/ps_login.exe — BigInt_powMod
 * Requested VA: 0x00421E50
 * Entry Ghidra:  00421e50
 * Ghidra name:   FUN_00421e50
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_00421e50(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_10 [2];
  undefined *local_8;
  
  iVar1 = param_3[1];
  if (param_1 == param_3) {
    local_10[0] = iVar1;
    if (iVar1 < 0) {
      local_10[0] = -iVar1;
    }
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    iVar1 = iVar1 * -4;
    *(int **)(&stack0xffffffe0 + iVar1) = param_3;
    local_8 = &stack0xffffffe4 + iVar1;
    *(int **)(&stack0xffffffdc + iVar1) = local_10;
    *(undefined4 *)(&stack0xffffffd8 + iVar1) = 0x421e93;
    FUN_004239e0(*(int **)(&stack0xffffffdc + iVar1),*(int *)(&stack0xffffffe0 + iVar1));
    param_3 = local_10;
  }
  FUN_00423850(param_1,param_2,(int)param_3);
  if ((param_1[1] != 0) && (param_2[1] < 0)) {
    if (param_3[1] < 0) {
      FUN_00423510(param_1,(uint)param_1,(int)param_3);
      return;
    }
    FUN_00422770(param_1,(uint)param_1,(int)param_3);
  }
  return;
}

