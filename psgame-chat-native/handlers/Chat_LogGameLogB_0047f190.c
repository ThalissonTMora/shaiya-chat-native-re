/*
 * server/ps_game.exe — Chat_LogGameLogB
 * Requested VA: 0x0047F190
 * Entry Ghidra:  0047f190
 * Ghidra name:   FUN_0047f190
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_0047f190(size_t param_1_00,int param_1,int param_2)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  char *pcVar3;
  size_t *psVar4;
  void *unaff_ESI;
  size_t local_b0;
  size_t local_ac;
  undefined2 local_a8;
  undefined4 local_a6;
  undefined4 local_a2;
  undefined2 local_9e;
  undefined local_9c;
  char local_9b [21];
  undefined local_86;
  undefined local_85 [129];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_b0;
  local_ac = param_1_00;
  local_b0 = 0x7f;
  psVar4 = &local_ac;
  if (0x7e < (int)param_1_00) {
    psVar4 = &local_b0;
  }
  local_a6 = *(undefined4 *)(param_1 + 0x582c);
  _Size = *psVar4;
  local_9e = *(undefined2 *)(param_1 + 0x160);
  local_a8 = 0x902;
  local_a2 = *(undefined4 *)(param_1 + 0x128);
  pcVar3 = (char *)(param_2 + 0x184);
  local_9c = 2;
  iVar2 = -(int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)(local_9b + iVar2)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_86 = (undefined)_Size;
  _memcpy(local_85,unaff_ESI,_Size);
  local_85[_Size] = 0;
  FUN_004ed210(&local_a8,_Size + 0x23);
  ___security_check_cookie_4();
  return;
}

