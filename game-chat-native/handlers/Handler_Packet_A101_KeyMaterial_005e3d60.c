/*
 * Game.exe — Handler_Packet_A101_KeyMaterial
 * Requested VA: 0x005E3D60
 * Entry Ghidra:  005e3d60
 * Ghidra name:   FUN_005e3d60
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005e3d60(void)

{
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined local_c4 [64];
  undefined local_84 [128];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_d0;
  FUN_005f4700(&local_d0,1);
  FUN_005f4700(&local_c8,1);
  FUN_005f4700(&local_cc,1);
  FUN_005f4700(local_c4,0x40);
  FUN_005f4700(local_84,0x80);
  (**(code **)(*DAT_022fa2f0 + 0x254))(local_d0,local_c8,local_cc,local_c4,local_84);
  ___security_check_cookie_4();
  return;
}

