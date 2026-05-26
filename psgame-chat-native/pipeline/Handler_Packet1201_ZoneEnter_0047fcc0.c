/*
 * server/ps_game.exe — Handler_Packet1201_ZoneEnter
 * Requested VA: 0x0047FCC0
 * Entry Ghidra:  0047fcc0
 * Ghidra name:   FUN_0047fcc0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: pipeline
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_0047fcc0(void)

{
  short *in_EAX;
  
  if (*in_EAX != 0x1201) {
    FUN_004ec760(9,0);
    return;
  }
  if (((ushort)in_EAX[1] < 0x3e9) && (1 < (ushort)in_EAX[1])) {
    *(undefined *)((ushort)in_EAX[1] + 3 + (int)in_EAX) = 0;
    FUN_00453cb0(in_EAX[1],in_EAX + 2);
  }
  return;
}

