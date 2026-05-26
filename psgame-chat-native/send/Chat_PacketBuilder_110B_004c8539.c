/*
 * server/ps_game.exe — Chat_PacketBuilder_110B
 * Requested VA: 0x004C8539
 * Entry Ghidra:  004c8520
 * Ghidra name:   FUN_004c8520
 * NOTE: VA is inside the function (landmark/hook), not the entry point.
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: send
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004c8520(char *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int unaff_ESI;
  float10 fVar9;
  int local_44;
  int local_40;
  int local_3c;
  float fStack_38;
  int local_34;
  float fStack_30;
  undefined2 local_2c;
  undefined4 local_2a;
  char local_26 [31];
  undefined local_7;
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_44;
  local_2a = *(undefined4 *)(unaff_ESI + 0x88);
  local_2c = 0x110b;
  _strncpy(local_26,param_1,0x20);
  local_7 = 0;
  iVar4 = FUN_005250c0();
  local_44 = iVar4;
  iVar5 = FUN_005250c0();
  local_40 = iVar5;
  iVar6 = FUN_005250c0();
  iVar7 = FUN_005250c0();
  if (iVar4 < 0) {
    local_44 = 0;
    iVar4 = 0;
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x8c) + 0x2c);
  if (iVar1 <= iVar5) {
    iVar5 = iVar1 + -1;
    local_40 = iVar5;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x8c) + 0x30);
  if (iVar1 <= iVar7) {
    iVar7 = iVar1 + -1;
  }
  local_3c = iVar7;
  if (iVar6 <= iVar7) {
    do {
      if (iVar4 <= iVar5) {
        iVar4 = iVar4 * 0x124;
        iVar7 = (iVar5 - local_44) + 1;
        do {
          local_34 = iVar7;
          EnterCriticalSection
                    ((LPCRITICAL_SECTION)
                     (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar6 * 4) + 8 + iVar4)
                    );
          iVar1 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar6 * 4);
          iVar2 = *(int *)(iVar1 + iVar4);
          iVar5 = *(int *)(iVar2 + 0xc);
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = iVar5 + -8;
          }
          *(int *)(iVar1 + iVar4 + 4) = iVar5;
          if (iVar5 != iVar2) {
            do {
              iVar7 = local_34;
              if (iVar5 == 0) break;
              fVar3 = *(float *)(iVar5 + 0xd0) - *(float *)(unaff_ESI + 0x7c);
              fStack_30 = *(float *)(iVar5 + 0xd8) - *(float *)(unaff_ESI + 0x84);
              fStack_38 = fVar3 * fVar3 + fStack_30 * fStack_30;
              fVar9 = (float10)FUN_0041b8a0(fStack_38);
              if (fVar9 <= (float10)param_2) {
                FUN_004ed0e0(&local_2c,0x26);
              }
              iVar7 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar6 * 4);
              iVar5 = *(int *)(*(int *)(iVar7 + 4 + iVar4) + 0xc);
              piVar8 = (int *)(iVar7 + iVar4);
              if (iVar5 == 0) {
                iVar5 = 0;
              }
              else {
                iVar5 = iVar5 + -8;
              }
              piVar8[1] = iVar5;
              iVar7 = local_34;
            } while (iVar5 != *piVar8);
          }
          LeaveCriticalSection
                    ((LPCRITICAL_SECTION)
                     (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar6 * 4) + 8 + iVar4)
                    );
          iVar4 = iVar4 + 0x124;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        local_34 = 0;
        iVar7 = local_3c;
        iVar5 = local_40;
        iVar4 = local_44;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= iVar7);
  }
  ___security_check_cookie_4();
  return;
}

