/*
 * server/ps_game.exe — Chat_LoginFieldTrim
 * VA solicitado: 0x0047A180
 * Entry Ghidra:  0047a180
 * Ghidra name:   FUN_0047a180
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: util
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_0047a180(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_104 [256];
  uint local_4;
  
  pcVar4 = local_104;
  pcVar2 = local_104;
  local_4 = DAT_0057f7c4 ^ (uint)local_104;
  *(undefined *)(param_1 + 0x14) = 0;
  iVar3 = 0;
  while( true ) {
    cVar1 = *(char *)(param_1 + iVar3);
    if (cVar1 != ' ') {
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    }
    if (cVar1 == '\0') break;
    cVar1 = *(char *)(param_1 + 1 + iVar3);
    if (cVar1 != ' ') {
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    }
    if (cVar1 == '\0') break;
    cVar1 = *(char *)(param_1 + 2 + iVar3);
    if (cVar1 != ' ') {
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    }
    if ((cVar1 == '\0') || (iVar3 = iVar3 + 3, 0x14 < iVar3)) break;
  }
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 - (int)local_104] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ___security_check_cookie_4();
  return;
}

