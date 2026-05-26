/*
 * Game.exe — DrawText_ChatBox_Core
 * Requested VA: 0x00422B90
 * Entry Ghidra:  00422b90
 * Ghidra name:   FUN_00422b90
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00422b90(int param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  void *pvVar4;
  DWORD DVar5;
  int iVar6;
  int iVar7;
  size_t _Size;
  size_t _Size_00;
  void *local_a4c;
  int local_a48;
  int iStack_a40;
  undefined4 uStack_a3c;
  undefined4 uStack_a38;
  undefined4 uStack_a34;
  undefined4 uStack_a30;
  undefined4 uStack_a2c;
  undefined4 uStack_a28;
  undefined4 uStack_a24;
  undefined4 uStack_a20;
  undefined4 uStack_a1c;
  undefined4 uStack_a18;
  undefined4 uStack_a14;
  undefined4 uStack_a10;
  char acStack_a0c [260];
  char acStack_908 [260];
  char local_804 [2048];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_a4c;
  _memset(local_804,0,0x800);
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)(local_804 + -(int)param_2)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((((param_1 == 0x32) || (param_1 == 0x17)) || (param_1 == 0x18)) ||
     (((param_1 == 0x19 || (param_1 == 0x1c)) ||
      ((param_1 == 0x1d || ((param_1 == 0x1e || (param_1 == 0x30)))))))) {
    pvVar4 = operator_new(0x10c);
    if (pvVar4 != (void *)0x0) {
      _memset(pvVar4,0,0x104);
      *(undefined *)((int)pvVar4 + 0x108) = 0;
      if (param_1 == 0x30) {
        *(undefined *)((int)pvVar4 + 0x108) = 1;
      }
      else if (param_1 == 0x32) {
        *(undefined *)((int)pvVar4 + 0x108) = 0x32;
      }
      DVar5 = timeGetTime();
      *(DWORD *)((int)pvVar4 + 0x104) = DVar5;
      puVar2 = DAT_022aad34;
      pcVar3 = local_804;
      iVar7 = (int)pvVar4 - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar7] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_a4c = pvVar4;
      iVar7 = FUN_00450d10(DAT_022aad34,DAT_022aad34[1],&local_a4c);
      FUN_00437f40(1);
      puVar2[1] = iVar7;
      **(int **)(iVar7 + 4) = iVar7;
    }
    if (5 < DAT_022aad38) {
      FUN_00420d50(&local_a4c,*DAT_022aad34);
    }
  }
  iVar7 = DAT_007c0e58;
  local_a4c = (void *)0x0;
  if (((DAT_007c0e58 != 0) && (DAT_007ab0d4 != 1)) && (DAT_0090d1d8 == 0)) {
    _memset(acStack_908,0,0x104);
    if (iVar7 == 1) {
      FUN_00422310(param_2,acStack_908,&local_a4c,0,1);
    }
    else {
      FUN_00420c10(local_804,param_2);
    }
    if (local_a4c == (void *)0x2) {
      FUN_00420c10(local_804,acStack_908);
    }
  }
  iVar7 = local_a48;
  pvVar4 = (void *)0x0;
  uStack_a3c = 0;
  uStack_a38 = 0;
  uStack_a34 = 0;
  FUN_00420a70(local_804,&uStack_a3c);
  pcVar3 = (char *)&uStack_a3c;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (pcVar3 != (char *)((int)&uStack_a3c + 1)) {
    FUN_00420c10(iVar7 + 0x40,&uStack_a3c);
  }
  do {
    if (local_804[0] == '\0') {
LAB_00423132:
      ___security_check_cookie_4();
      return;
    }
    _Size_00 = 0;
    _Size = 0;
    pcVar3 = local_804 + (int)pvVar4;
    local_a4c = pvVar4;
    do {
      cVar1 = pcVar3[_Size_00];
      if (cVar1 == '\0') {
        _memset(acStack_a0c,0,0x104);
        _memcpy(acStack_a0c,local_804 + (int)local_a4c,_Size_00);
        pcVar3 = (char *)&uStack_a3c;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (pcVar3 != (char *)((int)&uStack_a3c + 1)) {
          uStack_a30 = 0;
          uStack_a2c = 0;
          uStack_a28 = 0;
          FUN_00420a70(acStack_a0c,&uStack_a30);
          pcVar3 = (char *)&uStack_a30;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          if (pcVar3 == (char *)((int)&uStack_a30 + 1)) {
            _sprintf(acStack_908,"%s%s",&uStack_a3c,acStack_a0c);
            FUN_00420c10(acStack_a0c,acStack_908);
          }
        }
        pcVar3 = acStack_a0c;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (pcVar3 != acStack_a0c + 1) {
          FUN_00422630(param_1,acStack_a0c);
        }
        *(undefined4 *)(local_a48 + 0x40) = 0;
        *(undefined4 *)(local_a48 + 0x44) = 0;
        *(undefined4 *)(local_a48 + 0x48) = 0;
        goto LAB_00423132;
      }
      if (cVar1 == ' ') {
        _Size = _Size_00;
      }
      FUN_00407f70(cVar1,&iStack_a40);
      _Size_00 = _Size_00 + iStack_a40;
      pvVar4 = (void *)((int)pvVar4 + iStack_a40);
      iVar6 = FUN_00575740(pcVar3,_Size_00,0);
      iVar7 = iStack_a40;
    } while (iVar6 < 0x145);
    if (DAT_007ab0d4 == 3) {
      _memset(acStack_a0c,0,0x104);
      iVar7 = iStack_a40;
      if (_Size == 0) {
        _memcpy(acStack_a0c,pcVar3,_Size_00 - iStack_a40);
        pcVar3 = (char *)&uStack_a3c;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (pcVar3 != (char *)((int)&uStack_a3c + 1)) {
          uStack_a24 = 0;
          uStack_a20 = 0;
          uStack_a1c = 0;
          FUN_00420a70(acStack_a0c,&uStack_a24);
          pcVar3 = (char *)&uStack_a24;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          if (pcVar3 == (char *)((int)&uStack_a24 + 1)) {
            _sprintf(acStack_908,"%s%s",&uStack_a3c,acStack_a0c);
            FUN_00420c10(acStack_a0c,acStack_908);
          }
        }
        goto LAB_0042303c;
      }
      _memcpy(acStack_a0c,pcVar3,_Size);
      pcVar3 = (char *)&uStack_a3c;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (pcVar3 != (char *)((int)&uStack_a3c + 1)) {
        uStack_a18 = 0;
        uStack_a14 = 0;
        uStack_a10 = 0;
        FUN_00420a70(acStack_a0c,&uStack_a18);
        pcVar3 = (char *)&uStack_a18;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (pcVar3 == (char *)((int)&uStack_a18 + 1)) {
          _sprintf(acStack_908,"%s%s",&uStack_a3c,acStack_a0c);
          FUN_00420c10(acStack_a0c,acStack_908);
        }
      }
      FUN_00422630(param_1,acStack_a0c);
      pvVar4 = (void *)(_Size + 1 + (int)local_a4c);
    }
    else {
      _memset(acStack_a0c,0,0x104);
      _memcpy(acStack_a0c,pcVar3,_Size_00 - iVar7);
      pcVar3 = (char *)&uStack_a3c;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (pcVar3 != (char *)((int)&uStack_a3c + 1)) {
        uStack_a30 = 0;
        uStack_a2c = 0;
        uStack_a28 = 0;
        FUN_00420a70(acStack_a0c,&uStack_a30);
        pcVar3 = (char *)&uStack_a30;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (pcVar3 == (char *)((int)&uStack_a30 + 1)) {
          _sprintf(acStack_908,"%s%s",&uStack_a3c,acStack_a0c);
          FUN_00420c10(acStack_a0c,acStack_908);
        }
      }
LAB_0042303c:
      pvVar4 = (void *)((int)pvVar4 - iVar7);
      FUN_00422630(param_1,acStack_a0c);
    }
    local_804[0] = local_804[(int)pvVar4];
  } while( true );
}

