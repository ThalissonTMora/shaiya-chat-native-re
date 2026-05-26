/*
 * server/ps_game.exe — Chat_AdminWhisperHelper
 * VA solicitado: 0x0047F350
 * Entry Ghidra:  0047f350
 * Ghidra name:   FUN_0047f350
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: handlers
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0047f350(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int unaff_EDI;
  int local_20;
  undefined2 local_1c;
  char local_1a [22];
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_20;
  if (*(int *)(unaff_EDI + 0x5810) != 0) {
    local_20 = *(int *)(unaff_EDI + 0x5810);
    iVar3 = FUN_00415480(&local_20);
    *(undefined4 *)(unaff_EDI + 0x5810) = 0;
    if (iVar3 != 0) {
      pcVar4 = (char *)(unaff_EDI + 0x184);
      local_1c = 0xf109;
      iVar2 = -(int)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[(int)(local_1a + iVar2)] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_004ed0e0(&local_1c,0x17);
      pcVar4 = (char *)(iVar3 + 0x184);
      iVar3 = -(int)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[(int)(local_1a + iVar3)] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_004ed0e0(&local_1c,0x17);
    }
  }
  ___security_check_cookie_4();
  return;
}

