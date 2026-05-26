/*
 * Game.exe — ChatNotify_vfn_0x31C
 * VA solicitado: 0x00595690
 * Entry Ghidra:  00595690
 * Ghidra name:   FUN_00595690
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: vtable
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595690(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_00452c00(param_2);
  if (iVar4 == 0) {
    iVar4 = FUN_00452b10(param_3);
    if (iVar4 != 0) {
      FUN_004e7630(iVar4 + 0x158,param_4);
      FUN_00459d30(iVar4 + 0x10,_DAT_00746d18,param_4,param_1,0,0,*(undefined4 *)(iVar4 + 0x34));
      FUN_0041cad0();
      return;
    }
  }
  else {
    FUN_0043bc30();
    *(undefined2 *)(iVar4 + 0xc0) = (undefined2)param_4;
    *(undefined *)(iVar4 + 0xc6) = (undefined)param_1;
    *(undefined *)(iVar4 + 0xb9) = 1;
    *(undefined *)(iVar4 + 0xb8) = 1;
    *(undefined4 *)(iVar4 + 0x78) = 1;
    *(undefined4 *)(iVar4 + 0xbc) = param_3;
    *(undefined4 *)(iVar4 + 0x80) = 2;
    *(undefined4 *)(iVar4 + 0x74) = 2;
    iVar5 = FUN_00452b10(param_3);
    if (((iVar5 != 0) && (*(int *)(iVar4 + 0xb4) == 0)) &&
       (((NAN(*(float *)(iVar5 + 0x10)) || NAN(*(float *)(iVar4 + 0x38))) ==
         (*(float *)(iVar5 + 0x10) == *(float *)(iVar4 + 0x38)) ||
        ((NAN(*(float *)(iVar5 + 0x18)) || NAN(*(float *)(iVar4 + 0x40))) ==
         (*(float *)(iVar5 + 0x18) == *(float *)(iVar4 + 0x40)))))) {
      pfVar1 = (float *)(iVar4 + 0x98);
      fVar2 = *(float *)(iVar5 + 0x14);
      fVar3 = *(float *)(iVar5 + 0x18);
      *pfVar1 = *(float *)(iVar5 + 0x10) - *(float *)(iVar4 + 0x38);
      *(float *)(iVar4 + 0x9c) = fVar2 - *(float *)(iVar4 + 0x3c);
      *(float *)(iVar4 + 0xa0) = fVar3 - *(float *)(iVar4 + 0x40);
      *(undefined4 *)(iVar4 + 0x9c) = 0;
      thunk_FUN_006587f1(pfVar1,pfVar1);
    }
  }
  return;
}

