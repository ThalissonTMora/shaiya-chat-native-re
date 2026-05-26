/*
 * server/ps_game.exe — Script_SpatialEntityPush
 * Requested VA: 0x004C5D90
 * Entry Ghidra:  004c5d90
 * Ghidra name:   FUN_004c5d90
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: script
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004c5d90(int param_1,int param_2,float param_3)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  int local_2c;
  int local_28;
  int local_24;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar6 = param_1;
  if ((param_2 != 0) && (iVar7 = *(int *)(param_1 + 0x8c), 0 < *(int *)(iVar7 + 0x1a4))) {
    local_28 = FUN_005250c0();
    local_2c = *(int *)(param_1 + 0x90) + local_28;
    piVar1 = (int *)(param_1 + 0x94);
    param_1 = *(int *)(param_1 + 0x90) - local_28;
    iVar10 = *piVar1 - local_28;
    local_28 = local_28 + *piVar1;
    if (param_1 < 0) {
      param_1 = 0;
    }
    if (*(int *)(iVar7 + 0x2c) <= local_2c) {
      local_2c = *(int *)(iVar7 + 0x2c) + -1;
    }
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    if (*(int *)(iVar7 + 0x30) <= local_28) {
      local_28 = *(int *)(iVar7 + 0x30) + -1;
    }
    iVar7 = FUN_00415480(&param_2);
    if (iVar7 != 0) {
      for (; iVar10 <= local_28; iVar10 = iVar10 + 1) {
        if (param_1 <= local_2c) {
          iVar9 = param_1 * 0x124;
          local_24 = (local_2c - param_1) + 1;
          param_2 = iVar10;
          do {
            EnterCriticalSection
                      ((LPCRITICAL_SECTION)
                       (*(int *)(*(int *)(*(int *)(iVar6 + 0x8c) + 0x34) + iVar10 * 4) + 0x34 +
                       iVar9));
            piVar1 = (int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x8c) + 0x34) + iVar10 * 4) + 0x2c +
                            iVar9);
            iVar2 = *piVar1;
            iVar8 = *(int *)(iVar2 + 0x78);
            if (iVar8 == 0) {
              iVar8 = 0;
            }
            else {
              iVar8 = iVar8 + -0x74;
            }
            piVar1[1] = iVar8;
            if (iVar8 != iVar2) {
              do {
                if (iVar8 == 0) break;
                FUN_004bb660();
                if ((*(int *)(iVar8 + 0x88) != *(int *)(iVar6 + 0x88)) &&
                   (fVar3 = fStack_c - *(float *)(iVar6 + 0x7c),
                   fVar4 = fStack_8 - *(float *)(iVar6 + 0x80),
                   fVar5 = fStack_4 - *(float *)(iVar6 + 0x84),
                   fVar11 = (float10)FUN_0041b8a0(fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3),
                   fVar11 <= (float10)param_3)) {
                  FUN_004b4010(iVar7,1);
                  FUN_004a0db0();
                }
                iVar10 = *(int *)(*(int *)(*(int *)(iVar6 + 0x8c) + 0x34) + param_2 * 4);
                iVar8 = *(int *)(*(int *)(iVar10 + 0x30 + iVar9) + 0x78);
                piVar1 = (int *)(iVar10 + 0x2c + iVar9);
                if (iVar8 == 0) {
                  iVar8 = 0;
                }
                else {
                  iVar8 = iVar8 + -0x74;
                }
                piVar1[1] = iVar8;
                iVar10 = param_2;
              } while (iVar8 != *piVar1);
            }
            LeaveCriticalSection
                      ((LPCRITICAL_SECTION)
                       (*(int *)(*(int *)(*(int *)(iVar6 + 0x8c) + 0x34) + iVar10 * 4) + 0x34 +
                       iVar9));
            iVar9 = iVar9 + 0x124;
            local_24 = local_24 + -1;
          } while (local_24 != 0);
        }
      }
    }
  }
  return;
}

