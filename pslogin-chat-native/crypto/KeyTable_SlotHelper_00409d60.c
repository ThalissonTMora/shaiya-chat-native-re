/*
 * server/ps_login.exe — KeyTable_SlotHelper
 * Requested VA: 0x00409D60
 * Entry Ghidra:  00409d60
 * Ghidra name:   FUN_00409d60
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void FUN_00409d60(int *param_1)

{
  int *piVar1;
  int in_EAX;
  int *unaff_EBX;
  
  FUN_004229b0(unaff_EBX,param_1,in_EAX + 0x3c,in_EAX + 0x24);
  piVar1 = (int *)(in_EAX + 0x60);
  FUN_004229b0(piVar1,param_1,in_EAX + 0x48,in_EAX + 0x30);
  FUN_00423510(piVar1,(uint)piVar1,(int)unaff_EBX);
  FUN_00421ef0(piVar1,(uint *)piVar1,(uint *)(in_EAX + 0x54));
  FUN_00421e50(piVar1,piVar1,(int *)(in_EAX + 0x30));
  FUN_00421ef0(piVar1,(uint *)piVar1,(uint *)(in_EAX + 0x24));
  FUN_00422770(piVar1,(uint)unaff_EBX,(int)piVar1);
  FUN_00421e50(unaff_EBX,piVar1,(int *)(in_EAX + 0x18));
  return;
}

