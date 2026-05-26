/*
 * server/ps_game.exe — Chat_ScriptWrapper_110B
 * Requested VA: 0x004CB430
 * Entry Ghidra:  004cb430
 * Ghidra name:   FUN_004cb430
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_004cb430(undefined4 param_1)

{
  undefined4 uVar1;
  float10 fVar2;
  float fVar3;
  
  fVar2 = (float10)FUN_00507880(param_1,2);
  fVar3 = (float)fVar2;
  uVar1 = FUN_00507930(param_1,1,0,fVar3);
  FUN_004c8520(uVar1,fVar3);
  return 0;
}

