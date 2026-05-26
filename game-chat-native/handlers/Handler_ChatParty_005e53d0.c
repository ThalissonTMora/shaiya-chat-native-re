/*
 * Game.exe — Handler_ChatParty
 * Requested VA: 0x005E53D0
 * Entry Ghidra:  005e53d0
 * Ghidra name:   FUN_005e53d0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e53d0(void)

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
  (**(code **)(*DAT_022fa2f0 + 0x324))(0,1,local_88,local_8c,local_84);
  ___security_check_cookie_4();
  return;
}

