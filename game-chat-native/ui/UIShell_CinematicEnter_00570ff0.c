/*
 * Game.exe — UIShell_CinematicEnter
 * Requested VA: 0x00570FF0
 * Entry Ghidra:  00570ff0
 * Ghidra name:   FUN_00570ff0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 *
 * CONFIRMED: sets DAT_007c0838 object +0x1D0 = 1 for duration of cinematic camera
 * transition; cleared @ L57107a. Paired with balloon/nameplate gates @ 0x412792.
 */

undefined1 __thiscall FUN_00570ff0(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  
  uVar2 = *(undefined4 *)(param_1 + 0xf8);
  *(undefined1 *)(param_1 + 0x1d0) = 1;
  *(undefined1 *)(param_1 + 0x304) = 0;
  uVar1 = FUN_005705a0(uVar2);
  if (uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x1d0) = 0;
    return 0;
  }
  FUN_0056f850();
  puVar3 = DAT_022b69a8;
  pcVar4 = *(code **)(*DAT_022b69a8 + 0xe4);
  (*pcVar4)(DAT_022b69a8,1,0x98);
  pcVar4 = *(code **)(*puVar3 + 0xe4);
  (*pcVar4)(puVar3,1,0x1c);
  FUN_005454700();
  FUN_00570c50();
  puVar3 = DAT_022b69a8;
  pcVar4 = *(code **)(*DAT_022b69a8 + 0xe4);
  (*pcVar4)(DAT_022b69a8,0,0x98);
  FUN_00570660();
  *(undefined1 *)(param_1 + 0x1d0) = 0;
  return 1;
}
