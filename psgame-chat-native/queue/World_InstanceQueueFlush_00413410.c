/*
 * server/ps_game.exe — World_InstanceQueueFlush
 * Requested VA: 0x00413410
 * Entry Ghidra:  00413410
 * Ghidra name:   FUN_00413410
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413410(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  LONG LVar6;
  int iVar7;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  iVar4 = param_1;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x21c);
  EnterCriticalSection(lpCriticalSection);
  piVar5 = (int *)FUN_004155e0();
  if (piVar5 != (int *)0x0) {
    lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x21c);
    do {
      iVar7 = 0;
      param_1 = 0;
      if (0 < *(int *)(iVar4 + 8)) {
        do {
          if (*(int *)(*(int *)(iVar4 + 4) + iVar7 + 4) == 0) {
            FUN_004f4200();
            iVar2 = *(int *)(iVar7 + 0x50 + *(int *)(iVar4 + 4));
            iVar3 = *(int *)(iVar2 + 4);
            *(int *)(iVar7 + *(int *)(iVar4 + 4) + 0x54) = iVar3;
            if (iVar3 != iVar2) {
              do {
                if (iVar3 == 0) break;
                FUN_00426dd0(piVar5[2],*(undefined *)(piVar5 + 4),piVar5[5],piVar5[6],piVar5[7]);
                iVar3 = *(int *)(*(int *)(iVar7 + 0x54 + *(int *)(iVar4 + 4)) + 4);
                piVar1 = (int *)(iVar7 + 0x50 + *(int *)(iVar4 + 4));
                piVar1[1] = iVar3;
              } while (iVar3 != *piVar1);
            }
            FUN_004f4150();
          }
          param_1 = param_1 + 1;
          iVar7 = iVar7 + 0x98;
        } while (param_1 < *(int *)(iVar4 + 8));
      }
      iVar7 = piVar5[3];
      LVar6 = InterlockedDecrement((LONG *)(iVar7 + 8));
      if (LVar6 == 0) {
        FUN_004f33a0(iVar7);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_010a2bfc);
      if (DAT_010a2bf0 == (int *)0x0) {
        DAT_010a2bf0 = piVar5;
        piVar5[1] = 0;
      }
      else {
        piVar5[1] = (int)DAT_010a2bf0;
        DAT_010a2bf0 = piVar5;
      }
      _DAT_010a2bf8 = _DAT_010a2bf8 + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_010a2bfc);
      EnterCriticalSection(lpCriticalSection_00);
      piVar1 = *(int **)(iVar4 + 0x214);
      piVar5 = (int *)piVar1[1];
      if (piVar5 == piVar1) {
        piVar5 = (int *)0x0;
      }
      else {
        *(int **)(iVar4 + 0x218) = piVar1;
        if ((*piVar5 != 0) && (piVar5[1] != 0)) {
          *(int *)(*piVar5 + 4) = piVar5[1];
          *(int *)piVar5[1] = *piVar5;
          piVar5[1] = 0;
          *piVar5 = 0;
        }
        *(int *)(iVar4 + 0x234) = *(int *)(iVar4 + 0x234) + -1;
      }
      LeaveCriticalSection(lpCriticalSection_00);
    } while (piVar5 != (int *)0x0);
  }
  LeaveCriticalSection(lpCriticalSection);
  return;
}

