/*
 * server/ps_game.exe — Dispatch_Packet0500_Handler
 * VA solicitado: 0x00478490
 * Entry Ghidra:  00478490
 * Ghidra name:   FUN_00478490
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00478490(int param_1_00,undefined2 *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  uint extraout_ECX_01;
  undefined4 uVar7;
  float10 fVar8;
  undefined uVar9;
  undefined auStack_bc [4];
  undefined4 local_b8;
  undefined local_b1;
  undefined2 local_b0;
  undefined2 uStack_ae;
  undefined2 uStack_ac;
  undefined local_aa;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined2 uStack_a2;
  undefined2 local_a0;
  undefined uStack_9e;
  undefined uStack_9d;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined uStack_90;
  undefined4 local_8c;
  undefined2 local_88 [43];
  undefined4 local_31;
  undefined local_2d;
  undefined2 local_18;
  uint local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005535e6;
  local_c = ExceptionList;
  local_10 = DAT_0057f7c4 ^ (uint)auStack_bc;
  uVar3 = DAT_0057f7c4 ^ (uint)&stack0xffffff34;
  ExceptionList = &local_c;
  switch(*param_1) {
  case 0x501:
    FUN_0049af30();
    if ((((*(int *)(param_1_00 + 0x1444) != 1) || (*(int *)(param_1_00 + 0x1448) == 1)) &&
        ((iVar5 = FUN_0051ca16((double)*(float *)((int)param_1 + 5)), iVar5 != 0 &&
         (((iVar5 = __isnan((double)*(float *)((int)param_1 + 5)), iVar5 == 0 &&
           (iVar5 = FUN_0051ca16((double)*(float *)((int)param_1 + 9)), iVar5 != 0)) &&
          (iVar5 = __isnan((double)*(float *)((int)param_1 + 9)), iVar5 == 0)))))) &&
       ((iVar5 = FUN_0051ca16((double)*(float *)((int)param_1 + 0xd)), iVar5 != 0 &&
        (iVar5 = __isnan((double)*(float *)((int)param_1 + 0xd)), iVar5 == 0)))) {
      if (*(int *)(param_1_00 + 0x147c) == 2) {
        local_b8 = _DAT_00574218;
      }
      else if (*(int *)(param_1_00 + 0x147c) == 3) {
        local_b8 = DAT_0058198c + (float)_DAT_00574210;
      }
      else {
        iVar5 = FUN_0049b320();
        local_b8 = (float)(&DAT_0058197c)[iVar5];
        if (local_b8 < _DAT_0057420c == (NAN(local_b8) || NAN(_DAT_0057420c))) {
          if ((_DAT_00574208 < local_b8 != (_DAT_00574208 == local_b8)) &&
             (local_b8 < (float)_DAT_00574200 != (NAN(local_b8) || NAN((float)_DAT_00574200)))) {
            local_b8 = _DAT_005741fc;
          }
        }
        else {
          local_b8 = _DAT_0057420c;
        }
      }
      local_a8 = *(undefined4 *)((int)param_1 + 5);
      local_8c = *(undefined4 *)((int)param_1 + 9);
      local_9c = *(undefined4 *)((int)param_1 + 0xd);
      local_b0 = (undefined2)local_9c;
      uStack_ae = (undefined2)((uint)local_9c >> 0x10);
      local_a4 = (undefined2)local_a8;
      uStack_a2 = (undefined2)((uint)local_a8 >> 0x10);
      local_a0 = (undefined2)local_8c;
      uStack_9e = (undefined)((uint)local_8c >> 0x10);
      uStack_9d = (undefined)((uint)local_8c >> 0x18);
      iVar5 = FUN_00478240();
      if (iVar5 == 1) {
        FUN_0049ace0();
        DVar6 = GetTickCount();
        if (*(int *)(param_1_00 + 0x587c) == 0) {
          *(undefined4 *)(param_1_00 + 0x58c0) = *(undefined4 *)(param_1_00 + 0x5560);
          *(undefined4 *)(param_1_00 + 0x58b4) = 1;
          *(DWORD *)(param_1_00 + 0x58b8) = DVar6;
          *(undefined4 *)(param_1_00 + 0x58c4) = *(undefined4 *)(param_1_00 + 0x5564);
          *(uint *)(param_1_00 + 0x58bc) = (uint)*(ushort *)(param_1_00 + 0x160);
          *(undefined4 *)(param_1_00 + 0x58c8) = *(undefined4 *)(param_1_00 + 0x5568);
        }
      }
      else if (iVar5 != 2) {
        if (iVar5 == 3) {
          FUN_0049ace0();
          local_9c = *(undefined4 *)(param_1_00 + 0x5554);
          local_98 = *(undefined4 *)(param_1_00 + 0x5558);
          local_94 = *(undefined4 *)(param_1_00 + 0x555c);
          local_a4 = 0x20b;
          uStack_a2 = (undefined2)*(undefined4 *)(param_1_00 + 0xdc);
          local_a0 = (undefined2)((uint)*(undefined4 *)(param_1_00 + 0xdc) >> 0x10);
          uStack_9e = (undefined)*(undefined2 *)(param_1_00 + 0x160);
          uStack_9d = (undefined)((ushort)*(undefined2 *)(param_1_00 + 0x160) >> 8);
          FUN_004d5690(&local_a4,0x14);
          FUN_0045aab0();
        }
        else {
          cVar2 = FUN_0041cd60(*(undefined4 *)(param_1_00 + 0xe0),*(undefined4 *)((int)param_1 + 5),
                               *(undefined4 *)((int)param_1 + 9),*(undefined4 *)((int)param_1 + 0xd)
                              );
          if (cVar2 != '\0') {
            *(undefined2 *)(param_1_00 + 0x162) = *(undefined2 *)((int)param_1 + 3);
            DVar6 = GetTickCount();
            *(DWORD *)(param_1_00 + 0x586c) = DVar6;
            *(undefined *)(param_1_00 + 0x144d) = *(undefined *)(param_1 + 1);
            if (*(char *)(param_1 + 1) < '\0') {
              FUN_0049ace0();
            }
            else {
              FUN_0049aec0();
            }
            if (*(int *)(param_1_00 + 0x147c) == 1) {
              *(undefined4 *)(param_1_00 + 0x1480) = 0;
              *(undefined4 *)(param_1_00 + 0x147c) = 0;
            }
            if (*(char *)(param_1_00 + 0x1460) != '\0') {
              *(byte *)(param_1_00 + 0x144d) = *(byte *)(param_1_00 + 0x144d) & 0x7f;
              *(byte *)(param_1_00 + 0x144d) = *(byte *)(param_1_00 + 0x144d) | 0x80;
            }
            uStack_9e = *(undefined *)(param_1_00 + 0x144d);
            local_98._1_3_ = (undefined3)*(undefined4 *)((int)param_1 + 9);
            local_98 = CONCAT31(local_98._1_3_,
                                (char)((uint)*(undefined4 *)((int)param_1 + 5) >> 0x18));
            local_a4 = 0x501;
            local_94._1_3_ = (undefined3)*(undefined4 *)((int)param_1 + 0xd);
            local_94 = CONCAT31(local_94._1_3_,
                                (char)((uint)*(undefined4 *)((int)param_1 + 9) >> 0x18));
            uStack_90 = (undefined)((uint)*(undefined4 *)((int)param_1 + 0xd) >> 0x18);
            uStack_a2 = (undefined2)*(undefined4 *)(param_1_00 + 0xdc);
            local_a0 = (undefined2)((uint)*(undefined4 *)(param_1_00 + 0xdc) >> 0x10);
            uStack_9d = (undefined)*(undefined2 *)(param_1_00 + 0x162);
            local_9c._0_1_ = (undefined)((ushort)*(undefined2 *)(param_1_00 + 0x162) >> 8);
            local_9c = CONCAT31((int3)*(undefined4 *)((int)param_1 + 5),(undefined)local_9c);
            cVar2 = FUN_004d5750();
            if (cVar2 != '\0') {
              FUN_0044e110();
              local_4 = 0;
              if (*(int *)(param_1_00 + 0x17f4) != 0) {
                FUN_0044ec00();
              }
              local_4 = 0xffffffff;
              if (CONCAT22(uStack_ae,local_b0) != 0) {
                LeaveCriticalSection((LPCRITICAL_SECTION)(CONCAT22(uStack_ae,local_b0) + 0x118));
              }
            }
            iVar5 = *(int *)(param_1_00 + 0x15bc);
            if ((iVar5 != 0) && (fVar8 = (float10)FUN_0041b8c0(), (float10)_DAT_00574158 < fVar8)) {
              piVar1 = (int *)(iVar5 + 0x40);
              *piVar1 = *piVar1 + -1;
              *(undefined4 *)(param_1_00 + 0x15bc) = 0;
            }
            if (((*(int *)(param_1_00 + 0x15c0) != 0) && (*(int *)(param_1_00 + 0x15c4) != 0)) &&
               (fVar8 = (float10)FUN_0041b8c0(), (float10)_DAT_00574158 < fVar8)) {
              FUN_00454800();
              FUN_00454800();
              local_b8 = (float)CONCAT13(local_b8._3_1_,0x20a04);
              FUN_004ed0e0(&local_b8,3);
              local_b8._0_3_ = CONCAT12(3,(undefined2)local_b8);
              FUN_004ed0e0(&local_b8,3);
            }
            FUN_0048ac70();
            FUN_00499b60();
          }
          FUN_0049ae40();
        }
      }
    }
    break;
  case 0x502:
    if ((((((*(int *)(param_1_00 + 0x1444) != 1) && (*(int *)(param_1_00 + 0x1444) != 3)) &&
          (*(int *)(param_1_00 + 0x1358) == 0)) &&
         ((iVar5 = FUN_0049b250(), iVar5 != 0xff && (*(char *)(param_1_00 + 0x144c) != '\x01')))) &&
        (*(int *)(param_1_00 + 0x147c) == 0)) &&
       (((extraout_ECX != 2 || (*(int *)(param_1_00 + 0x1544) != 1)) ||
        (*(int *)(param_1 + 1) != *(int *)(param_1_00 + 0x1548))))) {
      iVar5 = *(int *)(param_1 + 1);
      local_b0 = (undefined2)iVar5;
      uStack_ae = (undefined2)((uint)iVar5 >> 0x10);
      iVar4 = FUN_00415480();
      if ((((iVar4 != 0) && (*(int *)(iVar4 + 0x1444) != 1)) &&
          (((*(char *)(iVar4 + 0x5814) != '\0' && (*(char *)(iVar4 + 0x5815) != '\0')) ||
           (*(int *)(param_1_00 + 0xdc) == iVar5)))) &&
         ((((*(char *)(iVar4 + 0x1360) != '\r' && (*(char *)(iVar4 + 0x1360) != 'g')) &&
           (*(int *)(iVar4 + 0xdc) != *(int *)(param_1_00 + 0xdc))) &&
          (cVar2 = FUN_00457dc0(), cVar2 == '\0')))) {
        iVar5 = *(int *)(param_1_00 + 0x1444);
        if ((iVar5 != 1) && (iVar5 != 2)) {
          if ((iVar5 == 0) && (FUN_00491540(), *(int *)(param_1_00 + 0x1270) < 2)) {
            *(undefined4 *)(param_1_00 + 0x1270) = 2;
          }
          *(undefined4 *)(param_1_00 + 0x1444) = 2;
        }
        *(undefined4 *)(param_1_00 + 0x1544) = 1;
        *(undefined4 *)(param_1_00 + 0x1548) = *(undefined4 *)(param_1 + 1);
        *(undefined4 *)(param_1_00 + 0x1454) = 1;
        *(undefined4 *)(param_1_00 + 0x1458) = 1;
        FUN_0049ae40();
        break;
      }
LAB_00478acc:
      FUN_004920d0();
      FUN_0049ae40();
      break;
    }
    goto LAB_00478bc9;
  case 0x503:
    if ((((*(int *)(param_1_00 + 0x1444) != 1) && (*(int *)(param_1_00 + 0x1444) != 3)) &&
        ((*(int *)(param_1_00 + 0x1358) == 0 &&
         (((iVar5 = FUN_0049b250(), iVar5 != 0xff && (*(char *)(param_1_00 + 0x144c) != '\x01')) &&
          (*(int *)(param_1_00 + 0x147c) == 0)))))) &&
       (((extraout_ECX_00 != 2 || (*(int *)(param_1_00 + 0x1544) != 2)) ||
        (*(int *)(param_1 + 1) != *(int *)(param_1_00 + 0x1548))))) {
      iVar5 = FUN_00458d80();
      if (iVar5 != 0) {
        iVar5 = *(int *)(param_1_00 + 0x1444);
        if ((iVar5 != 1) && (iVar5 != 2)) {
          if ((iVar5 == 0) && (FUN_00491540(), *(int *)(param_1_00 + 0x1270) < 2)) {
            *(undefined4 *)(param_1_00 + 0x1270) = 2;
          }
          *(undefined4 *)(param_1_00 + 0x1444) = 2;
        }
        *(undefined4 *)(param_1_00 + 0x1544) = 2;
        *(undefined4 *)(param_1_00 + 0x1548) = *(undefined4 *)(param_1 + 1);
        *(undefined4 *)(param_1_00 + 0x1454) = 1;
        *(undefined4 *)(param_1_00 + 0x1458) = 1;
        FUN_0049ae40();
        break;
      }
      goto LAB_00478acc;
    }
    goto LAB_00478bc9;
  default:
    FUN_004ec760(9,0);
    break;
  case 0x506:
    cVar2 = FUN_0049afb0();
    local_b0 = 0x506;
    local_aa = *(undefined *)(param_1 + 1);
    uStack_ae = (undefined2)*(undefined4 *)(param_1_00 + 0xdc);
    uStack_ac = (undefined2)((uint)*(undefined4 *)(param_1_00 + 0xdc) >> 0x10);
    if (cVar2 == '\0') {
      FUN_004d5690(&local_b0,7);
    }
    else {
      FUN_004d5250();
    }
    break;
  case 0x50a:
    if ((((*(int *)(param_1_00 + 0x1444) == 1) || (*(int *)(param_1_00 + 0x5880) != 0)) ||
        (*(int *)(param_1_00 + 0x1358) != 0)) ||
       (((*(byte *)(param_1 + 1) == 0 ||
         (*(int *)(param_1_00 + 0x130c) < (int)(uint)*(byte *)(param_1 + 1))) ||
        (0x17 < *(byte *)((int)param_1 + 3))))) break;
    FUN_00456610(uVar3);
    FUN_00487030();
    uVar7 = *(undefined4 *)(param_1_00 + 0xdc);
    uVar9 = 0;
    goto LAB_00478ff0;
  case 0x511:
    if ((*(char *)(param_1 + 1) == -1) && (*(int *)((int)param_1 + 3) != 0)) {
      FUN_00493ef0();
    }
    else if ((((*(int *)(param_1_00 + 0x1444) != 1) &&
              (((*(int *)(param_1_00 + 0x1358) == 0 && (*(int *)(param_1_00 + 0x1444) != 3)) &&
               (iVar5 = FUN_0049b250(), iVar5 != 0xff)))) &&
             (((*(char *)(param_1_00 + 0x144c) != '\x01' && (*(int *)(param_1_00 + 0x147c) == 0)) &&
              (uVar3 = extraout_ECX_01 & 0xff, (int)uVar3 < *(int *)(param_1_00 + 0xabc))))) &&
            (((*(char *)(param_1_00 + 0x1360) == '\0' || (*(char *)(param_1_00 + 0x1360) == '\r'))
             && ((*(int *)(param_1_00 + 0xac0 + uVar3 * 4) != 0 &&
                 ((((iVar5 = *(int *)(*(int *)(param_1_00 + 0xac0 + uVar3 * 4) + 0x34),
                    *(char *)(iVar5 + 0x2f) != '\0' &&
                    (*(char *)(*(byte *)(param_1_00 + 0x134) + 0x27 + iVar5) != '\0')) &&
                   (*(byte *)(iVar5 + 0x2d) <= *(byte *)(param_1_00 + 0x12f))) &&
                  ((*(ushort *)(iVar5 + 0x24) == 0 ||
                   (*(ushort *)(iVar5 + 0x24) <= *(ushort *)(param_1_00 + 0x136))))))))))) {
      cVar2 = FUN_0045a200(iVar5,*(undefined4 *)((int)param_1 + 3));
      goto LAB_00478c86;
    }
    goto LAB_00478bc9;
  case 0x517:
    if (((((((*(int *)(param_1_00 + 0x1444) != 1) && (*(int *)(param_1_00 + 0x1358) == 0)) &&
           (*(int *)(param_1_00 + 0x1444) != 3)) &&
          ((iVar5 = FUN_0049b250(), iVar5 != 0xff && (*(char *)(param_1_00 + 0x144c) != '\x01'))))
         && (*(int *)(param_1_00 + 0x147c) == 0)) &&
        (uVar3 = (uint)*(byte *)(param_1 + 1), (int)uVar3 < *(int *)(param_1_00 + 0xabc))) &&
       ((((*(char *)(param_1_00 + 0x1360) == '\0' || (*(char *)(param_1_00 + 0x1360) == '\r')) &&
         ((*(int *)(param_1_00 + 0xac0 + uVar3 * 4) != 0 &&
          (((iVar5 = *(int *)(*(int *)(param_1_00 + 0xac0 + uVar3 * 4) + 0x34),
            *(char *)(iVar5 + 0x2f) != '\0' &&
            (*(char *)(*(byte *)(param_1_00 + 0x134) + 0x27 + iVar5) != '\0')) &&
           (*(byte *)(iVar5 + 0x2d) <= *(byte *)(param_1_00 + 0x12f))))))) &&
        ((*(ushort *)(iVar5 + 0x24) == 0 ||
         (*(ushort *)(iVar5 + 0x24) <= *(ushort *)(param_1_00 + 0x136))))))) {
      cVar2 = FUN_0045a760(iVar5,&local_b1);
LAB_00478c86:
      if (cVar2 != '\0') {
        iVar5 = *(int *)(param_1_00 + 0x1444);
        if ((iVar5 != 1) && (iVar5 != 2)) {
          if ((iVar5 == 0) && (FUN_00491540(), *(int *)(param_1_00 + 0x1270) < 2)) {
            *(undefined4 *)(param_1_00 + 0x1270) = 2;
          }
          *(undefined4 *)(param_1_00 + 0x1444) = 2;
        }
        *(undefined4 *)(param_1_00 + 0x1458) = 2;
        *(uint *)(param_1_00 + 0x145c) = (uint)*(byte *)(param_1 + 1);
        FUN_0049ae40();
        break;
      }
      goto LAB_00478acc;
    }
LAB_00478bc9:
    FUN_004920d0();
    break;
  case 0x552:
    iVar5 = FUN_0041dcc0();
    if ((iVar5 != 0) &&
       (fVar8 = (float10)FUN_0041b8c0(),
       fVar8 < (float10)_DAT_005740d8 != (NAN(fVar8) || NAN((float10)_DAT_005740d8)))) {
      FUN_00466b90();
    }
    break;
  case 0x553:
    FUN_00467f60();
    cVar2 = *(char *)(param_1 + 1);
    local_88[0] = 0x305;
    local_31 = 0;
    local_2d = 0;
    if (cVar2 == '\x02') {
      local_18 = 1;
      FUN_004ed210(local_88,0x72);
      FUN_00466880();
    }
    else if (cVar2 == '\x03') {
      local_18 = 2;
      FUN_004ed210(local_88,0x72);
      FUN_0044e110();
      local_4 = 1;
      if (*(int *)(param_1_00 + 0x17f4) == 0) {
        FUN_00466880();
      }
      else {
        DVar6 = GetTickCount();
        *(DWORD *)(param_1_00 + 0x1470) = DVar6 + 30000;
        *(undefined4 *)(param_1_00 + 0x1474) = 1;
      }
      if (CONCAT22(uStack_ae,local_b0) != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(CONCAT22(uStack_ae,local_b0) + 0x118));
      }
    }
    else if (cVar2 == '\x04') {
      local_18 = 3;
      FUN_004ed210(local_88,0x72);
      FUN_004665e0();
    }
    else if (cVar2 == '\x05') {
      local_18 = 4;
      FUN_004ed210(local_88,0x72);
      FUN_00466740();
    }
    break;
  case 0x554:
    if (*(int *)(param_1_00 + 0x1444) != 1) {
      FUN_00456610(uVar3);
      FUN_00487030();
      FUN_00471b00(param_1_00,*(undefined *)(param_1 + 1),*(undefined *)((int)param_1 + 3));
    }
    break;
  case 0x555:
    local_a8 = CONCAT22(*(undefined2 *)(param_1_00 + 0x166),0x555);
    FUN_004ed0e0(&local_a8,4);
    break;
  case 0x556:
    if ((*(int *)(param_1_00 + 0x1444) != 1) && (*(int *)(param_1_00 + 0x1358) == 0)) {
      DVar6 = GetTickCount();
      if (*(int *)(param_1_00 + 0x587c) == 0) {
        FUN_0049dd00(DVar6 + 10000,*(undefined4 *)(param_1_00 + 0xd0),
                     *(undefined4 *)(param_1_00 + 0xd4),*(undefined4 *)(param_1_00 + 0xd8));
      }
    }
    break;
  case 0x557:
    if (((*(int *)(param_1_00 + 0x1444) != 1) && (*(int *)(param_1_00 + 0x5880) == 0)) &&
       ((*(int *)(param_1_00 + 0x1358) == 0 &&
        (((*(byte *)(param_1 + 1) != 0 &&
          ((int)(uint)*(byte *)(param_1 + 1) <= *(int *)(param_1_00 + 0x130c))) &&
         (*(byte *)((int)param_1 + 3) < 0x18)))))) {
      FUN_00456610(uVar3);
      FUN_00487030();
      FUN_00472da0(param_1_00,*(undefined *)(param_1 + 1),*(undefined *)((int)param_1 + 3),
                   *(undefined4 *)(param_1 + 2),0);
    }
    break;
  case 0x559:
    if (((*(int *)(param_1_00 + 0x1444) == 1) || (*(int *)(param_1_00 + 0x5880) != 0)) ||
       (*(int *)(param_1_00 + 0x1358) != 0)) break;
    if (*(int *)(param_1_00 + 0x147c) != 0) {
      FUN_00472b80();
      break;
    }
    if (((*(byte *)(param_1 + 1) == 0) ||
        (*(int *)(param_1_00 + 0x130c) < (int)(uint)*(byte *)(param_1 + 1))) ||
       (0x17 < *(byte *)((int)param_1 + 3))) break;
    FUN_00456610(uVar3);
    FUN_00487030();
    uVar9 = *(undefined *)(param_1 + 2);
    uVar7 = *(undefined4 *)((int)param_1 + 5);
LAB_00478ff0:
    FUN_00472da0(param_1_00,*(undefined *)(param_1 + 1),*(undefined *)((int)param_1 + 3),uVar7,uVar9
                );
  }
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
}

