/*
 * Game.exe — NativeText_Draw
 * VA solicitado: 0x00573C00
 * Entry Ghidra:  00573c00
 * Ghidra name:   FUN_00573c00
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00573c00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,char *param_6)

{
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_104;
  _vsprintf(local_104,param_6,&stack0x0000001c);
  FUN_0057d570(param_1 + 0x3a8,local_104,param_2,param_3,0,0,param_4);
  ___security_check_cookie_4();
  return;
}

