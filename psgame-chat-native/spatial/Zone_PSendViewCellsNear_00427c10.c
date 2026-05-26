/*
 * server/ps_game.exe — Zone_PSendViewCellsNear
 * Requested VA: 0x00427C10
 * Entry Ghidra:  00427c10
 * Ghidra name:   FUN_00427c10
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: spatial
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall
FUN_00427c10(int param_1_00,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int in_EAX;
  int iVar1;
  LONG LVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  undefined4 local_4;
  
  local_c = param_1_00 + -2;
  iVar4 = in_EAX + -2;
  local_4 = in_EAX + 2;
  param_1_00 = param_1_00 + 2;
  if (local_c < 0) {
    local_c = 0;
  }
  if (*(int *)(param_1 + 0x2c) <= param_1_00) {
    param_1_00 = *(int *)(param_1 + 0x2c) + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (*(int *)(param_1 + 0x30) <= local_4) {
    local_4 = *(int *)(param_1 + 0x30) + -1;
  }
  iVar1 = FUN_004f3dc0(param_2,param_3);
  if (iVar1 != 0) {
    for (; iVar4 <= local_4; iVar4 = iVar4 + 1) {
      if (local_c <= param_1_00) {
        iVar5 = local_c * 0x124;
        iVar3 = (param_1_00 - local_c) + 1;
        do {
          FUN_0042b030(*(int *)(*(int *)(param_1 + 0x34) + iVar4 * 4) + iVar5,param_4,param_5);
          iVar5 = iVar5 + 0x124;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    LVar2 = InterlockedDecrement((LONG *)(iVar1 + 8));
    if (LVar2 == 0) {
      FUN_004f33a0(iVar1);
    }
  }
  return;
}

