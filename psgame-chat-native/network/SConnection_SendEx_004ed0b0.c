/*
 * server/ps_game.exe — SConnection_SendEx
 * VA solicitado: 0x004ED0B0
 * Entry Ghidra:  004ed0b0
 * Ghidra name:   FUN_004ed0b0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: network
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004ed0b0(int param_1_00,int param_1)

{
  if (*(int *)(param_1_00 + 0x68) != -1) {
    InterlockedIncrement((LONG *)(param_1 + 8));
    FUN_004ef080(param_1_00,param_1);
  }
  return;
}

