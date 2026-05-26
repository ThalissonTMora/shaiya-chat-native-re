/*
 * server/ps_game.exe — World_FindUserById
 * VA solicitado: 0x00415480
 * Entry Ghidra:  00415480
 * Ghidra name:   FUN_00415480
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: lookup
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_00415480(undefined4 param_1)

{
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  PRTL_CRITICAL_SECTION_DEBUG p_Var2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  LPCRITICAL_SECTION unaff_ESI;
  undefined auStack_10 [12];
  
  EnterCriticalSection(unaff_ESI);
  piVar4 = (int *)FUN_00416190(auStack_10,param_1);
  p_Var1 = (PRTL_CRITICAL_SECTION_DEBUG)*piVar4;
  unaff_ESI[2].RecursionCount = (LONG)p_Var1;
  unaff_ESI[2].OwningThread = (HANDLE)piVar4[1];
  p_Var2 = unaff_ESI[2].DebugInfo;
  if ((p_Var1 == (PRTL_CRITICAL_SECTION_DEBUG)0x0) || (p_Var1 != unaff_ESI[1].DebugInfo)) {
    FUN_0051b1ad();
  }
  if ((PRTL_CRITICAL_SECTION_DEBUG)unaff_ESI[2].OwningThread == p_Var2) {
    LeaveCriticalSection(unaff_ESI);
    return 0;
  }
  piVar4 = (int *)unaff_ESI[2].RecursionCount;
  if (piVar4 == (int *)0x0) {
    FUN_0051b1ad();
    piVar4 = (int *)unaff_ESI[2].RecursionCount;
    if (piVar4 == (int *)0x0) {
      iVar5 = 0;
      goto LAB_004154f3;
    }
  }
  iVar5 = *piVar4;
LAB_004154f3:
  if (unaff_ESI[2].OwningThread == *(HANDLE *)(iVar5 + 0x18)) {
    FUN_0051b1ad();
  }
  uVar3 = *(undefined4 *)((int)unaff_ESI[2].OwningThread + 0x10);
  LeaveCriticalSection(unaff_ESI);
  return uVar3;
}

