/*
 * server/ps_game.exe — CWorld_PendingDequeHead
 * Requested VA: 0x00404E80
 * Entry Ghidra:  00404e80
 * Ghidra name:   FUN_00404e80
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int * FUN_00404e80(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int *piVar2;
  undefined4 *unaff_EDI;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EDI + 2);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = (int *)*unaff_EDI;
  piVar2 = (int *)piVar1[1];
  if (piVar2 == piVar1) {
    LeaveCriticalSection(lpCriticalSection);
    return (int *)0x0;
  }
  unaff_EDI[1] = piVar1;
  if ((*piVar2 != 0) && (piVar2[1] != 0)) {
    *(int *)(*piVar2 + 4) = piVar2[1];
    *(int *)piVar2[1] = *piVar2;
    piVar2[1] = 0;
    *piVar2 = 0;
  }
  unaff_EDI[8] = unaff_EDI[8] + -1;
  LeaveCriticalSection(lpCriticalSection);
  return piVar2;
}

