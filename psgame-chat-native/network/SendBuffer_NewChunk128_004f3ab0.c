/*
 * server/ps_game.exe — SendBuffer_NewChunk128
 * Requested VA: 0x004F3AB0
 * Entry Ghidra:  004f3ab0
 * Ghidra name:   FUN_004f3ab0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int __fastcall FUN_004f3ab0(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  uint uVar2;
  int iVar3;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0054d568;
  local_c = ExceptionList;
  uVar2 = DAT_0057f7c4 ^ (uint)&stack0xffffffe4;
  ExceptionList = &local_c;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 9);
  EnterCriticalSection(lpCriticalSection);
  uStack_4 = 0;
  if (*param_1 == 0) {
    iVar3 = FUN_004f3650(uVar2);
    if (iVar3 == 0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return 0;
    }
  }
  iVar3 = *param_1;
  iVar1 = *(int *)(iVar3 + 0x10);
  param_1[8] = param_1[8] + -1;
  *param_1 = iVar1;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return iVar3;
}

