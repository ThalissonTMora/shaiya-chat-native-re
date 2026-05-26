/*
 * Game.exe — Login_OnSubmitCredentials
 * Requested VA: 0x004D2B50
 * Entry Ghidra:  004d2b50
 * Ghidra name:   FUN_004d2b50
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: init
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d2b50(int param_1)

{
  LPCSTR lpString;
  char cVar1;
  uint uVar2;
  LPCSTR pCVar3;
  char *pcVar4;
  DWORD DVar5;
  BOOL BVar6;
  DWORD DVar7;
  void *pvVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined local_44 [4];
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  tagMSG local_28;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007330dd;
  local_c = ExceptionList;
  uVar2 = DAT_007b4dd0 ^ (uint)&stack0xffffffa4;
  lpString = (LPCSTR)(param_1 + 4);
  pCVar3 = lpString;
  do {
    cVar1 = *pCVar3;
    pCVar3 = pCVar3 + 1;
  } while (cVar1 != '\0');
  if (pCVar3 == (LPCSTR)(param_1 + 5)) {
    return 0;
  }
  pcVar4 = (char *)(param_1 + 0x27);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (pcVar4 == (char *)(param_1 + 0x28)) {
    return 0;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  pCVar3 = lpString;
  do {
    cVar1 = *pCVar3;
    pCVar3 = pCVar3 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  FUN_00405670(lpString,(int)pCVar3 - (param_1 + 5));
  local_4 = 0;
  FUN_0060fca0(local_44,uVar2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
                    /* WARNING: Subroutine does not return */
    FUN_006307cd(local_40);
  }
  FUN_005662f0();
  FUN_0056c650("ui_login001.wav",&DAT_022b6a70,_DAT_00748340,0);
  iVar10 = DAT_022eed30;
  *(undefined4 *)(DAT_022eed30 + 0x27c) = 0;
  *(undefined4 *)(iVar10 + 0x280) = 0;
  *(undefined4 *)(iVar10 + 0x284) = 0;
  *(undefined4 *)(iVar10 + 0x288) = 0;
  *(undefined4 *)(iVar10 + 0x28c) = 0;
  *(undefined4 *)(iVar10 + 0x290) = 0;
  *(undefined4 *)(iVar10 + 0x294) = 0;
  *(undefined4 *)(iVar10 + 0x298) = 0;
  *(undefined2 *)(iVar10 + 0x29c) = 0;
  *(undefined *)(iVar10 + 0x29e) = 0;
  iVar10 = DAT_022eed30;
  *(undefined4 *)(DAT_022eed30 + 0x29f) = 0;
  *(undefined4 *)(iVar10 + 0x2a3) = 0;
  *(undefined4 *)(iVar10 + 0x2a7) = 0;
  *(undefined4 *)(iVar10 + 0x2ab) = 0;
  *(undefined4 *)(iVar10 + 0x2af) = 0;
  *(undefined4 *)(iVar10 + 0x2b3) = 0;
  *(undefined4 *)(iVar10 + 0x2b7) = 0;
  *(undefined4 *)(iVar10 + 699) = 0;
  *(undefined2 *)(iVar10 + 0x2bf) = 0;
  *(undefined *)(iVar10 + 0x2c1) = 0;
  pCVar3 = lpString;
  puVar11 = (undefined4 *)(DAT_022eed30 + 0x27c);
  for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar11 = *(undefined4 *)pCVar3;
    pCVar3 = pCVar3 + 4;
    puVar11 = puVar11 + 1;
  }
  *(undefined2 *)puVar11 = *(undefined2 *)pCVar3;
  *(CHAR *)((int)puVar11 + 2) = pCVar3[2];
  pcVar4 = (char *)(param_1 + 0x27);
  puVar11 = (undefined4 *)(DAT_022eed30 + 0x29f);
  for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar11 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    puVar11 = puVar11 + 1;
  }
  *(undefined2 *)puVar11 = *(undefined2 *)pcVar4;
  *(char *)((int)puVar11 + 2) = pcVar4[2];
  FUN_005a4d30(0);
  *(undefined4 *)(DAT_022eed30 + 0x224) = 0x11;
  DVar5 = timeGetTime();
  iVar10 = *(int *)(DAT_022eed30 + 4);
  while (iVar10 == 0) {
    BVar6 = PeekMessageA(&local_28,(HWND)0x0,0,0,0);
    if ((BVar6 != 0) && (BVar6 = GetMessageA(&local_28,(HWND)0x0,0,0), BVar6 != 0)) {
      TranslateMessage(&local_28);
      DispatchMessageA(&local_28);
    }
    if (*(int *)(DAT_022eed30 + 0x224) < 0x10) break;
    DVar7 = timeGetTime();
    if (30000 < DVar7 - DVar5) {
      uVar9 = FUN_00420db0(0x2725);
      FUN_004dd4c0(0,0xff,0xff,0xff,uVar9);
      goto LAB_004d3131;
    }
    iVar10 = *(int *)(DAT_022eed30 + 4);
  }
  if (*(int *)(DAT_022eed30 + 0x224) == 0) {
    if (*(char *)(param_1 + 0x3213) == '\x01') {
      WritePrivateProfileStringA("LOGIN","ID",lpString,&DAT_007c0720);
    }
    FUN_0040fde0(DAT_022eed30 + 0x27c);
    *(undefined4 *)(param_1 + 0x4eac) = 1;
    *(undefined4 *)(DAT_022eed30 + 0x224) = 0;
    FUN_004057c0(1);
    FUN_0040fde0();
    ExceptionList = local_c;
    return 1;
  }
  if (*(int *)(param_1 + 0x4ec0) != 0) goto switchD_004d2d9f_caseD_f;
  switch(*(int *)(DAT_022eed30 + 0x224)) {
  case 1:
    pvVar8 = operator_new(0xc70);
    local_4 = 1;
    if (pvVar8 == (void *)0x0) break;
    uVar9 = 0x2726;
LAB_004d304d:
    uVar12 = 0;
    uVar9 = FUN_00420db0(uVar9,0);
    uVar9 = FUN_004dc9a0(0,0xff,0xff,0xff,uVar9,uVar12);
    goto LAB_004d3072;
  case 2:
    pvVar8 = operator_new(0xc70);
    local_4 = 2;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x2727;
      goto LAB_004d304d;
    }
    break;
  case 3:
    pvVar8 = operator_new(0xc70);
    local_4 = 3;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x2728;
      goto LAB_004d304d;
    }
    break;
  case 4:
    pvVar8 = operator_new(0xc70);
    local_4 = 4;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x2729;
      goto LAB_004d304d;
    }
    break;
  case 5:
    pvVar8 = operator_new(0xc70);
    local_4 = 5;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272a;
      goto LAB_004d304d;
    }
    break;
  case 6:
    pvVar8 = operator_new(0xc70);
    local_4 = 6;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272b;
      goto LAB_004d304d;
    }
    break;
  case 7:
    pvVar8 = operator_new(0xc70);
    local_4 = 7;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272b;
      goto LAB_004d304d;
    }
    break;
  case 8:
    pvVar8 = operator_new(0xc70);
    local_4 = 8;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272b;
      goto LAB_004d304d;
    }
    break;
  case 9:
    pvVar8 = operator_new(0xc70);
    local_4 = 9;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272c;
      goto LAB_004d304d;
    }
    break;
  case 10:
    pvVar8 = operator_new(0xc70);
    local_4 = 10;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x278a;
      goto LAB_004d304d;
    }
    break;
  case 0xb:
    pvVar8 = operator_new(0xc70);
    local_4 = 0xb;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272d;
      goto LAB_004d304d;
    }
    break;
  case 0xc:
    pvVar8 = operator_new(0xc70);
    local_4 = 0xc;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x272d;
      goto LAB_004d304d;
    }
    break;
  case 0xd:
    pvVar8 = operator_new(0xc70);
    local_4 = 0xd;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x2779;
      goto LAB_004d304d;
    }
    break;
  case 0xe:
    pvVar8 = operator_new(0xc70);
    local_4 = 0xe;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x2778;
      goto LAB_004d304d;
    }
    break;
  case 0xf:
    pvVar8 = operator_new(0xc70);
    local_4 = 0xf;
    if (pvVar8 != (void *)0x0) {
      uVar9 = 0x328;
      goto LAB_004d304d;
    }
    break;
  default:
    goto switchD_004d2d9f_caseD_f;
  }
  uVar9 = 0;
LAB_004d3072:
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x4ec0) = uVar9;
switchD_004d2d9f_caseD_f:
  *(undefined4 *)(DAT_022eed30 + 0x224) = 0x11;
LAB_004d3131:
  FUN_004057c0(1);
  ExceptionList = local_c;
  return 0;
}

