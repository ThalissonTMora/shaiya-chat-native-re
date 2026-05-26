/*
 * server/ps_game.exe — SendQueue_ReleaseIdleSlot
 * VA solicitado: 0x004F4150
 * Entry Ghidra:  004f4150
 * Ghidra name:   FUN_004f4150
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004f4150(LONG *param_1)

{
  uint uVar1;
  
  uVar1 = InterlockedDecrement(param_1);
  if (((uVar1 & 0xff000000) != 0) && ((short)uVar1 == 0)) {
    SetEvent((HANDLE)param_1[3]);
  }
  return;
}

