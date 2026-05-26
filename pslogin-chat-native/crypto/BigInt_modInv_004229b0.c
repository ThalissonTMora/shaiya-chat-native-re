/*
 * server/ps_login.exe — BigInt_modInv
 * Requested VA: 0x004229B0
 * Entry Ghidra:  004229b0
 * Ghidra name:   FUN_004229b0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_004229b0(int *param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined *puVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  byte bVar10;
  uint *puVar11;
  uint *puVar12;
  byte *pbVar13;
  uint *puVar14;
  undefined4 *puVar15;
  int *piVar16;
  int *piVar17;
  int iVar18;
  uint uVar19;
  int local_48 [2];
  undefined *local_40;
  int local_3c;
  int local_38;
  byte *local_34;
  uint *local_30;
  uint *local_2c;
  uint *local_28;
  uint *local_24;
  int local_20;
  uint local_1c;
  int local_18;
  uint *local_14;
  undefined *local_10;
  int local_c;
  uint *local_8;
  
  iVar18 = *(int *)(param_4 + 4);
  local_8 = *(uint **)(param_4 + 8);
  if (iVar18 < 0) {
    iVar18 = -iVar18;
  }
  if (iVar18 == 0) {
    FUN_00426ed0();
  }
  uVar19 = *(uint *)(param_3 + 4);
  local_1c = uVar19;
  if ((int)uVar19 < 1) {
    if (uVar19 == 0) {
      if ((iVar18 == 1) && (*local_8 == 1)) {
        param_1[1] = 0;
        *(undefined4 *)param_1[2] = 1;
        return;
      }
      param_1[1] = 1;
      *(undefined4 *)param_1[2] = 1;
      return;
    }
    iVar6 = iVar18 + 1;
    local_48[0] = iVar6;
    iVar2 = iVar6 * -4;
    *(int *)(&stack0xffffffa8 + iVar2) = param_4;
    *(int **)(&stack0xffffffa4 + iVar2) = param_2;
    *(int **)(&stack0xffffffa0 + iVar2) = local_48;
    local_40 = &stack0xffffffac;
    local_48[-7 - iVar6] = 0x422a4e;
    iVar6 = FUN_004236b0(*(undefined4 *)(&stack0xffffffa0 + iVar2),
                         *(int *)(&stack0xffffffa4 + iVar2),*(int *)(&stack0xffffffa8 + iVar2));
    if (iVar6 == 0) {
      *(undefined4 *)(&stack0xffffffa8 + iVar2) = 0x422a5a;
      FUN_00426ed0();
    }
    param_2 = local_48;
    uVar19 = -uVar19;
  }
  local_1c = uVar19;
  if ((iVar18 < 0x7d) && (uVar19 = *local_8, (uVar19 & 1) != 0)) {
    local_c = 1;
    iVar6 = (2 - (byte)(&DAT_004415b4)[uVar19 >> 1 & 0x7f] * uVar19) *
            (uint)(byte)(&DAT_004415b4)[uVar19 >> 1 & 0x7f];
    local_20 = -((2 - iVar6 * uVar19) * iVar6);
  }
  else {
    local_c = 0;
    uVar19 = local_8[iVar18 + -1];
    if (uVar19 < 0x10000) {
      local_20 = (-(uint)(uVar19 < 0x100) & 0xfffffff8) + 9;
    }
    else {
      local_20 = (-(uint)(uVar19 < 0x1000000) & 0xfffffff8) + 0x19;
    }
    local_20 = (0x21 - (uint)(byte)(&DAT_00441534)[uVar19 >> ((byte)local_20 & 0x1f)]) - local_20;
    if (local_20 != 0) {
      FUN_00423f40((int)&stack0xffffffac,(int)local_8,iVar18,(byte)local_20);
      local_8 = (uint *)&stack0xffffffac;
    }
  }
  uVar19 = *(uint *)(*(int *)(param_3 + 8) + -4 + local_1c * 4);
  if (uVar19 < 0x10000) {
    local_38 = (-(uint)(uVar19 < 0x100) & 0xfffffff8) + 9;
  }
  else {
    local_38 = (-(uint)(uVar19 < 0x1000000) & 0xfffffff8) + 0x19;
  }
  iVar6 = 2;
  local_38 = (0x21 - (uint)(byte)(&DAT_00441534)[uVar19 >> ((byte)local_38 & 0x1f)]) - local_38;
  uVar19 = (local_1c * 0x20 - local_38) * 2;
  local_2c = (uint *)0x1;
  puVar7 = (uint *)0x1;
  if (0xc < uVar19) {
    do {
      local_2c = (uint *)((int)puVar7 + 1);
      iVar6 = iVar6 * 2;
      puVar12 = puVar7 + 1;
      puVar7 = local_2c;
    } while ((uint)(((int)puVar12 * (int)local_2c + 2) * iVar6) < uVar19);
  }
  iVar2 = -(iVar18 * 8 + 4);
  puVar15 = (undefined4 *)(&stack0xffffffac + iVar2);
  puVar8 = (undefined4 *)(&stack0xffffffac + iVar2);
  puVar7 = (uint *)(&stack0xffffffac + iVar2);
  *(undefined4 *)(&stack0xffffffa8 + iVar2) = 0x422bbf;
  iVar3 = -(iVar18 * 4 + 4);
  local_10 = &stack0xffffffac + iVar3 + iVar2;
  local_18 = iVar6 / 2;
  iVar6 = local_18 * iVar18 * 4;
  *(int *)(&stack0xffffffa8 + iVar3 + iVar2) = iVar6;
  piVar16 = (int *)(&stack0xffffffa4 + iVar3 + iVar2);
  local_3c = iVar6;
  *(undefined4 *)(&stack0xffffffa4 + iVar3 + iVar2) = 0x422bdc;
  local_14 = (uint *)(*(code *)PTR_FUN_0044c098)();
  puVar12 = local_8;
  local_24 = (uint *)param_2[1];
  if ((int)local_24 < 0) {
    local_24 = (uint *)-(int)local_24;
  }
  else {
  }
  puVar14 = (uint *)param_2[2];
  if (iVar18 < (int)local_24) {
LAB_00422ce6:
    iVar6 = local_c;
    *piVar16 = iVar18;
    puVar11 = local_14;
    puVar12 = local_24;
    if (iVar6 == 0) {
      piVar16[-1] = (int)local_8;
      piVar16[-2] = (int)puVar12;
      piVar16[-3] = (int)puVar14;
      piVar16[-4] = (int)puVar11;
      piVar16[-5] = 0x422d47;
      FUN_00423380(piVar16[-4],piVar16[-3],piVar16[-2],piVar16[-1],*piVar16);
    }
    else {
      piVar16[-1] = (int)local_8;
      piVar16[-2] = (int)puVar12;
      piVar16[-3] = (int)puVar14;
      piVar16[-4] = (int)(&stack0xffffffac + iVar18 * 4 + iVar2);
      piVar16[-5] = 0x422d00;
      FUN_00423380(piVar16[-4],piVar16[-3],piVar16[-2],piVar16[-1],*piVar16);
      puVar12 = local_14;
      puVar14 = local_8;
      for (iVar6 = iVar18; local_14 = puVar12, local_8 = puVar14, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
        puVar12 = local_14;
        puVar14 = local_8;
      }
      *piVar16 = iVar18;
      piVar16[-1] = (int)puVar14;
      puVar5 = local_10;
      piVar16[-2] = iVar18 * 2;
      piVar16[-3] = (int)(&stack0xffffffac + iVar2);
      piVar16[-4] = 0;
      piVar16[-5] = (int)puVar12;
      piVar16[-6] = (int)puVar5;
      piVar16[-7] = 0x422d30;
      FUN_00426570((uint *)piVar16[-6],(uint *)piVar16[-5],(uint *)piVar16[-4],(uint *)piVar16[-3],
                   piVar16[-2],(uint *)piVar16[-1],(uint *)*piVar16);
    }
  }
  else {
    if (local_24 == (uint *)iVar18) {
      *piVar16 = iVar18;
      piVar16[-1] = (int)puVar12;
      piVar16[-2] = (int)puVar14;
      piVar16[-3] = 0x422c11;
      iVar6 = FUN_00424c80(piVar16[-2],piVar16[-1],*piVar16);
      if (-1 < iVar6) goto LAB_00422ce6;
    }
    puVar12 = local_24;
    iVar6 = iVar18;
    if (local_c == 0) {
      if (local_24 != (uint *)0x0) {
        uVar19 = *puVar14;
        local_34 = (byte *)((int)local_24 + -1);
        local_30 = puVar14;
        puVar12 = local_14;
        while (local_34 != (byte *)0x0) {
          local_30 = local_30 + 1;
          *puVar12 = uVar19;
          puVar12 = puVar12 + 1;
          uVar19 = *local_30;
          local_34 = (byte *)((int)local_34 + -1);
        }
        *puVar12 = uVar19;
        local_34 = (byte *)0x0;
      }
      iVar6 = iVar18 - (int)local_24;
      if (iVar6 != 0) {
        puVar12 = local_14 + (int)local_24;
        do {
          *puVar12 = 0;
          puVar12 = puVar12 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    else {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      if (puVar12 != (uint *)0x0) {
        uVar19 = *puVar14;
        puVar11 = (uint *)(&stack0xffffffac + iVar18 * 4 + iVar2);
        puVar4 = puVar12;
        while (puVar12 = local_24, puVar4 = (uint *)((int)puVar4 + -1), local_24 = puVar12,
              puVar4 != (uint *)0x0) {
          puVar14 = puVar14 + 1;
          *puVar11 = uVar19;
          uVar19 = *puVar14;
          puVar11 = puVar11 + 1;
        }
        *puVar11 = uVar19;
      }
      iVar6 = iVar18 - (int)puVar12;
      if (iVar6 != 0) {
        puVar8 = (undefined4 *)(&stack0xffffffac + ((int)puVar12 + iVar18) * 4 + iVar2);
        do {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      puVar14 = local_8;
      puVar12 = local_14;
      *piVar16 = iVar18;
      piVar16[-1] = (int)puVar14;
      puVar5 = local_10;
      piVar16[-2] = iVar18 * 2;
      piVar16[-3] = (int)(&stack0xffffffac + iVar2);
      piVar16[-4] = 0;
      piVar16[-5] = (int)puVar12;
      piVar16[-6] = (int)puVar5;
      piVar16[-7] = 0x422c8d;
      FUN_00426570((uint *)piVar16[-6],(uint *)piVar16[-5],(uint *)piVar16[-4],(uint *)piVar16[-3],
                   piVar16[-2],(uint *)piVar16[-1],(uint *)*piVar16);
    }
  }
  local_30 = (uint *)(iVar18 * 4);
  *piVar16 = 0x422d5e;
  puVar14 = local_14;
  puVar12 = (uint *)(piVar16 + (1 - iVar18));
  piVar17 = piVar16 + (1 - iVar18);
  piVar16[-iVar18] = iVar18;
  piVar16[-1 - iVar18] = (int)puVar14;
  piVar16[-2 - iVar18] = (int)(&stack0xffffffac + iVar2);
  piVar16[-3 - iVar18] = 0x422d6b;
  FUN_00423a30((uint *)piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
  puVar14 = local_8;
  puVar5 = local_10;
  iVar6 = local_20;
  if (local_c == 0) {
    piVar16[-iVar18] = iVar18;
    piVar16[-1 - iVar18] = (int)puVar14;
    piVar16[-2 - iVar18] = iVar18 * 2;
    piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
    piVar16[-4 - iVar18] = 0;
    piVar16[-5 - iVar18] = (int)(piVar16 + (1 - iVar18));
    piVar16[-6 - iVar18] = (int)puVar5;
    piVar16[-7 - iVar18] = 0x422da0;
    FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                 (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                 (uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
  }
  else {
    piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
    piVar16[-1 - iVar18] = iVar6;
    piVar16[-2 - iVar18] = iVar18;
    piVar16[-3 - iVar18] = (int)puVar14;
    piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
    piVar16[-5 - iVar18] = 0x422d85;
    FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                 piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
  }
  local_28 = local_14;
  if (1 < local_18) {
    local_34 = (byte *)(local_18 + -1);
    do {
      puVar14 = local_28;
      piVar16[-iVar18] = iVar18;
      piVar16[-1 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-2 - iVar18] = (int)puVar14;
      piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
      piVar16[-4 - iVar18] = 0x422dc1;
      FUN_00426480((uint *)piVar16[-3 - iVar18],(uint *)piVar16[-2 - iVar18],
                   (uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
      puVar14 = local_8;
      iVar6 = local_20;
      puVar11 = (uint *)((int)local_28 + (int)local_30);
      local_28 = puVar11;
      if (local_c == 0) {
        piVar16[-iVar18] = iVar18;
        piVar16[-1 - iVar18] = (int)puVar14;
        puVar5 = local_10;
        piVar16[-2 - iVar18] = iVar18 * 2;
        piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-4 - iVar18] = 0;
        piVar16[-5 - iVar18] = (int)puVar11;
        piVar16[-6 - iVar18] = (int)puVar5;
        piVar16[-7 - iVar18] = 0x422e07;
        FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                     (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                     (uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
      }
      else {
        piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-1 - iVar18] = iVar6;
        piVar16[-2 - iVar18] = iVar18;
        piVar16[-3 - iVar18] = (int)puVar14;
        piVar16[-4 - iVar18] = (int)puVar11;
        piVar16[-5 - iVar18] = 0x422de9;
        FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                     piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
      }
      local_34 = (byte *)((int)local_34 + -1);
    } while (local_34 != (byte *)0x0);
  }
  local_18 = local_1c - 1;
  local_34 = *(byte **)(param_3 + 8);
  uVar19 = *(uint *)(local_34 + local_18 * 4);
  param_3 = (0x20 - (int)local_2c) - local_38;
  bVar10 = (byte)param_3;
  if (param_3 < 0) {
    if (0 < local_18) {
      local_18 = local_1c - 2;
      param_3 = param_3 + 0x20;
      uVar19 = uVar19 << (-bVar10 & 0x1f) |
               *(uint *)(local_34 + (local_1c - 2) * 4) >> ((byte)param_3 & 0x1f);
    }
  }
  else {
    uVar19 = uVar19 >> (bVar10 & 0x1f);
  }
  puVar14 = (uint *)0x0;
  local_24 = (uint *)0x0;
  if ((uVar19 & 1) == 0) {
    do {
      uVar19 = uVar19 >> 1;
      puVar14 = (uint *)((int)puVar14 + 1);
    } while ((uVar19 & 1) == 0);
    local_24 = puVar14;
  }
  puVar14 = local_24;
  if (iVar18 != 0) {
    local_28 = (uint *)(iVar18 + -1);
    puVar11 = local_14 + (uVar19 >> 1) * iVar18;
    local_1c = *puVar11;
    puVar4 = (uint *)(piVar16 + (1 - iVar18));
    while (local_24 = puVar14, local_28 != (uint *)0x0) {
      puVar11 = puVar11 + 1;
      *puVar12 = local_1c;
      local_1c = *puVar11;
      puVar12 = puVar12 + 1;
      local_28 = (uint *)((int)local_28 + -1);
      puVar14 = local_24;
      puVar4 = puVar12;
    }
    *puVar4 = local_1c;
  }
  if (-1 < (int)((int)puVar14 + -1)) {
    local_28 = puVar14;
    do {
      piVar16[-iVar18] = iVar18;
      piVar16[-1 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-2 - iVar18] = (int)(&stack0xffffffac + iVar2);
      piVar16[-3 - iVar18] = 0x422eca;
      FUN_00423a30((uint *)piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
      puVar12 = local_8;
      puVar5 = local_10;
      iVar6 = local_20;
      if (local_c == 0) {
        piVar16[-iVar18] = iVar18;
        piVar16[-1 - iVar18] = (int)puVar12;
        piVar16[-2 - iVar18] = iVar18 * 2;
        piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-4 - iVar18] = 0;
        piVar16[-5 - iVar18] = (int)(piVar16 + (1 - iVar18));
        piVar16[-6 - iVar18] = (int)puVar5;
        piVar16[-7 - iVar18] = 0x422eff;
        FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                     (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                     (uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
      }
      else {
        piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-1 - iVar18] = iVar6;
        piVar16[-2 - iVar18] = iVar18;
        piVar16[-3 - iVar18] = (int)puVar12;
        piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
        piVar16[-5 - iVar18] = 0x422ee4;
        FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                     piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
      }
      local_28 = (uint *)((int)local_28 + -1);
    } while (local_28 != (uint *)0x0);
  }
  while ((0 < local_18 || (0 < param_3))) {
    param_3 = param_3 - (int)local_2c;
    local_24 = (uint *)(local_34 + local_18 * 4);
    local_1c = *(uint *)(local_34 + local_18 * 4);
    local_28 = local_2c;
    bVar10 = (byte)param_3;
    if (param_3 < 0) {
      if (local_18 < 1) {
        local_28 = (uint *)(param_3 + (int)local_2c);
      }
      else {
        local_18 = local_18 + -1;
        param_3 = param_3 + 0x20;
        local_24 = (uint *)(local_34 + local_18 * 4);
        local_1c = local_1c << (-bVar10 & 0x1f) |
                   *(uint *)(local_34 + local_18 * 4) >> ((byte)param_3 & 0x1f);
      }
    }
    else {
      local_1c = local_1c >> (bVar10 & 0x1f);
    }
    local_1c = local_1c & (1 << ((byte)local_28 & 0x1f)) - 1U;
    if (local_1c >> ((byte)local_28 - 1 & 0x1f) == 0) {
      do {
        if ((local_18 < 1) && (param_3 < 1)) break;
        piVar16[-iVar18] = iVar18;
        piVar16[-1 - iVar18] = (int)(piVar16 + (1 - iVar18));
        piVar16[-2 - iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-3 - iVar18] = 0x422faa;
        FUN_00423a30((uint *)piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
        puVar12 = local_8;
        puVar5 = local_10;
        iVar6 = local_20;
        if (local_c == 0) {
          piVar16[-iVar18] = iVar18;
          piVar16[-1 - iVar18] = (int)puVar12;
          piVar16[-2 - iVar18] = iVar18 * 2;
          piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
          piVar16[-4 - iVar18] = 0;
          piVar16[-5 - iVar18] = (int)(piVar16 + (1 - iVar18));
          piVar16[-6 - iVar18] = (int)puVar5;
          piVar16[-7 - iVar18] = 0x422fdf;
          FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                       (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],
                       piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
        }
        else {
          piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
          piVar16[-1 - iVar18] = iVar6;
          piVar16[-2 - iVar18] = iVar18;
          piVar16[-3 - iVar18] = (int)puVar12;
          piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
          piVar16[-5 - iVar18] = 0x422fc4;
          FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],
                       piVar16[-2 - iVar18],piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
        }
        if (param_3 == 0) {
          param_3 = 0x1f;
          local_18 = local_18 + -1;
          local_24 = local_24 + -1;
          uVar19 = *local_24 >> 0x1f;
        }
        else {
          param_3 = param_3 + -1;
          uVar19 = *local_24 >> ((byte)param_3 & 0x1f) & 1;
        }
        local_1c = uVar19 + local_1c * 2;
      } while (local_1c >> ((char)local_28 - 1U & 0x1f) == 0);
    }
    puVar12 = local_28;
    if (local_1c != 0) {
      puVar12 = (uint *)0x0;
      local_24 = (uint *)0x0;
      if ((local_1c & 1) == 0) {
        do {
          local_1c = local_1c >> 1;
          puVar12 = (uint *)((int)puVar12 + 1);
        } while ((local_1c & 1) == 0);
        local_24 = puVar12;
      }
      pbVar13 = (byte *)((int)local_28 + (-1 - (int)local_24));
      if (-1 < (int)pbVar13) {
        local_28 = (uint *)(pbVar13 + 1);
        do {
          piVar16[-iVar18] = iVar18;
          piVar16[-1 - iVar18] = (int)(piVar16 + (1 - iVar18));
          piVar16[-2 - iVar18] = (int)(&stack0xffffffac + iVar2);
          piVar16[-3 - iVar18] = 0x423066;
          FUN_00423a30((uint *)piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
          puVar12 = local_8;
          puVar5 = local_10;
          iVar6 = local_20;
          if (local_c == 0) {
            piVar16[-iVar18] = iVar18;
            piVar16[-1 - iVar18] = (int)puVar12;
            piVar16[-2 - iVar18] = iVar18 * 2;
            piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
            piVar16[-4 - iVar18] = 0;
            piVar16[-5 - iVar18] = (int)(piVar16 + (1 - iVar18));
            piVar16[-6 - iVar18] = (int)puVar5;
            piVar16[-7 - iVar18] = 0x42309b;
            FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                         (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],
                         piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18])
            ;
          }
          else {
            piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
            piVar16[-1 - iVar18] = iVar6;
            piVar16[-2 - iVar18] = iVar18;
            piVar16[-3 - iVar18] = (int)puVar12;
            piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
            piVar16[-5 - iVar18] = 0x423080;
            FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],
                         piVar16[-2 - iVar18],piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
          }
          local_28 = (uint *)((int)local_28 + -1);
        } while (local_28 != (uint *)0x0);
      }
      puVar12 = local_14;
      uVar19 = local_1c >> 1;
      piVar16[-iVar18] = iVar18;
      piVar16[-1 - iVar18] = (int)(puVar12 + uVar19 * iVar18);
      piVar16[-2 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
      piVar16[-4 - iVar18] = 0x4230be;
      FUN_00426480((uint *)piVar16[-3 - iVar18],(uint *)piVar16[-2 - iVar18],
                   (uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
      puVar12 = local_8;
      puVar5 = local_10;
      iVar6 = local_20;
      if (local_c == 0) {
        piVar16[-iVar18] = iVar18;
        piVar16[-1 - iVar18] = (int)puVar12;
        piVar16[-2 - iVar18] = iVar18 * 2;
        piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-4 - iVar18] = 0;
        piVar16[-5 - iVar18] = (int)(piVar16 + (1 - iVar18));
        piVar16[-6 - iVar18] = (int)puVar5;
        piVar16[-7 - iVar18] = 0x4230f6;
        FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                     (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                     (uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
        puVar12 = local_24;
      }
      else {
        piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-1 - iVar18] = iVar6;
        piVar16[-2 - iVar18] = iVar18;
        piVar16[-3 - iVar18] = (int)puVar12;
        piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
        piVar16[-5 - iVar18] = 0x4230d8;
        FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                     piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
        puVar12 = local_24;
      }
    }
    if (-1 < (int)((int)puVar12 + -1)) {
      local_28 = puVar12;
      do {
        piVar16[-iVar18] = iVar18;
        piVar16[-1 - iVar18] = (int)(piVar16 + (1 - iVar18));
        piVar16[-2 - iVar18] = (int)(&stack0xffffffac + iVar2);
        piVar16[-3 - iVar18] = 0x423114;
        FUN_00423a30((uint *)piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],piVar16[-iVar18]);
        puVar12 = local_8;
        puVar5 = local_10;
        iVar6 = local_20;
        if (local_c == 0) {
          piVar16[-iVar18] = iVar18;
          piVar16[-1 - iVar18] = (int)puVar12;
          piVar16[-2 - iVar18] = iVar18 * 2;
          piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
          piVar16[-4 - iVar18] = 0;
          piVar16[-5 - iVar18] = (int)(piVar16 + (1 - iVar18));
          piVar16[-6 - iVar18] = (int)puVar5;
          piVar16[-7 - iVar18] = 0x423149;
          FUN_00426570((uint *)piVar16[-6 - iVar18],(uint *)piVar16[-5 - iVar18],
                       (uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],
                       piVar16[-2 - iVar18],(uint *)piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
        }
        else {
          piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
          piVar16[-1 - iVar18] = iVar6;
          piVar16[-2 - iVar18] = iVar18;
          piVar16[-3 - iVar18] = (int)puVar12;
          piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
          piVar16[-5 - iVar18] = 0x42312e;
          FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],
                       piVar16[-2 - iVar18],piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
        }
        local_28 = (uint *)((int)local_28 + -1);
      } while (local_28 != (uint *)0x0);
    }
  }
  if (local_c == 0) {
    if (local_20 != 0) {
      piVar16[-iVar18] = local_20;
      piVar16[-1 - iVar18] = iVar18;
      piVar16[-2 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-3 - iVar18] = (int)(&stack0xffffffac + iVar2);
      piVar16[-4 - iVar18] = 0x4231ef;
      uVar19 = FUN_00423f40(piVar16[-3 - iVar18],piVar16[-2 - iVar18],piVar16[-1 - iVar18],
                            *(byte *)(piVar16 + -iVar18));
      puVar12 = local_8;
      puVar7 = local_30;
      piVar16[-4 - iVar18] = iVar18;
      piVar16[-5 - iVar18] = (int)puVar12;
      *(uint *)(&stack0xffffffac + (int)puVar7 + iVar2) = uVar19;
      puVar5 = local_10;
      piVar16[-6 - iVar18] = (uint)(uVar19 != 0) + iVar18;
      piVar16[-7 - iVar18] = (int)(&stack0xffffffac + iVar2);
      piVar16[-8 - iVar18] = 0;
      piVar16[-9 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-10 - iVar18] = (int)puVar5;
      piVar16[-0xb - iVar18] = 0x423211;
      FUN_00426570((uint *)piVar16[-10 - iVar18],(uint *)piVar16[-9 - iVar18],
                   (uint *)piVar16[-8 - iVar18],(uint *)piVar16[-7 - iVar18],piVar16[-6 - iVar18],
                   (uint *)piVar16[-5 - iVar18],(uint *)piVar16[-4 - iVar18]);
      piVar16[-0xb - iVar18] = local_20;
      piVar16[-0xc - iVar18] = iVar18;
      piVar16[-0xd - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-0xe - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-0xf - iVar18] = 0x42321d;
      FUN_004249b0((uint *)piVar16[-0xe - iVar18],(uint *)piVar16[-0xd - iVar18],
                   piVar16[-0xc - iVar18],*(byte *)(piVar16 + (-0xb - iVar18)));
    }
  }
  else {
    if (iVar18 != 0) {
      uVar19 = piVar16[1 - iVar18];
      local_2c = (uint *)(piVar16 + (2 - iVar18));
      puVar12 = local_2c;
      puVar14 = (uint *)(&stack0xffffffac + iVar2);
      iVar6 = iVar18;
      while (iVar6 = iVar6 + -1, iVar6 != 0) {
        *puVar7 = uVar19;
        puVar7 = puVar7 + 1;
        uVar19 = *puVar12;
        local_2c = puVar12 + 1;
        puVar12 = local_2c;
        puVar14 = puVar7;
      }
      local_2c = puVar12;
      *puVar14 = uVar19;
      puVar8 = (undefined4 *)(&stack0xffffffac + (int)local_30 + iVar2);
      iVar6 = iVar18;
      do {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    puVar7 = local_8;
    iVar6 = local_20;
    piVar16[-iVar18] = (int)(&stack0xffffffac + iVar2);
    piVar16[-1 - iVar18] = iVar6;
    piVar16[-2 - iVar18] = iVar18;
    piVar16[-3 - iVar18] = (int)puVar7;
    piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
    piVar16[-5 - iVar18] = 0x4231ba;
    FUN_004232d0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                 piVar16[-1 - iVar18],(uint *)piVar16[-iVar18]);
    puVar7 = local_8;
    piVar16[-5 - iVar18] = iVar18;
    piVar16[-6 - iVar18] = (int)puVar7;
    piVar16[-7 - iVar18] = (int)(piVar16 + (1 - iVar18));
    piVar16[-8 - iVar18] = 0x4231c5;
    iVar6 = FUN_00424c80(piVar16[-7 - iVar18],piVar16[-6 - iVar18],piVar16[-5 - iVar18]);
    puVar7 = local_8;
    if (-1 < iVar6) {
      piVar16[-iVar18] = iVar18;
      piVar16[-1 - iVar18] = (int)puVar7;
      piVar16[-2 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-3 - iVar18] = (int)(piVar16 + (1 - iVar18));
      piVar16[-4 - iVar18] = 0x4231d8;
      FUN_00424c30((uint *)piVar16[-3 - iVar18],(uint *)piVar16[-2 - iVar18],
                   (int *)piVar16[-1 - iVar18],piVar16[-iVar18]);
    }
  }
  iVar6 = iVar18;
  if (0 < iVar18) {
    piVar9 = (int *)((int)piVar16 + (int)local_30 + iVar18 * -4);
    do {
      if (*piVar9 != 0) break;
      iVar6 = iVar6 + -1;
      piVar9 = piVar9 + -1;
    } while (0 < iVar6);
  }
  if ((((*local_34 & 1) != 0) && (param_2[1] < 0)) && (iVar6 != 0)) {
    piVar16[-iVar18] = iVar6;
    piVar16[-1 - iVar18] = (int)(piVar16 + (1 - iVar18));
    piVar16[-2 - iVar18] = iVar18;
    piVar16[-3 - iVar18] = *(undefined4 *)(param_4 + 8);
    piVar16[-4 - iVar18] = (int)(piVar16 + (1 - iVar18));
    piVar16[-5 - iVar18] = 0x423260;
    FUN_00424cc0((uint *)piVar16[-4 - iVar18],(uint *)piVar16[-3 - iVar18],piVar16[-2 - iVar18],
                 (int *)piVar16[-1 - iVar18],piVar16[-iVar18]);
    iVar6 = iVar18;
    if (0 < iVar18) {
      piVar9 = (int *)((int)piVar16 + (int)local_30 + iVar18 * -4);
      do {
        if (*piVar9 != 0) break;
        iVar6 = iVar6 + -1;
        piVar9 = piVar9 + -1;
      } while (0 < iVar6);
    }
  }
  if (*param_1 < iVar6) {
    piVar16[-iVar18] = iVar6;
    piVar16[-1 - iVar18] = (int)param_1;
    piVar16[-2 - iVar18] = 0x42328b;
    FUN_00423dc0((int *)piVar16[-1 - iVar18],piVar16[-iVar18]);
  }
  puVar7 = local_14;
  param_1[1] = iVar6;
  if (iVar6 != 0) {
    uVar1 = piVar16[1 - iVar18];
    puVar8 = (undefined4 *)param_1[2];
    while (iVar6 = iVar6 + -1, iVar6 != 0) {
      piVar17 = piVar17 + 1;
      *puVar8 = uVar1;
      uVar1 = *piVar17;
      puVar8 = puVar8 + 1;
    }
    *puVar8 = uVar1;
  }
  piVar16[-iVar18] = local_3c;
  piVar16[-1 - iVar18] = (int)puVar7;
  piVar16[-2 - iVar18] = 0x4232bf;
  (*(code *)PTR_FUN_0044c0a0)();
  return;
}

