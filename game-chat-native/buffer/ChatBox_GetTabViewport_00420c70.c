/*
 * Game.exe — ChatBox_GetTabViewport
 * VA solicitado: 0x00420C70
 * Entry Ghidra:  00420c70
 * Ghidra name:   FUN_00420c70
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: buffer
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


undefined4 FUN_00420c70(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00420bf0(1);
  if (iVar1 != param_1) {
    uVar2 = FUN_00420bf0(0);
    if ((int)uVar2 != (int)((ulonglong)uVar2 >> 0x20)) {
      return 0;
    }
  }
  return 1;
}

