/*
 * Game.exe — PacketRead_Scalar
 * VA solicitado: 0x005F4700
 * Entry Ghidra:  005f4700
 * Ghidra name:   FUN_005f4700
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: recv
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


size_t __thiscall FUN_005f4700(int param_1_00,void *param_1,size_t param_2)

{
  void *_Src;
  
  _Src = *(void **)(param_1_00 + 0x2004);
  if ((uint)(*(int *)(param_1_00 + 0x2000) + param_1_00) < (int)_Src + param_2) {
    _memset(param_1,0,param_2);
    (**(code **)(*DAT_022fa2f0 + 0x680))(param_1_00);
    _Src = *(void **)(param_1_00 + 0x2004);
    param_2 = (param_1_00 - (int)_Src) + *(int *)(param_1_00 + 0x2000);
    if (param_2 == 0) {
      return 0;
    }
  }
  _memcpy(param_1,_Src,param_2);
  *(int *)(param_1_00 + 0x2004) = *(int *)(param_1_00 + 0x2004) + param_2;
  return param_2;
}

