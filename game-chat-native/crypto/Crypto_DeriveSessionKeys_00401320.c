/*
 * Game.exe — Crypto_DeriveSessionKeys
 * Requested VA: 0x00401320
 * Entry Ghidra:  00401320
 * Ghidra name:   FUN_00401320
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401320(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [4];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = _DAT_007b4dd0 ^ (uint)auStack_24;
  FUN_00404390(&DAT_023027c0);
  if (_DAT_023037e0 == 0) {
    _DAT_023038e4 = auStack_24[0];
    _DAT_023038e8 = auStack_24[1];
    _DAT_023038ec = auStack_24[2];
    _DAT_023038f0 = auStack_24[3];
    _DAT_023038f4 = 0;
    _DAT_02303a34 = auStack_24[0];
    _DAT_02303a38 = auStack_24[1];
    _DAT_02303a3c = auStack_24[2];
    _DAT_02303a40 = auStack_24[3];
    _DAT_02303a44 = 0;
  }
  else {
    uStack_10 = auStack_24[1];
    uStack_14 = auStack_24[0];
    auStack_24[0] = _DAT_023027d0;
    uStack_c = auStack_24[2];
    uStack_8 = auStack_24[3];
    auStack_24[3] = _DAT_023027dc;
    auStack_24[1] = _DAT_023027d4;
    auStack_24[2] = _DAT_023027d8;
    puVar2 = auStack_24;
    puVar3 = (undefined4 *)0x2303908;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00401500();
    puVar2 = auStack_24;
    puVar3 = (undefined4 *)0x2303a58;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    _DAT_02303938 = 0;
    FUN_00401500();
    _DAT_02303a88 = 0;
  }
  _DAT_023027c0 = 0;
  _DAT_023027c4 = 0;
  _DAT_023027c8 = 0;
  _DAT_023027cc = 0;
  _DAT_023027d0 = 0;
  _DAT_023027d4 = 0;
  _DAT_023027d8 = 0;
  _DAT_023027dc = 0;
  FUN_00630c8a();
  return;
}

