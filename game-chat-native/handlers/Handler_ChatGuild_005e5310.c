/*
 * Game.exe — Handler_ChatGuild
 * VA solicitado: 0x005E5310
 * Entry Ghidra:  005e5310
 * Ghidra name:   FUN_005e5310
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_005e5310(void)

{
  uint local_a0 [6];
  undefined local_88;
  undefined local_84 [128];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_a0;
  local_a0[1] = 0;
  local_a0[2] = 0;
  local_a0[3] = 0;
  local_a0[4] = 0;
  local_a0[5] = 0;
  local_88 = 0;
  FUN_005f4780(local_a0 + 1,0x15);
  FUN_005f4700(local_a0,1);
  _memset(local_84,0,0x80);
  FUN_005f4780(local_84,local_a0[0] & 0xff);
  (**(code **)(*DAT_022fa2f0 + 0x328))(0,0,2,local_a0 + 1,local_a0[0],local_84);
  ___security_check_cookie_4();
  return;
}

