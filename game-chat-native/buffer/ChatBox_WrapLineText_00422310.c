/*
 * Game.exe — ChatBox_WrapLineText
 * VA solicitado: 0x00422310
 * Entry Ghidra:  00422310
 * Ghidra name:   FUN_00422310
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00422310(char *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 *local_110 [2];
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_110;
  local_110[0] = param_2;
  _memset(local_108,0,0x104);
  iVar2 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_108 + iVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  uVar4 = 0;
  *param_3 = 0;
  if (local_108[0] != '\0') {
    while( true ) {
      iVar2 = FUN_00421d80(local_108,uVar4,param_3,param_4,param_5);
      uVar4 = uVar4 + iVar2;
      param_2 = local_110[0];
      if (*param_3 != 0) break;
      pcVar3 = local_108;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (((uint)((int)pcVar3 - (int)(local_108 + 1)) <= uVar4) || (local_108[uVar4] == '\0'))
      break;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    pcVar3 = local_108;
    for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      param_2 = param_2 + 1;
    }
    *(undefined2 *)param_2 = *(undefined2 *)pcVar3;
    *(char *)((int)param_2 + 2) = pcVar3[2];
  }
  ___security_check_cookie_4();
  return;
}

