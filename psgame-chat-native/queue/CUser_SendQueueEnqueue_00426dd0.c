/*
 * server/ps_game.exe — CUser_SendQueueEnqueue
 * VA solicitado: 0x00426DD0
 * Entry Ghidra:  00426dd0
 * Ghidra name:   FUN_00426dd0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426dd0(int param_1,undefined param_2,int param_3,undefined4 param_4,int param_5)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  if ((param_1 == 5) && (param_5 == 0)) {
    if (*(int *)(unaff_EDI + 0x28) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x28) + 0x78);
    }
    if (iVar1 != param_3) {
      return;
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_010a2c20);
  if (DAT_010a2c14 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)operator_new(0x20);
    _DAT_010a2c18 = _DAT_010a2c18 + 1;
  }
  else {
    _DAT_010a2c1c = _DAT_010a2c1c + -1;
    puVar2 = DAT_010a2c14;
    DAT_010a2c14 = (undefined4 *)DAT_010a2c14[1];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_010a2c20);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[3] = in_EAX;
    puVar2[2] = param_1;
    *(undefined *)(puVar2 + 4) = param_2;
    puVar2[7] = param_5;
    puVar2[5] = param_3;
    puVar2[6] = param_4;
    InterlockedIncrement((LONG *)(in_EAX + 8));
    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x268));
    puVar2[1] = *(undefined4 *)(unaff_EDI + 0x260);
    *puVar2 = **(undefined4 **)(unaff_EDI + 0x260);
    *(undefined4 **)(**(int **)(unaff_EDI + 0x260) + 4) = puVar2;
    **(undefined4 **)(unaff_EDI + 0x260) = puVar2;
    *(int *)(unaff_EDI + 0x280) = *(int *)(unaff_EDI + 0x280) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x268));
  }
  return;
}

