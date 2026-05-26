/*
 * Game.exe — ChatWindow_BeginSubmit
 * VA solicitado: 0x00564B60
 * Entry Ghidra:  00564b60
 * Ghidra name:   FUN_00564b60
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_00564b60(int param_1_00,int param_1)

{
  if (param_1 != 0) {
    ImmAssociateContext(*(HWND *)(param_1_00 + 0x1620),DAT_022b3f70);
    return;
  }
  ImmAssociateContext(*(HWND *)(param_1_00 + 0x1620),(HIMC)0x0);
  return;
}

