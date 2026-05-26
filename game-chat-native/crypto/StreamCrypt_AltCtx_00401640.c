/*
 * Game.exe — StreamCrypt_AltCtx
 * Requested VA: 0x00401640
 * Entry Ghidra:  00401640
 * Ghidra name:   FUN_00401640
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __fastcall FUN_00401640(int param_1_00,uint *param_2,uint param_1)

{
  int iVar1;
  uint *in_EAX;
  int extraout_ECX;
  int extraout_ECX_00;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar1 = *(int *)(param_1_00 + 0x30);
  uVar3 = param_1;
  if (0 < iVar1) {
    if ((int)param_1 <= 0x10 - iVar1) {
      if (param_1 != 0) {
        do {
          param_1 = param_1 - 1;
          *(byte *)param_2 =
               *(byte *)(param_1_00 + 0x20 + *(int *)(param_1_00 + 0x30)) ^ *(byte *)in_EAX;
          *(int *)(param_1_00 + 0x30) = *(int *)(param_1_00 + 0x30) + 1;
          param_2 = (uint *)((int)param_2 + 1);
          in_EAX = (uint *)((int)in_EAX + 1);
        } while (param_1 != 0);
      }
      if (*(int *)(param_1_00 + 0x30) < 0x10) {
        return;
      }
      *(undefined4 *)(param_1_00 + 0x30) = 0;
      return;
    }
    uVar3 = param_1 - (0x10 - iVar1);
    while (iVar1 < 0x10) {
      *(byte *)param_2 =
           *(byte *)(param_1_00 + 0x20 + *(int *)(param_1_00 + 0x30)) ^ *(byte *)in_EAX;
      *(int *)(param_1_00 + 0x30) = *(int *)(param_1_00 + 0x30) + 1;
      in_EAX = (uint *)((int)in_EAX + 1);
      param_2 = (uint *)((int)param_2 + 1);
      iVar1 = *(int *)(param_1_00 + 0x30);
    }
    *(undefined4 *)(param_1_00 + 0x30) = 0;
  }
  if (0xf < (int)uVar3) {
    param_1 = uVar3 >> 4;
    uVar3 = uVar3 + param_1 * -0x10;
    puVar2 = in_EAX;
    puVar4 = param_2;
    do {
      FUN_00401500();
      param_2 = puVar4 + 4;
      *puVar4 = *puVar2 ^ *(uint *)(param_1_00 + 0x20);
      in_EAX = puVar2 + 4;
      puVar4[1] = puVar2[1] ^ *(uint *)(extraout_ECX + 0x24);
      puVar4[2] = puVar2[2] ^ *(uint *)(extraout_ECX + 0x28);
      param_1 = param_1 - 1;
      puVar4[3] = puVar2[3] ^ *(uint *)(extraout_ECX + 0x2c);
      puVar2 = in_EAX;
      puVar4 = param_2;
    } while (param_1 != 0);
  }
  if (0 < (int)uVar3) {
    FUN_00401500();
    iVar1 = *(int *)(extraout_ECX_00 + 0x30);
    while (iVar1 < (int)uVar3) {
      *(byte *)param_2 =
           *(byte *)(extraout_ECX_00 + 0x20 + *(int *)(extraout_ECX_00 + 0x30)) ^ *(byte *)in_EAX;
      *(int *)(extraout_ECX_00 + 0x30) = *(int *)(extraout_ECX_00 + 0x30) + 1;
      in_EAX = (uint *)((int)in_EAX + 1);
      param_2 = (uint *)((int)param_2 + 1);
      iVar1 = *(int *)(extraout_ECX_00 + 0x30);
    }
  }
  return;
}

