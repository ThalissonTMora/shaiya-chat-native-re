/*
 * server/ps_game.exe — SConnection_AllocSendBuffer
 * Requested VA: 0x004F3DC0
 * Entry Ghidra:  004f3dc0
 * Ghidra name:   FUN_004f3dc0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int FUN_004f3dc0(void *param_1,size_t param_2)

{
  int iVar1;
  
  if ((int)param_2 < 0x1f) {
    iVar1 = FUN_004f3ab0();
  }
  else if ((int)param_2 < 0x7f) {
    iVar1 = FUN_004f3b50();
  }
  else {
    iVar1 = FUN_004f3bf0();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 1;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    _memcpy((void *)(*(int *)(iVar1 + 4) + 2),param_1,param_2);
    **(short **)(iVar1 + 4) = (short)param_2 + 2;
    return iVar1;
  }
  return 0;
}

