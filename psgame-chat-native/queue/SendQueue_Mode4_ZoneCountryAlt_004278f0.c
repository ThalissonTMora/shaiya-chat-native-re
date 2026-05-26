/*
 * server/ps_game.exe — SendQueue_Mode4_ZoneCountryAlt
 * VA solicitado: 0x004278F0
 * Entry Ghidra:  004278f0
 * Ghidra name:   FUN_004278f0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004278f0(int param_1,char param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x18c));
  iVar1 = *(int *)(*(int *)(unaff_EBX + 0x184) + 4);
  if (iVar1 != *(int *)(unaff_EBX + 0x184)) {
    do {
      if (iVar1 == 0) break;
      iVar3 = *(int *)(iVar1 + 8);
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = iVar3 + -0xd0;
      }
      if (param_2 == *(char *)(iVar2 + 0x12d)) {
        if (iVar3 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = iVar3 + -0xd0;
        }
        if (*(int *)(iVar2 + 0xdc) != param_3) {
          if (iVar3 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = iVar3 + -0xd0;
          }
          if (*(int *)(iVar2 + 0xdc) != param_4) {
            if (iVar3 == 0) {
              iVar3 = 0;
            }
            else {
              iVar3 = iVar3 + -0xd0;
            }
            if ((*(int *)(iVar3 + 0x68) != -1) && (*(int *)(iVar3 + 0x104) < 0x800)) {
              InterlockedIncrement((LONG *)(param_1 + 8));
              FUN_004f6f00(param_1,param_5,65000);
            }
            goto LAB_004279ce;
          }
        }
        FUN_004ed0b0(param_1);
      }
LAB_004279ce:
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != *(int *)(unaff_EBX + 0x184));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x18c));
  return;
}

