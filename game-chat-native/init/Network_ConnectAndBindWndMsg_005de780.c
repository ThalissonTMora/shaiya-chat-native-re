/*
 * Game.exe — Network_ConnectAndBindWndMsg
 * Requested VA: 0x005DE780
 * Entry Ghidra:  005de780
 * Ghidra name:   FUN_005de780
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: init
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005de780(void)

{
  int iVar1;
  
  iVar1 = send(DAT_022fa304,&DAT_022f22e8,DAT_022fe30c,0);
  if (iVar1 == -1) {
    MessageBoxA((HWND)0x0,"Send Error!!!----OnWrite()","Socket",0);
    WSAAsyncSelect(DAT_022fa304,DAT_022fa2f8,0x2b10,0x23);
    return;
  }
  DAT_022fe30c = 0;
  _memset(&DAT_022f22e8,0,0x4000);
  WSAAsyncSelect(DAT_022fa304,DAT_022fa2f8,0x2b10,0x21);
  return;
}

