/*
 * Game.exe — ChatWindow_DrawChannelLabel
 * Requested VA: 0x00575E90
 * Entry Ghidra:  00575e90
 * Ghidra name:   FUN_00575e90
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00575e90(undefined4 param_1,undefined4 param_2,byte param_3,byte param_4,byte param_5,
                 int param_6,int param_7,char *param_8)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int local_418;
  int local_414;
  int local_410;
  int local_40c [2];
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_418;
  _memset(local_404,0,0x400);
  pcVar2 = param_8;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_404 + -(int)param_8)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = 0;
  do {
    if (local_404[0] == '\0') {
LAB_00575f46:
      iVar4 = local_418 + 0x3a4;
      if ((((*(int *)(local_418 + 0x3a4) == 0) || (param_6 != 1)) &&
          ((iVar4 = local_418 + 0x3a0, *(int *)(local_418 + 0x3a0) == 0 || (param_6 != 2)))) &&
         ((iVar4 = local_418 + 0x39c, *(int *)(local_418 + 0x39c) == 0 || (param_6 != 3)))) {
        uVar3 = ((param_3 | 0xffffff00) << 8 | (uint)param_4) << 8 | (uint)param_5;
        iVar4 = local_418 + 0x3a8;
      }
      else {
        uVar3 = ((param_3 | 0xffffff00) << 8 | (uint)param_4) << 8 | (uint)param_5;
      }
      FUN_0057d570(iVar4,param_8,param_1,param_2,0,0,uVar3);
      ___security_check_cookie_4();
      return;
    }
    local_414 = iVar4;
    FUN_00407f70(local_404[iVar4],&local_410);
    iVar4 = iVar4 + local_410;
    FUN_00575610(local_404,iVar4,local_40c,param_6);
    if (param_7 < local_40c[0]) {
      param_8[local_414] = '\0';
      goto LAB_00575f46;
    }
    local_404[0] = local_404[iVar4];
  } while( true );
}

