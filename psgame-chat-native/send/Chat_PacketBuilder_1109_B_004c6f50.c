/*
 * server/ps_game.exe — Chat_PacketBuilder_1109_B
 * Requested VA: 0x004C6F50
 * Entry Ghidra:  004c6f50
 * Ghidra name:   FUN_004c6f50
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: send
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004c6f50(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int unaff_EBX;
  int iVar10;
  float10 fVar11;
  undefined auStack_c0 [4];
  int local_bc;
  int local_b8;
  int local_b4;
  float fStack_b0;
  int local_ac;
  float local_a8;
  int local_a4;
  int local_a0;
  float fStack_9c;
  undefined2 local_98;
  undefined local_96;
  undefined4 local_95;
  undefined local_91;
  char local_90 [132];
  uint local_c;
  
  local_c = DAT_0057f7c4 ^ (uint)auStack_c0;
  iVar5 = FUN_004c6970(param_1);
  if ((((iVar5 != 0) && (pcVar6 = (char *)(iVar5 + 4), pcVar6 != (char *)0x0)) &&
      (iVar9 = *(int *)(unaff_EBX + 0x8c), iVar9 != 0)) && (0 < *(int *)(iVar9 + 0x1a4))) {
    pcVar8 = pcVar6;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    local_a0 = (int)pcVar8 - (iVar5 + 5);
    if (local_a0 - 1U < 0x7f) {
      local_95 = *(undefined4 *)(unaff_EBX + 0x88);
      local_98 = 0x1109;
      local_96 = 1;
      local_91 = (undefined)local_a0;
      iVar5 = -(int)pcVar6;
      do {
        cVar1 = *pcVar6;
        pcVar6[(int)(local_90 + iVar5)] = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      local_a8 = (float)param_2;
      iVar5 = FUN_005250c0();
      local_bc = *(int *)(unaff_EBX + 0x90) + iVar5;
      local_ac = *(int *)(unaff_EBX + 0x90) - iVar5;
      iVar10 = *(int *)(unaff_EBX + 0x94) - iVar5;
      iVar5 = iVar5 + *(int *)(unaff_EBX + 0x94);
      if (local_ac < 0) {
        local_ac = 0;
      }
      if (*(int *)(iVar9 + 0x2c) <= local_bc) {
        local_bc = *(int *)(iVar9 + 0x2c) + -1;
      }
      if (iVar10 < 0) {
        iVar10 = 0;
      }
      if (*(int *)(iVar9 + 0x30) <= iVar5) {
        iVar5 = *(int *)(iVar9 + 0x30) + -1;
      }
      iVar9 = local_ac;
      local_b8 = iVar5;
      local_b4 = iVar10;
      if (iVar10 <= iVar5) {
        do {
          if (iVar9 <= local_bc) {
            iVar5 = iVar9 * 0x124;
            local_a4 = (local_bc - iVar9) + 1;
            local_b4 = iVar10;
            do {
              EnterCriticalSection
                        ((LPCRITICAL_SECTION)
                         (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4) + 8 +
                         iVar5));
              iVar2 = *(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4);
              iVar3 = *(int *)(iVar2 + iVar5);
              iVar9 = *(int *)(iVar3 + 0xc);
              if (iVar9 == 0) {
                iVar9 = 0;
              }
              else {
                iVar9 = iVar9 + -8;
              }
              *(int *)(iVar2 + iVar5 + 4) = iVar9;
              if (iVar9 != iVar3) {
                do {
                  iVar10 = local_b4;
                  if (iVar9 == 0) break;
                  fVar4 = *(float *)(iVar9 + 0xd0) - *(float *)(unaff_EBX + 0x7c);
                  fStack_9c = *(float *)(iVar9 + 0xd8) - *(float *)(unaff_EBX + 0x84);
                  fStack_b0 = fVar4 * fVar4 + fStack_9c * fStack_9c;
                  fVar11 = (float10)FUN_0041b8a0(fStack_b0);
                  if (fVar11 <= (float10)local_a8) {
                    FUN_004ed0e0(&local_98,local_a0 + 8);
                  }
                  iVar10 = *(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + local_b4 * 4);
                  iVar9 = *(int *)(*(int *)(iVar10 + 4 + iVar5) + 0xc);
                  piVar7 = (int *)(iVar10 + iVar5);
                  if (iVar9 == 0) {
                    iVar9 = 0;
                  }
                  else {
                    iVar9 = iVar9 + -8;
                  }
                  piVar7[1] = iVar9;
                  iVar10 = local_b4;
                } while (iVar9 != *piVar7);
              }
              LeaveCriticalSection
                        ((LPCRITICAL_SECTION)
                         (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x8c) + 0x34) + iVar10 * 4) + 8 +
                         iVar5));
              iVar5 = iVar5 + 0x124;
              local_a4 = local_a4 + -1;
            } while (local_a4 != 0);
            local_a4 = 0;
            iVar5 = local_b8;
            iVar9 = local_ac;
          }
          iVar10 = iVar10 + 1;
          local_b4 = iVar10;
        } while (iVar10 <= iVar5);
      }
    }
  }
  ___security_check_cookie_4();
  return;
}

