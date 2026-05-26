/*
 * Game.exe — WorldToScreen_ProjectPoint
 * Requested VA: 0x00573FF0
 * Entry Ghidra:  00573ff0
 * Ghidra name:   FUN_00573ff0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: render
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined4 __fastcall FUN_00573ff0(int param_1)

{
  undefined4 uStack_f8;
  undefined *puStack_f4;
  int *piStack_f0;
  undefined4 uStack_ec;
  undefined *puStack_e8;
  int *piStack_e4;
  undefined *puStack_e0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined auStack_a0 [8];
  undefined local_98 [16];
  undefined auStack_88 [40];
  undefined auStack_60 [12];
  undefined auStack_54 [56];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  puStack_e0 = local_98;
  piStack_e4 = DAT_022b69a8;
  puStack_e8 = (undefined *)0x57400e;
  (**(code **)(*DAT_022b69a8 + 0xc0))();
  piStack_f0 = *(int **)(param_1 + 0x414);
  uStack_a8 = 0;
  uStack_ac = 0;
  puStack_e8 = auStack_88;
  uStack_b0 = 0;
  uStack_b4 = 0;
  uStack_ec = 2;
  uStack_a4 = 0x3f800000;
  uStack_b8 = 0x3f800000;
  puStack_e0 = (undefined *)0x3f800000;
  puStack_f4 = (undefined *)0x57406a;
  (**(code **)(*piStack_f0 + 0xb4))();
  puStack_f4 = auStack_54;
  uStack_f8 = 3;
  (**(code **)(**(int **)(param_1 + 0x414) + 0xb4))(*(int **)(param_1 + 0x414));
  thunk_FUN_00658dfe(uStack_1c,uStack_18,&uStack_b8,auStack_60,auStack_a0,&uStack_f8);
  return uStack_1c;
}

