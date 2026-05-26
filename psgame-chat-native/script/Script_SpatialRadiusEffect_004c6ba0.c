/*
 * server/ps_game.exe — Script_SpatialRadiusEffect
 * Requested VA: 0x004C6BA0
 * Entry Ghidra:  004c6ba0
 * Ghidra name:   FUN_004c6ba0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004c6ba0(float param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int unaff_EBX;
  int iVar9;
  int iVar10;
  float10 fVar11;
  int local_2c;
  int local_28;
  int local_24;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  iVar9 = *(int *)(unaff_EBX + 0x8c);
  if ((iVar9 != 0) && (0 < *(int *)(iVar9 + 0x1a4))) {
    iVar6 = FUN_005250c0();
    local_28 = *(int *)(unaff_EBX + 0x90) + iVar6;
    local_24 = *(int *)(unaff_EBX + 0x90) - iVar6;
    iVar10 = *(int *)(unaff_EBX + 0x94) - iVar6;
    iVar6 = iVar6 + *(int *)(unaff_EBX + 0x94);
    if (local_24 < 0) {
      local_24 = 0;
    }
    if (*(int *)(iVar9 + 0x2c) <= local_28) {
      local_28 = *(int *)(iVar9 + 0x2c) + -1;
    }
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    if (*(int *)(iVar9 + 0x30) <= iVar6) {
      iVar6 = *(int *)(iVar9 + 0x30) + -1;
    }
    for (; iVar10 <= iVar6; iVar10 = iVar10 + 1) {
      if (local_24 <= local_28) {
        iVar9 = local_24 * 0x124;
        local_2c = local_24;
        do {
          EnterCriticalSection
                    ((LPCRITICAL_SECTION)
                     (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4) + 0x34 +
                     iVar9));
          iVar1 = *(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4);
          iVar2 = *(int *)(iVar1 + 0x2c + iVar9);
          iVar8 = *(int *)(iVar2 + 0x78);
          if (iVar8 == 0) {
            iVar8 = 0;
          }
          else {
            iVar8 = iVar8 + -0x74;
          }
          *(int *)(iVar1 + iVar9 + 0x30) = iVar8;
          if (iVar8 != iVar2) {
            do {
              if (iVar8 == 0) break;
              FUN_004bb660();
              if ((*(int *)(iVar8 + 0x88) != *(int *)(unaff_EBX + 0x88)) &&
                 (fVar3 = fStack_18 - *(float *)(unaff_EBX + 0x7c),
                 fVar4 = fStack_14 - *(float *)(unaff_EBX + 0x80),
                 fVar5 = fStack_10 - *(float *)(unaff_EBX + 0x84),
                 fVar11 = (float10)FUN_0041b8a0(fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4),
                 fVar11 < (float10)param_1)) {
                if (*(char *)(iVar8 + 0x2d4) == '\0') {
                  if (*(int *)(iVar8 + 0x70) == 0) {
                    iVar8 = *(int *)(iVar8 + 0x1a8);
                  }
                  else if (*(int *)(iVar8 + 0x6c) == 0) {
                    iVar8 = 0;
                  }
                  else {
                    piVar7 = (int *)FUN_00425af0();
                    iVar8 = *(int *)(*piVar7 + 0x48);
                  }
                  if (iVar8 == 0) {
                    *(float *)(unaff_EBX + 0xd2c) = fStack_18;
                    *(float *)(unaff_EBX + 0xd30) = fStack_14;
                    *(float *)(unaff_EBX + 0xd34) = fStack_10;
                    /* WARNING: Could not recover jumptable at 0x004c6ea2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    LeaveCriticalSection
                              ((LPCRITICAL_SECTION)
                               (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4) +
                                0x34 + local_2c * 0x124));
                    return;
                  }
                }
                else if (*(char *)(iVar8 + 0x2d6) == '\0') {
                  *(float *)(unaff_EBX + 0xd2c) = fStack_18;
                  *(float *)(unaff_EBX + 0xd30) = fStack_14;
                  *(float *)(unaff_EBX + 0xd34) = fStack_10;
                    /* WARNING: Could not recover jumptable at 0x004c6d7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LeaveCriticalSection
                            ((LPCRITICAL_SECTION)
                             (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4) +
                              0x34 + local_2c * 0x124));
                  return;
                }
              }
              iVar1 = *(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4);
              iVar8 = *(int *)(*(int *)(iVar1 + 0x30 + iVar9) + 0x78);
              piVar7 = (int *)(iVar1 + 0x2c + iVar9);
              if (iVar8 == 0) {
                iVar8 = 0;
              }
              else {
                iVar8 = iVar8 + -0x74;
              }
              piVar7[1] = iVar8;
            } while (iVar8 != *piVar7);
          }
          LeaveCriticalSection
                    ((LPCRITICAL_SECTION)
                     (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4) + 0x34 +
                     iVar9));
          local_2c = local_2c + 1;
          iVar9 = iVar9 + 0x124;
        } while (local_2c <= local_28);
      }
    }
    *(undefined4 *)(unaff_EBX + 0xd2c) = *(undefined4 *)(unaff_EBX + 0x7c);
    *(undefined4 *)(unaff_EBX + 0xd30) = *(undefined4 *)(unaff_EBX + 0x80);
    *(undefined4 *)(unaff_EBX + 0xd34) = *(undefined4 *)(unaff_EBX + 0x84);
  }
  return;
}

