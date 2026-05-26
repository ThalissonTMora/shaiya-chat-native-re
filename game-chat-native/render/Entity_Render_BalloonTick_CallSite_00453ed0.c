/*
 * Game.exe — Entity_Render_BalloonTick_CallSite
 * Requested VA: 0x00453ED0
 * Entry Ghidra:  004534e0
 * Ghidra name:   FUN_004534e0
 * NOTE: VA is inside the function (landmark/hook), not the entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: render
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004534e0(undefined *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  double dVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  byte *pbVar15;
  bool bVar16;
  undefined *puVar17;
  undefined4 uVar18;
  undefined *puVar19;
  float fStack_114;
  undefined4 local_110;
  float local_10c;
  undefined *local_104;
  undefined4 local_100;
  float local_fc;
  undefined4 local_f8;
  undefined local_e8 [12];
  undefined local_dc [16];
  undefined auStack_cc [36];
  undefined auStack_a8 [16];
  undefined auStack_98 [36];
  undefined auStack_74 [52];
  byte abStack_40 [60];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&fStack_114;
  piVar14 = (int *)**(int **)(param_1 + 0x13d9e4);
  *(int **)(param_1 + 0x13d9ec) = piVar14;
  local_104 = param_1;
  if (piVar14 != *(int **)(param_1 + 0x13d9e4)) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x13d9ec) + 0x10);
      if (((iVar3 != 0) && (*(int *)(iVar3 + 0x194) != 0)) &&
         (NAN(*(float *)(iVar3 + 0x328)) != (*(float *)(iVar3 + 0x328) == 1.0))) {
        iVar5 = *(int *)(iVar3 + 0x2c4);
        bVar16 = true;
        if ((iVar5 == 1) && (param_1 = local_104, DAT_022aa816 != *(char *)(iVar3 + 0x2b7))) {
          bVar16 = false;
        }
        if (iVar5 != 0) {
          if (*(char *)(iVar3 + 0x2d4) == '\x01') {
            bVar16 = false;
          }
          if (iVar5 != 0) {
            if ((0 < DAT_007c3e68) && (*(int *)(iVar3 + 0x34) == DAT_007c3e6c)) {
              bVar16 = false;
            }
            if ((((iVar5 != 0) && (0 < DAT_007c3e84)) && (*(int *)(iVar3 + 0x310) == DAT_007c3d4c))
               && (*(char *)(iVar3 + 0x3ca) != '\0')) goto LAB_00453ed5;
          }
        }
        if (bVar16) {
          local_f8 = *(undefined4 *)(iVar3 + 0x18);
          local_100 = *(undefined4 *)(iVar3 + 0x10);
          dVar4 = _DAT_00748528;
          if ((*(int *)(iVar3 + 0xf8) != 4) && (*(int *)(iVar3 + 0xf8) != 7)) {
            dVar4 = _DAT_007484b8;
          }
          local_fc = *(float *)(iVar3 + 0x14) + (float)dVar4;
          if (*(char *)(iVar3 + 0x2b8) != '\x03') {
            local_fc = local_fc - (float)_DAT_0074a790;
          }
          if ((*(int *)(iVar3 + 0x2d0) != 0) &&
             ((*(char *)(iVar3 + 0x3c8) == '\0' || (*(char *)(iVar3 + 0x3c8) == '\x02')))) {
            local_fc = (*(float *)(iVar3 + 0x14) - (float)_DAT_00748078) +
                       *(float *)(*(int *)(iVar3 + 0x2d0) + 0x8c);
          }
          if (((*(int *)(iVar3 + 0x41c) != 0) &&
              (iVar5 = FUN_00452b10(*(int *)(iVar3 + 0x41c)), iVar5 != 0)) &&
             (*(int *)(iVar5 + 0x2d0) != 0)) {
            local_fc = (*(float *)(iVar5 + 0x14) - (float)_DAT_00748078) +
                       *(float *)(*(int *)(iVar5 + 0x2d0) + 0x8c);
          }
          if ((*(char *)(iVar3 + 0x3c0) != '\0') &&
             ((*(char *)(iVar3 + 0x3c8) == '\0' || (*(char *)(iVar3 + 0x3c8) == '\x02')))) {
            local_fc = local_fc + (float)_DAT_00748068;
          }
          puVar6 = (undefined4 *)FUN_0044e5b0(local_e8,&local_100,_DAT_00748430);
          local_100 = *puVar6;
          local_fc = (float)puVar6[1];
          local_f8 = puVar6[2];
          FUN_00573ff0(&local_110,&local_100);
          if (*(int *)(iVar3 + 0x41c) != 0) {
            local_10c = local_10c + (float)_DAT_007480c8;
          }
          if (DAT_007c0e60 != 0) {
            puVar19 = local_dc;
            uVar18 = 3;
            piVar14 = DAT_022b69a8;
            (**(code **)(*DAT_022b69a8 + 0xb4))(DAT_022b69a8,3);
            puVar17 = auStack_a8;
            (**(code **)(*DAT_022b69a8 + 0xb4))(DAT_022b69a8,2,puVar17);
            (**(code **)(*DAT_022b69a8 + 0xb4))(DAT_022b69a8,0x100,auStack_74);
            if ((DAT_007c0d8c == 0) || (param_1 = puVar19, *(char *)(DAT_007c0838 + 0x1d0) == '\0'))
            {
              iVar5 = DAT_007c0e50;
              if (*(int *)(*(int *)(param_1 + 0x140038) + 0x34) == *(int *)(iVar3 + 0x34)) {
                iVar5 = DAT_007c0e4c;
              }
              if (iVar5 != 0) {
                abStack_40[0] = 0;
                abStack_40[1] = 0;
                abStack_40[2] = 0;
                abStack_40[3] = 0;
                abStack_40[4] = 0;
                abStack_40[5] = 0;
                abStack_40[6] = 0;
                abStack_40[7] = 0;
                abStack_40[8] = 0;
                abStack_40[9] = 0;
                abStack_40[10] = 0;
                abStack_40[0xb] = 0;
                abStack_40[0xc] = 0;
                abStack_40[0xd] = 0;
                abStack_40[0xe] = 0;
                abStack_40[0xf] = 0;
                abStack_40[0x10] = 0;
                abStack_40[0x11] = 0;
                abStack_40[0x12] = 0;
                abStack_40[0x13] = 0;
                abStack_40[0x14] = 0;
                cVar2 = *(char *)(iVar3 + 0x2ec);
                iVar5 = -1;
                if (cVar2 == '\x04') {
                  pbVar15 = (byte *)FUN_00420db0(0x14aa);
                  pbVar9 = abStack_40;
                  do {
                    bVar1 = *pbVar15;
                    *pbVar9 = bVar1;
                    pbVar15 = pbVar15 + 1;
                    pbVar9 = pbVar9 + 1;
                  } while (bVar1 != 0);
LAB_0045392d:
                  iVar5 = -0x100;
                }
                else {
                  if (cVar2 == '\x05') {
                    pbVar15 = (byte *)FUN_00420db0(0x14ab);
                    pbVar9 = abStack_40;
                    do {
                      bVar1 = *pbVar15;
                      *pbVar9 = bVar1;
                      pbVar15 = pbVar15 + 1;
                      pbVar9 = pbVar9 + 1;
                    } while (bVar1 != 0);
                    goto LAB_0045392d;
                  }
                  if (cVar2 == '\x06') {
                    pbVar15 = (byte *)FUN_00420db0(0x14ac);
                    pbVar9 = abStack_40;
                    do {
                      bVar1 = *pbVar15;
                      *pbVar9 = bVar1;
                      pbVar15 = pbVar15 + 1;
                      pbVar9 = pbVar9 + 1;
                    } while (bVar1 != 0);
                    goto LAB_0045392d;
                  }
                  pcVar7 = (char *)(iVar3 + 0x10c);
                  iVar10 = -(int)pcVar7;
                  do {
                    cVar2 = *pcVar7;
                    pcVar7[(int)(abStack_40 + iVar10)] = cVar2;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar2 != '\0');
                  if (*(char *)(iVar3 + 0x2d4) == '\0') {
                    if ((DAT_022aa7f8 != 0) &&
                       (iVar10 = 0, 0 < (int)(DAT_022aa710 - DAT_022aa70c & 0xfffffffcU))) {
                      do {
                        piVar8 = (int *)FUN_004e9700(iVar10);
                        if ((piVar8 != (int *)0x0) && (*piVar8 == *(int *)(iVar3 + 0x34))) {
                          iVar5 = -0xff0100;
                        }
                        iVar10 = iVar10 + 1;
                      } while (iVar10 < DAT_022aa710 - DAT_022aa70c >> 2);
                    }
                    if ((*(char *)(iVar3 + 0x2c8) == '\0') &&
                       (DAT_022aa816 != *(char *)(iVar3 + 0x2b7))) {
                      iVar5 = -0x10000;
                    }
                  }
                  else {
                    iVar5 = -0xffff01;
                  }
                  if ((0 < DAT_007c3e68) && (*(int *)(iVar3 + 0x34) == DAT_007c3e6c)) {
                    iVar5 = -0x10000;
                  }
                  if (((0 < DAT_007c3e84) && (*(int *)(iVar3 + 0x310) == DAT_007c3d4c)) &&
                     (*(char *)(iVar3 + 0x3ca) != '\0')) {
                    iVar5 = -0x10000;
                  }
                }
                piVar8 = *(int **)(iVar3 + 0x314);
                if (piVar8 == (int *)0x0) {
LAB_004539a0:
                  uVar11 = FUN_0057c280(abStack_40);
                  *(undefined4 *)(iVar3 + 0x314) = uVar11;
                  FUN_0057cc70(abStack_40);
                  uVar11 = FUN_00631be0();
                  *(undefined4 *)(iVar3 + 0x318) = uVar11;
                  pbVar9 = abStack_40;
                  iVar10 = iVar3 - (int)pbVar9;
                  do {
                    bVar1 = *pbVar9;
                    pbVar9[iVar10 + 0x121] = bVar1;
                    pbVar9 = pbVar9 + 1;
                  } while (bVar1 != 0);
                  DAT_022af6ec = (int *)*DAT_022af6e4;
                  if (DAT_022af6ec != DAT_022af6e4) {
                    do {
                      if (DAT_022af6ec[4] != 0) {
                        pbVar9 = abStack_40;
                        pbVar15 = (byte *)(DAT_022af6ec[4] + 0x1d);
                        do {
                          bVar1 = *pbVar15;
                          bVar16 = bVar1 < *pbVar9;
                          if (bVar1 != *pbVar9) {
LAB_00453a44:
                            iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
                            goto LAB_00453a49;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar15[1];
                          bVar16 = bVar1 < pbVar9[1];
                          if (bVar1 != pbVar9[1]) goto LAB_00453a44;
                          pbVar15 = pbVar15 + 2;
                          pbVar9 = pbVar9 + 2;
                        } while (bVar1 != 0);
                        iVar10 = 0;
LAB_00453a49:
                        if (iVar10 == 0) {
                          *(undefined4 *)(iVar3 + 0x424) = 1;
                          break;
                        }
                      }
                      FUN_0049ed20();
                    } while (DAT_022af6ec != DAT_022af6e4);
                  }
                }
                else {
                  pbVar15 = abStack_40;
                  pbVar9 = (byte *)(iVar3 + 0x121);
                  do {
                    bVar1 = *pbVar9;
                    bVar16 = bVar1 < *pbVar15;
                    if (bVar1 != *pbVar15) {
LAB_00453970:
                      iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
                      goto LAB_00453975;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar16 = bVar1 < pbVar15[1];
                    if (bVar1 != pbVar15[1]) goto LAB_00453970;
                    pbVar9 = pbVar9 + 2;
                    pbVar15 = pbVar15 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_00453975:
                  if (iVar10 != 0) {
                    if (piVar8 != (int *)0x0) {
                      piVar14 = (int *)*piVar8;
                      if (piVar14 != (int *)0x0) {
                        (**(code **)(*piVar14 + 8))(piVar14);
                        *piVar8 = 0;
                      }
                    /* WARNING: Subroutine does not return */
                      FUN_006307cd(piVar8);
                    }
                    goto LAB_004539a0;
                  }
                }
                uVar11 = uVar18;
                if (iVar5 != -0x100) {
                  if ((DAT_0090e2f4 == *(int *)(iVar3 + 0x34)) &&
                     ((DAT_022aa7f8 != 0 || (DAT_022aa7fc != 0)))) {
                    if ((DAT_022aa7f4 == DAT_0090e2f4) || (DAT_022aa730 == 0)) {
LAB_00453b0b:
                      uVar12 = FUN_00631be0(uVar18);
                      uVar13 = FUN_00631be0(uVar12);
                    }
                    else {
LAB_00453aba:
                      uVar12 = FUN_00631be0(uVar18);
                      uVar13 = FUN_00631be0(uVar12);
                    }
                    FUN_0057b680(uVar13,uVar12,uVar18);
                    uVar18 = uVar11;
                  }
                  else if (*(char *)(iVar3 + 0x308) != '\0') {
                    if (*(char *)(iVar3 + 0x308) != '\x01') goto LAB_00453b0b;
                    goto LAB_00453aba;
                  }
                  iVar10 = *(int *)(iVar3 + 0x334);
                  uVar11 = uVar18;
                  if (iVar10 != 0) {
                    uVar12 = FUN_00631be0(uVar18,iVar10);
                    uVar13 = FUN_00631be0(uVar12);
                    FUN_0044ebe0(uVar13,uVar12,uVar18,iVar10);
                  }
                }
                if (((DAT_00913464 == 2) && (*(int *)(puVar19 + 0x140038) != 0)) &&
                   (*(int *)(*(int *)(puVar19 + 0x140038) + 0x188) == *(int *)(iVar3 + 0x34))) {
                  uVar18 = uVar11;
                  if (*(char *)(iVar3 + 0x308) == '\0') {
                    uVar12 = FUN_00631be0(uVar11);
                  }
                  else {
                    uVar12 = FUN_00631be0(uVar11);
                  }
                  uVar13 = FUN_00631be0(uVar12);
                  FUN_0057b680(uVar13,uVar12,uVar11);
                  uVar11 = uVar18;
                  uVar12 = FUN_00631be0(uVar18);
                  uVar13 = FUN_00631be0(uVar12);
                  FUN_0057b680(uVar13,uVar12,uVar18);
                }
                iVar10 = *(int *)(iVar3 + 0x314);
                uVar18 = uVar11;
                if (iVar10 != 0) {
                  uVar12 = FUN_00631be0(uVar11,iVar5);
                  uVar13 = FUN_00631be0(uVar12);
                  FUN_0057ca20(iVar10,uVar13,uVar12,uVar11,iVar5);
                }
                if (*(byte *)(iVar3 + 0x2ec) < 4) {
                  if (*(int *)(iVar3 + 0x30c) != 0) {
                    if (*(int *)(iVar3 + 0x31c) == 0) {
                      uVar11 = FUN_0057c280(*(int *)(iVar3 + 0x30c));
                      *(undefined4 *)(iVar3 + 0x31c) = uVar11;
                      FUN_0057cc70(*(undefined4 *)(iVar3 + 0x30c));
                      uVar11 = FUN_00631be0();
                      *(undefined4 *)(iVar3 + 800) = uVar11;
                    }
                    iVar5 = *(int *)(iVar3 + 0x31c);
                    if (*(int *)(iVar3 + 0x424) == 1) {
                      if (iVar5 != 0) {
                        uVar11 = 0xffe0affa;
LAB_00453d9b:
                        uVar12 = uVar18;
                        uVar13 = FUN_00631be0(uVar18,uVar11);
                        iVar10 = FUN_00631be0(uVar13);
                        FUN_0057ca20(iVar5,iVar10 - *(int *)(iVar3 + 800),uVar13,uVar18,uVar11);
                        uVar18 = uVar12;
                      }
                    }
                    else if (iVar5 != 0) {
                      uVar11 = 0xffe4e4e4;
                      goto LAB_00453d9b;
                    }
                  }
                  if (*(int *)(iVar3 + 0x338) == 0) {
                    piVar14 = *(int **)(iVar3 + 0x324);
                    if (piVar14 != (int *)0x0) {
                      piVar8 = (int *)*piVar14;
                      if (piVar8 != (int *)0x0) {
                        (**(code **)(*piVar8 + 8))(piVar8);
                        *piVar14 = 0;
                      }
                    /* WARNING: Subroutine does not return */
                      FUN_006307cd(piVar14);
                    }
                  }
                  else {
                    if (*(int *)(iVar3 + 0x324) == 0) {
                      uVar11 = FUN_0041fcf0(iVar3 + 0x33c,*(undefined *)(iVar3 + 0x2b7),0);
                      *(undefined4 *)(iVar3 + 0x324) = uVar11;
                    }
                    if (*(int *)(iVar3 + 0x324) != 0) {
                      fStack_114 = (float)piVar14 - (float)_DAT_00748450;
                      local_110 = uVar18;
                      FUN_0041fd80(puVar17,fStack_114,uVar18,0x9a1d1f24,0xffccff66,
                                   *(int *)(iVar3 + 0x324));
                    }
                  }
                }
              }
            }
            (**(code **)(*DAT_022b69a8 + 0xb0))(DAT_022b69a8,3,&local_100);
            (**(code **)(*DAT_022b69a8 + 0xb0))(DAT_022b69a8,2,auStack_cc);
            (**(code **)(*DAT_022b69a8 + 0xb0))(DAT_022b69a8,0x100,auStack_98);
            param_1 = local_104;
          }
          FUN_00412780();
        }
      }
LAB_00453ed5:
      iVar3 = *(int *)(param_1 + 0x13d9ec);
      if (*(char *)(iVar3 + 0x15) == '\0') {
        piVar14 = *(int **)(iVar3 + 8);
        if (*(char *)((int)piVar14 + 0x15) == '\0') {
          cVar2 = *(char *)(*piVar14 + 0x15);
          piVar8 = (int *)*piVar14;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar8 + 0x15);
            piVar14 = piVar8;
            piVar8 = (int *)*piVar8;
          }
        }
        else {
          piVar14 = *(int **)(iVar3 + 4);
          cVar2 = *(char *)((int)piVar14 + 0x15);
          while ((cVar2 == '\0' && (*(int *)(param_1 + 0x13d9ec) == piVar14[2]))) {
            *(int **)(param_1 + 0x13d9ec) = piVar14;
            piVar14 = (int *)piVar14[1];
            cVar2 = *(char *)((int)piVar14 + 0x15);
          }
        }
        *(int **)(param_1 + 0x13d9ec) = piVar14;
      }
    } while (*(int *)(param_1 + 0x13d9ec) != *(int *)(param_1 + 0x13d9e4));
  }
  ___security_check_cookie_4();
  return;
}

