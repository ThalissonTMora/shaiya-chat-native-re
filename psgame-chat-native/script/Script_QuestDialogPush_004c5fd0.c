/*
 * server/ps_game.exe — Script_QuestDialogPush
 * Requested VA: 0x004C5FD0
 * Entry Ghidra:  004c5fd0
 * Ghidra name:   FUN_004c5fd0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004c5fd0(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 local_4;
  
  local_4 = *(undefined4 *)(param_1 + 0x1b0);
  iVar1 = FUN_00415480(&local_4);
  if (iVar1 != 0) {
    if ((0 < in_EAX) && (in_EAX <= DAT_010096a4)) {
      FUN_004b9280(*(undefined4 *)(param_1 + 0xd5c));
      return;
    }
    FUN_004b9280(*(undefined4 *)(param_1 + 0xd5c));
  }
  return;
}

