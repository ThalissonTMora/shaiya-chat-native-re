/*
 * server/ps_login.exe — Connection_SendGuard
 * Requested VA: 0x00410C10
 * Entry Ghidra:  00410c10
 * Ghidra name:   FUN_00410c10
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: pipeline
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __thiscall FUN_00410c10(void *this,undefined4 *param_1,uint param_2)

{
  if (*(char *)((int)this + 0xd8) != '\0') {
    FUN_00410ae0(this,param_1,param_2);
    return;
  }
  return;
}

