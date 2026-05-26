/*
 * server/ps_game.exe — CGuild_AcquireLockForChat
 * Requested VA: 0x00431EB0
 * Entry Ghidra:  00431eb0
 * Ghidra name:   FUN_00431eb0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: guild
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00431eb0(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x1810);
  *unaff_ESI = iVar1;
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x5cc));
    if (*(int *)(unaff_EDI + 0x1810) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*unaff_ESI + 0x5cc));
      *unaff_ESI = 0;
    }
  }
  return;
}

