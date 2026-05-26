/*
 * server/ps_game.exe — Script_FlagSetter_2FC
 * Requested VA: 0x004C69F0
 * Entry Ghidra:  004c69f0
 * Ghidra name:   FUN_004c69f0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004c69f0(int param_1)

{
  int in_EAX;
  
  if (param_1 == 4) {
    *(undefined **)(in_EAX + 0x2fc) = &DAT_01010101;
    return;
  }
  *(undefined4 *)(in_EAX + 0x2fc) = 0;
  if (param_1 != 5) {
    *(undefined *)(param_1 + 0x2fc + in_EAX) = 1;
  }
  return;
}

