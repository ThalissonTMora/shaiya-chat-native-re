/*
 * Game.exe — Crypto_OutputPack
 * Requested VA: 0x00405050
 * Entry Ghidra:  00405050
 * Ghidra name:   FUN_00405050
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void FUN_00405050(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 uStack_18;
  int iStack_14;
  int iStack_10;
  undefined auStack_c [4];
  int iStack_8;
  undefined4 uStack_4;
  
  FUN_005be350(auStack_c);
  FUN_005be350(&uStack_18);
  if (iStack_14 < 0x20) {
    iStack_10 = FUN_00637c72(iStack_10,0x80);
    uStack_18 = 0x21;
  }
  iStack_14 = 0x20;
  *(undefined4 *)(iStack_10 + 0x7c) = 0;
  *(undefined4 *)(iStack_10 + 0x78) = 0;
  FUN_00631300(iStack_10,param_3,0x80);
  FUN_005be750(auStack_c,&uStack_18);
  *param_2 = iStack_8 * 4;
  FUN_00631300(param_1,uStack_4,iStack_8 * 4);
  FUN_005be590(auStack_c);
  FUN_005be590(&uStack_18);
  return;
}

