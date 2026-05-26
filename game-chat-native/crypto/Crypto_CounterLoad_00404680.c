/*
 * Game.exe — Crypto_CounterLoad
 * Requested VA: 0x00404680
 * Entry Ghidra:  00404680
 * Ghidra name:   FUN_00404680
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


undefined4 __fastcall FUN_00404680(uint *param_1)

{
  uint *in_EAX;
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  if ((param_1 != (uint *)0x0) && (in_EAX != (uint *)0x0)) {
    in_EAX[0x3c] = 10;
    uVar2 = *param_1;
    *in_EAX = uVar2 >> 8 & 0xff00ff00 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 0x18;
    uVar2 = param_1[1];
    in_EAX[1] = uVar2 >> 8 & 0xff00ff00 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 0x18;
    uVar2 = param_1[2];
    in_EAX[2] = uVar2 >> 8 & 0xff00ff00 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 0x18;
    uVar2 = param_1[3];
    uVar3 = uVar2 >> 8 & 0xff00ff00 | uVar2 << 0x18 | uVar2 << 8 & 0xff00ff | uVar2 >> 0x18;
    in_EAX[3] = uVar3;
    uVar2 = (*(uint *)(&DAT_00790760 + ((uVar2 << 8 & 0xff0000) >> 0x10) * 4) ^ 0x1000000) &
            0xff000000 ^ *(uint *)(&DAT_00790760 + ((uVar2 >> 8 & 0xff00) >> 8) * 4) & 0xff0000 ^
            (uint)(byte)(&DAT_00790760)[(uVar2 & 0xff) * 4] ^
            *(uint *)(&DAT_00790760 + (uVar2 >> 0x18) * 4) & 0xff00 ^ *in_EAX;
    uVar6 = in_EAX[1] ^ uVar2;
    in_EAX[4] = uVar2;
    uVar2 = in_EAX[2] ^ uVar6;
    in_EAX[6] = uVar2;
    in_EAX[5] = uVar6;
    in_EAX[7] = uVar2 ^ uVar3;
    puVar1 = in_EAX + 1;
    puVar4 = &DAT_00791f64;
    do {
      uVar2 = puVar1[6];
      puVar5 = puVar4 + 1;
      uVar2 = *(uint *)(&DAT_00790760 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
              *(uint *)(&DAT_00790760 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
              (uint)(byte)(&DAT_00790760)[(uVar2 >> 0x18) * 4] ^
              *(uint *)(&DAT_00790760 + (uVar2 & 0xff) * 4) & 0xff00 ^ puVar1[3] ^ *puVar4;
      puVar1[7] = uVar2;
      uVar2 = puVar1[4] ^ uVar2;
      puVar1[8] = uVar2;
      uVar2 = puVar1[5] ^ uVar2;
      puVar1[9] = uVar2;
      puVar1[10] = puVar1[6] ^ uVar2;
      puVar1 = puVar1 + 4;
      puVar4 = puVar5;
    } while ((DotNetPdbInfo *)puVar5 != &DotNetPdbInfo_00791f88);
    return 0;
  }
  return 0xffffffff;
}

