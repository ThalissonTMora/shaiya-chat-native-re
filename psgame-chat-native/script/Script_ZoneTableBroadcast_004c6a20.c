/*
 * server/ps_game.exe — Script_ZoneTableBroadcast
 * Requested VA: 0x004C6A20
 * Entry Ghidra:  004c6a20
 * Ghidra name:   FUN_004c6a20
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall
FUN_004c6a20(undefined4 param_1_00,int param_2_00,undefined4 param_1,undefined4 param_2,
            undefined4 param_3)

{
  int in_EAX;
  short *psVar1;
  
  if ((-1 < in_EAX) && (in_EAX < DAT_01009674)) {
    psVar1 = (short *)(in_EAX * 0x10c + DAT_01009678);
    if ((*psVar1 != 0) &&
       (((*(int *)(psVar1 + 0x18) != 0 && (psVar1[0x11] != 0)) && (psVar1 != (short *)0x0)))) {
      FUN_00424a90(*(undefined4 *)(param_2_00 + 0x8c),param_2,param_1,param_3);
    }
  }
  return;
}

