/*
 * server/ps_game.exe — World_BroadcastTradeCore
 * VA solicitado: 0x00419240
 * Entry Ghidra:  00419240
 * Ghidra name:   FUN_00419240
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall
FUN_00419240(undefined4 param_1_00,undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
    local_4 = 0;
    if (0 < *(int *)(iVar1 + 8)) {
      do {
        if (*(int *)(*(int *)(iVar1 + 4) + 4 + iVar4) != 0) {
          FUN_00426dd0(3,0,param_1,param_2,param_3);
        }
        local_4 = local_4 + 1;
        iVar4 = iVar4 + 0x98;
      } while (local_4 < *(int *)(iVar1 + 8));
    }
    if (*(int *)(iVar1 + 0x380) != 0) {
      FUN_00413350(3,0,param_1,param_2,param_3);
    }
    LVar3 = InterlockedDecrement((LONG *)(iVar2 + 8));
    if (LVar3 == 0) {
      FUN_004f33a0(iVar2);
    }
  }
  return;
}

