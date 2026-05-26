/*
 * server/ps_game.exe — SConnection_CloseIfBound
 * Requested VA: 0x004EC830
 * Entry Ghidra:  004ec830
 * Ghidra name:   FUN_004ec830
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004ec830(int param_1_00,undefined4 param_1)

{
  if (*(int *)(param_1_00 + 0x68) != -1) {
    FUN_004ef090(param_1_00,param_1);
  }
  return;
}

