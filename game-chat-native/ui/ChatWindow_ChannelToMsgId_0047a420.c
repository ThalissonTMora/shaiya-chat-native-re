/*
 * Game.exe — ChatWindow_ChannelToMsgId
 * Requested VA: 0x0047A420
 * Entry Ghidra:  0047a420
 * Ghidra name:   FUN_0047a420
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined4 FUN_0047a420(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = FUN_00420db0(0x13de);
    return uVar1;
  case 1:
    uVar1 = FUN_00420db0(0x1501);
    return uVar1;
  case 2:
    uVar1 = FUN_00420db0(0x13df);
    return uVar1;
  case 3:
    uVar1 = FUN_00420db0(0x13e0);
    return uVar1;
  case 4:
    uVar1 = FUN_00420db0(0x13e1);
    return uVar1;
  case 5:
    uVar1 = FUN_00420db0(0x150c);
    return uVar1;
  default:
    return 0;
  }
}

