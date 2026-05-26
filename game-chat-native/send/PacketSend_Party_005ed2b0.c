/*
 * Game.exe — PacketSend_Party
 * VA solicitado: 0x005ED2B0
 * Entry Ghidra:  005ed2b0
 * Ghidra name:   FUN_005ed2b0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: send
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005ed2b0(byte param_1,undefined4 param_2,byte param_3,void *param_4)

{
  short local_2004;
  byte local_2002;
  undefined local_2001 [8189];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_2004;
  local_2004 = (((ushort)param_1 - (ushort)param_1) - (ushort)(param_1 != 0) & 0xe000) + 0x1103;
  local_2002 = param_3;
  _memcpy(local_2001,param_4,(uint)param_3);
  FUN_005ea9a0(&local_2004,param_3 + 3);
  ___security_check_cookie_4();
  return;
}

