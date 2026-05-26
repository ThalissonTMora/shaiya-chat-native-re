/*
 * Game.exe — GmCommand_Dispatch
 * Requested VA: 0x0047FFD0
 * Entry Ghidra:  0047ffd0
 * Ghidra name:   FUN_0047ffd0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: command
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0047ffd0(float param_1_00,char *param_1)

{
  byte bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  char *pcVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  float *pfVar13;
  int *piVar14;
  uint uVar15;
  undefined4 *puVar16;
  byte *pbVar17;
  byte *pbVar18;
  undefined **ppuVar19;
  bool bVar20;
  float10 fVar21;
  double dVar22;
  undefined1 *puVar23;
  undefined8 uVar24;
  undefined4 uVar26;
  undefined8 uVar25;
  float local_13c0;
  float local_13bc;
  int local_13b8 [2];
  undefined local_13b0 [28];
  undefined4 local_1394;
  float local_1390;
  float local_138c;
  undefined4 local_1388;
  undefined4 local_1384;
  undefined2 local_1380;
  undefined uStack_137e;
  undefined uStack_137d;
  undefined local_137c;
  undefined uStack_137b;
  undefined local_137a;
  undefined local_1374;
  int local_1364;
  undefined4 local_1360;
  undefined local_135c [24];
  uint local_1344;
  byte local_133c [260];
  undefined local_1238 [32];
  undefined4 local_1218;
  char local_1114 [260];
  char local_1010 [2048];
  char local_810 [2048];
  uint local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0073049e;
  local_c = ExceptionList;
  local_10 = DAT_007b4dd0 ^ (uint)&local_13c0;
  ExceptionList = &local_c;
  local_13c0 = param_1_00;
  _memset(local_133c,0,0x104);
  iVar6 = _strncmp(param_1,&DAT_0074e018,9);
  if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/char on",8), iVar6 == 0)) {
    cVar5 = FUN_0047a970();
    if (cVar5 != '\0') {
      iVar6 = FUN_00420db0();
      if (iVar6 != 0) {
        FUN_00405780();
        local_4 = 0;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        if (0xf < local_1344) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd();
        }
      }
      FUN_005ed6c0();
    }
    goto LAB_00486611;
  }
  iVar6 = _strncmp(param_1,"/mobkillarea ",0xd);
  if (iVar6 == 0) {
    cVar5 = FUN_0047a970();
    if (cVar5 != '\0') {
      local_13c0 = 0.0;
      iVar6 = _strncmp(param_1,"/mobkillarea ",0xd);
      if (iVar6 == 0) {
        FID_conflict__sscanf(param_1 + 0xd,"%d");
      }
      DAT_0090247c = (int *)*DAT_00902474;
      if (DAT_0090247c != DAT_00902474) {
        do {
          iVar6 = DAT_0090247c[4];
          if (iVar6 != 0) {
            local_1394 = *(float *)(iVar6 + 4) - *(float *)(DAT_00904aa0 + 0x10);
            local_1390 = *(float *)(iVar6 + 8) - *(float *)(DAT_00904aa0 + 0x14);
            local_138c = *(float *)(iVar6 + 0xc) - *(float *)(DAT_00904aa0 + 0x18);
            local_13bc = local_138c * local_138c + local_1390 * local_1390 + local_1394 * local_1394
            ;
            fVar21 = (float10)FUN_00633e40();
            local_13bc = (float)fVar21;
            if (local_13bc < (float)(int)local_13c0) {
              FUN_005eddf0();
            }
          }
          FUN_0049ed20();
        } while (DAT_0090247c != DAT_00902474);
      }
    }
    goto LAB_00486611;
  }
  pcVar7 = (char *)FUN_00420db0();
  pcVar9 = pcVar7 + 1;
  do {
    cVar5 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar5 != '\0');
  sVar8 = (int)pcVar7 - (int)pcVar9;
  pcVar9 = (char *)FUN_00420db0(0x19cd);
  iVar6 = _strncmp(param_1,pcVar9,sVar8);
  if (iVar6 == 0) {
    if (((DAT_022aa730 == 0) || (DAT_022aa730 == 1)) && (cVar5 = FUN_0047a970(), cVar5 != '\0')) {
      uVar10 = FUN_00420db0();
      _sprintf((char *)&local_1218,"%s ",uVar10);
      pcVar9 = (char *)&local_1218;
      do {
        cVar5 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar5 != '\0');
      iVar6 = (int)pcVar9 - ((int)&local_1218 + 1);
      iVar11 = _strncmp(param_1,(char *)&local_1218,iVar6 - 1);
      if (iVar11 == 0) {
        uVar24 = CONCAT44(param_1 + iVar6 + -1,local_133c);
      }
      else {
        uVar24 = CONCAT44(param_1 + 6,local_133c);
      }
      FUN_0047a9b0(uVar24);
      ppuVar19 = &PTR_00746cf4;
      pbVar17 = local_133c;
      do {
        bVar1 = *pbVar17;
        bVar20 = bVar1 < *(byte *)ppuVar19;
        if (bVar1 != *(byte *)ppuVar19) {
LAB_00480263:
          iVar11 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
          goto LAB_00480268;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar17[1];
        bVar20 = bVar1 < *(byte *)((int)ppuVar19 + 1);
        if (bVar1 != *(byte *)((int)ppuVar19 + 1)) goto LAB_00480263;
        pbVar17 = pbVar17 + 2;
        ppuVar19 = (undefined **)((int)ppuVar19 + 2);
      } while (bVar1 != 0);
      iVar11 = 0;
LAB_00480268:
      if (iVar11 == 0) {
        param_1 = param_1 + iVar6;
        iVar6 = -(int)param_1;
        do {
          cVar5 = *param_1;
          param_1[(int)(local_133c + iVar6)] = cVar5;
          param_1 = param_1 + 1;
        } while (cVar5 != '\0');
      }
      pbVar17 = local_133c;
      do {
        bVar1 = *pbVar17;
        pbVar17 = pbVar17 + 1;
      } while (bVar1 != 0);
      if (pbVar17 != local_133c + 1) {
        FUN_005f14e0();
      }
    }
    goto LAB_00486611;
  }
  iVar6 = _strncmp(param_1,&DAT_0074dff4,7);
  if (iVar6 == 0) {
    FID_conflict__sscanf(param_1,"%s %u",&local_1218);
    FUN_00452bd0();
    goto LAB_004802fb;
  }
  iVar6 = _strncmp(param_1,"/CheckBuildVersion",0x12);
  if (iVar6 == 0) {
    _memset(local_1114,0,0x104);
    FUN_0047c3b0(local_1114,"BuildVersion: 0x%X",DAT_0090d1d0);
    FUN_004231a0(0x1f,local_1114,0xc);
    goto LAB_00486611;
  }
  iVar6 = _strncmp(param_1,&DAT_0074deb0,9);
  if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/char off",9), iVar6 == 0)) {
    cVar5 = FUN_0047a970();
    if (cVar5 != '\0') {
      iVar6 = FUN_00420db0();
      if (iVar6 != 0) {
        FUN_00405780();
        local_4 = 1;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
      }
      FUN_005ed710();
    }
    goto LAB_00486611;
  }
  iVar6 = _strncmp(param_1,&DAT_0074de98,9);
  if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/attack on",10), iVar6 == 0)) {
    cVar5 = FUN_0047a970();
    if (cVar5 != '\0') {
      iVar6 = FUN_00420db0();
      if (iVar6 != 0) {
        FUN_00405780();
        local_4 = 2;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
      }
      FUN_005ed760();
    }
    goto LAB_00486611;
  }
  iVar6 = _strncmp(param_1,&DAT_0074de80,9);
  if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/attack off",0xb), iVar6 == 0)) {
    cVar5 = FUN_0047a970();
    if (cVar5 != '\0') {
      iVar6 = FUN_00420db0();
      if (iVar6 != 0) {
        FUN_00405780();
        local_4 = 3;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
      }
      FUN_005ed7b0();
    }
    goto LAB_00486611;
  }
  iVar6 = _strncmp(param_1,"/effectpos",10);
  if (iVar6 != 0) {
    iVar6 = _strncmp(param_1,&DAT_0074ddf8,6);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/amove ",7), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 == '\0') goto LAB_00486611;
      iVar6 = _strncmp(param_1,&DAT_0074ddf8,6);
      pcVar9 = param_1;
      if (iVar6 == 0) {
        do {
          cVar5 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar5 != '\0');
        if (6 < (uint)((int)pcVar9 - (int)(param_1 + 1))) {
          param_1 = param_1 + 6;
LAB_004863e9:
          FID_conflict__sscanf(param_1,"%s");
        }
      }
      else {
        do {
          cVar5 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar5 != '\0');
        if (7 < (uint)((int)pcVar9 - (int)(param_1 + 1))) {
          param_1 = param_1 + 7;
          goto LAB_004863e9;
        }
      }
      FUN_00420c10(&DAT_007c2338,local_133c);
      iVar6 = FUN_00420db0();
      if (iVar6 != 0) {
        FUN_00405780();
        local_4 = 0xc;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
      }
      FUN_005ed930();
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074dde4,8);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/bmove ",7), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13c0 = -NAN;
        iVar6 = _strncmp(param_1,&DAT_0074dde4,8);
        if (iVar6 == 0) {
          param_1 = param_1 + 8;
        }
        else {
          param_1 = param_1 + 7;
        }
        FID_conflict__sscanf(param_1,"%d %d %d");
        _memset(&local_1218,0,0x104);
        if (local_13c0 == -NAN) {
          uVar10 = FUN_00420db0();
          _sprintf((char *)&local_1218,"[%d,%d] %s",local_13b8[0],local_13bc,uVar10);
          FUN_00405780();
          local_4 = 0xd;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        else {
          FUN_00420db0();
          _sprintf((char *)&local_1218,"[map%d, %d,%d] %s");
          FUN_00405780();
          local_4 = 0xe;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005edd20();
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074ddd4,7);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/cmove",6), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13c0 = -NAN;
        iVar6 = _strncmp(param_1,&DAT_0074ddd4,7);
        if (iVar6 == 0) {
          param_1 = param_1 + 7;
        }
        else {
          param_1 = param_1 + 6;
        }
        FID_conflict__sscanf(param_1,"%d");
        _memset(local_1114,0,0x104);
        if (local_13c0 == -NAN) {
          FUN_00420db0();
          FUN_00405780();
          local_4 = 0x10;
        }
        else {
          FUN_00420db0();
          _sprintf(local_1114,"[map%d] %s");
          FUN_00405780();
          local_4 = 0xf;
        }
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
        FUN_005edd90();
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,"/itemlv",7);
    if (iVar6 == 0) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13c0 = -NAN;
        FID_conflict__sscanf(param_1 + 7,"%d");
        if (-1 < (int)local_13c0) {
          uVar26 = 0x14a9;
          uVar10 = FUN_00420db0();
          uVar24 = CONCAT44(uVar26,uVar10);
          puVar23 = &DAT_007c2338;
          FUN_00420c10();
          DAT_007c273c = local_13c0;
          FUN_00423150(0x22,0xda,7,puVar23,uVar24);
          if (DAT_00904aa0 != 0) {
            *(undefined *)(DAT_00904aa0 + 0x1cf) = local_13c0._0_1_;
            FUN_00418bb0();
          }
        }
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074ddb8,9);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/xcall",6), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13c0 = -NAN;
        iVar6 = _strncmp(param_1,&DAT_0074ddb8,9);
        if (iVar6 == 0) {
          param_1 = param_1 + 9;
        }
        else {
          param_1 = param_1 + 6;
        }
        FID_conflict__sscanf(param_1,"%d");
        if ((local_13c0 == 1.4013e-45) || (local_13c0 == 2.8026e-45)) {
          FUN_00420db0(0x150,0x34);
          FUN_00422b90();
          FUN_005ede40();
        }
        else {
          FUN_00420db0(0x7e6,0x34);
          FUN_00422b90();
        }
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,"/tacticszone",0xc);
    if (iVar6 == 0) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        DAT_022aff10 = (uint)(DAT_022aff10 == 0);
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,"/fogstart ",9);
    if (iVar6 == 0) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13c0 = 0.0;
        FID_conflict__sscanf(param_1 + 9,"%d");
        _DAT_007c0da4 = (float)(int)local_13c0;
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,"/fogend ",7);
    if (iVar6 == 0) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13c0 = 0.0;
        FID_conflict__sscanf(param_1 + 7,"%d");
        _DAT_007c0da8 = (float)(int)local_13c0;
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,"/itemlist ",9);
    if (iVar6 == 0) {
      cVar5 = FUN_0047a970();
      if (cVar5 == '\0') goto LAB_00486611;
      FUN_0047a9b0(local_133c);
      iVar6 = FUN_0046f5a0();
      iVar11 = 10;
      do {
        FUN_004231a0();
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      _sprintf((char *)&local_1218,&DAT_0074dd5c,local_133c);
      FUN_004231a0(0x22,&local_1218);
      piVar12 = (int *)**(int **)(iVar6 + 4);
      if (piVar12 != *(int **)(iVar6 + 4)) {
        do {
          piVar14 = piVar12 + 2;
          do {
            cVar5 = *(char *)piVar14;
            piVar14 = (int *)((int)piVar14 + 1);
          } while (cVar5 != '\0');
          if (piVar14 == (int *)((int)piVar12 + 9)) break;
          _memset(&local_1218,0,0x104);
          _sprintf((char *)&local_1218,"%4d %4d %s",*(byte *)(piVar12 + 0x43) + 1,
                   *(byte *)((int)piVar12 + 0x10d) + 1,piVar12 + 2);
          FUN_004231a0(0x22,&local_1218,0x34);
          piVar12 = (int *)*piVar12;
        } while (piVar12 != (int *)*(int *)(iVar6 + 4));
      }
      FUN_004231a0();
      param_1_00 = local_13c0;
    }
    else {
      iVar6 = _strncmp(param_1,&DAT_0074dd10,8);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/gmove ",7), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          local_13bc = -NAN;
          local_1394 = 0.0;
          local_1390 = 0.0;
          local_138c = 0.0;
          local_1388 = 0;
          local_1384 = 0;
          local_1380 = 0;
          uStack_137e = 0;
          uStack_137d = 0;
          local_137c = 0;
          iVar6 = _strncmp(param_1,&DAT_0074dd10,8);
          if (iVar6 == 0) {
            uVar25 = CONCAT44(&local_1394,&local_13bc);
            uVar24 = CONCAT44(local_13b8,&local_13c0);
            param_1 = param_1 + 9;
          }
          else {
            uVar25 = CONCAT44(&local_1394,&local_13bc);
            uVar24 = CONCAT44(local_13b8,&local_13c0);
            param_1 = param_1 + 7;
          }
          FID_conflict__sscanf(param_1,"%d %d %d %s",uVar24,uVar25);
          _memset(&local_1218,0,0x104);
          if (local_13bc == -NAN) {
            uVar10 = FUN_00420db0();
            _sprintf((char *)&local_1218,"szGuildName : [%d,%d] %s",local_13c0,local_13b8[0],uVar10)
            ;
            FUN_00405780();
            local_4 = 0x11;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
            uVar24 = CONCAT44(&local_1394,local_13bc);
          }
          else {
            FUN_00420db0();
            _sprintf((char *)&local_1218,"szGuildName : [map%d, %d,%d] %s");
            FUN_00405780();
            local_4 = 0x12;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
            uVar24 = CONCAT44(&local_1394,local_13bc);
          }
          FUN_005f13f0((float)(int)local_13c0,(float)local_13b8[0],uVar24);
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dd00,6);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/warning ",9), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 == '\0') goto LAB_00486611;
        _memset(local_1114,0,0x104);
        iVar6 = _strncmp(param_1,&DAT_0074dd00,6);
        pcVar9 = param_1;
        if (iVar6 == 0) {
          do {
            cVar5 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar5 != '\0');
          if (6 < (uint)((int)pcVar9 - (int)(param_1 + 1))) {
            FID_conflict__sscanf(param_1 + 6,"%s");
          }
          pcVar9 = param_1;
          do {
            cVar5 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar5 != '\0');
          pbVar17 = local_133c;
          do {
            bVar1 = *pbVar17;
            pbVar17 = pbVar17 + 1;
          } while (bVar1 != 0);
          if (pbVar17 + (7 - (int)(local_133c + 1)) < pcVar9 + -(int)(param_1 + 1)) {
            pbVar17 = local_133c;
            do {
              bVar1 = *pbVar17;
              pbVar17 = pbVar17 + 1;
            } while (bVar1 != 0);
            uVar24 = CONCAT44(param_1 + (int)(pbVar17 + (7 - (int)(local_133c + 1))),local_1114);
LAB_00485e36:
            FUN_0047a9b0(uVar24);
          }
        }
        else {
          do {
            cVar5 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar5 != '\0');
          if (9 < (uint)((int)pcVar9 - (int)(param_1 + 1))) {
            FID_conflict__sscanf(param_1 + 9,"%s");
          }
          pcVar9 = param_1;
          do {
            cVar5 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar5 != '\0');
          pbVar17 = local_133c;
          do {
            bVar1 = *pbVar17;
            pbVar17 = pbVar17 + 1;
          } while (bVar1 != 0);
          if (pbVar17 + (10 - (int)(local_133c + 1)) < pcVar9 + -(int)(param_1 + 1)) {
            pbVar17 = local_133c;
            do {
              bVar1 = *pbVar17;
              pbVar17 = pbVar17 + 1;
            } while (bVar1 != 0);
            uVar24 = CONCAT44(param_1 + (int)(pbVar17 + (10 - (int)(local_133c + 1))),local_1114);
            goto LAB_00485e36;
          }
        }
        FUN_00420c10(&DAT_007c2338,local_133c);
        iVar6 = FUN_00420db0();
        if (iVar6 != 0) {
          FUN_00405780();
          local_4 = 0x13;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005ed800(local_133c,local_1114);
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dcec,6);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/watch ",7), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          iVar6 = _strncmp(param_1,&DAT_0074dcec,6);
          if (iVar6 == 0) {
            param_1 = param_1 + 6;
          }
          else {
            param_1 = param_1 + 7;
          }
          FID_conflict__sscanf(param_1,"%s");
          FUN_00420c10(&DAT_007c2338,local_133c);
          iVar6 = FUN_00420db0();
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x14;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_005ed8b0();
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dcd8,10);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/cwatch ",8), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          iVar6 = _strncmp(param_1,&DAT_0074dcd8,10);
          if (iVar6 == 0) {
            param_1 = param_1 + 10;
          }
          else {
            param_1 = param_1 + 8;
          }
          FID_conflict__sscanf(param_1,"%s");
          pbVar17 = local_133c;
          iVar6 = ((int)param_1_00 + 0x3e0) - (int)pbVar17;
          do {
            bVar1 = *pbVar17;
            pbVar17[iVar6] = bVar1;
            pbVar17 = pbVar17 + 1;
          } while (bVar1 != 0);
          FUN_00420c10(&DAT_007c2338,(int)param_1_00 + 0x3e0);
          iVar6 = FUN_00420db0();
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x15;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_005ed9b0();
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dcbc,0xe);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/cwatch off",0xb), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          pcVar9 = (char *)((int)param_1_00 + 0x3e0);
          do {
            cVar5 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar5 != '\0');
          if (pcVar9 != (char *)((int)param_1_00 + 0x3e1)) {
            FUN_00420c10(&DAT_007c2338);
            iVar6 = FUN_00420db0();
            if (iVar6 != 0) {
              FUN_00405780();
              local_4 = 0x16;
              FUN_0047f8b0();
              local_4 = 0xffffffff;
              FUN_005535b0();
            }
            FUN_005edcd0();
            _memset((char *)((int)param_1_00 + 0x3e0),0,0x104);
          }
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dca4,10);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/silence off",0xc), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          iVar6 = _strncmp(param_1,&DAT_0074dca4,10);
          if (iVar6 == 0) {
            param_1 = param_1 + 10;
          }
          else {
            param_1 = param_1 + 0xc;
          }
          FID_conflict__sscanf(param_1,"%s");
          FUN_00420c10(&DAT_007c2338,local_133c);
          iVar6 = FUN_00420db0();
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x17;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_005edac0();
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dc8c,6);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/silence ",9), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          local_13c0 = 0.0;
          iVar6 = _strncmp(param_1,&DAT_0074dc8c,6);
          iVar11 = (-(uint)(iVar6 != 0) & 3) + 6;
          iVar6 = FUN_0047aaf0(param_1 + iVar11,&local_13c0);
          param_1 = param_1 + iVar6 + iVar11;
          FID_conflict__sscanf(param_1,"%s");
          uVar24 = CONCAT44(param_1,local_133c);
          puVar23 = &DAT_007c2338;
          FUN_00420c10();
          iVar6 = FUN_00420db0(0x112,puVar23,uVar24);
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x18;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_005eda30(local_13c0,local_133c);
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dc74,10);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/stopon ",8), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          local_13c0 = 0.0;
          iVar6 = _strncmp(param_1,&DAT_0074dc74,10);
          iVar11 = (-(uint)(iVar6 != 0) & 0xfffffffe) + 10;
          iVar6 = FUN_0047aaf0(param_1 + iVar11,&local_13c0);
          param_1 = param_1 + iVar6 + iVar11;
          FID_conflict__sscanf(param_1,"%s");
          uVar24 = CONCAT44(param_1,local_133c);
          puVar23 = &DAT_007c2338;
          FUN_00420c10();
          iVar6 = FUN_00420db0(0x114,puVar23,uVar24);
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x19;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_005edb40(local_13c0,local_133c);
        }
        goto LAB_00486611;
      }
      iVar6 = _strncmp(param_1,&DAT_0074dc58,0xe);
      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/stopoff ",9), iVar6 == 0)) {
        cVar5 = FUN_0047a970();
        if (cVar5 != '\0') {
          iVar6 = _strncmp(param_1,&DAT_0074dc58,0xe);
          if (iVar6 == 0) {
            param_1 = param_1 + 0xe;
          }
          else {
            param_1 = param_1 + 9;
          }
          FID_conflict__sscanf(param_1,"%s");
          FUN_00420c10(&DAT_007c2338,local_133c);
          iVar6 = FUN_00420db0();
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x1a;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_005edbd0();
        }
        goto LAB_00486611;
      }
      iVar6 = __strnicmp(param_1,"/newrandsimulate",0x10);
      if (iVar6 == 0) {
        iVar6 = _strncmp(param_1,"/newrandsimulate ",0x10);
        if (iVar6 == 0) {
          uVar25 = CONCAT44(local_13b8,&local_13c0);
          uVar24 = CONCAT44(&local_13bc,local_135c);
        }
        else {
          uVar25 = CONCAT44(local_13b8,&local_13c0);
          uVar24 = CONCAT44(&local_13bc,local_135c);
        }
        FID_conflict__sscanf(param_1,"%s %d %d %d",uVar24,uVar25);
        iVar6 = FUN_0046cb30(local_13bc,local_13c0);
        if (iVar6 == 0) {
          _sprintf((char *)&local_1218,&DAT_0074dbf4);
          FUN_004231a0();
        }
        else if (*(char *)(iVar6 + 0x2c) == '*') {
          if (*(char *)(iVar6 + 0x65) == '\0') {
            _sprintf((char *)&local_1218,&DAT_0074dbbc);
            FUN_004231a0();
          }
          else {
            FUN_005ed610(local_13bc,local_13c0,local_13b8[0],&DAT_009144ce);
          }
        }
        else {
          _sprintf((char *)&local_1218,&DAT_0074dbdc);
          FUN_004231a0();
        }
        goto LAB_00486611;
      }
    }
LAB_004802fb:
    iVar6 = _strncmp(param_1,&DAT_0074dfe4,6);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/quiry ",7), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        iVar6 = _strncmp(param_1,&DAT_0074dfe4,6);
        if (iVar6 == 0) {
          param_1 = param_1 + 6;
        }
        else {
          param_1 = param_1 + 7;
        }
        FID_conflict__sscanf(param_1,"%s");
        FUN_00420c10(&DAT_007c2338,local_133c);
        iVar6 = FUN_00420db0();
        if (iVar6 != 0) {
          FUN_00405780();
          local_4 = 0x1b;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005edc50();
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074dfd0,10);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/asummon ",9), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        iVar6 = _strncmp(param_1,&DAT_0074dfd0,10);
        if (iVar6 == 0) {
          param_1 = param_1 + 10;
        }
        else {
          param_1 = param_1 + 9;
        }
        FID_conflict__sscanf(param_1,"%s");
        FUN_00420c10(&DAT_007c2338,local_133c);
        iVar6 = FUN_00420db0();
        if (iVar6 != 0) {
          FUN_00405780();
          local_4 = 0x1c;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005ed8b0();
        iVar6 = FUN_00420db0(0x118);
        if (iVar6 != 0) {
          FUN_00405780();
          local_4 = 0x1d;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005ee660();
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074dfb4,0xc);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/bsummon ",9), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13bc = -NAN;
        iVar6 = _strncmp(param_1,&DAT_0074dfb4,0xc);
        if (iVar6 == 0) {
          uVar25 = CONCAT44(&local_13bc,&local_13c0);
          uVar24 = CONCAT44(local_13b8,local_133c);
          param_1 = param_1 + 0xc;
        }
        else {
          uVar25 = CONCAT44(&local_13bc,&local_13c0);
          uVar24 = CONCAT44(local_13b8,local_133c);
          param_1 = param_1 + 9;
        }
        FID_conflict__sscanf(param_1,"%s %d %d %d",uVar24,uVar25);
        FUN_00420c10(&DAT_007c2338,local_133c);
        iVar6 = FUN_00420db0();
        if (iVar6 != 0) {
          FUN_00405780();
          local_4 = 0x1e;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005ed8b0();
        if (local_13bc == -NAN) {
          FUN_00420db0();
          FUN_004205a0(local_133c);
          _sprintf(local_1114,"[%s]%s [%d, %d]%s");
        }
        else {
          uVar10 = FUN_00420db0();
          uVar25 = CONCAT44(uVar10,local_13c0);
          uVar24 = CONCAT44(local_13b8[0],local_13bc);
          uVar10 = FUN_004205a0();
          _sprintf(local_1114,"[%s]%s [map%d, %d, %d]%s",local_133c,uVar10,uVar24,uVar25);
        }
        FUN_00405780();
        local_4 = 0x1f;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
        FUN_005ee550(local_133c,(float)local_13b8[0],(float)(int)local_13c0,local_13bc);
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074df9c,10);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/partysummon ",0xe), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 != '\0') {
        local_13bc = -NAN;
        iVar6 = _strncmp(param_1,&DAT_0074df9c,10);
        if (iVar6 == 0) {
          uVar25 = CONCAT44(&local_13bc,&local_13c0);
          uVar24 = CONCAT44(local_13b8,local_133c);
          param_1 = param_1 + 10;
        }
        else {
          uVar25 = CONCAT44(&local_13bc,&local_13c0);
          uVar24 = CONCAT44(local_13b8,local_133c);
          param_1 = param_1 + 0xe;
        }
        FID_conflict__sscanf(param_1,"%s %d %d %d",uVar24,uVar25);
        _memset(local_1114,0,0x104);
        if (local_13bc == -NAN) {
          FUN_00420db0();
          FUN_004205a0(local_133c);
          _sprintf(local_1114,"[%s]%s [%d, %d]%s");
        }
        else {
          uVar10 = FUN_00420db0();
          uVar25 = CONCAT44(uVar10,local_13c0);
          uVar24 = CONCAT44(local_13b8[0],local_13bc);
          uVar10 = FUN_004205a0();
          _sprintf(local_1114,"[%s]%s [map%d, %d, %d]%s",local_133c,uVar10,uVar24,uVar25);
        }
        FUN_00405780();
        local_4 = 0x20;
        FUN_0047f8b0();
        local_4 = 0xffffffff;
        FUN_005535b0();
        FUN_005ee7f0(local_133c,(float)local_13b8[0],(float)(int)local_13c0,local_13bc);
      }
      goto LAB_00486611;
    }
    iVar6 = _strncmp(param_1,&DAT_0074df7c,0xc);
    if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/item ",6), iVar6 == 0)) {
      cVar5 = FUN_0047a970();
      if (cVar5 == '\0') goto LAB_00486611;
      iVar6 = _strncmp(param_1,&DAT_0074df7c,0xc);
      if (iVar6 == 0) {
        uVar24 = CONCAT44(param_1 + 0xc,local_133c);
      }
      else {
        uVar24 = CONCAT44(param_1 + 6,local_133c);
      }
      FUN_0047a9b0(uVar24);
      iVar6 = FUN_0046cb90();
      if (iVar6 != 0) {
        _memset(local_1010,0,0x400);
        FUN_0047adb0(iVar6,local_1010);
        _sprintf(local_810,"[%s] %s",local_133c,local_1010);
        FUN_00422b90();
        goto LAB_00486611;
      }
    }
    else {
      iVar6 = _strncmp(param_1,&DAT_0074df68,8);
      if ((iVar6 != 0) && (iVar6 = _strncmp(param_1,"/mob ",5), iVar6 != 0)) {
        iVar6 = _strncmp(param_1,&DAT_0074df54,10);
        if ((iVar6 != 0) && (iVar6 = _strncmp(param_1,"/guildgrade ",0xc), iVar6 != 0)) {
          iVar6 = _strncmp(param_1,&DAT_0074df38,0xb);
          if ((iVar6 != 0) && (iVar6 = _strncmp(param_1,"/guildgrade2 ",0xd), iVar6 != 0)) {
            iVar6 = _strncmp(param_1,&DAT_0074df1c,10);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/guildrank ",0xb), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                _memset(&local_1218,0,0x104);
                iVar6 = _strncmp(param_1,&DAT_0074df1c,10);
                if (iVar6 == 0) {
                  uVar24 = CONCAT44(&local_13c0,&local_1218);
                  param_1 = param_1 + 10;
                }
                else {
                  uVar24 = CONCAT44(&local_13c0,&local_1218);
                  param_1 = param_1 + 0xb;
                }
                FID_conflict__sscanf(param_1,"%s %d",uVar24);
                uVar26 = 0x14ea;
                uVar10 = FUN_00420db0();
                uVar25 = CONCAT44(uVar26,&local_1218);
                puVar23 = &DAT_007c2338;
                FUN_00420c10();
                uVar24 = CONCAT44(puVar23,uVar10);
                puVar23 = &DAT_007c1d38;
                FUN_00420c10();
                FUN_00420db0(0x126,puVar23,uVar24,uVar25);
                FUN_00422b90();
                FUN_005ef340(&local_1218,local_13c0);
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074df00,0xc);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/guildpoint ",0xc), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                _memset(&local_1218,0,0x104);
                iVar6 = _strncmp(param_1,&DAT_0074df00,0xc);
                if (iVar6 == 0) {
                  uVar24 = CONCAT44(&local_13c0,&local_1218);
                }
                else {
                  uVar24 = CONCAT44(&local_13c0,&local_1218);
                }
                FID_conflict__sscanf(param_1 + 0xc,"%s %d",uVar24);
                uVar26 = 0x14ea;
                uVar10 = FUN_00420db0();
                uVar25 = CONCAT44(uVar26,&local_1218);
                puVar23 = &DAT_007c2338;
                FUN_00420c10();
                uVar24 = CONCAT44(puVar23,uVar10);
                puVar23 = &DAT_007c1d38;
                FUN_00420c10();
                FUN_00420db0(0x126,puVar23,uVar24,uVar25);
                FUN_00422b90();
                FUN_005ef3b0(&local_1218,local_13c0);
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074dee4,0xb);
            if (iVar6 == 0) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = FUN_00420db0();
                if (iVar6 != 0) {
                  FUN_00405780();
                  local_4 = 0x23;
                  FUN_0047f8b0();
                  local_4 = 0xffffffff;
                  FUN_005535b0();
                }
                FUN_005edf70(0,0);
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074dbb0,0xb);
            if (iVar6 == 0) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = FUN_00420db0();
                if (iVar6 != 0) {
                  FUN_00405780();
                  local_4 = 0x24;
                  FUN_0047f8b0();
                  local_4 = 0xffffffff;
                  FUN_005535b0();
                }
                FUN_005ede90();
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db9c,9);
            if (iVar6 == 0) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = FUN_00420db0();
                if (iVar6 != 0) {
                  FUN_00405780();
                  local_4 = 0x25;
                  FUN_0047f8b0();
                  local_4 = 0xffffffff;
                  FUN_005535b0();
                }
                FUN_005ee190(0,0);
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db90,0xb);
            if (iVar6 == 0) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = FUN_00420db0();
                if (iVar6 != 0) {
                  FUN_00405780();
                  local_4 = 0x26;
                  FUN_0047f8b0();
                  local_4 = 0xffffffff;
                  FUN_005535b0();
                }
                FUN_005ee020(0,0);
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db80,0xd);
            if (iVar6 == 0) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = FUN_00420db0();
                if (iVar6 != 0) {
                  FUN_00405780();
                  local_4 = 0x27;
                  FUN_0047f8b0();
                  local_4 = 0xffffffff;
                  FUN_005535b0();
                }
                FUN_005ee0d0();
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db70,0xc);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/gmnotice ",10), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = _strncmp(param_1,&DAT_0074db70,0xc);
                if (iVar6 == 0) {
                  uVar24 = CONCAT44(param_1 + 0xc,local_133c);
                }
                else {
                  uVar24 = CONCAT44(param_1 + 10,local_133c);
                }
                FUN_0047a9b0(uVar24);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 != local_133c + 1) {
                  iVar6 = FUN_00420db0();
                  if (iVar6 != 0) {
                    FUN_00405780();
                    local_4 = 0x28;
                    FUN_0047f8b0();
                    local_4 = 0xffffffff;
                    FUN_005535b0();
                  }
                  FUN_005ee240();
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db58,8);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/cnotice ",9), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                local_13c0 = 0.0;
                iVar6 = _strncmp(param_1,&DAT_0074db58,8);
                iVar11 = (iVar6 != 0) + 8;
                iVar6 = FUN_0047aaf0(param_1 + iVar11,&local_13c0);
                FUN_0047a9b0(local_133c,param_1 + iVar6 + iVar11);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 != local_133c + 1) {
                  iVar6 = FUN_00420db0();
                  if (iVar6 != 0) {
                    FUN_00405780();
                    local_4 = 0x29;
                    FUN_0047f8b0();
                    local_4 = 0xffffffff;
                    FUN_005535b0();
                  }
                  FUN_005edf70(local_13c0,local_133c);
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db40,8);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/wnotice ",9), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                _memset(&local_1218,0,0x104);
                local_13c0 = 0.0;
                iVar6 = _strncmp(param_1,&DAT_0074db40,8);
                iVar6 = (iVar6 != 0) + 8;
                FID_conflict__sscanf(param_1 + iVar6,"%s",local_133c);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                iVar11 = FUN_0047aaf0(param_1 + (int)(pbVar17 + (iVar6 - (int)(local_133c + 1)) + 1)
                                      ,&local_13c0);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                FUN_0047a9b0(&local_1218,
                             param_1 + (int)(pbVar17 + iVar6 + (iVar11 - (int)(local_133c + 1)) + 1)
                            );
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 != local_133c + 1) {
                  pcVar9 = (char *)&local_1218;
                  do {
                    cVar5 = *pcVar9;
                    pcVar9 = pcVar9 + 1;
                  } while (cVar5 != '\0');
                  if (pcVar9 != (char *)((int)&local_1218 + 1)) {
                    iVar6 = FUN_00420db0();
                    if (iVar6 != 0) {
                      FUN_00405780();
                      local_4 = 0x2a;
                      FUN_0047f8b0();
                      local_4 = 0xffffffff;
                      FUN_005535b0();
                    }
                    FUN_005ede90();
                  }
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db2c,6);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/notice ",8), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                local_13c0 = 0.0;
                iVar6 = _strncmp(param_1,&DAT_0074db2c,6);
                iVar11 = (-(uint)(iVar6 != 0) & 2) + 6;
                iVar6 = FUN_0047aaf0(param_1 + iVar11,&local_13c0);
                FUN_0047a9b0(local_133c,param_1 + iVar6 + iVar11);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 != local_133c + 1) {
                  iVar6 = FUN_00420db0();
                  if (iVar6 != 0) {
                    FUN_00405780();
                    local_4 = 0x2b;
                    FUN_0047f8b0();
                    local_4 = 0xffffffff;
                    FUN_005535b0();
                  }
                  FUN_005ee190(local_13c0,local_133c);
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074db14,8);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/znotice ",9), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                local_13c0 = 0.0;
                iVar6 = _strncmp(param_1,&DAT_0074db14,8);
                iVar11 = (iVar6 != 0) + 8;
                iVar6 = FUN_0047aaf0(param_1 + iVar11,&local_13c0);
                FUN_0047a9b0(local_133c,param_1 + iVar6 + iVar11);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 != local_133c + 1) {
                  iVar6 = FUN_00420db0();
                  if (iVar6 != 0) {
                    FUN_00405780();
                    local_4 = 0x2c;
                    FUN_0047f8b0();
                    local_4 = 0xffffffff;
                    FUN_005535b0();
                  }
                  FUN_005ee020(local_13c0,local_133c);
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074dafc,10);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/bnotice ",9), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                iVar6 = _strncmp(param_1,&DAT_0074dafc,10);
                if (iVar6 == 0) {
                  pcVar9 = param_1 + 10;
                }
                else {
                  pcVar9 = param_1 + 9;
                }
                FID_conflict__sscanf(pcVar9,"%s");
                pbVar18 = &DAT_0074d6f8;
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  bVar20 = bVar1 < *pbVar18;
                  if (bVar1 != *pbVar18) {
LAB_00484593:
                    iVar6 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                    goto LAB_00484597;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar17[1];
                  bVar20 = bVar1 < pbVar18[1];
                  if (bVar1 != pbVar18[1]) goto LAB_00484593;
                  pbVar17 = pbVar17 + 2;
                  pbVar18 = pbVar18 + 2;
                } while (bVar1 != 0);
                iVar6 = 0;
LAB_00484597:
                if (iVar6 == 0) {
                  local_13bc = (float)((uint)local_13bc._1_3_ << 8);
                }
                else {
                  pbVar17 = local_133c;
                  pbVar18 = &DAT_0074d6f0;
                  do {
                    bVar1 = *pbVar17;
                    bVar20 = bVar1 < *pbVar18;
                    if (bVar1 != *pbVar18) {
LAB_004845d0:
                      iVar6 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                      goto LAB_004845d4;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar17[1];
                    bVar20 = bVar1 < pbVar18[1];
                    if (bVar1 != pbVar18[1]) goto LAB_004845d0;
                    pbVar17 = pbVar17 + 2;
                    pbVar18 = pbVar18 + 2;
                  } while (bVar1 != 0);
                  iVar6 = 0;
LAB_004845d4:
                  if (iVar6 != 0) {
                    FUN_00423150();
                    goto LAB_00486611;
                  }
                  local_13bc = (float)CONCAT31(local_13bc._1_3_,1);
                }
                pbVar17 = local_133c;
                local_13c0 = 0.0;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                iVar6 = FUN_0047aaf0(param_1 + (int)(pbVar17 + (0xb - (int)(local_133c + 1))),
                                     &local_13c0);
                FUN_0047a9b0(local_133c,
                             param_1 + (int)(pbVar17 + ((iVar6 + 0xb) - (int)(local_133c + 1))));
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 != local_133c + 1) {
                  iVar6 = FUN_00420db0();
                  if (iVar6 != 0) {
                    FUN_00405780();
                    local_4 = 0x2d;
                    FUN_0047f8b0();
                    local_4 = 0xffffffff;
                    FUN_005535b0();
                  }
                  FUN_005ee0d0();
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074dae4,10);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/auctionrecall ",0xf), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                _memset(&local_1218,0,0x104);
                local_13c0 = 0.0;
                iVar6 = _strncmp(param_1,&DAT_0074dae4,10);
                if (iVar6 == 0) {
                  uVar24 = CONCAT44(&local_13c0,&local_1218);
                  param_1 = param_1 + 10;
                }
                else {
                  uVar24 = CONCAT44(&local_13c0,&local_1218);
                  param_1 = param_1 + 0xf;
                }
                FID_conflict__sscanf(param_1,"%s %ld",uVar24);
                FUN_00420c10(&DAT_007c2338);
                DAT_007c273c = local_13c0;
                FUN_00420db0();
                FUN_00422b90();
                local_1380 = 0;
                uStack_137e = 0;
                local_1394 = 8.97181e-41;
                local_1390 = 0.0;
                local_138c = 0.0;
                local_1388 = 0;
                local_1384 = 0;
                uStack_137d = SUB41(local_13c0,0);
                local_137c = (undefined)((uint)local_13c0 >> 8);
                uStack_137b = (undefined)((uint)local_13c0 >> 0x10);
                local_137a = (undefined)((uint)local_13c0 >> 0x18);
                _strncpy((char *)((int)&local_1394 + 2),(char *)&local_1218,0x14);
                FUN_005ea9a0();
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074dac8,10);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/auctionsearch ",0xf), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                _memset(&local_1218,0,0x104);
                iVar6 = _strncmp(param_1,&DAT_0074dac8,10);
                if (iVar6 == 0) {
                  param_1 = param_1 + 10;
                }
                else {
                  param_1 = param_1 + 0xf;
                }
                FID_conflict__sscanf(param_1,"%s");
                FUN_00420c10(&DAT_007c2338);
                FUN_00420db0();
                FUN_00422b90();
                local_1390 = 0.0;
                local_138c = 0.0;
                local_1388 = 0;
                local_1384 = 0;
                local_1380 = 0;
                uStack_137e = 0;
                local_1394 = 8.97195e-41;
                _strncpy((char *)((int)&local_1394 + 2),(char *)&local_1218,0x14);
                FUN_005ea9a0();
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074dab0,5);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/cure",5), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 != '\0') {
                _memset(local_133c,0,0x104);
                FID_conflict__sscanf(param_1 + 5,"%s",local_133c);
                pbVar17 = local_133c;
                do {
                  bVar1 = *pbVar17;
                  pbVar17 = pbVar17 + 1;
                } while (bVar1 != 0);
                if (pbVar17 == local_133c + 1) {
                  pbVar17 = &DAT_009144ce;
                }
                else {
                  pbVar17 = local_133c;
                }
                FUN_00420c10(&DAT_007c2338,pbVar17);
                FUN_005ee2c0();
                iVar6 = FUN_00420db0(0x11a);
                if (iVar6 != 0) {
                  FUN_00405780();
                  local_4 = 0x2e;
                  FUN_0047f8b0();
                  FUN_005535b0();
                }
                iVar6 = 0;
                if (0 < (int)(DAT_022aa6b4 - DAT_022aa6b0 & 0xfffffffcU)) {
                  do {
                    iVar11 = FUN_004e9700();
                    if (iVar11 != 0) {
                      *(undefined4 *)(iVar11 + 0x10) = 0;
                    }
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < DAT_022aa6b4 - DAT_022aa6b0 >> 2);
                }
              }
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074da9c,9);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/autocure",9), iVar6 == 0)) {
              *(undefined *)((int)param_1_00 + 0x75b8) = 1;
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074da80,0xd);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/noautocure",0xb), iVar6 == 0)) {
              *(undefined *)((int)param_1_00 + 0x75b8) = 0;
              goto LAB_00486611;
            }
            iVar6 = _strncmp(param_1,&DAT_0074da68,9);
            if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/iclear",7), iVar6 == 0)) {
              cVar5 = FUN_0047a970();
              if (cVar5 == '\0') goto LAB_00486611;
              _memset(local_133c,0,0x104);
              iVar6 = _strncmp(param_1,&DAT_0074da68,9);
              if (iVar6 == 0) {
                param_1 = param_1 + 9;
              }
              else {
                param_1 = param_1 + 7;
              }
              FID_conflict__sscanf(param_1,"%s");
              pbVar17 = local_133c;
              do {
                bVar1 = *pbVar17;
                pbVar17 = pbVar17 + 1;
              } while (bVar1 != 0);
              if (pbVar17 == local_133c + 1) {
                pbVar17 = &DAT_009144ce;
              }
              else {
                pbVar17 = local_133c;
              }
              FUN_00420c10(&DAT_007c2338,pbVar17);
              FUN_005ee3c0();
              iVar6 = FUN_00420db0(0x11b);
              if (iVar6 == 0) goto LAB_00486611;
              FUN_00405780();
              local_4 = 0x2f;
            }
            else {
              iVar6 = _strncmp(param_1,&DAT_0074da54,9);
              if ((iVar6 != 0) && (iVar6 = _strncmp(param_1,"/eclear",7), iVar6 != 0)) {
                iVar6 = _strncmp(param_1,&DAT_0074da3c,0xc);
                if (iVar6 == 0) {
                  cVar5 = FUN_0047a970();
                  if (cVar5 == '\0') goto LAB_00486611;
                  iVar6 = _strncmp(param_1,&DAT_0074da3c,0xc);
                  if (iVar6 == 0) {
                    uVar24 = CONCAT44(param_1 + 0xc,local_133c);
                  }
                  else {
                    uVar24 = CONCAT44(param_1 + 10,local_133c);
                  }
                  FUN_0047a9b0(uVar24);
                  uVar15 = FUN_0048a1b0();
                  if ((uVar15 & 0xffff) != 0xffffffff) {
                    FUN_00420c10(&DAT_007c1d38,local_133c);
                    iVar6 = FUN_00420db0();
                    if (iVar6 != 0) {
                      FUN_00405780();
                      local_4 = 0x31;
                      FUN_0047f8b0();
                      local_4 = 0xffffffff;
                      FUN_005535b0();
                    }
                    FUN_005ee900();
                    goto LAB_00486611;
                  }
                }
                else {
                  iVar6 = _strncmp(param_1,"/queston ",9);
                  if (iVar6 == 0) {
                    cVar5 = FUN_0047a970();
                    if (cVar5 != '\0') {
                      FID_conflict__sscanf(param_1,"%s %d",local_1238,&local_13c0);
                      iVar6 = FUN_00489f00();
                      if (iVar6 != 0) {
                        FUN_00420c10(&DAT_007c1d38,*(undefined4 *)(iVar6 + 4));
                        iVar6 = FUN_00420db0();
                        if (iVar6 != 0) {
                          FUN_00405780();
                          local_4 = 0x32;
                          FUN_0047f8b0();
                          local_4 = 0xffffffff;
                          FUN_005535b0();
                        }
                        FUN_005ee900();
                      }
                    }
                    goto LAB_00486611;
                  }
                  iVar6 = _strncmp(param_1,&DAT_0074da18,0xc);
                  if (iVar6 == 0) {
                    cVar5 = FUN_0047a970();
                    if (cVar5 == '\0') goto LAB_00486611;
                    iVar6 = _strncmp(param_1,&DAT_0074da18,0xc);
                    if (iVar6 == 0) {
                      uVar24 = CONCAT44(param_1 + 0xc,local_133c);
                    }
                    else {
                      uVar24 = CONCAT44(param_1 + 0xb,local_133c);
                    }
                    FUN_0047a9b0(uVar24);
                    uVar15 = FUN_0048a1b0();
                    if ((uVar15 & 0xffff) != 0xffffffff) {
                      FUN_00420c10(&DAT_007c1d38,local_133c);
                      iVar6 = FUN_00420db0();
                      if (iVar6 != 0) {
                        FUN_00405780();
                        local_4 = 0x33;
                        FUN_0047f8b0();
                        local_4 = 0xffffffff;
                        FUN_005535b0();
                      }
                      FUN_005ee960();
                      goto LAB_00486611;
                    }
                  }
                  else {
                    iVar6 = _strncmp(param_1,"/questoff ",10);
                    if (iVar6 == 0) {
                      cVar5 = FUN_0047a970();
                      if (cVar5 != '\0') {
                        FID_conflict__sscanf(param_1,"%s %d",local_1238,&local_13c0);
                        iVar6 = FUN_00489f00();
                        if (iVar6 != 0) {
                          FUN_00420c10(&DAT_007c1d38,*(undefined4 *)(iVar6 + 4));
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x34;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005ee960();
                        }
                      }
                      goto LAB_00486611;
                    }
                    iVar6 = _strncmp(param_1,&DAT_0074d9fc,0xc);
                    if (iVar6 != 0) {
                      iVar6 = _strncmp(param_1,"/questadd ",10);
                      if (iVar6 == 0) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          FID_conflict__sscanf(param_1,"%s %s %d");
                          iVar6 = FUN_00489f00();
                          if (iVar6 != 0) {
                            FUN_00420c10(&DAT_007c1d38,*(undefined4 *)(iVar6 + 4));
                            FUN_00420c10(&DAT_007c2338,local_1114);
                            iVar6 = FUN_00420db0();
                            if (iVar6 != 0) {
                              FUN_00405780();
                              local_4 = 0x36;
                              FUN_0047f8b0();
                              local_4 = 0xffffffff;
                              FUN_005535b0();
                            }
                            FUN_005ee4c0(local_1114,local_13c0);
                          }
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,"/pvpon",6);
                      if (iVar6 == 0) {
                        iVar6 = FUN_00420db0();
                        if (iVar6 != 0) {
                          FUN_00405780();
                          local_4 = 0x37;
                          FUN_0047f8b0();
                          local_4 = 0xffffffff;
                          FUN_005535b0();
                        }
                        FUN_005ee9c0();
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,"/pvpoff",7);
                      if (iVar6 == 0) {
                        iVar6 = FUN_00420db0();
                        if (iVar6 != 0) {
                          FUN_00405780();
                          local_4 = 0x38;
                          FUN_0047f8b0();
                          local_4 = 0xffffffff;
                          FUN_005535b0();
                        }
                        FUN_005eea10();
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d9c4,0xc);
                      if (iVar6 == 0) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 == '\0') goto LAB_00486611;
                        _memset(&local_1218,0,0x104);
                        iVar6 = _strncmp(param_1,&DAT_0074d9c4,0xc);
                        if (iVar6 == 0) {
                          FID_conflict__sscanf(param_1 + 0xc,"%s");
                          pbVar17 = local_133c;
                          do {
                            bVar1 = *pbVar17;
                            pbVar17 = pbVar17 + 1;
                          } while (bVar1 != 0);
                          uVar24 = CONCAT44(param_1 + (int)(pbVar17 + (0xd - (int)(local_133c + 1)))
                                            ,&local_1218);
                        }
                        else {
                          FID_conflict__sscanf(param_1 + 10,"%s");
                          pbVar17 = local_133c;
                          do {
                            bVar1 = *pbVar17;
                            pbVar17 = pbVar17 + 1;
                          } while (bVar1 != 0);
                          uVar24 = CONCAT44(param_1 + (int)(pbVar17 + (0xb - (int)(local_133c + 1)))
                                            ,&local_1218);
                        }
                        FUN_0047a9b0(uVar24);
                        uVar15 = FUN_0048a1b0();
                        if ((uVar15 & 0xffff) != 0xffffffff) {
                          FUN_00420c10(&DAT_007c2338,local_133c);
                          FUN_00420c10(&DAT_007c1d38,&local_1218);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x39;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eedc0(local_133c,uVar15 & 0xffff);
                          goto LAB_00486611;
                        }
                        goto LAB_004814a0;
                      }
                      iVar6 = _strncmp(param_1,"/questrem ",10);
                      if (iVar6 == 0) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          FID_conflict__sscanf(param_1,"%s %s %d");
                          iVar6 = FUN_00489f00();
                          if (iVar6 != 0) {
                            FUN_00420c10(&DAT_007c1d38,*(undefined4 *)(iVar6 + 4));
                            FUN_00420c10(&DAT_007c2338,local_1114);
                            iVar6 = FUN_00420db0();
                            if (iVar6 != 0) {
                              FUN_00405780();
                              local_4 = 0x3a;
                              FUN_0047f8b0();
                              local_4 = 0xffffffff;
                              FUN_005535b0();
                            }
                            FUN_005eedc0(local_1114,local_13c0);
                          }
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d9a8,0xc);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/event on ",10), iVar6 == 0)) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          iVar6 = _strncmp(param_1,&DAT_0074d9a8,0xc);
                          if (iVar6 == 0) {
                            uVar24 = CONCAT44(param_1 + 0xc,local_133c);
                          }
                          else {
                            uVar24 = CONCAT44(param_1 + 10,local_133c);
                          }
                          FUN_0047a9b0(uVar24);
                          FUN_00420c10(&DAT_007c1d38,local_133c);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x3b;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eec30();
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d98c,0xc);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/event off ",0xb), iVar6 == 0))
                      {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          iVar6 = _strncmp(param_1,&DAT_0074d98c,0xc);
                          if (iVar6 == 0) {
                            uVar24 = CONCAT44(param_1 + 0xc,local_133c);
                          }
                          else {
                            uVar24 = CONCAT44(param_1 + 0xb,local_133c);
                          }
                          FUN_0047a9b0(uVar24);
                          FUN_00420c10(&DAT_007c1d38,local_133c);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x3c;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eecb0();
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d970,0xc);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/eventadd ",0xb), iVar6 == 0))
                      {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          _memset(&local_1218,0,0x104);
                          iVar6 = _strncmp(param_1,&DAT_0074d970,0xc);
                          if (iVar6 == 0) {
                            FID_conflict__sscanf(param_1 + 0xc,"%s");
                            pbVar17 = local_133c;
                            do {
                              bVar1 = *pbVar17;
                              pbVar17 = pbVar17 + 1;
                            } while (bVar1 != 0);
                            uVar24 = CONCAT44(param_1 + (int)(pbVar17 +
                                                             (0xd - (int)(local_133c + 1))),
                                              &local_1218);
                          }
                          else {
                            FID_conflict__sscanf(param_1 + 10,"%s");
                            pbVar17 = local_133c;
                            do {
                              bVar1 = *pbVar17;
                              pbVar17 = pbVar17 + 1;
                            } while (bVar1 != 0);
                            uVar24 = CONCAT44(param_1 + (int)(pbVar17 +
                                                             (0xb - (int)(local_133c + 1))),
                                              &local_1218);
                          }
                          FUN_0047a9b0(uVar24);
                          FUN_00420c10(&DAT_007c2338,local_133c);
                          FUN_00420c10(&DAT_007c1d38,&local_1218);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x3d;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eead0(local_133c,&local_1218);
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d954,0xc);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/eventrem ",0xb), iVar6 == 0))
                      {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          _memset(&local_1218,0,0x104);
                          iVar6 = _strncmp(param_1,&DAT_0074d954,0xc);
                          if (iVar6 == 0) {
                            FID_conflict__sscanf(param_1 + 0xc,"%s");
                            pbVar17 = local_133c;
                            do {
                              bVar1 = *pbVar17;
                              pbVar17 = pbVar17 + 1;
                            } while (bVar1 != 0);
                            uVar24 = CONCAT44(param_1 + (int)(pbVar17 +
                                                             (0xd - (int)(local_133c + 1))),
                                              &local_1218);
                          }
                          else {
                            FID_conflict__sscanf(param_1 + 10,"%s");
                            pbVar17 = local_133c;
                            do {
                              bVar1 = *pbVar17;
                              pbVar17 = pbVar17 + 1;
                            } while (bVar1 != 0);
                            uVar24 = CONCAT44(param_1 + (int)(pbVar17 +
                                                             (0xb - (int)(local_133c + 1))),
                                              &local_1218);
                          }
                          FUN_0047a9b0(uVar24);
                          FUN_00420c10(&DAT_007c2338,local_133c);
                          FUN_00420c10(&DAT_007c1d38,&local_1218);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x3e;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eeb80(local_133c,&local_1218);
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d940,4);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/kick ",6), iVar6 == 0)) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          iVar6 = _strncmp(param_1,&DAT_0074d940,4);
                          if (iVar6 == 0) {
                            param_1 = param_1 + 4;
                          }
                          else {
                            param_1 = param_1 + 6;
                          }
                          FID_conflict__sscanf(param_1,"%s");
                          FUN_00420c10(&DAT_007c2338,local_133c);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x3f;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005ee340();
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d92c,8);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/bancan ",8), iVar6 == 0)) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          param_1 = param_1 + 8;
                          FID_conflict__sscanf(param_1,"%s");
                          uVar24 = CONCAT44(param_1,local_133c);
                          puVar23 = &DAT_007c2338;
                          FUN_00420c10();
                          iVar6 = FUN_00420db0(0x124,puVar23,uVar24);
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x40;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005ee770();
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d918,4);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/ban ",5), iVar6 == 0)) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          local_13c0 = 0.0;
                          iVar6 = _strncmp(param_1,&DAT_0074d918,4);
                          if (iVar6 == 0) {
                            uVar24 = CONCAT44(local_133c,&local_13c0);
                            param_1 = param_1 + 4;
                          }
                          else {
                            uVar24 = CONCAT44(local_133c,&local_13c0);
                            param_1 = param_1 + 5;
                          }
                          FID_conflict__sscanf(param_1,"%d %s",uVar24);
                          FUN_00420c10(&DAT_007c2338,local_133c);
                          DAT_007c273c = (float)((uint)local_13c0 & 0xffff);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x41;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005ee6e0(local_13c0,local_133c);
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d908,6);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/set ",5), iVar6 == 0)) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 != '\0') {
                          local_1218 = 0;
                          iVar6 = _strncmp(param_1,&DAT_0074d908,6);
                          if (iVar6 == 0) {
                            param_1 = param_1 + 6;
                          }
                          else {
                            param_1 = param_1 + 5;
                          }
                          FID_conflict__sscanf(param_1,"%s %s %d");
                          cVar5 = FUN_0047aba0();
                          local_13bc = (float)CONCAT31(local_13bc._1_3_,cVar5);
                          if (cVar5 == 'd') {
                            FUN_00423150();
                          }
                          else {
                            FUN_00420c10(&DAT_007c2338,local_133c);
                            FUN_00420c10(&DAT_007c1d38,&local_1218);
                            iVar6 = FUN_00420db0();
                            if (iVar6 != 0) {
                              FUN_00405780();
                              local_4 = 0x42;
                              FUN_0047f8b0();
                              local_4 = 0xffffffff;
                              FUN_005535b0();
                            }
                            FUN_005eed30();
                          }
                        }
                        goto LAB_00486611;
                      }
                      iVar6 = _strncmp(param_1,&DAT_0074d8f8,6);
                      if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/imake ",7), iVar6 == 0)) {
                        cVar5 = FUN_0047a970();
                        if (cVar5 == '\0') goto LAB_00486611;
                        local_13c0 = 1.4013e-45;
                        iVar6 = _strncmp(param_1,&DAT_0074d8f8,6);
                        if (iVar6 == 0) {
                          uVar24 = CONCAT44(param_1 + 6,local_133c);
                        }
                        else {
                          uVar24 = CONCAT44(param_1 + 7,local_133c);
                        }
                        pcVar7 = "%d";
                        pcVar9 = (char *)FUN_0047a9b0(uVar24);
                        FID_conflict__sscanf(pcVar9,pcVar7);
                        cVar5 = FUN_0046cc10();
                        if (cVar5 != '\0') {
                          FUN_00420c10(&DAT_007c1d38,local_133c);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x43;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eea60();
                          goto LAB_00486611;
                        }
                      }
                      else {
                        iVar6 = _strncmp(param_1,&DAT_0074d8e0,0xc);
                        if ((iVar6 != 0) &&
                           (iVar6 = _strncmp(param_1,"/recallitem ",0xc), iVar6 != 0)) {
                          iVar6 = _strncmp(param_1,"/onekillon",10);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              FUN_005ef420();
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,"/onekilloff",0xb);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              FUN_005ef420();
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,&DAT_0074d8ac,8);
                          if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/getitem ",9), iVar6 == 0))
                          {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              local_13b8[0] = 0;
                              local_13c0 = 0.0;
                              local_13bc = 1.4013e-45;
                              iVar6 = _strncmp(param_1,&DAT_0074d8ac,8);
                              if (iVar6 == 0) {
                                uVar25 = CONCAT44(&local_13bc,&local_13c0);
                                uVar24 = CONCAT44(local_13b8,local_1238);
                              }
                              else {
                                uVar25 = CONCAT44(&local_13bc,&local_13c0);
                                uVar24 = CONCAT44(local_13b8,local_1238);
                              }
                              FID_conflict__sscanf(param_1,"%s %d %d %d",uVar24,uVar25);
                              if ((int)local_13bc < 1) {
                                local_13bc = 1.4013e-45;
                              }
                              puVar16 = (undefined4 *)FUN_0046cb30(local_13b8[0],local_13c0);
                              if (puVar16 != (undefined4 *)0x0) {
                                pcVar9 = (char *)*puVar16;
                                pcVar7 = pcVar9;
                                do {
                                  cVar5 = *pcVar7;
                                  pcVar7 = pcVar7 + 1;
                                } while (cVar5 != '\0');
                                if (pcVar7 == pcVar9 + 1) {
                                  FUN_00423150();
                                }
                                else {
                                  FUN_00420c10(&DAT_007c1d38,pcVar9);
                                  iVar6 = FUN_00420db0();
                                  if (iVar6 != 0) {
                                    FUN_00405780();
                                    local_4 = 0x45;
                                    FUN_0047f8b0();
                                    local_4 = 0xffffffff;
                                    FUN_005535b0();
                                  }
                                  FUN_005eea60();
                                }
                              }
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,"/mmake ",7);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              local_1114[0] = '\0';
                              _memset(local_1114 + 1,0,0x103);
                              local_13bc = 0.0;
                              local_13c0 = 1.4013e-45;
                              FID_conflict__sscanf
                                        (param_1,"%s %hu %d",local_1114,&local_13bc,&local_13c0);
                              if ((int)local_13c0 < 1) {
                                local_13c0 = 1.4013e-45;
                              }
                              puVar16 = (undefined4 *)FUN_0046cca0();
                              if (puVar16 != (undefined4 *)0x0) {
                                FUN_00420c10(&DAT_007c1d38,*puVar16);
                                iVar6 = FUN_00420db0();
                                if (iVar6 != 0) {
                                  FUN_00405780();
                                  local_4 = 0x46;
                                  FUN_0047f8b0();
                                  local_4 = 0xffffffff;
                                  FUN_005535b0();
                                }
                                FUN_005eeee0(local_13bc,local_13c0);
                              }
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,&DAT_0074d880,8);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 == '\0') goto LAB_00486611;
                            local_13c0 = 1.4013e-45;
                            iVar6 = _strncmp(param_1,&DAT_0074d880,8);
                            if (iVar6 == 0) {
                              uVar24 = CONCAT44(param_1 + 8,local_133c);
                            }
                            else {
                              uVar24 = CONCAT44(param_1 + 7,local_133c);
                            }
                            pcVar7 = "%d";
                            pcVar9 = (char *)FUN_0047a9b0(uVar24);
                            FID_conflict__sscanf(pcVar9,pcVar7);
                            iVar6 = FUN_0046cd30();
                            if (iVar6 != -1) {
                              FUN_00420c10(&DAT_007c1d38,local_133c);
                              iVar11 = FUN_00420db0();
                              if (iVar11 != 0) {
                                FUN_00405780();
                                local_4 = 0x47;
                                FUN_0047f8b0();
                                local_4 = 0xffffffff;
                                FUN_005535b0();
                              }
                              FUN_005eeee0(iVar6,local_13c0);
                              goto LAB_00486611;
                            }
LAB_00482153:
                            FUN_00420c10(&DAT_007c1d38,local_133c);
                            FUN_00423150();
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,&DAT_0074d874,9);
                          if ((iVar6 == 0) || (iVar6 = _strncmp(param_1,"/mera t",7), iVar6 == 0)) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              if ((((*(int *)(DAT_00904aa0 + 0x188) == -1) || (DAT_00913464 != 0))
                                  || (iVar6 = FUN_00452b90(), iVar6 == 0)) ||
                                 (iVar6 = FUN_0046cca0(), iVar6 == 0)) {
                                FUN_00423150();
                              }
                              else {
                                FUN_00420c10(&DAT_007c1d38,local_133c);
                                iVar6 = FUN_00420db0();
                                if (iVar6 != 0) {
                                  FUN_00405780();
                                  local_4 = 0x48;
                                  FUN_0047f8b0();
                                  local_4 = 0xffffffff;
                                  FUN_005535b0();
                                }
                                FUN_005eefa0();
                              }
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,&DAT_0074d860,8);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              pcVar7 = "%d";
                              local_13c0 = 1.4013e-45;
                              pcVar9 = (char *)FUN_0047a9b0(local_133c);
                              FID_conflict__sscanf(pcVar9,pcVar7);
                              iVar6 = FUN_0046cd30();
                              if (iVar6 == -1) {
                                FUN_00420c10(&DAT_007c1d38,local_133c);
                                FUN_00423150();
                              }
                              else {
                                FUN_00420c10(&DAT_007c1d38,local_133c);
                                iVar11 = FUN_00420db0();
                                if (iVar11 != 0) {
                                  FUN_00405780();
                                  local_4 = 0x49;
                                  FUN_0047f8b0();
                                  local_4 = 0xffffffff;
                                  FUN_005535b0();
                                }
                                FUN_005eef40(iVar6,local_13c0);
                              }
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,"/mera ",6);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 != '\0') {
                              uVar24 = CONCAT44(&local_13bc,&local_13c0);
                              pcVar7 = "%d %d";
                              local_13bc = 1.4013e-45;
                              local_13c0 = 0.0;
                              pcVar9 = (char *)FUN_0047a9b0();
                              FID_conflict__sscanf(pcVar9,pcVar7,uVar24);
                              puVar16 = (undefined4 *)FUN_0046cca0();
                              if (puVar16 == (undefined4 *)0x0) {
                                pcVar9 = (char *)&local_1394;
                                _sprintf(pcVar9,"%d");
                                uVar24 = CONCAT44(pcVar9,&local_1394);
                                puVar23 = &DAT_007c1d38;
                                FUN_00420c10();
                                FUN_00423150(0x29,0x144,0x34,puVar23,uVar24);
                              }
                              else {
                                uVar15 = (uint)local_13c0 & 0xffff;
                                FUN_00420c10(&DAT_007c1d38,*puVar16);
                                iVar6 = FUN_00420db0();
                                if (iVar6 != 0) {
                                  FUN_00405780();
                                  local_4 = 0x4a;
                                  FUN_0047f8b0();
                                  local_4 = 0xffffffff;
                                  FUN_005535b0();
                                }
                                FUN_005eef40(uVar15,local_13bc);
                              }
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,"/mmakeall ",10);
                          if (iVar6 == 0) {
                            local_1114[0] = '\0';
                            _memset(local_1114 + 1,0,0x103);
                            local_13bc = 0.0;
                            local_13c0 = 1.4013e-45;
                            FID_conflict__sscanf
                                      (param_1,"%s %hu %d",local_1114,&local_13bc,&local_13c0);
                            if ((int)local_13c0 < 1) {
                              local_13c0 = 1.4013e-45;
                            }
                            puVar16 = (undefined4 *)FUN_0046cca0();
                            if (puVar16 != (undefined4 *)0x0) {
                              FUN_00420c10(&DAT_007c1d38,*puVar16);
                              iVar6 = FUN_00420db0();
                              if (iVar6 != 0) {
                                FUN_00405780();
                                local_4 = 0x4b;
                                FUN_0047f8b0();
                                local_4 = 0xffffffff;
                                FUN_005535b0();
                              }
                              FUN_005eeff0(local_13bc,local_13c0);
                            }
                            goto LAB_00486611;
                          }
                          iVar6 = _strncmp(param_1,&DAT_0074d834,0xc);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 == '\0') goto LAB_00486611;
                            local_13c0 = 1.4013e-45;
                            iVar6 = _strncmp(param_1,&DAT_0074d834,0xc);
                            if (iVar6 == 0) {
                              uVar24 = CONCAT44(param_1 + 0xc,local_133c);
                            }
                            else {
                              uVar24 = CONCAT44(param_1 + 0xb,local_133c);
                            }
                            pcVar7 = "%d";
                            pcVar9 = (char *)FUN_0047a9b0(uVar24);
                            FID_conflict__sscanf(pcVar9,pcVar7);
                            iVar6 = FUN_0046cd30();
                            if (iVar6 != -1) {
                              FUN_00420c10(&DAT_007c1d38,local_133c);
                              iVar11 = FUN_00420db0();
                              if (iVar11 != 0) {
                                FUN_00405780();
                                local_4 = 0x4c;
                                FUN_0047f8b0();
                                local_4 = 0xffffffff;
                                FUN_005535b0();
                              }
                              FUN_005eeff0(iVar6,local_13c0);
                              goto LAB_00486611;
                            }
                            goto LAB_00482153;
                          }
                          iVar6 = __strnicmp(param_1,&DAT_0074d828,9);
                          if (iVar6 == 0) {
                            cVar5 = FUN_0047a970();
                            if (cVar5 == '\0') goto LAB_00486611;
                            local_13c0 = 1.4013e-45;
                            iVar6 = __strnicmp(param_1,&DAT_0074d828,9);
                            if (iVar6 == 0) {
                              uVar24 = CONCAT44(param_1 + 9,local_133c);
                            }
                            else {
                              uVar24 = CONCAT44(param_1 + 7,local_133c);
                            }
                            pcVar7 = "%d";
                            pcVar9 = (char *)FUN_0047a9b0(uVar24);
                            FID_conflict__sscanf(pcVar9,pcVar7);
                            iVar6 = FUN_0048a000();
                            if (iVar6 == 0) goto LAB_00482750;
                            FUN_00420c10(&DAT_007c1d38,local_133c);
                            iVar6 = FUN_00420db0();
                            if (iVar6 != 0) {
                              FUN_00405780();
                              local_4 = 0x4d;
                              goto LAB_0048270e;
                            }
                          }
                          else {
                            iVar6 = _strncmp(param_1,"/nmake ",7);
                            if (iVar6 != 0) {
                              iVar6 = __strnicmp(param_1,&DAT_0074d808,9);
                              if (iVar6 != 0) {
                                iVar6 = _strncmp(param_1,"/nera ",6);
                                if (iVar6 == 0) {
                                  cVar5 = FUN_0047a970();
                                  if (cVar5 != '\0') {
                                    uVar24 = CONCAT44(local_13b8,&local_13bc);
                                    pcVar7 = "%d %d";
                                    local_13bc = 0.0;
                                    local_13b8[0] = 0;
                                    pcVar9 = (char *)FUN_0047a9b0();
                                    FID_conflict__sscanf(pcVar9,pcVar7,uVar24);
                                    iVar6 = FUN_00489ed0(local_13bc,local_13b8[0]);
                                    if (iVar6 == 0) {
                                      iVar6 = FUN_00489e90();
                                      if (iVar6 == 0) {
                                        iVar6 = FUN_00489eb0();
                                        if (iVar6 == 0) {
                                          _sprintf((char *)&local_1394,"%d %d",local_13bc,
                                                   local_13b8[0]);
                                          FUN_00420c10(&DAT_007c1d38,&local_1394);
                                          FUN_00423150(0x29,0x145,5);
                                        }
                                        else {
                                          FUN_00420c10(&DAT_007c1d38,_DAT_00000018);
                                          iVar6 = FUN_00420db0();
                                          if (iVar6 != 0) {
                                            FUN_00405780();
                                            local_4 = 0x52;
                                            FUN_0047f8b0();
                                            local_4 = 0xffffffff;
                                            FUN_005535b0();
                                          }
                                          FUN_005ef0c0();
                                        }
                                      }
                                      else {
                                        FUN_00420c10(&DAT_007c1d38,*(undefined4 *)(iVar6 + 0x18));
                                        iVar6 = FUN_00420db0();
                                        if (iVar6 != 0) {
                                          FUN_00405780();
                                          local_4 = 0x51;
                                          FUN_0047f8b0();
                                          local_4 = 0xffffffff;
                                          FUN_005535b0();
                                        }
                                        FUN_005ef0c0();
                                      }
                                    }
                                    else {
                                      FUN_00420c10(&DAT_007c1d38,*(undefined4 *)(iVar6 + 0x14));
                                      iVar6 = FUN_00420db0();
                                      if (iVar6 != 0) {
                                        FUN_00405780();
                                        local_4 = 0x50;
                                        FUN_0047f8b0();
                                        local_4 = 0xffffffff;
                                        FUN_005535b0();
                                      }
                                      FUN_005ef0c0();
                                    }
                                  }
                                }
                                else {
                                  iVar6 = _strncmp(param_1,&DAT_0074d7f4,8);
                                  if ((iVar6 == 0) ||
                                     (iVar6 = _strncmp(param_1,"/akick ",7), iVar6 == 0)) {
                                    cVar5 = FUN_0047a970();
                                    if (cVar5 != '\0') {
                                      iVar6 = _strncmp(param_1,&DAT_0074d7f4,8);
                                      if (iVar6 == 0) {
                                        param_1 = param_1 + 8;
                                      }
                                      else {
                                        param_1 = param_1 + 7;
                                      }
                                      FID_conflict__sscanf(param_1,"%s");
                                      FUN_00420c10(&DAT_007c2338,local_133c);
                                      iVar6 = FUN_00420db0();
                                      if (iVar6 != 0) {
                                        FUN_00405780();
                                        local_4 = 0x53;
                                        FUN_0047f8b0();
                                        local_4 = 0xffffffff;
                                        FUN_005535b0();
                                      }
                                      FUN_005ef470();
                                    }
                                  }
                                  else {
                                    iVar6 = _strncmp(param_1,&DAT_0074d7dc,0xc);
                                    if ((iVar6 == 0) ||
                                       (iVar6 = _strncmp(param_1,"/abancan ",9), iVar6 == 0)) {
                                      cVar5 = FUN_0047a970();
                                      if (cVar5 != '\0') {
                                        iVar6 = _strncmp(param_1,&DAT_0074d7dc,0xc);
                                        if (iVar6 == 0) {
                                          param_1 = param_1 + 0xc;
                                        }
                                        else {
                                          param_1 = param_1 + 9;
                                        }
                                        FID_conflict__sscanf(param_1,"%s");
                                        FUN_00420c10(&DAT_007c2338,local_133c);
                                        iVar6 = FUN_00420db0();
                                        if (iVar6 != 0) {
                                          FUN_00405780();
                                          local_4 = 0x54;
                                          FUN_0047f8b0();
                                          local_4 = 0xffffffff;
                                          FUN_005535b0();
                                        }
                                        FUN_005ef4f0();
                                      }
                                    }
                                    else {
                                      iVar6 = _strncmp(param_1,&DAT_0074d7c4,8);
                                      if ((iVar6 == 0) ||
                                         (iVar6 = _strncmp(param_1,"/aban ",6), iVar6 == 0)) {
                                        cVar5 = FUN_0047a970();
                                        if (cVar5 != '\0') {
                                          local_13c0 = 0.0;
                                          iVar6 = _strncmp(param_1,&DAT_0074d7c4,8);
                                          if (iVar6 == 0) {
                                            uVar24 = CONCAT44(local_133c,&local_13c0);
                                            param_1 = param_1 + 8;
                                          }
                                          else {
                                            uVar24 = CONCAT44(local_133c,&local_13c0);
                                            param_1 = param_1 + 6;
                                          }
                                          FID_conflict__sscanf(param_1,"%d %s",uVar24);
                                          FUN_00420c10(&DAT_007c2338,local_133c);
                                          DAT_007c273c = (float)((uint)local_13c0 & 0xffff);
                                          iVar6 = FUN_00420db0();
                                          if (iVar6 != 0) {
                                            FUN_00405780();
                                            local_4 = 0x55;
                                            FUN_0047f8b0();
                                            local_4 = 0xffffffff;
                                            FUN_005535b0();
                                          }
                                          FUN_005ef570(local_13c0,local_133c);
                                        }
                                      }
                                      else {
                                        iVar6 = _strncmp(param_1,&DAT_0074d7ac,0xd);
                                        if ((iVar6 == 0) ||
                                           (iVar6 = _strncmp(param_1,"/server on",9), iVar6 == 0)) {
                                          cVar5 = FUN_0047a970();
                                          if (cVar5 != '\0') {
                                            iVar6 = FUN_00420db0();
                                            if (iVar6 != 0) {
                                              FUN_00405780();
                                              local_4 = 0x56;
                                              FUN_0047f8b0();
                                              local_4 = 0xffffffff;
                                              FUN_005535b0();
                                            }
                                            FUN_005ef130();
                                          }
                                        }
                                        else {
                                          iVar6 = _strncmp(param_1,&DAT_0074d794,9);
                                          if ((iVar6 == 0) ||
                                             (iVar6 = _strncmp(param_1,"/server off",10), iVar6 == 0
                                             )) {
                                            cVar5 = FUN_0047a970();
                                            if (cVar5 != '\0') {
                                              iVar6 = FUN_00420db0();
                                              if (iVar6 != 0) {
                                                FUN_00405780();
                                                local_4 = 0x57;
                                                FUN_0047f8b0();
                                                local_4 = 0xffffffff;
                                                FUN_005535b0();
                                              }
                                              FUN_005ef180();
                                            }
                                          }
                                          else {
                                            iVar6 = _strncmp(param_1,&DAT_0074d77c,9);
                                            if ((iVar6 == 0) ||
                                               (iVar6 = _strncmp(param_1,"/shutdown",9), iVar6 == 0)
                                               ) {
                                              cVar5 = FUN_0047a970();
                                              if (cVar5 != '\0') {
                                                iVar6 = FUN_00420db0();
                                                if (iVar6 != 0) {
                                                  FUN_00405780();
                                                  local_4 = 0x58;
                                                  FUN_0047f8b0();
                                                  local_4 = 0xffffffff;
                                                  FUN_005535b0();
                                                }
                                                FUN_005ef1d0();
                                              }
                                            }
                                            else {
                                              iVar6 = __strnicmp(param_1,"/chatcolor",10);
                                              if (iVar6 != 0) {
                                                pcVar7 = (char *)FUN_00420db0();
                                                pcVar9 = pcVar7 + 1;
                                                do {
                                                  cVar5 = *pcVar7;
                                                  pcVar7 = pcVar7 + 1;
                                                } while (cVar5 != '\0');
                                                sVar8 = (int)pcVar7 - (int)pcVar9;
                                                pcVar9 = (char *)FUN_00420db0(0x19cf);
                                                iVar6 = _strncmp(param_1,pcVar9,sVar8);
                                                if (iVar6 != 0) {
                                                  iVar6 = __strnicmp(param_1,"/chatcolor off",0xe);
                                                  if (iVar6 != 0) {
                                                    pcVar7 = (char *)FUN_00420db0();
                                                    pcVar9 = pcVar7 + 1;
                                                    do {
                                                      cVar5 = *pcVar7;
                                                      pcVar7 = pcVar7 + 1;
                                                    } while (cVar5 != '\0');
                                                    sVar8 = (int)pcVar7 - (int)pcVar9;
                                                    pcVar9 = (char *)FUN_00420db0(0x19d0);
                                                    iVar6 = _strncmp(param_1,pcVar9,sVar8);
                                                    if (iVar6 != 0) {
                                                      iVar6 = __strnicmp(param_1,"/camlimit on",0xc)
                                                      ;
                                                      if (iVar6 == 0) {
                                                        _DAT_00906d40 = 1;
                                                      }
                                                      else {
                                                        iVar6 = __strnicmp(param_1,"/camlimit off",
                                                                           0xd);
                                                        if (iVar6 == 0) {
                                                          _DAT_00906d40 = 0;
                                                        }
                                                        else {
                                                          iVar6 = _strncmp(param_1,&DAT_0074d744,10)
                                                          ;
                                                          if ((iVar6 == 0) ||
                                                             (iVar6 = _strncmp(param_1,"/apower ",8)
                                                             , iVar6 == 0)) {
                                                            cVar5 = FUN_0047a970();
                                                            if (cVar5 != '\0') {
                                                              iVar6 = _strncmp(param_1,&DAT_0074d744
                                                                               ,10);
                                                              if (iVar6 == 0) {
                                                                uVar24 = CONCAT44(local_133c,
                                                                                  &local_13c0);
                                                                param_1 = param_1 + 10;
                                                              }
                                                              else {
                                                                uVar24 = CONCAT44(local_133c,
                                                                                  &local_13c0);
                                                                param_1 = param_1 + 8;
                                                              }
                                                              FID_conflict__sscanf
                                                                        (param_1,"%d %s",uVar24);
                                                              FUN_00420c10(&DAT_007c2338,local_133c)
                                                              ;
                                                              DAT_007c273c = local_13c0;
                                                              iVar6 = FUN_00420db0();
                                                              if (iVar6 != 0) {
                                                                FUN_00405780();
                                                                local_4 = 0x59;
                                                                FUN_0047f8b0();
                                                                local_4 = 0xffffffff;
                                                                FUN_005535b0();
                                                              }
                                                              FUN_005ef680(local_133c,local_13c0);
                                                            }
                                                          }
                                                          else {
                                                            iVar6 = _strncmp(param_1,&DAT_0074d72c,
                                                                             10);
                                                            if ((iVar6 == 0) ||
                                                               (iVar6 = _strncmp(param_1,
                                                  "/apowercan ",0xb), iVar6 == 0)) {
                                                    cVar5 = FUN_0047a970();
                                                    if (cVar5 != '\0') {
                                                      iVar6 = _strncmp(param_1,&DAT_0074d72c,10);
                                                      if (iVar6 == 0) {
                                                        param_1 = param_1 + 10;
                                                      }
                                                      else {
                                                        param_1 = param_1 + 0xb;
                                                      }
                                                      FID_conflict__sscanf(param_1,"%s");
                                                      FUN_00420c10(&DAT_007c2338,local_133c);
                                                      iVar6 = FUN_00420db0();
                                                      if (iVar6 != 0) {
                                                        FUN_00405780();
                                                        local_4 = 0x5a;
                                                        FUN_0047f8b0();
                                                        local_4 = 0xffffffff;
                                                        FUN_005535b0();
                                                      }
                                                      FUN_005ef700();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = _strncmp(param_1,&DAT_0074d714,8);
                                                    if (((iVar6 == 0) ||
                                                        (iVar6 = _strncmp(param_1,"/cmd ",5),
                                                        iVar6 == 0)) &&
                                                       (cVar5 = FUN_0047a970(), cVar5 != '\0')) {
                                                      _strncmp(param_1,&DAT_0074d714,10);
                                                      _sprintf((char *)local_133c,"%s");
                                                      FUN_005ef600();
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00486611;
                                                  }
                                                  }
                                                  *(undefined4 *)((int)param_1_00 + 0x75c8) = 0;
                                                  FUN_00423150();
                                                  goto LAB_00486611;
                                                }
                                              }
                                              local_13c0 = 0.0;
                                              iVar6 = __strnicmp(param_1,"/chatcolor",10);
                                              if (iVar6 == 0) {
                                                param_1 = param_1 + 10;
                                              }
                                              else {
                                                pcVar7 = (char *)FUN_00420db0();
                                                pcVar9 = pcVar7 + 1;
                                                do {
                                                  cVar5 = *pcVar7;
                                                  pcVar7 = pcVar7 + 1;
                                                } while (cVar5 != '\0');
                                                param_1 = param_1 + ((int)pcVar7 - (int)pcVar9);
                                              }
                                              FID_conflict__sscanf(param_1," %d");
                                              if ((int)local_13c0 < 9) {
                                                *(float *)((int)param_1_00 + 0x75c8) = local_13c0;
                                                if (1 < (int)local_13c0) {
                                                  *(int *)((int)param_1_00 + 0x75c8) =
                                                       (int)local_13c0 + 1;
                                                }
                                                if (0 < (int)local_13c0) {
                                                  FUN_00423150();
                                                }
                                              }
                                              if ((local_13c0 == 0.0) || (8 < (int)local_13c0)) {
                                                FUN_00423150();
                                                *(undefined4 *)((int)param_1_00 + 0x75c8) = 0;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                goto LAB_00486611;
                              }
                              cVar5 = FUN_0047a970();
                              if (cVar5 == '\0') goto LAB_00486611;
                              pcVar7 = "%d";
                              local_13c0 = 1.4013e-45;
                              pcVar9 = (char *)FUN_0047a9b0(local_133c);
                              FID_conflict__sscanf(pcVar9,pcVar7);
                              iVar6 = FUN_0048a000();
                              if (iVar6 != 0) {
                                FUN_00420c10(&DAT_007c1d38,local_133c);
                                iVar6 = FUN_00420db0();
                                if (iVar6 != 0) {
                                  FUN_00405780();
                                  local_4 = 0x4f;
                                  FUN_0047f8b0();
                                  local_4 = 0xffffffff;
                                  FUN_005535b0();
                                }
                                FUN_005ef0c0();
                                goto LAB_00486611;
                              }
LAB_00482750:
                              FUN_00420c10(&DAT_007c1d38,local_133c);
                              FUN_00423150();
                              goto LAB_00486611;
                            }
                            cVar5 = FUN_0047a970();
                            if (cVar5 == '\0') goto LAB_00486611;
                            local_13b8[0] = 0;
                            local_13bc = 0.0;
                            local_13c0 = 1.4013e-45;
                            FID_conflict__sscanf
                                      (param_1,"%s %d %d",local_1238,local_13b8,&local_13bc,
                                       &local_13c0);
                            if (local_13c0 == 0.0) {
                              local_13c0 = 1.4013e-45;
                            }
                            switch(local_13b8[0]) {
                            case 1:
                              iVar6 = FUN_00489e90();
                              if (iVar6 != 0) {
                                uVar10 = *(undefined4 *)(iVar6 + 0x18);
LAB_00482840:
                                FUN_00420c10(&DAT_007c1d38,uVar10);
                              }
                              break;
                            case 2:
                              iVar6 = FUN_00489eb0();
                              if (iVar6 != 0) {
                                uVar10 = *(undefined4 *)(iVar6 + 0x14);
                                goto LAB_00482840;
                              }
                              break;
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                            case 10:
                            case 0xb:
                            case 0xc:
                            case 0xd:
                              iVar6 = FUN_00489ed0(local_13b8[0],local_13bc);
                              if (iVar6 != 0) {
                                uVar10 = *(undefined4 *)(iVar6 + 0x14);
                                goto LAB_00482840;
                              }
                            }
                            iVar6 = FUN_00420db0();
                            if (iVar6 != 0) {
                              FUN_00405780();
                              local_4 = 0x4e;
LAB_0048270e:
                              FUN_0047f8b0();
                              local_4 = 0xffffffff;
                              FUN_005535b0();
                            }
                          }
                          FUN_005ef050();
                          goto LAB_00486611;
                        }
                        cVar5 = FUN_0047a970();
                        if (cVar5 == '\0') goto LAB_00486611;
                        _memset(&local_1218,0,0x104);
                        _strncmp(param_1,&DAT_0074d8e0,0xc);
                        FID_conflict__sscanf(param_1 + 0xc,"%s");
                        pcVar9 = (char *)&local_1218;
                        do {
                          cVar5 = *pcVar9;
                          pcVar9 = pcVar9 + 1;
                        } while (cVar5 != '\0');
                        FUN_0047a9b0(local_133c,
                                     param_1 + (int)(pcVar9 + (0xd - ((int)&local_1218 + 1))));
                        cVar5 = FUN_0046cc10();
                        if (cVar5 != '\0') {
                          FUN_00420c10(&DAT_007c2338,&local_1218);
                          FUN_00420c10(&DAT_007c2538,local_133c);
                          iVar6 = FUN_00420db0();
                          if (iVar6 != 0) {
                            FUN_00405780();
                            local_4 = 0x44;
                            FUN_0047f8b0();
                            local_4 = 0xffffffff;
                            FUN_005535b0();
                          }
                          FUN_005eee50();
                          goto LAB_00486611;
                        }
                      }
                      FUN_00420c10(&DAT_007c2538,local_133c);
                      FUN_00423150();
                      goto LAB_00486611;
                    }
                    cVar5 = FUN_0047a970();
                    if (cVar5 == '\0') goto LAB_00486611;
                    _memset(&local_1218,0,0x104);
                    iVar6 = _strncmp(param_1,&DAT_0074d9fc,0xc);
                    if (iVar6 == 0) {
                      FID_conflict__sscanf(param_1 + 0xc,"%s");
                      pbVar17 = local_133c;
                      do {
                        bVar1 = *pbVar17;
                        pbVar17 = pbVar17 + 1;
                      } while (bVar1 != 0);
                      uVar24 = CONCAT44(param_1 + (int)(pbVar17 + (0xd - (int)(local_133c + 1))),
                                        &local_1218);
                    }
                    else {
                      FID_conflict__sscanf(param_1 + 10,"%s");
                      pbVar17 = local_133c;
                      do {
                        bVar1 = *pbVar17;
                        pbVar17 = pbVar17 + 1;
                      } while (bVar1 != 0);
                      uVar24 = CONCAT44(param_1 + (int)(pbVar17 + (0xb - (int)(local_133c + 1))),
                                        &local_1218);
                    }
                    FUN_0047a9b0(uVar24);
                    uVar15 = FUN_0048a1b0();
                    if ((uVar15 & 0xffff) != 0xffffffff) {
                      FUN_00420c10(&DAT_007c2338,local_133c);
                      FUN_00420c10(&DAT_007c1d38,&local_1218);
                      iVar6 = FUN_00420db0();
                      if (iVar6 != 0) {
                        FUN_00405780();
                        local_4 = 0x35;
                        FUN_0047f8b0();
                        local_4 = 0xffffffff;
                        FUN_005535b0();
                      }
                      FUN_005ee4c0(&DAT_007c2338,uVar15 & 0xffff);
                      goto LAB_00486611;
                    }
                  }
                }
LAB_004814a0:
                FUN_00420c10(&DAT_007c1d38,local_133c);
                FUN_00423150();
                goto LAB_00486611;
              }
              cVar5 = FUN_0047a970();
              if (cVar5 == '\0') goto LAB_00486611;
              _memset(local_133c,0,0x104);
              iVar6 = _strncmp(param_1,&DAT_0074da54,9);
              if (iVar6 == 0) {
                param_1 = param_1 + 9;
              }
              else {
                param_1 = param_1 + 7;
              }
              FID_conflict__sscanf(param_1,"%s");
              pbVar17 = local_133c;
              do {
                bVar1 = *pbVar17;
                pbVar17 = pbVar17 + 1;
              } while (bVar1 != 0);
              if (pbVar17 == local_133c + 1) {
                pbVar17 = &DAT_009144ce;
              }
              else {
                pbVar17 = local_133c;
              }
              FUN_00420c10(&DAT_007c2338,pbVar17);
              FUN_005ee440();
              iVar6 = FUN_00420db0(0x11c);
              if (iVar6 == 0) goto LAB_00486611;
              FUN_00405780();
              local_4 = 0x30;
            }
            FUN_0047f8b0();
            FUN_005535b0();
            goto LAB_00486611;
          }
          cVar5 = FUN_0047a970();
          if (cVar5 == '\0') goto LAB_00486611;
          _memset(&local_1218,0,0x104);
          iVar6 = _strncmp(param_1,&DAT_0074df38,0xb);
          if (iVar6 == 0) {
            param_1 = param_1 + 10;
LAB_00484e05:
            FID_conflict__sscanf(param_1,"%s %s %d");
          }
          else {
            if (((((DAT_007ab0d4 != 6) && (DAT_007ab0d4 != 7)) &&
                 ((DAT_007ab0d4 != 10 &&
                  (((DAT_007ab0d4 != 0xc && (DAT_007ab0d4 != 0xd)) && (DAT_007ab0d4 != 0xe)))))) &&
                ((DAT_007ab0d4 != 0xf && (DAT_007ab0d4 != 0x10)))) && (DAT_007ab0d4 != 0x11)) {
LAB_00484e02:
              param_1 = param_1 + 0xd;
              goto LAB_00484e05;
            }
            _memset(local_1114,0,0x104);
            iVar6 = 0;
            iVar11 = 0;
            bVar20 = false;
            bVar2 = false;
            if (*param_1 == '\0') goto LAB_00484e02;
            do {
              if (param_1[iVar6] == '\"') {
                if (bVar20) {
                  bVar20 = false;
                  *(undefined *)((int)&local_1218 + iVar11) = 0;
                  iVar11 = 0;
                  bVar2 = true;
                  iVar6 = iVar6 + 1;
                }
                else {
                  bVar20 = true;
                }
              }
              iVar6 = iVar6 + 1;
              if ((bVar20) && (param_1[iVar6] != '\"')) {
                *(char *)((int)&local_1218 + iVar11) = param_1[iVar6];
                iVar11 = iVar11 + 1;
              }
              if (bVar2) {
                local_1114[iVar11] = param_1[iVar6];
                iVar11 = iVar11 + 1;
              }
            } while ((iVar6 != 200) && (param_1[iVar6] != '\0'));
            if (!bVar2) goto LAB_00484e02;
            local_1114[iVar11] = '\0';
            FID_conflict__sscanf(local_1114,"%s %d",local_133c,&local_13c0);
          }
          uVar26 = 0x14ea;
          uVar10 = FUN_00420db0();
          uVar25 = CONCAT44(uVar26,local_133c);
          puVar23 = &DAT_007c2338;
          FUN_00420c10();
          uVar24 = CONCAT44(puVar23,uVar10);
          puVar23 = &DAT_007c1d38;
          FUN_00420c10();
          iVar6 = FUN_00420db0(0x126,puVar23,uVar24,uVar25);
          if (iVar6 != 0) {
            FUN_00405780();
            local_4 = 0x22;
            FUN_0047f8b0();
            local_4 = 0xffffffff;
            FUN_005535b0();
          }
          FUN_00631bc7(local_133c,local_13c0);
          FUN_005ef2c0();
          goto LAB_00486611;
        }
        cVar5 = FUN_0047a970();
        if (cVar5 == '\0') goto LAB_00486611;
        _memset(&local_1218,0,0x104);
        iVar6 = _strncmp(param_1,&DAT_0074df54,10);
        if (iVar6 == 0) {
          param_1 = param_1 + 10;
LAB_0048502a:
          FID_conflict__sscanf(param_1,"%s %s %d");
        }
        else {
          if ((((((DAT_007ab0d4 != 6) && (DAT_007ab0d4 != 7)) && (DAT_007ab0d4 != 10)) &&
               ((DAT_007ab0d4 != 0xc && (DAT_007ab0d4 != 0xd)))) &&
              ((DAT_007ab0d4 != 0xe && ((DAT_007ab0d4 != 0xf && (DAT_007ab0d4 != 0x10)))))) &&
             (DAT_007ab0d4 != 0x11)) {
LAB_00485027:
            param_1 = param_1 + 0xc;
            goto LAB_0048502a;
          }
          _memset(local_1114,0,0x104);
          iVar6 = 0;
          iVar11 = 0;
          bVar20 = false;
          bVar2 = false;
          if (*param_1 == '\0') goto LAB_00485027;
          do {
            if (param_1[iVar6] == '\"') {
              if (bVar20) {
                bVar20 = false;
                *(undefined *)((int)&local_1218 + iVar11) = 0;
                iVar11 = 0;
                bVar2 = true;
                iVar6 = iVar6 + 1;
              }
              else {
                bVar20 = true;
              }
            }
            iVar6 = iVar6 + 1;
            if ((bVar20) && (param_1[iVar6] != '\"')) {
              *(char *)((int)&local_1218 + iVar11) = param_1[iVar6];
              iVar11 = iVar11 + 1;
            }
            if (bVar2) {
              local_1114[iVar11] = param_1[iVar6];
              iVar11 = iVar11 + 1;
            }
          } while ((iVar6 != 200) && (param_1[iVar6] != '\0'));
          if (!bVar2) goto LAB_00485027;
          local_1114[iVar11] = '\0';
          FID_conflict__sscanf(local_1114,"%s %d",local_133c,&local_13c0);
        }
        uVar26 = 0x14ea;
        uVar10 = FUN_00420db0();
        uVar25 = CONCAT44(uVar26,local_133c);
        puVar23 = &DAT_007c2338;
        FUN_00420c10();
        uVar24 = CONCAT44(puVar23,uVar10);
        puVar23 = &DAT_007c1d38;
        FUN_00420c10();
        iVar6 = FUN_00420db0(0x126,puVar23,uVar24,uVar25);
        if (iVar6 != 0) {
          FUN_00405780();
          local_4 = 0x21;
          FUN_0047f8b0();
          local_4 = 0xffffffff;
          FUN_005535b0();
        }
        FUN_005ef220();
        goto LAB_00486611;
      }
      cVar5 = FUN_0047a970();
      if (cVar5 == '\0') goto LAB_00486611;
      iVar6 = _strncmp(param_1,&DAT_0074df68,8);
      if (iVar6 == 0) {
        FUN_0047a9b0(local_133c,param_1 + 8);
        iVar6 = FUN_0046ccd0();
      }
      else {
        iVar6 = _strncmp(param_1,"/mob ",5);
        if (iVar6 != 0) goto LAB_004851a6;
        FUN_0047a9b0(local_133c,param_1 + 5);
        FUN_00631bbc();
        iVar6 = FUN_0046cca0();
      }
      if (iVar6 != 0) {
        _sprintf(local_1010,"[%s] HP:%d, LV:%d");
        FUN_00422b90();
        goto LAB_00486611;
      }
    }
LAB_004851a6:
    FUN_00423150();
    goto LAB_00486611;
  }
  cVar5 = FUN_0047a970();
  if (cVar5 == '\0') goto LAB_00486611;
  cVar5 = param_1[10];
  local_1390 = 0.0;
  local_138c = 0.0;
  local_1388 = 0;
  local_4 = 4;
  FUN_00405780();
  local_4._0_1_ = 5;
  FUN_0047fd40();
  FUN_005535b0();
  local_1360 = 0xf;
  local_1364 = 0;
  local_1374 = 0;
  local_4 = CONCAT31(local_4._1_3_,8);
  piVar12 = (int *)FUN_0047fe20();
  uVar15 = *(int *)(*piVar12 + 4) + (int)piVar12 &
           ~-(uint)((*(uint *)(*(int *)(*piVar12 + 4) + 8 + (int)piVar12) & 6) != 0);
  fVar3 = 0.0;
  fVar4 = 0.0;
  while (uVar15 != 0) {
    if (local_1364 != 0) {
      FUN_0040cfc0();
    }
    piVar12 = (int *)FUN_0047fe20();
    fVar3 = local_138c;
    fVar4 = local_1390;
    uVar15 = *(int *)(*piVar12 + 4) + (int)piVar12 &
             ~-(uint)((*(uint *)(*(int *)(*piVar12 + 4) + 8 + (int)piVar12) & 6) != 0);
  }
  if (((int)fVar3 - (int)fVar4) / 0x1c == 2) {
    if (*(uint *)((int)fVar4 + 0x34) < 0x10) {
      pcVar9 = (char *)((int)fVar4 + 0x20);
    }
    else {
      pcVar9 = *(char **)((int)fVar4 + 0x20);
    }
    dVar22 = _atof(pcVar9);
    local_13c0 = (float)dVar22;
    FUN_0055e480();
    pfVar13 = (float *)FUN_0055f770();
    if (pfVar13 == (float *)0x0) goto LAB_00480785;
    if (cVar5 == 'x') {
      FUN_00405780();
      uVar24 = CONCAT44(local_13c0,local_135c);
      local_4 = CONCAT31(local_4._1_3_,9);
      FUN_0055e480(local_135c);
      FUN_0055f3e0(uVar24);
LAB_004808ce:
      local_4 = CONCAT31(local_4._1_3_,8);
      FUN_005535b0();
    }
    else {
      if (cVar5 == 'y') {
        FUN_00405780();
        uVar24 = CONCAT44(local_13c0,local_13b0);
        local_4 = CONCAT31(local_4._1_3_,10);
        FUN_0055e480(local_13b0);
        FUN_0055f510(uVar24);
        goto LAB_004808ce;
      }
      if (cVar5 == 'z') {
        FUN_00405780();
        uVar24 = CONCAT44(local_13c0,local_1238);
        local_4 = CONCAT31(local_4._1_3_,0xb);
        FUN_0055e480(local_1238);
        FUN_0055f640(uVar24);
        goto LAB_004808ce;
      }
    }
    _memset(local_1114,0,0x104);
    if (*(uint *)((int)fVar4 + 0x18) < 0x10) {
      iVar6 = (int)fVar4 + 4;
    }
    else {
      iVar6 = *(int *)((int)fVar4 + 4);
    }
    FUN_0047c3b0(local_1114,"Position change success. Name: %s, Pos: %.1f %.1f %.1f",iVar6,
                 (double)*pfVar13,(double)pfVar13[1],(double)pfVar13[2]);
    FUN_004231a0(0x13,local_1114,4);
  }
  else {
LAB_00480785:
    FUN_004231a0();
  }
  FUN_005535b0();
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_0047e890();
  FUN_0040a660();
LAB_00486611:
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
}

