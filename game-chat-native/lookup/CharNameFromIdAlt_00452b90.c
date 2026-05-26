/*
 * Game.exe — CharNameFromIdAlt
 * VA solicitado: 0x00452B90
 * Entry Ghidra:  00452b90
 * Ghidra name:   FUN_00452b90
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: lookup
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


undefined4 __thiscall FUN_00452b90(int param_1_00,undefined4 param_1)

{
  int local_4;
  
  local_4 = param_1_00;
  FUN_00451b80(&local_4,&param_1);
  if (local_4 == *(int *)(param_1_00 + 0x13da0c)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}

