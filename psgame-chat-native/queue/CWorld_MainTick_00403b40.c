/*
 * server/ps_game.exe — CWorld_MainTick
 * VA solicitado: 0x00403B40
 * Entry Ghidra:  00403b40
 * Ghidra name:   FUN_00403b40
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00403b40(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  LONG *lpAddend;
  undefined4 *puVar6;
  
  bVar3 = false;
  if (*(uint *)(param_1 + 0xa4) <= param_2) {
    piVar4 = (int *)FUN_00404e80();
    if (piVar4 != (int *)0x0) {
      bVar3 = true;
      do {
        iVar5 = piVar4[2];
        puVar6 = (undefined4 *)(iVar5 + 8);
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(param_1 + 0x14);
        *puVar6 = **(undefined4 **)(param_1 + 0x14);
        *(undefined4 **)(**(int **)(param_1 + 0x14) + 4) = puVar6;
        **(undefined4 **)(param_1 + 0x14) = puVar6;
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
        piVar1 = *(int **)(param_1 + 0x40);
        piVar4 = (int *)piVar1[1];
        if (piVar4 == piVar1) {
          piVar4 = (int *)0x0;
        }
        else {
          *(int **)(param_1 + 0x44) = piVar1;
          if ((*piVar4 != 0) && (piVar4[1] != 0)) {
            *(int *)(*piVar4 + 4) = piVar4[1];
            *(int *)piVar4[1] = *piVar4;
            piVar4[1] = 0;
            *piVar4 = 0;
          }
          *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -1;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
      } while (piVar4 != (int *)0x0);
    }
    *(uint *)(param_1 + 0xa4) = param_2 + 100;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
  *(int *)(param_1 + 0x18) = iVar5;
  if (iVar5 != *(int *)(param_1 + 0x14)) {
    do {
      if (iVar5 == 0) break;
      FUN_00428100();
      iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
      *(int *)(param_1 + 0x18) = iVar5;
    } while (iVar5 != *(int *)(param_1 + 0x14));
  }
  if (*(uint *)(param_1 + 0x74) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428400();
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x74) = param_2 + 100;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x78) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428a50(param_2);
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x78) = param_2 + 1000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x7c) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428c50(param_2);
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x7c) = param_2 + 3000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x80) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428b80(*(undefined4 *)(iVar5 + 8),param_2);
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x80) = param_2 + 5000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x84) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428460();
        FUN_00428de0();
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x84) = param_2 + 500;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x88) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_004284d0();
        FUN_00429090(param_2);
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x88) = param_2 + 1000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x94) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428e50();
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x94) = param_2 + 3000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x8c) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_004288f0(*(undefined4 *)(iVar5 + 8),param_2);
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x8c) = param_2 + 10000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x90) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428d70();
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x90) = param_2 + 60000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x98) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00424310();
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0x98) = param_2 + 60000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0x9c) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        iVar5 = *(int *)(iVar5 + 8);
        if ((((*(int *)(*(int *)(iVar5 + 0x28) + 0x1a4) == 5) && (0 < *(int *)(iVar5 + 0x1a4))) &&
            (*(int *)(iVar5 + 0x1c) != -1)) &&
           (iVar5 = FUN_0042f850(*(int *)(iVar5 + 0x28)), iVar5 != 0)) {
          FUN_00429a00();
        }
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    if (DAT_00582780 != 0xffff) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
      *(int *)(param_1 + 0x18) = iVar5;
      if (iVar5 != *(int *)(param_1 + 0x14)) {
        do {
          if (iVar5 == 0) break;
          FUN_004273a0();
          iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
          *(int *)(param_1 + 0x18) = iVar5;
        } while (iVar5 != *(int *)(param_1 + 0x14));
      }
    }
    *(uint *)(param_1 + 0x9c) = param_2 + 60000;
    bVar3 = true;
  }
  if (*(uint *)(param_1 + 0xac) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        if ((*(int *)(*(int *)(*(int *)(iVar5 + 8) + 0x28) + 0x1e0) != 0) && (DAT_005879ac != 0)) {
          FUN_0043ffd0(param_2);
        }
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0xac) = param_2 + 60000;
  }
  FUN_004042a0();
  iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
  *(int *)(param_1 + 0x18) = iVar5;
  if (iVar5 != *(int *)(param_1 + 0x14)) {
    do {
      if (iVar5 == 0) break;
      FUN_00426ec0();
      iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
      *(int *)(param_1 + 0x18) = iVar5;
    } while (iVar5 != *(int *)(param_1 + 0x14));
  }
  if (bVar3) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        FUN_00428210();
        iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
  }
  if (*(uint *)(param_1 + 0xa0) <= param_2) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(int *)(param_1 + 0x18) = iVar5;
    if (iVar5 != *(int *)(param_1 + 0x14)) {
      do {
        if (iVar5 == 0) break;
        iVar5 = *(int *)(iVar5 + 8);
        if (((*(int *)(*(int *)(iVar5 + 0x28) + 0x1a4) == 0) || (*(int *)(iVar5 + 0x1a4) != 0)) ||
           (*(int *)(iVar5 + 0x58) != 0)) {
LAB_00404250:
          iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        }
        else {
          iVar2 = *(int *)(*(int *)(iVar5 + 0x28) + 0x1d4);
          if (iVar2 == 0) {
LAB_00404156:
            piVar4 = *(int **)(param_1 + 0x18);
            if (*(int **)(param_1 + 0x14) != piVar4) {
              *(int *)(param_1 + 0x18) = *piVar4;
              if ((*piVar4 != 0) && (piVar4[1] != 0)) {
                *(int *)(*piVar4 + 4) = piVar4[1];
                *(int *)piVar4[1] = *piVar4;
                piVar4[1] = 0;
                *piVar4 = 0;
              }
              *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
            }
            switch(*(undefined4 *)(*(int *)(iVar5 + 0x28) + 0x1a4)) {
            case 3:
            case 4:
              FUN_00404c30(iVar5 + 0x1c);
              lpAddend = (LONG *)(DAT_00587960 + 0x378);
              break;
            case 5:
              FUN_00404c30(iVar5 + 0x1c);
              lpAddend = (LONG *)(DAT_00587960 + 0x36c);
              break;
            case 6:
              FUN_00404c30(iVar5 + 0x1c);
              lpAddend = (LONG *)(DAT_00587960 + 0x368);
              break;
            default:
              goto switchD_0040419b_caseD_4;
            }
            InterlockedDecrement(lpAddend);
            InterlockedDecrement((LONG *)(DAT_00587960 + 0x380));
switchD_0040419b_caseD_4:
            FUN_00404ce0();
            FUN_00423300(iVar5);
            iVar2 = *(int *)(iVar5 + 0x14);
            piVar4 = (int *)(iVar2 + 0x74);
            EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x80));
            if (*piVar4 == 0) {
              *piVar4 = iVar5;
              *(undefined4 *)(iVar5 + 4) = 0;
            }
            else {
              *(int *)(iVar5 + 4) = *piVar4;
              *piVar4 = iVar5;
            }
            *(int *)(iVar2 + 0x7c) = *(int *)(iVar2 + 0x7c) + 1;
            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x80));
            goto LAB_00404250;
          }
          if (*(uint *)(iVar5 + 0x20) != 0) {
            if (param_2 < *(uint *)(iVar5 + 0x20)) goto LAB_00404250;
            goto LAB_00404156;
          }
          *(uint *)(iVar5 + 0x20) = iVar2 + param_2;
          iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4);
        }
        *(int *)(param_1 + 0x18) = iVar5;
      } while (iVar5 != *(int *)(param_1 + 0x14));
    }
    *(uint *)(param_1 + 0xa0) = param_2 + 1000;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return;
}

