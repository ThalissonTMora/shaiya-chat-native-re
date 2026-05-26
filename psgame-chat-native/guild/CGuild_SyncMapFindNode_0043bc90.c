/*
 * server/ps_game.exe — CGuild_SyncMapFindNode
 * Requested VA: 0x0043BC90
 * Entry Ghidra:  0043bc90
 * Ghidra name:   FUN_0043bc90
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: guild
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int * FUN_0043bc90(int *param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *unaff_EDI;
  int local_14;
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  puVar5 = (undefined4 *)unaff_EDI[6];
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
    puVar2 = (undefined4 *)puVar5[1];
    do {
      if ((uint)puVar2[3] < *param_2) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar5 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  puVar2 = (undefined4 *)unaff_EDI[6];
  local_10 = puVar5;
  local_14 = *unaff_EDI;
  if (*unaff_EDI == 0) {
    FUN_0051b1ad();
  }
  if ((puVar5 == puVar2) || (*param_2 < (uint)puVar5[3])) {
    local_8 = unaff_EDI[6];
    local_c = *unaff_EDI;
    piVar4 = &local_c;
  }
  else {
    piVar4 = &local_14;
  }
  iVar1 = *piVar4;
  param_1[1] = piVar4[1];
  *param_1 = iVar1;
  return param_1;
}

