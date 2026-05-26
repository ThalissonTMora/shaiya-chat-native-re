/*
 * Game.exe — ChatWindow_DrawTabChrome
 * VA solicitado: 0x0057B990
 * Entry Ghidra:  0057b990
 * Ghidra name:   FUN_0057b990
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0057b990(int *param_1)

{
  int iStack_7c;
  
  iStack_7c = *param_1;
  if (iStack_7c != 0) {
    (**(code **)(*DAT_022b69a8 + 0x104))(DAT_022b69a8,0);
    (**(code **)(*DAT_022b69a8 + 0x14c))(DAT_022b69a8,6,2,&iStack_7c,0x1c);
  }
  return;
}

