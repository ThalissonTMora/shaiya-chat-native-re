/*
 * server/ps_login.exe — BigInt_powModCore
 * Requested VA: 0x00423850
 * Entry Ghidra:  00423850
 * Ghidra name:   FUN_00423850
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_00423850(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined *puVar10;
  int *piVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  
  iVar1 = param_2[1];
  iVar13 = *(int *)(param_3 + 4);
  iVar9 = iVar1;
  if (iVar1 < 0) {
    iVar9 = -iVar1;
  }
  if (iVar13 < 0) {
    iVar13 = -iVar13;
  }
  iVar14 = (iVar9 - iVar13) + 1;
  if (iVar13 == 0) {
    FUN_00426ed0();
  }
  if (*param_1 < iVar13) {
    FUN_00423dc0(param_1,iVar13);
  }
  if (iVar14 < 1) {
    if (param_2 != param_1) {
      puVar8 = (undefined4 *)param_2[2];
      puVar6 = (undefined4 *)param_1[2];
      if (iVar9 != 0) {
        uVar2 = *puVar8;
        while (iVar9 = iVar9 + -1, iVar9 != 0) {
          puVar8 = puVar8 + 1;
          *puVar6 = uVar2;
          uVar2 = *puVar8;
          puVar6 = puVar6 + 1;
        }
        *puVar6 = uVar2;
      }
      param_1[1] = param_2[1];
      return;
    }
  }
  else {
    iVar14 = iVar14 * -4;
    puVar10 = &stack0xffffffe0 + iVar14;
    piVar7 = (int *)param_1[2];
    param_2 = (int *)param_2[2];
    piVar15 = *(int **)(param_3 + 8);
    if (piVar15 == piVar7) {
      *(undefined4 *)(&stack0xffffffdc + iVar14) = 0x423924;
      iVar4 = iVar13 * -4;
      puVar10 = &stack0xffffffe0 + iVar4 + iVar14;
      piVar11 = (int *)(&stack0xffffffe0 + iVar4 + iVar14);
      if (iVar13 != 0) {
        iVar3 = *piVar15;
        iVar5 = iVar13;
        while (iVar5 = iVar5 + -1, iVar5 != 0) {
          piVar15 = piVar15 + 1;
          *piVar11 = iVar3;
          iVar3 = *piVar15;
          piVar11 = piVar11 + 1;
        }
        *piVar11 = iVar3;
      }
      piVar15 = (int *)(&stack0xffffffe0 + iVar4 + iVar14);
    }
    puVar12 = puVar10;
    if (param_2 == piVar7) {
      *(undefined4 *)(puVar10 + -4) = 0x423966;
      iVar4 = iVar9 * -4;
      puVar12 = puVar10 + iVar4;
      piVar11 = (int *)(puVar10 + iVar4);
      if (iVar9 != 0) {
        iVar3 = *param_2;
        iVar5 = iVar9;
        while (iVar5 = iVar5 + -1, iVar5 != 0) {
          param_2 = param_2 + 1;
          *piVar11 = iVar3;
          iVar3 = *param_2;
          piVar11 = piVar11 + 1;
        }
        *piVar11 = iVar3;
      }
      param_2 = (int *)(puVar10 + iVar4);
    }
    *(int *)(puVar12 + -4) = iVar13;
    *(int **)(puVar12 + -8) = piVar15;
    *(int *)(puVar12 + -0xc) = iVar9;
    *(int **)(puVar12 + -0x10) = param_2;
    *(undefined4 *)(puVar12 + -0x14) = 0;
    *(int **)(puVar12 + -0x18) = piVar7;
    *(undefined **)(puVar12 + -0x1c) = &stack0xffffffe0 + iVar14;
    *(undefined4 *)(puVar12 + -0x20) = 0x4239aa;
    FUN_00426570(*(uint **)(puVar12 + -0x1c),*(uint **)(puVar12 + -0x18),*(uint **)(puVar12 + -0x14)
                 ,*(uint **)(puVar12 + -0x10),*(uint *)(puVar12 + -0xc),*(uint **)(puVar12 + -8),
                 *(uint **)(puVar12 + -4));
    if (0 < iVar13) {
      piVar7 = piVar7 + iVar13 + -1;
      do {
        if (*piVar7 != 0) break;
        iVar13 = iVar13 + -1;
        piVar7 = piVar7 + -1;
      } while (0 < iVar13);
    }
    if (iVar1 < 0) {
      iVar13 = -iVar13;
    }
    param_1[1] = iVar13;
  }
  return;
}

