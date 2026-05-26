/*
 * Game.exe — ChatBalloon_DrawProjected
 * VA solicitado: 0x00420010
 * Entry Ghidra:  00420010
 * Ghidra name:   FUN_00420010
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: balloon
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00420010(int param_1_00,undefined4 param_1,float param_2)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  int *piStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  int *piStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  float *pfStack_a0;
  undefined *puStack_9c;
  int local_94;
  float local_88;
  float local_84;
  undefined4 local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  double local_8;
  
  if (DAT_007c0de4 != 0) {
    puStack_9c = (undefined *)&param_1;
    param_2 = *(float *)(param_1_00 + 0xc) + param_2;
    pfStack_a0 = &local_88;
    piStack_a4 = (int *)0x42004e;
    FUN_00573ff0();
    local_94 = 0;
    if (*(int *)(param_1_00 + 8) != 0) {
      local_94 = *(int *)(*(int *)(param_1_00 + 8) + 4);
    }
    local_3c = (float)_DAT_00748068;
    local_68 = 0x80484848;
    local_4c = 0x80484848;
    local_30 = 0x80484848;
    local_8 = (double)((float)local_94 * local_3c);
    local_14 = 0x80484848;
    fVar2 = (local_88 - (float)local_94 * local_3c) - (float)_DAT_00748408;
    local_7c = local_84 - (float)_DAT_00748408;
    local_78 = fVar2 - local_3c;
    local_74 = local_7c - local_3c;
    local_70 = local_80;
    local_6c = 0x3f800000;
    local_64 = 0;
    local_60 = 0;
    local_5c = ((float)(local_94 + 0x14) + fVar2) - local_3c;
    local_54 = local_80;
    local_50 = 0x3f800000;
    local_48 = 0x3f800000;
    local_44 = 0;
    local_3c = (local_7c + (float)_DAT_007480d0) - local_3c;
    local_38 = local_80;
    local_34 = 0x3f800000;
    local_2c = 0x3f800000;
    local_28 = 0x3f800000;
    local_18 = 0x3f800000;
    local_1c = local_80;
    local_10 = 0;
    local_c = 0x3f800000;
    puStack_9c = (undefined *)0x42018f;
    local_58 = local_74;
    local_40 = local_5c;
    local_24 = local_78;
    local_20 = local_3c;
    FUN_00574ea0();
    puStack_9c = (undefined *)0x1;
    pfStack_a0 = (float *)0x42019b;
    FUN_005740c0();
    puStack_9c = (undefined *)0x4;
    pfStack_a0 = (float *)0x17;
    piStack_a4 = DAT_022b69a8;
    uStack_a8 = 0x4201af;
    (**(code **)(*DAT_022b69a8 + 0xe4))();
    uStack_a8 = 5;
    uStack_ac = 0x13;
    piStack_b0 = DAT_022b69a8;
    uStack_b4 = 0x4201c3;
    (**(code **)(*DAT_022b69a8 + 0xe4))();
    uStack_b4 = 6;
    uStack_b8 = 0x14;
    piStack_bc = DAT_022b69a8;
    uStack_c0 = 0x4201d7;
    (**(code **)(*DAT_022b69a8 + 0xe4))();
    uStack_c0 = 2;
    uStack_c4 = 4;
    uStack_c8 = 0;
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,5,0);
    (**(code **)(*DAT_022b69a8 + 0x104))(DAT_022b69a8,0,0);
    (**(code **)(*DAT_022b69a8 + 0x14c))(DAT_022b69a8,6,2,&uStack_c8,0x1c);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,4,4);
    uVar6 = 5;
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,5,0);
    (**(code **)(*DAT_022b69a8 + 0x10c))(DAT_022b69a8,0,6,2);
    iVar1 = *(int *)(param_1_00 + 8);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      uVar3 = FUN_00631be0(uVar6,0xffffffff);
      uVar4 = FUN_00631be0(uVar3);
      FUN_0057ca20(iVar1,uVar4,uVar3,uVar6,uVar5);
    }
  }
  return;
}

