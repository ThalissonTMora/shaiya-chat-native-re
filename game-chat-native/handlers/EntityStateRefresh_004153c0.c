/*
 * Game.exe — EntityStateRefresh
 * Requested VA: 0x004153C0
 * Entry Ghidra:  004153c0
 * Ghidra name:   FUN_004153c0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004153c0(int param_1)

{
  if (DAT_007c0e30 != 0) {
    switch(*(undefined *)(param_1 + 0x2b8)) {
    case 0:
      if (*(char *)(param_1 + 0x19f) == '\0') {
        FUN_0056cfb0(2,0,param_1 + 0x10,_DAT_00747454);
        return;
      }
      FUN_0056cfb0(3,0,param_1 + 0x10,_DAT_00747454);
      return;
    case 1:
      if (*(char *)(param_1 + 0x19f) == '\0') {
        FUN_0056cfb0(4,0,param_1 + 0x10,_DAT_00747454);
        return;
      }
      FUN_0056cfb0(5,0,param_1 + 0x10,_DAT_00747454);
      return;
    case 2:
      if (*(char *)(param_1 + 0x19f) != '\0') {
        FUN_0056cfb0(9,0,param_1 + 0x10,_DAT_00747454);
        return;
      }
      FUN_0056cfb0(8,0,param_1 + 0x10,_DAT_00747454);
      break;
    case 3:
      if (*(char *)(param_1 + 0x19f) == '\0') {
        FUN_0056cfb0(6,0,param_1 + 0x10,_DAT_00747454);
        return;
      }
      FUN_0056cfb0(7,0,param_1 + 0x10,_DAT_00747454);
      return;
    }
  }
  return;
}

