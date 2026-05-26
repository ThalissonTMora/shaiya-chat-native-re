/*
 * Game.exe — ChatWindow_WhisperHighlight
 * Requested VA: 0x0047F970
 * Entry Ghidra:  0047f970
 * Ghidra name:   FUN_0047f970
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_0047f970(int param_1_00,char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined auStack_124 [4];
  int *local_120;
  char *local_11c;
  int local_118 [67];
  uint local_c;
  
  local_c = DAT_007b4dd0 ^ (uint)auStack_124;
  local_11c = param_1;
  *(undefined4 *)(param_1_00 + 0x75cc) = 0;
  if (param_1 == (char *)0x0) {
    local_11c = (char *)(param_1_00 + 0x198);
  }
  pcVar2 = local_11c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (pcVar2 != local_11c + 1) {
    local_120 = (int *)**(int **)(param_1_00 + 0x75ac);
    if (local_120 != *(int **)(param_1_00 + 0x75ac)) {
      do {
        piVar4 = local_120 + 2;
        piVar5 = local_118;
        for (iVar3 = 0x41; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
        pcVar2 = local_11c;
        do {
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        iVar3 = _strncmp(local_11c,(char *)local_118,(int)pcVar2 - (int)(local_11c + 1));
        if (iVar3 == 0) goto LAB_0047fabf;
        *(int *)(param_1_00 + 0x75cc) = *(int *)(param_1_00 + 0x75cc) + 1;
        local_120 = (int *)*local_120;
      } while (local_120 != (int *)*(int *)(param_1_00 + 0x75ac));
    }
    if ((9 < *(uint *)(param_1_00 + 0x75b0)) &&
       (piVar4 = (int *)**(int **)(param_1_00 + 0x75ac), piVar4 != *(int **)(param_1_00 + 0x75ac)))
    {
      *(int *)piVar4[1] = *piVar4;
      *(int *)(*piVar4 + 4) = piVar4[1];
                    /* WARNING: Subroutine does not return */
      FUN_006307cd(piVar4);
    }
    pcVar2 = local_11c;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)local_118 - (int)local_11c] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar3 = *(int *)(param_1_00 + 0x75ac);
    local_120 = (int *)FUN_0047d100(iVar3,*(undefined4 *)(iVar3 + 4),local_118);
    FUN_0047f140(1);
    *(int **)(iVar3 + 4) = local_120;
    *(int **)local_120[1] = local_120;
    *(int *)(param_1_00 + 0x75c4) = *(int *)(param_1_00 + 0x75b0) + -1;
  }
LAB_0047fabf:
  ___security_check_cookie_4();
  return;
}

