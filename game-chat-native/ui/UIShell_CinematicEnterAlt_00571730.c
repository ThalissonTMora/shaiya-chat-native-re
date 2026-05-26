/*
 * Game.exe — UIShell_CinematicEnterAlt
 * Requested VA: 0x00571730
 * Entry Ghidra:  00571730
 * Ghidra name:   FUN_00571730
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined __fastcall FUN_00571730(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  char cVar3;
  undefined uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  undefined4 *puVar10;
  float10 fVar11;
  undefined *puVar12;
  int *piVar13;
  undefined4 uVar14;
  float afStack_2cc [3];
  undefined *puStack_2c0;
  int *piStack_2bc;
  float fStack_2b8;
  float fStack_2b4;
  float fStack_2b0;
  float fStack_2ac;
  float fStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float afStack_29c [3];
  undefined auStack_290 [4];
  undefined4 auStack_28c [15];
  undefined4 auStack_250 [4];
  undefined auStack_240 [560];
  undefined4 uStack_10;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_00738b2b;
  pvStack_c = ExceptionList;
  uVar5 = DAT_007b4dd0 ^ (uint)&stack0xfffffd24;
  ExceptionList = &pvStack_c;
  *(undefined *)(param_1 + 0x1d0) = 1;
  *(undefined *)(param_1 + 0x304) = 1;
  cVar3 = FUN_005705a0(*(undefined4 *)(param_1 + 0xf4));
  if (cVar3 == '\0') {
    *(undefined *)(param_1 + 0x1d0) = 0;
    uVar4 = 0;
  }
  else {
    fStack_2b8 = _DAT_022ba20c - _DAT_022ba200;
    afStack_2cc[1] = _DAT_022ba210 - _DAT_022ba204;
    fVar1 = -((_DAT_022ba214 - _DAT_022ba208) * 0.0 + afStack_2cc[1] + fStack_2b8 * 0.0);
    puStack_2c0 = (undefined *)(fVar1 + fVar1);
    afStack_2cc[0] = (float)puStack_2c0 * 0.0;
    fStack_2b4 = afStack_2cc[0] + fStack_2b8;
    fStack_2b0 = (float)puStack_2c0 + afStack_2cc[1];
    fStack_2ac = (_DAT_022ba214 - _DAT_022ba208) + afStack_2cc[0];
    afStack_2cc[2] = afStack_2cc[0];
    piStack_2bc = (int *)afStack_2cc[0];
    FUN_00440530(uVar5);
    fStack_2a4 = -_DAT_022ba204;
    fStack_2a8 = _DAT_022ba200;
    fStack_2a0 = _DAT_022ba208;
    afStack_2cc[0] = fStack_2b4 + _DAT_022ba200;
    afStack_2cc[1] = fStack_2a4 + fStack_2b0;
    fStack_2b8 = fStack_2ac + _DAT_022ba208;
    afStack_29c[0] = afStack_2cc[0];
    afStack_29c[1] = afStack_2cc[1];
    afStack_29c[2] = fStack_2b8;
    FUN_0065ab84(param_1 + 0xfc,&fStack_2a8,afStack_29c,&DAT_022ba218);
    uVar14 = 2;
    piVar13 = DAT_022b69a8;
    (**(code **)(*DAT_022b69a8 + 0xb0))(DAT_022b69a8,2,param_1 + 0xfc);
    FUN_00571550(&DAT_022ba200);
    _DAT_022ba200 = fStack_2b4;
    _DAT_022ba204 = fStack_2b0;
    uStack_10 = 0;
    _DAT_022ba208 = fStack_2ac;
    _DAT_022ba20c = fStack_2a8;
    _DAT_022ba210 = fStack_2a4;
    _DAT_022ba214 = fStack_2a0;
    _DAT_022ba224 = fStack_2a8 - fStack_2b4;
    _DAT_022ba228 = fStack_2a4 - fStack_2b0;
    _DAT_022ba22c = fStack_2a0 - fStack_2ac;
    afStack_2cc[2] = _DAT_022ba22c;
    puVar6 = (undefined4 *)FUN_00570730(afStack_29c);
    _DAT_022ba23c = *puVar6;
    _DAT_022ba240 = puVar6[1];
    _DAT_022ba244 = puVar6[2];
    fVar11 = (float10)FUN_00405ef0(0);
    FUN_005d3b80((float)fVar11);
    FUN_005d6700(&DAT_022ba200);
    uVar2 = DAT_022b6a7c;
    puVar6 = &DAT_022b69f0;
    puVar10 = auStack_250;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar10 = puVar10 + 1;
    }
    afStack_29c[1] = DAT_022b6a80;
    afStack_29c[2] = DAT_022b6a84;
    puStack_2c0 = DAT_022b6a70;
    piStack_2bc = DAT_022b6a74;
    fStack_2b8 = DAT_022b6a78;
    DAT_022b6a7c = fStack_2a8;
    afStack_2cc[0] = fStack_2b0;
    DAT_022b6a84 = fStack_2a0;
    DAT_022b6a80 = fStack_2a4;
    afStack_2cc[1] = fStack_2ac;
    DAT_022b6a78 = fStack_2ac;
    DAT_022b6a70 = (undefined *)fStack_2b4;
    puVar12 = auStack_290;
    DAT_022b6a74 = (int *)fStack_2b0;
    (**(code **)(*DAT_022b6dc4 + 0xb4))(DAT_022b6dc4,2);
    pfVar8 = afStack_29c;
    pfVar9 = (float *)&DAT_022b69f0;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar9 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      pfVar9 = pfVar9 + 1;
    }
    FUN_0056f850();
    (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,0x98,1);
    (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,0x1c,0);
    FUN_0057e6b0();
    (**(code **)(*DAT_022b69a8 + 0xe4))(DAT_022b69a8,0x1c,1);
    FUN_00454700();
    FUN_00570c50();
    FUN_00571640(auStack_240);
    fVar11 = (float10)FUN_00405ef0(0);
    FUN_005d3b80((float)fVar11);
    DAT_022b6a78 = (float)uVar14;
    DAT_022b6a74 = piVar13;
    DAT_022b6a70 = puVar12;
    DAT_022b6a80 = afStack_2cc[1];
    DAT_022b6a84 = afStack_2cc[2];
    DAT_022b6a7c = (float)uVar2;
    FUN_00573470(_DAT_007ab0f0,_DAT_007c0d98,_DAT_007c0d94);
    (**(code **)(*DAT_022b6dc4 + 0xb4))(DAT_022b6dc4,3,&puStack_2c0);
    piVar13 = DAT_022b69a8;
    pfVar8 = afStack_2cc;
    pfVar9 = (float *)&DAT_022b6a30;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar9 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      pfVar9 = pfVar9 + 1;
    }
    puVar6 = auStack_28c;
    puVar10 = &DAT_022b69f0;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar10 = puVar10 + 1;
    }
    (**(code **)(*piVar13 + 0xe4))(piVar13,0x98,0);
    FUN_00570660();
    *(undefined *)(param_1 + 0x1d0) = 0;
    uStack_4 = 0xffffffff;
    FUN_005d32e0();
    uVar4 = 1;
  }
  ExceptionList = pvStack_c;
  return uVar4;
}

