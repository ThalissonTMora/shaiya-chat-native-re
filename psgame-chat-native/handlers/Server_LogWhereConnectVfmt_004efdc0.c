/*
 * server/ps_game.exe — Server_LogWhereConnectVfmt
 * Requested VA: 0x004EFDC0
 * Entry Ghidra:  004efdc0
 * Ghidra name:   FUN_004efdc0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004efdc0(int param_1,char *param_2)

{
  _SYSTEMTIME local_4114;
  char acStack_4104 [256];
  char acStack_4004 [16384];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_4114;
  if (*(int *)(param_1 + 4) == 0) {
    ___security_check_cookie_4();
    return;
  }
  GetLocalTime(&local_4114);
  _sprintf(acStack_4104,"%.4d-%.2d-%.2d %.2d:%.2d:%.2d",(uint)local_4114.wYear,
           (uint)local_4114.wMonth,(uint)local_4114.wDay,(uint)local_4114.wHour,
           (uint)local_4114.wMinute,(uint)local_4114.wSecond);
  _vsprintf(acStack_4004,param_2,&stack0x0000000c);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  _fprintf(*(FILE **)(param_1 + 4),"%s %s\r\n",acStack_4104,acStack_4004);
  _fflush(*(FILE **)(param_1 + 4));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  ___security_check_cookie_4();
  return;
}

