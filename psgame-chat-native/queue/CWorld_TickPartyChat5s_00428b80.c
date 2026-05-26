/*
 * server/ps_game.exe — CWorld_TickPartyChat5s
 * Requested VA: 0x00428B80
 * Entry Ghidra:  00428b80
 * Ghidra name:   FUN_00428b80
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00428b80(int param_1,undefined4 param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18c));
  iVar1 = *(int *)(*(int *)(param_1 + 0x184) + 4);
  *(int *)(param_1 + 0x188) = iVar1;
  if (iVar1 != *(int *)(param_1 + 0x184)) {
    do {
      if (iVar1 == 0) break;
      if (*(int *)(iVar1 + 8) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 8) + -0xd0;
      }
      if (*(int *)(iVar1 + 0x1444) != 1) {
        FUN_0049ec30(param_2);
        FUN_0049e900();
        FUN_0049e970(param_2);
      }
      iVar1 = *(int *)(*(int *)(param_1 + 0x188) + 4);
      *(int *)(param_1 + 0x188) = iVar1;
    } while (iVar1 != *(int *)(param_1 + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18c));
  return;
}

