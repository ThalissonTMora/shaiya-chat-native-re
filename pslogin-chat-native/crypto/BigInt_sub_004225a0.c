/*
 * server/ps_login.exe — BigInt_sub
 * Requested VA: 0x004225A0
 * Entry Ghidra:  004225a0
 * Ghidra name:   FUN_004225a0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_004225a0(int *param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  piVar3 = (int *)param_1[2];
  iVar4 = param_1[1];
  uVar8 = param_2 >> 5;
  bVar2 = (byte)param_2;
  if (-1 < iVar4) {
    if ((int)uVar8 < iVar4) {
      piVar3[uVar8] = piVar3[uVar8] | 1 << (bVar2 & 0x1f);
      param_1[1] = iVar4;
      return;
    }
    iVar1 = uVar8 + 1;
    if (*param_1 < iVar1) {
      FUN_00423dc0(param_1,iVar1);
      piVar3 = (int *)param_1[2];
    }
    iVar6 = uVar8 - iVar4;
    if (iVar6 != 0) {
      piVar5 = piVar3 + iVar4;
      do {
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    piVar3[uVar8] = 1 << (bVar2 & 0x1f);
    param_1[1] = iVar1;
    return;
  }
  uVar7 = 0;
  iVar6 = -iVar4;
  iVar1 = *piVar3;
  piVar5 = piVar3;
  while (iVar1 == 0) {
    piVar5 = piVar5 + 1;
    uVar7 = uVar7 + 1;
    iVar1 = *piVar5;
  }
  if ((int)uVar7 < (int)uVar8) {
    if ((int)uVar8 < iVar6) {
      piVar3[uVar8] = piVar3[uVar8] & ~(1 << (bVar2 & 0x1f));
      if (iVar6 != 0 && iVar4 < 1) {
        piVar3 = piVar3 + (-1 - iVar4);
        do {
          if (*piVar3 != 0) break;
          iVar6 = iVar6 + -1;
          piVar3 = piVar3 + -1;
        } while (0 < iVar6);
      }
      param_1[1] = -iVar6;
      return;
    }
  }
  else if (uVar8 == uVar7) {
    iVar4 = (~(1 << (bVar2 & 0x1f)) & piVar3[uVar8] - 1U) + 1;
    piVar3[uVar8] = iVar4;
    if (iVar4 == 0) {
      iVar4 = uVar8 + 1;
      if (iVar4 < iVar6) {
        piVar5 = piVar3 + iVar4;
        do {
          iVar1 = *piVar5;
          *piVar5 = iVar1 + 1;
          if (iVar1 + 1 != 0) {
            return;
          }
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar4 < iVar6);
      }
      iVar6 = iVar6 + 1;
      if (*param_1 < iVar6) {
        FUN_00423dc0(param_1,iVar6);
        piVar3 = (int *)param_1[2];
      }
      piVar3[iVar4] = 1;
      param_1[1] = -iVar6;
      return;
    }
  }
  else {
    uVar7 = piVar3[uVar8];
    piVar5 = piVar3 + uVar8;
    uVar8 = 1 << (bVar2 & 0x1f);
    *piVar5 = uVar7 - uVar8;
    if (uVar7 < uVar8) {
      iVar1 = piVar5[1];
      piVar5 = piVar5 + 1;
      *piVar5 = iVar1 + -1;
      while (iVar1 == 0) {
        iVar1 = piVar5[1];
        piVar5 = piVar5 + 1;
        *piVar5 = iVar1 + -1;
      }
    }
    param_1[1] = (uint)(piVar3[-1 - iVar4] == 0) + iVar4;
  }
  return;
}

