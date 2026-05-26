/*
 * server/ps_game.exe — ZoneChat_MapInsert
 * Requested VA: 0x0040DCE0
 * Entry Ghidra:  0040dce0
 * Ghidra name:   FUN_0040dce0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int * FUN_0040dce0(int *param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_c;
  undefined4 *local_8;
  
  bVar2 = true;
  puVar5 = DAT_00587c5c;
  if (*(char *)((int)DAT_00587c5c[1] + 0x15) == '\0') {
    puVar3 = (undefined4 *)DAT_00587c5c[1];
    do {
      puVar5 = puVar3;
      bVar2 = *param_2 < (int)puVar5[3];
      if (bVar2) {
        puVar3 = (undefined4 *)*puVar5;
      }
      else {
        puVar3 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  local_c = DAT_00587c44;
  local_8 = puVar5;
  if (bVar2) {
    puVar3 = (undefined4 *)*DAT_00587c5c;
    if (DAT_00587c44 == 0) {
      FUN_0051b1ad();
    }
    if (puVar5 == puVar3) {
      piVar4 = (int *)FUN_0040de10(&local_c,1,param_2);
      iVar1 = piVar4[1];
      *param_1 = *piVar4;
      *(undefined *)(param_1 + 2) = 1;
      param_1[1] = iVar1;
      return param_1;
    }
    FUN_0040e310();
  }
  if ((int)local_8[3] < *param_2) {
    piVar4 = (int *)FUN_0040de10(&local_c,bVar2,param_2);
    iVar1 = *piVar4;
    param_1[1] = piVar4[1];
    *param_1 = iVar1;
    *(undefined *)(param_1 + 2) = 1;
    return param_1;
  }
  *param_1 = local_c;
  *(undefined *)(param_1 + 2) = 0;
  param_1[1] = (int)local_8;
  return param_1;
}

