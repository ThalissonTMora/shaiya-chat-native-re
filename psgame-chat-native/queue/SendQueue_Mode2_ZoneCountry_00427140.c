/*
 * server/ps_game.exe — SendQueue_Mode2_ZoneCountry
 * VA solicitado: 0x00427140
 * Entry Ghidra:  00427140
 * Ghidra name:   FUN_00427140
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00427140(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char unaff_BL;
  int unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x184) + 4);
  if (iVar1 != *(int *)(unaff_EDI + 0x184)) {
    do {
      if (iVar1 == 0) break;
      if (*(int *)(iVar1 + 8) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar1 + 8) + -0xd0;
      }
      if (unaff_BL == *(char *)(iVar2 + 0x12d)) {
        FUN_004ed0b0(param_1);
      }
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != *(int *)(unaff_EDI + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  return;
}

