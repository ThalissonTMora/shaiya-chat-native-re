/*
 * Game.exe — Crypto_KeyMaterialAppend
 * Requested VA: 0x00404F90
 * Entry Ghidra:  00404f90
 * Ghidra name:   FUN_00404f90
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void FUN_00404f90(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int unaff_EBX;
  int *unaff_ESI;
  int iVar2;
  
  iVar2 = unaff_EBX >> 2;
  if (unaff_EBX != iVar2 * 4) {
    iVar2 = iVar2 + 1;
  }
  if (unaff_ESI[1] < iVar2) {
    iVar1 = FUN_00637c72(unaff_ESI[2],iVar2 * 4);
    unaff_ESI[2] = iVar1;
    *unaff_ESI = iVar2 + 1;
  }
  unaff_ESI[1] = iVar2;
  *(undefined4 *)(unaff_ESI[2] + -4 + iVar2 * 4) = 0;
  *(undefined4 *)(unaff_ESI[2] + -8 + iVar2 * 4) = 0;
  FUN_00631300(unaff_ESI[2],param_1);
  iVar2 = param_3 >> 2;
  if (param_3 != iVar2 * 4) {
    iVar2 = iVar2 + 1;
  }
  if (unaff_ESI[4] < iVar2) {
    iVar1 = FUN_00637c72(unaff_ESI[5],iVar2 * 4);
    unaff_ESI[5] = iVar1;
    unaff_ESI[3] = iVar2 + 1;
  }
  unaff_ESI[4] = iVar2;
  *(undefined4 *)(unaff_ESI[5] + -4 + iVar2 * 4) = 0;
  *(undefined4 *)(unaff_ESI[5] + -8 + iVar2 * 4) = 0;
  FUN_00631300(unaff_ESI[5],param_2,param_3);
  return;
}

