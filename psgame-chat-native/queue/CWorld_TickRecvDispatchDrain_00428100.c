/*
 * server/ps_game.exe — CWorld_TickRecvDispatchDrain
 * Requested VA: 0x00428100
 * Entry Ghidra:  00428100
 * Ghidra name:   FUN_00428100
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00428100(void)

{
  DWORD DVar1;
  int iVar2;
  int unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x40));
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x38) + 0xc);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + -8;
  }
  *(int *)(unaff_EDI + 0x3c) = iVar2;
  if (iVar2 != *(int *)(unaff_EDI + 0x38)) {
    do {
      if (iVar2 == 0) break;
      FUN_00474850();
      iVar2 = *(int *)(*(int *)(unaff_EDI + 0x3c) + 0xc);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = iVar2 + -8;
      }
      *(int *)(unaff_EDI + 0x3c) = iVar2;
    } while (iVar2 != *(int *)(unaff_EDI + 0x38));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x40));
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x184) + 4);
  *(int *)(unaff_EDI + 0x188) = iVar2;
  if (iVar2 != *(int *)(unaff_EDI + 0x184)) {
    do {
      if (iVar2 == 0) break;
      FUN_00474850();
      iVar2 = *(int *)(*(int *)(unaff_EDI + 0x188) + 4);
      *(int *)(unaff_EDI + 0x188) = iVar2;
    } while (iVar2 != *(int *)(unaff_EDI + 0x184));
  }
  DVar1 = GetTickCount();
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x184) + 4);
  *(int *)(unaff_EDI + 0x188) = iVar2;
  if (iVar2 != *(int *)(unaff_EDI + 0x184)) {
    do {
      if (iVar2 == 0) break;
      FUN_0049dd50(DVar1);
      iVar2 = *(int *)(*(int *)(unaff_EDI + 0x188) + 4);
      *(int *)(unaff_EDI + 0x188) = iVar2;
    } while (iVar2 != *(int *)(unaff_EDI + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  return;
}

