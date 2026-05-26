/*
 * Game.exe — GmOverlay_AppendText
 * VA solicitado: 0x0047F8B0
 * Entry Ghidra:  0047f8b0
 * Ghidra name:   FUN_0047f8b0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: command
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_0047f8b0(int param_1_00,undefined4 param_1)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_1_00 + 0x14) <= *(int *)(param_1_00 + 0x1c) + 1U) {
    FUN_0047f660(1);
  }
  uVar2 = *(int *)(param_1_00 + 0x18) + *(int *)(param_1_00 + 0x1c);
  if (*(uint *)(param_1_00 + 0x14) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(param_1_00 + 0x14);
  }
  if (*(int *)(*(int *)(param_1_00 + 0x10) + uVar2 * 4) == 0) {
    pvVar1 = operator_new(0x1c);
    *(void **)(*(int *)(param_1_00 + 0x10) + uVar2 * 4) = pvVar1;
  }
  FUN_00408ad0(*(undefined4 *)(*(int *)(param_1_00 + 0x10) + uVar2 * 4),param_1);
  *(int *)(param_1_00 + 0x1c) = *(int *)(param_1_00 + 0x1c) + 1;
  return;
}

