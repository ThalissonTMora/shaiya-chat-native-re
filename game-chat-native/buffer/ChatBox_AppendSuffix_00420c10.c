/*
 * Game.exe — ChatBox_AppendSuffix
 * VA solicitado: 0x00420C10
 * Entry Ghidra:  00420c10
 * Ghidra name:   FUN_00420c10
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00420c10(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 != param_2 + 1) {
      param_1 = param_1 - (int)param_2;
      do {
        cVar1 = *param_2;
        param_2[param_1] = cVar1;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
    }
  }
  return;
}

