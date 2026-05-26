/*
 * server/ps_game.exe — Script_InstrResolver
 * Requested VA: 0x004A5720
 * Entry Ghidra:  004a5720
 * Ghidra name:   FUN_004a5720
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004a5720(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_EAX + 0x18) + *(int *)(in_EAX + 0x1c) & 3U) == 0) &&
     (*(uint *)(in_EAX + 0x14) <= *(int *)(in_EAX + 0x1c) + 4U >> 2)) {
    FUN_004a5f80();
  }
  uVar4 = *(int *)(in_EAX + 0x18) + *(int *)(in_EAX + 0x1c);
  uVar3 = uVar4 >> 2;
  if (*(uint *)(in_EAX + 0x14) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(in_EAX + 0x14);
  }
  if (*(int *)(*(int *)(in_EAX + 0x10) + uVar3 * 4) == 0) {
    uVar2 = FUN_004a7e10();
    *(undefined4 *)(*(int *)(in_EAX + 0x10) + uVar3 * 4) = uVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(in_EAX + 0x10) + uVar3 * 4) + (uVar4 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)(in_EAX + 0x1c) = *(int *)(in_EAX + 0x1c) + 1;
  return;
}

