/*
 * Game.exe — Handler_Chat_110B
 * VA solicitado: 0x005E5740
 * Entry Ghidra:  005e5740
 * Ghidra name:   FUN_005e5740
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e5740(void)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_28;
  local_28 = 0;
  FUN_005f4700(&local_28,4);
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  FUN_005f4780(&local_24,0x20);
  local_8 = local_8 & 0xffffff;
  (**(code **)(*DAT_022fa2f0 + 0x350))(local_28,&local_24);
  ___security_check_cookie_4();
  return;
}

