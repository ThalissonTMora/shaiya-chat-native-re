/*
 * server/ps_game.exe — Chat_LogGameLogA
 * VA solicitado: 0x0047F0E0
 * Entry Ghidra:  0047f0e0
 * Ghidra name:   FUN_0047f0e0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_0047f0e0(size_t param_1_00,void *param_2_00,int param_1,undefined param_2)

{
  size_t _Size;
  size_t *psVar1;
  size_t local_9c;
  size_t local_98;
  undefined2 local_94;
  undefined4 local_92;
  undefined4 local_8e;
  undefined2 local_8a;
  undefined local_88;
  undefined local_87;
  undefined local_86 [130];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_9c;
  local_98 = param_1_00;
  local_9c = 0x7f;
  psVar1 = &local_98;
  if (0x7e < (int)param_1_00) {
    psVar1 = &local_9c;
  }
  _Size = *psVar1;
  local_94 = 0x901;
  local_92 = *(undefined4 *)(param_1 + 0x582c);
  local_8e = *(undefined4 *)(param_1 + 0x128);
  local_8a = *(undefined2 *)(param_1 + 0x160);
  local_88 = param_2;
  local_87 = (undefined)_Size;
  _memcpy(local_86,param_2_00,_Size);
  local_86[_Size] = 0;
  FUN_004ed210(&local_94,_Size + 0xe);
  ___security_check_cookie_4();
  return;
}

