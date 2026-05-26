/*
 * Game.exe — Handler_Chat_LongText_1112
 * VA solicitado: 0x005E88D0
 * Entry Ghidra:  005e88d0
 * Ghidra name:   FUN_005e88d0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e88d0(void)

{
  undefined auStack_40c [3];
  undefined local_409;
  undefined local_408 [4];
  undefined local_404 [1024];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)auStack_40c;
  _memset(local_404,0,0x400);
  FUN_005f4700(local_408,4);
  FUN_005f4700(&local_409,1);
  FUN_005f4780(local_404,local_409);
  (**(code **)(*DAT_022fa2f0 + 0x578))(local_404);
  ___security_check_cookie_4();
  return;
}

