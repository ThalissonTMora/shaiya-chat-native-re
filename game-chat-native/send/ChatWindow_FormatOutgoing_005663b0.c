/*
 * Game.exe — ChatWindow_FormatOutgoing
 * VA solicitado: 0x005663B0
 * Entry Ghidra:  005663b0
 * Ghidra name:   FUN_005663b0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: send
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005663b0(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  char local_804 [2048];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_804;
  _memset(local_804,0,0x800);
  _vsprintf(local_804,param_2,&stack0x0000000c);
  pcVar2 = local_804;
  if (DAT_007ab0d4 != 3) {
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_00405670(local_804,(int)pcVar2 - (int)(local_804 + 1));
    FUN_004246c0(0,0xffffffff);
    FUN_00565470(0);
    ___security_check_cookie_4();
    return;
  }
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  cchWideChar = MultiByteToWideChar(0xfde9,0,local_804,(int)pcVar2 - (int)(local_804 + 1),
                                    (LPWSTR)0x0,0);
  lpWideCharStr = (LPWSTR)_malloc(cchWideChar * 2);
  pcVar2 = local_804;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  MultiByteToWideChar(0xfde9,0,local_804,(int)pcVar2 - (int)(local_804 + 1),lpWideCharStr,
                      cchWideChar);
  FUN_00424fa0(lpWideCharStr,cchWideChar);
  FUN_004246c0(0,0xffffffff);
  FUN_00565470(0);
  ___security_check_cookie_4();
  return;
}

