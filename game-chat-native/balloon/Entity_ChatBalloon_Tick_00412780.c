/*
 * Game.exe — Entity_ChatBalloon_Tick
 * Requested VA: 0x00412780
 * Entry Ghidra:  00412780
 * Ghidra name:   FUN_00412780
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: balloon
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00412780(int param_1)

{
  float fVar1;
  
  if ((((DAT_007c0d8c == 0) || (*(char *)(DAT_007c0838 + 0x1d0) == '\0')) && (DAT_007c0e7c != 0)) &&
     (*(int *)(param_1 + 0x288) != 0)) {
    FUN_00420010(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                 *(undefined4 *)(param_1 + 0x18));
    fVar1 = *(float *)(param_1 + 0x28c) - _DAT_007c13bc;
    *(float *)(param_1 + 0x28c) = fVar1;
    if ((fVar1 < 0.0) && (*(undefined4 **)(param_1 + 0x288) != (undefined4 *)0x0)) {
      (**(code **)**(undefined4 **)(param_1 + 0x288))(1);
      *(undefined4 *)(param_1 + 0x288) = 0;
    }
  }
  return;
}

