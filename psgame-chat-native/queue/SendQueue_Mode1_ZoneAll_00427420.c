/*
 * server/ps_game.exe — SendQueue_Mode1_ZoneAll
 * VA solicitado: 0x00427420
 * Entry Ghidra:  00427420
 * Ghidra name:   FUN_00427420
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00427420(void)

{
  int iVar1;
  undefined4 unaff_EBX;
  int unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x184) + 4);
  if (iVar1 != *(int *)(unaff_EDI + 0x184)) {
    do {
      if (iVar1 == 0) break;
      FUN_004ed0b0(unaff_EBX);
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != *(int *)(unaff_EDI + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18c));
  return;
}

