/*
 * Game.exe — UIShell_CinematicEnterAlt
 * Requested VA: 0x00571730
 * Entry Ghidra:  00571730
 * Ghidra name:   FUN_00571730
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 *
 * CONFIRMED: alternate cinematic path; +0x1D0 = 1 @ 0x571766, cleared @ 0x571BC5.
 * Callers: UIShell_CinematicSceneHandler @ 0x571C71, 0x5722FD.
 */

undefined1 __fastcall FUN_00571730(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  float local_2c0 [176];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_2c0;
  uVar2 = *(undefined4 *)(param_1 + 0xf4);
  *(undefined1 *)(param_1 + 0x1d0) = 1;
  *(undefined1 *)(param_1 + 0x304) = 1;
  uVar1 = FUN_005705a0(uVar2);
  if (uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x1d0) = 0;
    ___security_check_cookie_4();
    return 0;
  }
  /* matrix / camera interpolation (float ops @ 0x571788–0x571B60) */
  FUN_00570660();
  *(undefined1 *)(param_1 + 0x1d0) = 0;
  ___security_check_cookie_4();
  return 1;
}
