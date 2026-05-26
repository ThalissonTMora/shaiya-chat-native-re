/*
 * server/ps_game.exe — Recv_PreDispatchInner
 * VA solicitado: 0x004EF120
 * Entry Ghidra:  004ef120
 * Ghidra name:   FUN_004ef120
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: pipeline
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 __thiscall FUN_004ef120(int param_1_00,undefined4 param_1,int param_2)

{
  short sVar1;
  
  sVar1 = *(short *)(*(int *)(param_2 + 4) + 2);
  if (sVar1 == 2) {
    FUN_004ec760(1,0);
  }
  else {
    if (sVar1 != 3) {
      return 0;
    }
    if (*(int *)(param_1_00 + 0x110) != 0) {
      FUN_004efa30(param_1);
      return 1;
    }
  }
  return 1;
}

