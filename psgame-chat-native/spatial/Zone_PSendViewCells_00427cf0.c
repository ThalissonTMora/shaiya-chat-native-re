/*
 * server/ps_game.exe — Zone_PSendViewCells
 * Requested VA: 0x00427CF0
 * Entry Ghidra:  00427cf0
 * Ghidra name:   FUN_00427cf0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: spatial
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00427cf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  LONG LVar3;
  int iVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = FUN_005250c0();
  local_4 = FUN_005250c0();
  iVar1 = FUN_005250c0();
  local_8 = FUN_005250c0();
  if (local_c < 0) {
    local_c = 0;
  }
  if (*(int *)(param_1 + 0x2c) <= local_4) {
    local_4 = *(int *)(param_1 + 0x2c) + -1;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (*(int *)(param_1 + 0x30) <= local_8) {
    local_8 = *(int *)(param_1 + 0x30) + -1;
  }
  iVar2 = FUN_004f3dc0(param_2,param_3);
  if (iVar2 != 0) {
    for (; iVar1 <= local_8; iVar1 = iVar1 + 1) {
      if (local_c <= local_4) {
        iVar4 = (local_4 - local_c) + 1;
        do {
          FUN_0042b0f0(param_4,param_5,param_6,param_7,param_8);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    LVar3 = InterlockedDecrement((LONG *)(iVar2 + 8));
    if (LVar3 == 0) {
      FUN_004f33a0(iVar2);
    }
  }
  return;
}

