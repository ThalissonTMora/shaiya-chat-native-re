/*
 * server/ps_game.exe — Chat_ScriptWrapper_110A
 * Requested VA: 0x004CB3D0
 * Entry Ghidra:  004cb3d0
 * Ghidra name:   FUN_004cb3d0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 FUN_004cb3d0(undefined4 param_1)

{
  float10 fVar1;
  float fVar2;
  
  fVar1 = (float10)FUN_00507880(param_1,2);
  fVar2 = (float)fVar1;
  FUN_00507880(param_1,1,fVar2);
  FUN_004c8310(fVar2);
  return 0;
}

