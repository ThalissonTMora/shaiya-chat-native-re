/*
 * Game.exe — ChatBox_SetLineDrawMode
 * VA solicitado: 0x00437F40
 * Entry Ghidra:  00437f40
 * Ghidra name:   FUN_00437f40
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_00437f40(int param_1_00,uint param_1)

{
  int iVar1;
  int extraout_ECX;
  undefined8 uVar2;
  undefined local_50 [4];
  undefined local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00738ed8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = *(int *)(param_1_00 + 8);
  if (0x3fffffffU - iVar1 < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    FUN_00405670("list<T> too long",0x10);
    local_4 = 0;
    FUN_00408b80(local_50);
    local_34[0] = std::length_error::vftable;
    uVar2 = __CxxThrowException_8(local_34,&DAT_007985d0);
    param_1 = (uint)((ulonglong)uVar2 >> 0x20);
    iVar1 = (int)uVar2;
    param_1_00 = extraout_ECX;
  }
  *(uint *)(param_1_00 + 8) = iVar1 + param_1;
  ExceptionList = local_c;
  return;
}

