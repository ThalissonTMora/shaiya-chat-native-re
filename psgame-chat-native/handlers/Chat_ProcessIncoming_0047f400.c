/*
 * server/ps_game.exe — Chat_ProcessIncoming
 * Requested VA: 0x0047F400
 * Entry Ghidra:  0047f400
 * Ghidra name:   FUN_0047f400
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047f400(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  DWORD DVar4;
  char *pcVar5;
  undefined2 *unaff_EBX;
  int iVar6;
  void *pvVar7;
  int local_158;
  int local_154;
  void *local_150;
  undefined2 local_14c;
  undefined4 local_14a;
  byte local_146;
  undefined local_145 [16];
  byte local_135;
  byte local_134;
  undefined local_133 [135];
  undefined2 local_ac;
  char local_aa [21];
  byte local_95;
  undefined local_94 [128];
  uint local_14;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0054f741;
  local_c = ExceptionList;
  local_14 = DAT_0057f7c4 ^ (uint)&local_158;
  uVar3 = DAT_0057f7c4 ^ (uint)&stack0xfffffe9c;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x581c) != 0) {
    DVar4 = GetTickCount();
    if (DVar4 < *(uint *)(param_1 + 0x581c)) goto LAB_0047fc57;
    *(undefined4 *)(param_1 + 0x581c) = 0;
  }
  local_158 = 0;
  if (((*(void **)(param_1 + 0x5820) != (void *)0x0) &&
      (local_150 = *(void **)(param_1 + 0x5820), local_158 = FUN_00415480(&local_150),
      local_158 != 0)) && (5 < *(byte *)(local_158 + 0x5808))) {
    *(undefined4 *)(param_1 + 0x5820) = 0;
    local_158 = 0;
  }
  switch(*unaff_EBX) {
  case 0x1101:
    if (*(int *)(param_1 + 0x57f4) != 4) goto LAB_0047fc57;
    bVar1 = *(byte *)(unaff_EBX + 1);
    if (bVar1 < 0x81) {
      if (1 < bVar1) {
        if (*(char *)(param_1 + 0x58dc) == '\0') {
          local_14a = *(uint *)(param_1 + 0x128);
          local_14c = 0x1101;
          local_146 = bVar1;
          _memcpy(local_145,(void *)((int)unaff_EBX + 3),(uint)bVar1);
          FUN_004d5710(&local_14c,bVar1 + 7);
          if (local_158 != 0) {
            FUN_0047f260(param_1,0,0,(void *)((int)unaff_EBX + 3),*(undefined *)(unaff_EBX + 1));
          }
          FUN_0047f0e0(param_1,1);
        }
        else {
          pcVar5 = (char *)(param_1 + 0x184);
          local_14c = 0x1108;
          iVar6 = (int)&local_14a - (int)pcVar5;
          do {
            cVar2 = *pcVar5;
            pcVar5[iVar6] = cVar2;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          local_135 = bVar1;
          _memcpy(&local_134,(void *)((int)unaff_EBX + 3),(uint)bVar1);
          FUN_004d55b0(&local_14c,bVar1 + 0x18);
          if (local_158 != 0) {
            FUN_0047f260(param_1,0,0,(void *)((int)unaff_EBX + 3),*(undefined *)(unaff_EBX + 1));
          }
          FUN_0047f0e0(param_1,5);
          *(undefined *)(param_1 + 0x58dc) = 0;
        }
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1102:
    if (*(byte *)((int)unaff_EBX + 0x17) < 0x81) {
      if (1 < *(byte *)((int)unaff_EBX + 0x17)) {
        *(undefined *)(unaff_EBX + 0xb) = 0;
        local_150 = (void *)FUN_00414d40();
        if ((local_150 == (void *)0x0) ||
           (*(char *)((int)local_150 + 0x12d) != *(char *)(param_1 + 0x12d))) {
          local_154 = CONCAT13(local_154._3_1_,0x11106);
          FUN_004ed0e0(&local_154,3);
        }
        else {
          local_14c = 0x1102;
          pcVar5 = (char *)(param_1 + 0x184);
          local_14a = local_14a & 0xffffff00;
          iVar6 = 1 - (int)pcVar5;
          do {
            cVar2 = *pcVar5;
            pcVar5[(int)&local_14a + iVar6] = cVar2;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          local_134 = *(byte *)((int)unaff_EBX + 0x17);
          uVar3 = (uint)local_134;
          _memcpy(local_133,unaff_EBX + 0xc,uVar3);
          pvVar7 = local_150;
          FUN_004ed0e0(&local_14c,uVar3 + 0x19);
          if (local_158 != 0) {
            pcVar5 = (char *)((int)pvVar7 + 0x184);
            do {
              cVar2 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar2 != '\0');
            FUN_0047f260(param_1,(char *)((int)pvVar7 + 0x184),(int)pcVar5 - ((int)pvVar7 + 0x185),
                         unaff_EBX + 0xc,*(undefined *)((int)unaff_EBX + 0x17));
            pvVar7 = local_150;
          }
          pcVar5 = (char *)((int)pvVar7 + 0x184);
          local_14a = CONCAT31(local_14a._1_3_,1);
          iVar6 = 1 - (int)pcVar5;
          do {
            cVar2 = *pcVar5;
            pcVar5[(int)&local_14a + iVar6] = cVar2;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          FUN_004ed0e0(&local_14c,*(byte *)((int)unaff_EBX + 0x17) + 0x19);
          FUN_0047f190(param_1,pvVar7);
        }
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1103:
    bVar1 = *(byte *)(unaff_EBX + 1);
    if (bVar1 < 0x81) {
      if (1 < bVar1) {
        local_14c = 0x1103;
        pcVar5 = (char *)(param_1 + 0x184);
        iVar6 = (int)&local_14a - (int)pcVar5;
        do {
          cVar2 = *pcVar5;
          pcVar5[iVar6] = cVar2;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        local_135 = bVar1;
        _memcpy(&local_134,(void *)((int)unaff_EBX + 3),(uint)bVar1);
        FUN_004192f0(*(undefined *)(param_1 + 0x12d));
        if (local_158 != 0) {
          FUN_0047f260(param_1,0,0,(void *)((int)unaff_EBX + 3),*(undefined *)(unaff_EBX + 1));
        }
        FUN_0047f0e0(param_1,5);
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1104:
    if (*(byte *)(unaff_EBX + 1) < 0x81) {
      if (1 < *(byte *)(unaff_EBX + 1)) {
        FUN_00431eb0();
        local_4 = 0;
        if (*(int *)(param_1 + 0x1810) != 0) {
          FUN_00432530(*(int *)(param_1 + 0x1810),param_1 + 0x184,*(undefined *)(unaff_EBX + 1),0);
          if (local_158 != 0) {
            FUN_0047f260(param_1,0,0,(int)unaff_EBX + 3,*(undefined *)(unaff_EBX + 1));
          }
          FUN_0047f0e0(param_1,3);
        }
        if (local_150 != (void *)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)((int)local_150 + 0x5cc));
        }
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1105:
    FUN_0044e110(uVar3);
    local_4 = 1;
    if (*(int *)(param_1 + 0x17f4) != 0) {
      bVar1 = *(byte *)(unaff_EBX + 1);
      if (bVar1 < 0x81) {
        if (1 < bVar1) {
          local_14a = *(uint *)(param_1 + 0x128);
          pvVar7 = (void *)((int)unaff_EBX + 3);
          local_14c = 0x1105;
          local_150 = pvVar7;
          local_146 = bVar1;
          _memcpy(local_145,pvVar7,(uint)bVar1);
          FUN_0044e950();
          if (local_158 != 0) {
            FUN_0047f260(param_1,0,0,pvVar7,*(undefined *)(unaff_EBX + 1));
          }
LAB_0047f916:
          FUN_0047f0e0(param_1,4);
        }
      }
      else {
        FUN_004ec760(9,0);
      }
    }
    goto LAB_0047f922;
  case 0x1107:
    if ((*(int *)(param_1 + 0x57f4) != 4) ||
       (DVar4 = GetTickCount(), DVar4 < *(uint *)(param_1 + 0x58e4))) goto LAB_0047fc57;
    bVar1 = *(byte *)(unaff_EBX + 1);
    if (bVar1 < 0x81) {
      if (1 < bVar1) {
        local_14a = *(uint *)(param_1 + 0x128);
        local_14c = 0x1107;
        local_146 = bVar1;
        _memcpy(local_145,(void *)((int)unaff_EBX + 3),(uint)bVar1);
        FUN_004d5600(&local_14c,bVar1 + 7,_DAT_00574178);
        if (local_158 != 0) {
          FUN_0047f260(param_1,0,0,(void *)((int)unaff_EBX + 3),*(undefined *)(unaff_EBX + 1));
        }
        FUN_0047f0e0(param_1,6);
        DVar4 = GetTickCount();
        *(DWORD *)(param_1 + 0x58e4) = DVar4 + 30000;
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1108:
    if (*(byte *)(unaff_EBX + 1) < 0x81) {
      if (((1 < *(byte *)(unaff_EBX + 1)) && (*(char *)(param_1 + 0x58dc) != '\0')) &&
         (DVar4 = GetTickCount(), *(uint *)(param_1 + 0x58e0) <= DVar4)) {
        local_14c = 0x1108;
        pcVar5 = (char *)(param_1 + 0x184);
        iVar6 = (int)&local_14a - (int)pcVar5;
        do {
          cVar2 = *pcVar5;
          pcVar5[iVar6] = cVar2;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        local_135 = *(byte *)(unaff_EBX + 1);
        uVar3 = (uint)local_135;
        _memcpy(&local_134,(void *)((int)unaff_EBX + 3),uVar3);
        FUN_004d55b0(&local_14c,uVar3 + 0x18);
        if (local_158 != 0) {
          FUN_0047f260(param_1,0,0,(void *)((int)unaff_EBX + 3),*(undefined *)(unaff_EBX + 1));
        }
        FUN_0047f0e0(param_1,5);
        *(undefined *)(param_1 + 0x58dc) = 0;
        DVar4 = GetTickCount();
        *(DWORD *)(param_1 + 0x58e0) = DVar4 + 30000;
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1111:
    if (*(int *)(param_1 + 0x57f4) != 4) goto LAB_0047fc57;
    bVar1 = *(byte *)(unaff_EBX + 1);
    if (bVar1 < 0x81) {
      if (1 < bVar1) {
        local_ac = 0x1111;
        pcVar5 = (char *)(param_1 + 0x184);
        iVar6 = -(int)pcVar5;
        do {
          cVar2 = *pcVar5;
          pcVar5[(int)(local_aa + iVar6)] = cVar2;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        local_95 = bVar1;
        _memcpy(local_94,(void *)((int)unaff_EBX + 3),(uint)bVar1);
        FUN_00427090(*(undefined4 *)(param_1 + 0xe0),*(undefined *)(param_1 + 0x12d));
        if (local_158 != 0) {
          FUN_0047f260(param_1,0,0,(void *)((int)unaff_EBX + 3),*(undefined *)(unaff_EBX + 1));
        }
        FUN_0047f0e0(param_1,7);
      }
      goto LAB_0047fc57;
    }
    break;
  case 0x1112:
    FUN_0044e110(uVar3);
    local_4 = 2;
    iVar6 = *(int *)(param_1 + 0x17f4);
    if (((iVar6 != 0) && (*(char *)(iVar6 + 0x114) != '\0')) &&
       ((*(int *)(iVar6 + 0x18 + *(int *)(iVar6 + 0xc) * 8) == param_1 ||
        (*(int *)(iVar6 + 0x18 + *(int *)(iVar6 + 0x110) * 8) == param_1)))) {
      bVar1 = *(byte *)(unaff_EBX + 1);
      if (bVar1 < 0x81) {
        if (1 < bVar1) {
          local_14a = *(uint *)(param_1 + 0x128);
          local_150 = (void *)((int)unaff_EBX + 3);
          local_14c = 0x1112;
          local_146 = bVar1;
          _memcpy(local_145,local_150,(uint)bVar1);
          FUN_0044e950();
          if (local_158 != 0) {
            FUN_0047f260(param_1,0,0,local_150,*(undefined *)(unaff_EBX + 1));
          }
          goto LAB_0047f916;
        }
      }
      else {
        FUN_004ec760(9,0);
      }
    }
LAB_0047f922:
    if (local_154 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(local_154 + 0x118));
    }
    goto LAB_0047fc57;
  }
  FUN_004ec760(9,0);
LAB_0047fc57:
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
}

