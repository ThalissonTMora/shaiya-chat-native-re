/*
 * server/ps_login.exe — KeyTable_SlotAltInit
 * Requested VA: 0x00423440
 * Entry Ghidra:  00423440
 * Ghidra name:   FUN_00423440
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __cdecl FUN_00423440(int param_1,int param_2)

{
  **(int **)(param_1 + 8) = param_2;
  *(uint *)(param_1 + 4) = (uint)(param_2 != 0);
  return;
}

