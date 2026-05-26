/*
 * Game.exe — PacketPayload_Encrypt
 * Requested VA: 0x00401040
 * Entry Ghidra:  00401040
 * Ghidra name:   FUN_00401040
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile-crypto.sh
 */


void FUN_00401040(undefined4 param_1,undefined4 param_2)

{
  if (DAT_023037e9 != '\0') {
    if (DAT_023037e0 == 0) {
      FUN_00404df0(param_2);
      return;
    }
    FUN_00401640(param_2);
  }
  return;
}

