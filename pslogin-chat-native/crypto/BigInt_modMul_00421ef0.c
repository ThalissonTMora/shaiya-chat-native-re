/*
 * server/ps_login.exe — BigInt_modMul
 * Requested VA: 0x00421EF0
 * Entry Ghidra:  00421ef0
 * Ghidra name:   FUN_00421ef0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __cdecl FUN_00421ef0(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *local_14;
  uint *local_c;
  
  puVar3 = param_3;
  uVar8 = param_3[1];
  uVar5 = param_2[1];
  uVar4 = uVar8 ^ uVar5;
  if ((int)uVar5 < 0) {
    uVar5 = -uVar5;
  }
  if ((int)uVar8 < 0) {
    uVar8 = -uVar8;
  }
  uVar6 = uVar5;
  if ((int)uVar5 < (int)uVar8) {
    param_3 = param_2;
    param_2 = puVar3;
    uVar6 = uVar8;
    uVar8 = uVar5;
  }
  if (uVar8 == 0) {
    param_1[1] = 0;
    return;
  }
  if (uVar8 == 1) {
    if (*param_1 < (int)(uVar6 + 1)) {
      FUN_00423dc0(param_1,uVar6 + 1);
    }
    puVar3 = (uint *)param_1[2];
    uVar8 = FUN_00423d20(puVar3,(uint *)param_2[2],uVar6,*(uint *)param_3[2]);
    puVar3[uVar6] = uVar8;
    iVar7 = uVar6 + (uVar8 != 0);
    if ((int)uVar4 < 0) {
      iVar7 = -iVar7;
    }
    param_1[1] = iVar7;
    return;
  }
  param_2 = (uint *)param_2[2];
  local_14 = (uint *)0x0;
  param_3 = (uint *)param_3[2];
  puVar3 = (uint *)*param_1;
  puVar2 = (uint *)param_1[2];
  if ((int)puVar3 < (int)(uVar8 + uVar6)) {
    if ((puVar2 != param_2) && (puVar2 != param_3)) {
      (*(code *)PTR_FUN_0044c0a0)(puVar2,(int)puVar3 << 2);
      puVar2 = local_14;
      puVar3 = local_c;
    }
    local_c = puVar3;
    local_14 = puVar2;
    *param_1 = uVar8 + uVar6;
    puVar2 = (uint *)(*(code *)PTR_FUN_0044c098)((uVar8 + uVar6) * 4);
    param_1[2] = (int)puVar2;
  }
  else {
    if (puVar2 == param_2) {
      puVar3 = (uint *)&stack0xffffffe0;
      param_2 = (uint *)&stack0xffffffe0;
      if (puVar2 == param_3) {
        param_3 = (uint *)&stack0xffffffe0;
      }
      if (uVar6 == 0) goto LAB_004220a4;
      uVar5 = *puVar2;
      local_c = puVar2;
      uVar1 = uVar6;
      while( true ) {
        uVar1 = uVar1 - 1;
        param_2 = (uint *)&stack0xffffffe0;
        local_c = local_c + 1;
        if (uVar1 == 0) break;
        *puVar3 = uVar5;
        puVar3 = puVar3 + 1;
        uVar5 = *local_c;
      }
    }
    else {
      if (puVar2 != param_3) goto LAB_004220a4;
      param_3 = (uint *)&stack0xffffffe0;
      puVar3 = (uint *)&stack0xffffffe0;
      uVar5 = *puVar2;
      local_c = puVar2;
      uVar1 = uVar8;
      while( true ) {
        uVar1 = uVar1 - 1;
        local_c = local_c + 1;
        if (uVar1 == 0) break;
        *puVar3 = uVar5;
        puVar3 = puVar3 + 1;
        uVar5 = *local_c;
      }
    }
    *puVar3 = uVar5;
  }
LAB_004220a4:
  uVar5 = FUN_00423af0(puVar2,param_2,uVar6,param_3,uVar8);
  iVar7 = (uVar8 - (uVar5 == 0)) + uVar6;
  if ((int)uVar4 < 0) {
    iVar7 = -iVar7;
  }
  param_1[1] = iVar7;
  if (local_14 != (uint *)0x0) {
    (*(code *)PTR_FUN_0044c0a0)(local_14,(int)local_c * 4);
  }
  return;
}

