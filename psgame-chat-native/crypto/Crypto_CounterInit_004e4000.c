/*
 * ps_game.exe — Crypto_CounterInit
 * Requested VA: 0x004E4000
 * Entry Ghidra:  004e4000
 * Ghidra name:   FUN_004e4000
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __fastcall FUN_004e4000(undefined4 *param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xf4) = *param_1;
  *(undefined4 *)(in_EAX + 0xf8) = param_1[1];
  *(undefined4 *)(in_EAX + 0xfc) = param_1[2];
  *(undefined4 *)(in_EAX + 0x100) = param_1[3];
  *(undefined4 *)(in_EAX + 0x104) = 0;
  return;
}

