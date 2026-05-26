/*
 * server/ps_login.exe — SendBuffer_AllocBySize
 * Requested VA: 0x0041DBB0
 * Entry Ghidra:  0041dbb0
 * Ghidra name:   FUN_0041dbb0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


int __cdecl FUN_0041dbb0(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0x1f) {
    iVar1 = FUN_0041d8d0(&DAT_0044dc8c);
  }
  else if ((int)param_2 < 0x7f) {
    iVar1 = FUN_0041d970(&DAT_0044dcc8);
  }
  else {
    iVar1 = FUN_0041da10(&DAT_0044dd04);
  }
  if (iVar1 != 0) {
    uVar2 = param_2 >> 2;
    *(undefined4 *)(iVar1 + 8) = 1;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    puVar3 = (undefined4 *)(*(int *)(iVar1 + 4) + 2);
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined *)puVar3 = *(undefined *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    **(short **)(iVar1 + 4) = (short)param_2 + 2;
    return iVar1;
  }
  return 0;
}

