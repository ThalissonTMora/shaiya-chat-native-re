/*
 * server/ps_game.exe — Cell_SendRadiusOuter
 * Requested VA: 0x0042B210
 * Entry Ghidra:  0042b210
 * Ghidra name:   FUN_0042b210
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: spatial
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0042b210(float *param_1,float param_2,float param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  float fVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *unaff_EBX;
  int unaff_EDI;
  float10 fVar6;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 2));
  iVar2 = *(int *)(*unaff_EBX + 0xc);
  if (iVar2 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar2 + -8;
  }
  if ((iVar5 != *unaff_EBX) && (iVar2 != 0)) {
    while (iVar2 != 8) {
      if ((*(int *)(iVar2 + 0xd4) == param_4) || (*(int *)(iVar2 + 0xd4) == param_5)) {
        FUN_004ed0b0(unaff_EDI);
      }
      else {
        fVar1 = *param_1 - *(float *)(iVar2 + 200);
        fVar3 = param_1[2] - *(float *)(iVar2 + 0xd0);
        fVar6 = (float10)FUN_0041b8a0(fVar1 * fVar1 + fVar3 * fVar3);
        fVar1 = (float)fVar6;
        if ((((param_2 < fVar1 != (param_2 == fVar1)) && (fVar1 <= param_3)) &&
            (*(int *)(iVar2 + 0x60) != -1)) && (*(int *)(iVar2 + 0xfc) < 0x800)) {
          InterlockedIncrement((LONG *)(unaff_EDI + 8));
          uVar4 = FUN_005250c0();
          FUN_004f6f00(unaff_EDI,param_6,uVar4);
        }
      }
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar2 + -8;
      }
      if ((iVar5 == *unaff_EBX) || (iVar2 == 0)) break;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 2));
  return;
}

