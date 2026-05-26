/*
 * Game.exe — AdminChatMonitor_vfn_0x308
 * VA solicitado: 0x00595570
 * Entry Ghidra:  00595570
 * Ghidra name:   FUN_00595570
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: vtable
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00595570(char param_1)

{
  if (param_1 == '\x01') {
    DAT_022aa80c = 1;
    return;
  }
  FUN_00423150(0x1f,0x12f,5);
  return;
}

