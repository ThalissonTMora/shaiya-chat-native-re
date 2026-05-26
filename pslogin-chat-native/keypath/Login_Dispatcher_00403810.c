/*
 * server/ps_login.exe — Login_Dispatcher
 * Requested VA: 0x00403810
 * Entry Ghidra:  00403810
 * Ghidra name:   FUN_00403810
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: keypath
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __thiscall FUN_00403810(void *this,uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  uint uVar4;
  void *pvStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0043ea30;
  pvStack_10 = ExceptionList;
  uVar4 = param_1 | 0xf;
  if (uVar4 != 0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x18);
    uVar3 = uVar1 >> 1;
    param_1 = uVar4;
    if ((uVar4 / 3 < uVar3) && (uVar1 <= -uVar3 - 2)) {
      param_1 = uVar3 + uVar1;
    }
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  puVar2 = (undefined4 *)operator_new(param_1 + 1);
  FUN_004038ae(extraout_ECX,puVar2);
  return;
}

