/*
 * Game.exe — PacketSend_Chat
 * Requested VA: 0x005ED060
 * Entry Ghidra:  005ed060
 * Ghidra name:   FUN_005ed060
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: send
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005ed060(char param_1,undefined param_2,byte param_3,void *param_4)

{
  undefined2 local_2008 [2];
  undefined2 local_2004;
  byte local_2002;
  undefined local_2001 [8189];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_2008;
  if (param_1 == '\0') {
    switch(param_2) {
    case 0:
      local_2008[0] = 0x1101;
      break;
    case 1:
      local_2008[0] = 0x1103;
      break;
    case 2:
      local_2008[0] = 0x1104;
      break;
    case 3:
      local_2008[0] = 0x1105;
      break;
    case 4:
      local_2008[0] = 0x1107;
    }
  }
  else {
    switch(param_2) {
    case 0:
      local_2008[0] = 0xf101;
      break;
    case 1:
      local_2008[0] = 0xf103;
      break;
    case 2:
      local_2008[0] = 0xf104;
      break;
    case 3:
      local_2008[0] = 0xf105;
    }
  }
  local_2002 = param_3;
  local_2004 = local_2008[0];
  _memcpy(local_2001,param_4,(uint)param_3);
  FUN_005ea9a0(&local_2004,param_3 + 3);
  ___security_check_cookie_4();
  return;
}

