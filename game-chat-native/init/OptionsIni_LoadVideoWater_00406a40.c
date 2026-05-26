/*
 * Game.exe — OptionsIni_LoadVideoWater
 * Requested VA: 0x00406A40
 * Entry Ghidra:  00406110
 * Ghidra name:   FUN_00406110
 * NOTE: VA is inside the function (landmark/hook), not the entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: init
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406110(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  byte abStack_2e8 [4];
  undefined1 *puStack_2e4;
  undefined *puStack_2e0;
  undefined *puStack_2dc;
  undefined1 *puStack_2d8;
  byte *pbStack_2d4;
  byte abStack_2d0 [4];
  undefined1 *puStack_2cc;
  undefined *puStack_2c8;
  undefined *puStack_2c4;
  undefined1 *puStack_2c0;
  byte *pbStack_2bc;
  byte abStack_2b8 [4];
  undefined1 *puStack_2b4;
  undefined *puStack_2b0;
  undefined *puStack_2ac;
  undefined1 *puStack_2a8;
  byte *pbStack_2a4;
  byte abStack_2a0 [4];
  undefined1 *puStack_29c;
  undefined *puStack_298;
  undefined *puStack_294;
  undefined1 *puStack_290;
  byte *pbStack_28c;
  byte abStack_288 [4];
  undefined1 *puStack_284;
  undefined *puStack_280;
  undefined *puStack_27c;
  undefined1 *puStack_278;
  byte *pbStack_274;
  byte abStack_270 [4];
  undefined1 *puStack_26c;
  undefined *puStack_268;
  undefined *puStack_264;
  undefined1 *puStack_260;
  byte *pbStack_25c;
  byte abStack_258 [4];
  undefined1 *puStack_254;
  undefined *puStack_250;
  undefined *puStack_24c;
  undefined1 *puStack_248;
  undefined4 *puStack_244;
  byte abStack_240 [4];
  undefined4 *puStack_23c;
  undefined *puStack_238;
  undefined *puStack_234;
  undefined1 *puStack_230;
  undefined4 *puStack_22c;
  undefined4 uStack_228;
  undefined4 *puStack_224;
  undefined *puStack_220;
  undefined *puStack_21c;
  undefined1 *puStack_218;
  undefined4 *puStack_214;
  undefined4 uStack_210;
  undefined4 *puStack_20c;
  undefined *puStack_208;
  undefined1 *puStack_204;
  undefined1 *puStack_200;
  undefined4 *puStack_1fc;
  undefined4 uStack_1f8;
  undefined4 *puStack_1f4;
  undefined *puStack_1f0;
  undefined *puStack_1ec;
  undefined1 *puStack_1e8;
  undefined4 *puStack_1e4;
  undefined4 uStack_1e0;
  undefined4 *puStack_1dc;
  undefined *puStack_1d8;
  undefined *puStack_1d4;
  undefined1 *puStack_1d0;
  byte *pbStack_1cc;
  undefined4 uStack_1c8;
  undefined1 *puStack_1c4;
  undefined *puStack_1c0;
  undefined *puStack_1bc;
  undefined1 *puStack_1b8;
  byte *pbStack_1b4;
  byte abStack_1b0 [4];
  undefined1 *puStack_1ac;
  undefined *puStack_1a8;
  undefined *puStack_1a4;
  undefined1 *puStack_1a0;
  byte *pbStack_19c;
  byte abStack_198 [4];
  undefined1 *puStack_194;
  undefined *puStack_190;
  undefined *puStack_18c;
  undefined1 *puStack_188;
  byte *pbStack_184;
  byte abStack_180 [4];
  undefined1 *puStack_17c;
  undefined *puStack_178;
  undefined *puStack_174;
  undefined1 *puStack_170;
  byte *pbStack_16c;
  byte abStack_168 [4];
  undefined1 *puStack_164;
  undefined *puStack_160;
  undefined *puStack_15c;
  undefined1 *puStack_158;
  byte *pbStack_154;
  byte abStack_150 [4];
  undefined1 *puStack_14c;
  undefined *puStack_148;
  undefined *puStack_144;
  undefined1 *puStack_140;
  byte *pbStack_13c;
  byte abStack_138 [4];
  undefined1 *puStack_134;
  undefined *puStack_130;
  undefined *puStack_12c;
  undefined1 *puStack_128;
  undefined *puStack_124;
  byte abStack_120 [4];
  undefined1 *puStack_11c;
  undefined auStack_108 [260];
  uint uStack_4;
  
  uStack_4 = DAT_007b4dd0 ^ (uint)auStack_108;
  puStack_11c = (undefined1 *)0x104;
  puStack_124 = auStack_108;
  abStack_120[0] = 0;
  abStack_120[1] = 0;
  abStack_120[2] = 0;
  abStack_120[3] = 0;
  puStack_128 = (undefined1 *)0x40613a;
  FUN_006319e0();
  puStack_11c = &DAT_007c0720;
  abStack_120[0] = 4;
  abStack_120[1] = 1;
  abStack_120[2] = 0;
  abStack_120[3] = 0;
  puStack_124 = auStack_108;
  puStack_128 = &DAT_00746cf4;
  puStack_12c = &DAT_00746e88;
  puStack_130 = &DAT_00746e7c;
  _DAT_007c0df8 = 0;
  puStack_134 = (undefined1 *)0x406169;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d70 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_120;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_004061ab:
        DAT_007c0d70 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_004061c5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_004061ab;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d70 = 0;
  }
LAB_004061c5:
  puStack_134 = &DAT_007c0720;
  abStack_138[0] = 4;
  abStack_138[1] = 1;
  abStack_138[2] = 0;
  abStack_138[3] = 0;
  pbStack_13c = abStack_120;
  puStack_140 = &DAT_00746cf4;
  puStack_144 = &DAT_00746e6c;
  puStack_148 = &DAT_00746e7c;
  puStack_14c = (undefined1 *)0x4061e5;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d74 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_138;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0040621d:
        DAT_007c0d74 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406237;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0040621d;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d74 = 0;
  }
LAB_00406237:
  puStack_14c = &DAT_007c0720;
  abStack_150[0] = 4;
  abStack_150[1] = 1;
  abStack_150[2] = 0;
  abStack_150[3] = 0;
  pbStack_154 = abStack_138;
  puStack_158 = &DAT_00746cf4;
  puStack_15c = &DAT_00746e64;
  puStack_160 = &DAT_00746e7c;
  puStack_164 = (undefined1 *)0x406257;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d78 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_150;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0040628f:
        DAT_007c0d78 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_004062a9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0040628f;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d78 = 0;
  }
LAB_004062a9:
  puStack_164 = &DAT_007c0720;
  abStack_168[0] = 4;
  abStack_168[1] = 1;
  abStack_168[2] = 0;
  abStack_168[3] = 0;
  pbStack_16c = abStack_150;
  puStack_170 = &DAT_00746cf4;
  puStack_174 = &DAT_00746e5c;
  puStack_178 = &DAT_00746e7c;
  puStack_17c = (undefined1 *)0x4062c9;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d7c = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_168;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406301:
        DAT_007c0d7c = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_0040631b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406301;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d7c = 0;
  }
LAB_0040631b:
  puStack_17c = &DAT_007c0720;
  abStack_180[0] = 4;
  abStack_180[1] = 1;
  abStack_180[2] = 0;
  abStack_180[3] = 0;
  pbStack_184 = abStack_168;
  puStack_188 = &DAT_00746cf4;
  puStack_18c = &DAT_00746e54;
  puStack_190 = &DAT_00746e7c;
  puStack_194 = (undefined1 *)0x40633b;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d80 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_180;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406373:
        DAT_007c0d80 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_0040638d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406373;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d80 = 0;
  }
LAB_0040638d:
  puStack_194 = &DAT_007c0720;
  abStack_198[0] = 4;
  abStack_198[1] = 1;
  abStack_198[2] = 0;
  abStack_198[3] = 0;
  pbStack_19c = abStack_180;
  puStack_1a0 = &DAT_00746cf4;
  puStack_1a4 = &DAT_00746e4c;
  puStack_1a8 = &DAT_00746e7c;
  puStack_1ac = (undefined1 *)0x4063ad;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d84 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_198;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_004063eb:
        DAT_007c0d84 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406405;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_004063eb;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d84 = 0;
  }
LAB_00406405:
  puStack_1ac = &DAT_007c0720;
  abStack_1b0[0] = 4;
  abStack_1b0[1] = 1;
  abStack_1b0[2] = 0;
  abStack_1b0[3] = 0;
  pbStack_1b4 = abStack_198;
  puStack_1b8 = &DAT_00746cf4;
  puStack_1bc = &DAT_00746e40;
  puStack_1c0 = &DAT_00746e38;
  puStack_1c4 = (undefined1 *)0x406425;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c13a4 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_1b0;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0040645d:
        DAT_007c13a4 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406477;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0040645d;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c13a4 = 0;
  }
LAB_00406477:
  puStack_1c4 = &DAT_007c0720;
  uStack_1c8 = 0x104;
  pbStack_1cc = abStack_1b0;
  puStack_1d0 = &DAT_00746cf4;
  puStack_1d4 = &DAT_00746e30;
  puStack_1d8 = &DAT_00746e38;
  puStack_1dc = (undefined4 *)0x406497;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 != 0) {
    puStack_1dc = &uStack_1c8;
    uStack_1e0 = 0x4064a5;
    DAT_007ab0d8 = FUN_00631bbc();
  }
  puStack_1dc = (undefined4 *)&DAT_007c0720;
  uStack_1e0 = 0x104;
  puStack_1e4 = &uStack_1c8;
  puStack_1e8 = &DAT_00746cf4;
  puStack_1ec = &DAT_00746e28;
  puStack_1f0 = &DAT_00746e38;
  puStack_1f4 = (undefined4 *)0x4064cd;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 != 0) {
    puStack_1f4 = &uStack_1e0;
    uStack_1f8 = 0x4064db;
    DAT_007ab0dc = FUN_00631bbc();
  }
  _DAT_007ab0f4 = _DAT_00746e24;
  if (DAT_007ab0d8 == 800) {
    if (DAT_007ab0dc == 600) {
      DAT_007c0dfc = 0;
    }
    else {
LAB_00406591:
      DAT_007c0dfc = 1;
    }
  }
  else {
    if (DAT_007ab0d8 == 0x400) goto LAB_00406591;
    if (DAT_007ab0d8 == 0x500) {
      if (DAT_007ab0dc == 0x400) {
        DAT_007c0dfc = 2;
      }
      else if (DAT_007ab0dc == 0x2d0) {
        DAT_007c0dfc = 6;
        _DAT_007ab0f4 = 0x3fe38e39;
      }
      else if (DAT_007ab0dc == 0x3c0) {
        DAT_007c0dfc = 9;
        _DAT_007ab0f4 = 0x3faaaaab;
      }
      else {
        if (DAT_007ab0dc != 800) goto LAB_00406591;
        DAT_007c0dfc = 0xc;
        _DAT_007ab0f4 = 0x3fcccccd;
      }
    }
    else if (DAT_007ab0d8 == 0x550) {
      if (DAT_007ab0dc != 0x300) goto LAB_00406591;
      DAT_007c0dfc = 3;
      _DAT_007ab0f4 = 0x3fe2aaab;
    }
    else if (DAT_007ab0d8 == 0x780) {
      if (DAT_007ab0dc == 0x4b0) {
        DAT_007c0dfc = 4;
        _DAT_007ab0f4 = 0x3fcccccd;
      }
      else {
        if (DAT_007ab0dc != 0x438) goto LAB_00406591;
        DAT_007c0dfc = 0xb;
        _DAT_007ab0f4 = 0x3fe38e39;
      }
    }
    else if (DAT_007ab0d8 == 0x690) {
      if (DAT_007ab0dc != 0x41a) goto LAB_00406591;
      DAT_007c0dfc = 5;
      _DAT_007ab0f4 = 0x3fcccccd;
    }
    else if (DAT_007ab0d8 == 0x640) {
      if (DAT_007ab0dc == 900) {
        DAT_007c0dfc = 7;
        _DAT_007ab0f4 = 0x3fe38e39;
      }
      else if (DAT_007ab0dc == 0x4b0) {
        DAT_007c0dfc = 10;
        _DAT_007ab0f4 = 0x3faaaaab;
      }
      else {
        if (DAT_007ab0dc != 0x400) goto LAB_00406591;
        DAT_007c0dfc = 0xd;
        _DAT_007ab0f4 = 0x3fc80000;
      }
    }
    else {
      if ((DAT_007ab0d8 != 0x480) || (DAT_007ab0dc != 0x360)) goto LAB_00406591;
      DAT_007c0dfc = 8;
      _DAT_007ab0f4 = 0x3faaaaab;
    }
  }
  puStack_1f4 = (undefined4 *)&DAT_007c0720;
  uStack_1f8 = 0x104;
  puStack_1fc = &uStack_1e0;
  puStack_200 = &DAT_00746cf4;
  puStack_204 = &DAT_00746e1c;
  puStack_208 = &DAT_00746e38;
  puStack_20c = (undefined4 *)0x40653e;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d9c = 1;
  }
  else {
    puStack_20c = &uStack_1f8;
    uStack_210 = 0x406550;
    iVar2 = FUN_00631bbc();
    DAT_007c0d9c = (uint)(iVar2 != 0x10);
    if ((DAT_022fe6bc == 6) && (DAT_022fe6c0 == 2)) {
      DAT_007c0d9c = 1;
    }
  }
  puStack_20c = (undefined4 *)&DAT_007c0720;
  uStack_210 = 0x104;
  puStack_214 = &uStack_1f8;
  puStack_218 = &DAT_00746cf4;
  puStack_21c = &DAT_00746e10;
  puStack_220 = &DAT_00746e38;
  puStack_224 = (undefined4 *)0x4067a3;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0e00 = 2;
  }
  else {
    puStack_224 = &uStack_210;
    uStack_228 = 0x4067b1;
    DAT_007c0e00 = FUN_00631bbc();
  }
  puStack_224 = (undefined4 *)&DAT_007c0720;
  uStack_228 = 0x104;
  puStack_22c = &uStack_210;
  puStack_230 = &DAT_00746cf4;
  puStack_234 = &DAT_00746e08;
  puStack_238 = &DAT_00746e38;
  puStack_23c = (undefined4 *)0x4067e1;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0e08 = 2;
  }
  else {
    puStack_23c = &uStack_228;
    abStack_240[0] = 0xef;
    abStack_240[1] = 0x67;
    abStack_240[2] = 0x40;
    abStack_240[3] = 0;
    DAT_007c0e08 = FUN_00631bbc();
  }
  puStack_23c = (undefined4 *)&DAT_007c0720;
  abStack_240[0] = 4;
  abStack_240[1] = 1;
  abStack_240[2] = 0;
  abStack_240[3] = 0;
  puStack_244 = &uStack_228;
  puStack_248 = &DAT_00746cf4;
  puStack_24c = &DAT_00746e00;
  puStack_250 = &DAT_00746e38;
  puStack_254 = (undefined1 *)0x40681f;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
LAB_004068d0:
    puStack_254 = (undefined1 *)0x1;
    DAT_007c0e04 = 1;
LAB_004068d7:
    abStack_258[0] = 0xe1;
    abStack_258[1] = 0x68;
    abStack_258[2] = 0x40;
    abStack_258[3] = 0;
    FUN_00405ff0();
  }
  else {
    pbVar4 = &DAT_00746df8;
    pbVar3 = abStack_240;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0040684e:
        iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_00406853;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0040684e;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_00406853:
    if (iVar2 == 0) {
      DAT_007c0e04 = 2;
      puStack_254 = (undefined1 *)0x2;
      goto LAB_004068d7;
    }
    pbVar4 = &DAT_00746df0;
    pbVar3 = abStack_240;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0040688e:
        iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_00406893;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0040688e;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_00406893:
    if (iVar2 == 0) goto LAB_004068d0;
    pbVar4 = &DAT_00746dec;
    pbVar3 = abStack_240;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_004068be:
        iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_004068c3;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_004068be;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_004068c3:
    if (iVar2 == 0) {
      DAT_007c0e04 = 0;
      puStack_254 = (undefined1 *)0x0;
      goto LAB_004068d7;
    }
  }
  puStack_254 = &DAT_007c0720;
  abStack_258[0] = 4;
  abStack_258[1] = 1;
  abStack_258[2] = 0;
  abStack_258[3] = 0;
  pbStack_25c = abStack_240;
  puStack_260 = &DAT_00746cf4;
  puStack_264 = &DAT_00746de4;
  puStack_268 = &DAT_00746e38;
  puStack_26c = (undefined1 *)0x406901;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 != 0) {
    pbVar4 = &DAT_00746df8;
    pbVar3 = abStack_258;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406930:
        iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_00406935;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406930;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_00406935:
    if (iVar2 != 0) {
      pbVar4 = &DAT_00746df0;
      pbVar3 = abStack_258;
      do {
        bVar1 = *pbVar3;
        bVar5 = bVar1 < *pbVar4;
        if (bVar1 != *pbVar4) {
LAB_00406964:
          iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
          goto LAB_00406969;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar5 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_00406964;
        pbVar3 = pbVar3 + 2;
        pbVar4 = pbVar4 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_00406969:
      if (iVar2 == 0) {
        DAT_007c0e0c = 1;
        DAT_007c0dcc = 0x80;
      }
      else {
        pbVar4 = &DAT_00746dec;
        pbVar3 = abStack_258;
        do {
          bVar1 = *pbVar3;
          bVar5 = bVar1 < *pbVar4;
          if (bVar1 != *pbVar4) {
LAB_004069a6:
            iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
            goto LAB_004069ab;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar5 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_004069a6;
          pbVar3 = pbVar3 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_004069ab:
        if (iVar2 == 0) {
          DAT_007c0e0c = 0;
          DAT_007c0dcc = 0x40;
        }
      }
      goto LAB_004069d1;
    }
  }
  DAT_007c0e0c = 2;
  DAT_007c0dcc = 0xffffffff;
LAB_004069d1:
  puStack_26c = &DAT_007c0720;
  abStack_270[0] = 4;
  abStack_270[1] = 1;
  abStack_270[2] = 0;
  abStack_270[3] = 0;
  pbStack_274 = abStack_258;
  puStack_278 = &DAT_00746cf4;
  puStack_27c = &DAT_00746ddc;
  puStack_280 = &DAT_00746e38;
  puStack_284 = (undefined1 *)0x4069f1;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d90 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_270;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406a2b:
        DAT_007c0d90 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406a45;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406a2b;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d90 = 0;
  }
LAB_00406a45:
  puStack_284 = &DAT_007c0720;
  abStack_288[0] = 4;
  abStack_288[1] = 1;
  abStack_288[2] = 0;
  abStack_288[3] = 0;
  pbStack_28c = abStack_270;
  puStack_290 = &DAT_00746cf4;
  puStack_294 = &DAT_00746dd4;
  puStack_298 = &DAT_00746e38;
  puStack_29c = (undefined1 *)0x406a65;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0d8c = 0;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_288;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406a9d:
        DAT_007c0d8c = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406ab7;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406a9d;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0d8c = 0;
  }
LAB_00406ab7:
  puStack_29c = &DAT_007c0720;
  abStack_2a0[0] = 4;
  abStack_2a0[1] = 1;
  abStack_2a0[2] = 0;
  abStack_2a0[3] = 0;
  pbStack_2a4 = abStack_288;
  puStack_2a8 = &DAT_00746cf4;
  puStack_2ac = &DAT_00746dcc;
  puStack_2b0 = &DAT_00746e38;
  puStack_2b4 = (undefined1 *)0x406ad7;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0e10 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_2a0;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406b0f:
        DAT_007c0e10 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406b29;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406b0f;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0e10 = 0;
  }
LAB_00406b29:
  puStack_2b4 = &DAT_007c0720;
  abStack_2b8[0] = 4;
  abStack_2b8[1] = 1;
  abStack_2b8[2] = 0;
  abStack_2b8[3] = 0;
  pbStack_2bc = abStack_2a0;
  puStack_2c0 = &DAT_00746cf4;
  puStack_2c4 = &DAT_00746dc4;
  puStack_2c8 = &DAT_00746e38;
  puStack_2cc = (undefined1 *)0x406b49;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0e14 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_2b8;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406b81:
        DAT_007c0e14 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406b9b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406b81;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0e14 = 0;
  }
LAB_00406b9b:
  puStack_2cc = &DAT_007c0720;
  abStack_2d0[0] = 4;
  abStack_2d0[1] = 1;
  abStack_2d0[2] = 0;
  abStack_2d0[3] = 0;
  pbStack_2d4 = abStack_2b8;
  puStack_2d8 = &DAT_00746cf4;
  puStack_2dc = &DAT_00746db8;
  puStack_2e0 = &DAT_00746e38;
  puStack_2e4 = (undefined1 *)0x406bbb;
  iVar2 = GetPrivateProfileStringA();
  if (iVar2 == 0) {
    DAT_007c0e18 = 1;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_2d0;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406bf3:
        DAT_007c0e18 = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406c0d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406bf3;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0e18 = 0;
  }
LAB_00406c0d:
  puStack_2e4 = &DAT_007c0720;
  abStack_2e8[0] = 4;
  abStack_2e8[1] = 1;
  abStack_2e8[2] = 0;
  abStack_2e8[3] = 0;
  iVar2 = GetPrivateProfileStringA(&DAT_00746e38,&DAT_00746da8,&DAT_00746cf4,abStack_2d0);
  if (iVar2 == 0) {
    DAT_007c0e1c = 0;
  }
  else {
    pbVar4 = &DAT_00746e74;
    pbVar3 = abStack_2e8;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00406c6b:
        DAT_007c0e1c = (uint)(1 - bVar5 != (uint)(bVar5 != 0));
        goto LAB_00406c85;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00406c6b;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    DAT_007c0e1c = 0;
  }
LAB_00406c85:
  FUN_00630c8a();
  return;
}

