/*
 * Game.exe — ChatString_Reset
 * Requested VA: 0x00405590
 * Entry Ghidra:  00405590
 * Ghidra name:   FUN_00405590
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: util
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


int __thiscall FUN_00405590(int param_1_00,int param_1,uint param_2,uint param_3)

{
  undefined4 *_Dst;
  undefined4 *puVar1;
  uint _MaxCount;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_006554df();
  }
  _MaxCount = *(int *)(param_1 + 0x14) - param_2;
  if (param_3 < _MaxCount) {
    _MaxCount = param_3;
  }
  if (param_1_00 != param_1) {
    if (_MaxCount == 0xffffffff) {
      FUN_006554a7();
    }
    if (*(uint *)(param_1_00 + 0x18) < _MaxCount) {
      FUN_00405390(_MaxCount,*(undefined4 *)(param_1_00 + 0x14));
    }
    else if (_MaxCount == 0) {
      *(undefined4 *)(param_1_00 + 0x14) = 0;
      if (*(uint *)(param_1_00 + 0x18) < 0x10) {
        *(undefined *)(param_1_00 + 4) = 0;
        return param_1_00;
      }
      **(undefined **)(param_1_00 + 4) = 0;
      return param_1_00;
    }
    if (_MaxCount != 0) {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        param_1 = param_1 + 4;
      }
      else {
        param_1 = *(int *)(param_1 + 4);
      }
      puVar1 = (undefined4 *)(param_1_00 + 4);
      _Dst = puVar1;
      if (0xf < *(uint *)(param_1_00 + 0x18)) {
        _Dst = (undefined4 *)*puVar1;
      }
      _memcpy_s(_Dst,*(uint *)(param_1_00 + 0x18),(void *)(param_1 + param_2),_MaxCount);
      *(uint *)(param_1_00 + 0x14) = _MaxCount;
      if (0xf < *(uint *)(param_1_00 + 0x18)) {
        puVar1 = (undefined4 *)*puVar1;
      }
      *(undefined *)((int)puVar1 + _MaxCount) = 0;
    }
    return param_1_00;
  }
  FUN_00405300(_MaxCount + param_2,0xffffffff);
  FUN_00405300(0,param_2);
  return param_1_00;
}

