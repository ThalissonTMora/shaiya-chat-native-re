/*
 * Game.exe — NetworkSend
 * VA solicitado: 0x005EA9A0
 * Entry Ghidra:  005ea9a0
 * Ghidra name:   FUN_005ea9a0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: send
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005ea9a0(undefined2 *param_1,size_t param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort local_1004;
  undefined local_1002 [4094];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_1004;
  if (DAT_007b3434 != 0) {
    FUN_005ea700("SEND>>",*param_1,param_1,param_2);
    uVar1 = (short)param_2 + 2;
    local_1004 = uVar1;
    _memcpy(local_1002,param_1,param_2);
    FUN_00401040(local_1002,param_2);
    iVar3 = send(DAT_022fa304,(char *)&local_1004,param_2 + 2,0);
    if ((iVar3 == -1) &&
       ((iVar3 = WSAGetLastError(), uVar2 = DAT_022fe30c, iVar3 == 0x2733 || (iVar3 == 0x3e5)))) {
      _memcpy(&DAT_022f22e8 + DAT_022fe30c,&local_1004,(uint)uVar1);
      DAT_022fe30c = uVar2 + uVar1;
      if (0x4000 < DAT_022fe30c) {
        MessageBoxA((HWND)0x0,"Send Error!!!","Socket",0);
        DAT_022fe30c = 0;
        ___security_check_cookie_4();
        return;
      }
      WSAAsyncSelect(DAT_022fa304,DAT_022fa2f8,0x2b10,0x23);
    }
  }
  ___security_check_cookie_4();
  return;
}

