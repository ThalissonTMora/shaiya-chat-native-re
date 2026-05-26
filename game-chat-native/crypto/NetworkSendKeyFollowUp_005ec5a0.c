/*
 * Game.exe — NetworkSendKeyFollowUp
 * Requested VA: 0x005EC5A0
 * Entry Ghidra:  005ec5a0
 * Ghidra name:   FUN_005ec5a0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005ec5a0(undefined param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 local_2004;
  undefined local_2002;
  undefined4 local_2001 [2047];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_2004;
  local_2002 = param_1;
  local_2004 = 0xa101;
  puVar2 = local_2001;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_005ea9a0(&local_2004,0x83);
  ___security_check_cookie_4();
  return;
}

