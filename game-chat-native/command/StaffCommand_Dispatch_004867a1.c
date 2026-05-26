/*
 * Game.exe — StaffCommand_Dispatch
 * VA solicitado: 0x004867A1
 * Entry Ghidra:  00486660
 * Ghidra name:   FUN_00486660
 * NOTA: VA dentro da função (landmark/hook), não é entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: command
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __fastcall FUN_00486660(int param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  char *pcVar9;
  int iVar10;
  byte *_Str1;
  byte *pbVar11;
  DWORD DVar12;
  char *pcVar13;
  bool bVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int local_22c;
  undefined4 local_228;
  char local_224 [24];
  char local_20c [260];
  char local_108 [127];
  char local_89;
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_22c;
  sVar4 = FUN_00564010();
  if ((sVar4 != 0x12) && (cVar3 = FUN_00565070(), cVar3 != '\0')) goto LAB_0048754b;
  iVar10 = DAT_007c0e58;
  _Str1 = (byte *)(param_1 + 0x90);
  pbVar5 = _Str1;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != 0);
  iVar6 = (int)pbVar5 - (param_1 + 0x91);
  if (iVar6 == 0) {
    DAT_007c13c0 = iVar6;
    DAT_0090c988 = iVar6;
    FUN_00564b60(0);
    goto LAB_0048754b;
  }
  local_22c = 0;
  if (((DAT_007c0e58 != 0) && (DAT_007ab0d4 != 1)) && (DAT_0090d1d8 == 0)) {
    _memset(local_20c,0,0x104);
    local_228 = CONCAT31(local_228._1_3_,iVar10 == 1);
    FUN_00422310(_Str1,local_20c,&local_22c,0,local_228);
    if (local_22c == 1) {
      FUN_00420c10(&DAT_007c1d38,local_20c);
      FUN_00423150(0x22,0xfa,0x34);
      goto LAB_0048754b;
    }
    if (local_22c == 2) {
      if (iVar10 == 1) {
        FUN_00420c10(_Str1,local_20c);
      }
    }
    else if (local_22c != 0) goto LAB_0048754b;
  }
  if (DAT_00904aa0 == 0) goto LAB_0048754b;
  pcVar7 = (char *)FUN_00420db0(0x13d4);
  pcVar9 = pcVar7 + 1;
  do {
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  sVar8 = (int)pcVar7 - (int)pcVar9;
  pcVar9 = (char *)FUN_00420db0(0x13d4);
  iVar10 = _strncmp((char *)_Str1,pcVar9,sVar8);
  if ((iVar10 == 0) || (iVar10 = _strncmp((char *)_Str1,"/town",5), iVar10 == 0)) {
    iVar10 = FUN_004e71a0();
    if ((iVar10 == 0) && ((DAT_00904aa0 != 0 && (*(int *)(DAT_00904aa0 + 0x100) == 0)))) {
      FUN_005ef780();
      uVar17 = 5;
      uVar16 = 0xfb;
      goto LAB_00487528;
    }
  }
  else {
    pcVar7 = (char *)FUN_00420db0(0x13d5);
    pcVar9 = pcVar7 + 1;
    do {
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    sVar8 = (int)pcVar7 - (int)pcVar9;
    pcVar9 = (char *)FUN_00420db0(0x13d5);
    iVar10 = __strnicmp((char *)_Str1,pcVar9,sVar8);
    if (iVar10 == 0) {
      do {
        bVar1 = *_Str1;
        _Str1 = _Str1 + 1;
      } while (bVar1 != 0);
      pcVar7 = (char *)FUN_00420db0(0x13d5);
      pcVar9 = pcVar7 + 1;
      do {
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      FUN_005ed3c0(_Str1 + (-((int)pcVar7 - (int)pcVar9) - (param_1 + 0x91)),
                   ((int)pcVar7 - (int)pcVar9) + 0x91 + param_1);
      FUN_00423150(0x16,0xfc,5);
    }
    else {
      pbVar11 = (byte *)FUN_00420db0(0x13fa);
      pbVar5 = _Str1;
      do {
        bVar1 = *pbVar5;
        bVar14 = bVar1 < *pbVar11;
        if (bVar1 != *pbVar11) {
LAB_004868b1:
          iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_004868b6;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar14 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_004868b1;
        pbVar5 = pbVar5 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar1 != 0);
      iVar10 = 0;
LAB_004868b6:
      if (iVar10 == 0) {
        iVar10 = FUN_004e71a0();
        if (iVar10 == 0) {
          FUN_005ebaa0(0x74);
        }
      }
      else {
        pbVar11 = (byte *)FUN_00420db0(0x13fb);
        pbVar5 = _Str1;
        do {
          bVar1 = *pbVar5;
          bVar14 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_0048690e:
            iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
            goto LAB_00486913;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar14 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_0048690e;
          pbVar5 = pbVar5 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        iVar10 = 0;
LAB_00486913:
        if (iVar10 == 0) {
          iVar10 = FUN_004e71a0();
          if (iVar10 == 0) {
            FUN_005ebaa0(0x75);
          }
        }
        else {
          pbVar11 = (byte *)FUN_00420db0(0x13fc);
          pbVar5 = _Str1;
          do {
            bVar1 = *pbVar5;
            bVar14 = bVar1 < *pbVar11;
            if (bVar1 != *pbVar11) {
LAB_00486965:
              iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
              goto LAB_0048696a;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar14 = bVar1 < pbVar11[1];
            if (bVar1 != pbVar11[1]) goto LAB_00486965;
            pbVar5 = pbVar5 + 2;
            pbVar11 = pbVar11 + 2;
          } while (bVar1 != 0);
          iVar10 = 0;
LAB_0048696a:
          if (iVar10 == 0) {
            iVar10 = FUN_004e71a0();
            if (iVar10 == 0) {
              FUN_005ebaa0(0x76);
            }
          }
          else {
            pbVar11 = (byte *)FUN_00420db0(0x13fd);
            pbVar5 = _Str1;
            do {
              bVar1 = *pbVar5;
              bVar14 = bVar1 < *pbVar11;
              if (bVar1 != *pbVar11) {
LAB_004869be:
                iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                goto LAB_004869c3;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar5[1];
              bVar14 = bVar1 < pbVar11[1];
              if (bVar1 != pbVar11[1]) goto LAB_004869be;
              pbVar5 = pbVar5 + 2;
              pbVar11 = pbVar11 + 2;
            } while (bVar1 != 0);
            iVar10 = 0;
LAB_004869c3:
            if (iVar10 == 0) {
              iVar10 = FUN_004e71a0();
              if (iVar10 == 0) {
                FUN_005ebaa0(0x77);
              }
            }
            else {
              pbVar11 = (byte *)FUN_00420db0(0x13fe);
              pbVar5 = _Str1;
              do {
                bVar1 = *pbVar5;
                bVar14 = bVar1 < *pbVar11;
                if (bVar1 != *pbVar11) {
LAB_00486a15:
                  iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                  goto LAB_00486a1a;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar5[1];
                bVar14 = bVar1 < pbVar11[1];
                if (bVar1 != pbVar11[1]) goto LAB_00486a15;
                pbVar5 = pbVar5 + 2;
                pbVar11 = pbVar11 + 2;
              } while (bVar1 != 0);
              iVar10 = 0;
LAB_00486a1a:
              if (iVar10 == 0) {
                iVar10 = FUN_004e71a0();
                if (iVar10 == 0) {
                  FUN_005ebaa0(0x78);
                }
              }
              else {
                pbVar11 = (byte *)FUN_00420db0(0x13ff);
                pbVar5 = _Str1;
                do {
                  bVar1 = *pbVar5;
                  bVar14 = bVar1 < *pbVar11;
                  if (bVar1 != *pbVar11) {
LAB_00486a6e:
                    iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                    goto LAB_00486a73;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar5[1];
                  bVar14 = bVar1 < pbVar11[1];
                  if (bVar1 != pbVar11[1]) goto LAB_00486a6e;
                  pbVar5 = pbVar5 + 2;
                  pbVar11 = pbVar11 + 2;
                } while (bVar1 != 0);
                iVar10 = 0;
LAB_00486a73:
                if (iVar10 == 0) {
                  iVar10 = FUN_004e71a0();
                  if (iVar10 == 0) {
                    FUN_005ebaa0(0x79);
                  }
                }
                else {
                  pbVar11 = (byte *)FUN_00420db0(0x1400);
                  pbVar5 = _Str1;
                  do {
                    bVar1 = *pbVar5;
                    bVar14 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_00486ac5:
                      iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                      goto LAB_00486aca;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar5[1];
                    bVar14 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_00486ac5;
                    pbVar5 = pbVar5 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_00486aca:
                  if (iVar10 == 0) {
                    iVar10 = FUN_004e71a0();
                    if (iVar10 == 0) {
                      FUN_005ebaa0(0x7a);
                    }
                  }
                  else {
                    pbVar11 = (byte *)FUN_00420db0(0x1401);
                    pbVar5 = _Str1;
                    do {
                      bVar1 = *pbVar5;
                      bVar14 = bVar1 < *pbVar11;
                      if (bVar1 != *pbVar11) {
LAB_00486b1e:
                        iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                        goto LAB_00486b23;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar5[1];
                      bVar14 = bVar1 < pbVar11[1];
                      if (bVar1 != pbVar11[1]) goto LAB_00486b1e;
                      pbVar5 = pbVar5 + 2;
                      pbVar11 = pbVar11 + 2;
                    } while (bVar1 != 0);
                    iVar10 = 0;
LAB_00486b23:
                    if (iVar10 == 0) {
                      iVar10 = FUN_004e71a0();
                      if (iVar10 == 0) {
                        FUN_005ebaa0(0x7b);
                      }
                    }
                    else {
                      pbVar11 = (byte *)FUN_00420db0(0x1402);
                      pbVar5 = _Str1;
                      do {
                        bVar1 = *pbVar5;
                        bVar14 = bVar1 < *pbVar11;
                        if (bVar1 != *pbVar11) {
LAB_00486b75:
                          iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                          goto LAB_00486b7a;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar5[1];
                        bVar14 = bVar1 < pbVar11[1];
                        if (bVar1 != pbVar11[1]) goto LAB_00486b75;
                        pbVar5 = pbVar5 + 2;
                        pbVar11 = pbVar11 + 2;
                      } while (bVar1 != 0);
                      iVar10 = 0;
LAB_00486b7a:
                      if (iVar10 == 0) {
                        iVar10 = FUN_004e71a0();
                        if (iVar10 == 0) {
                          FUN_005ebaa0(0x7c);
                        }
                      }
                      else {
                        pbVar11 = (byte *)FUN_00420db0(0x1403);
                        pbVar5 = _Str1;
                        do {
                          bVar1 = *pbVar5;
                          bVar14 = bVar1 < *pbVar11;
                          if (bVar1 != *pbVar11) {
LAB_00486bce:
                            iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                            goto LAB_00486bd3;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar5[1];
                          bVar14 = bVar1 < pbVar11[1];
                          if (bVar1 != pbVar11[1]) goto LAB_00486bce;
                          pbVar5 = pbVar5 + 2;
                          pbVar11 = pbVar11 + 2;
                        } while (bVar1 != 0);
                        iVar10 = 0;
LAB_00486bd3:
                        if (iVar10 == 0) {
                          iVar10 = FUN_004e71a0();
                          if (iVar10 == 0) {
                            FUN_005ebaa0(0x7d);
                          }
                        }
                        else {
                          pcVar7 = (char *)FUN_00420db0(0x13d6);
                          pcVar9 = pcVar7 + 1;
                          do {
                            cVar3 = *pcVar7;
                            pcVar7 = pcVar7 + 1;
                          } while (cVar3 != '\0');
                          sVar8 = (int)pcVar7 - (int)pcVar9;
                          pcVar9 = (char *)FUN_00420db0(0x13d6);
                          iVar10 = _strncmp((char *)_Str1,pcVar9,sVar8);
                          if (iVar10 == 0) {
                            _memset(local_20c,0,0x104);
                            pcVar7 = (char *)FUN_00420db0(0x13d6);
                            pcVar9 = pcVar7 + 1;
                            do {
                              cVar3 = *pcVar7;
                              pcVar7 = pcVar7 + 1;
                            } while (cVar3 != '\0');
                            pcVar13 = pcVar7 + param_1 + (0x91 - (int)pcVar9);
                            if (pcVar7[param_1 + (0x91 - (int)pcVar9)] != '\0') {
                              cVar3 = pcVar7[(param_1 + 0x91) - (int)pcVar9];
                              pcVar9 = local_20c;
                              do {
                                pcVar13 = pcVar13 + 1;
                                *pcVar9 = cVar3;
                                cVar3 = *pcVar13;
                                pcVar9 = pcVar9 + 1;
                              } while (cVar3 != '\0');
                            }
                            pcVar9 = local_20c;
                            if (*(int *)(param_1 + 0x75c8) < 1) {
                              cVar3 = (char)local_20c;
                              do {
                                cVar2 = *pcVar9;
                                pcVar9 = pcVar9 + 1;
                              } while (cVar2 != '\0');
                              pcVar7 = local_20c;
                            }
                            else {
                              do {
                                cVar3 = *pcVar9;
                                pcVar9 = pcVar9 + 1;
                              } while (cVar3 != '\0');
                              _sprintf(local_224,"<<%03dc%02d",(int)pcVar9 - (int)(local_20c + 1),
                                       *(int *)(param_1 + 0x75c8));
                              _sprintf(local_108,"%s%s",local_224,local_20c);
                              pcVar9 = local_20c;
                              do {
                                cVar3 = *pcVar9;
                                pcVar9 = pcVar9 + 1;
                              } while (cVar3 != '\0');
                              if (0x7f < (uint)((int)pcVar9 - (int)(local_20c + 1))) {
                                local_89 = cVar3;
                              }
                              pcVar9 = local_108;
                              cVar3 = (char)local_108;
                              do {
                                cVar2 = *pcVar9;
                                pcVar9 = pcVar9 + 1;
                              } while (cVar2 != '\0');
                              pcVar7 = local_108;
                            }
                            FUN_005ed060(0,4,((char)pcVar9 - (cVar3 + '\x01')) + '\x01',pcVar7);
                          }
                          else {
                            pcVar7 = (char *)FUN_00420db0(0x13d7);
                            pcVar9 = pcVar7 + 1;
                            do {
                              cVar3 = *pcVar7;
                              pcVar7 = pcVar7 + 1;
                            } while (cVar3 != '\0');
                            sVar8 = (int)pcVar7 - (int)pcVar9;
                            pcVar9 = (char *)FUN_00420db0(0x13d7);
                            iVar10 = _strncmp((char *)_Str1,pcVar9,sVar8);
                            if (((iVar10 == 0) ||
                                (iVar10 = _strncmp((char *)_Str1,&DAT_0074e084,5), iVar10 == 0)) ||
                               (iVar10 = _strncmp((char *)_Str1,"/party",7), iVar10 == 0)) {
                              _memset(local_20c,0,0x104);
                              FID_conflict__sscanf((char *)_Str1,"%s %s",local_20c,local_20c);
                              if (DAT_022aa7fc == 0) {
                                FUN_005ec9e0(local_20c);
LAB_004874e0:
                                FUN_00420c10(&DAT_007c2338,local_20c);
                                FUN_00423150(0x16,0xcb,7);
                              }
                              else {
                                if (DAT_022aa730 == 2) {
                                  uVar17 = 7;
                                  uVar16 = 0x198c;
                                }
                                else {
                                  if ((DAT_022aa728 != 0x1e) ||
                                     ((DAT_022aa730 != 0 && (DAT_022aa730 != 1)))) {
                                    FUN_005eb750(local_20c);
                                    goto LAB_004874e0;
                                  }
                                  uVar17 = 7;
                                  uVar16 = 0x198b;
                                }
LAB_00487528:
                                uVar15 = 0x16;
LAB_0048752a:
                                FUN_00423150(uVar15,uVar16,uVar17);
                              }
                            }
                            else {
                              pcVar7 = (char *)FUN_00420db0(0x198f);
                              pcVar9 = pcVar7 + 1;
                              do {
                                cVar3 = *pcVar7;
                                pcVar7 = pcVar7 + 1;
                              } while (cVar3 != '\0');
                              sVar8 = (int)pcVar7 - (int)pcVar9;
                              pcVar9 = (char *)FUN_00420db0(0x198f);
                              iVar10 = _strncmp((char *)_Str1,pcVar9,sVar8);
                              if (((iVar10 == 0) ||
                                  (iVar10 = _strncmp((char *)_Str1,&DAT_0074e074,5), iVar10 == 0))
                                 || (iVar10 = _strncmp((char *)_Str1,"/join",5), iVar10 == 0)) {
                                if ((DAT_022aa7f8 != 0) || (DAT_022aa7fc != 0)) {
                                  uVar17 = 7;
                                  uVar16 = 0x1989;
                                  goto LAB_00487528;
                                }
                                _memset(local_108,0,0x104);
                                FID_conflict__sscanf((char *)_Str1,"%s %s",local_108,local_224);
                                FUN_005eb7e0(local_224);
                              }
                              else {
                                pcVar7 = (char *)FUN_00420db0(0x13d8);
                                pcVar9 = pcVar7 + 1;
                                do {
                                  cVar3 = *pcVar7;
                                  pcVar7 = pcVar7 + 1;
                                } while (cVar3 != '\0');
                                sVar8 = (int)pcVar7 - (int)pcVar9;
                                pcVar9 = (char *)FUN_00420db0(0x13d8);
                                iVar10 = _strncmp((char *)_Str1,pcVar9,sVar8);
                                if (iVar10 == 0) {
                                  if (((DAT_00904aa0 != 0) && (DAT_00913464 == 2)) &&
                                     (*(int *)(DAT_00904aa0 + 0x188) != -1)) {
                                    FUN_005efa60(*(int *)(DAT_00904aa0 + 0x188));
                                  }
                                }
                                else {
                                  pbVar11 = (byte *)FUN_00420db0(0x14d7);
                                  pbVar5 = _Str1;
                                  do {
                                    bVar1 = *pbVar5;
                                    bVar14 = bVar1 < *pbVar11;
                                    if (bVar1 != *pbVar11) {
LAB_00486e9e:
                                      iVar10 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                                      goto LAB_00486ea3;
                                    }
                                    if (bVar1 == 0) break;
                                    bVar1 = pbVar5[1];
                                    bVar14 = bVar1 < pbVar11[1];
                                    if (bVar1 != pbVar11[1]) goto LAB_00486e9e;
                                    pbVar5 = pbVar5 + 2;
                                    pbVar11 = pbVar11 + 2;
                                  } while (bVar1 != 0);
                                  iVar10 = 0;
LAB_00486ea3:
                                  if (iVar10 == 0) {
                                    if (DAT_007c3e68 == 2) {
                                      FUN_005f0890();
                                    }
                                  }
                                  else {
                                    iVar10 = _strncmp((char *)_Str1,"/time",5);
                                    if ((iVar10 == 0) && (cVar3 = FUN_0047a970(5), cVar3 != '\0')) {
                                      _memset(local_108,0,0x104);
                                      FID_conflict__sscanf
                                                ((char *)_Str1,"%s %d",local_108,&DAT_022aacf8);
                                    }
                                    else {
                                      iVar10 = _strncmp((char *)_Str1,"/wire",5);
                                      if ((iVar10 == 0) && (cVar3 = FUN_0047a970(5), cVar3 != '\0'))
                                      {
                                        (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,8,2);
                                      }
                                      else {
                                        iVar10 = _strncmp((char *)_Str1,"/point",6);
                                        if ((iVar10 == 0) &&
                                           (cVar3 = FUN_0047a970(5), cVar3 != '\0')) {
                                          (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,8,1);
                                        }
                                        else {
                                          iVar10 = _strncmp((char *)_Str1,"/basic",6);
                                          if ((iVar10 == 0) &&
                                             (cVar3 = FUN_0047a970(5), cVar3 != '\0')) {
                                            (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,8,3);
                                          }
                                          else {
                                            pcVar7 = (char *)FUN_00420db0(0x13d9);
                                            pcVar9 = pcVar7 + 1;
                                            do {
                                              cVar3 = *pcVar7;
                                              pcVar7 = pcVar7 + 1;
                                            } while (cVar3 != '\0');
                                            sVar8 = (int)pcVar7 - (int)pcVar9;
                                            pcVar9 = (char *)FUN_00420db0(0x13d9);
                                            iVar10 = _strncmp((char *)_Str1,pcVar9,sVar8);
                                            if (iVar10 == 0) {
                                              FUN_005ec8f0();
                                            }
                                            else {
                                              iVar10 = _strncmp((char *)_Str1,"@ ",2);
                                              if (iVar10 == 0) {
                                                FUN_0047c1e0(2);
                                                FUN_0047a5f0(param_1 + 0x92);
                                              }
                                              else {
                                                iVar10 = _strncmp((char *)_Str1,"# ",2);
                                                if (iVar10 == 0) {
                                                  uVar16 = 3;
LAB_0048703f:
                                                  FUN_0047c1e0(uVar16);
                                                  FUN_0047a5f0(param_1 + 0x92);
                                                }
                                                else {
                                                  iVar10 = _strncmp((char *)_Str1,"~ ",2);
                                                  if (iVar10 == 0) {
                                                    uVar16 = 5;
LAB_004870fd:
                                                    FUN_0047c1e0(uVar16);
                                                    FUN_0047a5f0(param_1 + 0x92);
                                                  }
                                                  else {
                                                    iVar10 = _strncmp((char *)_Str1,"$ ",2);
                                                    if (iVar10 == 0) {
                                                      switch(DAT_007ab0d4) {
                                                      case 2:
                                                        DVar12 = GetTickCount();
                                                        if (15000 < DVar12 - *(int *)(param_1 +
                                                                                     0x75bc)) {
                                                          DVar12 = GetTickCount();
                                                          *(DWORD *)(param_1 + 0x75bc) = DVar12;
                                                          uVar16 = 4;
                                                          goto LAB_0048703f;
                                                        }
                                                        break;
                                                      case 3:
                                                      case 6:
                                                      case 7:
                                                      case 8:
                                                      case 0xb:
                                                      case 0xc:
                                                      case 0xd:
                                                      case 0xe:
                                                      case 0xf:
                                                      case 0x10:
                                                        DVar12 = GetTickCount();
                                                        if ((5000 < DVar12 - *(int *)(param_1 +
                                                                                     0x75bc)) &&
                                                           (9 < DAT_0090d1e4)) {
                                                          DVar12 = GetTickCount();
                                                          *(DWORD *)(param_1 + 0x75bc) = DVar12;
                                                          FUN_0047c1e0(4);
                                                          FUN_0047a5f0(param_1 + 0x92);
                                                        }
                                                        break;
                                                      default:
switchD_0048709e_caseD_4:
                                                        uVar16 = 4;
                                                        goto LAB_004870fd;
                                                      case 5:
                                                      case 9:
                                                        DVar12 = GetTickCount();
                                                        if ((5000 < DVar12 - *(int *)(param_1 +
                                                                                     0x75bc)) &&
                                                           (0xe < DAT_0090d1e4)) {
                                                          DVar12 = GetTickCount();
                                                          *(DWORD *)(param_1 + 0x75bc) = DVar12;
                                                          goto switchD_0048709e_caseD_4;
                                                        }
                                                        break;
                                                      case 10:
                                                        DVar12 = GetTickCount();
                                                        if ((7000 < DVar12 - *(int *)(param_1 +
                                                                                     0x75bc)) &&
                                                           (9 < DAT_0090d1e4)) {
                                                          DVar12 = GetTickCount();
                                                          *(DWORD *)(param_1 + 0x75bc) = DVar12;
                                                          FUN_0047c1e0(4);
                                                          FUN_0047a5f0(param_1 + 0x92);
                                                        }
                                                      }
                                                    }
                                                    else {
                                                      iVar10 = _strncmp((char *)_Str1,"! ",2);
                                                      if (iVar10 == 0) {
                                                        _memset(local_20c,0,0x104);
                                                        _memset(local_108,0,0x104);
                                                        FID_conflict__sscanf
                                                                  ((char *)(param_1 + 0x92),"%s",
                                                                   local_20c);
                                                        pcVar9 = local_20c;
                                                        do {
                                                          cVar3 = *pcVar9;
                                                          pcVar9 = pcVar9 + 1;
                                                        } while (cVar3 != '\0');
                                                        if (pcVar9 + param_1 + (0x92 - (int)(
                                                  local_20c + 1)) != (char *)0x0) {
                                                    pcVar9 = local_20c;
                                                    do {
                                                      cVar3 = *pcVar9;
                                                      pcVar9 = pcVar9 + 1;
                                                    } while (cVar3 != '\0');
                                                    if (pcVar9 + param_1 + (0x93 - (int)(local_20c +
                                                                                        1)) !=
                                                        (char *)0x0) {
                                                      pcVar9 = local_20c;
                                                      do {
                                                        cVar3 = *pcVar9;
                                                        pcVar9 = pcVar9 + 1;
                                                      } while (cVar3 != '\0');
                                                      pcVar9 = pcVar9 + param_1 + (0x93 - (int)(
                                                  local_20c + 1));
                                                  iVar10 = -(int)pcVar9;
                                                  do {
                                                    cVar3 = *pcVar9;
                                                    pcVar9[(int)(local_108 + iVar10)] = cVar3;
                                                    pcVar9 = pcVar9 + 1;
                                                  } while (cVar3 != '\0');
                                                  pcVar9 = (char *)(param_1 + 0x198);
                                                  _memset(pcVar9,0,0x104);
                                                  pcVar7 = local_20c;
                                                  iVar10 = (int)pcVar9 - (int)pcVar7;
                                                  do {
                                                    cVar3 = *pcVar7;
                                                    pcVar7[iVar10] = cVar3;
                                                    pcVar7 = pcVar7 + 1;
                                                  } while (cVar3 != '\0');
                                                  iVar10 = (param_1 + 0x29c) - (int)pcVar9;
                                                  do {
                                                    cVar3 = *pcVar9;
                                                    pcVar9[iVar10] = cVar3;
                                                    pcVar9 = pcVar9 + 1;
                                                  } while (cVar3 != '\0');
                                                  FUN_0047f970(0);
                                                  FUN_0047c1e0(1);
                                                  FUN_0047a5f0(local_108);
                                                  }
                                                  }
                                                  }
                                                  else if (*_Str1 == 0x2f) {
                                                    cVar3 = FUN_0047bea0(_Str1);
                                                    if (((cVar3 == '\0') && (DAT_0090d1d8 != 0)) &&
                                                       (cVar3 = FUN_0047ffd0(_Str1), cVar3 == '\0'))
                                                    {
                                                      pbVar11 = &DAT_0074e044;
                                                      pbVar5 = _Str1;
                                                      do {
                                                        bVar1 = *pbVar5;
                                                        bVar14 = bVar1 < *pbVar11;
                                                        if (bVar1 != *pbVar11) {
LAB_0048732e:
                                                          iVar10 = (1 - (uint)bVar14) -
                                                                   (uint)(bVar14 != 0);
                                                          goto LAB_00487333;
                                                        }
                                                        if (bVar1 == 0) break;
                                                        bVar1 = pbVar5[1];
                                                        bVar14 = bVar1 < pbVar11[1];
                                                        if (bVar1 != pbVar11[1]) goto LAB_0048732e;
                                                        pbVar5 = pbVar5 + 2;
                                                        pbVar11 = pbVar11 + 2;
                                                      } while (bVar1 != 0);
                                                      iVar10 = 0;
LAB_00487333:
                                                      if (iVar10 == 0) {
                                                        FUN_005ed430();
                                                      }
                                                      else {
                                                        pcVar9 = "/UQCOUNT";
                                                        pbVar5 = _Str1;
                                                        do {
                                                          bVar1 = *pbVar5;
                                                          bVar14 = bVar1 < (byte)*pcVar9;
                                                          if (bVar1 != *pcVar9) {
LAB_00487366:
                                                            iVar10 = (1 - (uint)bVar14) -
                                                                     (uint)(bVar14 != 0);
                                                            goto LAB_0048736b;
                                                          }
                                                          if (bVar1 == 0) break;
                                                          bVar1 = pbVar5[1];
                                                          bVar14 = bVar1 < ((byte *)pcVar9)[1];
                                                          if (bVar1 != ((byte *)pcVar9)[1])
                                                          goto LAB_00487366;
                                                          pbVar5 = pbVar5 + 2;
                                                          pcVar9 = (char *)((byte *)pcVar9 + 2);
                                                        } while (bVar1 != 0);
                                                        iVar10 = 0;
LAB_0048736b:
                                                        if (iVar10 == 0) {
                                                          FUN_005ed5c0();
                                                        }
                                                        else {
                                                          pcVar9 = "/oneshot";
                                                          pbVar5 = _Str1;
                                                          do {
                                                            bVar1 = *pbVar5;
                                                            bVar14 = bVar1 < (byte)*pcVar9;
                                                            if (bVar1 != *pcVar9) {
LAB_0048739e:
                                                              iVar10 = (1 - (uint)bVar14) -
                                                                       (uint)(bVar14 != 0);
                                                              goto LAB_004873a3;
                                                            }
                                                            if (bVar1 == 0) break;
                                                            bVar1 = pbVar5[1];
                                                            bVar14 = bVar1 < ((byte *)pcVar9)[1];
                                                            if (bVar1 != ((byte *)pcVar9)[1])
                                                            goto LAB_0048739e;
                                                            pbVar5 = pbVar5 + 2;
                                                            pcVar9 = (char *)((byte *)pcVar9 + 2);
                                                          } while (bVar1 != 0);
                                                          iVar10 = 0;
LAB_004873a3:
                                                          if (iVar10 != 0) {
                                                            pcVar9 = "/noshot";
                                                            pbVar5 = _Str1;
                                                            do {
                                                              bVar1 = *pbVar5;
                                                              bVar14 = bVar1 < (byte)*pcVar9;
                                                              if (bVar1 != *pcVar9) {
LAB_004873ce:
                                                                iVar10 = (1 - (uint)bVar14) -
                                                                         (uint)(bVar14 != 0);
                                                                goto LAB_004873d3;
                                                              }
                                                              if (bVar1 == 0) break;
                                                              bVar1 = pbVar5[1];
                                                              bVar14 = bVar1 < ((byte *)pcVar9)[1];
                                                              if (bVar1 != ((byte *)pcVar9)[1])
                                                              goto LAB_004873ce;
                                                              pbVar5 = pbVar5 + 2;
                                                              pcVar9 = (char *)((byte *)pcVar9 + 2);
                                                            } while (bVar1 != 0);
                                                            iVar10 = 0;
LAB_004873d3:
                                                            if (iVar10 != 0) {
                                                              uVar17 = 0xc;
                                                              uVar16 = 0xfd;
                                                              uVar15 = 0x1f;
                                                              goto LAB_0048752a;
                                                            }
                                                          }
                                                          FUN_0047c1e0(0);
                                                          FUN_0047a5f0(_Str1);
                                                        }
                                                      }
                                                    }
                                                  }
                                                  else {
                                                    FUN_0047c1e0(0);
                                                    FUN_0047a5f0(_Str1);
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  DAT_0090c988 = 0;
  DAT_007c13c0 = 0;
  FUN_00564b60(0);
LAB_0048754b:
  ___security_check_cookie_4();
  return;
}

