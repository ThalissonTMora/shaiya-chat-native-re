/*
 * Game.exe — ChatObject_PacketUnderflow_vfn680
 * VA solicitado: 0x00598DC0
 * Entry Ghidra:  00598dc0
 * Ghidra name:   FUN_00598dc0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: vtable
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00598dc0(ushort *param_1)

{
  undefined *puStack_b0;
  undefined auStack_ac [24];
  uint uStack_94;
  CHAR local_90 [128];
  uint local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0073906b;
  local_c = ExceptionList;
  local_10 = DAT_007b4dd0 ^ (uint)&puStack_b0;
  ExceptionList = &local_c;
  if (param_1 == (ushort *)0x0) {
    DAT_022eed38 = (ushort *)0x0;
  }
  else if (DAT_022eed38 != param_1) {
    DAT_022eed38 = param_1;
    _memset(local_90,0,0x80);
    wsprintfA(local_90,"Packet Underflow. Protocol : 0x%04X Size : %d Read %d");
    FUN_00408c10();
    FUN_005fd900();
    if (DAT_022fe9a8 == 2) {
      FUN_0060c240();
      puStack_b0 = &stack0xffffff28;
      uStack_4 = 0;
      FUN_00405780("Shaiya Error Report-Packet Error");
      FUN_0060fd60(2);
      puStack_b0 = &stack0xffffff28;
      FUN_00405590(auStack_ac,0,0xffffffff);
      FUN_0060fd60(3);
      FUN_0060fde0();
      if (0xf < uStack_94) {
                    /* WARNING: Subroutine does not return */
        FUN_006307cd();
      }
    }
  }
  ExceptionList = local_c;
  ___security_check_cookie_4();
  return;
}

