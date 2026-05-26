/*
 * server/ps_game.exe — SConnection_SendIfConnReady
 * VA solicitado: 0x004ED210
 * Entry Ghidra:  004ed210
 * Ghidra name:   FUN_004ed210
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: network
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004ed210(int param_1)

{
  if (*(char *)(param_1 + 0xd8) != '\0') {
    FUN_004ed0e0();
    return;
  }
  return;
}

