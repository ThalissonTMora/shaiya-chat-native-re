/*
 * server/ps_login.exe — SendKeyBlob_A101
 * Requested VA: 0x00404DA0
 * Entry Ghidra:  00404da0
 * Ghidra name:   FUN_00404da0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: keypath
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void FUN_00404da0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 local_d8;
  undefined local_d6;
  char local_d5;
  char local_d4;
  undefined4 local_d3 [16];
  undefined4 local_93 [33];
  int local_c;
  
  local_c = DAT_0044c528;
  iVar1 = _rand();
  iVar1 = iVar1 % DAT_00454c70;
  *(undefined *)((int)param_1 + 0x15) = 1;
  local_d8 = 0xa101;
  local_d6 = 0;
  iVar1 = iVar1 * 0x84;
  param_1[6] = &DAT_00454c74 + iVar1;
  local_d5 = (char)*(uint *)(&DAT_00454c78 + iVar1) * '\x04';
  puVar4 = *(undefined4 **)(&DAT_00454c7c + iVar1);
  puVar5 = local_d3;
  for (uVar2 = *(uint *)(&DAT_00454c78 + iVar1) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar2 = *(uint *)(&DAT_00454c90 + iVar1);
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined *)puVar5 = *(undefined *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  local_d4 = (char)uVar2 * '\x04';
  puVar4 = *(undefined4 **)(&DAT_00454c94 + iVar1);
  puVar5 = local_93;
  for (uVar2 = uVar2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined *)puVar5 = *(undefined *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  FUN_00410ae0((void *)*param_1,(undefined4 *)&local_d8,0xc5);
  FUN_0042e427(local_c);
  return;
}

