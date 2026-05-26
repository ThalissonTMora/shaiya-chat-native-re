/*
 * server/ps_game.exe — Script_ZonePush_0610
 * Requested VA: 0x004C6EC0
 * Entry Ghidra:  004c6ec0
 * Ghidra name:   FUN_004c6ec0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c6ec0(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined2 local_c;
  undefined4 local_a;
  int local_6;
  
  *(int *)(in_EAX + 0x2a8) = *(int *)(in_EAX + 0x2a8) + param_1;
  if (*(uint *)(*(int *)(in_EAX + 0xd4) + 0x30) < *(uint *)(in_EAX + 0x2a8)) {
    iVar1 = *(int *)(*(int *)(in_EAX + 0xd4) + 0x30);
    param_1 = param_1 + (iVar1 - *(uint *)(in_EAX + 0x2a8));
    *(int *)(in_EAX + 0x2a8) = iVar1;
  }
  if (0 < param_1) {
    local_c = 0x610;
    local_a = *(undefined4 *)(in_EAX + 0x88);
    if (*(int *)(in_EAX + 0x8c) != 0) {
      local_6 = param_1;
      FUN_00427cf0(*(int *)(in_EAX + 0x8c),&local_c,10,in_EAX + 0x7c,_DAT_00574168,0,0,6);
    }
  }
  return;
}

