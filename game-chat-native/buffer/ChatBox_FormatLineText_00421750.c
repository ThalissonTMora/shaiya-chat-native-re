/*
 * Game.exe — ChatBox_FormatLineText
 * VA solicitado: 0x00421750
 * Entry Ghidra:  00421750
 * Ghidra name:   FUN_00421750
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_00421750(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  void *pvVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  undefined local_9;
  int local_8;
  char *local_4;
  
  iVar9 = 0;
  local_9 = 0;
  _memset(param_2,0,0x104);
  local_8 = 0;
  pcVar5 = param_2;
  if (*param_1 == '\0') {
    return;
  }
  do {
    bVar3 = DAT_022aacf1;
    if (DAT_022aacf1 < DAT_022aacf0) {
      bVar3 = DAT_022aacf0;
    }
    uVar8 = 1;
    switch(bVar3) {
    case 1:
      iVar4 = _rand();
      uVar8 = iVar4 % 3;
      break;
    case 2:
      iVar4 = _rand();
      uVar8 = (uint)(0x3c < iVar4 % 100);
      break;
    case 3:
      uVar8 = 0;
    }
    pcVar7 = param_1 + local_8;
    iVar4 = FUN_00407f70(*pcVar7,&local_4);
    pcVar2 = local_4;
    if (iVar4 == 0) {
      iVar4 = iVar9 + 1;
      if (0x102 < iVar4) {
        return;
      }
      if (uVar8 == 0) {
        param_2[iVar9] = *pcVar7;
      }
      else {
        param_2[iVar9] = '~';
      }
      local_8 = local_8 + 1;
    }
    else {
      if (uVar8 == 0) {
        if (0x102 < (int)(local_4 + iVar9)) {
          return;
        }
        _memcpy(param_2 + iVar9,pcVar7,(size_t)local_4);
        local_8 = local_8 + (int)pcVar2;
        iVar4 = iVar9 + (int)pcVar2;
        pcVar5 = pcVar2;
        goto LAB_004219d7;
      }
      switch(local_9) {
      case 0:
        pcVar5 = (char *)FUN_00420db0(0x13e4);
        pcVar7 = pcVar5 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        break;
      case 1:
        pcVar5 = (char *)FUN_00420db0(0x13e5);
        pcVar7 = pcVar5 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        break;
      case 2:
        pcVar5 = (char *)FUN_00420db0(0x13e6);
        pcVar7 = pcVar5 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        break;
      case 3:
        pcVar5 = (char *)FUN_00420db0(0x13e7);
        pcVar7 = pcVar5 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        break;
      default:
        goto switchD_00421849_caseD_4;
      }
      pcVar5 = pcVar5 + -(int)pcVar7;
switchD_00421849_caseD_4:
      if (0x102 < (int)(pcVar5 + iVar9)) {
        if (0x102 < iVar9) {
          return;
        }
        _memset(param_2 + iVar9,0x7e,0x103 - iVar9);
        return;
      }
      switch(local_9) {
      case 0:
        pcVar7 = pcVar5;
        pvVar6 = (void *)FUN_00420db0(0x13e4);
        _memcpy(param_2 + iVar9,pvVar6,(size_t)pcVar7);
        local_8 = local_8 + (int)local_4;
        local_9 = 1;
        iVar4 = iVar9 + (int)pcVar5;
        break;
      case 1:
        pcVar7 = pcVar5;
        pvVar6 = (void *)FUN_00420db0(0x13e5);
        _memcpy(param_2 + iVar9,pvVar6,(size_t)pcVar7);
        local_8 = local_8 + (int)local_4;
        local_9 = 2;
        iVar4 = iVar9 + (int)pcVar5;
        break;
      case 2:
        pcVar7 = pcVar5;
        pvVar6 = (void *)FUN_00420db0(0x13e6);
        _memcpy(param_2 + iVar9,pvVar6,(size_t)pcVar7);
        local_8 = local_8 + (int)local_4;
        local_9 = 3;
        iVar4 = iVar9 + (int)pcVar5;
        break;
      case 3:
        pcVar7 = pcVar5;
        pvVar6 = (void *)FUN_00420db0(0x13e7);
        _memcpy(param_2 + iVar9,pvVar6,(size_t)pcVar7);
        local_9 = 0;
      default:
        local_8 = local_8 + (int)local_4;
        iVar4 = iVar9 + (int)pcVar5;
      }
    }
LAB_004219d7:
    iVar9 = iVar4;
    if (param_1[local_8] == '\0') {
      return;
    }
  } while( true );
}

