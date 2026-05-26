/*
 * Game.exe — ChatUnion_vfn_0x34C
 * Requested VA: 0x0059A940
 * Entry Ghidra:  0059a940
 * Ghidra name:   FUN_0059a940
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: vtable
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_0059a940(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_108;
  iVar1 = FUN_00452b90(param_1);
  if ((iVar1 != 0) &&
     (puVar2 = (undefined4 *)FUN_0046cca0(*(undefined2 *)(iVar1 + 0x2c)),
     puVar2 != (undefined4 *)0x0)) {
    uVar3 = FUN_00420db0(param_2);
    _sprintf(local_108,"%s : %s",*puVar2,uVar3);
    FUN_00422b90(0x30,local_108,0x34);
  }
  ___security_check_cookie_4();
  return;
}

