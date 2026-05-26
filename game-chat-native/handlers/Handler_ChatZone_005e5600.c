/*
 * Game.exe — Handler_ChatZone
 * Requested VA: 0x005E5600
 * Entry Ghidra:  005e5600
 * Ghidra name:   FUN_005e5600
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5600(void)

{
  undefined auStack_90 [3];
  char local_8d;
  uint local_8c;
  undefined local_88 [4];
  undefined local_84 [128];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)auStack_90;
  _memset(local_84,0,0x80);
  FUN_005f4700(&local_8d,1);
  FUN_005f4700(local_88,4);
  FUN_005f4700(&local_8c,1);
  FUN_005f4780(local_84,local_8c & 0xff);
  if (local_8d != '\0') {
    (**(code **)(*DAT_022fa2f0 + 0x328))(0,0,5,local_88,local_8c,local_84);
    ___security_check_cookie_4();
    return;
  }
  (**(code **)(*DAT_022fa2f0 + 0x328))(0,0,4,local_88,local_8c,local_84);
  ___security_check_cookie_4();
  return;
}

