/*
 * server/ps_game.exe — SConnection_Send
 * Requested VA: 0x004ED0E0
 * Entry Ghidra:  004ed0e0
 * Ghidra name:   FUN_004ed0e0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004ed0e0(int param_1_00,undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0x801) {
    if (*(int *)(param_1_00 + 0x68) != -1) {
      iVar1 = FUN_004f3dc0(param_1,param_2);
      if (iVar1 != 0) {
        FUN_004ef080(param_1_00,iVar1);
      }
    }
  }
  else {
    if (*(int *)(param_1_00 + 0x18) == 0) {
      *(undefined4 *)(param_1_00 + 0x18) = 0xc;
    }
    if (*(int *)(param_1_00 + 0x1c) == 0) {
      *(undefined4 *)(param_1_00 + 0x1c) = 0;
    }
    if (*(int *)(param_1_00 + 0x68) != -1) {
      Ordinal_3(*(int *)(param_1_00 + 0x68));
      *(undefined4 *)(param_1_00 + 0x68) = 0xffffffff;
      return;
    }
  }
  return;
}

