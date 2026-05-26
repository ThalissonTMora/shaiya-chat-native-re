/*
 * Game.exe — PacketRecv_AttachBuffer
 * Requested VA: 0x005F4680
 * Entry Ghidra:  005f4680
 * Ghidra name:   FUN_005f4680
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: recv
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void * __thiscall FUN_005f4680(void *param_1_00,void *param_1,size_t param_2)

{
  _memset(param_1_00,0,0x2000);
  *(void **)((int)param_1_00 + 0x2008) = param_1_00;
  *(void **)((int)param_1_00 + 0x2004) = param_1_00;
  if (0x2000 < param_2) {
    param_2 = 0x2000;
  }
  _memcpy(param_1_00,param_1,param_2);
  *(int *)((int)param_1_00 + 0x2008) = *(int *)((int)param_1_00 + 0x2008) + param_2;
  *(size_t *)((int)param_1_00 + 0x2000) = param_2;
  return param_1_00;
}

