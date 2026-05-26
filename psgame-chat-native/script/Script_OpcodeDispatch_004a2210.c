/*
 * server/ps_game.exe — Script_OpcodeDispatch
 * Requested VA: 0x004A2210
 * Entry Ghidra:  004a2210
 * Ghidra name:   FUN_004a2210
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_004a2210(int param_1_00,undefined4 *param_1,uint param_2,int param_3)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  double local_10;
  float local_8;
  undefined4 *local_4;
  
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if (param_2 < 0x7405ad05) {
    if (param_2 == 0x7405ad04) {
      iVar5 = *(int *)(param_3 + 0x10) - *(int *)(param_3 + 0xc);
      iVar2 = iVar5 >> 0x1f;
      if (iVar5 / 0x94 + iVar2 == iVar2) {
        FUN_0051b1ad();
      }
      if (*(int *)(*(int *)(param_3 + 0xc) + 0xc) != 0) {
        iVar2 = FUN_004a3000();
        local_10 = (double)CONCAT44(local_10._4_4_,*(undefined4 *)(iVar2 + 0xc));
        iVar2 = FUN_00415480(&local_10);
        if (iVar2 != 0) {
          FUN_004b4010(iVar2,1);
          return param_1;
        }
      }
    }
    else if (param_2 < 0x335cfa70) {
      if (param_2 == 0x335cfa6f) {
        *param_1 = 3;
        uVar3 = FUN_004a15d0();
        param_1[3] = uVar3;
        return param_1;
      }
      if (param_2 < 0xff3a2fe) {
        if (param_2 == 0xff3a2fd) {
          *param_1 = 1;
          param_1[1] = (uint)*(byte *)(param_1_00 + 0x2d6);
          return param_1;
        }
        if (param_2 < 0xb8820f3) {
          if (param_2 == 0xb8820f2) {
            iVar2 = FUN_004a3000();
            FUN_004c6a80(*(undefined4 *)(iVar2 + 4));
            return param_1;
          }
          if (param_2 == 0x72a8c2f) {
            iVar2 = FUN_004a3000();
            *(undefined4 *)(param_1_00 + 0x2d8) = *(undefined4 *)(iVar2 + 4);
            return param_1;
          }
          if (param_2 == 0x8a6f4c3) {
            iVar2 = FUN_004a3000();
            *(undefined4 *)(param_1_00 + 700) = *(undefined4 *)(iVar2 + 4);
            return param_1;
          }
        }
        else if (param_2 == 0xc726665) {
          iVar2 = FUN_004b4c50();
          if (iVar2 != 0) {
            *param_1 = 3;
            param_1[3] = *(undefined4 *)(iVar2 + 0xdc);
            return param_1;
          }
        }
      }
      else if (param_2 < 0x3246b755) {
        if (param_2 == 0x3246b754) {
          iVar2 = FUN_004a3000();
          FUN_004c6ba0(*(undefined4 *)(iVar2 + 8));
          return param_1;
        }
        if (param_2 == 0x1fe5ec34) {
          FUN_004a3000();
          FUN_004c69f0();
          return param_1;
        }
        if (param_2 == 0x2c14ef3c) {
          iVar2 = FUN_004a3000();
          local_10 = (double)CONCAT44(local_10._4_4_,*(undefined4 *)(iVar2 + 8));
          iVar2 = FUN_004a3000();
          if (*(int *)(param_1_00 + 0x8c) != 0) {
            FUN_004c5d90(param_1_00,*(undefined4 *)(iVar2 + 0xc),local_10._0_4_);
            return param_1;
          }
        }
      }
      else if (param_2 == 0x327674e7) {
        iVar2 = FUN_004a3000();
        *(bool *)(param_1_00 + 0x2e8) = *(int *)(iVar2 + 4) == 1;
        return param_1;
      }
    }
    else if (param_2 < 0x540b1610) {
      if (param_2 == 0x540b160f) {
        FUN_004a3000();
        FUN_004c5fd0();
        return param_1;
      }
      if (param_2 < 0x368302a8) {
        if (param_2 == 0x368302a7) {
          *param_1 = 3;
          if (*(int *)(param_1_00 + 0x1ac) != 0) {
            param_1[3] = *(undefined4 *)(param_1_00 + 0x1b0);
            return param_1;
          }
          param_1[3] = 0;
          return param_1;
        }
        if (param_2 == 0x353ab14e) {
          iVar2 = FUN_004a3000();
          uVar8 = *(undefined4 *)(iVar2 + 4);
          iVar2 = FUN_004a3000(uVar8);
          uVar7 = *(undefined4 *)(iVar2 + 4);
          iVar2 = FUN_004a3000(uVar7);
          uVar3 = *(undefined4 *)(iVar2 + 8);
          FUN_004a3000(uVar3);
          FUN_004c6a20(uVar3,uVar7,uVar8);
          return param_1;
        }
        if (param_2 == 0x36824cb7) {
          *param_1 = 3;
          param_1[3] = *(undefined4 *)(param_1_00 + 0xd5c);
          return param_1;
        }
      }
      else if (param_2 == 0x38a1f081) {
        iVar2 = FUN_004a3000();
        *(undefined4 *)(param_1_00 + 0x2f8) = *(undefined4 *)(iVar2 + 8);
        return param_1;
      }
    }
    else {
      if (param_2 == 0x59ccb87b) {
        *(undefined *)(param_1_00 + 0x2dc) = 0;
        return param_1;
      }
      if (param_2 == 0x603dacb4) {
        _printf(&DAT_00572368);
        return param_1;
      }
      if (param_2 == 0x6dd15366) {
        *(undefined **)(param_1_00 + 0x2fc) = &DAT_01010101;
        return param_1;
      }
    }
  }
  else if (param_2 < 0xbbfc6d87) {
    if (param_2 == 0xbbfc6d86) {
      *param_1 = 1;
      if (*(int *)(param_1_00 + 0x2e0) < 0) {
        *(undefined4 *)(param_1_00 + 0x2e0) = 0;
      }
      param_1[1] = *(undefined4 *)(param_1_00 + 0x2e0);
      return param_1;
    }
    if (param_2 < 0x8a1feef9) {
      if (param_2 == 0x8a1feef8) {
        FUN_004a3000();
        FUN_004c6ec0();
        return param_1;
      }
      if (param_2 < 0x8420f03b) {
        if (param_2 == 0x8420f03a) {
          iVar2 = FUN_004a3000();
          *(undefined4 *)(param_1_00 + 0x2f0) = *(undefined4 *)(iVar2 + 8);
          return param_1;
        }
        if (param_2 == 0x74ab875e) {
          iVar2 = _rand();
          local_4 = (undefined4 *)(param_1_00 + 0xd2c);
          local_10 = (double)CONCAT44(local_10._4_4_,iVar2 % 0x168);
          local_8 = (float)(iVar2 % 0x168);
          *local_4 = 0;
          iVar2 = FUN_004a12a0();
          local_10 = (double)(int)((&DAT_005819ac)[iVar2] +
                                  (uint)*(byte *)(*(int *)(param_1_00 + 0xd4) + 0x60));
          iVar2 = FUN_004a3000();
          *(float *)(param_1_00 + 0xd34) = *(float *)(iVar2 + 8) + (float)local_10;
          *(undefined4 *)(param_1_00 + 0xd30) = 0;
          local_8 = local_8 * (float)_DAT_005741e0;
          FUN_004a0330(local_8);
          return param_1;
        }
        if (param_2 == 0x7c8c3f64) {
          iVar2 = FUN_004a3000();
          uVar3 = *(undefined4 *)(iVar2 + 4);
          iVar2 = FUN_004a3000(uVar3);
          FUN_004c6f50(*(undefined4 *)(iVar2 + 4),uVar3);
          return param_1;
        }
      }
      else if (param_2 == 0x899b2549) {
        *(undefined *)(param_1_00 + 0x2dc) = 1;
        return param_1;
      }
    }
    else if (param_2 < 0xae8b3fe2) {
      if (param_2 == 0xae8b3fe1) {
        *param_1 = 1;
        iVar2 = FUN_004b4330();
        param_1[1] = (uint)(iVar2 != 0);
        return param_1;
      }
      if (param_2 == 0x9602ff4f) {
        iVar2 = FUN_004a3000();
        *(undefined4 *)(param_1_00 + 0x2e4) = *(undefined4 *)(iVar2 + 4);
        return param_1;
      }
      if (param_2 == 0xa45c668b) {
        *param_1 = 1;
        param_1[1] = (uint)*(byte *)(param_1_00 + 0x2d5);
        return param_1;
      }
    }
    else if (param_2 == 0xaec1b010) {
      *param_1 = 1;
      if (*(char *)(param_1_00 + 0x2d7) != '\0') {
        param_1[1] = 1;
        *(undefined *)(param_1_00 + 0x2d7) = 0;
        return param_1;
      }
LAB_004a27e9:
      param_1[1] = 0;
      return param_1;
    }
  }
  else if (param_2 < 0xd0dfe84b) {
    if (param_2 == 0xd0dfe84a) {
      iVar2 = FUN_004a3000();
      *(undefined4 *)(param_1_00 + 0x2ec) = *(undefined4 *)(iVar2 + 8);
      return param_1;
    }
    if (param_2 < 0xd06189bf) {
      if (param_2 == 0xd06189be) {
        *param_1 = 2;
        fVar6 = (float10)FUN_004a02e0();
        param_1[2] = (float)fVar6;
        return param_1;
      }
      if (param_2 == 0xc0785271) {
        *param_1 = 1;
        fVar6 = (float10)FUN_004a02e0();
        if (fVar6 < (float10)_DAT_005741f8 != (NAN(fVar6) || NAN((float10)_DAT_005741f8))) {
          param_1[1] = 1;
          return param_1;
        }
        goto LAB_004a27e9;
      }
      if (param_2 == 0xc78b4620) {
        *param_1 = 2;
        uVar4 = *(uint *)(param_1_00 + 0x2a8) / *(uint *)(*(int *)(param_1_00 + 0xd4) + 0x30);
        fVar1 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar1 = fVar1 + _DAT_00573f50;
        }
        param_1[2] = fVar1;
        return param_1;
      }
    }
    else if (param_2 == 0xd0dfe20b) {
      iVar2 = FUN_004a3000();
      *(undefined4 *)(param_1_00 + 0x2f4) = *(undefined4 *)(iVar2 + 8);
      FUN_004a0db0();
      return param_1;
    }
  }
  else if (param_2 == 0xe9f3a815) {
    *param_1 = 1;
    iVar2 = _rand();
    param_1[1] = iVar2 % 100;
  }
  else {
    if (param_2 == 0xee13ebad) {
      *(undefined4 *)(param_1_00 + 0xd20) = *(undefined4 *)(param_1_00 + 0x7c);
      *(undefined4 *)(param_1_00 + 0xd24) = *(undefined4 *)(param_1_00 + 0x80);
      *(undefined4 *)(param_1_00 + 0xd28) = *(undefined4 *)(param_1_00 + 0x84);
      return param_1;
    }
    if (param_2 == 0xf0a049a9) {
      *(undefined4 *)(param_1_00 + 0x2e0) = 0;
      return param_1;
    }
  }
  return param_1;
}

