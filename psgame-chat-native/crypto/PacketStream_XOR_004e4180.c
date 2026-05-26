/*
 * ps_game.exe — PacketStream_XOR
 * Requested VA: 0x004E4180
 * Entry Ghidra:  004e4180
 * Ghidra name:   FUN_004e4180
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __thiscall FUN_004e4180(uint *param_1_00,uint param_1)

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
  uVar5 = param_1;
  if (0 < iVar2) {
    if ((int)param_1 <= 0x10 - iVar2) {
      if (param_1 != 0) {
        do {
          param_1 = param_1 - 1;
          *(byte *)param_1_00 =
               *(byte *)(unaff_ESI + 0x108 + *(int *)(unaff_ESI + 0x104)) ^ *(byte *)in_EAX;
          *(int *)(unaff_ESI + 0x104) = *(int *)(unaff_ESI + 0x104) + 1;
          param_1_00 = (uint *)((int)param_1_00 + 1);
          in_EAX = (uint *)((int)in_EAX + 1);
        } while (param_1 != 0);
      }
      if (*(int *)(unaff_ESI + 0x104) < 0x10) {
        return;
      }
      *(undefined4 *)(unaff_ESI + 0x104) = 0;
      return;
    }
    uVar5 = param_1 - (0x10 - iVar2);
    while (iVar2 < 0x10) {
      *(byte *)param_1_00 =
           *(byte *)(unaff_ESI + 0x108 + *(int *)(unaff_ESI + 0x104)) ^ *(byte *)in_EAX;
      *(int *)(unaff_ESI + 0x104) = *(int *)(unaff_ESI + 0x104) + 1;
      in_EAX = (uint *)((int)in_EAX + 1);
      param_1_00 = (uint *)((int)param_1_00 + 1);
      iVar2 = *(int *)(unaff_ESI + 0x104);
    }
    *(undefined4 *)(unaff_ESI + 0x104) = 0;
  }
  if (0xf < (int)uVar5) {
    param_1 = uVar5 >> 4;
    uVar5 = uVar5 + param_1 * -0x10;
    puVar4 = in_EAX;
    puVar6 = param_1_00;
    do {
      FUN_004e3450(unaff_ESI + 0x108);
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
      param_1_00 = puVar6 + 4;
      *puVar6 = *puVar4 ^ *(uint *)(unaff_ESI + 0x108);
      in_EAX = puVar4 + 4;
      puVar6[1] = puVar4[1] ^ *(uint *)(unaff_ESI + 0x10c);
      puVar6[2] = puVar4[2] ^ *(uint *)(unaff_ESI + 0x110);
      param_1 = param_1 - 1;
      puVar6[3] = puVar4[3] ^ *(uint *)(unaff_ESI + 0x114);
      puVar4 = in_EAX;
      puVar6 = param_1_00;
    } while (param_1 != 0);
  }
  if (0 < (int)uVar5) {
    FUN_004e3450(unaff_ESI + 0x108);
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
      *(byte *)param_1_00 = *(byte *)(unaff_ESI + 0x108 + *(int *)(unaff_ESI + 0x104)) ^ bVar1;
      *(int *)(unaff_ESI + 0x104) = *(int *)(unaff_ESI + 0x104) + 1;
      param_1_00 = (uint *)((int)param_1_00 + 1);
      iVar2 = *(int *)(unaff_ESI + 0x104);
    }
  }
  return;
}

