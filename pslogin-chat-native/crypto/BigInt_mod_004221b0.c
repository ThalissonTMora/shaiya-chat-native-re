/*
 * server/ps_login.exe — BigInt_mod
 * Requested VA: 0x004221B0
 * Entry Ghidra:  004221b0
 * Ghidra name:   FUN_004221b0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl FUN_004221b0(int *param_1,int *param_2,int *param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  undefined *puVar13;
  uint *puVar14;
  uint *puVar15;
  int *piVar16;
  uint *puVar17;
  undefined4 auStackY_38 [2];
  int iVar18;
  int local_c;
  
  puVar17 = (uint *)param_2[1];
  puVar14 = (uint *)param_2[2];
  if ((int)puVar17 < 0) {
    puVar17 = (uint *)-(int)puVar17;
  }
  puVar11 = (uint *)param_3[1];
  puVar10 = (uint *)param_3[2];
  if ((int)puVar11 < 0) {
    puVar11 = (uint *)-(int)puVar11;
  }
  if (puVar17 == (uint *)0x0) {
    param_1[1] = (int)puVar11;
    if (param_1 != param_3) {
      if (*param_1 < (int)puVar11) {
        FUN_00423dc0(param_1,(int)puVar11);
      }
      if (puVar11 != (uint *)0x0) {
        uVar5 = *puVar10;
        puVar17 = (uint *)param_1[2];
        while (puVar11 = (uint *)((int)puVar11 + -1), puVar11 != (uint *)0x0) {
          puVar10 = puVar10 + 1;
          *puVar17 = uVar5;
          uVar5 = *puVar10;
          puVar17 = puVar17 + 1;
        }
        *puVar17 = uVar5;
        return;
      }
    }
  }
  else if (puVar11 == (uint *)0x0) {
    param_1[1] = (int)puVar17;
    if (param_1 != param_2) {
      if (*param_1 < (int)puVar17) {
        FUN_00423dc0(param_1,(int)puVar17);
      }
      uVar5 = *puVar14;
      puVar11 = (uint *)param_1[2];
      while (puVar17 = (uint *)((int)puVar17 + -1), puVar17 != (uint *)0x0) {
        puVar14 = puVar14 + 1;
        *puVar11 = uVar5;
        uVar5 = *puVar14;
        puVar11 = puVar11 + 1;
      }
      *puVar11 = uVar5;
      return;
    }
  }
  else {
    if (puVar17 == (uint *)0x1) {
      param_1[1] = 1;
      auStackY_38[1] = 0x42229a;
      iVar4 = FUN_00424a30(puVar10,puVar11,*puVar14);
      *(int *)param_1[2] = iVar4;
      return;
    }
    if (puVar11 == (uint *)0x1) {
      param_1[1] = 1;
      auStackY_38[1] = 0x4222c0;
      iVar4 = FUN_00424a30(puVar14,puVar17,*puVar10);
      *(int *)param_1[2] = iVar4;
      return;
    }
    uVar5 = *puVar14;
    puVar15 = puVar14;
    while (uVar5 == 0) {
      puVar1 = puVar15 + 1;
      puVar15 = puVar15 + 1;
      uVar5 = *puVar1;
    }
    iVar4 = (int)puVar15 - (int)puVar14 >> 2;
    local_c = (int)puVar17 - iVar4;
    uVar5 = -*puVar15 & *puVar15;
    if (uVar5 < 0x10000) {
      iVar8 = (-(uint)(uVar5 < 0x100) & 0xfffffff8) + 9;
    }
    else {
      iVar8 = (-(uint)(uVar5 < 0x1000000) & 0xfffffff8) + 0x19;
    }
    param_2 = (int *)(0x1f - ((0x21 - (uint)(byte)(&DAT_00441534)[uVar5 >> ((byte)iVar8 & 0x1f)]) -
                             iVar8));
    iVar18 = 0x422349;
    iVar8 = local_c * -4;
    puVar17 = (uint *)(&stack0xffffffdc + iVar8);
    if (param_2 == (int *)0x0) {
      puVar13 = &stack0xffffffdc + iVar8;
      if (local_c != 0) {
        uVar5 = *puVar15;
        puVar14 = (uint *)(&stack0xffffffdc + iVar8);
        iVar18 = local_c;
        while (iVar18 = iVar18 + -1, iVar18 != 0) {
          puVar15 = puVar15 + 1;
          *puVar17 = uVar5;
          uVar5 = *puVar15;
          puVar17 = puVar17 + 1;
          puVar14 = puVar17;
        }
        *puVar14 = uVar5;
        puVar13 = &stack0xffffffdc + iVar8;
      }
    }
    else {
      *(int **)(&stack0xffffffd8 + iVar8) = param_2;
      *(int *)(&stack0xffffffd4 + iVar8) = local_c;
      *(uint **)(&stack0xffffffd0 + iVar8) = puVar15;
      auStackY_38[1 - local_c] = &stack0xffffffdc + iVar8;
      auStackY_38[-local_c] = 0x42235b;
      FUN_004249b0((uint *)auStackY_38[1 - local_c],*(uint **)(&stack0xffffffd0 + iVar8),
                   *(int *)(&stack0xffffffd4 + iVar8),(&stack0xffffffd8)[iVar8]);
      local_c = local_c - (uint)(iVar18 == 0);
      puVar13 = &stack0xffffffdc + iVar8;
    }
    uVar5 = *puVar10;
    while (uVar5 == 0) {
      puVar17 = puVar10 + 1;
      puVar10 = puVar10 + 1;
      uVar5 = *puVar17;
    }
    iVar18 = (int)puVar10 - param_3[2] >> 2;
    iVar12 = (int)puVar11 - iVar18;
    uVar5 = -*puVar10 & *puVar10;
    if (uVar5 < 0x10000) {
      iVar9 = (-(uint)(uVar5 < 0x100) & 0xfffffff8) + 9;
    }
    else {
      iVar9 = (-(uint)(uVar5 < 0x1000000) & 0xfffffff8) + 0x19;
    }
    piVar16 = (int *)(0x1f - ((0x21 - (uint)(byte)(&DAT_00441534)[uVar5 >> ((byte)iVar9 & 0x1f)]) -
                             iVar9));
    *(undefined4 *)(puVar13 + -4) = 0x42240f;
    iVar9 = iVar12 * -4;
    puVar17 = (uint *)(puVar13 + iVar9);
    puVar6 = (undefined4 *)(puVar13 + iVar9);
    if (piVar16 == (int *)0x0) {
      if (iVar12 != 0) {
        uVar5 = *puVar10;
        iVar3 = iVar12;
        while (iVar3 = iVar3 + -1, iVar3 != 0) {
          puVar10 = puVar10 + 1;
          *puVar17 = uVar5;
          uVar5 = *puVar10;
          puVar17 = puVar17 + 1;
        }
        *puVar17 = uVar5;
      }
    }
    else {
      *(int **)(puVar13 + iVar9 + -4) = piVar16;
      *(int *)(puVar13 + iVar9 + -8) = iVar12;
      *(uint **)(puVar13 + iVar9 + -0xc) = puVar10;
      *(undefined **)(puVar13 + iVar9 + -0x10) = puVar13 + iVar9;
      *(undefined4 *)(puVar13 + iVar9 + -0x14) = 0x422421;
      FUN_004249b0(*(uint **)(puVar13 + iVar9 + -0x10),*(uint **)(puVar13 + iVar9 + -0xc),
                   *(int *)(puVar13 + iVar9 + -8),puVar13[iVar9 + -4]);
      iVar12 = iVar12 - (uint)(*(int *)(puVar13 + -4) == 0);
    }
    if ((iVar18 < iVar4) || ((iVar18 <= iVar4 && (iVar18 = iVar4, piVar16 <= param_2)))) {
      iVar4 = iVar18;
      param_2 = piVar16;
    }
    if ((local_c < iVar12) ||
       ((local_c == iVar12 &&
        (*(uint *)(&stack0xffffffd8 + local_c * 4 + iVar8) <
         *(uint *)(puVar13 + iVar12 * 4 + iVar9 + -4))))) {
      *(int *)(puVar13 + iVar9 + -4) = local_c;
      *(undefined **)(puVar13 + iVar9 + -8) = &stack0xffffffdc + iVar8;
      *(int *)(puVar13 + iVar9 + -0xc) = iVar12;
      *(undefined **)(puVar13 + iVar9 + -0x10) = puVar13 + iVar9;
    }
    else {
      *(int *)(puVar13 + iVar9 + -4) = iVar12;
      *(undefined **)(puVar13 + iVar9 + -8) = puVar13 + iVar9;
      *(int *)(puVar13 + iVar9 + -0xc) = local_c;
      *(undefined **)(puVar13 + iVar9 + -0x10) = &stack0xffffffdc + iVar8;
    }
    *(undefined **)(puVar13 + iVar9 + -0x14) = puVar13 + iVar9;
    *(undefined4 *)(puVar13 + iVar9 + -0x18) = 0x4224b4;
    iVar8 = FUN_00423fd0(*(uint **)(puVar13 + iVar9 + -0x14),*(uint **)(puVar13 + iVar9 + -0x10),
                         *(uint **)(puVar13 + iVar9 + -0xc),*(uint **)(puVar13 + iVar9 + -8),
                         *(uint **)(puVar13 + iVar9 + -4));
    param_3 = (int *)(iVar4 + iVar8);
    if (param_2 == (int *)0x0) {
      if (*param_1 < (int)param_3) {
        *(int **)(puVar13 + iVar9 + -4) = param_3;
        *(int **)(puVar13 + iVar9 + -8) = param_1;
        *(undefined4 *)(puVar13 + iVar9 + -0xc) = 0x422546;
        FUN_00423dc0(*(int **)(puVar13 + iVar9 + -8),*(int *)(puVar13 + iVar9 + -4));
      }
      if (iVar4 != 0) {
        puVar7 = (undefined4 *)param_1[2];
        iVar18 = iVar4;
        do {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      if (iVar8 != 0) {
        uVar2 = *(undefined4 *)(puVar13 + iVar9);
        puVar7 = (undefined4 *)(param_1[2] + iVar4 * 4);
        while (iVar8 = iVar8 + -1, iVar8 != 0) {
          puVar6 = puVar6 + 1;
          *puVar7 = uVar2;
          uVar2 = *puVar6;
          puVar7 = puVar7 + 1;
        }
        *puVar7 = uVar2;
      }
    }
    else {
      param_3 = (int *)((int)param_3 +
                       (uint)(*(uint *)(puVar13 + iVar8 * 4 + iVar9 + -4) >>
                              (0x20U - (char)param_2 & 0x1f) != 0));
      if (*param_1 < (int)param_3) {
        *(int **)(puVar13 + iVar9 + -4) = param_3;
        *(int **)(puVar13 + iVar9 + -8) = param_1;
        *(undefined4 *)(puVar13 + iVar9 + -0xc) = 0x4224ee;
        FUN_00423dc0(*(int **)(puVar13 + iVar9 + -8),*(int *)(puVar13 + iVar9 + -4));
      }
      if (iVar4 != 0) {
        puVar6 = (undefined4 *)param_1[2];
        iVar18 = iVar4;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      iVar18 = param_1[2];
      *(int **)(puVar13 + iVar9 + -4) = param_2;
      *(int *)(puVar13 + iVar9 + -8) = iVar8;
      iVar18 = iVar18 + iVar4 * 4;
      *(undefined **)(puVar13 + iVar9 + -0xc) = puVar13 + iVar9;
      *(int *)(puVar13 + iVar9 + -0x10) = iVar18;
      *(undefined4 *)(puVar13 + iVar9 + -0x14) = 0x42251b;
      uVar5 = FUN_00423f40(*(int *)(puVar13 + iVar9 + -0x10),*(int *)(puVar13 + iVar9 + -0xc),
                           *(int *)(puVar13 + iVar9 + -8),puVar13[iVar9 + -4]);
      if (uVar5 != 0) {
        *(uint *)(iVar18 + iVar8 * 4) = uVar5;
        param_1[1] = (int)param_3;
        return;
      }
    }
    param_1[1] = (int)param_3;
  }
  return;
}

