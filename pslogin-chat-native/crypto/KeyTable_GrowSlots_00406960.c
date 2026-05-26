/*
 * server/ps_login.exe — KeyTable_GrowSlots
 * Requested VA: 0x00406960
 * Entry Ghidra:  00406960
 * Ghidra name:   FUN_00406960
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void FUN_00406960(void)

{
  int in_EAX;
  int unaff_EDI;
  
  if (0 < in_EAX) {
    do {
      FUN_00409ae0(0x400,0);
      *(int *)(unaff_EDI + 0x10) = *(int *)(unaff_EDI + 0x10) + 1;
      in_EAX = in_EAX + -1;
    } while (in_EAX != 0);
  }
  return;
}

