/*
 * server/ps_game.exe — Chat_BroadcastZone
 * VA solicitado: 0x00427090
 * Entry Ghidra:  00427090
 * Ghidra name:   FUN_00427090
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_00427090(undefined4 param_1_00,int param_1,char param_3)

{
  int iVar1;
  int iVar2;
  LONG LVar3;
  int iVar4;
  
  iVar2 = FUN_004f3dc0(param_1_00);
  if (iVar2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18c));
    iVar1 = *(int *)(*(int *)(param_1 + 0x184) + 4);
    if (iVar1 != *(int *)(param_1 + 0x184)) {
      do {
        if (iVar1 == 0) break;
        if (*(int *)(iVar1 + 8) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar1 + 8) + -0xd0;
        }
        if (param_3 == *(char *)(iVar4 + 0x12d)) {
          FUN_004ed0b0(iVar2);
        }
        iVar1 = *(int *)(iVar1 + 4);
      } while (iVar1 != *(int *)(param_1 + 0x184));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18c));
    LVar3 = InterlockedDecrement((LONG *)(iVar2 + 8));
    if (LVar3 == 0) {
      FUN_004f33a0(iVar2);
    }
  }
  return;
}

