/*
 * Game.exe — AES_BlockKeystream
 * Requested VA: 0x00404830
 * Entry Ghidra:  00404830
 * Ghidra name:   FUN_00404830
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_00404830(uint *param_1,uint *param_2)

{
  uint *in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = *in_EAX;
  uVar3 = (uVar1 >> 8 & 0xff00ff00 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 0x18) ^
          *param_2;
  uVar1 = in_EAX[1];
  uVar7 = (uVar1 >> 8 & 0xff00ff00 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 0x18) ^
          param_2[1];
  uVar1 = in_EAX[2];
  uVar5 = (uVar1 >> 8 & 0xff00ff00 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 0x18) ^
          param_2[2];
  uVar1 = in_EAX[3];
  uVar8 = (uVar1 >> 8 & 0xff00ff00 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 0x18) ^
          param_2[3];
  uVar1 = *(uint *)(&DAT_0078ff60 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_0078fb60 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_0078f760 + (uVar3 >> 0x18) * 4) ^
          *(uint *)(&DAT_00790360 + (uVar8 & 0xff) * 4) ^ param_2[4];
  uVar2 = *(uint *)(&DAT_0078ff60 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_0078fb60 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_0078f760 + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&DAT_00790360 + (uVar3 & 0xff) * 4) ^ param_2[5];
  uVar9 = *(uint *)(&DAT_0078fb60 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_0078ff60 + (uVar3 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_0078f760 + (uVar5 >> 0x18) * 4) ^
          *(uint *)(&DAT_00790360 + (uVar7 & 0xff) * 4) ^ param_2[6];
  puVar6 = param_2 + 8;
  uVar3 = *(uint *)(&DAT_0078ff60 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_0078fb60 + (uVar3 >> 0x10 & 0xff) * 4) ^
          *(uint *)(&DAT_0078f760 + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&DAT_00790360 + (uVar5 & 0xff) * 4) ^ param_2[7];
  iVar4 = (int)param_2[0x3c] >> 1;
  while (iVar4 = iVar4 + -1, iVar4 != 0) {
    uVar5 = *(uint *)(&DAT_0078ff60 + (uVar9 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078fb60 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar1 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar3 & 0xff) * 4) ^ *puVar6;
    uVar8 = *(uint *)(&DAT_0078ff60 + (uVar3 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078fb60 + (uVar9 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar1 & 0xff) * 4) ^ puVar6[1];
    uVar7 = *(uint *)(&DAT_0078fb60 + (uVar3 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078ff60 + (uVar1 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar9 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar2 & 0xff) * 4) ^ puVar6[2];
    uVar9 = *(uint *)(&DAT_0078ff60 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078fb60 + (uVar1 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar9 & 0xff) * 4) ^ puVar6[3];
    uVar1 = *(uint *)(&DAT_0078ff60 + (uVar7 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078fb60 + (uVar8 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar5 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar9 & 0xff) * 4) ^ puVar6[4];
    uVar2 = *(uint *)(&DAT_0078ff60 + (uVar9 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078fb60 + (uVar7 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar8 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar5 & 0xff) * 4) ^ puVar6[5];
    uVar3 = *(uint *)(&DAT_0078ff60 + (uVar8 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078fb60 + (uVar5 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar9 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar7 & 0xff) * 4) ^ puVar6[7];
    uVar9 = *(uint *)(&DAT_0078fb60 + (uVar9 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_0078ff60 + (uVar5 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_0078f760 + (uVar7 >> 0x18) * 4) ^
            *(uint *)(&DAT_00790360 + (uVar8 & 0xff) * 4) ^ puVar6[6];
    puVar6 = puVar6 + 8;
  }
  uVar5 = *(uint *)(&DAT_00790760 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff0000 ^
          *(uint *)(&DAT_00790760 + (uVar9 >> 8 & 0xff) * 4) & 0xff00 ^
          *(uint *)(&DAT_00790760 + (uVar1 >> 0x18) * 4) & 0xff000000 ^
          (uint)(byte)(&DAT_00790760)[(uVar3 & 0xff) * 4] ^ *puVar6;
  *param_1 = uVar5 >> 8 & 0xff00ff00 | uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 0x18;
  uVar5 = *(uint *)(&DAT_00790760 + (uVar9 >> 0x10 & 0xff) * 4) & 0xff0000 ^
          *(uint *)(&DAT_00790760 + (uVar3 >> 8 & 0xff) * 4) & 0xff00 ^
          *(uint *)(&DAT_00790760 + (uVar2 >> 0x18) * 4) & 0xff000000 ^
          (uint)(byte)(&DAT_00790760)[(uVar1 & 0xff) * 4] ^ puVar6[1];
  param_1[1] = uVar5 >> 8 & 0xff00ff00 | uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 0x18;
  uVar5 = *(uint *)(&DAT_00790760 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff0000 ^
          *(uint *)(&DAT_00790760 + (uVar1 >> 8 & 0xff) * 4) & 0xff00 ^
          *(uint *)(&DAT_00790760 + (uVar9 >> 0x18) * 4) & 0xff000000 ^
          (uint)(byte)(&DAT_00790760)[(uVar2 & 0xff) * 4] ^ puVar6[2];
  param_1[2] = uVar5 >> 8 & 0xff00ff00 | uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 0x18;
  uVar1 = *(uint *)(&DAT_00790760 + (uVar1 >> 0x10 & 0xff) * 4) & 0xff0000 ^
          *(uint *)(&DAT_00790760 + (uVar2 >> 8 & 0xff) * 4) & 0xff00 ^
          *(uint *)(&DAT_00790760 + (uVar3 >> 0x18) * 4) & 0xff000000 ^
          (uint)(byte)(&DAT_00790760)[(uVar9 & 0xff) * 4] ^ puVar6[3];
  param_1[3] = uVar1 >> 8 & 0xff00ff00 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 0x18;
  return;
}

