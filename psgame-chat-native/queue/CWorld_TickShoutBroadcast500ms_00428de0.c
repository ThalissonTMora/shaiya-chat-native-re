/*
 * server/ps_game.exe — CWorld_TickShoutBroadcast500ms
 * Requested VA: 0x00428DE0
 * Entry Ghidra:  00428de0
 * Ghidra name:   FUN_00428de0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00428de0(void)

{
  int iVar1;
  int unaff_ESI;
  uint unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1e4));
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1dc) + 4);
  *(int *)(unaff_ESI + 0x1e0) = iVar1;
  if (iVar1 != *(int *)(unaff_ESI + 0x1dc)) {
    do {
      if (iVar1 == 0) break;
      if (*(int *)(iVar1 + 8) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 8) + -8;
      }
      if (((*(uint *)(iVar1 + 0x68) <= unaff_EDI) && (*(int *)(iVar1 + 0x34) == 8)) &&
         (*(int *)(iVar1 + 0x54) != 0)) {
        FUN_004d3f40();
      }
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1e0) + 4);
      *(int *)(unaff_ESI + 0x1e0) = iVar1;
    } while (iVar1 != *(int *)(unaff_ESI + 0x1dc));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1e4));
  return;
}

