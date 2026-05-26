/*
 * server/ps_login.exe — Connection_EnqueueKeyBlob
 * Requested VA: 0x00401C70
 * Entry Ghidra:  00401c70
 * Ghidra name:   FUN_00401c70
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: keypath
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __thiscall FUN_00401c70(void *this,int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x2c4));
  if (*(int *)((int)this + 700) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)((int)this + 700) + 8;
  }
  *(int *)(param_1 + 0xc) = iVar1;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)((int)this + 700) + 8);
  *(int *)(*(int *)(*(int *)((int)this + 700) + 8) + 4) = param_1 + 8;
  *(int *)(*(int *)((int)this + 700) + 8) = param_1 + 8;
  *(int *)((int)this + 0x2dc) = *(int *)((int)this + 0x2dc) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x2c4));
  *(int *)(param_1 + 0xf8) = (int)this + -0x418;
  FUN_00404da0((undefined4 *)(param_1 + 0x13c));
                    /* WARNING: Could not recover jumptable at 0x00401cf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InterlockedIncrement((LONG *)(DAT_0044e7b8 + 0x59));
  return;
}

