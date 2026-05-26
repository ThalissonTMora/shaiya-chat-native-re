/*
 * Game.exe — NetworkSendKeyBlob
 * Requested VA: 0x005EC610
 * Entry Ghidra:  005ec610
 * Ghidra name:   FUN_005ec610
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005ec610(undefined4 *param_1,undefined4 *param_2,char param_3)

{
  int iVar1;
  undefined4 *puVar2;
  short sStack_2004;
  undefined4 auStack_2002 [8];
  undefined4 uStack_1fe2;
  undefined4 uStack_1fde;
  undefined4 uStack_1fda;
  undefined4 uStack_1fd6;
  uint uStack_4;
  
  uStack_4 = DAT_007b4dd0 ^ (uint)&sStack_2004;
  sStack_2004 = (ushort)(param_3 != '\0') * 4 + -0x5efe;
  uStack_1fde = param_2[1];
  puVar2 = auStack_2002;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  uStack_1fe2 = *param_2;
  uStack_1fda = param_2[2];
  uStack_1fd6 = param_2[3];
  FUN_005ea9a0(&sStack_2004,0x32);
  FUN_00630c8a();
  return;
}

