/*
 * server/ps_game.exe — SSyncMap_IterNext
 * Requested VA: 0x0043A800
 * Entry Ghidra:  0043a800
 * Ghidra name:   FUN_0043a800
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_0043a800(void)

{
  int *piVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)(in_EAX + 0x40);
  FUN_0043dc50();
  iVar3 = *(int *)(in_EAX + 0x30);
  if ((*piVar1 == 0) || (*piVar1 != *(int *)(in_EAX + 0x18))) {
    FUN_0051b1ad();
  }
  if (*(int *)(in_EAX + 0x44) == iVar3) {
    return 0;
  }
  piVar2 = (int *)*piVar1;
  if (piVar2 == (int *)0x0) {
    FUN_0051b1ad();
    piVar2 = (int *)*piVar1;
    if (piVar2 == (int *)0x0) {
      iVar3 = 0;
      goto LAB_0043a83e;
    }
  }
  iVar3 = *piVar2;
LAB_0043a83e:
  if (*(int *)(in_EAX + 0x44) == *(int *)(iVar3 + 0x18)) {
    FUN_0051b1ad();
  }
  return *(undefined4 *)(*(int *)(in_EAX + 0x44) + 0x10);
}

