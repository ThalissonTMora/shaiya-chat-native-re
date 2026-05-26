/*
 * Game.exe — PacketPayload_Decrypt
 * Requested VA: 0x00401080
 * Entry Ghidra:  00401080
 * Ghidra name:   FUN_00401080
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: recv
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00401080(undefined4 param_1,undefined4 param_2)

{
  if (DAT_023037e8 == '\0') {
    if (DAT_023037ea != '\0') {
      if (DAT_023037e0 == 0) {
        FUN_00404df0(param_2);
        return;
      }
      FUN_00401640(param_2);
    }
  }
  else if (DAT_023037e4 == 2) {
    FUN_00401000();
    return;
  }
  return;
}

