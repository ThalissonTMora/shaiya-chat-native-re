/*
 * server/ps_game.exe — ZoneChat_MessageLookup
 * Requested VA: 0x004C71D0
 * Entry Ghidra:  004c71d0
 * Ghidra name:   FUN_004c71d0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004c71d0(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int *unaff_EDI;
  int local_14;
  int local_10;
  
  FUN_004c7250(unaff_EDI);
  iVar1 = DAT_00587c5c;
  if ((local_14 == 0) || (local_14 != DAT_00587c44)) {
    FUN_0051b1ad();
  }
  iVar2 = DAT_00587c5c;
  if ((local_10 != iVar1) && (*(int *)(local_10 + 0xc) <= *unaff_EDI)) {
    *unaff_EBX = local_14;
    unaff_EBX[1] = local_10;
    return;
  }
  *unaff_EBX = DAT_00587c44;
  unaff_EBX[1] = iVar2;
  return;
}

