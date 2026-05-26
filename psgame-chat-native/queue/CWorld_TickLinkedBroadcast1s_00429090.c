/*
 * server/ps_game.exe — CWorld_TickLinkedBroadcast1s
 * Requested VA: 0x00429090
 * Entry Ghidra:  00429090
 * Ghidra name:   FUN_00429090
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00429090(int param_1,uint param_2)

{
  LPCRITICAL_SECTION p_Var1;
  byte bVar2;
  int iVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  undefined auStack_60 [4];
  float fStack_5c;
  int local_58;
  int iStack_54;
  int iStack_50;
  float fStack_4c;
  undefined2 auStack_48 [2];
  undefined2 uStack_44;
  undefined2 uStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  LPCRITICAL_SECTION local_2c;
  int *piStack_28;
  uint uStack_24;
  int *piStack_20;
  uint uStack_1c;
  undefined2 uStack_18;
  undefined uStack_16;
  undefined4 uStack_15;
  undefined4 uStack_11;
  undefined2 uStack_d;
  undefined uStack_b;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)auStack_60;
  local_2c = (LPCRITICAL_SECTION)(param_1 + 0x23c);
  local_58 = param_1;
  EnterCriticalSection(local_2c);
  iVar3 = *(int *)(*(int *)(param_1 + 0x234) + 4);
  *(int *)(param_1 + 0x238) = iVar3;
  iVar9 = local_58;
  if (iVar3 != *(int *)(param_1 + 0x234)) {
    do {
      local_58 = iVar9;
      if (iVar3 == 0) break;
      iStack_38 = *(int *)(iVar3 + 0x1c) + -1;
      iVar6 = *(int *)(iVar3 + 0x1c) + 1;
      iVar13 = *(int *)(iVar3 + 0x20) + -1;
      iVar8 = *(int *)(iVar3 + 0x20) + 1;
      if (iStack_38 < 0) {
        iStack_38 = 0;
      }
      if (*(int *)(iVar9 + 0x2c) <= iVar6) {
        iVar6 = *(int *)(iVar9 + 0x2c) + -1;
      }
      if (iVar13 < 0) {
        iVar13 = 0;
      }
      if (*(int *)(iVar9 + 0x30) <= iVar8) {
        iVar8 = *(int *)(iVar9 + 0x30) + -1;
      }
      iVar12 = iStack_38;
      iStack_54 = iVar13;
      iStack_3c = iVar8;
      iStack_34 = iVar6;
      if (iVar13 <= iVar8) {
        do {
          iVar10 = iVar12;
          iStack_54 = iVar13;
          iStack_50 = iVar12;
          if (iVar12 <= iVar6) {
            do {
              iVar10 = iVar12 * 0x124;
              iStack_50 = iVar12;
              iStack_30 = iVar10;
              EnterCriticalSection
                        ((LPCRITICAL_SECTION)
                         (*(int *)(*(int *)(iVar9 + 0x34) + iVar13 * 4) + 8 + iVar10));
              iVar6 = *(int *)(*(int *)(iVar9 + 0x34) + iVar13 * 4);
              iVar8 = *(int *)(iVar6 + iVar10);
              iVar9 = *(int *)(iVar8 + 0xc);
              if (iVar9 == 0) {
                iVar9 = 0;
              }
              else {
                iVar9 = iVar9 + -8;
              }
              *(int *)(iVar6 + iVar10 + 4) = iVar9;
              if (iVar9 != iVar8) {
                do {
                  if (iVar9 == 0) break;
                  if ((((*(int *)(iVar9 + 0x1444) != 1) &&
                       (*(int *)(*(int *)(*(int *)(iVar9 + 0xe0) + 0x28) + 0x7c) < 1)) &&
                      (*(char *)(iVar3 + 0x34) != *(char *)(iVar9 + 0x12d))) &&
                     ((*(char *)(iVar9 + 0x5815) != '\0' && (*(char *)(iVar9 + 0x5814) != '\0')))) {
                    fVar4 = *(float *)(iVar9 + 0xd0) - *(float *)(iVar3 + 8);
                    fStack_4c = *(float *)(iVar9 + 0xd8) - *(float *)(iVar3 + 0x10);
                    fStack_5c = fVar4 * fVar4 + fStack_4c * fStack_4c;
                    fVar14 = (float10)FUN_0041b8a0(fStack_5c);
                    fStack_5c = (float)(uint)*(byte *)(*(int *)(iVar3 + 0x3c) + 0x57);
                    if (fVar14 <= (float10)(int)fStack_5c) {
                      FUN_00499980();
                      FUN_00428ed0(*(undefined4 *)(iVar9 + 0x1234),*(undefined4 *)(iVar9 + 0x123c),
                                   *(undefined4 *)(iVar9 + 0x1238),*(undefined4 *)(iVar9 + 0x178),
                                   *(undefined4 *)(iVar9 + 0x180),*(undefined4 *)(iVar9 + 0x17c));
                      cVar5 = FUN_004581f0(1,*(undefined4 *)(iVar3 + 0x30),auStack_48);
                      if (cVar5 != '\0') {
                        FUN_004654c0(1,*(undefined4 *)(iVar3 + 0x30),0);
                      }
                      uStack_16 = 0;
                      uStack_18 = 0x513;
                      uStack_15 = *(undefined4 *)(iVar3 + 0x30);
                      uStack_11 = *(undefined4 *)(iVar9 + 0xdc);
                      uStack_d = **(undefined2 **)(iVar3 + 0x3c);
                      uStack_b = *(undefined *)(*(int *)(iVar3 + 0x3c) + 2);
                      uStack_a = auStack_48[0];
                      uStack_8 = uStack_44;
                      uStack_6 = uStack_40;
                      if (*(int *)(iVar3 + 0x18) != 0) {
                        FUN_00427cf0(*(int *)(iVar3 + 0x18),&uStack_18,0x14,iVar3 + 8,_DAT_00574168,
                                     *(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar9 + 0xdc),6);
                      }
                      iVar9 = local_58;
                      if (*(short *)(*(int *)(iVar3 + 0x3c) + 0x32) == 0x65) {
                        piVar7 = *(int **)(local_58 + 0x238);
                        if (*(int **)(local_58 + 0x234) != piVar7) {
                          *(int *)(local_58 + 0x238) = *piVar7;
                          if ((*piVar7 != 0) && (piVar7[1] != 0)) {
                            *(int *)(*piVar7 + 4) = piVar7[1];
                            *(int *)piVar7[1] = *piVar7;
                            piVar7[1] = 0;
                            *piVar7 = 0;
                          }
                          *(int *)(local_58 + 0x254) = *(int *)(local_58 + 0x254) + -1;
                        }
                        iVar13 = DAT_00587964;
                        piVar7 = (int *)(DAT_00587964 + 0xcc);
                        p_Var1 = (LPCRITICAL_SECTION)(DAT_00587964 + 0xd8);
                        EnterCriticalSection(p_Var1);
                        if (*piVar7 == 0) {
                          *piVar7 = iVar3;
                          *(undefined4 *)(iVar3 + 4) = 0;
                        }
                        else {
                          *(int *)(iVar3 + 4) = *piVar7;
                          *piVar7 = iVar3;
                        }
                        *(int *)(iVar13 + 0xd4) = *(int *)(iVar13 + 0xd4) + 1;
                        LeaveCriticalSection(p_Var1);
                        LeaveCriticalSection
                                  ((LPCRITICAL_SECTION)
                                   (*(int *)(*(int *)(iVar9 + 0x34) + iStack_54 * 4) + 8 +
                                   iStack_50 * 0x124));
                        goto LAB_00429852;
                      }
                    }
                  }
                  iVar13 = *(int *)(*(int *)(local_58 + 0x34) + iStack_54 * 4);
                  iVar9 = *(int *)(*(int *)(iVar13 + 4 + iStack_30) + 0xc);
                  piVar7 = (int *)(iVar13 + iStack_30);
                  if (iVar9 == 0) {
                    iVar9 = 0;
                  }
                  else {
                    iVar9 = iVar9 + -8;
                  }
                  piVar7[1] = iVar9;
                  iVar10 = iStack_30;
                  iVar13 = iStack_54;
                } while (iVar9 != *piVar7);
              }
              iVar9 = local_58;
              LeaveCriticalSection
                        ((LPCRITICAL_SECTION)
                         (*(int *)(*(int *)(local_58 + 0x34) + iVar13 * 4) + 8 + iVar10));
              EnterCriticalSection
                        ((LPCRITICAL_SECTION)
                         (*(int *)(*(int *)(iVar9 + 0x34) + iVar13 * 4) + 0x34 + iVar10));
              iVar6 = *(int *)(*(int *)(iVar9 + 0x34) + iVar13 * 4);
              iVar8 = *(int *)(iVar6 + 0x2c + iVar10);
              iVar9 = *(int *)(iVar8 + 0x78);
              if (iVar9 == 0) {
                iVar9 = 0;
              }
              else {
                iVar9 = iVar9 + -0x74;
              }
              *(int *)(iVar6 + iVar10 + 0x30) = iVar9;
              if ((iVar9 != iVar8) && (iVar9 != 0)) {
LAB_004293c0:
                if (*(int *)(iVar9 + 0x31c) == 0) {
                  if ((*(short *)(*(int *)(iVar3 + 0x3c) + 0x32) == 0x65) &&
                     ((bVar2 = *(byte *)(*(int *)(iVar3 + 0x3c) + 0x4d), bVar2 == 0 ||
                      (*(char *)(*(int *)(iVar9 + 0xd4) + 0x45 + (uint)bVar2) != '\0')))) {
                    iVar9 = *(int *)(*(int *)(local_58 + 0x34) + iVar13 * 4);
                    piVar7 = (int *)(iVar9 + 0x2c + iVar10);
                    iVar9 = *(int *)(*(int *)(iVar9 + 0x30 + iVar10) + 0x78);
                    if (iVar9 == 0) goto LAB_0042964b;
                    iVar9 = iVar9 + -0x74;
                    goto LAB_0042964d;
                  }
                  fStack_5c = (float)(uint)*(byte *)(iVar3 + 0x34);
                  if (*(int *)(iVar9 + 0x70) == 0) {
                    iVar13 = *(int *)(iVar9 + 0x1a8);
                  }
                  else if (*(int *)(iVar9 + 0x6c) == 0) {
                    iVar13 = 0;
                  }
                  else {
                    uVar11 = *(int *)(iVar9 + 0x6c) + *(uint *)(iVar9 + 0x68);
                    if (uVar11 < *(uint *)(iVar9 + 0x68)) {
                      FUN_0051b1ad();
                    }
                    piVar7 = *(int **)(iVar9 + 0x50);
                    piStack_28 = piVar7;
                    uStack_24 = uVar11;
                    if (piVar7 == (int *)0x0) {
                      FUN_0051b1ad();
                      iVar13 = 0;
                    }
                    else {
                      iVar13 = *piVar7;
                    }
                    uVar11 = uVar11 - 1;
                    if ((uint)(*(int *)(iVar13 + 0x1c) + *(int *)(iVar13 + 0x18)) < uVar11) {
LAB_00429474:
                      FUN_0051b1ad();
                    }
                    else {
                      if (piVar7 == (int *)0x0) {
                        iVar13 = 0;
                      }
                      else {
                        iVar13 = *piVar7;
                      }
                      if (uVar11 < *(uint *)(iVar13 + 0x18)) goto LAB_00429474;
                    }
                    piStack_20 = piStack_28;
                    uStack_1c = uVar11;
                    piVar7 = (int *)FUN_00425b90();
                    iVar13 = *(int *)(*piVar7 + 0x48);
                  }
                  if ((iVar13 != 2) &&
                     ((fVar4 = *(float *)(*(int *)(iVar9 + 0xd4) + 0x78), fVar4 == 2.8026e-45 ||
                      (fVar4 != fStack_5c)))) {
                    iVar13 = *(int *)(iVar3 + 0x3c);
                    fStack_4c = *(float *)(iVar9 + 0x7c) - *(float *)(iVar3 + 8);
                    fVar4 = *(float *)(iVar9 + 0x84) - *(float *)(iVar3 + 0x10);
                    fStack_5c = fStack_4c * fStack_4c + fVar4 * fVar4;
                    fVar14 = (float10)FUN_0041b8a0(fStack_5c);
                    fStack_5c = (float)(uint)*(byte *)(iVar13 + 0x57);
                    if (fVar14 <= (float10)(int)fStack_5c) {
                      iVar6 = *(int *)(iVar9 + 0xd4);
                      FUN_00428ed0(*(undefined4 *)(iVar9 + 0x2a8),*(undefined2 *)(iVar9 + 0x2ac),
                                   *(undefined2 *)(iVar9 + 0x2ae),*(undefined4 *)(iVar6 + 0x30),
                                   *(undefined2 *)(iVar6 + 0x34),*(undefined2 *)(iVar6 + 0x36));
                      cVar5 = FUN_004a1980(iVar9,1,*(undefined4 *)(iVar3 + 0x30),0,
                                           *(undefined2 *)(iVar13 + 100),0);
                      if (cVar5 == '\0') {
                        fStack_5c = *(float *)(iVar3 + 0x30);
                        iVar13 = FUN_00415480(&fStack_5c);
                        if (iVar13 != 0) {
                          FUN_004b4010(iVar13,1);
                        }
                      }
                      else {
                        FUN_004a1c20(1,*(undefined4 *)(iVar3 + 0x30));
                      }
                      uStack_16 = 0;
                      uStack_18 = 0x519;
                      uStack_15 = *(undefined4 *)(iVar3 + 0x30);
                      uStack_11 = *(undefined4 *)(iVar9 + 0x88);
                      uStack_d = **(undefined2 **)(iVar3 + 0x3c);
                      uStack_b = *(undefined *)(*(int *)(iVar3 + 0x3c) + 2);
                      uStack_a = auStack_48[0];
                      uStack_8 = uStack_44;
                      uStack_6 = uStack_40;
                      if (*(int *)(iVar3 + 0x18) != 0) {
                        FUN_00427cf0(*(int *)(iVar3 + 0x18),&uStack_18,0x14,iVar3 + 8,_DAT_00574168,
                                     0,*(undefined4 *)(iVar3 + 0x30),6);
                      }
                      iVar9 = local_58;
                      if (*(short *)(*(int *)(iVar3 + 0x3c) + 0x32) != 0x65) goto LAB_00429625;
                      piVar7 = *(int **)(local_58 + 0x238);
                      if (*(int **)(local_58 + 0x234) != piVar7) {
                        *(int *)(local_58 + 0x238) = *piVar7;
                        if ((*piVar7 != 0) && (piVar7[1] != 0)) {
                          *(int *)(*piVar7 + 4) = piVar7[1];
                          *(int *)piVar7[1] = *piVar7;
                          piVar7[1] = 0;
                          *piVar7 = 0;
                        }
                        *(int *)(local_58 + 0x254) = *(int *)(local_58 + 0x254) + -1;
                      }
                      iVar13 = DAT_00587964;
                      piVar7 = (int *)(DAT_00587964 + 0xcc);
                      p_Var1 = (LPCRITICAL_SECTION)(DAT_00587964 + 0xd8);
                      EnterCriticalSection(p_Var1);
                      if (*piVar7 == 0) {
                        *piVar7 = iVar3;
                        *(undefined4 *)(iVar3 + 4) = 0;
                      }
                      else {
                        *(int *)(iVar3 + 4) = *piVar7;
                        *piVar7 = iVar3;
                      }
                      *(int *)(iVar13 + 0xd4) = *(int *)(iVar13 + 0xd4) + 1;
                      LeaveCriticalSection(p_Var1);
                      LeaveCriticalSection
                                ((LPCRITICAL_SECTION)
                                 (*(int *)(*(int *)(iVar9 + 0x34) + iStack_54 * 4) + 0x34 +
                                 iStack_50 * 0x124));
                      goto LAB_00429852;
                    }
                  }
                }
LAB_00429625:
                iVar13 = *(int *)(*(int *)(local_58 + 0x34) + iStack_54 * 4);
                iVar9 = *(int *)(*(int *)(iVar13 + 0x30 + iStack_30) + 0x78);
                piVar7 = (int *)(iVar13 + 0x2c + iStack_30);
                iVar10 = iStack_30;
                iVar13 = iStack_54;
                if (iVar9 == 0) {
LAB_0042964b:
                  iVar9 = 0;
                }
                else {
                  iVar9 = iVar9 + -0x74;
                }
LAB_0042964d:
                piVar7[1] = iVar9;
                if ((iVar9 == *piVar7) || (iVar9 == 0)) goto LAB_0042965c;
                goto LAB_004293c0;
              }
LAB_0042965c:
              iVar9 = local_58;
              LeaveCriticalSection
                        ((LPCRITICAL_SECTION)
                         (*(int *)(*(int *)(local_58 + 0x34) + iVar13 * 4) + 0x34 + iVar10));
              iVar12 = iStack_50 + 1;
              iVar6 = iStack_34;
              iVar8 = iStack_3c;
              iVar10 = iStack_38;
              iStack_50 = iVar12;
            } while (iVar12 <= iStack_34);
          }
          iVar13 = iVar13 + 1;
          iVar12 = iVar10;
          iStack_54 = iVar13;
        } while (iVar13 <= iVar8);
      }
      if (*(uint *)(iVar3 + 0x38) < param_2) {
        piVar7 = *(int **)(local_58 + 0x238);
        if (*(int **)(local_58 + 0x234) != piVar7) {
          *(int *)(local_58 + 0x238) = *piVar7;
          if ((*piVar7 != 0) && (piVar7[1] != 0)) {
            *(int *)(*piVar7 + 4) = piVar7[1];
            *(int *)piVar7[1] = *piVar7;
            piVar7[1] = 0;
            *piVar7 = 0;
          }
          *(int *)(local_58 + 0x254) = *(int *)(local_58 + 0x254) + -1;
        }
        iVar9 = DAT_00587964;
        piVar7 = (int *)(DAT_00587964 + 0xcc);
        p_Var1 = (LPCRITICAL_SECTION)(DAT_00587964 + 0xd8);
        EnterCriticalSection(p_Var1);
        if (*piVar7 == 0) {
          *piVar7 = iVar3;
          *(undefined4 *)(iVar3 + 4) = 0;
        }
        else {
          *(int *)(iVar3 + 4) = *piVar7;
          *piVar7 = iVar3;
        }
        *(int *)(iVar9 + 0xd4) = *(int *)(iVar9 + 0xd4) + 1;
        LeaveCriticalSection(p_Var1);
      }
LAB_00429852:
      iVar3 = *(int *)(*(int *)(local_58 + 0x238) + 4);
      *(int *)(local_58 + 0x238) = iVar3;
      iVar9 = local_58;
    } while (iVar3 != *(int *)(local_58 + 0x234));
  }
  LeaveCriticalSection(local_2c);
  ___security_check_cookie_4();
  return;
}

