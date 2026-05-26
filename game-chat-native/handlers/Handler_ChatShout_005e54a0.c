/*
 * Game.exe — Handler_ChatShout
 * VA solicitado: 0x005E54A0
 * Entry Ghidra:  005e54a0
 * Ghidra name:   FUN_005e54a0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e54a0(void)

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
  (**(code **)(*DAT_022fa2f0 + 0x32c))(local_88,local_8c,local_84);
  ___security_check_cookie_4();
  return;
}

