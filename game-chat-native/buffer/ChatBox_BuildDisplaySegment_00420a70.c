/*
 * Game.exe — ChatBox_BuildDisplaySegment
 * VA solicitado: 0x00420A70
 * Entry Ghidra:  00420a70
 * Ghidra name:   FUN_00420a70
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00420a70(char *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  uint3 *puVar7;
  char *local_10;
  undefined2 local_c;
  undefined local_a;
  int local_8;
  int local_4;
  
  pcVar3 = param_1;
  bVar2 = false;
  local_10 = (char *)0x0;
  pcVar6 = (char *)0x0;
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (pcVar4 != param_1 + 1) {
    local_4 = 3 - (int)param_1;
    local_8 = 5 - (int)param_1;
    puVar7 = (uint3 *)(param_1 + 2);
    do {
      if (*(char *)((int)puVar7 + -2) == '<') {
        if (((local_10 == (char *)0x0) && (0 < (int)pcVar6)) && (pcVar3[(int)(pcVar6 + -1)] != '<'))
        {
          local_10 = pcVar6;
        }
        pcVar4 = pcVar3;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        if ((pcVar6 < pcVar4 + (-1 - (int)(pcVar3 + 1))) && (pcVar3[(int)(pcVar6 + 1)] == '<')) {
          bVar2 = true;
          pcVar4 = pcVar3;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          if (pcVar4 + (-1 - (int)(pcVar3 + 1)) < (char *)(local_8 + (int)puVar7))
          goto LAB_00420bb5;
          param_1 = (char *)(uint)*puVar7;
          iVar5 = FUN_00631bbc(&param_1);
          if ((iVar5 < 1) || (*(char *)((int)puVar7 + 3) != 'c')) goto LAB_00420bb5;
          local_c = *(undefined2 *)((char *)((int)puVar7 + local_4 + 1) + (int)pcVar3);
          local_a = 0;
          iVar5 = FUN_00631bbc(&local_c);
          if (iVar5 < 1) goto LAB_00420bb5;
        }
      }
      pcVar6 = pcVar6 + 1;
      puVar7 = (uint3 *)((int)puVar7 + 1);
      pcVar4 = pcVar3;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    } while (pcVar6 < pcVar4 + -(int)(pcVar3 + 1));
    if (bVar2) {
      if ((int)(local_10 + 8) <= (int)local_10) {
        return;
      }
      pcVar4 = local_10;
      do {
        param_2[(int)pcVar4 - (int)local_10] = pcVar3[(int)pcVar4];
        pcVar4 = pcVar4 + 1;
      } while ((int)pcVar4 < (int)(local_10 + 8));
      return;
    }
  }
LAB_00420bb5:
  _sprintf(param_2,(char *)&PTR_00746cf4);
  return;
}

