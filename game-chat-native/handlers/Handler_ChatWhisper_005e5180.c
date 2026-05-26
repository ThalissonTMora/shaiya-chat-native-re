/*
 * Game.exe — Handler_ChatWhisper
 * VA solicitado: 0x005E5180
 * Entry Ghidra:  005e5180
 * Ghidra name:   FUN_005e5180
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5180(void)

{
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined local_88;
  undefined local_84 [128];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_a4;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  FUN_005f4700(&local_a0,1);
  FUN_005f4780(&local_9c,0x15);
  FUN_005f4700(&local_a4,1);
  _memset(local_84,0,0x80);
  FUN_005f4780(local_84,local_a4 & 0xff);
  (**(code **)(*DAT_022fa2f0 + 0x328))(local_a0,0,0,&local_9c,local_a4,local_84);
  ___security_check_cookie_4();
  return;
}

