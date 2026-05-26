/*
 * Game.exe — UIShell_CinematicEnter
 * Requested VA: 0x00570FF0
 * Entry Ghidra:  00570ff0
 * Ghidra name:   FUN_00570ff0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined __fastcall FUN_00570ff0(int param_1)

{
  char cVar1;
  
  *(undefined *)(param_1 + 0x1d0) = 1;
  *(undefined *)(param_1 + 0x304) = 0;
  cVar1 = FUN_005705a0(*(undefined4 *)(param_1 + 0xf8));
  if (cVar1 == '\0') {
    *(undefined *)(param_1 + 0x1d0) = 0;
    return 0;
  }
  FUN_0056f850();
  (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,0x98,1);
  (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,0x1c,1);
  FUN_00454700();
  FUN_00570c50();
  (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,0x98,0);
  FUN_00570660();
  *(undefined *)(param_1 + 0x1d0) = 0;
  return 1;
}

