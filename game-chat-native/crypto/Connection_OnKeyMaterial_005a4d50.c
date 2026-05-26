/*
 * Game.exe — Connection_OnKeyMaterial
 * Requested VA: 0x005A4D50
 * Entry Ghidra:  005a4d50
 * Ghidra name:   FUN_005a4d50
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __thiscall
FUN_005a4d50(int param_1,undefined param_2,undefined param_3,undefined param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 uStack_88;
  undefined auStack_84 [128];
  uint uStack_4;
  
  uStack_4 = DAT_007b4dd0 ^ (uint)&uStack_88;
  FUN_00401100(auStack_84,&uStack_88,param_2,param_5,param_3,param_6,param_4);
  FUN_005ec5a0(uStack_88,auStack_84);
  FUN_00401310();
  *(undefined4 *)(param_1 + 0x224) = 1;
  FUN_00630c8a();
  return;
}

