/*
 * Game.exe — ChatBalloon_FormatTextBuffer
 * Requested VA: 0x0041FCF0
 * Entry Ghidra:  0041fcf0
 * Ghidra name:   FUN_0041fcf0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: balloon
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_0041fcf0(undefined *param_1,char param_2)

{
  undefined local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_108;
  if (param_1 != (undefined *)0x0) {
    if ((param_2 != DAT_022aa816) && (DAT_0090e2e0 != 0x2a)) {
      FUN_00421750(param_1,local_108);
      param_1 = local_108;
    }
    FUN_0057c280(param_1);
    ___security_check_cookie_4();
    return;
  }
  ___security_check_cookie_4();
  return;
}

