/*
 * Game.exe — Handler_Chat_Admin_F105
 * Requested VA: 0x005E5B70
 * Entry Ghidra:  005e5b70
 * Ghidra name:   FUN_005e5b70
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5b70(void)

{
  uint local_8c;
  undefined4 local_88;
  undefined local_84 [128];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_8c;
  _memset(local_84,0,0x80);
  FUN_005f4700(&local_88,4);
  FUN_005f4700(&local_8c,1);
  FUN_005f4780(local_84,local_8c & 0xff);
  (**(code **)(*DAT_022fa2f0 + 0x324))(1,1,local_88,local_8c,local_84);
  ___security_check_cookie_4();
  return;
}

