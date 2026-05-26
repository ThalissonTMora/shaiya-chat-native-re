/*
 * server/ps_game.exe — World_FindUserByIdInWorld
 * VA solicitado: 0x00414D10
 * Entry Ghidra:  00414d10
 * Ghidra name:   FUN_00414d10
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: lookup
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


int FUN_00414d10(void)

{
  int iVar1;
  
  iVar1 = FUN_00415480(&stack0x00000004);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x57f4) != 4)) {
    iVar1 = 0;
  }
  return iVar1;
}

