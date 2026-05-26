/*
 * server/ps_game.exe — ZoneChat_MapInit
 * Requested VA: 0x00407E40
 * Entry Ghidra:  00407e20
 * Ghidra name:   FUN_00407e20
 * NOTE: VA is inside the function (landmark/hook), not the entry point.
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 * FUN_00407e20(void)

{
  uint uVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0054e875;
  local_c = ExceptionList;
  uVar1 = DAT_0057f7c4 ^ (uint)&local_c;
  ExceptionList = &local_c;
  DAT_00587c44 = (undefined4 *)operator_new(4);
  if (DAT_00587c44 == (undefined4 *)0x0) {
    DAT_00587c44 = (undefined4 *)0x0;
  }
  else {
    *DAT_00587c44 = &DAT_00587c44;
  }
  local_4 = 0;
  DAT_00587c5c = FUN_004085e0(uVar1);
  *(undefined *)(DAT_00587c5c + 0x15) = 1;
  *(int *)(DAT_00587c5c + 4) = DAT_00587c5c;
  *(int *)DAT_00587c5c = DAT_00587c5c;
  *(int *)(DAT_00587c5c + 8) = DAT_00587c5c;
  DAT_00587c60 = 0;
  ExceptionList = local_c;
  return &DAT_00587c44;
}

