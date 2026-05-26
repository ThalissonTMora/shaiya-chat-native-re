/*
 * server/ps_game.exe — Recv_Wrapper
 * VA solicitado: 0x004748E0
 * Entry Ghidra:  004748e0
 * Ghidra name:   FUN_004748e0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: pipeline
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004748e0(int param_1_00,int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1_00 + 0x57f0) != '\0') {
    FUN_004e4180(**(ushort **)(param_1 + 4) - 2);
  }
  cVar1 = FUN_004ec930(param_1);
  if (cVar1 == '\0') {
    FUN_00474940();
  }
  FUN_004f33a0(param_1);
  return;
}

