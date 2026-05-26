/*
 * server/ps_game.exe — Dispatch_Packet0200_Handler
 * VA solicitado: 0x00476070
 * Entry Ghidra:  00476070
 * Ghidra name:   FUN_00476070
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00476070(undefined2 *param_1_00,int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined4 uVar7;
  double dVar8;
  char cVar9;
  int *piVar10;
  int iVar11;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD DVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  uint uVar16;
  short extraout_DX;
  char *pcVar17;
  char *pcVar18;
  bool bVar19;
  undefined2 in_FPUControlWord;
  float10 fVar20;
  undefined8 uVar21;
  undefined auStack_114 [4];
  undefined4 local_110;
  undefined4 local_10c;
  int *local_108;
  undefined2 local_104;
  undefined local_102;
  undefined uStack_101;
  undefined2 uStack_100;
  int local_fc;
  undefined2 local_f8;
  undefined local_f6;
  byte local_f5;
  undefined2 local_f4;
  undefined4 local_f2;
  undefined4 local_ee;
  undefined4 local_ea;
  undefined2 local_e4;
  int local_e2;
  undefined local_de;
  undefined8 local_dc;
  undefined2 local_d4;
  undefined2 uStack_d2;
  undefined2 local_d0;
  undefined uStack_ce;
  undefined uStack_cd;
  undefined4 local_cc;
  undefined2 local_c8;
  undefined4 local_c6;
  undefined local_c2;
  undefined local_c1;
  undefined local_c0;
  undefined local_bf;
  undefined2 local_bc;
  undefined4 local_ba;
  char local_b6;
  undefined2 local_b5;
  undefined4 local_b3;
  undefined4 local_af;
  undefined4 local_ab;
  undefined2 local_a4 [43];
  undefined local_4d;
  undefined2 local_4c;
  undefined local_4a;
  undefined4 uStack_49;
  undefined4 uStack_45;
  undefined4 uStack_41;
  undefined2 uStack_3d;
  uint local_14;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00553412;
  local_c = ExceptionList;
  local_14 = DAT_0057f7c4 ^ (uint)auStack_114;
  ExceptionList = &local_c;
  switch(*param_1_00) {
  case 0x204:
    if ((((*(int *)(param_1 + 0x1444) == 1) || (*(char *)(param_1 + 0x1360) == 'd')) ||
        (*(int *)(param_1 + 0x5880) != 0)) ||
       ((*(char *)(param_1_00 + 1) == *(char *)(param_1_00 + 2) &&
        (*(char *)((int)param_1_00 + 3) == *(char *)((int)param_1_00 + 5))))) break;
    FUN_00456610();
    FUN_00487030();
    if ((*(byte *)(param_1_00 + 1) == 100) && (*(byte *)((int)param_1_00 + 3) < 0xf0)) {
      if ((*(byte *)(param_1_00 + 2) == 100) && (*(byte *)((int)param_1_00 + 5) < 0xf0)) {
        if ((*(byte *)((int)param_1_00 + 5) < 0x78) || (*(int *)(param_1 + 0x5968) != 0)) {
          FUN_00469950(100,*(byte *)((int)param_1_00 + 3),100);
        }
      }
      else {
        uVar16 = (uint)*(byte *)(param_1_00 + 2);
        if (((int)uVar16 <= *(int *)(param_1 + 0x130c)) &&
           ((bVar3 = *(byte *)((int)param_1_00 + 5), bVar3 < 0x18 &&
            (*(int *)(param_1 + 0x1c0 + ((uint)bVar3 + uVar16 * 0x18) * 4) == 0)))) {
          FUN_00468e80(100,uVar16,(uint)bVar3);
        }
      }
      break;
    }
    uVar16 = (uint)*(byte *)(param_1_00 + 1);
    if ((*(int *)(param_1 + 0x130c) < (int)uVar16) ||
       (bVar3 = *(byte *)((int)param_1_00 + 3), 0x17 < bVar3)) {
      FUN_00431eb0();
      local_4 = 1;
      if ((*(int *)(param_1 + 0x1810) != 0) &&
         ((*(char *)(param_1_00 + 1) == -1 && (*(byte *)((int)param_1_00 + 3) < 0xf0)))) {
        bVar3 = *(byte *)(param_1_00 + 2);
        if ((bVar3 == 0xff) && (*(byte *)((int)param_1_00 + 5) < 0xf0)) {
          FUN_00435840(param_1,0xff,*(byte *)((int)param_1_00 + 3),0xff);
        }
        else if (((int)(uint)bVar3 <= *(int *)(param_1 + 0x130c)) &&
                (*(byte *)((int)param_1_00 + 5) < 0x18)) {
          FUN_00435bc0(*(int *)(param_1 + 0x1810),0xff,(uint)bVar3,*(byte *)((int)param_1_00 + 5));
        }
      }
    }
    else {
      bVar1 = *(byte *)(param_1_00 + 2);
      if ((bVar1 == 100) && (bVar2 = *(byte *)((int)param_1_00 + 5), bVar2 < 0xf0)) {
        if (((bVar2 < 0x78) || (*(int *)(param_1 + 0x5968) != 0)) &&
           (*(int *)(param_1 + 0x400 + (uint)bVar2 * 4) == 0)) {
          FUN_00469400(uVar16,bVar3,100);
        }
        break;
      }
      if (((int)(uint)bVar1 <= *(int *)(param_1 + 0x130c)) &&
         (*(byte *)((int)param_1_00 + 5) < 0x18)) {
        FUN_004685a0(uVar16,bVar3,(uint)bVar1,*(byte *)((int)param_1_00 + 5));
        break;
      }
      FUN_00431eb0();
      local_4 = 0;
      if (((*(int *)(param_1 + 0x1810) != 0) && (*(char *)(param_1_00 + 2) == -1)) &&
         (*(byte *)((int)param_1_00 + 5) < 0xf0)) {
        iVar11 = (uint)*(byte *)((int)param_1_00 + 3) + (uint)*(byte *)(param_1_00 + 1) * 0x18;
        if (((*(int *)(param_1 + 0x1c0 + iVar11 * 4) != 0) &&
            (iVar11 = *(int *)(*(int *)(param_1 + 0x1c0 + iVar11 * 4) + 0x30),
            *(int *)(iVar11 + 0xa0) != 0x1b)) && (*(char *)(iVar11 + 0x31) == '\0')) {
          FUN_004350b0(*(int *)(param_1 + 0x1810),(uint)*(byte *)(param_1_00 + 1),
                       (uint)*(byte *)((int)param_1_00 + 3),0xff);
        }
      }
    }
    goto LAB_00476345;
  case 0x205:
    if ((*(int *)(param_1 + 0x1444) != 1) && (*(int *)(param_1 + 0x5880) == 0)) {
      FUN_00456610();
      FUN_00487030();
      FUN_0046a1e0();
    }
    break;
  case 0x206:
    if ((((*(int *)(param_1 + 0x1444) != 1) && (*(int *)(param_1 + 0x5880) == 0)) &&
        (*(byte *)(param_1_00 + 1) != 0)) &&
       (((*(char *)(param_1_00 + 2) != '\0' &&
         ((int)(uint)*(byte *)(param_1_00 + 1) <= *(int *)(param_1 + 0x130c))) &&
        (*(byte *)((int)param_1_00 + 3) < 0x18)))) {
      FUN_00456610();
      FUN_00487030();
      FUN_00469c00(*(undefined *)(param_1_00 + 1),*(undefined *)((int)param_1_00 + 3),
                   *(undefined *)(param_1_00 + 2));
    }
    break;
  default:
    FUN_004ec760(9,0);
    break;
  case 0x208:
    if ((*(char *)(param_1 + 0x58ea) == '\0') && (*(int *)(param_1 + 0x1444) != 1)) {
      uVar16 = (uint)(ushort)param_1_00[4] + (uint)(ushort)param_1_00[2] +
               (uint)(ushort)param_1_00[6] + (uint)(ushort)param_1_00[5] +
               (uint)(ushort)param_1_00[1] + (uint)(ushort)param_1_00[3];
      if (uVar16 != 0) {
        if (*(ushort *)(param_1 + 0x138) < uVar16) {
          param_1_00[3] = 0;
          param_1_00[6] = 0;
          param_1_00[1] = 0;
          param_1_00[2] = 0;
          param_1_00[4] = 0;
          param_1_00[5] = 0;
          FUN_004ed0e0(param_1_00,0xe);
        }
        else {
          *(short *)(param_1 + 0x16c) = *(short *)(param_1 + 0x16c) + param_1_00[1];
          *(int *)(param_1 + 0x121c) = *(int *)(param_1 + 0x121c) + (uint)(ushort)param_1_00[1];
          *(short *)(param_1 + 0x16e) = *(short *)(param_1 + 0x16e) + param_1_00[2];
          *(int *)(param_1 + 0x1220) = *(int *)(param_1 + 0x1220) + (uint)(ushort)param_1_00[2];
          *(short *)(param_1 + 0x174) = *(short *)(param_1 + 0x174) + param_1_00[3];
          *(int *)(param_1 + 0x122c) = *(int *)(param_1 + 0x122c) + (uint)(ushort)param_1_00[3];
          *(short *)(param_1 + 0x170) = *(short *)(param_1 + 0x170) + param_1_00[4];
          *(int *)(param_1 + 0x1224) = *(int *)(param_1 + 0x1224) + (uint)(ushort)param_1_00[4];
          *(short *)(param_1 + 0x172) = *(short *)(param_1 + 0x172) + param_1_00[5];
          *(int *)(param_1 + 0x1228) = *(int *)(param_1 + 0x1228) + (uint)(ushort)param_1_00[5];
          *(short *)(param_1 + 0x176) = *(short *)(param_1 + 0x176) + param_1_00[6];
          *(int *)(param_1 + 0x1230) = *(int *)(param_1 + 0x1230) + (uint)(ushort)param_1_00[6];
          *(ushort *)(param_1 + 0x138) = *(ushort *)(param_1 + 0x138) - (short)uVar16;
          if (param_1_00[3] != 0) {
            *(int *)(param_1 + 0x178) = *(int *)(param_1 + 0x178) + (uint)(ushort)param_1_00[3] * 5;
            FUN_00490830();
          }
          if (param_1_00[2] != 0) {
            *(int *)(param_1 + 0x180) = *(int *)(param_1 + 0x180) + (uint)(ushort)param_1_00[2] * 5;
            FUN_00490960();
          }
          if (param_1_00[5] != 0) {
            *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + (uint)(ushort)param_1_00[5] * 5;
            FUN_00490a70();
          }
          FUN_00460e40();
          FUN_0047ab60();
          FUN_004ed0e0(param_1_00,0xe);
          FUN_00467f60();
          local_a4[0] = 0x30a;
          sVar4 = param_1_00[1];
          if (sVar4 != 0) {
            local_4c = *(undefined2 *)(param_1 + 0x16c);
            local_4d = 1;
            local_4a = (undefined)sVar4;
            uStack_49._0_1_ = (undefined)((ushort)sVar4 >> 8);
            FUN_004ed210(local_a4,0x5c);
          }
          sVar4 = param_1_00[2];
          if (sVar4 != 0) {
            local_4c = *(undefined2 *)(param_1 + 0x16e);
            local_4d = 2;
            local_4a = (undefined)sVar4;
            uStack_49._0_1_ = (undefined)((ushort)sVar4 >> 8);
            FUN_004ed210(local_a4,0x5c);
          }
          sVar4 = param_1_00[3];
          if (sVar4 != 0) {
            local_4c = *(undefined2 *)(param_1 + 0x174);
            local_4d = 5;
            local_4a = (undefined)sVar4;
            uStack_49._0_1_ = (undefined)((ushort)sVar4 >> 8);
            FUN_004ed210(local_a4,0x5c);
          }
          sVar4 = param_1_00[4];
          if (sVar4 != 0) {
            local_4c = *(undefined2 *)(param_1 + 0x170);
            local_4d = 3;
            local_4a = (undefined)sVar4;
            uStack_49._0_1_ = (undefined)((ushort)sVar4 >> 8);
            FUN_004ed210(local_a4,0x5c);
          }
          sVar4 = param_1_00[5];
          if (sVar4 != 0) {
            local_4c = *(undefined2 *)(param_1 + 0x172);
            local_4d = 4;
            local_4a = (undefined)sVar4;
            uStack_49._0_1_ = (undefined)((ushort)sVar4 >> 8);
            FUN_004ed210(local_a4,0x5c);
          }
          sVar4 = param_1_00[6];
          if (sVar4 != 0) {
            local_4c = *(undefined2 *)(param_1 + 0x176);
            local_4d = 6;
            local_4a = (undefined)sVar4;
            uStack_49._0_1_ = (undefined)((ushort)sVar4 >> 8);
            FUN_004ed210(local_a4,0x5c);
          }
        }
      }
    }
    break;
  case 0x209:
    if ((*(char *)(param_1 + 0x58eb) == '\0') && (*(int *)(param_1 + 0x1444) != 1)) {
      FUN_004933f0(param_1,param_1_00[1],*(undefined *)(param_1_00 + 2));
    }
    break;
  case 0x20a:
  case 0x227:
    if (*(int *)(param_1 + 0x1444) == 1) break;
    iVar11 = *(int *)(*(int *)(param_1 + 0xe0) + 0x28);
    piVar10 = (int *)FUN_00430260();
    local_108 = piVar10;
    if ((piVar10 == (int *)0x0) ||
       (fVar20 = (float10)FUN_0041b8c0(),
       fVar20 < (float10)_DAT_00574140 == (NAN(fVar20) || NAN((float10)_DAT_00574140)))) break;
    iVar13 = piVar10[8];
    if (iVar13 == 200) goto LAB_0047679a;
    if ((*(int *)(iVar11 + 0x1a4) == 0) || (*piVar10 < 0x3e9)) {
      iVar11 = piVar10[5];
    }
    else {
      iVar11 = FUN_0041df50();
      iVar13 = piVar10[8];
    }
    if ((*(int *)(DAT_00587960 + 8) <= iVar13) ||
       (local_110 = iVar13 * 0x208 + *(int *)(DAT_00587960 + 0xc), local_110 == 0)) break;
    if (iVar11 != 0) {
      if (iVar11 == 1) {
        if (*(char *)(param_1 + 0x12d) != '\0') break;
      }
      else if ((iVar11 != 2) || (*(char *)(param_1 + 0x12d) != '\x01')) break;
    }
    if (((piVar10[6] != 0) || (piVar10[7] != 0)) &&
       (((int)(uint)*(ushort *)(param_1 + 0x136) < piVar10[6] ||
        (piVar10[7] < (int)(uint)*(ushort *)(param_1 + 0x136))))) break;
    switch(*(undefined4 *)(local_110 + 0x1a4)) {
    case 3:
      iVar11 = FUN_0042fa40();
      if (iVar11 == 0) {
        local_10c._0_3_ = CONCAT12(*(undefined *)(param_1_00 + 1),0x20a);
        local_10c = CONCAT13(9,(uint3)local_10c);
        FUN_004ed0e0(&local_10c,4);
        break;
      }
      FUN_0044e110();
      local_4 = 2;
      if (*(int *)(param_1 + 0x17f4) == 0) {
        local_110._3_1_ = 4;
      }
      else {
        iVar11 = FUN_0041a840(*(undefined4 *)(*(int *)(param_1 + 0x17f4) + 8),
                              *(undefined4 *)(param_1 + 0xe0));
        if ((iVar11 == 0) || (iVar11 == 2)) {
          local_110._3_1_ = 0xb;
        }
        else {
          if (*(int *)(local_110 + 0x1d8) <= *(int *)(*(int *)(param_1 + 0x17f4) + 0x10)) {
            local_4 = 0xffffffff;
            if (local_10c != 0) {
              lpCriticalSection = (LPCRITICAL_SECTION)(local_10c + 0x118);
              goto LAB_00476b19;
            }
            goto switchD_00476899_caseD_4;
          }
          local_110._3_1_ = 10;
        }
      }
      local_110._0_3_ = CONCAT12(*(undefined *)(param_1_00 + 1),0x20a);
      FUN_004ed0e0(&local_110,4);
      if (local_10c != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(local_10c + 0x118));
      }
      break;
    case 4:
      if (*(int *)(param_1 + 0x1810) == 0) {
        local_10c._0_3_ = CONCAT12(*(undefined *)(param_1_00 + 1),0x20a);
        local_10c = (uint)(uint3)local_10c;
        FUN_004ed0e0(&local_10c,4);
        break;
      }
    default:
switchD_00476899_caseD_4:
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x28) + 0x1e0) != 0) &&
         (*(int *)(local_110 + 0x1e0) == 0)) {
        FUN_0043fcc0();
      }
      DVar12 = GetTickCount();
      piVar10 = (int *)local_108[9];
      iVar11 = local_108[8];
      local_10c = local_108[10];
      local_110 = local_108[0xb];
      local_108 = piVar10;
      if (*(int *)(param_1 + 0x587c) == 0) {
        *(undefined4 *)(param_1 + 0x58b4) = 1;
        *(int **)(param_1 + 0x58c0) = piVar10;
        *(DWORD *)(param_1 + 0x58b8) = DVar12;
        *(int *)(param_1 + 0x58bc) = iVar11;
        *(uint *)(param_1 + 0x58c4) = local_10c;
        *(int *)(param_1 + 0x58c8) = local_110;
      }
      break;
    case 5:
      FUN_00431eb0();
      local_4 = 4;
      if (*(int *)(param_1 + 0x1810) == 0) {
LAB_004769f1:
        local_110._3_1_ = 0;
        goto LAB_004769f6;
      }
      iVar11 = FUN_0042f770(local_110,&local_fc);
      if (iVar11 == 0) {
        local_110._0_3_ = CONCAT12(*(undefined *)(param_1_00 + 1),0x20a);
        local_110 = CONCAT13(1,(undefined3)local_110);
        uVar21 = CONCAT44(4,&local_110);
      }
      else {
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x28) + 0x1a4) == 5) ||
           (local_fc != *(int *)(param_1 + 0x5584))) {
LAB_00476b01:
          local_4 = 0xffffffff;
          if (local_10c != 0) {
            lpCriticalSection = (LPCRITICAL_SECTION)(local_10c + 0x5cc);
LAB_00476b19:
            local_4 = 0xffffffff;
            LeaveCriticalSection(lpCriticalSection);
          }
          goto switchD_00476899_caseD_4;
        }
        local_110._0_3_ = CONCAT12(*(undefined *)(param_1_00 + 1),0x20a);
        local_110 = CONCAT13(2,(undefined3)local_110);
        uVar21 = CONCAT44(4,&local_110);
      }
      goto LAB_00476a0e;
    case 6:
      FUN_00431eb0();
      local_4 = 3;
      iVar11 = *(int *)(param_1 + 0x1810);
      if (iVar11 == 0) goto LAB_004769f1;
      if (*(byte *)(iVar11 + 0x48) < 0x1f) {
        if (*(char *)(iVar11 + 0x55) == '\0') {
          local_110._3_1_ = 6;
        }
        else if (*(char *)(iVar11 + 0x54) == '\0') {
          local_110._3_1_ = 7;
        }
        else {
          if (*(char *)(iVar11 + 0x54) != '\x02') goto LAB_00476b01;
          local_110._3_1_ = 8;
        }
      }
      else {
        local_110._3_1_ = 3;
      }
LAB_004769f6:
      local_110._0_3_ = CONCAT12(*(undefined *)(param_1_00 + 1),0x20a);
      uVar21 = CONCAT44(4,&local_110);
LAB_00476a0e:
      FUN_004ed0e0(uVar21);
      if (local_10c != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(local_10c + 0x5cc));
      }
    }
    break;
  case 0x20c:
    if ((((*(byte *)(param_1_00 + 3) < 3) && (iVar11 = FUN_0041d4a0(), iVar11 != 0)) &&
        (*(int *)(iVar11 + 0x34) == 2)) &&
       (((iVar11 = *(int *)(iVar11 + 0x50), local_110 = iVar11, iVar11 != 0 &&
         (fVar20 = (float10)FUN_0041b8c0(),
         fVar20 < (float10)_DAT_005740d8 != (NAN(fVar20) || NAN((float10)_DAT_005740d8)))) &&
        ((*(uint *)(iVar11 + 0x10) == 2 ||
         (*(uint *)(iVar11 + 0x10) == (uint)*(byte *)(param_1 + 0x12d))))))) {
      iVar11 = (uint)*(byte *)(param_1_00 + 3) * 0x114 + iVar11;
      if (*(short *)(iVar11 + 0x124) == 200) {
LAB_0047679a:
        if ((*(int *)(param_1 + 0x587c) == 0) && (*(int *)(param_1 + 0x68) != -1)) {
          FUN_00456610();
          FUN_00487030();
          uVar7 = *(undefined4 *)(param_1 + 0x582c);
          local_104 = 0x80c;
          local_102 = (undefined)uVar7;
          uStack_101 = (undefined)((uint)uVar7 >> 8);
          uStack_100 = (undefined2)((uint)uVar7 >> 0x10);
          FUN_004ed2d0(&local_104,6);
        }
        break;
      }
      local_10c = *(uint *)(iVar11 + 0x234);
      if (*(int *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x28) + 0x1a4) == 6) {
        FUN_00431eb0();
        local_4 = 5;
        if (*(int *)(param_1 + 0x1810) == 0) {
          local_10c = 0x1e010d28;
          FUN_004ed0e0(&local_10c,4);
        }
        else {
          iVar11 = FUN_004369c0(*(undefined2 *)(local_110 + 2),&local_dc,&local_fc);
          if (iVar11 != 0) {
            dVar8 = (double)(int)local_10c;
            if ((int)local_10c < 0) {
              dVar8 = dVar8 + _DAT_00574070;
            }
            local_fc = CONCAT22(local_fc._2_2_,in_FPUControlWord);
            local_dc = (double)(longlong)ROUND(dVar8 * local_dc);
            local_10c = (uint)local_dc;
            local_4 = 0xffffffff;
            if (local_108 != (int *)0x0) {
              LeaveCriticalSection((LPCRITICAL_SECTION)(local_108 + 0x173));
            }
            goto LAB_00476d03;
          }
          local_10c = CONCAT13((undefined)local_fc,0x20d28);
          FUN_004ed0e0(&local_10c,4);
        }
LAB_00476345:
        if (local_108 != (int *)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)(local_108 + 0x173));
        }
        break;
      }
LAB_00476d03:
      iVar11 = local_110 + (uint)*(byte *)(param_1_00 + 3) * 0x114;
      if (((*(char *)(iVar11 + 0x134) != '\0') && (local_10c <= *(uint *)(param_1 + 0x140))) &&
         (((int)(uint)*(ushort *)(iVar11 + 0x124) < *(int *)(DAT_00587960 + 8) &&
          ((iVar13 = (uint)*(ushort *)(iVar11 + 0x124) * 0x208 + *(int *)(DAT_00587960 + 0xc),
           iVar13 != 0 &&
           (cVar9 = FUN_0041bad0(iVar13,*(undefined4 *)(iVar11 + 0x128),
                                 *(undefined4 *)(iVar11 + 0x130)), cVar9 != '\0')))))) {
        DVar12 = GetTickCount();
        iVar11 = (uint)*(byte *)(param_1_00 + 3) * 0x114;
        local_108 = *(int **)(iVar11 + 0x128 + local_110);
        local_fc = *(int *)(iVar11 + 300 + local_110);
        uVar7 = *(undefined4 *)(iVar11 + 0x130 + local_110);
        local_104 = (undefined2)uVar7;
        local_102 = (undefined)((uint)uVar7 >> 0x10);
        uStack_101 = (undefined)((uint)uVar7 >> 0x18);
        uVar6 = *(ushort *)(iVar11 + local_110 + 0x124);
        if (*(int *)(param_1 + 0x587c) == 0) {
          *(undefined4 *)(param_1 + 0x58b4) = 1;
          *(int **)(param_1 + 0x58c0) = local_108;
          *(DWORD *)(param_1 + 0x58b8) = DVar12;
          *(uint *)(param_1 + 0x58bc) = (uint)uVar6;
          *(int *)(param_1 + 0x58c4) = local_fc;
          *(undefined4 *)(param_1 + 0x58c8) = uVar7;
        }
        *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) - local_10c;
        FUN_0047aae0();
        FUN_00467f60();
        local_a4[0] = 0x804;
        uVar7 = *(undefined4 *)((uint)*(byte *)(param_1_00 + 3) * 0x114 + 0x234 + local_110);
        uStack_49 = *(undefined4 *)(param_1 + 0x140);
        local_4d = (undefined)uVar7;
        local_4c = (undefined2)((uint)uVar7 >> 8);
        local_4a = (undefined)((uint)uVar7 >> 0x18);
        uStack_45 = (uint)*(ushort *)(local_110 + 2);
        pcVar14 = (char *)(local_110 + 0x14);
        uStack_3d = DAT_00571b34;
        uStack_41 = DAT_00571b30;
        pcVar15 = pcVar14;
        do {
          cVar9 = *pcVar15;
          pcVar15 = pcVar15 + 1;
        } while (cVar9 != '\0');
        pcVar18 = (char *)((int)&uStack_45 + 3);
        do {
          pcVar17 = pcVar18 + 1;
          pcVar18 = pcVar18 + 1;
        } while (*pcVar17 != '\0');
        pcVar17 = pcVar14;
        for (uVar16 = (uint)((int)pcVar15 - (int)pcVar14) >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
          *(undefined4 *)pcVar18 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar18 = pcVar18 + 4;
        }
        for (uVar16 = (int)pcVar15 - (int)pcVar14 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
          *pcVar18 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar18 = pcVar18 + 1;
        }
        FUN_004ed210(local_a4,0x8b);
        local_dc = (double)CONCAT53(CONCAT14(local_dc._7_1_,*(undefined4 *)(param_1 + 0x140)),
                                    0x1020c);
        FUN_004ed0e0(&local_dc,7);
        break;
      }
    }
    local_de = (undefined)((uint)*(int *)(param_1 + 0x140) >> 0x18);
    local_e4 = 0x20c;
    local_e2 = *(int *)(param_1 + 0x140) << 8;
    FUN_004ed0e0(&local_e4,7);
    break;
  case 0x210:
    if (*(char *)(param_1 + 0x1360) == '\r') {
      *(undefined *)(param_1_00 + 1) = 0;
      FUN_004ed0e0(param_1_00,3);
    }
    else {
      bVar19 = *(int *)(param_1 + 0x1450) == 0;
      *(uint *)(param_1 + 0x1450) = (uint)bVar19;
      *(bool *)(param_1_00 + 1) = bVar19;
      FUN_004ed0e0(param_1_00,3);
    }
    break;
  case 0x212:
    FUN_0049ace0();
    break;
  case 0x214:
    if (*(char *)(param_1 + 0x58ea) == '\0') {
      if ((int)(uint)*(byte *)(param_1 + 0x58e8) < DAT_00582784) {
        *(undefined *)(param_1 + 0x58ea) = 1;
        FUN_0048f710();
      }
      else {
        local_f8 = 0x214;
        local_f6 = 0;
        FUN_004ed0e0(&local_f8,3);
      }
    }
    break;
  case 0x215:
    if (*(char *)(param_1 + 0x58eb) == '\0') {
      if ((int)(uint)*(byte *)(param_1 + 0x58e9) < DAT_00582788) {
        *(undefined *)(param_1 + 0x58eb) = 1;
        FUN_0048fbc0();
      }
      else {
        local_104 = 0x215;
        local_102 = 0;
        FUN_004ed0e0(&local_104,3);
      }
    }
    break;
  case 0x216:
    DVar12 = GetTickCount();
    if ((*(int *)(param_1 + 0x147c) != 3) && (*(int *)(param_1 + 0x1444) != 1)) {
      local_10c = CONCAT22(local_10c._2_2_,0x216);
      if ((*(int *)(param_1 + 500) == 0) ||
         ((*(char *)(param_1 + 0x144c) != '\0' || (*(char *)(param_1 + 0x1360) != '\0')))) {
        local_10c = 0x1000216;
        FUN_004ed0e0(&local_10c,4);
      }
      else {
        FUN_0049ace0();
        iVar11 = *(int *)(param_1 + 0x147c);
        if (iVar11 == 0) {
          if (*(uint *)(param_1 + 0x1480) < DVar12) {
            if (*(int *)(param_1 + 0x1490) != 0) {
              iVar11 = FUN_0041c6e0();
              if ((iVar11 != 0) && (*(int *)(iVar11 + 0x147c) == 2)) {
                *(undefined4 *)(iVar11 + 0x1490) = 0;
                *(undefined4 *)(iVar11 + 0x1494) = 0;
                local_110 = CONCAT13(local_110._3_1_,0x2021e);
                FUN_004ed0e0(&local_110,3);
              }
              *(undefined4 *)(param_1 + 0x1490) = 0;
            }
            *(undefined4 *)(param_1 + 0x147c) = 1;
            if (*(char *)(*(int *)(*(int *)(param_1 + 500) + 0x30) + 0x30) == '\x03') {
              iVar11 = DVar12 + 3000;
            }
            else {
              iVar11 = DVar12 + 5000;
            }
            uVar7 = *(undefined4 *)(param_1 + 0xdc);
            local_104 = 0x217;
            *(int *)(param_1 + 0x1480) = iVar11;
            local_102 = (undefined)uVar7;
            uStack_101 = (undefined)((uint)uVar7 >> 8);
            uStack_100 = (undefined2)((uint)uVar7 >> 0x10);
            FUN_004d5250();
          }
          else {
            local_10c._0_3_ = (uint3)local_10c & 0xffff;
            local_10c = (uint)(uint3)local_10c;
            FUN_004ed0e0(&local_10c,4);
          }
        }
        else {
          if (iVar11 == 1) {
            *(undefined4 *)(param_1 + 0x1480) = 0;
          }
          else if (iVar11 == 2) {
            FUN_004564c0();
          }
          *(undefined4 *)(param_1 + 0x147c) = 0;
          local_10c._0_3_ = CONCAT12(1,(undefined2)local_10c);
          local_10c = (uint)(uint3)local_10c;
          FUN_004ed0e0(&local_10c,4);
          FUN_004913e0();
        }
      }
    }
    break;
  case 0x218:
    if ((*(char *)(param_1 + 0x12f) != '\0') && (0xf < *(ushort *)(param_1 + 0x136))) {
      FUN_0049d240();
    }
    break;
  case 0x219:
    if ((*(char *)(param_1 + 0x12f) != '\0') && (0xf < *(ushort *)(param_1 + 0x136))) {
      FUN_0049cfc0();
    }
    break;
  case 0x21a:
    if ((*(char *)(param_1 + 0x12f) != '\0') && (0xf < *(ushort *)(param_1 + 0x136))) {
      FUN_0049d0f0();
    }
    break;
  case 0x21c:
    if (*(int *)(param_1 + 0x147c) == 3) {
      iVar11 = FUN_0041c6e0();
      if (iVar11 != 0) {
        *(undefined4 *)(iVar11 + 0x148c) = 0;
      }
      *(undefined4 *)(param_1 + 0x147c) = 0;
      *(undefined4 *)(param_1 + 0x148c) = 0;
      FUN_004914b0();
    }
    break;
  case 0x21d:
    if (((((*(int *)(param_1 + 0x147c) == 2) && (*(int *)(param_1 + 0x1484) == 0xf)) &&
         (*(int *)(param_1 + 0x148c) == 0)) &&
        ((iVar11 = FUN_0041c6e0(), iVar11 != 0 && (*(int *)(iVar11 + 0x1490) == 0)))) &&
       ((*(int *)(iVar11 + 0x147c) == 0 &&
        ((*(char *)(iVar11 + 0x12d) == *(char *)(param_1 + 0x12d) &&
         (*(int *)(iVar11 + 0x1358) == 0)))))) {
      *(undefined4 *)(param_1 + 0x1490) = *(undefined4 *)(iVar11 + 0xdc);
      *(undefined4 *)(iVar11 + 0x1490) = *(undefined4 *)(param_1 + 0xdc);
      DVar12 = GetTickCount();
      uVar7 = *(undefined4 *)(param_1 + 0xdc);
      *(DWORD *)(param_1 + 0x1494) = DVar12 + 30000;
      local_102 = (undefined)uVar7;
      uStack_101 = (undefined)((uint)uVar7 >> 8);
      uStack_100 = (undefined2)((uint)uVar7 >> 0x10);
      local_104 = 0x21d;
      FUN_004ed0e0(&local_104,6);
    }
    else {
      local_110 = CONCAT13(local_110._3_1_,0x2021e);
      FUN_004ed0e0(&local_110,3);
    }
    break;
  case 0x21e:
    if ((*(int *)(param_1 + 0x147c) == 0) && (*(int *)(param_1 + 0x1490) != 0)) {
      iVar11 = FUN_0041c6e0();
      if ((iVar11 != 0) && (*(int *)(iVar11 + 0x1490) == *(int *)(param_1 + 0xdc))) {
        FUN_004ed0e0(param_1_00,3);
        if (*(char *)(param_1_00 + 1) == '\0') {
          *(undefined4 *)(iVar11 + 0x148c) = *(undefined4 *)(param_1 + 0xdc);
          *(undefined4 *)(param_1 + 0x148c) = *(undefined4 *)(iVar11 + 0xdc);
          *(undefined4 *)(param_1 + 0x147c) = 3;
          FUN_004914b0();
        }
        *(undefined4 *)(iVar11 + 0x1490) = 0;
        *(undefined4 *)(iVar11 + 0x1494) = 0;
      }
      *(undefined4 *)(param_1 + 0x1490) = 0;
    }
    break;
  case 0x220:
    local_f5 = *(byte *)(param_1_00 + 1);
    local_f8 = 0x220;
    iVar11 = *(int *)(*(int *)(param_1 + 0xe0) + 0x28);
    if (*(int *)(iVar11 + 0x80) == 1) {
      local_f6 = 1;
      FUN_004ed0e0(&local_f8,0x12);
      break;
    }
    if (*(char *)(iVar11 + 0x1e6) == -1) {
      if ((local_f5 != 0) && (local_f5 < 5)) {
        iVar11 = FUN_0051ca16((double)*(float *)((int)param_1_00 + 5));
        if ((iVar11 == 0) ||
           (iVar11 = __isnan((double)*(float *)((int)param_1_00 + 5)), iVar11 != 0)) {
          local_f6 = 2;
          FUN_004ed0e0(&local_f8,0x12);
          break;
        }
        iVar11 = FUN_0051ca16((double)*(float *)((int)param_1_00 + 9));
        if ((iVar11 == 0) ||
           (iVar11 = __isnan((double)*(float *)((int)param_1_00 + 9)), iVar11 != 0))
        goto LAB_0047752d;
        iVar11 = FUN_0051ca16((double)*(float *)((int)param_1_00 + 0xd));
        if ((iVar11 != 0) &&
           (iVar11 = __isnan((double)*(float *)((int)param_1_00 + 0xd)), iVar11 == 0)) {
          uVar6 = *(ushort *)(param_1 + 0x160);
          if (*(ushort *)((int)param_1_00 + 3) == uVar6) {
            local_d4 = (undefined2)*(undefined4 *)((int)param_1_00 + 5);
            uStack_d2 = (undefined2)((uint)*(undefined4 *)((int)param_1_00 + 5) >> 0x10);
            uVar7 = *(undefined4 *)((int)param_1_00 + 9);
            local_d0 = (undefined2)uVar7;
            uStack_ce = (undefined)((uint)uVar7 >> 0x10);
            uStack_cd = (undefined)((uint)uVar7 >> 0x18);
            local_cc = *(undefined4 *)((int)param_1_00 + 0xd);
            fVar20 = (float10)FUN_0041b8c0();
            if (fVar20 <= (float10)_DAT_005740e8) {
              if (*(int *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x28) + 0x1a4) == 0) {
                *(uint *)(param_1 + 0x5908 + (uint)*(byte *)(param_1_00 + 1) * 4) = (uint)uVar6;
                *(undefined4 *)(param_1 + (*(byte *)(param_1_00 + 1) + 0x76c) * 0xc) =
                     *(undefined4 *)((int)param_1_00 + 5);
                *(undefined4 *)(param_1 + 0x5914 + (uint)*(byte *)(param_1_00 + 1) * 0xc) =
                     *(undefined4 *)((int)param_1_00 + 9);
                *(undefined4 *)(param_1 + 0x5918 + (uint)*(byte *)(param_1_00 + 1) * 0xc) =
                     *(undefined4 *)((int)param_1_00 + 0xd);
                local_f4 = *(undefined2 *)(param_1 + 0x160);
                local_f2 = *(undefined4 *)((int)param_1_00 + 5);
                local_f6 = 0;
                local_ee = *(undefined4 *)((int)param_1_00 + 9);
                local_ea = *(undefined4 *)((int)param_1_00 + 0xd);
                FUN_004ed0e0(&local_f8,0x12);
                local_b3 = *(undefined4 *)((int)param_1_00 + 5);
                local_ba = *(undefined4 *)(param_1 + 0x582c);
                local_af = *(undefined4 *)((int)param_1_00 + 9);
                local_b6 = *(char *)(param_1_00 + 1) + -1;
                local_ab = *(undefined4 *)((int)param_1_00 + 0xd);
                local_bc = 0xd02;
                local_b5 = *(undefined2 *)(param_1 + 0x160);
                FUN_004ed2d0(&local_bc,0x15);
              }
              else {
                local_f6 = 2;
                FUN_004ed0e0(&local_f8,0x12);
              }
              break;
            }
          }
          local_f6 = 1;
          FUN_004ed0e0(&local_f8,0x12);
          break;
        }
      }
      local_f6 = 2;
      FUN_004ed0e0(&local_f8,0x12);
    }
    else {
LAB_0047752d:
      local_f6 = 2;
      FUN_004ed0e0(&local_f8,0x12);
    }
    break;
  case 0x224:
    if (*(int *)(param_1 + 0x1498) != 0) {
      iVar11 = FUN_00414d80();
      if ((iVar11 != 0) &&
         ((*(int *)(iVar11 + 0xe0) == 0 ||
          (((iVar13 = *(int *)(*(int *)(*(int *)(iVar11 + 0xe0) + 0x28) + 0x1a4), iVar13 != 5 &&
            (iVar13 != 3)) &&
           ((iVar13 != 6 ||
            ((*(int *)(iVar11 + 0x1810) != 0 &&
             (*(int *)(iVar11 + 0x1810) == *(int *)(param_1 + 0x1810))))))))))) {
        if (*(int *)(param_1 + 0x1444) == 1) {
          *(undefined *)(param_1_00 + 1) = 1;
        }
        local_e2 = *(int *)(param_1 + 0xdc);
        local_de = *(undefined *)(param_1_00 + 1);
        local_e4 = 0x224;
        FUN_004ed0e0(&local_e4,7);
        if (*(char *)(param_1_00 + 1) == '\0') {
          uVar5 = *(undefined2 *)(iVar11 + 0x160);
          cVar9 = FUN_00472880();
          if ((cVar9 != '\0') &&
             ((*(short *)(param_1 + 0x160) == extraout_DX ||
              (cVar9 = FUN_00430340(uVar5,*(undefined *)(param_1 + 0x12d)), cVar9 != '\0')))) {
            DVar12 = GetTickCount();
            uVar7 = *(undefined4 *)(iVar11 + 0xd0);
            local_104 = (undefined2)uVar7;
            local_102 = (undefined)((uint)uVar7 >> 0x10);
            uStack_101 = (undefined)((uint)uVar7 >> 0x18);
            local_108 = *(int **)(iVar11 + 0xd4);
            uVar6 = *(ushort *)(iVar11 + 0x160);
            local_10c = *(uint *)(iVar11 + 0xd8);
            if (*(int *)(param_1 + 0x587c) == 0) {
              *(undefined4 *)(param_1 + 0x58b4) = 1;
              *(undefined4 *)(param_1 + 0x58c0) = uVar7;
              *(DWORD *)(param_1 + 0x58b8) = DVar12;
              *(uint *)(param_1 + 0x58bc) = (uint)uVar6;
              *(int **)(param_1 + 0x58c4) = local_108;
              *(uint *)(param_1 + 0x58c8) = local_10c;
            }
          }
        }
      }
      *(undefined4 *)(param_1 + 0x1498) = 0;
      *(undefined4 *)(param_1 + 0x149c) = 0;
    }
    break;
  case 0x226:
    if ((((*(int *)(param_1 + 0x1444) == 1) || (bVar3 = *(byte *)(param_1_00 + 1), bVar3 == 0)) ||
        (*(int *)(param_1 + 0x130c) < (int)(uint)bVar3)) ||
       ((0x17 < *(byte *)((int)param_1_00 + 3) ||
        (iVar11 = *(int *)(param_1 + 0x1c0 +
                          ((uint)*(byte *)((int)param_1_00 + 3) + (uint)bVar3 * 0x18) * 4),
        iVar11 == 0)))) break;
    iVar11 = *(int *)(iVar11 + 0x30);
    if (*(int *)(iVar11 + 0xa0) == 0x1a) {
      cVar9 = *(char *)(iVar11 + 0x46);
      if (cVar9 == ',') {
        *(undefined *)(param_1 + 0x131) = *(undefined *)(param_1_00 + 2);
        *(undefined *)(param_1 + 0x132) = *(undefined *)((int)param_1_00 + 5);
        *(undefined *)(param_1 + 0x133) = *(undefined *)(param_1_00 + 3);
      }
      else {
        if (cVar9 != '-') goto LAB_00477833;
        iVar11 = 0;
        piVar10 = (int *)(param_1 + 0x1c0);
        do {
          if ((*piVar10 != 0) &&
             ((cVar9 = *(char *)(*(int *)(*piVar10 + 0x30) + 0x46), cVar9 == 'A' || (cVar9 == '@')))
             ) {
            local_fc = CONCAT22(local_fc._2_2_,0x228);
            FUN_004ed0e0(&local_fc,2);
            goto LAB_00477999;
          }
          iVar11 = iVar11 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar11 < 0xd);
        *(undefined *)(param_1 + 0x131) = *(undefined *)(param_1_00 + 2);
        *(undefined *)(param_1 + 0x132) = *(undefined *)((int)param_1_00 + 5);
        *(undefined *)(param_1 + 0x133) = *(undefined *)(param_1_00 + 3);
        *(undefined *)(param_1 + 0x135) = *(undefined *)((int)param_1_00 + 7);
      }
      local_c6 = *(undefined4 *)(param_1 + 0x582c);
      local_c2 = *(undefined *)(param_1 + 0x131);
      local_c8 = 0x615;
      local_c1 = *(undefined *)(param_1 + 0x132);
      local_c0 = *(undefined *)(param_1 + 0x133);
      local_bf = *(undefined *)(param_1 + 0x135);
      FUN_004ed2d0(&local_c8,10);
      FUN_004728e0(*(undefined *)(param_1_00 + 1),*(undefined *)((int)param_1_00 + 3),0);
      uStack_ce = *(undefined *)(param_1 + 0x131);
      local_d4 = 0x226;
      uStack_cd = *(undefined *)(param_1 + 0x132);
      uStack_d2 = (undefined2)*(undefined4 *)(param_1 + 0xdc);
      local_d0 = (undefined2)((uint)*(undefined4 *)(param_1 + 0xdc) >> 0x10);
      local_cc = CONCAT31(CONCAT21(local_cc._2_2_,*(undefined *)(param_1 + 0x135)),
                          *(undefined *)(param_1 + 0x133));
      FUN_004d56d0(&local_d4,10);
    }
    else {
LAB_00477833:
      FUN_00472b80(DAT_0057f7c4 ^ (uint)&stack0xfffffedc);
    }
  }
LAB_00477999:
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
}

