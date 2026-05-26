/*
 * server/ps_game.exe — SConnection_Close
 * VA solicitado: 0x004EC760
 * Entry Ghidra:  004ec760
 * Ghidra name:   FUN_004ec760
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: network
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004ec760(int param_1_00,undefined4 param_1,undefined4 param_2)

{
  if (*(int *)(param_1_00 + 0x18) == 0) {
    *(undefined4 *)(param_1_00 + 0x18) = param_1;
  }
  if (*(int *)(param_1_00 + 0x1c) == 0) {
    *(undefined4 *)(param_1_00 + 0x1c) = param_2;
  }
  if (*(int *)(param_1_00 + 0x68) != -1) {
    Ordinal_3(*(int *)(param_1_00 + 0x68));
    *(undefined4 *)(param_1_00 + 0x68) = 0xffffffff;
  }
  return;
}

