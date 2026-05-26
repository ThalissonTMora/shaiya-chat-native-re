/*
 * server/ps_login.exe — KeyTable_Realloc
 * Requested VA: 0x00411050
 * Entry Ghidra:  00411050
 * Ghidra name:   FUN_00411050
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: pipeline
 * Regenerate: tools/ghidra/decompile.sh
 */


void __fastcall FUN_00411050(int param_1)

{
  if (*(char *)(param_1 + 8) != '\0') {
    SetEvent(*(HANDLE *)(param_1 + 0xc));
  }
  return;
}

