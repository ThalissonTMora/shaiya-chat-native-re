/*
 * server/ps_game.exe — CWorld_TickGuildChat3s
 * Requested VA: 0x00428C50
 * Entry Ghidra:  00428c50
 * Ghidra name:   FUN_00428c50
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00428c50(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x184) + 4);
  *(int *)(unaff_EDI + 0x188) = iVar1;
  if (iVar1 != *(int *)(unaff_EDI + 0x184)) {
    do {
      if (iVar1 == 0) break;
      iVar1 = *(int *)(iVar1 + 8);
      if (iVar1 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar1 + -0xd0;
      }
      if (*(int *)(iVar3 + 0x1444) != 1) {
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = iVar1 + -0xd0;
        }
        FUN_004971a0(iVar1,param_1);
      }
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x188) + 4);
      *(int *)(unaff_EDI + 0x188) = iVar1;
    } while (iVar1 != *(int *)(unaff_EDI + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x1b8));
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x1b0) + 4);
  *(int *)(unaff_EDI + 0x1b4) = iVar1;
  if (iVar1 != *(int *)(unaff_EDI + 0x1b0)) {
    do {
      if (iVar1 == 0) break;
      if (*(int *)(iVar1 + 8) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 8) + -0x7c;
      }
      if (*(int *)(iVar1 + 0x70) == 0) {
        iVar1 = *(int *)(iVar1 + 0x1a8);
      }
      else if (*(int *)(iVar1 + 0x6c) == 0) {
        iVar1 = 0;
      }
      else {
        piVar2 = (int *)FUN_00425af0();
        iVar1 = *(int *)(*piVar2 + 0x48);
      }
      if (iVar1 != 2) {
        FUN_004b5700(param_1);
      }
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x1b4) + 4);
      *(int *)(unaff_EDI + 0x1b4) = iVar1;
    } while (iVar1 != *(int *)(unaff_EDI + 0x1b0));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x1b8));
  return;
}

