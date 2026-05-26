/*
 * Game.exe — Handler_AdminChatMonitor
 * VA solicitado: 0x005E4E30
 * Entry Ghidra:  005e4e30
 * Ghidra name:   FUN_005e4e30
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e4e30(void)

{
  undefined4 local_4;
  
  FUN_005f4700(&local_4,1);
  (**(code **)(*DAT_022fa2f0 + 0x308))(local_4);
  return;
}

