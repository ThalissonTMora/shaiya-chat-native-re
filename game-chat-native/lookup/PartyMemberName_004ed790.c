/*
 * Game.exe — PartyMemberName
 * Requested VA: 0x004ED790
 * Entry Ghidra:  004ed790
 * Ghidra name:   FUN_004ed790
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


int * __thiscall FUN_004ed790(int param_1_00,int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = (int *)**(int **)(&DAT_0199d554 + param_1_00);
  *(int **)(&DAT_0199d55c + param_1_00) = piVar2;
  if (piVar2 != *(int **)(&DAT_0199d554 + param_1_00)) {
    do {
      piVar2 = *(int **)(*(int *)(&DAT_0199d55c + param_1_00) + 0x10);
      if ((piVar2 != (int *)0x0) && (*piVar2 == param_1)) {
        return piVar2;
      }
      iVar3 = *(int *)(&DAT_0199d55c + param_1_00);
      if (*(char *)(iVar3 + 0x15) == '\0') {
        piVar2 = *(int **)(iVar3 + 8);
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar4 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x15);
            piVar2 = piVar4;
            piVar4 = (int *)*piVar4;
          }
          *(int **)(&DAT_0199d55c + param_1_00) = piVar2;
        }
        else {
          iVar3 = *(int *)(iVar3 + 4);
          cVar1 = *(char *)(iVar3 + 0x15);
          while ((cVar1 == '\0' && (*(int *)(&DAT_0199d55c + param_1_00) == *(int *)(iVar3 + 8)))) {
            *(int *)(&DAT_0199d55c + param_1_00) = iVar3;
            iVar3 = *(int *)(iVar3 + 4);
            cVar1 = *(char *)(iVar3 + 0x15);
          }
          *(int *)(&DAT_0199d55c + param_1_00) = iVar3;
        }
      }
    } while (*(int *)(&DAT_0199d55c + param_1_00) != *(int *)(&DAT_0199d554 + param_1_00));
  }
  return (int *)0x0;
}

