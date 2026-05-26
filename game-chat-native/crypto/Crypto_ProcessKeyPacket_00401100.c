/*
 * Game.exe — Crypto_ProcessKeyPacket
 * Requested VA: 0x00401100
 * Entry Ghidra:  00401100
 * Ghidra name:   FUN_00401100
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401100(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined auStack_dc [4];
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined auStack_c8 [12];
  undefined auStack_bc [12];
  undefined4 auStack_b0 [4];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined auStack_90 [127];
  byte bStack_11;
  uint uStack_c;
  
  uStack_c = DAT_007b4dd0 ^ (uint)auStack_dc;
  uStack_d8 = param_1;
  uStack_d0 = param_2;
  uStack_cc = param_4;
  uStack_d4 = param_6;
  DAT_023037e0 = param_3;
  FUN_00404610();
  bStack_11 = bStack_11 & 0x7f;
  FUN_00404420(auStack_90,param_7);
  if (param_3 == 0) {
    FUN_00404680();
    FUN_00404680();
    _DAT_023027c0 = uStack_a0;
    _DAT_023027c4 = uStack_9c;
    _DAT_023027c8 = uStack_98;
    _DAT_023027cc = uStack_94;
    _DAT_023038e4 = uStack_a0;
    _DAT_023038e8 = uStack_9c;
    _DAT_023038ec = uStack_98;
    _DAT_023038f0 = uStack_94;
    _DAT_023038f4 = 0;
    _DAT_02303a34 = uStack_a0;
    _DAT_02303a38 = uStack_9c;
    _DAT_02303a3c = uStack_98;
    _DAT_02303a40 = uStack_94;
    _DAT_02303a44 = 0;
  }
  else {
    _DAT_023027c8 = uStack_98;
    _DAT_023027c0 = uStack_a0;
    _DAT_023027c4 = uStack_9c;
    DAT_023027d4 = auStack_b0[1];
    _DAT_023027cc = uStack_94;
    DAT_023027d0 = auStack_b0[0];
    puVar2 = auStack_b0;
    puVar3 = &DAT_02303908;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_023027d8 = auStack_b0[2];
    DAT_023027dc = auStack_b0[3];
    FUN_00401500();
    puVar2 = auStack_b0;
    puVar3 = &DAT_02303a58;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    _DAT_02303938 = 0;
    FUN_00401500();
    _DAT_02303a88 = 0;
    param_6 = uStack_d4;
  }
  FUN_005be350(auStack_c8);
  FUN_005be350(auStack_bc);
  FUN_00404f90(uStack_cc,param_6,param_7);
  FUN_00405050(uStack_d8,uStack_d0,auStack_90);
  FUN_005be590(auStack_c8);
  FUN_005be590(auStack_bc);
  FUN_00630c8a();
  return;
}

