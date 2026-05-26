/*
 * Game.exe — PacketSend_Whisper
 * VA solicitado: 0x005ED160
 * Entry Ghidra:  005ed160
 * Ghidra name:   FUN_005ed160
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: send
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005ed160(byte param_1,undefined4 *param_2,byte param_3,void *param_4)

{
  short local_2004;
  undefined4 local_2002;
  undefined4 local_1ffe;
  undefined4 local_1ffa;
  undefined4 local_1ff6;
  undefined4 local_1ff2;
  undefined local_1fee;
  byte local_1fed;
  undefined local_1fec [8168];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_2004;
  local_2004 = (((ushort)param_1 - (ushort)param_1) - (ushort)(param_1 != 0) & 0xe000) + 0x1102;
  local_2002 = *param_2;
  local_1ffe = param_2[1];
  local_1ffa = param_2[2];
  local_1ff6 = param_2[3];
  local_1ff2 = param_2[4];
  local_1fee = *(undefined *)(param_2 + 5);
  local_1fed = param_3;
  _memcpy(local_1fec,param_4,(uint)param_3);
  FUN_005ea9a0(&local_2004,param_3 + 0x18);
  ___security_check_cookie_4();
  return;
}

