/*
 * server/ps_game.exe — CWorld_InstanceSendEnqueue
 * VA solicitado: 0x00413350
 * Entry Ghidra:  00413350
 * Ghidra name:   FUN_00413350
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413350(undefined4 param_1,undefined param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_EDI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_010a2bfc);
  if (DAT_010a2bf0 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)operator_new(0x20);
    _DAT_010a2bf4 = _DAT_010a2bf4 + 1;
  }
  else {
    _DAT_010a2bf8 = _DAT_010a2bf8 + -1;
    puVar1 = DAT_010a2bf0;
    DAT_010a2bf0 = (undefined4 *)DAT_010a2bf0[1];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_010a2bfc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = in_EAX;
    puVar1[2] = param_1;
    *(undefined *)(puVar1 + 4) = param_2;
    puVar1[7] = param_5;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
    InterlockedIncrement((LONG *)(in_EAX + 8));
    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x21c));
    puVar1[1] = *(undefined4 *)(unaff_EDI + 0x214);
    *puVar1 = **(undefined4 **)(unaff_EDI + 0x214);
    *(undefined4 **)(**(int **)(unaff_EDI + 0x214) + 4) = puVar1;
    **(undefined4 **)(unaff_EDI + 0x214) = puVar1;
    *(int *)(unaff_EDI + 0x234) = *(int *)(unaff_EDI + 0x234) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x21c));
  }
  return;
}

