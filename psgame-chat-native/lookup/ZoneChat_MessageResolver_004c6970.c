/*
 * server/ps_game.exe — ZoneChat_MessageResolver
 * Requested VA: 0x004C6970
 * Entry Ghidra:  004c6970
 * Ghidra name:   FUN_004c6970
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_004c6970(void)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004c71d0();
  iVar1 = DAT_00587c5c;
  if ((local_8 == (int *)0x0) || (local_8 != DAT_00587c44)) {
    FUN_0051b1ad();
  }
  if (local_4 == iVar1) {
    return 0;
  }
  if (local_8 == (int *)0x0) {
    FUN_0051b1ad();
    iVar1 = 0;
  }
  else {
    iVar1 = *local_8;
  }
  if (local_4 == *(int *)(iVar1 + 0x18)) {
    FUN_0051b1ad();
  }
  return *(undefined4 *)(local_4 + 0x10);
}

