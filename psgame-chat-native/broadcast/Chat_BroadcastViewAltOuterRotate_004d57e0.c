/*
 * server/ps_game.exe — Chat_BroadcastViewAltOuterRotate
 * Requested VA: 0x004D57E0
 * Entry Ghidra:  004d57e0
 * Ghidra name:   FUN_004d57e0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d57e0(void)

{
  undefined4 uVar1;
  undefined4 unaff_EBX;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_00427550(*(int *)(unaff_ESI + 0x10),unaff_EBX,unaff_EDI,unaff_ESI,_DAT_00574160);
    *(int *)(unaff_ESI + 0x28) = *(int *)(unaff_ESI + 0x28) + 1;
    uVar1 = _DAT_0057415c;
    if (3 < *(int *)(unaff_ESI + 0x28)) {
      *(undefined4 *)(unaff_ESI + 0x28) = 0;
      FUN_00427680(*(undefined4 *)(unaff_ESI + 0x10),unaff_EBX,unaff_EDI,unaff_ESI,_DAT_00574160,
                   uVar1);
      return 1;
    }
  }
  return 0;
}

