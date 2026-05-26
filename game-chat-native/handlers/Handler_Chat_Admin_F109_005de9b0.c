/*
 * Game.exe — Handler_Chat_Admin_F109
 * Requested VA: 0x005DE9B0
 * Entry Ghidra:  005de9b0
 * Ghidra name:   FUN_005de9b0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005de9b0(void)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined local_8;
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_1c;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  FUN_005f4780(&local_1c,0x15);
  (**(code **)(*DAT_022fa2f0 + 0x348))(&local_1c);
  ___security_check_cookie_4();
  return;
}

