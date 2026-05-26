/*
 * server/ps_game.exe — CParty_BroadcastPacket
 * Requested VA: 0x0044E950
 * Entry Ghidra:  0044e950
 * Ghidra name:   FUN_0044e950
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_0044e950(undefined4 param_1)

{
  int iVar1;
  LONG LVar2;
  int *piVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar1 = FUN_004f3dc0(param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x118));
    if (*(char *)(unaff_ESI + 0x114) == '\x01') {
      iVar4 = 0;
      if (0 < *(int *)(unaff_ESI + 0x10)) {
        piVar3 = (int *)(unaff_ESI + 0x18);
        do {
          if (*piVar3 != 0) {
            FUN_004ed0b0(iVar1);
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 2;
        } while (iVar4 < *(int *)(unaff_ESI + 0x10));
      }
    }
    else if ((*(char *)(unaff_ESI + 0x114) == '\0') && (iVar4 = 0, 0 < *(int *)(unaff_ESI + 0x10)))
    {
      piVar3 = (int *)(unaff_ESI + 0x18);
      do {
        if (*piVar3 != 0) {
          FUN_004ed0b0(iVar1);
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 2;
      } while (iVar4 < *(int *)(unaff_ESI + 0x10));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x118));
    LVar2 = InterlockedDecrement((LONG *)(iVar1 + 8));
    if (LVar2 == 0) {
      FUN_004f33a0(iVar1);
    }
  }
  return;
}

