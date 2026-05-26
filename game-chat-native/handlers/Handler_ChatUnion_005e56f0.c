/*
 * Game.exe — Handler_ChatUnion
 * VA solicitado: 0x005E56F0
 * Entry Ghidra:  005e56f0
 * Ghidra name:   FUN_005e56f0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e56f0(void)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  FUN_005f4700(&local_4,4);
  FUN_005f4700(&local_8,2);
  (**(code **)(*DAT_022fa2f0 + 0x34c))(local_4,local_8);
  return;
}

