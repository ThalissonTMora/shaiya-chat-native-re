/*
 * server/ps_game.exe — Cell_SendRadiusInner
 * VA solicitado: 0x0042B0F0
 * Entry Ghidra:  0042b0f0
 * Ghidra name:   FUN_0042b0f0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: spatial
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0042b0f0(float *param_1,float param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *unaff_EBX;
  int unaff_EDI;
  float10 fVar6;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 2));
  iVar1 = *(int *)(*unaff_EBX + 0xc);
  if (iVar1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar1 + -8;
  }
  if ((iVar5 != *unaff_EBX) && (iVar1 != 0)) {
    while (iVar1 != 8) {
      if ((*(int *)(iVar1 + 0xd4) == param_3) || (*(int *)(iVar1 + 0xd4) == param_4)) {
        FUN_004ed0b0(unaff_EDI);
      }
      else {
        fVar2 = *param_1 - *(float *)(iVar1 + 200);
        fVar3 = param_1[2] - *(float *)(iVar1 + 0xd0);
        fVar6 = (float10)FUN_0041b8a0(fVar2 * fVar2 + fVar3 * fVar3);
        if ((((float)fVar6 <= param_2) && (*(int *)(iVar1 + 0x60) != -1)) &&
           (*(int *)(iVar1 + 0xfc) < 0x800)) {
          InterlockedIncrement((LONG *)(unaff_EDI + 8));
          uVar4 = FUN_005250c0();
          FUN_004f6f00(unaff_EDI,param_5,uVar4);
        }
      }
      iVar1 = *(int *)(iVar1 + 4);
      if (iVar1 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar1 + -8;
      }
      if ((iVar5 == *unaff_EBX) || (iVar1 == 0)) break;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 2));
  return;
}

