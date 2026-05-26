/*
 * server/ps_game.exe — ItemUse_PostSendRefresh
 * VA solicitado: 0x00411710
 * Entry Ghidra:  00411710
 * Ghidra name:   FUN_00411710
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: megaphone
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00411710(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  
  iVar2 = DAT_00587964;
  piVar3 = (int *)(DAT_00587964 + 0x84);
  if (unaff_EDI != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(DAT_00587964 + 0x90);
    EnterCriticalSection(lpCriticalSection);
    if (*piVar3 == 0) {
      *piVar3 = unaff_EDI;
      *(undefined4 *)(unaff_EDI + 4) = 0;
      piVar3 = (int *)(iVar2 + 0x8c);
      *piVar3 = *piVar3 + 1;
      LeaveCriticalSection(lpCriticalSection);
      return;
    }
    *(int *)(unaff_EDI + 4) = *piVar3;
    piVar1 = (int *)(iVar2 + 0x8c);
    *piVar1 = *piVar1 + 1;
    *piVar3 = unaff_EDI;
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}

