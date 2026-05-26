/*
 * server/ps_login.exe — KeyTable_SlotInit
 * Requested VA: 0x00409AE0
 * Entry Ghidra:  00409ae0
 * Ghidra name:   FUN_00409ae0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 * Callees: tools/ghidra/keytable-slotinit-callees.manifest
 * Pipeline: docs/LOGIN_A101_BODY_MAP.md § KeyTable
 */


void FUN_00409ae0(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int *in_EAX;
  __time32_t _Var6;
  int iVar7;
  uint uVar8;
  int local_20 [3];
  int local_14 [5];
  
  FUN_00423430(local_14);
  _Var6 = FID_conflict___time32((__time32_t *)0x0);
  FUN_00422730((int)local_14,_Var6);
  uVar8 = param_1 >> 1;
  puVar1 = (uint *)(in_EAX + 9);
  FUN_004233d0((int *)puVar1,(int)local_14,uVar8);
  uVar2 = uVar8 - 1;
  FUN_004225a0((int *)puVar1,uVar2);
  uVar3 = uVar8 - 2;
  FUN_004225a0((int *)puVar1,uVar3);
  FUN_00422910((int *)puVar1,(int)puVar1);
  puVar4 = (uint *)(in_EAX + 0xc);
  FUN_004233d0((int *)puVar4,(int)local_14,uVar8);
  FUN_004225a0((int *)puVar4,uVar2);
  FUN_004225a0((int *)puVar4,uVar3);
  FUN_00422910((int *)puVar4,(int)puVar4);
  FUN_00422100(in_EAX + 0xf,(int)puVar1,1);
  FUN_00422100(in_EAX + 0x12,(int)puVar4,1);
  FUN_00421ef0(in_EAX + 3,(uint *)(in_EAX + 0x12),(uint *)(in_EAX + 0xf));
  if (param_2 == 0) {
    FUN_004233d0(in_EAX,(int)local_14,uVar8);
    FUN_004225a0(in_EAX,uVar2);
    FUN_004225a0(in_EAX,uVar3);
    FUN_004225a0(in_EAX,0);
    if (in_EAX + 3 < in_EAX) {
      do {
        FUN_004233d0(in_EAX,(int)local_14,uVar2);
        FUN_004225a0(in_EAX,uVar3);
        FUN_004225a0(in_EAX,uVar8 - 3);
        FUN_004225a0(in_EAX,0);
      } while( true );
    }
    FUN_00421dd0(local_20);
    FUN_004221b0(local_20,in_EAX,in_EAX + 3);
    iVar7 = FUN_00421e00((int)local_20,1);
    while (iVar7 != 0) {
      FUN_00423460(in_EAX,(int)in_EAX,2);
      FUN_004221b0(local_20,in_EAX,in_EAX + 3);
      iVar7 = FUN_00421e00((int)local_20,1);
    }
    FUN_00422750(local_20);
  }
  else {
    FUN_00423440((int)in_EAX,param_2);
  }
  piVar5 = in_EAX + 3;
  iVar7 = FUN_004236b0(piVar5,(int)in_EAX,(int)piVar5);
  if ((iVar7 != 0) && (iVar7 = FUN_004236b0(in_EAX + 0x15,(int)puVar1,(int)puVar4), iVar7 != 0)) {
    FUN_00421e50(in_EAX + 0xf,piVar5,in_EAX + 0xf);
    FUN_00421e50(in_EAX + 0x12,piVar5,in_EAX + 0x12);
    FUN_00421ef0(in_EAX + 6,puVar1,puVar4);
  }
  return;
}

