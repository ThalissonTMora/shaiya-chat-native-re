/*
 * server/ps_game.exe — Chat_BuildOutgoing_F502
 * Requested VA: 0x0047F260
 * Entry Ghidra:  0047f260
 * Ghidra name:   FUN_0047f260
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall
FUN_0047f260(size_t param_1_00,void *param_2_00,int param_1,void *param_2,size_t param_3,
            void *param_4,size_t param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  void *local_7f4;
  undefined2 local_7f0;
  char local_7ee [21];
  byte local_7d9;
  undefined local_7d8 [2004];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_7f4;
  local_7f4 = param_4;
  local_7f0 = 0xf502;
  pcVar2 = (char *)(param_1 + 0x184);
  iVar3 = -(int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_7ee + iVar3)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  local_7d8[0] = 0x5b;
  _memcpy(local_7d8 + 1,param_2_00,param_1_00);
  iVar3 = param_1_00 + 1;
  if (param_3 != 0) {
    local_7d8[param_1_00 + 1] = 0x2c;
    _memcpy(local_7d8 + param_1_00 + 2,param_2,param_3);
    iVar3 = param_1_00 + 2 + param_3;
  }
  local_7d8[iVar3] = 0x5d;
  _memcpy(local_7d8 + iVar3 + 1,local_7f4,param_5);
  local_7d9 = (char)param_5 + (char)iVar3 + '\x01';
  FUN_004ed0e0(&local_7f0,local_7d9 + 0x18);
  ___security_check_cookie_4();
  return;
}

