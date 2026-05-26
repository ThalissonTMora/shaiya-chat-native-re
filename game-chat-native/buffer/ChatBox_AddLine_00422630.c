/*
 * Game.exe — ChatBox_AddLine
 * VA solicitado: 0x00422630
 * Entry Ghidra:  00422630
 * Ghidra name:   FUN_00422630
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_00422630(int param_1_00,int param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  
  if (((((param_1 == 0xf) || (param_1 == 0x10)) || (param_1 == 0x12)) ||
      (((param_1 == 0x11 || (param_1 == 0x13)) ||
       ((param_1 == 0x14 || ((param_1 == 0x15 || (param_1 == 0x16)))))))) ||
     ((param_1 == 0x1f ||
      (((((param_1 == 0x17 || (param_1 == 0x18)) || (param_1 == 0x19)) ||
        ((param_1 == 0x1c || (param_1 == 0x1d)))) || (param_1 == 0x1e)))))) {
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
  }
  iVar1 = param_1_00 + iVar7 * 0xc;
  piVar3 = *(int **)(iVar1 + 4);
  piVar4 = (int *)piVar3[1];
  iVar6 = piVar4[2];
  if (piVar4 != piVar3) {
    *(int *)piVar4[1] = *piVar4;
    *(int *)(*piVar4 + 4) = piVar4[1];
    param_1 = iVar6;
                    /* WARNING: Subroutine does not return */
    FUN_006307cd(piVar4);
  }
  pcVar5 = param_2;
  do {
    cVar2 = *pcVar5;
    pcVar5[iVar6 - (int)param_2] = cVar2;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  *(int *)(iVar6 + 0x104) = param_1;
  param_1 = iVar6;
  FUN_004207f0(iVar6);
  iVar1 = **(int **)(iVar1 + 4);
  iVar6 = FUN_00450d10(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00437f40(1);
  *(int *)(iVar1 + 4) = iVar6;
  **(int **)(iVar6 + 4) = iVar6;
  piVar3 = (int *)(param_1_00 + 0x18 + iVar7 * 4);
  *piVar3 = *piVar3 + 1;
  if (100 < *(int *)(param_1_00 + 0x18 + iVar7 * 4)) {
    *(undefined4 *)(param_1_00 + 0x18 + iVar7 * 4) = 100;
  }
  return;
}

