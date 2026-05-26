/*
 * Game.exe — ChatWindow_FormatDrawBuffer
 * VA solicitado: 0x00575610
 * Entry Ghidra:  00575610
 * Ghidra name:   FUN_00575610
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_00575610(int param_1_00,LPCSTR param_1,int param_2,int *param_3,int param_5)

{
  UINT CodePage;
  int cchWideChar;
  int iVar1;
  
  if ((((((DAT_007ab0d4 != 3) && (DAT_007ab0d4 != 4)) && (DAT_007ab0d4 != 5)) &&
       ((DAT_007ab0d4 != 9 && (DAT_007ab0d4 != 6)))) &&
      (((DAT_007ab0d4 != 7 && ((DAT_007ab0d4 != 8 && (DAT_007ab0d4 != 10)))) &&
       (DAT_007ab0d4 != 0xb)))) &&
     ((((DAT_007ab0d4 != 0xc && (DAT_007ab0d4 != 0xd)) && (DAT_007ab0d4 != 0xe)) &&
      (((DAT_007ab0d4 != 0xf && (DAT_007ab0d4 != 0x10)) && (DAT_007ab0d4 != 0x11)))))) {
    *param_3 = param_2 * 6;
    param_3[1] = 0xc;
    return;
  }
  CodePage = FUN_00408060();
  cchWideChar = MultiByteToWideChar(CodePage,0,param_1,param_2,(LPWSTR)0x0,0);
  _memset(&DAT_022b61a8,0,0x800);
  MultiByteToWideChar(CodePage,0,param_1,param_2,(LPWSTR)&DAT_022b61a8,cchWideChar);
  FUN_005741e0(&DAT_022b61a8,cchWideChar,param_3,param_5);
  iVar1 = 0;
  while ((cchWideChar = cchWideChar + -1, -1 < cchWideChar &&
         (*(short *)(&DAT_022b61a8 + cchWideChar * 2) == 0x20))) {
    iVar1 = iVar1 + 1;
  }
  if ((*(int *)(param_1_00 + 0x3a4) != 0) && (param_5 == 1)) {
    *param_3 = *param_3 + *(int *)(param_1_00 + 0x3b4) * iVar1;
    return;
  }
  *param_3 = *param_3 + *(int *)(param_1_00 + 0x3b0) * iVar1;
  return;
}

