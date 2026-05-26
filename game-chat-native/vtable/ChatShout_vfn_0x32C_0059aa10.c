/*
 * Game.exe — ChatShout_vfn_0x32C
 * VA solicitado: 0x0059AA10
 * Entry Ghidra:  0059aa10
 * Ghidra name:   FUN_0059aa10
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: vtable
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_0059aa10(undefined4 param_1,undefined4 param_2,undefined *param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char local_20c [260];
  undefined local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_20c;
  _memset(local_20c,0,0x104);
  iVar3 = FUN_00452b10(param_1);
  if (iVar3 != 0) {
    pcVar1 = (char *)(iVar3 + 0x10c);
    pcVar4 = pcVar1;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    pcVar7 = &stack0xfffffdf3;
    do {
      pcVar6 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = pcVar1;
    for (uVar5 = (uint)((int)pcVar4 - (int)pcVar1) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = (int)pcVar4 - (int)pcVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    puVar8 = (undefined4 *)&stack0xfffffdf3;
    do {
      pcVar1 = (char *)((int)puVar8 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    } while (*pcVar1 != '\0');
    *puVar8 = DAT_0075b1fc;
    if (*(char *)(iVar3 + 0x2b7) == DAT_022aa816) {
      FUN_004126d0(param_3);
    }
    else {
      if (param_3 == (undefined *)0x0) goto LAB_0059ab38;
      if (DAT_0090d1d8 == 0) {
        FUN_00421750(param_3,local_108);
      }
      else {
        FUN_00420c10(local_108,param_3);
      }
      FUN_004126d0(local_108);
      param_3 = local_108;
    }
    _sprintf(&DAT_022eed40,"%s%s",local_20c,param_3);
    FUN_00422b90(0x27,&DAT_022eed40,0x34);
  }
LAB_0059ab38:
  ___security_check_cookie_4();
  return;
}

