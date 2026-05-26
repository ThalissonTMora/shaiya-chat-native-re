/*
 * ps_game.exe — Connection_DecryptInbound
 * Requested VA: 0x00464FA0
 * Entry Ghidra:  00464fa0
 * Ghidra name:   FUN_00464fa0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __fastcall FUN_00464fa0(int param_1)

{
  int in_EAX;
  
  if (*(char *)(param_1 + 0x230) != '\0') {
    FUN_004e4180(**(ushort **)(in_EAX + 4) - 2);
  }
  return;
}

