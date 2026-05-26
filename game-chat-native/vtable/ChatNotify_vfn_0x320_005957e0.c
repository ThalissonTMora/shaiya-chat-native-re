/*
 * Game.exe — ChatNotify_vfn_0x320
 * Requested VA: 0x005957E0
 * Entry Ghidra:  005957e0
 * Ghidra name:   FUN_005957e0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: vtable
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005957e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_00452c00(param_2);
  if (iVar4 == 0) {
    iVar4 = FUN_00452b90(param_3);
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x58) = *(int *)(iVar4 + 0x58) - (param_4 & 0xffff);
      FUN_00459d30(iVar4 + 4,*(undefined4 *)(iVar4 + 0x8c),param_4,param_1,0,0,0);
      FUN_0043a810();
      return;
    }
  }
  else {
    FUN_0043bc30();
    *(undefined2 *)(iVar4 + 0xc0) = (undefined2)param_4;
    *(undefined4 *)(iVar4 + 0x80) = 2;
    *(undefined4 *)(iVar4 + 0x74) = 2;
    *(undefined *)(iVar4 + 0xb9) = 1;
    *(undefined *)(iVar4 + 0xb8) = 0;
    *(undefined4 *)(iVar4 + 0xbc) = param_3;
    *(undefined *)(iVar4 + 0xc6) = (undefined)param_1;
    *(undefined4 *)(iVar4 + 0x78) = 1;
    if (*(int *)(iVar4 + 100) != 0) {
      if (*(int *)(*(int *)(iVar4 + 100) + 0x104) == 0) {
        return;
      }
      FUN_0056cfb0(*(int *)(iVar4 + 0xa4) + 0xf0,0,iVar4 + 0x38,_DAT_00747454);
    }
    iVar5 = FUN_00452b90(param_3);
    if (((iVar5 != 0) && (*(int *)(iVar4 + 0xb4) == 0)) &&
       (((NAN(*(float *)(iVar5 + 4)) || NAN(*(float *)(iVar4 + 0x38))) ==
         (*(float *)(iVar5 + 4) == *(float *)(iVar4 + 0x38)) ||
        ((NAN(*(float *)(iVar5 + 0xc)) || NAN(*(float *)(iVar4 + 0x40))) ==
         (*(float *)(iVar5 + 0xc) == *(float *)(iVar4 + 0x40)))))) {
      pfVar1 = (float *)(iVar4 + 0x98);
      fVar2 = *(float *)(iVar5 + 8);
      fVar3 = *(float *)(iVar5 + 0xc);
      *pfVar1 = *(float *)(iVar5 + 4) - *(float *)(iVar4 + 0x38);
      *(float *)(iVar4 + 0x9c) = fVar2 - *(float *)(iVar4 + 0x3c);
      *(float *)(iVar4 + 0xa0) = fVar3 - *(float *)(iVar4 + 0x40);
      *(undefined4 *)(iVar4 + 0x9c) = 0;
      thunk_FUN_006587f1(pfVar1,pfVar1);
    }
  }
  return;
}

