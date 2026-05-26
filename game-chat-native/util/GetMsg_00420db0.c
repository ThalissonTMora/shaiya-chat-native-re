/*
 * Game.exe — GetMsg
 * VA solicitado: 0x00420DB0
 * Entry Ghidra:  00420db0
 * Ghidra name:   FUN_00420db0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: util
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420db0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined auStack_10f8 [4];
  char *local_10f4;
  char *local_10f0;
  char local_10ec [256];
  char local_fec [2047];
  char cStack_7ed;
  char local_7ec [2024];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)auStack_10f8;
  DAT_007c3b40 = DAT_007c3b40 + 1;
  if (4 < DAT_007c3b40) {
    DAT_007c3b40 = 0;
  }
  iVar2 = DAT_007c3b40 * 0x400;
  _memset(&DAT_007c2740 + iVar2,0,0x400);
  piVar3 = (int *)FUN_004163c0(&local_10f4,&param_1);
  iVar5 = *piVar3;
  _DAT_007c3b44 = iVar5;
  if (iVar5 == DAT_007c3b4c) {
    _sprintf(&DAT_007c2740 + iVar2,"GetMsg Error %d",param_1);
  }
  else {
    _memset(local_7ec,0,0x7e8);
    pcVar9 = *(char **)(iVar5 + 0x10);
    cVar1 = *pcVar9;
    pcVar10 = (char *)0x0;
    local_10f0 = pcVar9;
    if (cVar1 != '\0') {
      do {
        if (cVar1 == '<') {
          if (pcVar10 != (char *)0x0) {
            pcVar4 = local_7ec;
            pcVar6 = local_7ec + 1;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            _memcpy(pcVar4 + (int)(local_7ec + -(int)pcVar6),local_10f0,(size_t)pcVar10);
            if (0x3ff < (int)(pcVar4 + ((int)pcVar10 - (int)pcVar6))) {
              pcVar4 = pcVar4 + ((int)pcVar10 - (int)pcVar6);
              pcVar10 = "GetMsg Error %d buf2:%d";
              pcVar9 = &DAT_007c2740 + DAT_007c3b40 * 0x400;
              goto LAB_00421717;
            }
            local_7ec[(int)(pcVar4 + ((int)pcVar10 - (int)pcVar6))] = '\0';
          }
          pcVar10 = pcVar9 + 1;
          pcVar4 = (char *)0x0;
          cVar1 = pcVar9[1];
          pcVar9 = pcVar10;
          while ((cVar1 != '\0' && (cVar1 != '>'))) {
            pcVar6 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            pcVar4 = pcVar4 + 1;
            cVar1 = *pcVar6;
          }
          local_10f4 = pcVar4;
          local_10f0 = pcVar10;
          _memset(local_10ec,0,0x100);
          if (0x13 < (int)pcVar4) {
            pcVar10 = "GetMsg Error %d s:%d";
            pcVar9 = &DAT_007c2740 + DAT_007c3b40 * 0x400;
            goto LAB_00421717;
          }
          _memcpy(local_10ec,pcVar10,(size_t)pcVar4);
          iVar5 = __stricmp(local_10ec,"p");
          if (iVar5 == 0) {
            pcVar10 = &DAT_007c2338;
            do {
              pcVar6 = pcVar10;
              pcVar10 = pcVar6 + 1;
            } while (*pcVar6 != '\0');
            if (pcVar6 + -0x7c2338 < (char *)0x100) {
              pcVar10 = &DAT_007c2338;
              do {
                cVar1 = *pcVar10;
                pcVar10 = pcVar10 + 1;
              } while (cVar1 != '\0');
              if (pcVar10 != &DAT_007c2339) {
                iVar5 = 0;
                do {
                  cVar1 = (&DAT_007c2338)[iVar5];
                  local_fec[iVar5] = cVar1;
                  iVar5 = iVar5 + 1;
                } while (cVar1 != '\0');
                pcVar10 = local_fec;
                pcVar6 = pcVar10;
                do {
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                uVar7 = (int)pcVar6 - (int)pcVar10;
                pcVar6 = &cStack_7ed;
                do {
                  pcVar4 = pcVar6 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (*pcVar4 != '\0');
                goto LAB_004215e9;
              }
            }
          }
          else {
            iVar5 = __stricmp(local_10ec,"t");
            if (iVar5 == 0) {
              pcVar10 = &DAT_007c1b38;
              do {
                pcVar6 = pcVar10;
                pcVar10 = pcVar6 + 1;
              } while (*pcVar6 != '\0');
              if (pcVar6 + -0x7c1b38 < (char *)0x100) {
                pcVar10 = &DAT_007c1b38;
                do {
                  cVar1 = *pcVar10;
                  pcVar10 = pcVar10 + 1;
                } while (cVar1 != '\0');
                if (pcVar10 != &DAT_007c1b39) {
                  iVar5 = 0;
                  do {
                    cVar1 = (&DAT_007c1b38)[iVar5];
                    local_fec[iVar5] = cVar1;
                    iVar5 = iVar5 + 1;
                  } while (cVar1 != '\0');
                  pcVar10 = local_fec;
                  pcVar6 = pcVar10;
                  do {
                    cVar1 = *pcVar6;
                    pcVar6 = pcVar6 + 1;
                  } while (cVar1 != '\0');
                  uVar7 = (int)pcVar6 - (int)pcVar10;
                  pcVar6 = &cStack_7ed;
                  do {
                    pcVar4 = pcVar6 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (*pcVar4 != '\0');
                  goto LAB_004215e9;
                }
              }
            }
            else {
              iVar5 = __stricmp(local_10ec,"s");
              if (iVar5 == 0) {
                pcVar10 = &DAT_007c2138;
                do {
                  pcVar6 = pcVar10;
                  pcVar10 = pcVar6 + 1;
                } while (*pcVar6 != '\0');
                if (pcVar6 + -0x7c2138 < (char *)0x100) {
                  pcVar10 = &DAT_007c2138;
                  do {
                    cVar1 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                  } while (cVar1 != '\0');
                  if (pcVar10 != &DAT_007c2139) {
                    iVar5 = 0;
                    do {
                      cVar1 = (&DAT_007c2138)[iVar5];
                      local_fec[iVar5] = cVar1;
                      iVar5 = iVar5 + 1;
                    } while (cVar1 != '\0');
                    pcVar10 = local_fec;
                    pcVar6 = pcVar10;
                    do {
                      cVar1 = *pcVar6;
                      pcVar6 = pcVar6 + 1;
                    } while (cVar1 != '\0');
                    uVar7 = (int)pcVar6 - (int)pcVar10;
                    pcVar6 = &cStack_7ed;
                    do {
                      pcVar4 = pcVar6 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (*pcVar4 != '\0');
                    goto LAB_004215e9;
                  }
                }
              }
              else {
                iVar5 = __stricmp(local_10ec,"i");
                if (iVar5 == 0) {
                  pcVar10 = &DAT_007c2538;
                  do {
                    pcVar6 = pcVar10;
                    pcVar10 = pcVar6 + 1;
                  } while (*pcVar6 != '\0');
                  if (pcVar6 + -0x7c2538 < (char *)0x100) {
                    pcVar10 = &DAT_007c2538;
                    do {
                      cVar1 = *pcVar10;
                      pcVar10 = pcVar10 + 1;
                    } while (cVar1 != '\0');
                    if (pcVar10 != &DAT_007c2539) {
                      iVar5 = 0;
                      do {
                        cVar1 = (&DAT_007c2538)[iVar5];
                        local_fec[iVar5] = cVar1;
                        iVar5 = iVar5 + 1;
                      } while (cVar1 != '\0');
                      pcVar10 = local_fec;
                      pcVar6 = pcVar10;
                      do {
                        cVar1 = *pcVar6;
                        pcVar6 = pcVar6 + 1;
                      } while (cVar1 != '\0');
                      uVar7 = (int)pcVar6 - (int)pcVar10;
                      pcVar6 = &cStack_7ed;
                      do {
                        pcVar4 = pcVar6 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (*pcVar4 != '\0');
                      goto LAB_004215e9;
                    }
                  }
                }
                else {
                  iVar5 = __stricmp(local_10ec,"r");
                  if (iVar5 == 0) {
                    pcVar10 = &DAT_007c1938;
                    do {
                      pcVar6 = pcVar10;
                      pcVar10 = pcVar6 + 1;
                    } while (*pcVar6 != '\0');
                    if (pcVar6 + -0x7c1938 < (char *)0x100) {
                      pcVar10 = &DAT_007c1938;
                      do {
                        cVar1 = *pcVar10;
                        pcVar10 = pcVar10 + 1;
                      } while (cVar1 != '\0');
                      if (pcVar10 != &DAT_007c1939) {
                        iVar5 = 0;
                        do {
                          cVar1 = (&DAT_007c1938)[iVar5];
                          local_fec[iVar5] = cVar1;
                          iVar5 = iVar5 + 1;
                        } while (cVar1 != '\0');
                        pcVar10 = local_fec;
                        pcVar6 = pcVar10;
                        do {
                          cVar1 = *pcVar6;
                          pcVar6 = pcVar6 + 1;
                        } while (cVar1 != '\0');
                        uVar7 = (int)pcVar6 - (int)pcVar10;
                        pcVar6 = &cStack_7ed;
                        do {
                          pcVar4 = pcVar6 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (*pcVar4 != '\0');
                        goto LAB_004215e9;
                      }
                    }
                  }
                  else {
                    iVar5 = __stricmp(local_10ec,"b");
                    if (iVar5 == 0) {
                      pcVar10 = &DAT_007c1d38;
                      do {
                        pcVar6 = pcVar10;
                        pcVar10 = pcVar6 + 1;
                      } while (*pcVar6 != '\0');
                      if (pcVar6 + -0x7c1d38 < (char *)0x200) {
                        pcVar10 = &DAT_007c1d38;
                        do {
                          cVar1 = *pcVar10;
                          pcVar10 = pcVar10 + 1;
                        } while (cVar1 != '\0');
                        if (pcVar10 != &DAT_007c1d39) {
                          iVar5 = 0;
                          do {
                            cVar1 = (&DAT_007c1d38)[iVar5];
                            local_fec[iVar5] = cVar1;
                            iVar5 = iVar5 + 1;
                          } while (cVar1 != '\0');
                          pcVar10 = local_fec;
                          pcVar6 = pcVar10;
                          do {
                            cVar1 = *pcVar6;
                            pcVar6 = pcVar6 + 1;
                          } while (cVar1 != '\0');
                          uVar7 = (int)pcVar6 - (int)pcVar10;
                          pcVar6 = &cStack_7ed;
                          do {
                            pcVar4 = pcVar6 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (*pcVar4 != '\0');
                          goto LAB_004215e9;
                        }
                      }
                    }
                    else {
                      iVar5 = __stricmp(local_10ec,"v3");
                      if (iVar5 == 0) {
                        _sprintf(local_fec,"%d",DAT_007c2738);
                        pcVar10 = local_fec;
                        pcVar6 = pcVar10;
                        do {
                          cVar1 = *pcVar6;
                          pcVar6 = pcVar6 + 1;
                        } while (cVar1 != '\0');
                        uVar7 = (int)pcVar6 - (int)pcVar10;
                        pcVar6 = &cStack_7ed;
                        do {
                          pcVar4 = pcVar6 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (*pcVar4 != '\0');
                      }
                      else {
                        iVar5 = __stricmp(local_10ec,"v2");
                        if (iVar5 == 0) {
                          _sprintf(local_fec,"%d",DAT_007c1930);
                          pcVar10 = local_fec;
                          pcVar6 = pcVar10;
                          do {
                            cVar1 = *pcVar6;
                            pcVar6 = pcVar6 + 1;
                          } while (cVar1 != '\0');
                          uVar7 = (int)pcVar6 - (int)pcVar10;
                          pcVar6 = &cStack_7ed;
                          do {
                            pcVar4 = pcVar6 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (*pcVar4 != '\0');
                        }
                        else {
                          iVar5 = __stricmp(local_10ec,"v");
                          if (iVar5 == 0) {
                            _sprintf(local_fec,"%d",DAT_007c273c);
                            pcVar10 = local_fec;
                            pcVar6 = pcVar10;
                            do {
                              cVar1 = *pcVar6;
                              pcVar6 = pcVar6 + 1;
                            } while (cVar1 != '\0');
                            uVar7 = (int)pcVar6 - (int)pcVar10;
                            pcVar6 = &cStack_7ed;
                            do {
                              pcVar4 = pcVar6 + 1;
                              pcVar6 = pcVar6 + 1;
                            } while (*pcVar4 != '\0');
                          }
                          else {
                            iVar5 = __stricmp(local_10ec,"hp");
                            if (iVar5 == 0) {
                              pcVar6 = (char *)FUN_005ac680(DAT_007c1936);
                              pcVar10 = local_fec;
                              do {
                                cVar1 = *pcVar6;
                                *pcVar10 = cVar1;
                                pcVar6 = pcVar6 + 1;
                                pcVar10 = pcVar10 + 1;
                              } while (cVar1 != '\0');
                              pcVar10 = local_fec;
                              pcVar6 = pcVar10;
                              do {
                                cVar1 = *pcVar6;
                                pcVar6 = pcVar6 + 1;
                              } while (cVar1 != '\0');
                              uVar7 = (int)pcVar6 - (int)pcVar10;
                              pcVar6 = &cStack_7ed;
                              do {
                                pcVar4 = pcVar6 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (*pcVar4 != '\0');
                            }
                            else {
                              iVar5 = __stricmp(local_10ec,"zz");
                              if (iVar5 == 0) {
                                pcVar6 = (char *)FUN_005ac6c0(DAT_007c1935);
                                pcVar10 = local_fec;
                                do {
                                  cVar1 = *pcVar6;
                                  *pcVar10 = cVar1;
                                  pcVar6 = pcVar6 + 1;
                                  pcVar10 = pcVar10 + 1;
                                } while (cVar1 != '\0');
                                pcVar10 = local_fec;
                                pcVar6 = pcVar10;
                                do {
                                  cVar1 = *pcVar6;
                                  pcVar6 = pcVar6 + 1;
                                } while (cVar1 != '\0');
                                uVar7 = (int)pcVar6 - (int)pcVar10;
                                pcVar6 = &cStack_7ed;
                                do {
                                  pcVar4 = pcVar6 + 1;
                                  pcVar6 = pcVar6 + 1;
                                } while (*pcVar4 != '\0');
                              }
                              else {
                                iVar5 = __stricmp(local_10ec,"up");
                                if (iVar5 == 0) {
                                  pcVar6 = (char *)FUN_005ac680(DAT_007c1934);
                                  pcVar10 = local_fec;
                                  do {
                                    cVar1 = *pcVar6;
                                    *pcVar10 = cVar1;
                                    pcVar6 = pcVar6 + 1;
                                    pcVar10 = pcVar10 + 1;
                                  } while (cVar1 != '\0');
                                  pcVar10 = local_fec;
                                  pcVar6 = pcVar10;
                                  do {
                                    cVar1 = *pcVar6;
                                    pcVar6 = pcVar6 + 1;
                                  } while (cVar1 != '\0');
                                  uVar7 = (int)pcVar6 - (int)pcVar10;
                                  pcVar6 = &cStack_7ed;
                                  do {
                                    pcVar4 = pcVar6 + 1;
                                    pcVar6 = pcVar6 + 1;
                                  } while (*pcVar4 != '\0');
                                }
                                else {
                                  iVar5 = __stricmp(local_10ec,&DAT_0074861c);
                                  if (iVar5 == 0) {
                                    pcVar10 = (char *)FUN_00420480(local_fec);
                                    pcVar6 = pcVar10;
                                    do {
                                      cVar1 = *pcVar6;
                                      pcVar6 = pcVar6 + 1;
                                    } while (cVar1 != '\0');
                                    uVar7 = (int)pcVar6 - (int)pcVar10;
                                    pcVar6 = &cStack_7ed;
                                    do {
                                      pcVar4 = pcVar6 + 1;
                                      pcVar6 = pcVar6 + 1;
                                    } while (*pcVar4 != '\0');
                                  }
                                  else {
                                    iVar5 = __stricmp(local_10ec,&DAT_00748614);
                                    if (iVar5 == 0) {
                                      pcVar10 = (char *)FUN_00420540(local_fec);
                                      pcVar6 = pcVar10;
                                      do {
                                        cVar1 = *pcVar6;
                                        pcVar6 = pcVar6 + 1;
                                      } while (cVar1 != '\0');
                                      uVar7 = (int)pcVar6 - (int)pcVar10;
                                      pcVar6 = &cStack_7ed;
                                      do {
                                        pcVar4 = pcVar6 + 1;
                                        pcVar6 = pcVar6 + 1;
                                      } while (*pcVar4 != '\0');
                                    }
                                    else {
                                      iVar5 = __stricmp(local_10ec,&DAT_0074860c);
                                      if (iVar5 == 0) {
                                        pcVar10 = (char *)FUN_004205a0(local_fec);
                                        pcVar6 = pcVar10;
                                        do {
                                          cVar1 = *pcVar6;
                                          pcVar6 = pcVar6 + 1;
                                        } while (cVar1 != '\0');
                                        uVar7 = (int)pcVar6 - (int)pcVar10;
                                        pcVar6 = &cStack_7ed;
                                        do {
                                          pcVar4 = pcVar6 + 1;
                                          pcVar6 = pcVar6 + 1;
                                        } while (*pcVar4 != '\0');
                                      }
                                      else {
                                        iVar5 = __stricmp(local_10ec,&DAT_007485b8);
                                        if (iVar5 != 0) goto LAB_004215f9;
                                        pcVar10 = (char *)FUN_00420610(local_fec);
                                        pcVar6 = pcVar10;
                                        do {
                                          cVar1 = *pcVar6;
                                          pcVar6 = pcVar6 + 1;
                                        } while (cVar1 != '\0');
                                        uVar7 = (int)pcVar6 - (int)pcVar10;
                                        pcVar6 = &cStack_7ed;
                                        do {
                                          pcVar4 = pcVar6 + 1;
                                          pcVar6 = pcVar6 + 1;
                                        } while (*pcVar4 != '\0');
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
LAB_004215e9:
                      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar10;
                        pcVar10 = pcVar10 + 4;
                        pcVar6 = pcVar6 + 4;
                      }
                      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *pcVar6 = *pcVar10;
                        pcVar10 = pcVar10 + 1;
                        pcVar6 = pcVar6 + 1;
                      }
                    }
                  }
                }
              }
            }
          }
LAB_004215f9:
          pcVar10 = local_10f4;
          if (*pcVar9 == '\0') break;
          pcVar9 = pcVar9 + 1;
          pcVar10 = (char *)0x0;
          local_10f0 = pcVar9;
        }
        else {
          pcVar9 = pcVar9 + 1;
          pcVar10 = pcVar10 + 1;
        }
        cVar1 = *pcVar9;
      } while (cVar1 != '\0');
      if (pcVar10 != (char *)0x0) {
        pcVar9 = local_7ec;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        pcVar4 = pcVar9 + ((int)pcVar10 - (int)(local_7ec + 1));
        if (0x3ff < (int)pcVar4) {
          pcVar10 = "GetMsg Error %d buf1:%d";
          pcVar9 = &DAT_007c2740 + DAT_007c3b40 * 0x400;
LAB_00421717:
          _sprintf(pcVar9,pcVar10,param_1,pcVar4);
          goto LAB_00421720;
        }
        _memcpy(pcVar9 + (int)(local_7ec + -(int)(local_7ec + 1)),local_10f0,(size_t)pcVar10);
        local_7ec[(int)pcVar4] = '\0';
      }
    }
    pcVar10 = local_7ec;
    pcVar9 = &DAT_007c2740 + DAT_007c3b40 * 0x400;
    iVar5 = (int)pcVar9 - (int)pcVar10;
    do {
      cVar1 = *pcVar10;
      pcVar10[iVar5] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9;
    do {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    if (pcVar10 == &DAT_007c2741 + DAT_007c3b40 * 0x400) {
      _sprintf(pcVar9,"GetMsg Error %d",param_1);
    }
  }
LAB_00421720:
  ___security_check_cookie_4();
  return;
}

