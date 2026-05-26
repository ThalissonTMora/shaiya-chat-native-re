/*
 * server/ps_game.exe — Recv_PostDispatchCleanup
 * VA solicitado: 0x004F33A0
 * Entry Ghidra:  004f33a0
 * Ghidra name:   FUN_004f33a0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: pipeline
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004f33a0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x20) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00583748);
    param_1[4] = (int)DAT_00583724;
    DAT_00583744 = DAT_00583744 + 1;
    DAT_00583724 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00583748);
    return;
  }
  if (iVar1 == 0x80) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00583784);
    param_1[4] = (int)DAT_00583760;
    DAT_00583780 = DAT_00583780 + 1;
    DAT_00583760 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00583784);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0058370c);
  param_1[4] = (int)DAT_005836e8;
  DAT_00583708 = DAT_00583708 + 1;
  DAT_005836e8 = param_1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0058370c);
  return;
}

