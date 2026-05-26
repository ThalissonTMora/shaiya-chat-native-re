/*
 * Game.exe — UIShell_ctor
 * Requested VA: 0x0056F470
 * Entry Ghidra:  0056f470
 * Ghidra name:   FUN_0056f470
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: init
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 *
 * CONFIRMED: allocates main UI shell stored in DAT_007c0838 @ ChatObject_alloc_site 0x0040AD5D.
 * Initializes +0x1D0 = 0 @ 0x56F515 (cinematic_overlay_suppress).
 */

int __thiscall FUN_0056f470(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0056ae00(param_1 + 0x1d4);
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)param_1 = uVar2;
  *(undefined4 *)(param_1 + 0xf4) = uVar2;
  *(undefined4 *)(param_1 + 0xf8) = uVar2;
  *(undefined4 *)(param_1 + 0xf0) = uVar2;
  *(undefined4 *)(param_1 + 0x2d8) = uVar2;
  *(undefined1 *)(param_1 + 0x1d0) = 0;  /* CONFIRMED @ 0x56F515 */
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  *(undefined4 *)(param_1 + 0x2dc) = uVar2;
  *(undefined4 *)(param_1 + 0x2e0) = uVar2;
  *(undefined4 *)(param_1 + 0x2e4) = uVar2;
  *(undefined4 *)(param_1 + 0x2f0) = uVar2;
  *(undefined4 *)(param_1 + 0x2f4) = uVar2;
  *(undefined4 *)(param_1 + 0x2e8) = uVar2;
  *(undefined4 *)(param_1 + 0x2ec) = uVar2;
  *(undefined4 *)(param_1 + 0x2f8) = uVar2;
  *(undefined4 *)(param_1 + 0x2fc) = uVar2;
  *(undefined1 *)(param_1 + 4) = 0;
  return param_1;
}
