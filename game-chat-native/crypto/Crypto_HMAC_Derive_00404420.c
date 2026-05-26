/*
 * Game.exe — Crypto_HMAC_Derive
 * Requested VA: 0x00404420
 * Entry Ghidra:  00404420
 * Ghidra name:   FUN_00404420
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 *
 * Calling convention (CONFIRMED @ 0x40115C–0x401162 caller):
 *   ECX = block_b pointer
 *   EBX = digest output (32 B) — caller lea ebx,[esp+0x40] → stack+0x38 after arg pops
 *   Stack [esp+0x11c] = PRNG buffer pointer (128 B at caller stack+0x58)
 *   Stack [esp+0x120] = zero-extended field_2 (inner HMAC message length)
 *
 * Pipeline (CONFIRMED disasm):
 *   key0 = SHA256(prng, 128)                    @ 0x404434–0x404496
 *   digest = HMAC_SHA256(key0, block_b, field_2) @ 0x404506–0x404579 (len @ 0x404569)
 *   outer finalize reuses EBX buffer             @ 0x40457E–0x4045E8
 */


void FUN_00404420(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined auStack_ac [32];
  byte abStack_8c [64];
  byte abStack_4c [68];
  uint uStack_8;
  
  uStack_8 = DAT_007b4dd0 ^ (uint)&uStack_118;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0x6a09e667;
  uStack_108 = 0xbb67ae85;
  uStack_104 = 0x3c6ef372;
  uStack_100 = 0xa54ff53a;
  uStack_fc = 0x510e527f;
  uStack_f8 = 0x9b05688c;
  uStack_f4 = 0x1f83d9ab;
  uStack_f0 = 0x5be0cd19;
  FUN_00404150(param_1);
  FUN_004041f0();
  FUN_006319e0(abStack_8c,0,0x40);
  FUN_006319e0(abStack_4c,0,0x40);
  FUN_00631300(abStack_8c,auStack_ac,0x20);
  FUN_00631300(abStack_4c,auStack_ac,0x20);
  iVar1 = 0;
  do {
    abStack_8c[iVar1] = abStack_8c[iVar1] ^ 0x36;
    abStack_4c[iVar1] = abStack_4c[iVar1] ^ 0x5c;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0x6a09e667;
  uStack_108 = 0xbb67ae85;
  uStack_104 = 0x3c6ef372;
  uStack_100 = 0xa54ff53a;
  uStack_fc = 0x510e527f;
  uStack_f8 = 0x9b05688c;
  uStack_f4 = 0x1f83d9ab;
  uStack_f0 = 0x5be0cd19;
  FUN_00404150(abStack_8c);
  FUN_00404150(uStack_118);
  FUN_004041f0();
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0x6a09e667;
  uStack_108 = 0xbb67ae85;
  uStack_104 = 0x3c6ef372;
  uStack_100 = 0xa54ff53a;
  uStack_fc = 0x510e527f;
  uStack_f8 = 0x9b05688c;
  uStack_f4 = 0x1f83d9ab;
  uStack_f0 = 0x5be0cd19;
  FUN_00404150(abStack_4c);
  FUN_00404150();
  FUN_004041f0();
  FUN_00630c8a();
  return;
}

