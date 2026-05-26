/*
 * ps_game.exe — Connection_EncryptOutbound
 * Requested VA: 0x00464F20
 * Entry Ghidra:  00464f20
 * Ghidra name:   FUN_00464f20
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void __fastcall FUN_00464f20(undefined4 param_1,int param_2)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  byte *pbVar4;
  
  if (*(char *)(param_2 + 0x232) == '\0') {
    if (*(char *)(param_2 + 0x231) == '\0') {
      return;
    }
    if (*(int *)(in_EAX + 0xc) != 0) {
      return;
    }
    FUN_004e4180(**(ushort **)(in_EAX + 4) - 2);
  }
  else {
    if (*(int *)(in_EAX + 0xc) != 0) {
      return;
    }
    uVar1 = (uint)**(ushort **)(in_EAX + 4);
    iVar2 = uVar1 - 2;
    puVar3 = *(ushort **)(in_EAX + 4) + 1;
    pbVar4 = &DAT_005868be + uVar1;
    if (0 < iVar2) {
      do {
        *(byte *)puVar3 = *(byte *)puVar3 ^ *pbVar4;
        puVar3 = (ushort *)((int)puVar3 + 1);
        pbVar4 = pbVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      InterlockedIncrement((LONG *)(in_EAX + 0xc));
      return;
    }
  }
  InterlockedIncrement((LONG *)(in_EAX + 0xc));
  return;
}

