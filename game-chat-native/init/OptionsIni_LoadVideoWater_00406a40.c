/*
 * Game.exe — OptionsIni_LoadVideoWater
 * Requested VA: 0x00406A40
 * Entry Ghidra:  00406a40
 * Ghidra name:   FUN_00406a40
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: init
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 *
 * CONFIRMED: GetPrivateProfileString [VIDEO] WATER → DAT_007c0d8c @ 0x406A95.
 * Compared against "FALSE" @ .rdata 0x746E74; non-FALSE → 1.
 * Used as first operand in balloon gate OR @ Entity_ChatBalloon_Tick 0x412781.
 */

void FUN_00406a40(void)

{
  char local_114 [260];
  
  GetPrivateProfileStringA("VIDEO","WATER","",&DAT_007c0720,local_114,0x104);
  if (local_114[0] == '\0') {
    DAT_007c0d8c = 1;
  }
  else if (_strcmp(local_114,"FALSE") == 0) {
    DAT_007c0d8c = 0;
  }
  else {
    DAT_007c0d8c = 1;
  }
  GetPrivateProfileStringA("VIDEO","CLOAK","",&DAT_007c0720,local_114,0x104);
  return;
}
