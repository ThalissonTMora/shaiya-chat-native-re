/*
 * server/ps_login.exe — Connection_SendEx
 * Requested VA: 0x00410B50
 * Entry Ghidra:  00410b50
 * Ghidra name:   FUN_00410b50
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: pipeline
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __thiscall FUN_00410b50(int *param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  
  if ((int)param_3 < 0x801) {
    if (param_1[0x1a] != -1) {
      piVar1 = (int *)FUN_0041dbb0(param_2,param_3);
      if (piVar1 != (int *)0x0) {
        FUN_004116c0((void *)param_1[0x32],param_1,piVar1);
        FUN_004116e0((void *)param_1[0x32],param_1);
      }
    }
  }
  else {
    if (param_1[6] == 0) {
      param_1[6] = 0xc;
    }
    if (param_1[7] == 0) {
      param_1[7] = 0;
    }
    if (param_1[0x1a] != -1) {
      Ordinal_3(param_1[0x1a]);
      param_1[0x1a] = -1;
      return;
    }
  }
  return;
}

