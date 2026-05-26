/*
 * server/ps_login.exe — BigInt_poolInit
 * Requested VA: 0x004272F0
 * Entry Ghidra:  004272f0
 * Ghidra name:   FUN_004272f0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


undefined4 __cdecl FUN_004272f0(int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int local_c [3];
  
  piVar3 = (int *)&DAT_00441638;
  uVar2 = DAT_00441638;
  if (DAT_00441638 != 0) {
    do {
      if (param_2 <= uVar2 >> 1) {
        FUN_0042ae90(local_c,(char *)piVar3[1],0x10);
        FUN_0042ae20(param_1,(int)local_c,piVar3[2],*piVar3);
        FUN_00422750(local_c);
        return 1;
      }
      puVar1 = (uint *)(piVar3 + 3);
      piVar3 = piVar3 + 3;
      uVar2 = *puVar1;
    } while (*puVar1 != 0);
  }
  return 0;
}

