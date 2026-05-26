/*
 * Game.exe — ChatObject_ctor
 * Requested VA: 0x0040A840
 * Entry Ghidra:  0040a840
 * Ghidra name:   FUN_0040a840
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: init
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined4 * __fastcall FUN_0040a840(undefined4 *param_1)

{
  int *piVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0072c3ac;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = CNetWork::vftable;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x242] = 0xf;
  param_1[0x241] = 0;
  *(undefined *)(param_1 + 0x23d) = 0;
  local_4 = 1;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0x245);
  }
  param_1[0x245] = piVar1;
  param_1[0x249] = 0;
  param_1[0x24a] = 0;
  param_1[0x24b] = 0;
  param_1[0x24c] = 0;
  param_1[1] = 0;
  _memset(param_1 + 3,0,0x208);
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  *(undefined2 *)(param_1 + 0xa7) = 0;
  *(undefined *)((int)param_1 + 0x29e) = 0;
  *(undefined4 *)((int)param_1 + 0x29f) = 0;
  *(undefined4 *)((int)param_1 + 0x2a3) = 0;
  *(undefined4 *)((int)param_1 + 0x2a7) = 0;
  *(undefined4 *)((int)param_1 + 0x2ab) = 0;
  *(undefined4 *)((int)param_1 + 0x2af) = 0;
  *(undefined4 *)((int)param_1 + 0x2b3) = 0;
  *(undefined4 *)((int)param_1 + 0x2b7) = 0;
  *(undefined4 *)((int)param_1 + 699) = 0;
  *(undefined2 *)((int)param_1 + 0x2bf) = 0;
  *(undefined *)((int)param_1 + 0x2c1) = 0;
  _memset((void *)((int)param_1 + 0x82f),0,0xb0);
  *(undefined4 *)((int)param_1 + 0x8df) = 0;
  *(undefined4 *)((int)param_1 + 0x8e3) = 0;
  *(undefined4 *)((int)param_1 + 0x8e7) = 0;
  *(undefined4 *)((int)param_1 + 0x8eb) = 0;
  param_1[0x243] = 0;
  param_1[0x244] = 0;
  param_1[0x24d] = 0;
  param_1[0x8c] = 0;
  *(undefined *)(param_1 + 0x8d) = 0;
  _memset((void *)((int)param_1 + 0x235),0,0x2b);
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined *)((int)param_1 + 0x26e) = 0;
  param_1[2] = 0;
  ExceptionList = local_c;
  return param_1;
}

