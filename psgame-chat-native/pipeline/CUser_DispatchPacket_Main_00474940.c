/*
 * server/ps_game.exe — CUser_DispatchPacket_Main
 * VA solicitado: 0x00474940
 * Entry Ghidra:  00474940
 * Ghidra name:   FUN_00474940
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: pipeline
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_00474940(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  DWORD DVar5;
  byte *pbVar6;
  undefined auStack_34 [4];
  int local_30;
  undefined2 local_2c;
  undefined4 local_2a;
  undefined4 local_26;
  undefined4 local_22;
  undefined4 local_1e;
  undefined4 local_1a;
  undefined4 local_16;
  undefined4 local_12;
  uint local_c;
  
  local_c = DAT_0057f7c4 ^ (uint)auStack_34;
  iVar3 = *(int *)(param_1 + 0x57f4);
  if (iVar3 == 0) {
    if ((*param_2 == 0xa301) && (*(int *)(param_2 + 1) != 0)) {
      local_30 = *(int *)(param_2 + 1);
      iVar3 = FUN_00415480(&local_30);
      if ((iVar3 == 0) && (*(int *)(param_1 + 0x582c) == 0)) {
        local_2a = *(undefined4 *)(param_1 + 0x57f8);
        *(undefined4 *)(param_1 + 0x582c) = *(undefined4 *)(param_2 + 1);
        local_26 = *(undefined4 *)(param_1 + 0x70);
        local_1e = *(undefined4 *)(param_2 + 3);
        local_1a = *(undefined4 *)(param_2 + 5);
        local_2c = 0x801;
        local_22 = *(undefined4 *)(param_2 + 1);
        local_12 = *(undefined4 *)(param_2 + 9);
        local_16 = *(undefined4 *)(param_2 + 7);
        FUN_004ed2d0(&local_2c,0x1e);
        ___security_check_cookie_4();
        return;
      }
    }
    FUN_004efdc0(DAT_00587970 + 0xe0,"WHERE_CONNECT Error Packet=%x, Char=%s, Cnt=%d",*param_2,
                 param_1 + 0x184,*(undefined4 *)(param_1 + 0x58b0));
    if (*(uint *)(param_1 + 0x58b0) < 10) {
      *(uint *)(param_1 + 0x58b0) = *(uint *)(param_1 + 0x58b0) + 1;
      ___security_check_cookie_4();
      return;
    }
    FUN_004ec760(0x65,0);
    ___security_check_cookie_4();
    return;
  }
  if (iVar3 == 1) {
    if ((*param_2 & 0xff00) == 0x100) {
      FUN_0047a220();
      ___security_check_cookie_4();
      return;
    }
  }
  else if (iVar3 == 3) {
    uVar1 = *param_2;
    uVar2 = uVar1 & 0xff00;
    if (uVar2 < 0x3101) {
      if (uVar2 == 0x3100) {
LAB_00474fda:
        FUN_00486cf0();
        ___security_check_cookie_4();
        return;
      }
      if (uVar2 == 0x200) {
        if (uVar1 == 0x201) {
          FUN_00456910();
          ___security_check_cookie_4();
          return;
        }
      }
      else if ((uVar2 == 0x1100) && (*(int *)(param_1 + 0x1818) != 0)) {
LAB_00474afc:
        FUN_0047f400(param_1);
        ___security_check_cookie_4();
        return;
      }
    }
    else {
      if (uVar2 == 0xb100) {
        if (uVar1 == 0xb106) {
          FUN_004dc090();
          ___security_check_cookie_4();
          return;
        }
        goto LAB_00474d6b;
      }
      if ((uVar2 == 0xf100) && (*(int *)(param_1 + 0x1818) != 0)) {
LAB_00474b5b:
        FUN_0047fd10(param_1);
        ___security_check_cookie_4();
        return;
      }
    }
  }
  else if ((iVar3 == 4) && (*(int *)(param_1 + 0xe0) != 0)) {
    uVar1 = *param_2;
    uVar2 = uVar1 & 0xff00;
    if (uVar2 < 0x1c01) {
      if (uVar2 == 0x1c00) {
        FUN_004862b0(param_2);
        ___security_check_cookie_4();
        return;
      }
      if (uVar2 < 0xa01) {
        if (uVar2 == 0xa00) {
          FUN_0047d940();
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 < 0x501) {
          if (uVar2 == 0x500) {
            FUN_00478490(param_2);
            ___security_check_cookie_4();
            return;
          }
          if (uVar2 == 0x100) {
            if (uVar1 != 0x10b) {
              if (uVar1 == 0x107) {
                if (((*(char *)(param_1 + 0x144c) == '\x01') && (*(int *)(param_1 + 0x587c) == 0))
                   && (*(int *)(param_1 + 0x68) != -1)) {
                  *(undefined4 *)(param_1 + 0x5878) = 1;
                  DVar5 = GetTickCount();
                  *(DWORD *)(param_1 + 0x587c) = DVar5 + 10000;
                  *(undefined4 *)(param_1 + 0x58b8) = 0;
                  ___security_check_cookie_4();
                  return;
                }
              }
              else {
                if (uVar1 != 0x10d) goto LAB_00474d6b;
                if (((*(char *)(param_1 + 0x144c) == '\x01') && (*(int *)(param_1 + 0x587c) == 0))
                   && (*(int *)(param_1 + 0x68) != -1)) {
                  *(undefined4 *)(param_1 + 0x5878) = 2;
                  DVar5 = GetTickCount();
                  *(DWORD *)(param_1 + 0x587c) = DVar5 + 10000;
                  ___security_check_cookie_4();
                  return;
                }
              }
              goto LAB_004750d3;
            }
            if (*(byte *)(param_2 + 1) < 0x80) {
              iVar3 = 0;
              *(undefined4 *)(param_1 + 0xec0) = 0;
              if (*(char *)(param_2 + 1) != '\0') {
                pbVar4 = (byte *)((int)param_2 + 5);
                pbVar6 = (byte *)(param_1 + 0xec4);
                do {
                  if ((*pbVar4 != 0xff) || (9 < *pbVar6)) {
                    *pbVar6 = pbVar4[-2];
                    pbVar6[1] = pbVar4[-1];
                    pbVar6[2] = *pbVar4;
                    *(undefined2 *)(pbVar6 + 4) = *(undefined2 *)(pbVar4 + 1);
                    *(int *)(param_1 + 0xec0) = *(int *)(param_1 + 0xec0) + 1;
                  }
                  iVar3 = iVar3 + 1;
                  pbVar4 = pbVar4 + 5;
                  pbVar6 = pbVar6 + 6;
                } while (iVar3 < (int)(uint)*(byte *)(param_2 + 1));
              }
              FUN_0047ace0();
              ___security_check_cookie_4();
              return;
            }
          }
          else {
            if (uVar2 == 0x200) {
              FUN_00476070(param_1);
              ___security_check_cookie_4();
              return;
            }
            if (uVar2 == 0x300) {
              FUN_00477a50();
              ___security_check_cookie_4();
              return;
            }
          }
        }
        else {
          if (uVar2 == 0x700) {
            FUN_00479220();
            ___security_check_cookie_4();
            return;
          }
          if (uVar2 == 0x800) {
            FUN_00479f90();
            ___security_check_cookie_4();
            return;
          }
          if (uVar2 == 0x900) {
            FUN_0047a080();
            ___security_check_cookie_4();
            return;
          }
        }
      }
      else if (uVar2 < 0xf01) {
        if (uVar2 == 0xf00) {
          FUN_00475150();
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0xb00) {
          FUN_004752b0(param_1);
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0xd00) {
          FUN_00484fc0(param_1);
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0xe00) {
          FUN_004750f0();
          ___security_check_cookie_4();
          return;
        }
      }
      else {
        if (uVar2 == 0x1100) goto LAB_00474afc;
        if (uVar2 == 0x1200) {
          FUN_0047fcc0();
          ___security_check_cookie_4();
          return;
        }
      }
    }
    else if (uVar2 < 0xf101) {
      if (uVar2 == 0xf100) goto LAB_00474b5b;
      if (uVar2 < 0x2501) {
        if (uVar2 == 0x2500) {
          FUN_0048c950(param_1,param_2);
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0x2200) {
          FUN_00484360(param_1);
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0x2300) {
          FUN_00487370(param_1);
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0x2400) {
          FUN_0048bde0(param_1);
          ___security_check_cookie_4();
          return;
        }
      }
      else {
        if (uVar2 == 0x2600) {
          FUN_00487f20();
          ___security_check_cookie_4();
          return;
        }
        if (uVar2 == 0x3100) {
          if (uVar1 == 0x3101) goto LAB_00474fda;
          goto LAB_004750d3;
        }
        if (uVar2 == 0xb100) {
          FUN_004648f0(param_2);
          ___security_check_cookie_4();
          return;
        }
      }
    }
    else if (uVar2 < 0xf801) {
      if (uVar2 == 0xf800) {
        FUN_00481f50(param_1);
        ___security_check_cookie_4();
        return;
      }
      if (uVar2 == 0xf200) {
        FUN_00480610();
        ___security_check_cookie_4();
        return;
      }
      if (uVar2 == 0xf600) {
        FUN_00480ab0(param_1);
        ___security_check_cookie_4();
        return;
      }
      if (uVar2 == 0xf700) {
        FUN_00480d20(param_2);
        ___security_check_cookie_4();
        return;
      }
    }
    else {
      if (uVar2 == 0xf900) {
        FUN_00482630(param_2);
        goto LAB_004750d3;
      }
      if (uVar2 == 64000) {
        FUN_00483430(param_1);
        ___security_check_cookie_4();
        return;
      }
    }
LAB_00474d6b:
    FUN_004ec760(9,0);
    ___security_check_cookie_4();
    return;
  }
LAB_004750d3:
  ___security_check_cookie_4();
  return;
}

