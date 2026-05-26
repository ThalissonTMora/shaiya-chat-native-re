/*
 * Game.exe — ChatWindow_MouseWheelScroll
 * VA solicitado: 0x0047BEA0
 * Entry Ghidra:  0047bea0
 * Ghidra name:   FUN_0047bea0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_0047bea0(int param_1_00,char *param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  byte *pbVar9;
  undefined **ppuVar10;
  bool bVar11;
  int local_18c;
  byte local_188 [260];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_18c;
  _memset(local_188,0,0x104);
  pcVar3 = (char *)FUN_00420db0(0x19cd);
  pcVar5 = pcVar3 + 1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  sVar4 = (int)pcVar3 - (int)pcVar5;
  pcVar5 = (char *)FUN_00420db0(0x19cd);
  iVar6 = _strncmp(param_1,pcVar5,sVar4);
  if (iVar6 == 0) {
    if ((DAT_022aa730 == 0) || (DAT_022aa730 == 1)) {
      uVar7 = FUN_00420db0(0x19cd);
      _sprintf(local_84,"%s ",uVar7);
      pcVar5 = local_84;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar6 = (int)pcVar5 - (int)(local_84 + 1);
      iVar8 = _strncmp(param_1,local_84,iVar6 - 1);
      if (iVar8 == 0) {
        pcVar5 = param_1 + iVar6 + -1;
      }
      else {
        pcVar5 = param_1 + 6;
      }
      FUN_0047a9b0(local_188,pcVar5);
      ppuVar10 = &PTR_00746cf4;
      pbVar9 = local_188;
      do {
        bVar2 = *pbVar9;
        bVar11 = bVar2 < *(byte *)ppuVar10;
        if (bVar2 != *(byte *)ppuVar10) {
LAB_0047bfb2:
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0047bfb7;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar9[1];
        bVar11 = bVar2 < *(byte *)((int)ppuVar10 + 1);
        if (bVar2 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0047bfb2;
        pbVar9 = pbVar9 + 2;
        ppuVar10 = (undefined **)((int)ppuVar10 + 2);
      } while (bVar2 != 0);
      iVar8 = 0;
LAB_0047bfb7:
      if (iVar8 == 0) {
        param_1 = param_1 + iVar6;
        iVar6 = -(int)param_1;
        do {
          cVar1 = *param_1;
          param_1[(int)(local_188 + iVar6)] = cVar1;
          param_1 = param_1 + 1;
        } while (cVar1 != '\0');
      }
      pbVar9 = local_188;
      do {
        bVar2 = *pbVar9;
        pbVar9 = pbVar9 + 1;
      } while (bVar2 != 0);
      if (pbVar9 != local_188 + 1) {
        FUN_005f1560(local_188);
      }
    }
  }
  else {
    iVar6 = __strnicmp(param_1,"/chatcolor",10);
    if (iVar6 != 0) {
      pcVar3 = (char *)FUN_00420db0(0x19cf);
      pcVar5 = pcVar3 + 1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      sVar4 = (int)pcVar3 - (int)pcVar5;
      pcVar5 = (char *)FUN_00420db0(0x19cf);
      iVar6 = _strncmp(param_1,pcVar5,sVar4);
      if (iVar6 != 0) {
        iVar6 = __strnicmp(param_1,"/chatcolor off",10);
        if (iVar6 != 0) {
          pcVar3 = (char *)FUN_00420db0(0x19d0);
          pcVar5 = pcVar3 + 1;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          sVar4 = (int)pcVar3 - (int)pcVar5;
          pcVar5 = (char *)FUN_00420db0(0x19d0);
          iVar6 = _strncmp(param_1,pcVar5,sVar4);
          if (iVar6 != 0) goto LAB_0047c16c;
        }
        *(undefined4 *)(param_1_00 + 0x75c8) = 0;
        FUN_00423150(0x16,0x1e4,0x34);
        goto LAB_0047c16c;
      }
    }
    local_18c = 0;
    iVar6 = __strnicmp(param_1,"/chatcolor",10);
    if (iVar6 == 0) {
      param_1 = param_1 + 10;
    }
    else {
      pcVar3 = (char *)FUN_00420db0(0x19cf);
      pcVar5 = pcVar3 + 1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      param_1 = param_1 + ((int)pcVar3 - (int)pcVar5);
    }
    FID_conflict__sscanf(param_1," %d",&local_18c);
    if (local_18c < 9) {
      *(int *)(param_1_00 + 0x75c8) = local_18c;
      if (1 < local_18c) {
        *(int *)(param_1_00 + 0x75c8) = local_18c + 1;
      }
      if (0 < local_18c) {
        FUN_00423150(0x16,0x1e3,0x34);
      }
    }
    if ((local_18c == 0) || (8 < local_18c)) {
      FUN_00423150(0x16,0x1e4,0x34);
      *(undefined4 *)(param_1_00 + 0x75c8) = 0;
    }
  }
LAB_0047c16c:
  ___security_check_cookie_4();
  return;
}

