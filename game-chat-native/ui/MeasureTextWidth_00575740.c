/*
 * Game.exe — MeasureTextWidth
 * VA solicitado: 0x00575740
 * Entry Ghidra:  00575740
 * Ghidra name:   FUN_00575740
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


undefined4 FUN_00575740(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_8 [2];
  
  FUN_00575610(param_1,param_2,local_8,param_3);
  return local_8[0];
}

