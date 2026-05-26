/*
 * server/ps_game.exe — CParty_ReleaseLock
 * VA solicitado: 0x0044E230
 * Entry Ghidra:  0044e230
 * Ghidra name:   FUN_0044e230
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: party
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0044e230(void)

{
  int in_EAX;
  
  if (in_EAX < 0x10) {
    return (float10)_DAT_00574068;
  }
  if (in_EAX < 0x20) {
    return (float10)_DAT_00574060;
  }
  if (in_EAX < 0x30) {
    return (float10)_DAT_00574058;
  }
  return (float10)_DAT_00573f68;
}

