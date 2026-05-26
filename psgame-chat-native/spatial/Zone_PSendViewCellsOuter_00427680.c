/*
 * server/ps_game.exe — Zone_PSendViewCellsOuter
 * VA solicitado: 0x00427680
 * Entry Ghidra:  00427680
 * Ghidra name:   FUN_00427680
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: spatial
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00427680(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  LONG LVar4;
  int iVar5;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = param_4;
  param_4 = FUN_005250c0();
  local_4 = FUN_005250c0();
  iVar2 = FUN_005250c0();
  local_8 = FUN_005250c0();
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (*(int *)(param_1 + 0x2c) <= local_4) {
    local_4 = *(int *)(param_1 + 0x2c) + -1;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (*(int *)(param_1 + 0x30) <= local_8) {
    local_8 = *(int *)(param_1 + 0x30) + -1;
  }
  iVar3 = FUN_004f3dc0(param_2,param_3);
  if (iVar3 != 0) {
    for (; iVar2 <= local_8; iVar2 = iVar2 + 1) {
      if (param_4 <= local_4) {
        iVar5 = (local_4 - param_4) + 1;
        do {
          FUN_0042ae60(iVar3,uVar1,param_5,param_6);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    LVar4 = InterlockedDecrement((LONG *)(iVar3 + 8));
    if (LVar4 == 0) {
      FUN_004f33a0(iVar3);
    }
  }
  return;
}

