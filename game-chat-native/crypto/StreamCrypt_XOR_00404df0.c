/*
 * Game.exe — StreamCrypt_XOR
 * Requested VA: 0x00404DF0
 * Entry Ghidra:  00404df0
 * Ghidra name:   FUN_00404df0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __thiscall FUN_00404df0(uint *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint *in_EAX;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int unaff_ESI;
  uint *puVar6;
  
  iVar2 = *(int *)(unaff_ESI + 0x104);
  uVar5 = param_2;
  if (0 < iVar2) {
    if ((int)param_2 <= 0x10 - iVar2) {
      if (param_2 != 0) {
        do {
          param_2 = param_2 - 1;
          *(byte *)param_1 =
               *(byte *)(unaff_ESI + 0x108 + *(int *)(unaff_ESI + 0x104)) ^ *(byte *)in_EAX;
          *(int *)(unaff_ESI + 0x104) = *(int *)(unaff_ESI + 0x104) + 1;
          param_1 = (uint *)((int)param_1 + 1);
          in_EAX = (uint *)((int)in_EAX + 1);
        } while (param_2 != 0);
      }
      if (*(int *)(unaff_ESI + 0x104) < 0x10) {
        return;
      }
      *(undefined4 *)(unaff_ESI + 0x104) = 0;
      return;
    }
    uVar5 = param_2 - (0x10 - iVar2);
    while (iVar2 < 0x10) {
      *(byte *)param_1 =
           *(byte *)(unaff_ESI + 0x108 + *(int *)(unaff_ESI + 0x104)) ^ *(byte *)in_EAX;
      *(int *)(unaff_ESI + 0x104) = *(int *)(unaff_ESI + 0x104) + 1;
      in_EAX = (uint *)((int)in_EAX + 1);
      param_1 = (uint *)((int)param_1 + 1);
      iVar2 = *(int *)(unaff_ESI + 0x104);
    }
    *(undefined4 *)(unaff_ESI + 0x104) = 0;
  }
  if (0xf < (int)uVar5) {
    param_2 = uVar5 >> 4;
    uVar5 = uVar5 + param_2 * -0x10;
    puVar4 = in_EAX;
    puVar6 = param_1;
    do {
      FUN_00404830(unaff_ESI + 0x108);
      piVar3 = (int *)(unaff_ESI + 0xf4);
      *piVar3 = *piVar3 + 1;
      if (*piVar3 == 0) {
        piVar3 = (int *)(unaff_ESI + 0xf8);
        *piVar3 = *piVar3 + 1;
        if (*piVar3 == 0) {
          piVar3 = (int *)(unaff_ESI + 0xfc);
          *piVar3 = *piVar3 + 1;
          if (*piVar3 == 0) {
            *(int *)(unaff_ESI + 0x100) = *(int *)(unaff_ESI + 0x100) + 1;
          }
        }
      }
      param_1 = puVar6 + 4;
      *puVar6 = *puVar4 ^ *(uint *)(unaff_ESI + 0x108);
      in_EAX = puVar4 + 4;
      puVar6[1] = puVar4[1] ^ *(uint *)(unaff_ESI + 0x10c);
      puVar6[2] = puVar4[2] ^ *(uint *)(unaff_ESI + 0x110);
      param_2 = param_2 - 1;
      puVar6[3] = puVar4[3] ^ *(uint *)(unaff_ESI + 0x114);
      puVar4 = in_EAX;
      puVar6 = param_1;
    } while (param_2 != 0);
  }
  if (0 < (int)uVar5) {
    FUN_00404830(unaff_ESI + 0x108);
    piVar3 = (int *)(unaff_ESI + 0xf4);
    *piVar3 = *piVar3 + 1;
    if (*piVar3 == 0) {
      piVar3 = (int *)(unaff_ESI + 0xf8);
      *piVar3 = *piVar3 + 1;
      if (*piVar3 == 0) {
        piVar3 = (int *)(unaff_ESI + 0xfc);
        *piVar3 = *piVar3 + 1;
        if (*piVar3 == 0) {
          *(int *)(unaff_ESI + 0x100) = *(int *)(unaff_ESI + 0x100) + 1;
        }
      }
    }
    iVar2 = *(int *)(unaff_ESI + 0x104);
    while (iVar2 < (int)uVar5) {
      bVar1 = *(byte *)in_EAX;
      in_EAX = (uint *)((int)in_EAX + 1);
      *(byte *)param_1 = *(byte *)(unaff_ESI + 0x108 + *(int *)(unaff_ESI + 0x104)) ^ bVar1;
      *(int *)(unaff_ESI + 0x104) = *(int *)(unaff_ESI + 0x104) + 1;
      param_1 = (uint *)((int)param_1 + 1);
      iVar2 = *(int *)(unaff_ESI + 0x104);
    }
  }
  return;
}

