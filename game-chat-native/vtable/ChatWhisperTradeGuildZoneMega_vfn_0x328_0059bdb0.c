/*
 * Game.exe — ChatWhisperTradeGuildZoneMega_vfn_0x328
 * VA solicitado: 0x0059BDB0
 * Entry Ghidra:  0059bdb0
 * Ghidra name:   FUN_0059bdb0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: vtable
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059bdb0(char param_1,char param_2,char param_3,byte *param_4,undefined4 param_5,
                 undefined4 param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  undefined4 uVar10;
  undefined auStack_110 [3];
  char local_10d;
  undefined4 local_10c;
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)auStack_110;
  local_10c = param_6;
  if (param_1 != '\0') {
    if (param_3 == '\0') {
      FUN_00420c10(&DAT_007c2338,&DAT_009144ce);
      FUN_00420c10(&DAT_007c1d38,local_10c);
      FUN_00423150(0x24,0x162,0x34);
      ___security_check_cookie_4();
      return;
    }
    goto switchD_0059bebc_caseD_6;
  }
  iVar7 = DAT_022aa7bc - (int)DAT_022aa7b8 >> 2;
  iVar8 = 0;
  local_10d = '\x01';
  if (0 < iVar7) {
    piVar6 = DAT_022aa7b8;
    if (iVar7 < 1) goto LAB_0059be99;
    do {
      _DAT_022aa7c4 = piVar6;
      if (*piVar6 != 0) {
        pbVar2 = (byte *)(*piVar6 + 4);
        pbVar5 = param_4;
        do {
          bVar1 = *pbVar2;
          bVar9 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_0059be90:
            iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_0059be95;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar9 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_0059be90;
          pbVar2 = pbVar2 + 2;
          pbVar5 = pbVar5 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_0059be95:
        if (iVar3 == 0) {
          local_10d = '\0';
          break;
        }
      }
LAB_0059be99:
      iVar8 = iVar8 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar8 < iVar7);
  }
  switch(param_3) {
  case '\0':
    if (DAT_007c0e84 != 0) {
      local_10d = '\0';
    }
    if (((param_2 != '\0') || (local_10d != '\0')) && (param_4 != (byte *)0x0)) {
      FUN_00420c10(&DAT_007c2338,param_4);
      FUN_00420c10(&DAT_007c1d38,local_10c);
      FUN_00423150(0x24,0x162,0x34);
      if (((DAT_007c4918 != (int *)0x0) && (*DAT_007c4918 != 0)) &&
         (*(int *)(*DAT_007c4918 + 0x1a4) != 0)) {
        FUN_0047f970(param_4);
        ___security_check_cookie_4();
        return;
      }
    }
    break;
  case '\x01':
    if ((param_4 != (byte *)0x0) && ((param_2 != '\0' || (local_10d != '\0')))) {
      FUN_00420c10(&DAT_007c2338,param_4);
      FUN_00420c10(&DAT_007c1d38,local_10c);
      FUN_00423150(0x26,0x163,0x34);
      ___security_check_cookie_4();
      return;
    }
    break;
  case '\x02':
    if ((param_4 != (byte *)0x0) && ((param_2 != '\0' || (local_10d != '\0')))) {
      FUN_00420c10(&DAT_007c2338,param_4);
      FUN_00420c10(&DAT_007c1d38,local_10c);
      FUN_00423150(0x25,0x172,0x34);
      ___security_check_cookie_4();
      return;
    }
    break;
  case '\x03':
    if ((param_4 != (byte *)0x0) && ((param_2 != '\0' || (local_10d != '\0')))) {
      FUN_00420c10(&DAT_007c2338,param_4);
      FUN_00420c10(&DAT_007c1d38,local_10c);
      FUN_00423150(0x30,0x1e1,0x34);
      ___security_check_cookie_4();
      return;
    }
    break;
  case '\x04':
    iVar7 = FUN_00452b90(*(undefined4 *)param_4);
    if ((iVar7 == 0) ||
       (puVar4 = (undefined4 *)FUN_0046cca0(*(undefined2 *)(iVar7 + 0x2c)),
       puVar4 == (undefined4 *)0x0)) break;
    _sprintf(local_108,"%s : %s",*puVar4,local_10c);
    uVar10 = 0x28;
    goto LAB_0059c111;
  case '\x05':
    iVar7 = FUN_00452b90(*(undefined4 *)param_4);
    if ((iVar7 == 0) ||
       (puVar4 = (undefined4 *)FUN_0046cca0(*(undefined2 *)(iVar7 + 0x2c)),
       puVar4 == (undefined4 *)0x0)) break;
    _sprintf(local_108,"%s : %s",*puVar4,local_10c);
    uVar10 = 0x30;
LAB_0059c111:
    FUN_00422b90(uVar10,local_108,0x34);
  }
switchD_0059bebc_caseD_6:
  ___security_check_cookie_4();
  return;
}

