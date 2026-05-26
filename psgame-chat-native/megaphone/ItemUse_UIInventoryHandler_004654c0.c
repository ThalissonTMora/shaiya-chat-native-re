/*
 * server/ps_game.exe — ItemUse_UIInventoryHandler
 * VA solicitado: 0x004654C0
 * Entry Ghidra:  004654c0
 * Ghidra name:   FUN_004654c0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: megaphone
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004654c0(int param_1_00,uint param_1,uint param_2,char param_3)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  DWORD DVar8;
  int iVar9;
  undefined4 uVar10;
  uint local_174;
  int *piStack_170;
  int *piStack_16c;
  int local_168;
  undefined4 local_164;
  undefined2 uStack_160;
  int local_15c;
  int iStack_158;
  int local_154;
  int local_150;
  int local_14c;
  undefined8 uStack_148;
  byte local_134;
  uint local_130;
  int local_128 [21];
  undefined3 local_d4;
  undefined uStack_d1;
  undefined uStack_d0;
  undefined2 uStack_cf;
  char acStack_cd [37];
  undefined2 local_a8 [43];
  uint local_51;
  char local_4d [21];
  undefined2 local_38;
  undefined4 local_36;
  undefined4 local_32;
  undefined4 local_2e;
  undefined4 local_2a;
  uint local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00552bfb;
  local_14 = ExceptionList;
  local_1c = DAT_0057f7c4 ^ (uint)&local_174;
  uVar3 = DAT_0057f7c4 ^ (uint)&stack0xfffffe80;
  ExceptionList = &local_14;
  if (*(int *)(param_1_00 + 0x1444) == 1) goto LAB_00465e12;
  *(undefined4 *)(param_1_00 + 0x1478) = 5;
  if (*(int *)(param_1_00 + 0x5958) == 0) {
    iVar5 = *(int *)(param_1_00 + 0x594c);
    if (iVar5 == 1) {
      *(undefined4 *)(param_1_00 + 0x1478) = 1;
    }
    else if (iVar5 == 2) {
      *(undefined4 *)(param_1_00 + 0x1478) = 1;
    }
    else if (iVar5 == 3) goto LAB_0046554b;
  }
  else {
LAB_0046554b:
    *(undefined4 *)(param_1_00 + 0x1478) = 0;
  }
  *(undefined4 *)(param_1_00 + 0x1444) = 1;
  *(undefined4 *)(param_1_00 + 0x1448) = 0;
  *(undefined4 *)(param_1_00 + 0x1238) = 0;
  *(undefined4 *)(param_1_00 + 0x123c) = 0;
  *(undefined4 *)(param_1_00 + 0x1234) = 0;
  FUN_00456610(uVar3);
  FUN_00487030();
  FUN_00456550();
  local_14c = param_1_00 + 0x1590;
  cVar2 = FUN_004d0f00();
  if (cVar2 == '\0') {
    local_164._0_2_ = (undefined2)param_2;
    local_164._2_2_ = (undefined2)(param_2 >> 0x10);
    if (param_1 == 1) {
      FUN_00467f60();
      local_a8[0] = 0x303;
      local_51 = local_130;
      local_4d[0] = '\0';
      local_38 = 0;
      iVar5 = FUN_00415480(&local_164);
      if (iVar5 != 0) {
        pcVar4 = (char *)(iVar5 + 0x184);
        iVar9 = -(int)pcVar4;
        do {
          cVar2 = *pcVar4;
          pcVar4[(int)(local_4d + iVar9)] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
      }
      if (param_2 != *(uint *)(param_1_00 + 0xdc)) {
        FUN_004670a0(param_1_00,iVar5);
      }
      local_36 = *(undefined4 *)(param_1_00 + 0x148);
      local_32 = *(undefined4 *)(param_1_00 + 0x14c);
      local_2e = *(undefined4 *)(param_1_00 + 0x150);
      local_2a = *(undefined4 *)(param_1_00 + 0x154);
      uVar10 = 0x82;
      piVar6 = (int *)local_a8;
    }
    else {
      FUN_00467f60();
      local_128[0] = CONCAT22(local_128[0]._2_2_,0x301);
      uStack_cf = 0;
      _local_d4 = _local_d4 & 0xffffff;
      uStack_d0 = 0;
      acStack_cd[0] = '\0';
      iVar5 = FUN_0041e1d0(&local_164);
      if (iVar5 != 0) {
        uStack_d1 = (undefined)*(undefined2 *)(iVar5 + 0x2a4);
        uStack_d0 = (undefined)((ushort)*(undefined2 *)(iVar5 + 0x2a4) >> 8);
        pcVar7 = (char *)(*(int *)(iVar5 + 0xd4) + 2);
        pcVar4 = acStack_cd;
        do {
          cVar2 = *pcVar7;
          *pcVar4 = cVar2;
          pcVar7 = pcVar7 + 1;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
      }
      uVar10 = 0x7b;
      piVar6 = local_128;
    }
    FUN_004ed210(piVar6,uVar10);
  }
  else {
    if (local_134 == 1) {
      FUN_00467f60();
      local_a8[0] = 0x303;
      local_51 = local_130;
      local_4d[0] = '\0';
      local_38 = 0;
      if (local_130 == *(uint *)(param_1_00 + 0xdc)) {
        pcVar4 = (char *)(param_1_00 + 0x184);
        iVar5 = -(int)pcVar4;
        do {
          cVar2 = *pcVar4;
          pcVar4[(int)(local_4d + iVar5)] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        local_164 = (LPCRITICAL_SECTION)CONCAT22(local_164._2_2_,(undefined2)local_164);
        if (param_3 != '\0') {
          *(undefined4 *)(param_1_00 + 0x1478) = 0xffffffff;
          if (*(int *)(param_1_00 + 0x558c) == 4) {
            iVar5 = FUN_0041c6e0(*(undefined4 *)(param_1_00 + 0x5594));
            local_164 = (LPCRITICAL_SECTION)CONCAT22(local_164._2_2_,(undefined2)local_164);
            if (iVar5 != 0) {
              iVar9 = 4;
              goto LAB_00465aea;
            }
          }
          else {
            local_164 = (LPCRITICAL_SECTION)CONCAT22(local_164._2_2_,(undefined2)local_164);
            if (*(int *)(param_1_00 + 0x55a4) != 0) {
              iVar9 = 5;
              iVar5 = param_1_00;
              goto LAB_00465aea;
            }
          }
        }
      }
      else {
        local_174 = local_130;
        iVar5 = FUN_00415480(&local_174);
        local_15c = iVar5;
        local_164 = (LPCRITICAL_SECTION)CONCAT22(local_164._2_2_,(undefined2)local_164);
        if (iVar5 != 0) {
          pcVar4 = (char *)(iVar5 + 0x184);
          iVar9 = -(int)pcVar4;
          do {
            cVar2 = *pcVar4;
            pcVar4[(int)(local_4d + iVar9)] = cVar2;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          if (param_3 == '\0') {
            iVar9 = FUN_00489ee0();
            if (iVar9 == 3) {
              iVar5 = *(int *)(iVar5 + 0x17f4);
              local_168 = iVar5;
              if (iVar5 == 0) {
                local_174 = FUN_00465010();
                uVar3 = FUN_005250c0();
                local_174 = uVar3;
                if (*(byte *)(param_1_00 + 0x1441) != 0) {
                  local_174 = (uint)*(byte *)(param_1_00 + 0x1441);
                  uVar3 = FUN_005250c0();
                }
                if (uVar3 != 0) {
                  FUN_00465060(param_2,uVar3,0);
                }
                FUN_00467ee0();
                FUN_004670a0(param_1_00,local_15c);
              }
              else {
                local_150 = 0;
                local_154 = 0;
                local_128[0] = 0;
                local_128[1] = 0;
                local_128[2] = 0;
                local_128[3] = 0;
                local_128[4] = 0;
                local_128[5] = 0;
                local_128[6] = 0;
                local_128[7] = 0;
                local_128[8] = 0;
                local_128[9] = 0;
                local_128[10] = 0;
                local_128[0xb] = 0;
                local_128[0xc] = 0;
                local_128[0xd] = 0;
                local_128[0xe] = 0;
                local_128[0xf] = 0;
                local_128[0x10] = 0;
                local_128[0x11] = 0;
                local_128[0x12] = 0;
                local_128[0x13] = 0;
                local_128[0x14] = 0;
                _local_d4 = 0;
                uStack_d0 = 0;
                uStack_cf = 0;
                acStack_cd[0] = '\0';
                acStack_cd[1] = '\0';
                acStack_cd[2] = '\0';
                acStack_cd[3] = '\0';
                acStack_cd[4] = '\0';
                acStack_cd[5] = '\0';
                acStack_cd[6] = '\0';
                acStack_cd[7] = '\0';
                acStack_cd[8] = '\0';
                acStack_cd[9] = '\0';
                acStack_cd[10] = '\0';
                acStack_cd[0xb] = '\0';
                acStack_cd[0xc] = '\0';
                acStack_cd[0xd] = '\0';
                acStack_cd[0xe] = '\0';
                acStack_cd[0xf] = '\0';
                acStack_cd[0x10] = '\0';
                acStack_cd[0x11] = '\0';
                acStack_cd[0x12] = '\0';
                acStack_cd[0x13] = '\0';
                acStack_cd[0x14] = '\0';
                acStack_cd[0x15] = '\0';
                acStack_cd[0x16] = '\0';
                acStack_cd[0x17] = '\0';
                acStack_cd[0x18] = '\0';
                acStack_cd[0x19] = '\0';
                acStack_cd[0x1a] = '\0';
                acStack_cd[0x1b] = '\0';
                acStack_cd[0x1c] = '\0';
                local_164 = (LPCRITICAL_SECTION)(iVar5 + 0x118);
                EnterCriticalSection(local_164);
                if (*(char *)(iVar5 + 0x114) == '\0') {
                  iVar9 = *(int *)(iVar5 + 0x10);
                  iStack_158 = 0;
                  local_174 = 0;
                  if (0 < iVar9) {
                    piStack_16c = (int *)(iVar5 + 0x18);
                    do {
                      iVar5 = *piStack_16c;
                      cVar2 = FUN_0046ad40(100);
                      if (cVar2 != '\0') {
                        if (iVar9 < 0x1f) {
                          uStack_148 = *(undefined8 *)(&DAT_00581b10 + iVar9 * 8);
                        }
                        else {
                          uStack_148 = 0x3ff0000000000000;
                        }
                        uVar1 = *(ushort *)(iVar5 + 0x136);
                        piStack_170 = (int *)FUN_00465010();
                        piStack_170 = (int *)FUN_005250c0();
                        if (7 < (int)(*(int *)(local_168 + 0x10c) - (uint)uVar1)) {
                          FUN_0044e230();
                        }
                        piVar6 = (int *)FUN_005250c0();
                        piStack_170 = piVar6;
                        if (*(byte *)(param_1_00 + 0x1441) != 0) {
                          piStack_170 = (int *)(uint)*(byte *)(param_1_00 + 0x1441);
                          piVar6 = (int *)FUN_005250c0();
                        }
                        if (piVar6 != (int *)0x0) {
                          FUN_00465060(param_2,piVar6,0);
                        }
                        if (iStack_158 == 0) {
                          iStack_158 = 1;
                          local_150 = iVar5;
                        }
                        else {
                          local_128[local_154] = iVar5;
                          local_154 = local_154 + 1;
                        }
                      }
                      iVar9 = *(int *)(local_168 + 0x10);
                      piStack_16c = piStack_16c + 2;
                      local_174 = local_174 + 1;
                    } while ((int)local_174 < iVar9);
                  }
                }
                else if (*(char *)(iVar5 + 0x114) == '\x01') {
                  iVar9 = *(int *)(iVar5 + 0x10);
                  local_174 = 0;
                  iStack_158 = 0;
                  if (0 < iVar9) {
                    piStack_170 = (int *)(iVar5 + 0x18);
                    do {
                      iVar5 = *piStack_170;
                      cVar2 = FUN_0046ad40(100);
                      if (cVar2 != '\0') {
                        if (iVar9 < 0x1f) {
                          uStack_148 = *(undefined8 *)(&DAT_00581b50 + iVar9 * 8);
                        }
                        else {
                          uStack_148 = 0x3ff0000000000000;
                        }
                        uVar1 = *(ushort *)(iVar5 + 0x136);
                        piStack_16c = (int *)FUN_00465010();
                        piStack_16c = (int *)FUN_005250c0();
                        if (7 < (int)(*(int *)(local_168 + 0x10c) - (uint)uVar1)) {
                          FUN_0044e230();
                        }
                        piVar6 = (int *)FUN_005250c0();
                        piStack_16c = piVar6;
                        if (*(byte *)(param_1_00 + 0x1441) != 0) {
                          piStack_16c = (int *)(uint)*(byte *)(param_1_00 + 0x1441);
                          piVar6 = (int *)FUN_005250c0();
                        }
                        if (piVar6 != (int *)0x0) {
                          FUN_00465060(param_2,piVar6,0);
                        }
                        if (local_174 == 0) {
                          local_174 = 1;
                          local_150 = iVar5;
                        }
                        else {
                          local_128[local_154] = iVar5;
                          local_154 = local_154 + 1;
                        }
                      }
                      iVar9 = *(int *)(local_168 + 0x10);
                      piStack_170 = piStack_170 + 2;
                      iStack_158 = iStack_158 + 1;
                    } while (iStack_158 < iVar9);
                  }
                }
                LeaveCriticalSection(local_164);
                if (local_150 != 0) {
                  FUN_00467ee0();
                }
                iVar5 = local_154;
                iVar9 = 0;
                if (0 < local_154) {
                  do {
                    FUN_00467ce0(param_1_00);
                    iVar9 = iVar9 + 1;
                  } while (iVar9 < iVar5);
                }
                FUN_004670a0(param_1_00,local_15c);
              }
              goto LAB_00465af1;
            }
            *(undefined4 *)(param_1_00 + 0x1478) = 0xffffffff;
          }
          else {
            *(undefined4 *)(param_1_00 + 0x1478) = 0xffffffff;
            if (((*(int *)(param_1_00 + 0x558c) == 4) &&
                (*(int *)(iVar5 + 0x5594) == *(int *)(param_1_00 + 0xdc))) &&
               (*(int *)(param_1_00 + 0x5594) == *(int *)(iVar5 + 0xdc))) {
              iVar9 = 4;
            }
            else {
              local_164 = (LPCRITICAL_SECTION)CONCAT22(local_164._2_2_,(undefined2)local_164);
              if (*(int *)(param_1_00 + 0x55a4) == 0) goto LAB_00465af1;
              iVar9 = 5;
            }
          }
LAB_00465aea:
          FUN_00489f30(iVar9,iVar5);
          local_164 = (LPCRITICAL_SECTION)CONCAT22(local_164._2_2_,(undefined2)local_164);
        }
      }
LAB_00465af1:
      local_36 = *(undefined4 *)(param_1_00 + 0x148);
      local_32 = *(undefined4 *)(param_1_00 + 0x14c);
      local_2e = *(undefined4 *)(param_1_00 + 0x150);
      local_2a = *(undefined4 *)(param_1_00 + 0x154);
      uVar10 = 0x82;
      piVar6 = (int *)local_a8;
    }
    else {
      FUN_00467f60();
      uStack_cf = 0;
      _local_d4 = _local_d4 & 0xffffff;
      uStack_d0 = 0;
      acStack_cd[0] = '\0';
      local_128[0] = CONCAT22(local_128[0]._2_2_,0x301);
      local_164._0_2_ = (undefined2)local_130;
      local_164._2_2_ = (undefined2)(local_130 >> 0x10);
      iVar5 = FUN_0041e1d0(&local_164);
      if (iVar5 != 0) {
        uStack_d1 = (undefined)*(undefined2 *)(iVar5 + 0x2a4);
        uStack_d0 = (undefined)((ushort)*(undefined2 *)(iVar5 + 0x2a4) >> 8);
        pcVar7 = (char *)(*(int *)(iVar5 + 0xd4) + 2);
        pcVar4 = acStack_cd;
        do {
          cVar2 = *pcVar7;
          *pcVar4 = cVar2;
          pcVar7 = pcVar7 + 1;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
      }
      uVar10 = 0x7b;
      piVar6 = local_128;
    }
    FUN_004ed210(piVar6,uVar10);
    param_1 = (uint)local_134;
    param_2 = local_130;
  }
  FUN_0048a1d0(param_1_00);
  FUN_004983e0();
  FUN_004d0db0();
  FUN_004652f0();
  *(undefined4 *)(param_1_00 + 0x58b8) = 0;
  DVar8 = GetTickCount();
  *(DWORD *)(param_1_00 + 0x1470) = DVar8 + 0x2d2a8;
  *(undefined4 *)(param_1_00 + 0x1474) = 0;
  FUN_00465290(param_1,param_2);
  iVar5 = *(int *)(param_1_00 + 0x17f4);
  local_14c = iVar5;
  if (iVar5 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x118));
    if (*(int *)(param_1_00 + 0x17f4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x118));
      iVar5 = 0;
      local_14c = 0;
    }
  }
  uStack_c = 0;
  if (*(int *)(param_1_00 + 0x17f4) != 0) {
    cVar2 = *(char *)(*(int *)(param_1_00 + 0x17f4) + 0x114);
    if (cVar2 == '\0') {
      local_164._0_2_ = 0xc06;
    }
    else if (cVar2 == '\x01') {
      local_164._0_2_ = 0xc11;
    }
    local_164._2_2_ = (undefined2)*(undefined4 *)(param_1_00 + 0xdc);
    uStack_160 = (undefined2)((uint)*(undefined4 *)(param_1_00 + 0xdc) >> 0x10);
    FUN_0044ea00(param_1_00);
    FUN_00450690(param_1_00);
  }
  if (iVar5 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x118));
  }
LAB_00465e12:
  ExceptionList = local_14;
  ___security_check_cookie_4();
  return;
}

