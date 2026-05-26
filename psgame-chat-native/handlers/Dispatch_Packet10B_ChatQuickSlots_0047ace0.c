/*
 * server/ps_game.exe — Dispatch_Packet10B_ChatQuickSlots
 * Requested VA: 0x0047ACE0
 * Entry Ghidra:  0047ace0
 * Ghidra name:   FUN_0047ace0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0047ace0(void)

{
  int in_EAX;
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined2 local_508;
  undefined4 local_506;
  byte local_502;
  undefined local_500 [1280];
  
  iVar3 = *(int *)(in_EAX + 0xec0);
  if (0 < iVar3) {
    local_506 = *(undefined4 *)(in_EAX + 0x582c);
    local_508 = 0x609;
    local_502 = *(byte *)(in_EAX + 0xec0);
    puVar2 = local_500;
    puVar1 = (undefined *)(in_EAX + 0xec5);
    do {
      puVar2[-1] = puVar1[-1];
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(puVar1 + 3);
      puVar1 = puVar1 + 6;
      puVar2 = puVar2 + 5;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_004ed2d0(&local_508,(uint)local_502 * 5 + 7);
  }
  return;
}

