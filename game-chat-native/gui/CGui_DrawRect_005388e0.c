/*
 * Game.exe — CGui_DrawRect
 * VA solicitado: 0x005388E0
 * Entry Ghidra:  005388e0
 * Ghidra name:   FUN_005388e0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: gui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005388e0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (param_7 == 0) {
    FUN_0057b990(param_6,param_1,param_2,4,4,0,_DAT_0074815c,0,_DAT_0074815c);
    iVar2 = param_1 + 4;
    FUN_0057b990(param_6,iVar2,param_2,param_3,4,_DAT_0074815c,_DAT_00748160,0,_DAT_0074815c);
    param_3 = param_1 + 4 + param_3;
    FUN_0057b990(param_6,param_3,param_2,4,4,_DAT_00748160,_DAT_00748164,0,_DAT_0074815c);
    FUN_0057b990(param_6,param_1,param_2 + 4,4,param_4 + 4,_DAT_0074815c,_DAT_00748160,_DAT_0074815c
                 ,_DAT_00748160);
    FUN_0057b990(param_6,param_3,param_2 + 4,4,param_4 + 4,_DAT_00748164,0x3f800000,_DAT_0074815c,
                 _DAT_00748160);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,1,2);
    uVar6 = 0;
    piVar4 = DAT_022b69a8;
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,2,0);
    uVar5 = 2;
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,4);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,5,0);
    FUN_0057b990(uVar6,iVar2,param_2 + 4,uVar5,piVar4 + 1,_DAT_00748160,_DAT_00748164,_DAT_00748160,
                 _DAT_00748164);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,1,4);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,2,2);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,3,1);
    piVar4 = DAT_022b69a8;
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,4);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,5);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,6,2);
    iVar1 = param_2 + 8 + (int)piVar4;
    FUN_0057b990(param_6,param_1,iVar1,4,4,0,_DAT_0074815c,_DAT_0074815c,_DAT_00748160);
    FUN_0057b990(param_6,iVar2,iVar1,0,4,_DAT_00748164,0x3f800000,0,_DAT_0074815c);
    FUN_0057b990(param_6,4,iVar1,4,4,_DAT_00748160,_DAT_00748164,_DAT_0074815c,_DAT_00748160);
    return;
  }
  FUN_0057b860(param_1,param_2);
  param_4 = param_4 / 0xf;
  iVar2 = 0;
  if (0 < param_4) {
    iVar3 = param_2 + 8;
    iVar1 = param_4;
    do {
      FUN_0057b860(param_1,iVar3);
      iVar3 = iVar3 + 0xf;
      iVar1 = iVar1 + -1;
      iVar2 = param_4;
    } while (iVar1 != 0);
  }
  FUN_0057b860(param_1,iVar2 * 0xf + 8 + param_2);
  return;
}

