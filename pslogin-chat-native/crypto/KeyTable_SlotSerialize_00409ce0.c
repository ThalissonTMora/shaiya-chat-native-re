/*
 * server/ps_login.exe — KeyTable_SlotSerialize
 * Requested VA: 0x00409CE0
 * Entry Ghidra:  00409ce0
 * Ghidra name:   FUN_00409ce0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


bool FUN_00409ce0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  int local_14 [5];
  
  FUN_00423430(local_14);
  piVar1 = (int *)(unaff_ESI + 0x60);
  FUN_004233d0(piVar1,(int)local_14,*(int *)(unaff_ESI + 0x1c) * 0x20 - 1);
  FUN_004229b0((int *)(unaff_ESI + 0x6c),piVar1,unaff_ESI,unaff_ESI + 0x18);
  FUN_00409d60((int *)(unaff_ESI + 0x6c));
  iVar2 = FUN_00422950((int)piVar1,unaff_ESI + 0x78);
  return (bool)('\x01' - (iVar2 != 0));
}

