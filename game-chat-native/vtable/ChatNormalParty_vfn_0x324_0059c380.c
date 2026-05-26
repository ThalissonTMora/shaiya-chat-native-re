/*
 * Game.exe — ChatNormalParty_vfn_0x324
 * VA solicitado: 0x0059C380
 * Entry Ghidra:  0059c380
 * Ghidra name:   FUN_0059c380
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: vtable
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059c380(char param_1,char param_2,int param_3,undefined4 param_4,undefined *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_50c;
  undefined local_508 [260];
  undefined local_404 [1024];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_50c;
  if (param_2 != '\0') {
    if (DAT_022aa7fc == 0) {
      iVar2 = DAT_022aa710 - DAT_022aa70c >> 2;
      iVar4 = 0;
      if (0 < iVar2) {
        iVar3 = DAT_022aa70c;
        if (iVar2 < 1) goto LAB_0059c465;
        do {
          _DAT_022aa718 = (int *)(iVar3 + iVar4 * 4);
          piVar1 = (int *)*_DAT_022aa718;
          if ((piVar1 != (int *)0x0) && (*piVar1 == param_3)) {
            FUN_00420c10(&DAT_007c2338,piVar1 + 1);
            FUN_00420c10(&DAT_007c1d38,param_5);
            FUN_00423150(0x23,0x161,0x34);
            iVar3 = DAT_022aa70c;
          }
LAB_0059c465:
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_022aa710 - iVar3 >> 2);
      }
    }
    else {
      iVar2 = FUN_004ed790(param_3);
      if (iVar2 != 0) {
        FUN_00420c10(&DAT_007c2338,iVar2 + 4);
        FUN_00420c10(&DAT_007c1d38,param_5);
        FUN_00423150(0x23,0x161,0x34);
      }
    }
    goto LAB_0059c62d;
  }
  iVar2 = FUN_00452b10(param_3);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x2f4) == 0)) goto LAB_0059c62d;
  if (param_1 == '\0') {
    if (*(char *)(iVar2 + 0x2b7) == DAT_022aa816) {
      if ((DAT_007ab0d4 == 1) || (DAT_007c0e58 != 1)) {
LAB_0059c53f:
        FUN_004126d0(param_5);
      }
      else {
        _memset(local_404,0,0x400);
        local_50c = 0;
        FUN_00422310(param_5,local_404,&local_50c,0,1);
        if (local_50c == 0) goto LAB_0059c53f;
      }
      if (iVar2 == -0x10c) goto LAB_0059c62d;
    }
    else {
      if (param_5 == (undefined *)0x0) goto LAB_0059c62d;
      if (DAT_0090d1d8 == 0) {
        FUN_00421750(param_5,local_508);
      }
      else {
        FUN_00420c10(local_508,param_5);
      }
      if ((DAT_007ab0d4 == 1) || (DAT_007c0e58 != 1)) {
LAB_0059c5f0:
        FUN_004126d0(local_508);
      }
      else {
        _memset(local_404,0,0x400);
        local_50c = 0;
        FUN_00422310(local_508,local_404,&local_50c,0,1);
        if (local_50c == 0) goto LAB_0059c5f0;
      }
      if (iVar2 == -0x10c) goto LAB_0059c62d;
      param_5 = local_508;
    }
    _sprintf(&DAT_022eed40,"%s : %s",iVar2 + 0x10c,param_5);
    uVar5 = 0x22;
  }
  else {
    FUN_004126d0(param_5);
    if (iVar2 + 0x10c == 0) goto LAB_0059c62d;
    _sprintf(&DAT_022eed40,"%s : %s",iVar2 + 0x10c,param_5);
    uVar5 = 0x29;
  }
  FUN_00422b90(uVar5,&DAT_022eed40,0x34);
LAB_0059c62d:
  ___security_check_cookie_4();
  return;
}

