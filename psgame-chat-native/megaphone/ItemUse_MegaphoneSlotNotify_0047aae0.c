/*
 * server/ps_game.exe — ItemUse_MegaphoneSlotNotify
 * VA solicitado: 0x0047AAE0
 * Entry Ghidra:  0047aae0
 * Ghidra name:   FUN_0047aae0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: megaphone
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0047aae0(void)

{
  int in_EAX;
  undefined2 local_c;
  undefined4 local_a;
  undefined4 local_6;
  
  local_a = *(undefined4 *)(in_EAX + 0x582c);
  local_6 = *(undefined4 *)(in_EAX + 0x140);
  local_c = 0x603;
  FUN_004ed2d0(&local_c,10);
  return;
}

