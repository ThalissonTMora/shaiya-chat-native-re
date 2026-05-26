/*
 * server/ps_login.exe — BigInt_gcd
 * Requested VA: 0x00422950
 * Entry Ghidra:  00422950
 * Ghidra name:   FUN_00422950
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


int __cdecl FUN_00422950(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = iVar1 - *(int *)(param_2 + 4);
  if (iVar3 == 0) {
    iVar4 = iVar1;
    if (iVar1 < 0) {
      iVar4 = -iVar1;
    }
    iVar3 = 0;
    iVar4 = iVar4 + -1;
    if (-1 < iVar4) {
      puVar5 = (uint *)(*(int *)(param_2 + 8) + iVar4 * 4);
      do {
        uVar2 = *(uint *)((*(int *)(param_1 + 8) - *(int *)(param_2 + 8)) + (int)puVar5);
        if (*puVar5 != uVar2) {
          iVar3 = (-(uint)(*puVar5 < uVar2) & 2) - 1;
          break;
        }
        iVar4 = iVar4 + -1;
        puVar5 = puVar5 + -1;
      } while (-1 < iVar4);
    }
    if (iVar1 < 0) {
      iVar3 = -iVar3;
    }
  }
  return iVar3;
}

