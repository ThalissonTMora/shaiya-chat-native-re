/*
 * server/ps_game.exe — Zone_IterCellUserSendPacket
 * Requested VA: 0x0042AE60
 * Entry Ghidra:  0042ae60
 * Ghidra name:   FUN_0042ae60
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: spatial
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0042ae60(undefined4 param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int *unaff_EDI;
  float10 fVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 2));
  iVar2 = *(int *)(*unaff_EDI + 0xc);
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = iVar2 + -8;
  }
  if ((iVar4 != *unaff_EDI) && (iVar2 != 0)) {
    while (iVar2 != 8) {
      fVar1 = *param_2 - *(float *)(iVar2 + 200);
      fVar3 = param_2[2] - *(float *)(iVar2 + 0xd0);
      fVar5 = (float10)FUN_0041b8a0(fVar1 * fVar1 + fVar3 * fVar3);
      fVar1 = (float)fVar5;
      if ((param_3 < fVar1 != (param_3 == fVar1)) && (fVar1 <= param_4)) {
        FUN_004ed0b0(param_1);
      }
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar2 + -8;
      }
      if ((iVar4 == *unaff_EDI) || (iVar2 == 0)) break;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 2));
  return;
}

