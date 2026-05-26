/*
 * server/ps_game.exe — Chat_BroadcastTrade
 * VA solicitado: 0x004192F0
 * Entry Ghidra:  004192f0
 * Ghidra name:   FUN_004192f0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004192f0(undefined4 param_1_00,undefined4 param_1)

{
  int iVar1;
  int iVar2;
  LONG LVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar1 = DAT_00587960;
  iVar2 = FUN_004f3dc0(param_1_00);
  iVar4 = 0;
  if (iVar2 != 0) {
    if (0 < *(int *)(iVar1 + 8)) {
      local_4 = 0;
      do {
        if (*(int *)(*(int *)(iVar1 + 4) + 4 + local_4) != 0) {
          FUN_00426dd0(4,param_1,0,0,8);
        }
        local_4 = local_4 + 0x98;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar1 + 8));
    }
    if (*(int *)(iVar1 + 0x380) != 0) {
      FUN_00413350(4,param_1,0,0,8);
    }
    LVar3 = InterlockedDecrement((LONG *)(iVar2 + 8));
    if (LVar3 == 0) {
      FUN_004f33a0(iVar2);
    }
  }
  return;
}

