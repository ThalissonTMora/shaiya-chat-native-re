/*
 * Game.exe — SStaticText_HeapAlloc
 * Requested VA: 0x0057D4C0
 * Entry Ghidra:  0057d4c0
 * Ghidra name:   FUN_0057d4c0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined * FUN_0057d4c0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  UINT UVar4;
  DWORD DVar5;
  LPWSTR pWVar6;
  int iVar7;
  
  _memset(&DAT_022b80c8,0,0x2000);
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar7 = 0;
  pWVar6 = (LPWSTR)0x0;
  iVar3 = (int)pcVar2 - (int)(param_1 + 1);
  DVar5 = 0;
  pcVar2 = param_1;
  UVar4 = FUN_00408060();
  iVar3 = MultiByteToWideChar(UVar4,DVar5,pcVar2,iVar3,pWVar6,iVar7);
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pWVar6 = (LPWSTR)&DAT_022b80c8;
  iVar7 = (int)pcVar2 - (int)(param_1 + 1);
  DVar5 = 0;
  UVar4 = FUN_00408060();
  MultiByteToWideChar(UVar4,DVar5,param_1,iVar7,pWVar6,iVar3);
  return &DAT_022b80c8;
}

