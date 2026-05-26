/*
 * Game.exe — ChatWindow_DrawTextStyled
 * Requested VA: 0x00573D70
 * Entry Ghidra:  00573d70
 * Ghidra name:   FUN_00573d70
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall
FUN_00573d70(int param_1_00,undefined4 param_1,undefined4 param_2,byte param_3,byte param_4,
            byte param_5,undefined4 param_6,int param_7)

{
  if ((*(int *)(param_1_00 + 0x3a4) != 0) && (param_7 == 1)) {
    FUN_0057d570((int *)(param_1_00 + 0x3a4),param_6,param_1,param_2,0,0,
                 ((param_3 | 0xffffff00) << 8 | (uint)param_4) << 8 | (uint)param_5);
    return;
  }
  FUN_0057d570(param_1_00 + 0x3a8,param_6,param_1,param_2,0,0,
               ((param_3 | 0xffffff00) << 8 | (uint)param_4) << 8 | (uint)param_5);
  return;
}

