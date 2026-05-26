/*
 * server/ps_game.exe — ItemUse_ValidateChatItem
 * Requested VA: 0x00467F60
 * Entry Ghidra:  00467f60
 * Ghidra name:   FUN_00467f60
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: megaphone
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_00467f60(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + 2) = *(undefined4 *)(unaff_EDI + 0x582c);
  *(undefined4 *)(unaff_ESI + 0x26) = *(undefined4 *)(unaff_EDI + 0x128);
  *(undefined2 *)(unaff_ESI + 0x3f) = *(undefined2 *)(unaff_EDI + 0x136);
  *(undefined4 *)(unaff_ESI + 0x41) = *(undefined4 *)(unaff_EDI + 0x13c);
  *(undefined2 *)(unaff_ESI + 0x45) = *(undefined2 *)(unaff_EDI + 0x160);
  *(undefined4 *)(unaff_ESI + 0x47) = *(undefined4 *)(unaff_EDI + 0xd0);
  *(undefined4 *)(unaff_ESI + 0x4b) = *(undefined4 *)(unaff_EDI + 0xd4);
  *(undefined4 *)(unaff_ESI + 0x4f) = *(undefined4 *)(unaff_EDI + 0xd8);
  uVar2 = FUN_004e1a50(param_1);
  *(undefined4 *)(unaff_ESI + 0x53) = uVar2;
  pcVar3 = (char *)(unaff_EDI + 0x5834);
  iVar4 = (unaff_ESI + 6) - (int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[iVar4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = (char *)(unaff_EDI + 0x184);
  iVar4 = (unaff_ESI + 0x2a) - (int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[iVar4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return;
}

