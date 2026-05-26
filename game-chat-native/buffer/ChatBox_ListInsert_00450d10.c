/*
 * Game.exe — ChatBox_ListInsert
 * VA solicitado: 0x00450D10
 * Entry Ghidra:  00450d10
 * Ghidra name:   FUN_00450d10
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00450d10(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = param_2;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_3;
  }
  return;
}

