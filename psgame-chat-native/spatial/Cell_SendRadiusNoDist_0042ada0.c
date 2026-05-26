/*
 * server/ps_game.exe — Cell_SendRadiusNoDist
 * VA solicitado: 0x0042ADA0
 * Entry Ghidra:  0042ada0
 * Ghidra name:   FUN_0042ada0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: spatial
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0042ada0(undefined4 param_1,float *param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *unaff_EDI;
  float10 fVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 2));
  iVar1 = *(int *)(*unaff_EDI + 0xc);
  if (iVar1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = iVar1 + -8;
  }
  if ((iVar4 != *unaff_EDI) && (iVar1 != 0)) {
    while (iVar1 != 8) {
      fVar2 = *param_2 - *(float *)(iVar1 + 200);
      fVar3 = param_2[2] - *(float *)(iVar1 + 0xd0);
      fVar5 = (float10)FUN_0041b8a0(fVar2 * fVar2 + fVar3 * fVar3);
      if (fVar5 <= (float10)param_3) {
        FUN_004ed0b0(param_1);
      }
      iVar1 = *(int *)(iVar1 + 4);
      if (iVar1 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar1 + -8;
      }
      if ((iVar4 == *unaff_EDI) || (iVar1 == 0)) break;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 2));
  return;
}

