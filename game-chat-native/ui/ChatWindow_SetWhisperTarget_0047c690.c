/*
 * Game.exe — ChatWindow_SetWhisperTarget
 * Requested VA: 0x0047C690
 * Entry Ghidra:  0047c690
 * Ghidra name:   FUN_0047c690
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_0047c690(int param_1_00,char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (param_1_00 + 0x198) - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  if (DAT_0090c988 == 0) {
    *(undefined *)(param_1_00 + 0x75b5) = 0;
    *(undefined4 *)(param_1_00 + 0x75c0) = 1;
    FUN_0047c1e0(1);
    FUN_0047a4b0();
  }
  return;
}

