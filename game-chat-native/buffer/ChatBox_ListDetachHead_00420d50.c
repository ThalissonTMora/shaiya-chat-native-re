/*
 * Game.exe — ChatBox_ListDetachHead
 * Requested VA: 0x00420D50
 * Entry Ghidra:  00420d50
 * Ghidra name:   FUN_00420d50
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: buffer
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_00420d50(int param_1_00,int *param_1,int *param_2)

{
  if (param_2[2] != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_006307cd(param_2[2]);
  }
  if (param_2 != *(int **)(param_1_00 + 8)) {
    *(int *)param_2[1] = *param_2;
    *(int *)(*param_2 + 4) = param_2[1];
                    /* WARNING: Subroutine does not return */
    FUN_006307cd(param_2);
  }
  *param_1 = *param_2;
  return;
}

