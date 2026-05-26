/*
 * server/ps_game.exe — World_FindUserByName
 * Requested VA: 0x00414D40
 * Entry Ghidra:  00414d40
 * Ghidra name:   FUN_00414d40
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


int FUN_00414d40(void)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  char local_24 [36];
  
  iVar2 = -(int)in_EAX;
  do {
    cVar1 = *in_EAX;
    in_EAX[(int)(local_24 + iVar2)] = cVar1;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_00415ad0(local_24);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x57f4) != 4)) {
    iVar2 = 0;
  }
  return iVar2;
}

