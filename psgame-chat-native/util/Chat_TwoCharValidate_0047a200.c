/*
 * server/ps_game.exe — Chat_TwoCharValidate
 * VA solicitado: 0x0047A200
 * Entry Ghidra:  0047a200
 * Ghidra name:   FUN_0047a200
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: util
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_0047a200(void)

{
  char *in_EAX;
  
  if ((*in_EAX != '\0') && (in_EAX[1] != '\0')) {
    return 1;
  }
  return 0;
}

