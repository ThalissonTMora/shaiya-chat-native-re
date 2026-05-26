/*
 * Game.exe — Handler_Chat_Admin_F106
 * Requested VA: 0x005E5C10
 * Entry Ghidra:  005e5c10
 * Ghidra name:   FUN_005e5c10
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5c10(void)

{
  uint local_7d8;
  undefined local_7d4 [2000];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_7d8;
  _memset(local_7d4,0,2000);
  FUN_005f4700(&local_7d8,2);
  FUN_005f4780(local_7d4,local_7d8 & 0xffff);
  (**(code **)(*DAT_022fa2f0 + 0x334))(local_7d8,local_7d4);
  ___security_check_cookie_4();
  return;
}

