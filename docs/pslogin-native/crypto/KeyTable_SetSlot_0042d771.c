/*
 * server/ps_login.exe — KeyTable_SetSlot
 * Requested VA: 0x0042D771
 * Entry Ghidra:  0042d771
 * Ghidra name:   FUN_0042d771
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __cdecl FUN_0042d771(ulong param_1)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  p_Var1->_holdrand = param_1;
  return;
}

