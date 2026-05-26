/*
 * server/ps_login.exe — KeyTable_SlotEnsure
 * Requested VA: 0x00406990
 * Entry Ghidra:  00406990
 * Ghidra name:   FUN_00406990
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


undefined4 __fastcall FUN_00406990(int param_1)

{
  if (0x3ff < *(int *)(param_1 + 0x10)) {
    func_0x00411050();
    return 0;
  }
  FUN_00409ae0(0x400,0);
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return 1;
}

