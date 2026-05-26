/*
 * server/ps_game.exe — World_BroadcastAll
 * VA solicitado: 0x00419120
 * Entry Ghidra:  00419120
 * Ghidra name:   FUN_00419120
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_00419120(undefined4 param_1)

{
  int iVar1;
  LONG LVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  iVar1 = FUN_004f3dc0(param_1);
  if (iVar1 != 0) {
    iVar4 = 0;
    if (0 < *(int *)(unaff_ESI + 8)) {
      iVar3 = 0;
      do {
        if (*(int *)(*(int *)(unaff_ESI + 4) + 4 + iVar3) != 0) {
          FUN_00426dd0(1,0,0,0,0);
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x98;
      } while (iVar4 < *(int *)(unaff_ESI + 8));
    }
    if (*(int *)(unaff_ESI + 0x380) != 0) {
      FUN_00413350(1,0,0,0,0);
    }
    LVar2 = InterlockedDecrement((LONG *)(iVar1 + 8));
    if (LVar2 == 0) {
      FUN_004f33a0(iVar1);
    }
  }
  return;
}

