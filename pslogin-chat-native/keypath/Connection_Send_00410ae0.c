/*
 * server/ps_login.exe — Connection_Send
 * Requested VA: 0x00410AE0
 * Entry Ghidra:  00410ae0
 * Ghidra name:   FUN_00410ae0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: keypath
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __thiscall FUN_00410ae0(void *this,undefined4 *param_1,uint param_2)

{
  int *piVar1;
  
  if ((int)param_2 < 0x801) {
    if (*(int *)((int)this + 0x68) != -1) {
      piVar1 = (int *)FUN_0041dbb0(param_1,param_2);
      if (piVar1 != (int *)0x0) {
        FUN_004116c0(*(void **)((int)this + 200),(int *)this,piVar1);
      }
    }
  }
  else {
    if (*(int *)((int)this + 0x18) == 0) {
      *(undefined4 *)((int)this + 0x18) = 0xc;
    }
    if (*(int *)((int)this + 0x1c) == 0) {
      *(undefined4 *)((int)this + 0x1c) = 0;
    }
    if (*(int *)((int)this + 0x68) != -1) {
      Ordinal_3(*(int *)((int)this + 0x68));
      *(undefined4 *)((int)this + 0x68) = 0xffffffff;
      return;
    }
  }
  return;
}

