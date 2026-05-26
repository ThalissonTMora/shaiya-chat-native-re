/*
 * Game.exe — ChatObject_alloc_site
 * VA solicitado: 0x0040AD5D
 * Entry Ghidra:  0040ab40
 * Ghidra name:   FUN_0040ab40
 * NOTA: VA dentro da função (landmark/hook), não é entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: init
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_0040ab40(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  LPCWSTR pWVar5;
  LPCWSTR pWVar6;
  char *pcVar7;
  DWORD DVar8;
  BOOL BVar9;
  DWORD DVar10;
  char *pcVar11;
  UINT UVar12;
  void *pvStack_238;
  tagMSG local_234;
  char acStack_218 [260];
  char acStack_114 [260];
  uint local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0072c413;
  local_c = ExceptionList;
  local_10 = DAT_007b4dd0 ^ (uint)&pvStack_238;
  ExceptionList = &local_c;
  FUN_005fd640(&DAT_022fe3a8,4,"****************%s****************","GameInit",
               DAT_007b4dd0 ^ (uint)&stack0xfffffdb8);
  iVar2 = FUN_0040d6b0("data/Config.cfg",&DAT_00747cb8);
  if (iVar2 != 0) {
    if (DAT_007c17f8 == 0) {
      local_234.pt.y = 0xf;
      local_234.pt.x = 0;
      local_234.message = local_234.message & 0xffffff00;
      FUN_00405670("data/Config.cfg",0xf);
      local_4 = 0;
      uVar3 = FUN_004085d0(&local_234);
      local_4 = 0xffffffff;
      if (0xf < (uint)local_234.pt.y) {
                    /* WARNING: Subroutine does not return */
        FUN_006307cd(local_234.message);
      }
    }
    else {
      uVar3 = *(undefined4 *)(DAT_007c17f8 + 0x28);
    }
    iVar4 = FUN_00632ab5(uVar3);
    FUN_0040d2a0(iVar4,1,uVar3,iVar2);
    FUN_0040d2d0(iVar2);
    FUN_006095b0();
    FUN_00608f60(iVar4,uVar3,0);
    if (iVar4 != 0) {
      FUN_006319d5(iVar4);
    }
  }
  FUN_004010e0();
  cVar1 = FUN_005f45e0(DAT_007c139c,DAT_007c13a0);
  if (cVar1 == '\0') {
    FUN_005fd640(&DAT_022fe3a8,4,"****************%s Init Network****************","GameInit");
    pvStack_238 = operator_new(0x58);
    local_4 = 1;
    if (pvStack_238 == (void *)0x0) {
      DAT_007c06f4 = 0;
    }
    else {
      DAT_007c06f4 = FUN_00405ca0();
    }
    local_4 = 0xffffffff;
    FUN_005de760(DAT_007c06f4);
    FUN_00556660(1);
    pvStack_238 = operator_new(0x938);
    local_4 = 2;
    if (pvStack_238 == (void *)0x0) {
      DAT_022eed30 = 0;
    }
    else {
      DAT_022eed30 = FUN_0040a840();
    }
    local_4 = 0xffffffff;
    FUN_005de770(DAT_022eed30);
    cVar1 = FUN_005de670(&DAT_007c0dd0,0x7850);
    if (cVar1 == '\0') {
      FUN_005fd640(&DAT_022fe3a8,4,"****************%s Connect****************","GameInit");
      *(undefined4 *)(DAT_022eed30 + 0x224) = 0;
      DVar8 = timeGetTime();
LAB_0040ae01:
      BVar9 = PeekMessageA(&local_234,(HWND)0x0,0,0,0);
      if ((BVar9 != 0) && (BVar9 = GetMessageA(&local_234,(HWND)0x0,0,0), BVar9 != 0)) {
        TranslateMessage(&local_234);
        DispatchMessageA(&local_234);
      }
      if (*(int *)(DAT_022eed30 + 4) != 0) goto LAB_0040b156;
      if (*(int *)(DAT_022eed30 + 0x224) == 0) goto code_r0x0040ae4e;
      FUN_005fd640(&DAT_022fe3a8,4,"****************%s Connect OK****************","GameInit");
      iVar2 = FUN_00573030();
      if (iVar2 == 0) {
        UVar12 = 0x10;
        pcVar11 = "ERROR!!!";
        if (DAT_007ab0d4 != 3) {
          pcVar7 = (char *)FUN_00420db0(0x274e);
          goto LAB_0040b14e;
        }
        pWVar5 = (LPCWSTR)FUN_0057d4c0();
        uVar3 = FUN_00420db0(0x274e);
        pWVar6 = (LPCWSTR)FUN_0057d4c0(uVar3);
        MessageBoxW(DAT_007c139c,pWVar6,pWVar5,UVar12);
        goto LAB_0040b156;
      }
      iVar2 = FUN_00563b60();
      if (iVar2 == 0) {
        UVar12 = 0x10;
        pcVar11 = "ERROR!!!";
        if (DAT_007ab0d4 != 3) {
          uVar3 = 0x274f;
          goto LAB_0040b13f;
        }
        pWVar5 = (LPCWSTR)FUN_0057d4c0();
        uVar3 = 0x274f;
        goto LAB_0040ae7b;
      }
      if ((DAT_007c13a4 == 0) || (iVar2 = FUN_00573040(), iVar2 != 0)) {
        iVar2 = FUN_005762d0();
        if (iVar2 == 0) {
          DAT_007c0d9c = 0;
          iVar2 = FUN_005762d0();
          if (iVar2 != 0) goto LAB_0040b05e;
          pcVar7 = (char *)FUN_00420db0(0x2751);
          pcVar11 = acStack_114;
          do {
            cVar1 = *pcVar7;
            *pcVar11 = cVar1;
            pcVar7 = pcVar7 + 1;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          UVar12 = 0x10;
          if (DAT_007ab0d4 == 3) {
            pWVar5 = (LPCWSTR)FUN_0057d4c0(acStack_114);
            uVar3 = FUN_00420db0(0x2750);
            pWVar6 = (LPCWSTR)FUN_0057d4c0(uVar3);
            MessageBoxW(DAT_007c139c,pWVar6,pWVar5,UVar12);
            goto LAB_0040b156;
          }
          pcVar11 = acStack_114;
          uVar3 = 0x2750;
          goto LAB_0040b13f;
        }
LAB_0040b05e:
        FUN_0056bd30();
        FUN_0056d5d0(0,0x1e,"ui_button001.wav",5,1);
        FUN_0056d5d0(0,0x20,"ui_window.wav",5,1);
        pvStack_238 = operator_new(0x308);
        local_4 = 3;
        if (pvStack_238 == (void *)0x0) {
          DAT_007c0838 = 0;
        }
        else {
          DAT_007c0838 = FUN_0056f470();
        }
        local_4 = 0xffffffff;
        pvStack_238 = operator_new(0x94);
        local_4 = 4;
        if (pvStack_238 == (void *)0x0) {
          DAT_007c0834 = 0;
        }
        else {
          DAT_007c0834 = FUN_0057fac0();
        }
        local_4 = 0xffffffff;
        FUN_00408180();
        *(undefined4 *)(DAT_022eed30 + 0x934) = 1;
        FUN_005fd640(&DAT_022fe3a8,4,"****************%s End****************","GameInit");
      }
      else {
        UVar12 = 0x10;
        if (DAT_007ab0d4 != 3) {
          pcVar11 = (char *)FUN_00420db0(0x2750);
          pcVar7 = "Full Screen Error!!!";
          goto LAB_0040b14e;
        }
        uVar3 = FUN_00420db0(0x2750);
        pWVar5 = (LPCWSTR)FUN_0057d4c0(uVar3);
        pWVar6 = (LPCWSTR)FUN_0057d4c0("Full Screen Error!!!");
        MessageBoxW(DAT_007c139c,pWVar6,pWVar5,UVar12);
      }
      goto LAB_0040b156;
    }
    pcVar7 = (char *)FUN_00420db0(0x274c);
    pcVar11 = acStack_218;
    do {
      cVar1 = *pcVar7;
      *pcVar11 = cVar1;
      pcVar7 = pcVar7 + 1;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    UVar12 = 0x10;
    if (DAT_007ab0d4 != 3) {
      pcVar11 = acStack_218;
      uVar3 = 0x274b;
      goto LAB_0040b13f;
    }
    pWVar5 = (LPCWSTR)FUN_0057d4c0(acStack_218);
    uVar3 = 0x274b;
  }
  else {
    UVar12 = 0x10;
    pcVar11 = "ERROR!!!";
    if (DAT_007ab0d4 != 3) {
      pcVar7 = (char *)FUN_00420db0(0x274a);
      goto LAB_0040b14e;
    }
    pWVar5 = (LPCWSTR)FUN_0057d4c0();
    uVar3 = 0x274a;
  }
  uVar3 = FUN_00420db0(uVar3);
  pWVar6 = (LPCWSTR)FUN_0057d4c0(uVar3);
  MessageBoxW(DAT_007c139c,pWVar6,pWVar5,UVar12);
LAB_0040b156:
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
code_r0x0040ae4e:
  DVar10 = timeGetTime();
  if (30000 < DVar10 - DVar8) goto code_r0x0040ae59;
  goto LAB_0040ae01;
code_r0x0040ae59:
  UVar12 = 0x10;
  pcVar11 = "ERROR!!!";
  if (DAT_007ab0d4 == 3) {
    pWVar5 = (LPCWSTR)FUN_0057d4c0();
    uVar3 = 0x274d;
LAB_0040ae7b:
    uVar3 = FUN_00420db0(uVar3);
    pWVar6 = (LPCWSTR)FUN_0057d4c0(uVar3);
    MessageBoxW(DAT_007c139c,pWVar6,pWVar5,UVar12);
    goto LAB_0040b156;
  }
  uVar3 = 0x274d;
LAB_0040b13f:
  UVar12 = 0x10;
  pcVar7 = (char *)FUN_00420db0(uVar3);
LAB_0040b14e:
  MessageBoxA(DAT_007c139c,pcVar7,pcVar11,UVar12);
  goto LAB_0040b156;
}

