/*
 * server/ps_game.exe — SendQueue_GrowSlotTable
 * VA solicitado: 0x004F4200
 * Entry Ghidra:  004f4200
 * Ghidra name:   FUN_004f4200
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004f4200(uint *param_1)

{
  uint *Destination;
  uint uVar1;
  LONG LVar2;
  
  uVar1 = InterlockedIncrement((LONG *)param_1);
  if ((uVar1 & 0xff00) != 0) {
    Destination = param_1 + 1;
    LVar2 = InterlockedCompareExchange((LONG *)Destination,1,0);
    if (LVar2 != 0) {
      FUN_004f40e0();
    }
    uVar1 = *param_1;
    do {
      if ((int)uVar1 < 0) {
        LVar2 = InterlockedExchangeAdd((LONG *)param_1,0xffff);
        if ((short)LVar2 == 1) {
          InterlockedExchange((LONG *)Destination,0);
          SetEvent((HANDLE)param_1[3]);
        }
        else {
          InterlockedExchange((LONG *)Destination,0);
        }
        WaitForSingleObject((HANDLE)param_1[2],0xffffffff);
        LVar2 = InterlockedCompareExchange((LONG *)Destination,1,0);
        if (LVar2 != 0) {
          FUN_004f40e0();
        }
        LVar2 = InterlockedExchangeAdd((LONG *)param_1,-0xffff);
        uVar1 = LVar2 - 0xffff;
      }
      else {
        LVar2 = InterlockedExchangeAdd((LONG *)param_1,0x7fffffff);
        if ((short)LVar2 == 1) {
          InterlockedExchange((LONG *)Destination,0);
          SetEvent((HANDLE)param_1[3]);
        }
        else {
          InterlockedExchange((LONG *)Destination,0);
        }
        WaitForSingleObject((HANDLE)param_1[3],0xffffffff);
        LVar2 = InterlockedCompareExchange((LONG *)Destination,1,0);
        if (LVar2 != 0) {
          FUN_004f40e0();
        }
        LVar2 = InterlockedExchangeAdd((LONG *)param_1,-0x7fffffff);
        uVar1 = LVar2 + 0x80000001;
      }
    } while ((uVar1 & 0xff00) != 0);
    if ((uVar1 & 0xff0000) != 0) {
      InterlockedExchange((LONG *)Destination,0);
      SetEvent((HANDLE)param_1[2]);
      return;
    }
    InterlockedExchange((LONG *)Destination,0);
  }
  return;
}

