/*
 * server/ps_game.exe — Script_ArgFetcher
 * Requested VA: 0x004A3000
 * Entry Ghidra:  004a3000
 * Ghidra name:   FUN_004a3000
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int FUN_004a3000(void)

{
  int unaff_ESI;
  uint unaff_EDI;
  
  if ((uint)((*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 0xc)) / 0x94) <= unaff_EDI) {
    FUN_0051b1ad();
  }
  return unaff_EDI * 0x94 + *(int *)(unaff_ESI + 0xc);
}

