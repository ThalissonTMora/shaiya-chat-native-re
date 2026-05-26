/*
 * ps_game.exe — AES_KeyExpand
 * Requested VA: 0x004E4350
 * Entry Ghidra:  004e4350
 * Ghidra name:   FUN_004e4350
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


void FUN_004e4350(int param_1)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  undefined *in_EAX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  
  iVar24 = CONCAT31(CONCAT21(CONCAT11(*in_EAX,in_EAX[1]),in_EAX[2]),in_EAX[3]);
  uVar6 = CONCAT31(CONCAT21(CONCAT11(in_EAX[4],in_EAX[5]),in_EAX[6]),in_EAX[7]);
  uVar7 = CONCAT31(CONCAT21(CONCAT11(in_EAX[8],in_EAX[9]),in_EAX[10]),in_EAX[0xb]);
  uVar8 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0xc],in_EAX[0xd]),in_EAX[0xe]),in_EAX[0xf]);
  uVar9 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x10],in_EAX[0x11]),in_EAX[0x12]),in_EAX[0x13]);
  uVar10 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x14],in_EAX[0x15]),in_EAX[0x16]),in_EAX[0x17]);
  uVar11 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x18],in_EAX[0x19]),in_EAX[0x1a]),in_EAX[0x1b]);
  uVar12 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x1c],in_EAX[0x1d]),in_EAX[0x1e]),in_EAX[0x1f]);
  uVar13 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x20],in_EAX[0x21]),in_EAX[0x22]),in_EAX[0x23]);
  uVar14 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x24],in_EAX[0x25]),in_EAX[0x26]),in_EAX[0x27]);
  uVar15 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x28],in_EAX[0x29]),in_EAX[0x2a]),in_EAX[0x2b]);
  uVar16 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x2c],in_EAX[0x2d]),in_EAX[0x2e]),in_EAX[0x2f]);
  uVar17 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x30],in_EAX[0x31]),in_EAX[0x32]),in_EAX[0x33]);
  uVar18 = CONCAT31(CONCAT21(CONCAT11(in_EAX[0x34],in_EAX[0x35]),in_EAX[0x36]),in_EAX[0x37]);
  uVar2 = CONCAT11(in_EAX[0x38],in_EAX[0x39]);
  uVar19 = CONCAT31(CONCAT21(uVar2,in_EAX[0x3a]),in_EAX[0x3b]);
  uVar27 = *(uint *)(param_1 + 8);
  uVar25 = *(uint *)(param_1 + 0xc);
  uVar3 = CONCAT11(in_EAX[0x3c],in_EAX[0x3d]);
  uVar28 = *(uint *)(param_1 + 0x18);
  uVar20 = CONCAT31(CONCAT21(uVar3,in_EAX[0x3e]),in_EAX[0x3f]);
  uVar5 = *(uint *)(param_1 + 0x1c);
  uVar29 = *(uint *)(param_1 + 0x20);
  iVar1 = iVar24 + 0x428a2f98 +
          ((uVar29 ^ uVar5) & uVar28 ^ uVar29) +
          ((uVar28 >> 0x19 | uVar28 << 7) ^ (uVar28 >> 0xb | uVar28 << 0x15) ^
          (uVar28 >> 6 | uVar28 << 0x1a)) + *(int *)(param_1 + 0x24);
  uVar21 = *(int *)(param_1 + 0x14) + iVar1;
  uVar4 = ((uVar25 | uVar27) & *(uint *)(param_1 + 0x10) | uVar25 & uVar27) +
          ((uVar27 >> 0x16 | uVar27 << 10) ^ (uVar27 >> 0xd | uVar27 << 0x13) ^
          (uVar27 >> 2 | uVar27 << 0x1e)) + iVar1;
  iVar1 = uVar6 + 0x71374491 +
          ((uVar5 ^ uVar28) & uVar21 ^ uVar5) +
          ((uVar21 >> 0x19 | uVar21 * 0x80) ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^
          (uVar21 >> 6 | uVar21 * 0x4000000)) + uVar29;
  uVar29 = *(uint *)(param_1 + 0x10) + iVar1;
  uVar22 = ((uVar4 | uVar27) & uVar25 | uVar4 & uVar27) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  iVar1 = ((uVar28 ^ uVar21) & uVar29 ^ uVar28) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar5 + -0x4a3f0431 + uVar7;
  uVar25 = uVar25 + iVar1;
  uVar23 = ((uVar4 | uVar22) & uVar27 | uVar4 & uVar22) +
           ((uVar22 >> 0x16 | uVar22 * 0x400) ^ (uVar22 >> 0xd | uVar22 * 0x80000) ^
           (uVar22 >> 2 | uVar22 * 0x40000000)) + iVar1;
  iVar1 = ((uVar21 ^ uVar29) & uVar25 ^ uVar21) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar28 + -0x164a245b + uVar8;
  uVar27 = uVar27 + iVar1;
  uVar26 = ((uVar22 | uVar23) & uVar4 | uVar22 & uVar23) +
           ((uVar23 >> 0x16 | uVar23 * 0x400) ^ (uVar23 >> 0xd | uVar23 * 0x80000) ^
           (uVar23 >> 2 | uVar23 * 0x40000000)) + iVar1;
  iVar1 = ((uVar29 ^ uVar25) & uVar27 ^ uVar29) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar21 + 0x3956c25b + uVar9;
  uVar4 = uVar4 + iVar1;
  uVar28 = ((uVar23 | uVar26) & uVar22 | uVar23 & uVar26) +
           ((uVar26 >> 0x16 | uVar26 * 0x400) ^ (uVar26 >> 0xd | uVar26 * 0x80000) ^
           (uVar26 >> 2 | uVar26 * 0x40000000)) + iVar1;
  iVar1 = ((uVar25 ^ uVar27) & uVar4 ^ uVar25) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar29 + 0x59f111f1 + uVar10;
  uVar22 = uVar22 + iVar1;
  uVar29 = ((uVar26 | uVar28) & uVar23 | uVar26 & uVar28) +
           ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
           (uVar28 >> 2 | uVar28 * 0x40000000)) + iVar1;
  iVar1 = uVar11 + 0x923f82a4 +
          ((uVar4 ^ uVar27) & uVar22 ^ uVar27) +
          ((uVar22 >> 0x19 | uVar22 * 0x80) ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^
          (uVar22 >> 6 | uVar22 * 0x4000000)) + uVar25;
  uVar23 = uVar23 + iVar1;
  uVar25 = ((uVar28 | uVar29) & uVar26 | uVar28 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  iVar1 = ((uVar4 ^ uVar22) & uVar23 ^ uVar4) +
          ((uVar23 >> 0x19 | uVar23 * 0x80) ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^
          (uVar23 >> 6 | uVar23 * 0x4000000)) + uVar27 + -0x54e3a12b + uVar12;
  uVar26 = uVar26 + iVar1;
  uVar30 = ((uVar29 | uVar25) & uVar28 | uVar29 & uVar25) +
           ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
           (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  iVar1 = uVar13 + 0xd807aa98 +
          ((uVar22 ^ uVar23) & uVar26 ^ uVar22) +
          ((uVar26 >> 0x19 | uVar26 * 0x80) ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^
          (uVar26 >> 6 | uVar26 * 0x4000000)) + uVar4;
  uVar28 = uVar28 + iVar1;
  uVar27 = ((uVar25 | uVar30) & uVar29 | uVar25 & uVar30) +
           ((uVar30 >> 0x16 | uVar30 * 0x400) ^ (uVar30 >> 0xd | uVar30 * 0x80000) ^
           (uVar30 >> 2 | uVar30 * 0x40000000)) + iVar1;
  iVar1 = uVar14 + 0x12835b01 +
          ((uVar23 ^ uVar26) & uVar28 ^ uVar23) +
          ((uVar28 >> 0x19 | uVar28 * 0x80) ^ (uVar28 >> 0xb | uVar28 * 0x200000) ^
          (uVar28 >> 6 | uVar28 * 0x4000000)) + uVar22;
  uVar29 = uVar29 + iVar1;
  uVar5 = ((uVar27 | uVar30) & uVar25 | uVar27 & uVar30) +
          ((uVar27 >> 0x16 | uVar27 * 0x400) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
          (uVar27 >> 2 | uVar27 * 0x40000000)) + iVar1;
  iVar1 = ((uVar26 ^ uVar28) & uVar29 ^ uVar26) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar23 + 0x243185be + uVar15;
  uVar25 = uVar25 + iVar1;
  uVar4 = ((uVar27 | uVar5) & uVar30 | uVar27 & uVar5) +
          ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
          (uVar5 >> 2 | uVar5 * 0x40000000)) + iVar1;
  iVar1 = ((uVar28 ^ uVar29) & uVar25 ^ uVar28) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar26 + 0x550c7dc3 + uVar16;
  uVar30 = uVar30 + iVar1;
  uVar21 = ((uVar5 | uVar4) & uVar27 | uVar5 & uVar4) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  iVar1 = ((uVar29 ^ uVar25) & uVar30 ^ uVar29) +
          ((uVar30 >> 0x19 | uVar30 * 0x80) ^ (uVar30 >> 0xb | uVar30 * 0x200000) ^
          (uVar30 >> 6 | uVar30 * 0x4000000)) + uVar28 + 0x72be5d74 + uVar17;
  uVar27 = uVar27 + iVar1;
  uVar28 = ((uVar4 | uVar21) & uVar5 | uVar4 & uVar21) +
           ((uVar21 >> 0x16 | uVar21 * 0x400) ^ (uVar21 >> 0xd | uVar21 * 0x80000) ^
           (uVar21 >> 2 | uVar21 * 0x40000000)) + iVar1;
  iVar1 = uVar18 + 0x80deb1fe +
          ((uVar25 ^ uVar30) & uVar27 ^ uVar25) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar29;
  uVar5 = uVar5 + iVar1;
  uVar29 = ((uVar21 | uVar28) & uVar4 | uVar21 & uVar28) +
           ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
           (uVar28 >> 2 | uVar28 * 0x40000000)) + iVar1;
  iVar1 = ((uVar27 ^ uVar30) & uVar5 ^ uVar30) +
          ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
          (uVar5 >> 6 | uVar5 * 0x4000000)) + uVar25 + -0x6423f959 + uVar19;
  uVar4 = uVar4 + iVar1;
  uVar25 = ((uVar28 | uVar29) & uVar21 | uVar28 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  iVar1 = uVar20 + 0xc19bf174 +
          ((uVar27 ^ uVar5) & uVar4 ^ uVar27) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar30;
  uVar21 = uVar21 + iVar1;
  uVar23 = ((uVar29 | uVar25) & uVar28 | uVar29 & uVar25) +
           ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
           (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  uVar22 = (((uint)(ushort)(CONCAT11(in_EAX[4],in_EAX[5]) >> 2) | uVar6 << 0xe) ^
            (uVar6 >> 7 | uVar6 << 0x19) ^ uVar6 >> 3) +
           (((uint)(uVar2 >> 3) | uVar19 << 0xd) ^ ((uint)(uVar2 >> 1) | uVar19 << 0xf) ^
           (uint)(uint3)(CONCAT21(uVar2,in_EAX[0x3a]) >> 2)) + uVar14 + iVar24;
  iVar1 = uVar27 + 0xe49b69c1 +
          ((uVar5 ^ uVar4) & uVar21 ^ uVar5) +
          ((uVar21 >> 0x19 | uVar21 * 0x80) ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^
          (uVar21 >> 6 | uVar21 * 0x4000000)) + uVar22;
  uVar28 = uVar28 + iVar1;
  uVar27 = ((uVar25 | uVar23) & uVar29 | uVar25 & uVar23) +
           ((uVar23 >> 0x16 | uVar23 * 0x400) ^ (uVar23 >> 0xd | uVar23 * 0x80000) ^
           (uVar23 >> 2 | uVar23 * 0x40000000)) + iVar1;
  uVar6 = (((uint)(ushort)(CONCAT11(in_EAX[8],in_EAX[9]) >> 2) | uVar7 << 0xe) ^
           (uVar7 >> 7 | uVar7 << 0x19) ^ uVar7 >> 3) +
          (((uint)(uVar3 >> 3) | uVar20 << 0xd) ^ ((uint)(uVar3 >> 1) | uVar20 << 0xf) ^
          (uint)(uint3)(CONCAT21(uVar3,in_EAX[0x3e]) >> 2)) + uVar15 + uVar6;
  iVar1 = uVar5 + 0xefbe4786 +
          ((uVar4 ^ uVar21) & uVar28 ^ uVar4) +
          ((uVar28 >> 0x19 | uVar28 * 0x80) ^ (uVar28 >> 0xb | uVar28 * 0x200000) ^
          (uVar28 >> 6 | uVar28 * 0x4000000)) + uVar6;
  uVar29 = uVar29 + iVar1;
  uVar26 = ((uVar27 | uVar23) & uVar25 | uVar27 & uVar23) +
           ((uVar27 >> 0x16 | uVar27 * 0x400) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
           (uVar27 >> 2 | uVar27 * 0x40000000)) + iVar1;
  uVar7 = (((uint)(ushort)(CONCAT11(in_EAX[0xc],in_EAX[0xd]) >> 2) | uVar8 << 0xe) ^
           (uVar8 >> 7 | uVar8 << 0x19) ^ uVar8 >> 3) +
          ((uVar22 >> 0x13 | uVar22 * 0x2000) ^ (uVar22 >> 0x11 | uVar22 * 0x8000) ^ uVar22 >> 10) +
          uVar16 + uVar7;
  iVar1 = ((uVar21 ^ uVar28) & uVar29 ^ uVar21) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar7 + 0xfc19dc6 + uVar4;
  uVar25 = uVar25 + iVar1;
  uVar5 = ((uVar27 | uVar26) & uVar23 | uVar27 & uVar26) +
          ((uVar26 >> 0x16 | uVar26 * 0x400) ^ (uVar26 >> 0xd | uVar26 * 0x80000) ^
          (uVar26 >> 2 | uVar26 * 0x40000000)) + iVar1;
  uVar8 = (((uint)(ushort)(CONCAT11(in_EAX[0x10],in_EAX[0x11]) >> 2) | uVar9 << 0xe) ^
           (uVar9 >> 7 | uVar9 << 0x19) ^ uVar9 >> 3) +
          ((uVar6 >> 0x13 | uVar6 * 0x2000) ^ (uVar6 >> 0x11 | uVar6 * 0x8000) ^ uVar6 >> 10) +
          uVar17 + uVar8;
  iVar1 = ((uVar28 ^ uVar29) & uVar25 ^ uVar28) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar8 + 0x240ca1cc + uVar21;
  uVar23 = uVar23 + iVar1;
  uVar4 = ((uVar26 | uVar5) & uVar27 | uVar26 & uVar5) +
          ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
          (uVar5 >> 2 | uVar5 * 0x40000000)) + iVar1;
  uVar9 = (((uint)(ushort)(CONCAT11(in_EAX[0x14],in_EAX[0x15]) >> 2) | uVar10 << 0xe) ^
           (uVar10 >> 7 | uVar10 << 0x19) ^ uVar10 >> 3) +
          ((uVar7 >> 0x13 | uVar7 * 0x2000) ^ (uVar7 >> 0x11 | uVar7 * 0x8000) ^ uVar7 >> 10) +
          uVar18 + uVar9;
  iVar1 = ((uVar29 ^ uVar25) & uVar23 ^ uVar29) +
          ((uVar23 >> 0x19 | uVar23 * 0x80) ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^
          (uVar23 >> 6 | uVar23 * 0x4000000)) + uVar9 + 0x2de92c6f + uVar28;
  uVar27 = uVar27 + iVar1;
  uVar28 = ((uVar5 | uVar4) & uVar26 | uVar5 & uVar4) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  uVar10 = (((uint)(ushort)(CONCAT11(in_EAX[0x18],in_EAX[0x19]) >> 2) | uVar11 << 0xe) ^
            (uVar11 >> 7 | uVar11 << 0x19) ^ uVar11 >> 3) +
           ((uVar8 >> 0x13 | uVar8 * 0x2000) ^ (uVar8 >> 0x11 | uVar8 * 0x8000) ^ uVar8 >> 10) +
           uVar19 + uVar10;
  iVar1 = uVar29 + 0x4a7484aa +
          ((uVar25 ^ uVar23) & uVar27 ^ uVar25) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar10;
  uVar26 = uVar26 + iVar1;
  uVar29 = ((uVar4 | uVar28) & uVar5 | uVar4 & uVar28) +
           ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
           (uVar28 >> 2 | uVar28 * 0x40000000)) + iVar1;
  uVar11 = (((uint)(ushort)(CONCAT11(in_EAX[0x1c],in_EAX[0x1d]) >> 2) | uVar12 << 0xe) ^
            (uVar12 >> 7 | uVar12 << 0x19) ^ uVar12 >> 3) +
           ((uVar9 >> 0x13 | uVar9 * 0x2000) ^ (uVar9 >> 0x11 | uVar9 * 0x8000) ^ uVar9 >> 10) +
           uVar20 + uVar11;
  iVar1 = uVar25 + 0x5cb0a9dc +
          ((uVar27 ^ uVar23) & uVar26 ^ uVar23) +
          ((uVar26 >> 0x19 | uVar26 * 0x80) ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^
          (uVar26 >> 6 | uVar26 * 0x4000000)) + uVar11;
  uVar5 = uVar5 + iVar1;
  uVar21 = ((uVar28 | uVar29) & uVar4 | uVar28 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  uVar12 = (((uint)(ushort)(CONCAT11(in_EAX[0x20],in_EAX[0x21]) >> 2) | uVar13 << 0xe) ^
            (uVar13 >> 7 | uVar13 << 0x19) ^ uVar13 >> 3) +
           ((uVar10 >> 0x13 | uVar10 * 0x2000) ^ (uVar10 >> 0x11 | uVar10 * 0x8000) ^ uVar10 >> 10)
           + uVar22 + uVar12;
  iVar1 = uVar23 + 0x76f988da +
          ((uVar27 ^ uVar26) & uVar5 ^ uVar27) +
          ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
          (uVar5 >> 6 | uVar5 * 0x4000000)) + uVar12;
  uVar4 = uVar4 + iVar1;
  uVar25 = ((uVar29 | uVar21) & uVar28 | uVar29 & uVar21) +
           ((uVar21 >> 0x16 | uVar21 * 0x400) ^ (uVar21 >> 0xd | uVar21 * 0x80000) ^
           (uVar21 >> 2 | uVar21 * 0x40000000)) + iVar1;
  uVar13 = (((uint)(ushort)(CONCAT11(in_EAX[0x24],in_EAX[0x25]) >> 2) | uVar14 << 0xe) ^
            (uVar14 >> 7 | uVar14 << 0x19) ^ uVar14 >> 3) +
           ((uVar11 >> 0x13 | uVar11 * 0x2000) ^ (uVar11 >> 0x11 | uVar11 * 0x8000) ^ uVar11 >> 10)
           + uVar6 + uVar13;
  iVar1 = uVar27 + 0x983e5152 +
          ((uVar26 ^ uVar5) & uVar4 ^ uVar26) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar13;
  uVar28 = uVar28 + iVar1;
  uVar23 = ((uVar21 | uVar25) & uVar29 | uVar21 & uVar25) +
           ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
           (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  uVar14 = (((uint)(ushort)(CONCAT11(in_EAX[0x28],in_EAX[0x29]) >> 2) | uVar15 << 0xe) ^
            (uVar15 >> 7 | uVar15 << 0x19) ^ uVar15 >> 3) +
           ((uVar12 >> 0x13 | uVar12 * 0x2000) ^ (uVar12 >> 0x11 | uVar12 * 0x8000) ^ uVar12 >> 10)
           + uVar7 + uVar14;
  iVar1 = uVar26 + 0xa831c66d +
          ((uVar5 ^ uVar4) & uVar28 ^ uVar5) +
          ((uVar28 >> 0x19 | uVar28 * 0x80) ^ (uVar28 >> 0xb | uVar28 * 0x200000) ^
          (uVar28 >> 6 | uVar28 * 0x4000000)) + uVar14;
  uVar29 = uVar29 + iVar1;
  uVar26 = ((uVar23 | uVar25) & uVar21 | uVar23 & uVar25) +
           ((uVar23 >> 0x16 | uVar23 * 0x400) ^ (uVar23 >> 0xd | uVar23 * 0x80000) ^
           (uVar23 >> 2 | uVar23 * 0x40000000)) + iVar1;
  uVar15 = (((uint)(ushort)(CONCAT11(in_EAX[0x2c],in_EAX[0x2d]) >> 2) | uVar16 << 0xe) ^
            (uVar16 >> 7 | uVar16 << 0x19) ^ uVar16 >> 3) +
           ((uVar13 >> 0x13 | uVar13 * 0x2000) ^ (uVar13 >> 0x11 | uVar13 * 0x8000) ^ uVar13 >> 10)
           + uVar8 + uVar15;
  iVar1 = ((uVar4 ^ uVar28) & uVar29 ^ uVar4) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar15 + -0x4ffcd838 + uVar5;
  uVar21 = uVar21 + iVar1;
  uVar5 = ((uVar23 | uVar26) & uVar25 | uVar23 & uVar26) +
          ((uVar26 >> 0x16 | uVar26 * 0x400) ^ (uVar26 >> 0xd | uVar26 * 0x80000) ^
          (uVar26 >> 2 | uVar26 * 0x40000000)) + iVar1;
  uVar16 = (((uint)(ushort)(CONCAT11(in_EAX[0x30],in_EAX[0x31]) >> 2) | uVar17 << 0xe) ^
            (uVar17 >> 7 | uVar17 << 0x19) ^ uVar17 >> 3) +
           ((uVar14 >> 0x13 | uVar14 * 0x2000) ^ (uVar14 >> 0x11 | uVar14 * 0x8000) ^ uVar14 >> 10)
           + uVar9 + uVar16;
  iVar1 = ((uVar28 ^ uVar29) & uVar21 ^ uVar28) +
          ((uVar21 >> 0x19 | uVar21 * 0x80) ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^
          (uVar21 >> 6 | uVar21 * 0x4000000)) + uVar16 + -0x40a68039 + uVar4;
  uVar25 = uVar25 + iVar1;
  uVar27 = ((uVar26 | uVar5) & uVar23 | uVar26 & uVar5) +
           ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
           (uVar5 >> 2 | uVar5 * 0x40000000)) + iVar1;
  uVar17 = (((uint)(ushort)(CONCAT11(in_EAX[0x34],in_EAX[0x35]) >> 2) | uVar18 << 0xe) ^
            (uVar18 >> 7 | uVar18 << 0x19) ^ uVar18 >> 3) +
           ((uVar15 >> 0x13 | uVar15 * 0x2000) ^ (uVar15 >> 0x11 | uVar15 * 0x8000) ^ uVar15 >> 10)
           + uVar10 + uVar17;
  iVar1 = uVar28 + 0xc6e00bf3 +
          ((uVar29 ^ uVar21) & uVar25 ^ uVar29) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar17;
  uVar23 = uVar23 + iVar1;
  uVar28 = ((uVar5 | uVar27) & uVar26 | uVar5 & uVar27) +
           ((uVar27 >> 0x16 | uVar27 * 0x400) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
           (uVar27 >> 2 | uVar27 * 0x40000000)) + iVar1;
  uVar18 = (((uint)(uVar2 >> 2) | uVar19 << 0xe) ^ (uVar19 >> 7 | uVar19 << 0x19) ^ uVar19 >> 3) +
           ((uVar16 >> 0x13 | uVar16 * 0x2000) ^ (uVar16 >> 0x11 | uVar16 * 0x8000) ^ uVar16 >> 10)
           + uVar11 + uVar18;
  iVar1 = ((uVar21 ^ uVar25) & uVar23 ^ uVar21) +
          ((uVar23 >> 0x19 | uVar23 * 0x80) ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^
          (uVar23 >> 6 | uVar23 * 0x4000000)) + uVar18 + -0x2a586eb9 + uVar29;
  uVar26 = uVar26 + iVar1;
  uVar4 = ((uVar27 | uVar28) & uVar5 | uVar27 & uVar28) +
          ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
          (uVar28 >> 2 | uVar28 * 0x40000000)) + iVar1;
  uVar19 = (((uint)(uVar3 >> 2) | uVar20 << 0xe) ^ (uVar20 >> 7 | uVar20 << 0x19) ^ uVar20 >> 3) +
           ((uVar17 >> 0x13 | uVar17 * 0x2000) ^ (uVar17 >> 0x11 | uVar17 * 0x8000) ^ uVar17 >> 10)
           + uVar12 + uVar19;
  iVar1 = uVar21 + 0x6ca6351 +
          ((uVar23 ^ uVar25) & uVar26 ^ uVar25) +
          ((uVar26 >> 0x19 | uVar26 * 0x80) ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^
          (uVar26 >> 6 | uVar26 * 0x4000000)) + uVar19;
  uVar5 = uVar5 + iVar1;
  uVar29 = ((uVar28 | uVar4) & uVar27 | uVar28 & uVar4) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  uVar20 = ((uVar22 >> 0x12 | uVar22 * 0x4000) ^ (uVar22 >> 7 | uVar22 * 0x2000000) ^ uVar22 >> 3) +
           ((uVar18 >> 0x13 | uVar18 * 0x2000) ^ (uVar18 >> 0x11 | uVar18 * 0x8000) ^ uVar18 >> 10)
           + uVar13 + uVar20;
  iVar1 = uVar25 + 0x14292967 +
          ((uVar23 ^ uVar26) & uVar5 ^ uVar23) +
          ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
          (uVar5 >> 6 | uVar5 * 0x4000000)) + uVar20;
  uVar27 = uVar27 + iVar1;
  uVar21 = ((uVar4 | uVar29) & uVar28 | uVar4 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  uVar22 = ((uVar6 >> 0x12 | uVar6 * 0x4000) ^ (uVar6 >> 7 | uVar6 * 0x2000000) ^ uVar6 >> 3) +
           ((uVar19 >> 0x13 | uVar19 * 0x2000) ^ (uVar19 >> 0x11 | uVar19 * 0x8000) ^ uVar19 >> 10)
           + uVar14 + uVar22;
  iVar1 = uVar23 + 0x27b70a85 +
          ((uVar26 ^ uVar5) & uVar27 ^ uVar26) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar22;
  uVar28 = uVar28 + iVar1;
  uVar23 = ((uVar29 | uVar21) & uVar4 | uVar29 & uVar21) +
           ((uVar21 >> 0x16 | uVar21 * 0x400) ^ (uVar21 >> 0xd | uVar21 * 0x80000) ^
           (uVar21 >> 2 | uVar21 * 0x40000000)) + iVar1;
  uVar6 = ((uVar7 >> 0x12 | uVar7 * 0x4000) ^ (uVar7 >> 7 | uVar7 * 0x2000000) ^ uVar7 >> 3) +
          ((uVar20 >> 0x13 | uVar20 * 0x2000) ^ (uVar20 >> 0x11 | uVar20 * 0x8000) ^ uVar20 >> 10) +
          uVar15 + uVar6;
  iVar1 = ((uVar5 ^ uVar27) & uVar28 ^ uVar5) +
          ((uVar28 >> 0x19 | uVar28 * 0x80) ^ (uVar28 >> 0xb | uVar28 * 0x200000) ^
          (uVar28 >> 6 | uVar28 * 0x4000000)) + uVar6 + 0x2e1b2138 + uVar26;
  uVar4 = uVar4 + iVar1;
  uVar26 = ((uVar23 | uVar21) & uVar29 | uVar23 & uVar21) +
           ((uVar23 >> 0x16 | uVar23 * 0x400) ^ (uVar23 >> 0xd | uVar23 * 0x80000) ^
           (uVar23 >> 2 | uVar23 * 0x40000000)) + iVar1;
  uVar7 = ((uVar8 >> 0x12 | uVar8 * 0x4000) ^ (uVar8 >> 7 | uVar8 * 0x2000000) ^ uVar8 >> 3) +
          ((uVar22 >> 0x13 | uVar22 * 0x2000) ^ (uVar22 >> 0x11 | uVar22 * 0x8000) ^ uVar22 >> 10) +
          uVar16 + uVar7;
  iVar1 = ((uVar27 ^ uVar28) & uVar4 ^ uVar27) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar7 + 0x4d2c6dfc + uVar5;
  uVar29 = uVar29 + iVar1;
  uVar25 = ((uVar23 | uVar26) & uVar21 | uVar23 & uVar26) +
           ((uVar26 >> 0x16 | uVar26 * 0x400) ^ (uVar26 >> 0xd | uVar26 * 0x80000) ^
           (uVar26 >> 2 | uVar26 * 0x40000000)) + iVar1;
  uVar8 = ((uVar9 >> 0x12 | uVar9 * 0x4000) ^ (uVar9 >> 7 | uVar9 * 0x2000000) ^ uVar9 >> 3) +
          ((uVar6 >> 0x13 | uVar6 * 0x2000) ^ (uVar6 >> 0x11 | uVar6 * 0x8000) ^ uVar6 >> 10) +
          uVar17 + uVar8;
  iVar1 = uVar27 + 0x53380d13 +
          ((uVar28 ^ uVar4) & uVar29 ^ uVar28) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar8;
  uVar21 = uVar21 + iVar1;
  uVar27 = ((uVar26 | uVar25) & uVar23 | uVar26 & uVar25) +
           ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
           (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  uVar9 = ((uVar10 >> 0x12 | uVar10 * 0x4000) ^ (uVar10 >> 7 | uVar10 * 0x2000000) ^ uVar10 >> 3) +
          ((uVar7 >> 0x13 | uVar7 * 0x2000) ^ (uVar7 >> 0x11 | uVar7 * 0x8000) ^ uVar7 >> 10) +
          uVar18 + uVar9;
  iVar1 = ((uVar4 ^ uVar29) & uVar21 ^ uVar4) +
          ((uVar21 >> 0x19 | uVar21 * 0x80) ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^
          (uVar21 >> 6 | uVar21 * 0x4000000)) + uVar9 + 0x650a7354 + uVar28;
  uVar23 = uVar23 + iVar1;
  uVar5 = ((uVar25 | uVar27) & uVar26 | uVar25 & uVar27) +
          ((uVar27 >> 0x16 | uVar27 * 0x400) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
          (uVar27 >> 2 | uVar27 * 0x40000000)) + iVar1;
  uVar10 = ((uVar11 >> 0x12 | uVar11 * 0x4000) ^ (uVar11 >> 7 | uVar11 * 0x2000000) ^ uVar11 >> 3) +
           ((uVar8 >> 0x13 | uVar8 * 0x2000) ^ (uVar8 >> 0x11 | uVar8 * 0x8000) ^ uVar8 >> 10) +
           uVar19 + uVar10;
  iVar1 = uVar4 + 0x766a0abb +
          ((uVar29 ^ uVar21) & uVar23 ^ uVar29) +
          ((uVar23 >> 0x19 | uVar23 * 0x80) ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^
          (uVar23 >> 6 | uVar23 * 0x4000000)) + uVar10;
  uVar26 = uVar26 + iVar1;
  uVar28 = ((uVar27 | uVar5) & uVar25 | uVar27 & uVar5) +
           ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
           (uVar5 >> 2 | uVar5 * 0x40000000)) + iVar1;
  uVar11 = ((uVar12 >> 0x12 | uVar12 * 0x4000) ^ (uVar12 >> 7 | uVar12 * 0x2000000) ^ uVar12 >> 3) +
           ((uVar9 >> 0x13 | uVar9 * 0x2000) ^ (uVar9 >> 0x11 | uVar9 * 0x8000) ^ uVar9 >> 10) +
           uVar20 + uVar11;
  iVar1 = uVar29 + 0x81c2c92e +
          ((uVar23 ^ uVar21) & uVar26 ^ uVar21) +
          ((uVar26 >> 0x19 | uVar26 * 0x80) ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^
          (uVar26 >> 6 | uVar26 * 0x4000000)) + uVar11;
  uVar25 = uVar25 + iVar1;
  uVar4 = ((uVar5 | uVar28) & uVar27 | uVar5 & uVar28) +
          ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
          (uVar28 >> 2 | uVar28 * 0x40000000)) + iVar1;
  uVar12 = ((uVar13 >> 0x12 | uVar13 * 0x4000) ^ (uVar13 >> 7 | uVar13 * 0x2000000) ^ uVar13 >> 3) +
           ((uVar10 >> 0x13 | uVar10 * 0x2000) ^ (uVar10 >> 0x11 | uVar10 * 0x8000) ^ uVar10 >> 10)
           + uVar22 + uVar12;
  iVar1 = uVar21 + 0x92722c85 +
          ((uVar23 ^ uVar26) & uVar25 ^ uVar23) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar12;
  uVar27 = uVar27 + iVar1;
  uVar21 = ((uVar28 | uVar4) & uVar5 | uVar28 & uVar4) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  uVar13 = ((uVar14 >> 0x12 | uVar14 * 0x4000) ^ (uVar14 >> 7 | uVar14 * 0x2000000) ^ uVar14 >> 3) +
           ((uVar11 >> 0x13 | uVar11 * 0x2000) ^ (uVar11 >> 0x11 | uVar11 * 0x8000) ^ uVar11 >> 10)
           + uVar6 + uVar13;
  iVar1 = ((uVar26 ^ uVar25) & uVar27 ^ uVar26) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar13 + -0x5d40175f + uVar23;
  uVar5 = uVar5 + iVar1;
  uVar23 = ((uVar4 | uVar21) & uVar28 | uVar4 & uVar21) +
           ((uVar21 >> 0x16 | uVar21 * 0x400) ^ (uVar21 >> 0xd | uVar21 * 0x80000) ^
           (uVar21 >> 2 | uVar21 * 0x40000000)) + iVar1;
  uVar14 = ((uVar15 >> 0x12 | uVar15 * 0x4000) ^ (uVar15 >> 7 | uVar15 * 0x2000000) ^ uVar15 >> 3) +
           ((uVar12 >> 0x13 | uVar12 * 0x2000) ^ (uVar12 >> 0x11 | uVar12 * 0x8000) ^ uVar12 >> 10)
           + uVar7 + uVar14;
  iVar1 = ((uVar25 ^ uVar27) & uVar5 ^ uVar25) +
          ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
          (uVar5 >> 6 | uVar5 * 0x4000000)) + uVar14 + -0x57e599b5 + uVar26;
  uVar28 = uVar28 + iVar1;
  uVar29 = ((uVar23 | uVar21) & uVar4 | uVar23 & uVar21) +
           ((uVar23 >> 0x16 | uVar23 * 0x400) ^ (uVar23 >> 0xd | uVar23 * 0x80000) ^
           (uVar23 >> 2 | uVar23 * 0x40000000)) + iVar1;
  uVar15 = ((uVar16 >> 0x12 | uVar16 * 0x4000) ^ (uVar16 >> 7 | uVar16 * 0x2000000) ^ uVar16 >> 3) +
           ((uVar13 >> 0x13 | uVar13 * 0x2000) ^ (uVar13 >> 0x11 | uVar13 * 0x8000) ^ uVar13 >> 10)
           + uVar8 + uVar15;
  iVar1 = uVar25 + 0xc24b8b70 +
          ((uVar27 ^ uVar5) & uVar28 ^ uVar27) +
          ((uVar28 >> 0x19 | uVar28 * 0x80) ^ (uVar28 >> 0xb | uVar28 * 0x200000) ^
          (uVar28 >> 6 | uVar28 * 0x4000000)) + uVar15;
  uVar4 = uVar4 + iVar1;
  uVar25 = ((uVar23 | uVar29) & uVar21 | uVar23 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  uVar16 = ((uVar17 >> 0x12 | uVar17 * 0x4000) ^ (uVar17 >> 7 | uVar17 * 0x2000000) ^ uVar17 >> 3) +
           ((uVar14 >> 0x13 | uVar14 * 0x2000) ^ (uVar14 >> 0x11 | uVar14 * 0x8000) ^ uVar14 >> 10)
           + uVar9 + uVar16;
  iVar1 = ((uVar5 ^ uVar28) & uVar4 ^ uVar5) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar16 + -0x3893ae5d + uVar27;
  uVar21 = uVar21 + iVar1;
  uVar26 = ((uVar29 | uVar25) & uVar23 | uVar29 & uVar25) +
           ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
           (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  uVar17 = ((uVar18 >> 0x12 | uVar18 * 0x4000) ^ (uVar18 >> 7 | uVar18 * 0x2000000) ^ uVar18 >> 3) +
           ((uVar15 >> 0x13 | uVar15 * 0x2000) ^ (uVar15 >> 0x11 | uVar15 * 0x8000) ^ uVar15 >> 10)
           + uVar10 + uVar17;
  iVar1 = uVar5 + 0xd192e819 +
          ((uVar28 ^ uVar4) & uVar21 ^ uVar28) +
          ((uVar21 >> 0x19 | uVar21 * 0x80) ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^
          (uVar21 >> 6 | uVar21 * 0x4000000)) + uVar17;
  uVar23 = uVar23 + iVar1;
  uVar27 = ((uVar25 | uVar26) & uVar29 | uVar25 & uVar26) +
           ((uVar26 >> 0x16 | uVar26 * 0x400) ^ (uVar26 >> 0xd | uVar26 * 0x80000) ^
           (uVar26 >> 2 | uVar26 * 0x40000000)) + iVar1;
  uVar18 = ((uVar19 >> 0x12 | uVar19 * 0x4000) ^ (uVar19 >> 7 | uVar19 * 0x2000000) ^ uVar19 >> 3) +
           ((uVar16 >> 0x13 | uVar16 * 0x2000) ^ (uVar16 >> 0x11 | uVar16 * 0x8000) ^ uVar16 >> 10)
           + uVar11 + uVar18;
  iVar1 = uVar28 + 0xd6990624 +
          ((uVar4 ^ uVar21) & uVar23 ^ uVar4) +
          ((uVar23 >> 0x19 | uVar23 * 0x80) ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^
          (uVar23 >> 6 | uVar23 * 0x4000000)) + uVar18;
  uVar29 = uVar29 + iVar1;
  uVar5 = ((uVar26 | uVar27) & uVar25 | uVar26 & uVar27) +
          ((uVar27 >> 0x16 | uVar27 * 0x400) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
          (uVar27 >> 2 | uVar27 * 0x40000000)) + iVar1;
  uVar19 = ((uVar20 >> 0x12 | uVar20 * 0x4000) ^ (uVar20 >> 7 | uVar20 * 0x2000000) ^ uVar20 >> 3) +
           ((uVar17 >> 0x13 | uVar17 * 0x2000) ^ (uVar17 >> 0x11 | uVar17 * 0x8000) ^ uVar17 >> 10)
           + uVar12 + uVar19;
  iVar1 = uVar4 + 0xf40e3585 +
          ((uVar23 ^ uVar21) & uVar29 ^ uVar21) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar19;
  uVar25 = uVar25 + iVar1;
  uVar4 = ((uVar27 | uVar5) & uVar26 | uVar27 & uVar5) +
          ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
          (uVar5 >> 2 | uVar5 * 0x40000000)) + iVar1;
  uVar20 = ((uVar22 >> 0x12 | uVar22 * 0x4000) ^ (uVar22 >> 7 | uVar22 * 0x2000000) ^ uVar22 >> 3) +
           ((uVar18 >> 0x13 | uVar18 * 0x2000) ^ (uVar18 >> 0x11 | uVar18 * 0x8000) ^ uVar18 >> 10)
           + uVar13 + uVar20;
  iVar1 = ((uVar23 ^ uVar29) & uVar25 ^ uVar23) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar20 + 0x106aa070 + uVar21;
  uVar26 = uVar26 + iVar1;
  uVar21 = ((uVar5 | uVar4) & uVar27 | uVar5 & uVar4) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  uVar22 = ((uVar6 >> 0x12 | uVar6 * 0x4000) ^ (uVar6 >> 7 | uVar6 * 0x2000000) ^ uVar6 >> 3) +
           ((uVar19 >> 0x13 | uVar19 * 0x2000) ^ (uVar19 >> 0x11 | uVar19 * 0x8000) ^ uVar19 >> 10)
           + uVar14 + uVar22;
  iVar1 = ((uVar29 ^ uVar25) & uVar26 ^ uVar29) +
          ((uVar26 >> 0x19 | uVar26 * 0x80) ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^
          (uVar26 >> 6 | uVar26 * 0x4000000)) + uVar22 + 0x19a4c116 + uVar23;
  uVar27 = uVar27 + iVar1;
  uVar28 = ((uVar4 | uVar21) & uVar5 | uVar4 & uVar21) +
           ((uVar21 >> 0x16 | uVar21 * 0x400) ^ (uVar21 >> 0xd | uVar21 * 0x80000) ^
           (uVar21 >> 2 | uVar21 * 0x40000000)) + iVar1;
  uVar6 = ((uVar7 >> 0x12 | uVar7 * 0x4000) ^ (uVar7 >> 7 | uVar7 * 0x2000000) ^ uVar7 >> 3) +
          ((uVar20 >> 0x13 | uVar20 * 0x2000) ^ (uVar20 >> 0x11 | uVar20 * 0x8000) ^ uVar20 >> 10) +
          uVar15 + uVar6;
  iVar1 = uVar29 + 0x1e376c08 +
          ((uVar25 ^ uVar26) & uVar27 ^ uVar25) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar6;
  uVar5 = uVar5 + iVar1;
  uVar29 = ((uVar28 | uVar21) & uVar4 | uVar28 & uVar21) +
           ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
           (uVar28 >> 2 | uVar28 * 0x40000000)) + iVar1;
  uVar7 = ((uVar8 >> 0x12 | uVar8 * 0x4000) ^ (uVar8 >> 7 | uVar8 * 0x2000000) ^ uVar8 >> 3) +
          ((uVar22 >> 0x13 | uVar22 * 0x2000) ^ (uVar22 >> 0x11 | uVar22 * 0x8000) ^ uVar22 >> 10) +
          uVar16 + uVar7;
  iVar1 = ((uVar26 ^ uVar27) & uVar5 ^ uVar26) +
          ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
          (uVar5 >> 6 | uVar5 * 0x4000000)) + uVar7 + 0x2748774c + uVar25;
  uVar4 = uVar4 + iVar1;
  uVar23 = ((uVar28 | uVar29) & uVar21 | uVar28 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  uVar8 = ((uVar9 >> 0x12 | uVar9 * 0x4000) ^ (uVar9 >> 7 | uVar9 * 0x2000000) ^ uVar9 >> 3) +
          ((uVar6 >> 0x13 | uVar6 * 0x2000) ^ (uVar6 >> 0x11 | uVar6 * 0x8000) ^ uVar6 >> 10) +
          uVar17 + uVar8;
  iVar1 = uVar26 + 0x34b0bcb5 +
          ((uVar27 ^ uVar5) & uVar4 ^ uVar27) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar8;
  uVar21 = uVar21 + iVar1;
  uVar25 = ((uVar29 | uVar23) & uVar28 | uVar29 & uVar23) +
           ((uVar23 >> 0x16 | uVar23 * 0x400) ^ (uVar23 >> 0xd | uVar23 * 0x80000) ^
           (uVar23 >> 2 | uVar23 * 0x40000000)) + iVar1;
  uVar9 = ((uVar7 >> 0x13 | uVar7 * 0x2000) ^ (uVar7 >> 0x11 | uVar7 * 0x8000) ^ uVar7 >> 10) +
          ((uVar10 >> 0x12 | uVar10 * 0x4000) ^ (uVar10 >> 7 | uVar10 * 0x2000000) ^ uVar10 >> 3) +
          uVar18 + uVar9;
  iVar1 = uVar27 + 0x391c0cb3 +
          ((uVar5 ^ uVar4) & uVar21 ^ uVar5) +
          ((uVar21 >> 0x19 | uVar21 * 0x80) ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^
          (uVar21 >> 6 | uVar21 * 0x4000000)) + uVar9;
  uVar28 = uVar28 + iVar1;
  uVar26 = ((uVar23 | uVar25) & uVar29 | uVar23 & uVar25) +
           ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
           (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  uVar10 = ((uVar8 >> 0x13 | uVar8 * 0x2000) ^ (uVar8 >> 0x11 | uVar8 * 0x8000) ^ uVar8 >> 10) +
           ((uVar11 >> 0x12 | uVar11 * 0x4000) ^ (uVar11 >> 7 | uVar11 * 0x2000000) ^ uVar11 >> 3) +
           uVar19 + uVar10;
  iVar1 = uVar5 + 0x4ed8aa4a +
          ((uVar4 ^ uVar21) & uVar28 ^ uVar4) +
          ((uVar28 >> 0x19 | uVar28 * 0x80) ^ (uVar28 >> 0xb | uVar28 * 0x200000) ^
          (uVar28 >> 6 | uVar28 * 0x4000000)) + uVar10;
  uVar29 = uVar29 + iVar1;
  uVar5 = ((uVar25 | uVar26) & uVar23 | uVar25 & uVar26) +
          ((uVar26 >> 0x16 | uVar26 * 0x400) ^ (uVar26 >> 0xd | uVar26 * 0x80000) ^
          (uVar26 >> 2 | uVar26 * 0x40000000)) + iVar1;
  uVar11 = ((uVar9 >> 0x13 | uVar9 * 0x2000) ^ (uVar9 >> 0x11 | uVar9 * 0x8000) ^ uVar9 >> 10) +
           ((uVar12 >> 0x12 | uVar12 * 0x4000) ^ (uVar12 >> 7 | uVar12 * 0x2000000) ^ uVar12 >> 3) +
           uVar20 + uVar11;
  iVar1 = uVar4 + 0x5b9cca4f +
          ((uVar28 ^ uVar21) & uVar29 ^ uVar21) +
          ((uVar29 >> 0x19 | uVar29 * 0x80) ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^
          (uVar29 >> 6 | uVar29 * 0x4000000)) + uVar11;
  uVar23 = uVar23 + iVar1;
  uVar4 = ((uVar26 | uVar5) & uVar25 | uVar26 & uVar5) +
          ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
          (uVar5 >> 2 | uVar5 * 0x40000000)) + iVar1;
  uVar12 = ((uVar10 >> 0x13 | uVar10 * 0x2000) ^ (uVar10 >> 0x11 | uVar10 * 0x8000) ^ uVar10 >> 10)
           + ((uVar13 >> 0x12 | uVar13 * 0x4000) ^ (uVar13 >> 7 | uVar13 * 0x2000000) ^ uVar13 >> 3)
             + uVar22 + uVar12;
  iVar1 = ((uVar28 ^ uVar29) & uVar23 ^ uVar28) +
          ((uVar23 >> 0x19 | uVar23 * 0x80) ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^
          (uVar23 >> 6 | uVar23 * 0x4000000)) + uVar12 + 0x682e6ff3 + uVar21;
  uVar25 = uVar25 + iVar1;
  uVar27 = ((uVar5 | uVar4) & uVar26 | uVar5 & uVar4) +
           ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar1;
  uVar13 = ((uVar11 >> 0x13 | uVar11 * 0x2000) ^ (uVar11 >> 0x11 | uVar11 * 0x8000) ^ uVar11 >> 10)
           + ((uVar14 >> 0x12 | uVar14 * 0x4000) ^ (uVar14 >> 7 | uVar14 * 0x2000000) ^ uVar14 >> 3)
             + uVar6 + uVar13;
  iVar1 = uVar28 + 0x748f82ee +
          ((uVar29 ^ uVar23) & uVar25 ^ uVar29) +
          ((uVar25 >> 0x19 | uVar25 * 0x80) ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^
          (uVar25 >> 6 | uVar25 * 0x4000000)) + uVar13;
  uVar26 = uVar26 + iVar1;
  uVar6 = ((uVar4 | uVar27) & uVar5 | uVar4 & uVar27) +
          ((uVar27 >> 0x16 | uVar27 * 0x400) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
          (uVar27 >> 2 | uVar27 * 0x40000000)) + iVar1;
  uVar14 = ((uVar12 >> 0x13 | uVar12 * 0x2000) ^ (uVar12 >> 0x11 | uVar12 * 0x8000) ^ uVar12 >> 10)
           + ((uVar15 >> 0x12 | uVar15 * 0x4000) ^ (uVar15 >> 7 | uVar15 * 0x2000000) ^ uVar15 >> 3)
             + uVar7 + uVar14;
  iVar1 = ((uVar23 ^ uVar25) & uVar26 ^ uVar23) +
          ((uVar26 >> 0x19 | uVar26 * 0x80) ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^
          (uVar26 >> 6 | uVar26 * 0x4000000)) + uVar14 + 0x78a5636f + uVar29;
  uVar5 = uVar5 + iVar1;
  uVar7 = ((uVar6 | uVar27) & uVar4 | uVar6 & uVar27) +
          ((uVar6 >> 0x16 | uVar6 * 0x400) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
          (uVar6 >> 2 | uVar6 * 0x40000000)) + iVar1;
  uVar15 = ((uVar13 >> 0x13 | uVar13 * 0x2000) ^ (uVar13 >> 0x11 | uVar13 * 0x8000) ^ uVar13 >> 10)
           + ((uVar16 >> 0x12 | uVar16 * 0x4000) ^ (uVar16 >> 7 | uVar16 * 0x2000000) ^ uVar16 >> 3)
             + uVar8 + uVar15;
  iVar1 = uVar23 + 0x84c87814 +
          ((uVar25 ^ uVar26) & uVar5 ^ uVar25) +
          ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
          (uVar5 >> 6 | uVar5 * 0x4000000)) + uVar15;
  uVar4 = uVar4 + iVar1;
  uVar8 = ((uVar6 | uVar7) & uVar27 | uVar6 & uVar7) +
          ((uVar7 >> 0x16 | uVar7 * 0x400) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
          (uVar7 >> 2 | uVar7 * 0x40000000)) + iVar1;
  uVar16 = ((uVar14 >> 0x13 | uVar14 * 0x2000) ^ (uVar14 >> 0x11 | uVar14 * 0x8000) ^ uVar14 >> 10)
           + ((uVar17 >> 0x12 | uVar17 * 0x4000) ^ (uVar17 >> 7 | uVar17 * 0x2000000) ^ uVar17 >> 3)
             + uVar9 + uVar16;
  iVar1 = uVar25 + 0x8cc70208 +
          ((uVar26 ^ uVar5) & uVar4 ^ uVar26) +
          ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
          (uVar4 >> 6 | uVar4 * 0x4000000)) + uVar16;
  uVar27 = uVar27 + iVar1;
  uVar25 = ((uVar7 | uVar8) & uVar6 | uVar7 & uVar8) +
           ((uVar8 >> 0x16 | uVar8 * 0x400) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
           (uVar8 >> 2 | uVar8 * 0x40000000)) + iVar1;
  uVar17 = ((uVar15 >> 0x13 | uVar15 * 0x2000) ^ (uVar15 >> 0x11 | uVar15 * 0x8000) ^ uVar15 >> 10)
           + ((uVar18 >> 0x12 | uVar18 * 0x4000) ^ (uVar18 >> 7 | uVar18 * 0x2000000) ^ uVar18 >> 3)
             + uVar10 + uVar17;
  iVar1 = uVar26 + 0x90befffa +
          ((uVar5 ^ uVar4) & uVar27 ^ uVar5) +
          ((uVar27 >> 0x19 | uVar27 * 0x80) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
          (uVar27 >> 6 | uVar27 * 0x4000000)) + uVar17;
  uVar6 = uVar6 + iVar1;
  uVar9 = ((uVar8 | uVar25) & uVar7 | uVar8 & uVar25) +
          ((uVar25 >> 0x16 | uVar25 * 0x400) ^ (uVar25 >> 0xd | uVar25 * 0x80000) ^
          (uVar25 >> 2 | uVar25 * 0x40000000)) + iVar1;
  uVar18 = ((uVar16 >> 0x13 | uVar16 * 0x2000) ^ (uVar16 >> 0x11 | uVar16 * 0x8000) ^ uVar16 >> 10)
           + ((uVar19 >> 0x12 | uVar19 * 0x4000) ^ (uVar19 >> 7 | uVar19 * 0x2000000) ^ uVar19 >> 3)
             + uVar11 + uVar18;
  iVar1 = ((uVar4 ^ uVar27) & uVar6 ^ uVar4) +
          ((uVar6 >> 0x19 | uVar6 * 0x80) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
          (uVar6 >> 6 | uVar6 * 0x4000000)) + uVar18 + -0x5baf9315 + uVar5;
  uVar7 = uVar7 + iVar1;
  uVar29 = ((uVar25 | uVar9) & uVar8 | uVar25 & uVar9) +
           ((uVar9 >> 0x16 | uVar9 * 0x400) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
           (uVar9 >> 2 | uVar9 * 0x40000000)) + iVar1;
  iVar1 = uVar4 + 0xbef9a3f7 +
          ((uVar6 ^ uVar27) & uVar7 ^ uVar27) +
          ((uVar7 >> 0x19 | uVar7 * 0x80) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
          (uVar7 >> 6 | uVar7 * 0x4000000)) +
          ((uVar17 >> 0x13 | uVar17 * 0x2000) ^ (uVar17 >> 0x11 | uVar17 * 0x8000) ^ uVar17 >> 10) +
          ((uVar20 >> 0x12 | uVar20 * 0x4000) ^ (uVar20 >> 7 | uVar20 * 0x2000000) ^ uVar20 >> 3) +
          uVar12 + uVar19;
  uVar8 = uVar8 + iVar1;
  uVar28 = ((uVar9 | uVar29) & uVar25 | uVar9 & uVar29) +
           ((uVar29 >> 0x16 | uVar29 * 0x400) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^
           (uVar29 >> 2 | uVar29 * 0x40000000)) + iVar1;
  iVar1 = ((uVar6 ^ uVar7) & uVar8 ^ uVar6) +
          ((uVar18 >> 0x13 | uVar18 * 0x2000) ^ (uVar18 >> 0x11 | uVar18 * 0x8000) ^ uVar18 >> 10) +
          uVar13 + ((uVar8 >> 0x19 | uVar8 * 0x80) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
                   (uVar8 >> 6 | uVar8 * 0x4000000)) +
                   ((uVar22 >> 0x12 | uVar22 * 0x4000) ^ (uVar22 >> 7 | uVar22 * 0x2000000) ^
                   uVar22 >> 3) + uVar20 + -0x398e870e + uVar27;
  *(uint *)(param_1 + 8) =
       ((uVar29 | uVar28) & uVar9 | uVar29 & uVar28) +
       ((uVar28 >> 0x16 | uVar28 * 0x400) ^ (uVar28 >> 0xd | uVar28 * 0x80000) ^
       (uVar28 >> 2 | uVar28 * 0x40000000)) + *(int *)(param_1 + 8) + iVar1;
  *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar28;
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar29;
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar9;
  *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar1 + uVar25;
  *(uint *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + uVar8;
  *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar7;
  *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + uVar6;
  return;
}

