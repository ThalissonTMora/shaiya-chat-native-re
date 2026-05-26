/*
 * server/ps_game.exe — CWorld_TickFlushBroadcastSends
 * Requested VA: 0x004273A0
 * Entry Ghidra:  004273a0
 * Ghidra name:   FUN_004273a0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004273a0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  LONG LVar3;
  int unaff_EBX;
  
  iVar2 = FUN_004f3dc0(param_1);
  if (iVar2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x18c));
    iVar1 = *(int *)(*(int *)(unaff_EBX + 0x184) + 4);
    if (iVar1 != *(int *)(unaff_EBX + 0x184)) {
      do {
        if (iVar1 == 0) break;
        FUN_004ed0b0(iVar2);
        iVar1 = *(int *)(iVar1 + 4);
      } while (iVar1 != *(int *)(unaff_EBX + 0x184));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x18c));
    LVar3 = InterlockedDecrement((LONG *)(iVar2 + 8));
    if (LVar3 == 0) {
      FUN_004f33a0(iVar2);
    }
  }
  return;
}

