/*
 * Game.exe — ChatBox_ParseColorCode
 * Requested VA: 0x00407F70
 * Entry Ghidra:  00407f70
 * Ghidra name:   FUN_00407f70
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: buffer
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


undefined4 FUN_00407f70(byte param_1,undefined4 *param_2)

{
  BOOL BVar1;
  
  if (DAT_007ab0d4 == 3) {
    if (-1 < (char)param_1) {
      *param_2 = 1;
      return 0;
    }
    if ((param_1 & 0xf0) == 0xf0) {
      *param_2 = 4;
      return 1;
    }
    if ((param_1 & 0xe0) == 0xe0) {
      *param_2 = 3;
      return 1;
    }
    if ((param_1 & 0xc0) == 0xc0) {
LAB_00407fd3:
      *param_2 = 2;
      return 1;
    }
  }
  else {
    if ((DAT_007ab0d4 == 4) && (BVar1 = IsDBCSLeadByteEx(0x3a4,param_1), BVar1 != 0)) {
      *param_2 = 2;
      return 1;
    }
    if ((DAT_007ab0d4 == 5) || (DAT_007ab0d4 == 9)) {
      BVar1 = IsDBCSLeadByteEx(0x3b6,param_1);
      if (BVar1 != 0) goto LAB_00407fd3;
      goto LAB_00408046;
    }
  }
  BVar1 = IsDBCSLeadByte(param_1);
  if (BVar1 != 0) {
    *param_2 = 2;
    return 1;
  }
LAB_00408046:
  *param_2 = 1;
  return 0;
}

