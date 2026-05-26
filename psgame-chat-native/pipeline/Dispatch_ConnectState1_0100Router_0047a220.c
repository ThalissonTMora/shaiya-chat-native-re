/*
 * server/ps_game.exe — Dispatch_ConnectState1_0100Router
 * Requested VA: 0x0047A220
 * Entry Ghidra:  0047a220
 * Ghidra name:   FUN_0047a220
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: pipeline
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0047a220(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int unaff_ESI;
  undefined2 *unaff_EDI;
  bool bVar4;
  undefined4 uVar5;
  undefined2 local_40;
  undefined local_3e;
  undefined2 local_3c;
  undefined4 local_3a;
  undefined4 local_36;
  undefined2 local_30;
  undefined4 local_2e;
  undefined4 local_2a;
  undefined2 local_24;
  undefined4 local_22;
  undefined4 local_1e;
  char local_1a [22];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_40;
  switch(*unaff_EDI) {
  case 0x102:
    if (*(char *)(unaff_ESI + 0x12d) == '\x02') {
LAB_0047a2a5:
      local_40 = 0x102;
      local_3e = 1;
      FUN_004ed0e0(&local_40,3);
      ___security_check_cookie_4();
      return;
    }
    if ((((*(byte *)(unaff_EDI + 1) < 5) &&
         (*(byte *)(unaff_EDI + 2) <= *(byte *)(unaff_ESI + 0x130))) &&
        (*(byte *)((int)unaff_EDI + 3) < 4)) && (*(byte *)(unaff_EDI + 4) < 6)) {
      pcVar2 = (char *)(unaff_EDI + 5);
      FUN_0047a180();
      cVar1 = FUN_0047a200();
      if (cVar1 != '\0') {
        *(undefined *)(unaff_ESI + 300) = *(undefined *)(unaff_EDI + 1);
        *(undefined *)(unaff_ESI + 0x131) = *(undefined *)((int)unaff_EDI + 5);
        *(undefined *)(unaff_ESI + 0x132) = *(undefined *)(unaff_EDI + 3);
        *(undefined *)(unaff_ESI + 0x133) = *(undefined *)((int)unaff_EDI + 7);
        *(undefined *)(unaff_ESI + 0x134) = *(undefined *)(unaff_EDI + 4);
        *(undefined *)(unaff_ESI + 0x135) = *(undefined *)((int)unaff_EDI + 9);
        *(undefined *)(unaff_ESI + 0x12e) = *(undefined *)((int)unaff_EDI + 3);
        *(undefined *)(unaff_ESI + 0x12f) = *(undefined *)(unaff_EDI + 2);
        iVar3 = (unaff_ESI + 0x184) - (int)pcVar2;
        do {
          cVar1 = *pcVar2;
          pcVar2[iVar3] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        FUN_0048fe60();
        ___security_check_cookie_4();
        return;
      }
      goto LAB_0047a2a5;
    }
    break;
  case 0x103:
    if (*(char *)(unaff_ESI + 0x12d) != '\x02') {
      local_3a = *(undefined4 *)(unaff_ESI + 0x582c);
      local_36 = *(undefined4 *)(unaff_EDI + 1);
      local_3c = 0x40a;
      FUN_004ed2d0(&local_3c,10);
      ___security_check_cookie_4();
      return;
    }
    break;
  case 0x104:
    if (*(char *)(unaff_ESI + 0x5860) == '\0') goto LAB_0047a574;
    if (*(char *)(unaff_ESI + 0x12d) != '\x02') {
      bVar4 = DAT_0058799c != 0;
      *(undefined *)(unaff_ESI + 0x5860) = 0;
      if (bVar4) {
        local_36 = *(undefined4 *)(unaff_ESI + 0x70);
        local_3a = *(undefined4 *)(unaff_ESI + 0x582c);
        local_3c = 0x1b01;
        FUN_004ed2d0(&local_3c,10);
      }
      local_2e = *(undefined4 *)(unaff_ESI + 0x582c);
      local_2a = *(undefined4 *)(unaff_EDI + 1);
      local_30 = 0x407;
      FUN_004ed2d0(&local_30,10);
      ___security_check_cookie_4();
      return;
    }
    break;
  case 0x107:
    uVar5 = 1;
    goto LAB_0047a56d;
  case 0x109:
    if (*(byte *)(unaff_EDI + 1) < 2) {
      local_3a = *(undefined4 *)(unaff_ESI + 0x582c);
      local_3c = 0x402;
      *(undefined *)(unaff_ESI + 0x12d) = 2;
      local_36 = CONCAT31(local_36._1_3_,*(undefined *)(unaff_EDI + 1));
      FUN_004ed2d0(&local_3c,7);
      ___security_check_cookie_4();
      return;
    }
    break;
  case 0x10e:
    if (*(char *)(unaff_ESI + 0x5861) != '\0') {
      pcVar2 = (char *)(unaff_EDI + 3);
      *(undefined *)(unaff_ESI + 0x5861) = 0;
      FUN_0047a180();
      if ((*pcVar2 != '\0') && (*(char *)((int)unaff_EDI + 7) != '\0')) {
        local_22 = *(undefined4 *)(unaff_ESI + 0x582c);
        local_1e = *(undefined4 *)(unaff_EDI + 1);
        local_24 = 0x409;
        iVar3 = -(int)pcVar2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(int)(local_1a + iVar3)] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        FUN_004ed2d0(&local_24,0x1f);
        ___security_check_cookie_4();
        return;
      }
      local_40 = 0x10e;
      local_3e = 2;
      FUN_004ed0e0(&local_40,3);
      ___security_check_cookie_4();
      return;
    }
    goto LAB_0047a574;
  case 0x10f:
    if (*(char *)(unaff_ESI + 0x12d) != '\x02') {
      local_3a = *(undefined4 *)(unaff_ESI + 0x582c);
      local_36 = *(undefined4 *)(unaff_EDI + 1);
      local_3c = 0x40b;
      FUN_004ed2d0(&local_3c,10);
      ___security_check_cookie_4();
      return;
    }
  }
  uVar5 = 9;
LAB_0047a56d:
  FUN_004ec760(uVar5,0);
LAB_0047a574:
  ___security_check_cookie_4();
  return;
}

