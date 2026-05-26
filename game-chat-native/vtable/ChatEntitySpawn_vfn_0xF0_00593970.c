/*
 * unknown.exe — ChatEntitySpawn_vfn_0xF0
 * Requested VA: 0x00593970
 * Entry Ghidra:  00593970
 * Ghidra name:   FUN_00593970
 * MD5: unknown
 * ImageBase: 0x00400000
 * Category: vtable
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00593970(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined uVar4;
  undefined uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  bool bVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  bool bVar16;
  float *pfVar17;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  FUN_004e4ef0(param_1,param_2);
  FUN_004e4f30(param_1,param_3);
  iVar11 = FUN_00452b10(param_2);
  iVar12 = FUN_00452b10(param_3);
  bVar9 = false;
  if (iVar11 == 0) {
    uVar14 = FUN_00452b10(param_3);
    if (uVar14 != 0) {
      if ((short)param_4 != 0) {
        FUN_004e7630(uVar14 + 0x158,param_4);
        FUN_00459d30(uVar14 + 0x10,_DAT_00746d18,param_4,param_1,0,0,*(undefined4 *)(uVar14 + 0x34))
        ;
      }
      if ((short)param_5 != 0) {
        FUN_004e7630(uVar14 + 0x168,param_5);
        FUN_00459d30(uVar14 + 0x10,_DAT_00746d18,param_5,param_1,0,0,*(undefined4 *)(uVar14 + 0x34))
        ;
      }
      if ((short)param_6 != 0) {
        FUN_004e7630(uVar14 + 0x160,param_6);
        FUN_00459d30(uVar14 + 0x10,_DAT_00746d18,param_6,param_1,0,0,*(undefined4 *)(uVar14 + 0x34))
        ;
      }
      uVar14 = FUN_0041cad0();
    }
  }
  else {
    *(undefined4 *)(iVar11 + 0x3cc) = 2;
    *(undefined4 *)(iVar11 + 0x3d0) = param_3;
    iVar13 = FUN_004e8410(*(undefined *)(iVar11 + 0x1ad));
    bVar16 = *(int *)(iVar11 + 0x2d0) == 0;
    bVar9 = bVar16 && iVar13 != 0;
    if (DAT_0090e2f4 == *(int *)(iVar11 + 0x34)) {
      if ((iVar12 != 0) &&
         (iVar13 = FUN_00440aa0(*(undefined4 *)(iVar11 + 0x10),*(undefined4 *)(iVar11 + 0x14),
                                *(undefined4 *)(iVar11 + 0x18),*(undefined4 *)(iVar12 + 0x10),
                                *(undefined4 *)(iVar12 + 0x14),*(undefined4 *)(iVar12 + 0x18)),
         iVar13 == 0)) {
        FUN_004434d0();
      }
      DAT_022aa810 = 0;
      uVar14 = FUN_00593890(*(undefined *)(iVar11 + 0x1a0),param_1,bVar9);
      if (uVar14 != 0) {
        return uVar14;
      }
    }
    else {
      *(undefined4 *)(iVar11 + 0x330) = 0xffffffff;
      *(undefined4 *)(iVar11 + 0x32c) = 0;
      if ((!bVar16 || iVar13 == 0) && (iVar12 != 0)) {
        *(undefined4 *)(iVar11 + 0x330) = param_3;
        *(undefined4 *)(iVar11 + 0x32c) = 1;
      }
    }
    *(undefined4 *)(iVar11 + 0xf8) = 2;
    uVar15 = FUN_004e9350(*(undefined *)(iVar11 + 0x1ad));
    if (*(int *)(iVar11 + 0x2d0) == 0) {
      *(undefined4 *)(iVar11 + 0xec) = uVar15;
      *(undefined4 *)(iVar11 + 0xf0) = 1;
    }
    else {
      uVar14 = FUN_00632035();
      uVar14 = uVar14 & 0x80000001;
      if ((int)uVar14 < 0) {
        uVar14 = (uVar14 - 1 | 0xfffffffe) + 1;
      }
      *(uint *)(*(int *)(iVar11 + 0x2d0) + 0x40) = uVar14 + 2;
      *(undefined4 *)(*(int *)(iVar11 + 0x2d0) + 0x44) = 1;
    }
    FUN_0041abc0();
    *(undefined *)(iVar11 + 0x1e9) = 1;
    *(undefined *)(iVar11 + 0x1ea) = 1;
    *(undefined4 *)(iVar11 + 0x1ec) = param_3;
    *(short *)(iVar11 + 0x1f0) = (short)param_4;
    *(short *)(iVar11 + 0x1f2) = (short)param_5;
    *(short *)(iVar11 + 500) = (short)param_6;
    *(char *)(iVar11 + 0x1fc) = (char)param_1;
    uVar15 = timeGetTime();
    *(undefined4 *)(iVar11 + 0x1dc) = uVar15;
    iVar13 = FUN_00632035();
    uVar14 = iVar13 / 10;
    if (((char)param_1 == '\x01') || (iVar13 % 10 < 3)) {
      uVar14 = FUN_004153c0();
    }
  }
  if (iVar12 == 0) {
    return uVar14;
  }
  if (iVar11 == 0) {
    return uVar14;
  }
  pfVar17 = (float *)(iVar11 + 0x10);
  if ((NAN(*(float *)(iVar12 + 0x10)) || NAN(*(float *)(iVar11 + 0x10))) !=
      (*(float *)(iVar12 + 0x10) == *(float *)(iVar11 + 0x10))) {
    fVar2 = *(float *)(iVar11 + 0x18);
    fVar3 = *(float *)(iVar12 + 0x18);
    uVar14 = (uint)(ushort)((ushort)(fVar3 < fVar2) << 8 | (ushort)(NAN(fVar3) || NAN(fVar2)) << 10
                           | (ushort)(fVar3 == fVar2) << 0xe);
    if ((NAN(fVar3) || NAN(fVar2)) != (fVar3 == fVar2)) goto LAB_00593ce1;
  }
  pfVar1 = (float *)(iVar11 + 0x17c);
  fStack_c = *(float *)(iVar12 + 0x10) - *pfVar17;
  fStack_8 = *(float *)(iVar12 + 0x14) - *(float *)(iVar11 + 0x14);
  fStack_4 = *(float *)(iVar12 + 0x18) - *(float *)(iVar11 + 0x18);
  *pfVar1 = fStack_c;
  *(float *)(iVar11 + 0x180) = fStack_8;
  *(float *)(iVar11 + 0x184) = fStack_4;
  *(undefined4 *)(iVar11 + 0x180) = 0;
  uVar14 = FUN_00658804(pfVar1,pfVar1);
LAB_00593ce1:
  if (bVar9) {
    uVar4 = *(undefined *)(iVar11 + 0x1ad);
    uVar5 = *(undefined *)(iVar11 + 0x1be);
    cVar10 = FUN_004e5630(uVar4);
    if (cVar10 == '\v') {
      uVar14 = FUN_0045cba0(uVar5,0,0,0,pfVar17,uVar4,0,0,param_2,*(undefined *)(iVar11 + 0x1ea),
                            *(undefined2 *)(iVar11 + 0x1ec),*(undefined2 *)(iVar11 + 0x1f0),
                            *(undefined2 *)(iVar11 + 0x1f2),*(undefined *)(iVar11 + 500),
                            *(undefined *)(iVar11 + 0x1fc),0);
      return uVar14;
    }
    if (*(char *)(iVar11 + 0x2b8) == '\x01') {
      fStack_c = *pfVar17;
      fStack_4 = *(float *)(iVar11 + 0x18);
      uVar4 = *(undefined *)(iVar11 + 0x1fc);
      uVar6 = *(undefined2 *)(iVar11 + 0x1f0);
      uVar7 = *(undefined2 *)(iVar11 + 500);
      fStack_8 = *(float *)(iVar11 + 0x14) - (float)_DAT_007484f8;
      uVar15 = *(undefined4 *)(iVar11 + 0x1ec);
      uVar8 = *(undefined2 *)(iVar11 + 0x1f2);
      uVar5 = *(undefined *)(iVar11 + 0x1ea);
      pfVar17 = &fStack_c;
    }
    else {
      uVar4 = *(undefined *)(iVar11 + 0x1fc);
      uVar7 = *(undefined2 *)(iVar11 + 500);
      uVar8 = *(undefined2 *)(iVar11 + 0x1f2);
      uVar6 = *(undefined2 *)(iVar11 + 0x1f0);
      uVar15 = *(undefined4 *)(iVar11 + 0x1ec);
      uVar5 = *(undefined *)(iVar11 + 0x1ea);
    }
    uVar14 = FUN_0045cba0(0,0,0,0,pfVar17,0,0,param_2,uVar5,uVar15,uVar6,uVar8,uVar7,uVar4,0,0);
  }
  return uVar14;
}

