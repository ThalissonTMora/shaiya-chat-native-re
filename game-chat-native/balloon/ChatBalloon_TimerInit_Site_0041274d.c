/*
 * Game.exe — ChatBalloon_TimerInit_Site
 * VA solicitado: 0x0041274D
 * Entry Ghidra:  004126d0
 * Ghidra name:   FUN_004126d0
 * NOTA: VA dentro da função (landmark/hook), não é entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: balloon
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004126d0(int param_1_00,char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0072c77b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (pcVar3 != param_1 + 1) {
    if (*(undefined4 **)(param_1_00 + 0x288) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1_00 + 0x288))(1,DAT_007b4dd0 ^ (uint)&stack0xffffffec);
      *(undefined4 *)(param_1_00 + 0x288) = 0;
    }
    pvVar4 = operator_new(0x10);
    uStack_4 = 0;
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0041fcc0(param_1);
    }
    uVar2 = _DAT_00747538;
    *(int *)(param_1_00 + 0x288) = iVar5;
    *(undefined4 *)(param_1_00 + 0x28c) = uVar2;
    *(undefined4 *)(iVar5 + 0xc) = _DAT_0074823c;
  }
  ExceptionList = local_c;
  return;
}

