/*
 * Game.exe — Handler_ChatError
 * Requested VA: 0x005E5470
 * Entry Ghidra:  005e5470
 * Ghidra name:   FUN_005e5470
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5470(void)

{
  undefined4 local_4;
  
  FUN_005f4700(&local_4,1);
  (**(code **)(*DAT_022fa2f0 + 0x340))(local_4);
  return;
}

