/*
 * server/ps_game.exe — SConnection_DrainWriteQueue
 * Requested VA: 0x004F1CA0
 * Entry Ghidra:  004f1ca0
 * Ghidra name:   FUN_004f1ca0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004f1ca0(int param_1_00,int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION local_88;
  char acStack_84 [128];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_88;
  local_88 = (LPCRITICAL_SECTION)(param_1 + 0x14);
  EnterCriticalSection(local_88);
  if (*(char *)(param_1[0x32] + 0x59) != '\0') {
    (**(code **)(*param_1 + 0x14))(param_2);
  }
  if (param_1[0x11] < *(int *)(param_1[0x32] + 0x14)) {
    if (*(char *)(param_1[0x32] + 8) == '\0') {
      iVar1 = FUN_004f7b20(param_2);
    }
    else {
      iVar1 = FUN_004f7950(param_2);
    }
    if (iVar1 != 0) {
      InterlockedIncrement(param_1 + 0x11);
      FUN_004f1b70(param_1,iVar1);
    }
  }
  else {
    iVar2 = FUN_004f78c0(param_2);
    iVar1 = param_1[0x32];
    if (*(int *)(iVar1 + 0xc) < iVar2) {
      _sprintf(acStack_84,
               "PacketOver nSendCount=%d, MaxOverSize=%d, m_nSendProcessing=%d, m_nMaxSendProcessing=%d"
               ,iVar2,*(undefined4 *)(iVar1 + 0xc),param_1[0x11],*(undefined4 *)(iVar1 + 0x14));
      if (*(int *)(param_1_00 + 0x410) != 0) {
        FUN_004f02e0(1,1,acStack_84);
      }
      FUN_004ec760(0xf,0);
    }
  }
  LeaveCriticalSection(local_88);
  ___security_check_cookie_4();
  return;
}

