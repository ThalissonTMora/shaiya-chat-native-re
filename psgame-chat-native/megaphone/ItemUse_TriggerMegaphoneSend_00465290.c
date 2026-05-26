/*
 * server/ps_game.exe — ItemUse_TriggerMegaphoneSend
 * Requested VA: 0x00465290
 * Entry Ghidra:  00465290
 * Ghidra name:   FUN_00465290
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: megaphone
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_00465290(int param_1_00,undefined param_1,undefined4 param_2)

{
  undefined2 local_c;
  undefined4 local_a;
  undefined local_6;
  undefined4 local_5;
  
  local_6 = param_1;
  local_5 = param_2;
  local_c = 0x504;
  local_a = *(undefined4 *)(param_1_00 + 0xdc);
  if (*(int *)(param_1_00 + 0xe0) != 0) {
    FUN_00427c10(*(int *)(param_1_00 + 0xe0),&local_c,0xb,local_a,5);
  }
  return;
}

