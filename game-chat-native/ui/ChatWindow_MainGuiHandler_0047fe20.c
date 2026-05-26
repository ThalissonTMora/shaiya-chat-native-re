/*
 * Game.exe — ChatWindow_MainGuiHandler
 * Requested VA: 0x0047FE20
 * Entry Ghidra:  0047fe20
 * Ghidra name:   FUN_0047fe20
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


int * FUN_0047fe20(int *param_1,int param_2,byte param_3)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  int *local_24;
  char local_20;
  uint local_1c;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00730098;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  bVar3 = false;
  FUN_0047fcd0(param_1,1);
  uVar4 = 0;
  if (local_20 != '\0') {
    local_8 = 1;
    FUN_00405300(0,0xffffffff);
    piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x28 + (int)param_1);
    if ((*(int *)piVar1[8] == 0) || (*(int *)piVar1[0xc] < 1)) {
      uVar4 = (**(code **)(*piVar1 + 0x10))();
    }
    else {
      uVar4 = (uint)**(byte **)piVar1[8];
    }
    while (uVar4 != 0xffffffff) {
      if (uVar4 == param_3) {
        piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x28 + (int)param_1);
        bVar3 = true;
        if ((*(int *)piVar1[8] == 0) || (piVar2 = (int *)piVar1[0xc], *piVar2 < 1)) {
          (**(code **)(*piVar1 + 0x14))();
        }
        else {
          *piVar2 = *piVar2 + -1;
          *(int *)piVar1[8] = *(int *)piVar1[8] + 1;
        }
        goto LAB_0047fef8;
      }
      if (0xfffffffd < *(uint *)(param_2 + 0x14)) {
        local_1c = 2;
        goto LAB_0047fef8;
      }
      FUN_00424d30(1,uVar4);
      bVar3 = true;
      uVar4 = FUN_0047cd10();
    }
    local_1c = 1;
LAB_0047fef8:
    uVar4 = local_1c;
    if (bVar3) goto LAB_0047ff0b;
  }
  local_1c = uVar4 | 2;
LAB_0047ff0b:
  local_8 = 0;
  if (local_1c != 0) {
    local_1c = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 8) | local_1c;
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x28) == 0) {
      local_1c = local_1c | 4;
    }
    FUN_0047f410(local_1c,0);
  }
  local_8 = 0xffffffff;
  if (*(int *)(*(int *)(*local_24 + 4) + 0x28 + (int)local_24) != 0) {
    FUN_00655bbc();
  }
  ExceptionList = local_10;
  return param_1;
}

