/*
 * Game.exe — UIShell_CinematicSceneHandler
 * Requested VA: 0x00571C00
 * Entry Ghidra:  00571c00
 * Ghidra name:   FUN_00571c00
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 *
 * CONFIRMED: only enters cinematic when object+0x1D0 == 0 (L571C24, L57227C).
 * Calls UIShell_CinematicEnter @ 0x5722BE and UIShell_CinematicEnterAlt @ 0x5722FD.
 */

void __thiscall FUN_00571c00(int param_1)

{
  if (*(int *)param_1 != 0) {
    if ((*(int *)param_1 == 1) && (*(char *)(param_1 + 4) != '\0') &&
       (*(char *)(param_1 + 0x1d0) == '\0')) {
      FUN_0056f6e0();
      FUN_00570ff0();
      FUN_00571730();
    }
    return;
  }
  if (*(char *)(param_1 + 4) == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x1d0) != '\0') {
    return;
  }
  FUN_0056f6e0();
  FUN_00571730();
  return;
}
