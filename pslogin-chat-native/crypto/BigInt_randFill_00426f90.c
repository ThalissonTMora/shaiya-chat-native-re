/*
 * server/ps_login.exe — BigInt_randFill
 * Requested VA: 0x00426F90
 * Entry Ghidra:  00426f90
 * Ghidra name:   FUN_00426f90
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0042702a) */
/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_00426f90(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint auStack_3c [6];
  undefined4 uStack_24;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    uVar10 = *(uint *)(*(int *)(param_2 + 0x10) + 0x1c) >> 1;
    iVar2 = (int)(uVar10 + 0x1f + ((int)(uVar10 + 0x1f) >> 0x1f & 0x1fU)) >> 5;
    uStack_24 = 0x426fcb;
    iVar1 = iVar2 * -4;
    puVar8 = (uint *)(&stack0xffffffe0 + iVar1);
    uVar7 = 0;
    uVar3 = uVar10;
    while (uVar3 <= param_3) {
      uVar3 = uVar7 & 0x1f;
      puVar9 = (uint *)(param_1 + (uVar7 >> 5) * 4);
      if (uVar3 == 0) {
        auStack_3c[6 - iVar2] = param_2;
        auStack_3c[5 - iVar2] = (uint)puVar9;
        auStack_3c[4 - iVar2] = 0x42704c;
        FUN_00427120((uint *)auStack_3c[5 - iVar2],auStack_3c[6 - iVar2]);
      }
      else {
        auStack_3c[6 - iVar2] = param_2;
        auStack_3c[5 - iVar2] = (uint)(&stack0xffffffe0 + iVar1);
        auStack_3c[4 - iVar2] = 0x426ffd;
        FUN_00427120((uint *)auStack_3c[5 - iVar2],auStack_3c[6 - iVar2]);
        uVar6 = *puVar9;
        auStack_3c[4 - iVar2] = uVar3;
        auStack_3c[3 - iVar2] = iVar2;
        auStack_3c[2 - iVar2] = (uint)(&stack0xffffffe0 + iVar1);
        auStack_3c[1 - iVar2] = (uint)puVar9;
        auStack_3c[-iVar2] = 0x427014;
        uVar4 = FUN_00423f40(auStack_3c[1 - iVar2],auStack_3c[2 - iVar2],auStack_3c[3 - iVar2],
                             *(byte *)(auStack_3c + (4 - iVar2)));
        *puVar9 = *puVar9 | uVar6;
        if (0x20 < (uVar10 & 0x8000001f) + uVar3) {
          puVar9[iVar2] = uVar4;
        }
      }
      uVar7 = uVar7 + uVar10;
      uVar3 = uVar7 + uVar10;
    }
    if (uVar7 != param_3) {
      iVar5 = (param_3 - uVar7) + 0x1f;
      puVar9 = (uint *)(param_1 + (uVar7 >> 5) * 4);
      auStack_3c[6 - iVar2] = param_2;
      auStack_3c[5 - iVar2] = (uint)(&stack0xffffffe0 + iVar1);
      iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
      auStack_3c[4 - iVar2] = 0x42708d;
      FUN_00427120((uint *)auStack_3c[5 - iVar2],auStack_3c[6 - iVar2]);
      uVar3 = uVar7 & 0x1f;
      if (uVar3 == 0) {
        if (iVar5 != 0) {
          uVar3 = *(uint *)(&stack0xffffffe0 + iVar1);
          while (iVar5 = iVar5 + -1, iVar5 != 0) {
            puVar8 = puVar8 + 1;
            *puVar9 = uVar3;
            uVar3 = *puVar8;
            puVar9 = puVar9 + 1;
          }
          *puVar9 = uVar3;
        }
      }
      else {
        uVar10 = *puVar9;
        auStack_3c[6 - iVar2] = uVar3;
        auStack_3c[5 - iVar2] = iVar5;
        auStack_3c[4 - iVar2] = (uint)(&stack0xffffffe0 + iVar1);
        auStack_3c[3 - iVar2] = (uint)puVar9;
        auStack_3c[2 - iVar2] = 0x4270ab;
        uVar6 = FUN_00423f40(auStack_3c[3 - iVar2],auStack_3c[4 - iVar2],auStack_3c[5 - iVar2],
                             *(byte *)(auStack_3c + (6 - iVar2)));
        *puVar9 = *puVar9 | uVar10;
        if ((iVar5 * 0x20 - uVar3) + uVar7 < param_3) {
          puVar9[iVar5] = uVar6;
        }
      }
      if ((param_3 & 0x1f) != 0) {
        puVar8 = (uint *)(param_1 + (param_3 >> 5) * 4);
        *puVar8 = *puVar8 & ~(-1 << (sbyte)(param_3 & 0x1f));
      }
    }
  }
  return;
}

