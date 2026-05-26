/*
 * server/ps_game.exe — Script_ExecuteTick
 * Requested VA: 0x004A4710
 * Entry Ghidra:  004a4710
 * Ghidra name:   FUN_004a4710
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004a4710(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *unaff_ESI;
  int local_24;
  int *local_20;
  int local_1c;
  undefined **local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00551548;
  local_c = ExceptionList;
  uVar2 = DAT_0057f7c4 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_c;
  local_24 = 0;
  iVar3 = unaff_ESI[0x1a];
  while (iVar3 != 0) {
    if ((unaff_ESI[0x1a] != 0) &&
       (iVar3 = unaff_ESI[0x1a] + -1, unaff_ESI[0x1a] = iVar3, iVar3 == 0)) {
      unaff_ESI[0x19] = 0;
    }
    iVar3 = unaff_ESI[0x1a];
  }
  FUN_004a5c90(&local_20,&local_24);
  iVar3 = unaff_ESI[8];
  if ((local_20 == (int *)0x0) || (local_20 != (int *)unaff_ESI[3])) {
    FUN_0051b1ad(uVar2);
  }
  if (local_1c != iVar3) {
    if (local_20 == (int *)0x0) {
      FUN_0051b1ad(uVar2);
      iVar3 = 0;
    }
    else {
      iVar3 = *local_20;
    }
    if (local_1c == *(int *)(iVar3 + 0x14)) {
      FUN_0051b1ad(uVar2);
    }
    iVar3 = *(int *)(local_1c + 0xc);
    local_24 = iVar3;
    FUN_004a5720(&local_24);
    local_18 = StackStateMachine<class_CMob,-1>::EventObject::vftable;
    local_14 = 0xffffffff;
    local_10 = 0;
    local_4 = 0;
    pcVar1 = *(code **)(iVar3 + 0x60);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(&local_18);
    }
    ExceptionList = local_c;
    return;
  }
  (**(code **)(*unaff_ESI + 4))();
  FUN_004a3e70();
  ExceptionList = local_c;
  return;
}

