/*
 * server/ps_game.exe — CParty_AcquireLock
 * Requested VA: 0x0044E110
 * Entry Ghidra:  0044e110
 * Ghidra name:   FUN_0044e110
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: party
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0044e110(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x17f4);
  *unaff_ESI = iVar1;
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x118));
    if (*(int *)(unaff_EDI + 0x17f4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*unaff_ESI + 0x118));
      *unaff_ESI = 0;
    }
  }
  return;
}

