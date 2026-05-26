/*
 * Game.exe — ChatWorldFX_SendUI (was NativeChatSendUI; not PacketSend_*)
 * Requested VA: 0x0045BBE0
 * Entry Ghidra:  0045bbe0
 * Ghidra name:   FUN_0045bbe0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0045bbe0(int param_1_00,undefined4 param_1,float param_2,short param_3,undefined param_4,
            float *param_5,int param_6,undefined param_7,undefined4 param_8,char param_9,
            undefined4 param_10,ushort param_11,ushort param_12,ushort param_13,char param_14,
            float param_15,undefined4 param_16,char param_17)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  DWORD DVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  float10 fVar9;
  float afStack_1c4 [2];
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float local_18c;
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  undefined4 local_150;
  float local_14c;
  float fStack_148;
  float fStack_144;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  undefined4 uStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a4;
  uint uStack_90;
  uint uStack_88;
  undefined4 uStack_78;
  uint uStack_74;
  short sStack_70;
  undefined uStack_6e;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined uStack_4c;
  undefined4 uStack_48;
  char cStack_44;
  undefined4 uStack_40;
  ushort uStack_3c;
  ushort uStack_3a;
  ushort uStack_38;
  char cStack_36;
  int iStack_34;
  undefined4 uStack_30;
  uint local_24;
  void *local_1c;
  undefined *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_0072e4f1;
  local_1c = ExceptionList;
  local_24 = DAT_007b4dd0 ^ (uint)afStack_1c4;
  ExceptionList = &local_1c;
  local_18c = 0.0;
  local_188 = 0.0;
  local_184 = 0.0;
  local_150 = param_1;
  local_14c = param_2;
  FUN_0055e480(param_1,DAT_007b4dd0 ^ (uint)&stack0xfffffe30);
  pfVar3 = (float *)FUN_0055f770(param_1);
  if (pfVar3 != (float *)0x0) {
    if (param_17 == '\0') {
      local_18c = *pfVar3;
      local_188 = pfVar3[1];
      local_184 = pfVar3[2];
    }
    else {
      local_18c = pfVar3[3];
      local_188 = pfVar3[4];
      local_184 = pfVar3[5];
    }
    iVar4 = FUN_00452b10(param_8);
    if (iVar4 == 0) {
      iVar4 = FUN_00452b90(param_8);
      if (iVar4 == 0) goto LAB_0045bd97;
      local_180 = *(float *)(iVar4 + 0x68);
      local_17c = *(float *)(iVar4 + 0x6c);
      local_178 = *(float *)(iVar4 + 0x70);
    }
    else {
      local_180 = *(float *)(iVar4 + 0x1c);
      local_17c = *(float *)(iVar4 + 0x20);
      local_178 = *(float *)(iVar4 + 0x24);
    }
    local_164 = 0.0;
    local_15c = 0.0;
    local_158 = 0.0;
    local_154 = 1.0;
    local_168 = local_180;
    local_160 = local_178;
    thunk_FUN_006587f1(&local_168,&local_168);
    thunk_FUN_006587f1(&local_164,&local_164);
    afStack_1c4[0] = local_164 * fStack_170 + fStack_16c * local_178 + local_168 * fStack_174;
    fVar9 = (float10)FUN_00633f70();
    afStack_1c4[0] = (float)fVar9;
    fStack_1bc = -afStack_1c4[0];
    if (0.0 < fStack_190 != NAN(fStack_190)) {
      fStack_1bc = -fStack_1bc;
    }
    thunk_FUN_00659f6e(&uStack_100,fStack_1bc);
    thunk_FUN_00658bd7(&fStack_19c,&fStack_19c,&uStack_100);
  }
LAB_0045bd97:
  if (param_14 == 'd') {
    if (*(int *)(param_1_00 + 0x1422dc) == 0) {
      *(undefined4 *)(param_1_00 + 0x1422e4) = 0;
      *(undefined4 *)(param_1_00 + 0x1422e8) = 0;
      FUN_00405590(local_150,0,0xffffffff);
      FUN_00405590(local_14c,0,0xffffffff);
      *(short *)(param_1_00 + 0x142324) = param_3;
      *(undefined *)(param_1_00 + 0x142326) = param_4;
      fStack_19c = *param_5;
      fStack_198 = param_5[1];
      fStack_194 = param_5[2];
      *(undefined4 *)(param_1_00 + 0x14234c) = param_8;
      *(undefined *)(param_1_00 + 0x14235e) = 100;
      *(undefined4 *)(param_1_00 + 0x1422dc) = 1;
      fStack_174 = fStack_19c + local_18c;
      *(float *)(param_1_00 + 0x142328) = fStack_174;
      fStack_170 = fStack_198 + local_188;
      *(int *)(param_1_00 + 0x142344) = param_6;
      *(float *)(param_1_00 + 0x14232c) = fStack_170;
      fStack_16c = fStack_194 + local_184;
      *(undefined *)(param_1_00 + 0x142348) = param_7;
      *(float *)(param_1_00 + 0x142330) = fStack_16c;
      *(char *)(param_1_00 + 0x142350) = param_9;
      *(undefined4 *)(param_1_00 + 0x142354) = param_10;
      *(ushort *)(param_1_00 + 0x142358) = param_11;
      *(ushort *)(param_1_00 + 0x14235a) = param_12;
      *(ushort *)(param_1_00 + 0x14235c) = param_13;
      DVar5 = GetTickCount();
      *(DWORD *)(param_1_00 + 0x1422e0) = DVar5 + 0x96;
      goto LAB_0045cb70;
    }
    if (*(int *)(param_1_00 + 0x1422e0) != 0) {
      *(undefined4 *)(param_1_00 + 0x1422dc) = 0;
      *(undefined4 *)(param_1_00 + 0x1422e0) = 0;
    }
  }
  if (param_6 == 5) {
    iVar4 = FUN_00452b10(param_8);
    iVar6 = FUN_00452b90(param_8);
    if (iVar4 == 0) {
      if (iVar6 == 0) goto LAB_0045cb70;
      pfVar3 = (float *)(iVar6 + 4);
    }
    else {
      pfVar3 = (float *)(iVar4 + 0x10);
    }
    local_168 = *pfVar3;
    local_164 = pfVar3[1];
    local_160 = pfVar3[2];
    if (iVar4 == 0) {
      puVar7 = (undefined4 *)(iVar6 + 0x1c);
    }
    else {
      puVar7 = (undefined4 *)(iVar4 + 0x28);
    }
    uStack_fc = *puVar7;
    fStack_1a8 = 0.0;
    fStack_1a4 = 0.0;
    uStack_f8 = puVar7[1];
    fStack_1a0 = 0.0;
    uStack_f4 = puVar7[2];
    if (param_9 == '\0') {
      iVar4 = FUN_00452b90(param_10);
      if (iVar4 != 0) {
        fStack_1a8 = *(float *)(iVar4 + 4);
        fStack_1a4 = *(float *)(iVar4 + 8);
        fStack_1a0 = *(float *)(iVar4 + 0xc);
      }
    }
    else {
      iVar4 = FUN_00452b10(param_10);
      if (iVar4 != 0) {
        fStack_1a8 = *(float *)(iVar4 + 0x10);
        fStack_1a4 = *(float *)(iVar4 + 0x14);
        fStack_1a0 = *(float *)(iVar4 + 0x18);
      }
    }
    fStack_1bc = fStack_1a8 - local_168;
    fStack_1b8 = fStack_1a4 - local_164;
    fStack_1b4 = fStack_1a0 - local_160;
    local_15c = fStack_1bc;
    local_158 = fStack_1b8;
    local_154 = fStack_1b4;
    thunk_FUN_006587f1(&local_15c,&local_15c);
    fStack_1b0 = 0.0;
    if (0 < (int)param_15) {
      fStack_148 = (float)((longlong)(ulonglong)param_11 / (longlong)(int)param_15);
      fStack_190 = (float)(param_1_00 + 0x1422c8);
      fStack_1ac = 0.0;
      fStack_1b4 = param_15;
      uStack_128 = (undefined4)((longlong)(ulonglong)param_12 / (longlong)(int)param_15);
      uStack_100 = (undefined4)((longlong)(ulonglong)param_13 / (longlong)(int)param_15);
      do {
        fVar2 = fStack_190;
        FUN_00451fe0();
        uStack_14 = 2;
        uStack_b0 = 0;
        uStack_ac = 0;
        FUN_00405590(local_150,0,0xffffffff);
        FUN_00405590(local_14c,0,0xffffffff);
        sStack_70 = param_3;
        uStack_6e = param_4;
        thunk_FUN_006587f1(&fStack_1a8,&uStack_fc);
        bVar8 = fStack_1b8 == 0.0;
        if (bVar8) {
          fVar1 = (float)_DAT_00748248;
          fStack_1b0 = fStack_1b0 * fVar1;
          fStack_1ac = fStack_1ac * fVar1;
          fStack_1a8 = fVar1 * fStack_1a8;
          fStack_1a4 = local_160 * fStack_1a8 - local_15c * fStack_1ac;
          fStack_1a0 = fStack_1b0 * local_15c - local_164 * fStack_1a8;
          fStack_19c = fStack_1ac * local_164 - local_160 * fStack_1b0;
          local_14c = fStack_1a4;
          fStack_148 = fStack_1a0;
          fStack_144 = fStack_19c;
          thunk_FUN_006587f1(&fStack_1a4,&fStack_1a4);
          fVar1 = (float)_DAT_00748250;
          local_180 = fStack_19c * fVar1 + local_168;
          local_17c = local_164 + fStack_198 * fVar1;
          local_178 = local_160 + fVar1 * fStack_194;
          fStack_134 = local_180;
          fStack_130 = local_17c;
          fStack_12c = local_178;
        }
        else {
          local_17c = local_160 * fStack_1a8 - local_15c * fStack_1ac;
          local_178 = fStack_1b0 * local_15c - local_164 * fStack_1a8;
          fStack_174 = fStack_1ac * local_164 - local_160 * fStack_1b0;
          fStack_114 = local_17c;
          fStack_110 = local_178;
          fStack_10c = fStack_174;
          thunk_FUN_006587f1(&local_17c,&local_17c);
          fVar1 = (float)_DAT_00748250;
          local_180 = fStack_174 * fVar1 + local_168;
          local_17c = local_164 + fStack_170 * fVar1;
          local_178 = local_160 + fVar1 * fStack_16c;
          fStack_118 = local_180;
          fStack_114 = local_17c;
          fStack_110 = local_178;
        }
        fStack_1b0 = (float)(uint)bVar8;
        local_17c = local_17c + (float)_DAT_00748428;
        uStack_50 = 4;
        fStack_1bc = local_180 + local_18c;
        fStack_1b8 = local_188 + local_17c;
        fStack_138 = local_184 + local_178;
        uStack_4c = param_7;
        uStack_48 = param_8;
        cStack_44 = param_9;
        uStack_40 = param_10;
        uStack_3c = fStack_148._0_2_;
        uStack_3a = (ushort)uStack_128;
        uStack_38 = (ushort)uStack_100;
        cStack_36 = param_14;
        uStack_30 = param_16;
        fStack_124 = fStack_1bc;
        fStack_120 = fStack_1b8;
        fStack_11c = fStack_138;
        fStack_6c = fStack_1bc;
        fStack_68 = fStack_1b8;
        fStack_64 = fStack_138;
        DVar5 = GetTickCount();
        iStack_34 = DVar5 + (int)fStack_1ac;
        if (param_3 == 0x222) {
          iStack_34 = iStack_34 + 1000;
        }
        iVar4 = *(int *)((int)fVar2 + 4);
        iVar6 = FUN_004583d0(iVar4,*(undefined4 *)(iVar4 + 4),&uStack_b0);
        FUN_00454560(1);
        *(int *)(iVar4 + 4) = iVar6;
        **(int **)(iVar6 + 4) = iVar6;
        uStack_14 = 0xffffffff;
        if (0xf < uStack_74) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd(uStack_88);
        }
        uStack_74 = 0xf;
        uStack_78 = 0;
        uStack_88 = uStack_88 & 0xffffff00;
        if (0xf < uStack_90) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd(uStack_a4);
        }
        fStack_1ac = (float)((int)fStack_1ac + 300);
        fStack_1b4 = (float)((int)fStack_1b4 + -1);
      } while (fStack_1b4 != 0.0);
    }
  }
  else if (param_6 == 6) {
    if (0 < (int)param_15) {
      fStack_1ac = (float)(param_1_00 + 0x1422c8);
      fStack_1b0 = 0.0;
      fStack_190 = param_15;
      do {
        FUN_00451fe0();
        uStack_14 = 0;
        uStack_b0 = 0;
        uStack_ac = 0;
        FUN_00405590(local_150,0,0xffffffff);
        FUN_00405590(local_14c,0,0xffffffff);
        sStack_70 = param_3;
        uStack_6e = param_4;
        uStack_50 = 4;
        fStack_1bc = *param_5 + local_18c;
        fStack_1b8 = local_188 + param_5[1];
        fStack_1b4 = local_184 + param_5[2];
        uStack_4c = param_7;
        uStack_48 = param_8;
        cStack_44 = param_9;
        uStack_40 = param_10;
        uStack_30 = param_16;
        if (0 < (int)param_15) {
          uStack_3c = (ushort)((longlong)(ulonglong)param_11 / (longlong)(int)param_15);
          uStack_3a = (ushort)((longlong)(ulonglong)param_12 / (longlong)(int)param_15);
          cStack_36 = param_14;
          uStack_38 = (ushort)((longlong)(ulonglong)param_13 / (longlong)(int)param_15);
        }
        fStack_19c = fStack_1bc;
        fStack_198 = fStack_1b8;
        fStack_194 = fStack_1b4;
        fStack_6c = fStack_1bc;
        fStack_68 = fStack_1b8;
        fStack_64 = fStack_1b4;
        DVar5 = GetTickCount();
        iStack_34 = DVar5 + (int)fStack_1b0;
        iVar4 = *(int *)((int)fStack_1ac + 4);
        iVar6 = FUN_004583d0(iVar4,*(undefined4 *)(iVar4 + 4),&uStack_b0);
        FUN_00454560(1);
        *(int *)(iVar4 + 4) = iVar6;
        **(int **)(iVar6 + 4) = iVar6;
        uStack_14 = 0xffffffff;
        if (0xf < uStack_74) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd(uStack_88);
        }
        uStack_74 = 0xf;
        uStack_78 = 0;
        uStack_88 = uStack_88 & 0xffffff00;
        if (0xf < uStack_90) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd(uStack_a4);
        }
        fStack_1b0 = (float)((int)fStack_1b0 + 300);
        fStack_190 = (float)((int)fStack_190 + -1);
      } while (fStack_190 != 0.0);
      fStack_190 = 0.0;
    }
  }
  else if (param_6 == 7) {
    if (0 < (int)param_15) {
      fStack_1b0 = (float)(param_1_00 + 0x1422c8);
      fStack_1ac = 0.0;
      fStack_190 = param_15;
      do {
        fVar2 = fStack_1b0;
        fStack_1a8 = 0.0;
        fStack_1a4 = 0.0;
        fStack_1a0 = 0.0;
        if (param_9 == '\0') {
          iVar4 = FUN_00452b90(param_10);
          if (iVar4 != 0) {
            fStack_1a8 = *(float *)(iVar4 + 4);
            fStack_1a4 = *(float *)(iVar4 + 8);
            fStack_1a0 = *(float *)(iVar4 + 0xc);
          }
        }
        else {
          iVar4 = FUN_00452b10(param_10);
          if (iVar4 != 0) {
            fStack_1a8 = *(float *)(iVar4 + 0x10);
            fStack_1a4 = *(float *)(iVar4 + 0x14);
            fStack_1a0 = *(float *)(iVar4 + 0x18);
          }
        }
        FUN_00451fe0();
        uStack_b0 = 0;
        uStack_ac = 0;
        uStack_14 = 1;
        FUN_00405590(local_150,0,0xffffffff);
        FUN_00405590(local_14c,0,0xffffffff);
        sStack_70 = param_3;
        uStack_6e = param_4;
        fStack_1b4 = *param_5 + local_18c;
        fStack_1b8 = local_188 + param_5[1];
        fStack_1bc = local_184 + param_5[2];
        fStack_19c = fStack_1b4;
        fStack_198 = fStack_1b8;
        fStack_194 = fStack_1bc;
        fStack_6c = fStack_1b4;
        fStack_68 = fStack_1b8;
        fStack_64 = fStack_1bc;
        iVar4 = _rand();
        fStack_1bc = (float)(iVar4 % 9 + -4);
        iVar4 = _rand();
        fStack_1bc = (float)(int)fStack_1bc + fStack_1a8;
        fStack_1b4 = fStack_1a4 + (float)_DAT_00748078;
        fStack_1b8 = (float)(iVar4 % 9 + -4) + fStack_1a0;
        uStack_4c = param_7;
        uStack_48 = param_8;
        cStack_44 = param_9;
        uStack_40 = param_10;
        uStack_3c = param_11;
        uStack_54 = 1;
        uStack_50 = 4;
        uStack_3a = param_12;
        uStack_38 = param_13;
        cStack_36 = '\x04';
        uStack_30 = param_16;
        fStack_174 = fStack_1bc;
        fStack_170 = fStack_1b4;
        fStack_16c = fStack_1b8;
        fStack_60 = fStack_1bc;
        fStack_5c = fStack_1b4;
        fStack_58 = fStack_1b8;
        DVar5 = GetTickCount();
        iStack_34 = DVar5 + (int)fStack_1ac;
        iVar4 = *(int *)((int)fVar2 + 4);
        iVar6 = FUN_004583d0(iVar4,*(undefined4 *)(iVar4 + 4),&uStack_b0);
        FUN_00454560(1);
        *(int *)(iVar4 + 4) = iVar6;
        **(int **)(iVar6 + 4) = iVar6;
        uStack_14 = 0xffffffff;
        if (0xf < uStack_74) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd(uStack_88);
        }
        uStack_74 = 0xf;
        uStack_78 = 0;
        uStack_88 = uStack_88 & 0xffffff00;
        if (0xf < uStack_90) {
                    /* WARNING: Subroutine does not return */
          FUN_006307cd(uStack_a4);
        }
        fStack_1ac = (float)((int)fStack_1ac + 300);
        fStack_190 = (float)((int)fStack_190 + -1);
      } while (fStack_190 != 0.0);
      fStack_190 = 0.0;
    }
  }
  else {
    fStack_1b4 = (float)(param_1_00 + 0x13d9a0);
    iVar4 = CreateObject();
    if (iVar4 != 0) {
      fStack_19c = *param_5 + local_18c;
      fStack_198 = param_5[1] + local_188;
      fStack_194 = param_5[2] + local_184;
      *(float *)(iVar4 + 4) = fStack_19c;
      *(float *)(iVar4 + 8) = fStack_198;
      *(float *)(iVar4 + 0xc) = fStack_194;
      *(float *)(iVar4 + 8) = *(float *)(iVar4 + 8) + (float)_DAT_0074b6a8;
      if ((param_6 < 2) || (4 < param_6)) {
        param_6 = 0;
      }
      else {
        FUN_0040fc80(local_150,param_4);
      }
      *(undefined4 *)(iVar4 + 0xb0) = 0;
      FUN_00405590(local_14c,0,0xffffffff);
      *(short *)(iVar4 + 0xd0) = param_3;
      *(undefined *)(iVar4 + 0xd3) = param_7;
      *(int *)(iVar4 + 0x90) = param_6;
      *(char *)(iVar4 + 0x80) = param_9;
      *(ushort *)(iVar4 + 0x88) = param_11;
      *(undefined4 *)(iVar4 + 0x84) = param_10;
      *(ushort *)(iVar4 + 0x8a) = param_12;
      *(char *)(iVar4 + 0x8e) = param_14;
      *(undefined *)(iVar4 + 0xd2) = param_4;
      *(undefined4 *)(iVar4 + 0x94) = param_8;
      *(ushort *)(iVar4 + 0x8c) = param_13;
      *(undefined4 *)(iVar4 + 0xe0) = param_16;
      FUN_00458750(iVar4);
    }
  }
LAB_0045cb70:
  ExceptionList = local_1c;
  ___security_check_cookie_4();
  return;
}

