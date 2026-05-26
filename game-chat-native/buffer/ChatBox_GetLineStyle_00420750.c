/*
 * Game.exe — ChatBox_GetLineStyle
 * Requested VA: 0x00420750
 * Entry Ghidra:  00420750
 * Ghidra name:   FUN_00420750
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: buffer
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined4 __thiscall FUN_00420750(int param_1_00,undefined4 param_1)

{
  switch(param_1) {
  case 0xf:
  case 0x10:
  case 0x14:
    return *(undefined4 *)(param_1_00 + 0x20);
  case 0x11:
    return *(undefined4 *)(param_1_00 + 0x28);
  case 0x12:
  case 0x13:
  case 0x15:
  case 0x16:
  case 0x1f:
    return *(undefined4 *)(param_1_00 + 0x24);
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
    return *(undefined4 *)(param_1_00 + 0x2c);
  default:
    return 1;
  case 0x22:
  case 0x30:
    return *(undefined4 *)(param_1_00 + 0x30);
  case 0x23:
    return *(undefined4 *)(param_1_00 + 0x34);
  case 0x25:
    return *(undefined4 *)(param_1_00 + 0x38);
  case 0x26:
  case 0x31:
    return *(undefined4 *)(param_1_00 + 0x3c);
  }
}

