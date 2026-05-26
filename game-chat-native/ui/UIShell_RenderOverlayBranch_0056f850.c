/*
 * Game.exe — UIShell_RenderOverlayBranch
 * Requested VA: 0x0056F850
 * Entry Ghidra:  0056f850
 * Ghidra name:   FUN_0056f850
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __fastcall FUN_0056f850(int *param_1)

{
  if ((*(char *)(param_1 + 1) != '\0') && (*(char *)(param_1 + 0x74) != '\0')) {
    if (*param_1 == 0) {
      (**(code **)(*DAT_022b69a8 + 0xdc))(DAT_022b69a8,0,param_1 + 0x58);
      return;
    }
    if (*(char *)(param_1 + 0xc1) != '\0') {
      (**(code **)(*DAT_022b69a8 + 0xdc))(DAT_022b69a8,0,param_1 + 0x60);
      return;
    }
    (**(code **)(*DAT_022b69a8 + 0xdc))(DAT_022b69a8,0,param_1 + 0x6c);
  }
  return;
}

