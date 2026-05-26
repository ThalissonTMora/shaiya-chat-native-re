/*
 * Game.exe — Handler_ChatNotify_E06
 * Requested VA: 0x005E5070
 * Entry Ghidra:  005e5070
 * Ghidra name:   FUN_005e5070
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5070(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005f4700(&local_4,1);
  FUN_005f4700(&local_8,4);
  FUN_005f4700(&local_c,4);
  FUN_005f4700(&local_10,2);
  (**(code **)(*DAT_022fa2f0 + 800))(local_4,local_8,local_c,local_10);
  return;
}

