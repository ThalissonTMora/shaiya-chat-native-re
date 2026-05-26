/*
 * server/ps_game.exe — SSyncMap_Begin
 * VA solicitado: 0x0043A7A0
 * Entry Ghidra:  0043a7a0
 * Ghidra name:   FUN_0043a7a0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_0043a7a0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int unaff_ESI;
  
  uVar1 = **(undefined4 **)(unaff_ESI + 0x30);
  *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_ESI + 0x44) = uVar1;
  iVar3 = *(int *)(unaff_ESI + 0x30);
  if ((*(int *)(unaff_ESI + 0x40) == 0) ||
     (*(int *)(unaff_ESI + 0x40) != *(int *)(unaff_ESI + 0x18))) {
    FUN_0051b1ad();
  }
  if (*(int *)(unaff_ESI + 0x44) == iVar3) {
    return 0;
  }
  piVar2 = *(int **)(unaff_ESI + 0x40);
  if (piVar2 == (int *)0x0) {
    FUN_0051b1ad();
    piVar2 = *(int **)(unaff_ESI + 0x40);
    if (piVar2 == (int *)0x0) {
      iVar3 = 0;
      goto LAB_0043a7e3;
    }
  }
  iVar3 = *piVar2;
LAB_0043a7e3:
  if (*(int *)(unaff_ESI + 0x44) == *(int *)(iVar3 + 0x18)) {
    FUN_0051b1ad();
  }
  return *(undefined4 *)(*(int *)(unaff_ESI + 0x44) + 0x10);
}

