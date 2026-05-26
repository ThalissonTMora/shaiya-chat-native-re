/*
 * server/ps_game.exe — AdminChat_DefaultKick
 * VA solicitado: 0x004805A6
 * Entry Ghidra:  0047fd10
 * Ghidra name:   FUN_0047fd10
 * NOTA: VA dentro da função (landmark/hook), não é entry point.
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_0047fd10(undefined2 *param_1_00,int param_1)

{
  void *_Src;
  byte bVar1;
  char cVar2;
  undefined uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  DWORD DVar7;
  int iVar8;
  char *pcVar9;
  undefined auStack_17c [4];
  int local_178;
  void *pvStack_174;
  int iStack_170;
  undefined2 uStack_16c;
  undefined4 uStack_16a;
  byte bStack_166;
  undefined auStack_165 [16];
  byte bStack_155;
  byte bStack_154;
  undefined auStack_153 [135];
  undefined2 uStack_cc;
  char acStack_ca [22];
  undefined2 uStack_b4;
  undefined uStack_b2;
  char acStack_b1 [21];
  byte bStack_9c;
  undefined auStack_9b [135];
  uint local_14;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00550921;
  local_c = ExceptionList;
  local_14 = DAT_0057f7c4 ^ (uint)auStack_17c;
  uVar6 = DAT_0057f7c4 ^ (uint)&stack0xfffffe74;
  ExceptionList = &local_c;
  if (10 < *(byte *)(param_1 + 0x5808)) {
    FUN_004efdc0(DAT_00587970 + 0xe0,"Error AdminChat : %s %d",param_1 + 0x184,
                 *(byte *)(param_1 + 0x5808));
    goto switchD_0047fdff_caseD_a;
  }
  if (*(int *)(param_1 + 0x581c) != 0) {
    DVar7 = GetTickCount();
    if (DVar7 < *(uint *)(param_1 + 0x581c)) goto LAB_004805b9;
    *(undefined4 *)(param_1 + 0x581c) = 0;
  }
  local_178 = 0;
  if (((*(int *)(param_1 + 0x5820) != 0) &&
      (local_178 = *(int *)(param_1 + 0x5820), local_178 = FUN_00415480(&local_178), local_178 != 0)
      ) && (5 < *(byte *)(local_178 + 0x5808))) {
    *(undefined4 *)(param_1 + 0x5820) = 0;
    local_178 = 0;
  }
  switch(*param_1_00) {
  case 0xf101:
    if (*(int *)(param_1 + 0x57f4) != 4) goto LAB_004805b9;
    bVar1 = *(byte *)(param_1_00 + 1);
    if (bVar1 < 0x81) {
      if (1 < bVar1) {
        if (*(char *)(param_1 + 0x58dc) == '\0') {
          uStack_16a = *(uint *)(param_1 + 0x128);
          uStack_16c = 0xf101;
          bStack_166 = bVar1;
          _memcpy(auStack_165,(void *)((int)param_1_00 + 3),(uint)bVar1);
          FUN_004d5320(bVar1 + 7);
          if (local_178 != 0) {
            FUN_0047f260(param_1,0,0,(void *)((int)param_1_00 + 3),*(undefined *)(param_1_00 + 1));
          }
          FUN_0047f0e0(param_1,1);
        }
        else {
          pcVar9 = (char *)(param_1 + 0x184);
          uStack_16c = 0x1108;
          iVar8 = (int)&uStack_16a - (int)pcVar9;
          do {
            cVar2 = *pcVar9;
            pcVar9[iVar8] = cVar2;
            pcVar9 = pcVar9 + 1;
          } while (cVar2 != '\0');
          bStack_155 = bVar1;
          _memcpy(&bStack_154,(void *)((int)param_1_00 + 3),(uint)bVar1);
          FUN_004d55b0(&uStack_16c,bVar1 + 0x18);
          if (local_178 != 0) {
            FUN_0047f260(param_1,0,0,(void *)((int)param_1_00 + 3),*(undefined *)(param_1_00 + 1));
          }
          FUN_0047f0e0(param_1,5);
          *(undefined *)(param_1 + 0x58dc) = 0;
        }
      }
      goto LAB_004805b9;
    }
    break;
  case 0xf102:
    if (*(byte *)((int)param_1_00 + 0x17) < 0x81) {
      if (1 < *(byte *)((int)param_1_00 + 0x17)) {
        *(undefined *)(param_1_00 + 0xb) = 0;
        iStack_170 = FUN_00414d40();
        if ((iStack_170 == 0) || (*(char *)(iStack_170 + 0x12d) != *(char *)(param_1 + 0x12d))) {
          pvStack_174 = (void *)CONCAT13(pvStack_174._3_1_,0x11106);
          FUN_004ed0e0(&pvStack_174,3);
        }
        else {
          uStack_16c = 0xf102;
          pcVar9 = (char *)(param_1 + 0x184);
          uStack_16a = uStack_16a & 0xffffff00;
          iVar8 = 1 - (int)pcVar9;
          do {
            cVar2 = *pcVar9;
            pcVar9[(int)&uStack_16a + iVar8] = cVar2;
            pcVar9 = pcVar9 + 1;
          } while (cVar2 != '\0');
          bStack_154 = *(byte *)((int)param_1_00 + 0x17);
          uVar6 = (uint)bStack_154;
          _memcpy(auStack_153,param_1_00 + 0xc,uVar6);
          iVar8 = iStack_170;
          FUN_004ed0e0(&uStack_16c,uVar6 + 0x19);
          if (local_178 != 0) {
            pcVar9 = (char *)(iVar8 + 0x184);
            do {
              cVar2 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
            FUN_0047f260(param_1,(char *)(iVar8 + 0x184),(int)pcVar9 - (iVar8 + 0x185),
                         param_1_00 + 0xc,*(undefined *)((int)param_1_00 + 0x17));
            iVar8 = iStack_170;
          }
          pcVar9 = (char *)(iVar8 + 0x184);
          uStack_16a = CONCAT31(uStack_16a._1_3_,1);
          iVar5 = 1 - (int)pcVar9;
          do {
            cVar2 = *pcVar9;
            pcVar9[(int)&uStack_16a + iVar5] = cVar2;
            pcVar9 = pcVar9 + 1;
          } while (cVar2 != '\0');
          FUN_004ed0e0(&uStack_16c,*(byte *)((int)param_1_00 + 0x17) + 0x19);
          FUN_0047f190(param_1,iVar8);
        }
      }
      goto LAB_004805b9;
    }
    break;
  case 0xf103:
    bVar1 = *(byte *)(param_1_00 + 1);
    if (bVar1 < 0x81) {
      if (1 < bVar1) {
        uStack_16c = 0xf103;
        pcVar9 = (char *)(param_1 + 0x184);
        iVar8 = (int)&uStack_16a - (int)pcVar9;
        do {
          cVar2 = *pcVar9;
          pcVar9[iVar8] = cVar2;
          pcVar9 = pcVar9 + 1;
        } while (cVar2 != '\0');
        _Src = (void *)((int)param_1_00 + 3);
        pvStack_174 = _Src;
        bStack_155 = bVar1;
        _memcpy(&bStack_154,_Src,(uint)bVar1);
        FUN_00419120();
        if (local_178 != 0) {
          FUN_0047f260(param_1,0,0,_Src,*(undefined *)(param_1_00 + 1));
        }
        FUN_0047f0e0(param_1,5);
      }
      goto LAB_004805b9;
    }
    break;
  case 0xf104:
    if (*(byte *)(param_1_00 + 1) < 0x81) {
      if (1 < *(byte *)(param_1_00 + 1)) {
        FUN_00431eb0();
        uStack_4 = 0;
        if (*(int *)(param_1 + 0x1810) != 0) {
          FUN_00432770(param_1 + 0x184,*(undefined *)(param_1_00 + 1));
          if (local_178 != 0) {
            FUN_0047f260(param_1,0,0,(int)param_1_00 + 3,*(undefined *)(param_1_00 + 1));
          }
          FUN_0047f0e0(param_1,3);
        }
        if (iStack_170 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)(iStack_170 + 0x5cc));
        }
      }
      goto LAB_004805b9;
    }
    break;
  case 0xf105:
    bVar1 = *(byte *)(param_1_00 + 1);
    if (bVar1 < 0x81) {
      if (bVar1 < 2) goto LAB_004805b9;
      uStack_16a = *(uint *)(param_1 + 0x128);
      uStack_16c = 0xf105;
      pvStack_174 = (void *)((int)param_1_00 + 3);
      bStack_166 = bVar1;
      _memcpy(auStack_165,pvStack_174,(uint)bVar1);
      FUN_0044e110();
      uStack_4 = 1;
      if (*(int *)(param_1 + 0x17f4) != 0) {
        FUN_0044e950();
        if (local_178 != 0) {
          uVar3 = *(undefined *)(param_1_00 + 1);
LAB_00480232:
          FUN_0047f260(param_1,0,0,pvStack_174,uVar3);
        }
LAB_0048024a:
        FUN_0047f0e0(param_1,4);
      }
      goto LAB_0048025a;
    }
    break;
  case 0xf106:
    uVar4 = param_1_00[1];
    if (uVar4 < 0x7d1) {
      if (1 < uVar4) {
        *(undefined *)(uVar4 + 3 + (int)param_1_00) = 0;
        FUN_00419120();
        if (local_178 != 0) {
          FUN_0047f260(param_1,0,0,param_1_00 + 2,param_1_00[1]);
        }
      }
      goto LAB_004805b9;
    }
    break;
  case 0xf107:
    *(undefined *)(param_1_00 + 0xb) = 0;
    iVar8 = FUN_00414d40();
    if (iVar8 == 0) {
      pvStack_174 = (void *)CONCAT13(pvStack_174._3_1_,0x11106);
      FUN_004ed0e0(&pvStack_174,3);
    }
    else if (*(int *)(param_1 + 0x5810) != *(int *)(iVar8 + 0x128)) {
      if (*(int *)(param_1 + 0x5810) != 0) {
        FUN_0047f350();
      }
      *(undefined4 *)(param_1 + 0x5810) = *(undefined4 *)(iVar8 + 0x128);
      uStack_cc = 0xf107;
      pcVar9 = (char *)(param_1 + 0x184);
      iVar5 = -(int)pcVar9;
      do {
        cVar2 = *pcVar9;
        pcVar9[(int)(acStack_ca + iVar5)] = cVar2;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      FUN_004ed0e0(&uStack_cc,0x17);
      pcVar9 = (char *)(iVar8 + 0x184);
      iVar8 = -(int)pcVar9;
      do {
        cVar2 = *pcVar9;
        pcVar9[(int)(acStack_ca + iVar8)] = cVar2;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      FUN_004ed0e0(&uStack_cc,0x17);
    }
    goto LAB_004805b9;
  case 0xf108:
    if (*(int *)(param_1 + 0x5810) != 0) {
      if (0x80 < *(byte *)(param_1_00 + 1)) break;
      if (*(byte *)(param_1_00 + 1) < 2) goto LAB_004805b9;
      pvStack_174 = (void *)FUN_00414d10(*(int *)(param_1 + 0x5810));
      if (pvStack_174 != (void *)0x0) {
        uStack_b4 = 0xf102;
        pcVar9 = (char *)(param_1 + 0x184);
        uStack_b2 = 0;
        iVar8 = -(int)pcVar9;
        do {
          cVar2 = *pcVar9;
          pcVar9[(int)(acStack_b1 + iVar8)] = cVar2;
          pcVar9 = pcVar9 + 1;
        } while (cVar2 != '\0');
        bStack_9c = *(byte *)(param_1_00 + 1);
        uVar6 = (uint)bStack_9c;
        _memcpy(auStack_9b,(void *)((int)param_1_00 + 3),uVar6);
        FUN_004ed0e0(&uStack_b4,uVar6 + 0x19);
        if (local_178 != 0) {
          pcVar9 = (char *)((int)pvStack_174 + 0x184);
          do {
            cVar2 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar2 != '\0');
          FUN_0047f260(param_1,(char *)((int)pvStack_174 + 0x184),
                       (int)pcVar9 - ((int)pvStack_174 + 0x185),(void *)((int)param_1_00 + 3),
                       *(undefined *)(param_1_00 + 1));
        }
        pcVar9 = (char *)((int)pvStack_174 + 0x184);
        uStack_b2 = 1;
        iVar8 = -(int)pcVar9;
        do {
          cVar2 = *pcVar9;
          pcVar9[(int)(acStack_b1 + iVar8)] = cVar2;
          pcVar9 = pcVar9 + 1;
        } while (cVar2 != '\0');
        FUN_004ed0e0(&uStack_b4,*(byte *)(param_1_00 + 1) + 0x19);
        FUN_0047f0e0(param_1,2);
        goto LAB_004805b9;
      }
    }
    iStack_170 = CONCAT13(iStack_170._3_1_,0x11106);
    FUN_004ed0e0(&iStack_170,3);
    goto LAB_004805b9;
  case 0xf109:
    FUN_0047f350();
    goto LAB_004805b9;
  case 0xf10a:
    FUN_0044e110(uVar6);
    uStack_4 = 2;
    iVar8 = *(int *)(param_1 + 0x17f4);
    if (((iVar8 != 0) && (*(char *)(iVar8 + 0x114) != '\0')) &&
       ((*(int *)(iVar8 + 0x18 + *(int *)(iVar8 + 0xc) * 8) == param_1 ||
        (*(int *)(iVar8 + 0x18 + *(int *)(iVar8 + 0x110) * 8) == param_1)))) {
      bVar1 = *(byte *)(param_1_00 + 1);
      if (bVar1 < 0x81) {
        if (1 < bVar1) {
          uStack_16a = *(uint *)(param_1 + 0x128);
          pvStack_174 = (void *)((int)param_1_00 + 3);
          uStack_16c = 0xf10a;
          bStack_166 = bVar1;
          _memcpy(auStack_165,pvStack_174,(uint)bVar1);
          FUN_0044e950();
          if (local_178 != 0) {
            uVar3 = *(undefined *)(param_1_00 + 1);
            goto LAB_00480232;
          }
          goto LAB_0048024a;
        }
      }
      else {
        FUN_004ec760(9,0);
      }
    }
LAB_0048025a:
    if (iStack_170 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(iStack_170 + 0x118));
    }
    goto LAB_004805b9;
  }
switchD_0047fdff_caseD_a:
  FUN_004ec760(9,0);
LAB_004805b9:
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
}

