/*
 * server/ps_login.exe — KeyTable_AllocOne
 * Requested VA: 0x004069D0
 * Entry Ghidra:  004069d0
 * Ghidra name:   FUN_004069d0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __fastcall FUN_004069d0(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  DVar1 = GetTickCount();
  if (0x3ff < *(LONG *)(param_1 + 0x10)) {
    if (*(char *)(param_1 + 8) != '\0') {
      SetEvent(*(HANDLE *)(param_1 + 0xc));
    }
    return;
  }
  FUN_00409ae0(0x400,0);
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  DVar2 = GetTickCount();
  DVar1 = (DVar2 - DVar1) * 9;
  if ((int)DVar1 < 0) {
    DVar1 = 0;
  }
  Sleep(DVar1);
  return;
}

