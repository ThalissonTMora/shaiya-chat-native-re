/*
 * Game.exe — ChatWindow_ApplyChannelPrefix
 * VA solicitado: 0x0047C190
 * Entry Ghidra:  0047c190
 * Ghidra name:   FUN_0047c190
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_0047c190(char *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = _strncmp(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1));
  if (iVar3 == 0) {
    uVar4 = FUN_00575740(param_2,(int)pcVar2 - (int)(param_2 + 1),0);
    *param_3 = uVar4;
  }
  return;
}

