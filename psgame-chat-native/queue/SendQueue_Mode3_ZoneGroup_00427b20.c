/*
 * server/ps_game.exe — SendQueue_Mode3_ZoneGroup
 * Requested VA: 0x00427B20
 * Entry Ghidra:  00427b20
 * Ghidra name:   FUN_00427b20
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: queue
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00427b20(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18c));
  iVar1 = *(int *)(*(int *)(param_1 + 0x184) + 4);
  if (iVar1 != *(int *)(param_1 + 0x184)) {
    do {
      if (iVar1 == 0) break;
      iVar3 = *(int *)(iVar1 + 8);
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = iVar3 + -0xd0;
      }
      if (*(int *)(iVar2 + 0xdc) == param_2) {
LAB_00427bda:
        FUN_004ed0b0(unaff_EBX);
      }
      else {
        if (iVar3 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = iVar3 + -0xd0;
        }
        if (*(int *)(iVar2 + 0xdc) == param_3) goto LAB_00427bda;
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar3 + -0xd0;
        }
        if ((*(int *)(iVar3 + 0x68) != -1) && (*(int *)(iVar3 + 0x104) < 0x800)) {
          InterlockedIncrement((LONG *)(unaff_EBX + 8));
          FUN_004f6f00(unaff_EBX,param_4,65000);
        }
      }
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != *(int *)(param_1 + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18c));
  return;
}

