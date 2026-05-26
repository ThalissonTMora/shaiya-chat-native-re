/*
 * server/ps_game.exe — CUser_SendQueueFlush
 * Requested VA: 0x00426EC0
 * Entry Ghidra:  00426ec0
 * Ghidra name:   FUN_00426ec0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426ec0(int param_1)

{
  int *piVar1;
  int iVar2;
  LONG LVar3;
  int *piVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x268));
  piVar1 = *(int **)(param_1 + 0x260);
  piVar4 = (int *)piVar1[1];
  if (piVar4 == piVar1) {
    piVar4 = (int *)0x0;
  }
  else {
    *(int **)(param_1 + 0x264) = piVar1;
    if ((*piVar4 != 0) && (piVar4[1] != 0)) {
      *(int *)(*piVar4 + 4) = piVar4[1];
      *(int *)piVar4[1] = *piVar4;
      piVar4[1] = 0;
      *piVar4 = 0;
    }
    *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + -1;
  }
  while (piVar4 != (int *)0x0) {
    switch(piVar4[2]) {
    case 1:
      FUN_00427420();
      break;
    case 2:
      FUN_00427140(piVar4[3]);
      break;
    case 3:
      FUN_00427b20(param_1,piVar4[5],piVar4[6],piVar4[7]);
      break;
    case 4:
      FUN_004278f0(piVar4[3],*(undefined *)(piVar4 + 4),piVar4[5],piVar4[6],piVar4[7]);
      break;
    case 5:
      if (piVar4[7] == 0) {
        FUN_00427f80(piVar4[3]);
      }
    }
    iVar2 = piVar4[3];
    LVar3 = InterlockedDecrement((LONG *)(iVar2 + 8));
    if (LVar3 == 0) {
      FUN_004f33a0(iVar2);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_010a2c20);
    if (DAT_010a2c14 == (int *)0x0) {
      DAT_010a2c14 = piVar4;
      piVar4[1] = 0;
    }
    else {
      piVar4[1] = (int)DAT_010a2c14;
      DAT_010a2c14 = piVar4;
    }
    _DAT_010a2c1c = _DAT_010a2c1c + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_010a2c20);
    piVar1 = *(int **)(param_1 + 0x260);
    piVar4 = (int *)piVar1[1];
    if (piVar4 == piVar1) {
      piVar4 = (int *)0x0;
    }
    else {
      *(int **)(param_1 + 0x264) = piVar1;
      if ((*piVar4 != 0) && (piVar4[1] != 0)) {
        *(int *)(*piVar4 + 4) = piVar4[1];
        *(int *)piVar4[1] = *piVar4;
        piVar4[1] = 0;
        *piVar4 = 0;
      }
      *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + -1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x268));
  return;
}

