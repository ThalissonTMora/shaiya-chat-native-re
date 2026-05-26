/*
 * Game.exe — NetworkRecv_SocketPump
 * VA solicitado: 0x005F438E
 * Entry Ghidra:  005f438e
 * Ghidra name:   FUN_005f438e
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: recv
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005f438e(void)

{
  ushort uVar1;
  uint uVar2;
  size_t _Size;
  void *unaff_retaddr;
  HWND in_stack_00000010;
  UINT in_stack_00000014;
  SOCKET in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 uStack_4018;
  HWND pHStack_4014;
  undefined auStack_4010 [8192];
  undefined4 uStack_2010;
  char acStack_2004 [8192];
  uint uStack_4;
  
  uStack_4 = DAT_007b4dd0 ^ (uint)&uStack_4018;
  pHStack_4014 = in_stack_00000010;
  ExceptionList = register0x00000010;
  if (in_stack_00000014 == 0x2b10) {
    if ((short)(in_stack_0000001c >> 0x10) == 0) {
      uVar2 = in_stack_0000001c & 0xffff;
      if (uVar2 == 1) {
        if (DAT_007b3434 != 0) {
          _Size = recv(in_stack_00000018,acStack_2004,0x2000,0);
          uVar1 = DAT_022f62e8;
          if (_Size == 0xffffffff) {
            closesocket(in_stack_00000018);
          }
          else {
            _memcpy((void *)((int)&DAT_022f62f0 + (uint)DAT_022f62e8),acStack_2004,_Size);
            DAT_022f62e8 = uVar1 + (short)_Size;
            uVar1 = DAT_022f62f0;
            while ((DAT_022f62f0 = uVar1, 3 < DAT_022f62e8 &&
                   (uVar2 = (uint)uVar1, uVar1 <= DAT_022f62e8))) {
              FUN_005f4680(&DAT_022f62f2,uVar2 - 2);
              FUN_00401080(auStack_4010,uVar2 - 2);
              DAT_022f62e8 = DAT_022f62e8 - uVar1;
              _memcpy(&DAT_022f62f0,(void *)((int)&DAT_022f62f0 + uVar2),(uint)DAT_022f62e8);
              FUN_005f4700(&uStack_4018,2);
              FUN_005ea700("RECV>>",uStack_4018,auStack_4010,uStack_2010);
              FUN_005f1e10(uStack_4018,auStack_4010);
              FUN_005f46e0();
              uVar1 = DAT_022f62f0;
            }
          }
        }
      }
      else if (uVar2 == 2) {
        if (DAT_007b3434 != 0) {
          FUN_005de780(DAT_007b4dd0 ^ (uint)&stack0xffffbfe0);
        }
      }
      else if (uVar2 == 0x20) {
        FUN_005de810();
      }
    }
    else {
      FUN_005de820(in_stack_0000001c >> 0x10);
      closesocket(in_stack_00000018);
    }
  }
  DefWindowProcA(pHStack_4014,in_stack_00000014,in_stack_00000018,in_stack_0000001c);
  ExceptionList = unaff_retaddr;
  ___security_check_cookie_4();
  return;
}

