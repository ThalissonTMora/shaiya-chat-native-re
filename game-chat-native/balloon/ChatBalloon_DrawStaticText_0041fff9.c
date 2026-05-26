/*
 * Game.exe — ChatBalloon_DrawStaticText
 * Requested VA: 0x0041FFF9
 * Entry Ghidra:  0041fd80
 * Ghidra name:   FUN_0041fd80
 * NOTE: VA is inside the function (landmark/hook), not the entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: balloon
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fd80(float param_1,float param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int param_6;
  float fVar3;
  float fVar4;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int *piStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  int *piStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int *piStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  
  if ((DAT_007c0de4 != 0) && (param_6 != 0)) {
    fVar3 = (float)_DAT_00748068;
    fVar4 = ((param_1 - (float)*(int *)(param_6 + 4) * fVar3) - (float)_DAT_00748408) - fVar3;
    fVar3 = (param_2 - (float)_DAT_00748408) - fVar3;
    uStack_90 = 0x41fed9;
    FUN_00574ea0();
    uStack_90 = 1;
    uStack_94 = 0x41fee5;
    FUN_005740c0();
    uStack_90 = 4;
    uStack_94 = 0x17;
    piStack_98 = DAT_022b69a8;
    uStack_9c = 0x41fef9;
    (**(code **)(*DAT_022b69a8 + 0xe4))();
    uStack_9c = 5;
    uStack_a0 = 0x13;
    piStack_a4 = DAT_022b69a8;
    uStack_a8 = 0x41ff0d;
    (**(code **)(*DAT_022b69a8 + 0xe4))();
    uStack_a8 = 6;
    uStack_ac = 0x14;
    piStack_b0 = DAT_022b69a8;
    uStack_b4 = 0x41ff21;
    (**(code **)(*DAT_022b69a8 + 0xe4))();
    uStack_b4 = 2;
    uStack_b8 = 4;
    uStack_bc = 0;
    piStack_c0 = DAT_022b69a8;
    uStack_c4 = 0x41ff37;
    (**(code **)(*DAT_022b69a8 + 0x10c))();
    uStack_c4 = 0;
    uStack_c8 = 5;
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0);
    (**(code **)(*DAT_022b69a8 + 0x104))(DAT_022b69a8,0,0);
    (**(code **)(*DAT_022b69a8 + 0x14c))(DAT_022b69a8,6,2,&uStack_c8,0x1c);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,4,4);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,5,0);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,6,2);
    uVar1 = FUN_00631be0(fVar3,fVar4);
    uVar2 = FUN_00631be0(uVar1);
    FUN_0057ca20(param_6,uVar2,uVar1,fVar3,fVar4);
  }
  return;
}

