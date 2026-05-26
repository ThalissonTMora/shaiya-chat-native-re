/*
 * Game.exe — Network_GameSocketWndProc
 * VA solicitado: 0x005F1810
 * Entry Ghidra:  005f1810
 * Ghidra name:   FUN_005f1810
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: recv
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005f1810(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined param_4,
                 undefined param_5,char param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined auStack_2014 [4];
  undefined2 local_2010;
  undefined4 local_200e;
  undefined4 local_200a;
  undefined4 local_2006;
  undefined4 local_2002;
  undefined4 local_1ffe;
  undefined local_1ffa;
  undefined4 local_1ff9 [64];
  undefined local_1ef8;
  undefined local_1ef7;
  char local_1ef6;
  undefined4 local_1ef5;
  uint local_c;
  
  local_c = DAT_007b4dd0 ^ (uint)auStack_2014;
  if (param_6 == '\0') {
    param_4 = 0;
    param_6 = '\0';
    param_5 = 0;
  }
  local_2010 = 0x1d0c;
  local_200e = *param_1;
  local_200a = param_1[1];
  local_2006 = param_1[2];
  local_2002 = param_1[3];
  local_1ffe = param_1[4];
  local_1ffa = *(undefined *)(param_1 + 5);
  puVar2 = local_1ff9;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined *)puVar2 = *(undefined *)param_2;
  local_1ef8 = param_4;
  local_1ef5 = param_3;
  local_1ef7 = param_5;
  local_1ef6 = param_6;
  FUN_005ea9a0(&local_2010,0x11f);
  ___security_check_cookie_4();
  return;
}

