/*
 * server/ps_game.exe — SConnection_SendIfGlobalReady
 * Requested VA: 0x004ED2D0
 * Entry Ghidra:  004ed2d0
 * Ghidra name:   FUN_004ed2d0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004ed2d0(int param_1)

{
  if (*(char *)(param_1 + 0xd8) != '\0') {
    FUN_004ed0e0();
    return;
  }
  return;
}

