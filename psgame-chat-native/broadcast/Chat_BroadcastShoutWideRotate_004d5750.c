/*
 * server/ps_game.exe — Chat_BroadcastShoutWideRotate
 * VA solicitado: 0x004D5750
 * Entry Ghidra:  004d5750
 * Ghidra name:   FUN_004d5750
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d5750(void)

{
  undefined4 uVar1;
  undefined4 unaff_EBX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xe0) != 0) {
    FUN_00427cf0(*(int *)(unaff_ESI + 0xe0),unaff_EBX,0x15,unaff_ESI + 0xd0,_DAT_00574160,
                 *(undefined4 *)(unaff_ESI + 0xdc),0,7);
    *(int *)(unaff_ESI + 0xf8) = *(int *)(unaff_ESI + 0xf8) + 1;
    uVar1 = _DAT_0057415c;
    if (3 < *(int *)(unaff_ESI + 0xf8)) {
      *(undefined4 *)(unaff_ESI + 0xf8) = 0;
      FUN_00427e30(*(undefined4 *)(unaff_ESI + 0xe0),unaff_EBX,0x15,unaff_ESI + 0xd0,_DAT_00574160,
                   uVar1,*(undefined4 *)(unaff_ESI + 0xdc),0,7);
      return 1;
    }
  }
  return 0;
}

