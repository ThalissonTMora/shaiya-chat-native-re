/*
 * ps_game.exe — Connection_InitStreamCrypto
 * Requested VA: 0x00464E60
 * Entry Ghidra:  00464e60
 * Ghidra name:   FUN_00464e60
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void FUN_00464e60(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_004e2ce0();
  *(undefined4 *)(unaff_EDI + 0xf4) = *(undefined4 *)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_EDI + 0xf8) = *(undefined4 *)(unaff_ESI + 0x14);
  *(undefined4 *)(unaff_EDI + 0xfc) = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_EDI + 0x100) = *(undefined4 *)(unaff_ESI + 0x1c);
  *(undefined4 *)(unaff_EDI + 0x104) = 0;
  FUN_004e2ce0();
  *(undefined4 *)(unaff_EDI + 0x20c) = *(undefined4 *)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_EDI + 0x210) = *(undefined4 *)(unaff_ESI + 0x14);
  *(undefined4 *)(unaff_EDI + 0x214) = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_EDI + 0x218) = *(undefined4 *)(unaff_ESI + 0x1c);
  *(undefined4 *)(unaff_EDI + 0x21c) = 0;
  *(undefined *)(unaff_EDI + 0x230) = 1;
  *(undefined *)(unaff_EDI + 0x231) = 1;
  return;
}

