/*
 * Game.exe — ChatWindow_MeasureString
 * Requested VA: 0x0057BD90
 * Entry Ghidra:  0057bd90
 * Ghidra name:   FUN_0057bd90
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0057bd90(int *param_1_00,undefined4 param_1,int param_2,int param_3)

{
  undefined4 uStack_7c;
  int iStack_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iStack_78 = *param_1_00;
  if (iStack_78 != 0) {
    local_60 = param_1;
    local_44 = param_1;
    local_28 = param_1;
    local_c = param_1;
    local_74 = (float)_DAT_00748068;
    local_70 = (float)param_2 - local_74;
    uStack_7c = 0;
    local_6c = (float)param_3 - local_74;
    local_68 = 0x3f800000;
    local_64 = 0x3f800000;
    local_5c = 0;
    local_58 = 0;
    local_54 = ((float)param_1_00[2] + (float)param_2) - local_74;
    local_4c = 0x3f800000;
    local_48 = 0x3f800000;
    local_40 = 0x3f800000;
    local_3c = 0;
    local_74 = ((float)param_1_00[3] + (float)param_3) - local_74;
    local_30 = 0x3f800000;
    local_2c = 0x3f800000;
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_14 = 0x3f800000;
    local_10 = 0x3f800000;
    local_8 = 0;
    local_4 = 0x3f800000;
    local_50 = local_6c;
    local_38 = local_54;
    local_34 = local_74;
    local_1c = local_70;
    local_18 = local_74;
    (**(code **)(*DAT_022b69a8 + 0x104))(DAT_022b69a8);
    (**(code **)(*DAT_022b69a8 + 0x14c))(DAT_022b69a8,6,2,&uStack_7c,0x1c);
  }
  return;
}

