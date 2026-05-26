/*
 * server/ps_game.exe — ItemUse_PreMegaphoneSend
 * Requested VA: 0x004652F0
 * Entry Ghidra:  004652f0
 * Ghidra name:   FUN_004652f0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: megaphone
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004652f0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int unaff_EDI;
  
  iVar2 = FUN_004123a0();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_EDI + 0xdc);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(unaff_EDI + 0xd0);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(unaff_EDI + 0xd4);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(unaff_EDI + 0xd8);
    *(undefined2 *)(iVar2 + 0x30) = *(undefined2 *)(unaff_EDI + 0x162);
    *(undefined *)(iVar2 + 0x32) = *(undefined *)(unaff_EDI + 0x12d);
    *(undefined *)(iVar2 + 0x33) = *(undefined *)(unaff_EDI + 0x12e);
    *(undefined *)(iVar2 + 0x34) = *(undefined *)(unaff_EDI + 0x131);
    *(undefined *)(iVar2 + 0x35) = *(undefined *)(unaff_EDI + 0x132);
    *(undefined *)(iVar2 + 0x36) = *(undefined *)(unaff_EDI + 0x133);
    *(undefined *)(iVar2 + 0x37) = *(undefined *)(unaff_EDI + 0x134);
    *(undefined *)(iVar2 + 0x38) = *(undefined *)(unaff_EDI + 0x135);
    if (*(int *)(unaff_EDI + 0x1c0) != 0) {
      *(undefined *)(iVar2 + 0x39) = *(undefined *)(*(int *)(unaff_EDI + 0x1c0) + 0x40);
      *(undefined *)(iVar2 + 0x41) = *(undefined *)(*(int *)(unaff_EDI + 0x1c0) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1c4) != 0) {
      *(undefined *)(iVar2 + 0x3a) = *(undefined *)(*(int *)(unaff_EDI + 0x1c4) + 0x40);
      *(undefined *)(iVar2 + 0x42) = *(undefined *)(*(int *)(unaff_EDI + 0x1c4) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1c8) != 0) {
      *(undefined *)(iVar2 + 0x3b) = *(undefined *)(*(int *)(unaff_EDI + 0x1c8) + 0x40);
      *(undefined *)(iVar2 + 0x43) = *(undefined *)(*(int *)(unaff_EDI + 0x1c8) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1cc) != 0) {
      *(undefined *)(iVar2 + 0x3c) = *(undefined *)(*(int *)(unaff_EDI + 0x1cc) + 0x40);
      *(undefined *)(iVar2 + 0x44) = *(undefined *)(*(int *)(unaff_EDI + 0x1cc) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1d0) != 0) {
      *(undefined *)(iVar2 + 0x3d) = *(undefined *)(*(int *)(unaff_EDI + 0x1d0) + 0x40);
      *(undefined *)(iVar2 + 0x45) = *(undefined *)(*(int *)(unaff_EDI + 0x1d0) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1d4) != 0) {
      *(undefined *)(iVar2 + 0x3e) = *(undefined *)(*(int *)(unaff_EDI + 0x1d4) + 0x40);
      *(undefined *)(iVar2 + 0x46) = *(undefined *)(*(int *)(unaff_EDI + 0x1d4) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1d8) != 0) {
      *(undefined *)(iVar2 + 0x3f) = *(undefined *)(*(int *)(unaff_EDI + 0x1d8) + 0x40);
      *(undefined *)(iVar2 + 0x47) = *(undefined *)(*(int *)(unaff_EDI + 0x1d8) + 0x41);
    }
    if (*(int *)(unaff_EDI + 0x1dc) != 0) {
      *(undefined *)(iVar2 + 0x40) = *(undefined *)(*(int *)(unaff_EDI + 0x1dc) + 0x40);
      *(undefined *)(iVar2 + 0x48) = *(undefined *)(*(int *)(unaff_EDI + 0x1dc) + 0x41);
    }
    pcVar3 = (char *)(unaff_EDI + 0x184);
    iVar2 = (iVar2 + 0x49) - (int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[iVar2] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_0041dce0(*(undefined4 *)(unaff_EDI + 0xe0));
  }
  return;
}

