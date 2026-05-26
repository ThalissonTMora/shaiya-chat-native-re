/*
 * Game.exe — ChatWindow_DrawShadedLine
 * VA solicitado: 0x00577860
 * Entry Ghidra:  00577860
 * Ghidra name:   FUN_00577860
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00577860(int param_1_00,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  size_t _Size;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  int local_818;
  int local_814;
  int local_810;
  int local_80c;
  int local_808;
  char local_804 [1024];
  undefined local_404 [1024];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_818;
  if (DAT_007b01e8 != 0) {
    local_804[0] = '\0';
    _memset(local_804 + 1,0,0x3ff);
    iVar6 = param_5;
    FUN_00565470(param_5);
    local_818 = param_1;
    _memset(local_804,0,0x400);
    pcVar2 = (char *)FUN_005652f0();
    iVar7 = param_2;
    pcVar3 = local_804;
    do {
      cVar1 = *pcVar2;
      *pcVar3 = cVar1;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (DAT_022b2924 == 0) {
      FUN_00573d70(param_1,param_2,*(undefined *)(param_1_00 + 0x3c0),
                   *(undefined *)(param_1_00 + 0x3c4),*(undefined *)(param_1_00 + 0x3c8),local_804,
                   iVar6);
      pcVar3 = local_804;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00575610(local_804,(int)pcVar3 - (int)(local_804 + 1),&local_810,iVar6);
      local_818 = local_810 + param_1;
    }
    else {
      iVar5 = 0;
      cVar1 = local_804[0];
      while (param_2 = iVar7, cVar1 != '\0') {
        pcVar3 = local_804 + iVar5;
        cVar1 = local_804[iVar5];
        pcVar2 = pcVar3;
        local_814 = iVar5;
        while (cVar1 != '\0') {
          FUN_00407f70(*pcVar2,&local_808);
          iVar7 = iVar5 + local_808;
          FUN_00575610(pcVar3,iVar7 - local_814,&local_810,param_5);
          if (DAT_022b2920 < local_810) {
            _memset(local_404,0,0x400);
            _memcpy(local_404,pcVar3,iVar5 - local_814);
            iVar7 = param_2;
            FUN_00573d70(local_818,param_2,*(undefined *)(param_1_00 + 0x3c0),
                         *(undefined *)(param_1_00 + 0x3c4),*(undefined *)(param_1_00 + 0x3c8),
                         local_404,param_5);
            param_2 = iVar7 + 3 + local_80c;
            local_818 = param_1;
            goto LAB_00577a5f;
          }
          pcVar2 = local_804 + iVar7;
          iVar5 = iVar7;
          cVar1 = local_804[iVar7];
        }
        _Size = iVar5 - local_814;
        if (0 < (int)_Size) {
          _memset(local_404,0,0x400);
          _memcpy(local_404,pcVar3,_Size);
          iVar7 = local_818;
          FUN_00573d70(local_818,param_2,*(undefined *)(param_1_00 + 0x3c0),
                       *(undefined *)(param_1_00 + 0x3c4),*(undefined *)(param_1_00 + 0x3c8),
                       local_404,param_5);
          local_818 = iVar7 + local_810;
        }
LAB_00577a5f:
        iVar7 = param_2;
        iVar6 = param_5;
        cVar1 = local_804[iVar5];
      }
    }
    iVar5 = param_4;
    iVar4 = param_3;
    if ((param_3 == 0) && (param_4 == 0)) {
      iVar5 = iVar7 + 0x14;
      iVar4 = local_818;
    }
    if ((((DAT_007ab0d4 != 2) && (DAT_007ab0d4 != 5)) && (DAT_007ab0d4 != 9)) && (DAT_007ab0d4 != 8)
       ) {
      FUN_005772c0(&local_818,&param_2,iVar4,iVar5,param_1);
      iVar7 = param_2;
    }
    _DAT_022b2960 = _DAT_022b2960 + _DAT_007c13bc;
    iVar5 = local_818;
    if (_DAT_022b2960 < _DAT_00748160) {
      iVar4 = 0;
      if (iVar6 == 1) {
        FUN_005741d0();
        uVar8 = FUN_005741c0();
        iVar4 = (int)((ulonglong)uVar8 >> 0x20) - (int)uVar8;
      }
      iVar5 = local_818;
      FUN_00573a00(param_1_00,local_818,iVar4 + iVar7,0xff,0xff,0xff,0,&DAT_007525f0);
    }
    if (1.0 < _DAT_022b2960 != NAN(_DAT_022b2960)) {
      _DAT_022b2960 = 0.0;
    }
    if ((((DAT_007ab0d4 == 2) || (DAT_007ab0d4 == 5)) ||
        ((DAT_007ab0d4 == 9 || (DAT_007ab0d4 == 8)))) &&
       (((DAT_022b29f4 != 0 || (DAT_022b29ec != iVar5 + 0xc)) || (DAT_022b29f0 != iVar7)))) {
      FUN_00564b90(iVar5 + 0xc,iVar7);
      DAT_022b29f4 = 0;
      DAT_022b29ec = iVar5 + 0xc;
      DAT_022b29f0 = iVar7;
    }
    if ((((DAT_007ab0d4 != 2) && (DAT_007ab0d4 != 5)) && (DAT_007ab0d4 != 9)) && (DAT_007ab0d4 != 8)
       ) {
      FUN_00575770(DAT_022b29e4,DAT_022b29e8,1);
    }
  }
  ___security_check_cookie_4();
  return;
}

