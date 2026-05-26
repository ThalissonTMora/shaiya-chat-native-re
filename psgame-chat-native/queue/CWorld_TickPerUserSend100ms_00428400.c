/*
 * server/ps_game.exe — CWorld_TickPerUserSend100ms
 * VA solicitado: 0x00428400
 * Entry Ghidra:  00428400
 * Ghidra name:   FUN_00428400
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00428400(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x18c));
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x184) + 4);
  *(int *)(unaff_ESI + 0x188) = iVar1;
  if (iVar1 != *(int *)(unaff_ESI + 0x184)) {
    do {
      if (iVar1 == 0) break;
      if (*(int *)(iVar1 + 8) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 8) + -0xd0;
      }
      FUN_0049d3e0(iVar1,unaff_EDI);
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x188) + 4);
      *(int *)(unaff_ESI + 0x188) = iVar1;
    } while (iVar1 != *(int *)(unaff_ESI + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x18c));
  return;
}

