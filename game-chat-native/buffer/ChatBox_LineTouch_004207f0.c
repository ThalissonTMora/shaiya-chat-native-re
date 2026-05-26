/*
 * Game.exe — ChatBox_LineTouch
 * Requested VA: 0x004207F0
 * Entry Ghidra:  004207f0
 * Ghidra name:   FUN_004207f0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: buffer
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_004207f0(int param_1)

{
  undefined uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x104)) {
  case 10:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
    if (DAT_007ab0d4 == 2) goto switchD_00420806_caseD_10;
  default:
    uVar1 = 0xff;
    break;
  case 0xf:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0x9b;
    *(undefined *)(param_1 + 0x10a) = 0x32;
    return;
  case 0x10:
  case 0x11:
  case 0x2a:
  case 0x2d:
switchD_00420806_caseD_10:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0;
    *(undefined *)(param_1 + 0x10a) = 0;
    return;
  case 0x12:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0xcc;
    *(undefined *)(param_1 + 0x10a) = 0;
    return;
  case 0x13:
    *(undefined *)(param_1 + 0x108) = 0x33;
    *(undefined *)(param_1 + 0x109) = 0xff;
    *(undefined *)(param_1 + 0x10a) = 0x33;
    return;
  case 0x14:
  case 0x2f:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0;
    *(undefined *)(param_1 + 0x10a) = 0xff;
    return;
  case 0x15:
    *(undefined *)(param_1 + 0x108) = 0x99;
    *(undefined *)(param_1 + 0x109) = 0xff;
    *(undefined *)(param_1 + 0x10a) = 0xff;
    return;
  case 0x16:
    *(undefined *)(param_1 + 0x108) = 0xcc;
    *(undefined *)(param_1 + 0x109) = 0xff;
    *(undefined *)(param_1 + 0x10a) = 0x33;
    return;
  case 0x18:
  case 0x28:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0xff;
    *(undefined *)(param_1 + 0x10a) = 0;
    return;
  case 0x1f:
    uVar1 = 0xcc;
    break;
  case 0x22:
    *(undefined *)(param_1 + 0x108) = 0xd5;
    *(undefined *)(param_1 + 0x109) = 0xd4;
    *(undefined *)(param_1 + 0x10a) = 0xd3;
    return;
  case 0x23:
    *(undefined *)(param_1 + 0x108) = 0xa8;
    *(undefined *)(param_1 + 0x109) = 0xf3;
    *(undefined *)(param_1 + 0x10a) = 0xa0;
    return;
  case 0x24:
    *(undefined *)(param_1 + 0x108) = 0xf3;
    *(undefined *)(param_1 + 0x109) = 0xa0;
    *(undefined *)(param_1 + 0x10a) = 0xa0;
    return;
  case 0x25:
    *(undefined *)(param_1 + 0x108) = 0xee;
    *(undefined *)(param_1 + 0x109) = 0xa4;
    *(undefined *)(param_1 + 0x10a) = 0xed;
    return;
  case 0x26:
    *(undefined *)(param_1 + 0x108) = 0xf3;
    *(undefined *)(param_1 + 0x109) = 0xde;
    *(undefined *)(param_1 + 0x10a) = 0xa0;
    return;
  case 0x27:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0x30;
    *(undefined *)(param_1 + 0x10a) = 0;
    return;
  case 0x30:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 0x80;
    *(undefined *)(param_1 + 0x10a) = 0xff;
    return;
  case 0x31:
    *(undefined *)(param_1 + 0x108) = 0x78;
    *(undefined *)(param_1 + 0x109) = 0x75;
    *(undefined *)(param_1 + 0x10a) = 0xe6;
    return;
  case 0x32:
    *(undefined *)(param_1 + 0x108) = 0xff;
    *(undefined *)(param_1 + 0x109) = 3;
    *(undefined *)(param_1 + 0x10a) = 0xda;
    return;
  }
  *(undefined *)(param_1 + 0x108) = uVar1;
  *(undefined *)(param_1 + 0x109) = uVar1;
  *(undefined *)(param_1 + 0x10a) = uVar1;
  return;
}

