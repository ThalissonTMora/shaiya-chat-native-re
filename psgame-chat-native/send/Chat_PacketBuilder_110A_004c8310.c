/*
 * server/ps_game.exe — Chat_PacketBuilder_110A
 * Requested VA: 0x004C8310
 * Entry Ghidra:  004c8310
 * Ghidra name:   FUN_004c8310
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: send
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_004c8310(undefined4 param_1_00,undefined2 param_2,float param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int unaff_ESI;
  int iVar9;
  float10 fVar10;
  int local_2c;
  int local_28;
  int local_1c;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 local_a;
  
  local_e = *(undefined4 *)(unaff_ESI + 0x88);
  local_10 = 0x110a;
  local_a = param_2;
  local_28 = FUN_005250c0();
  local_2c = FUN_005250c0();
  iVar5 = FUN_005250c0();
  iVar6 = FUN_005250c0();
  if (local_28 < 0) {
    local_28 = 0;
  }
  iVar9 = *(int *)(*(int *)(unaff_ESI + 0x8c) + 0x2c);
  if (iVar9 <= local_2c) {
    local_2c = iVar9 + -1;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  iVar9 = *(int *)(*(int *)(unaff_ESI + 0x8c) + 0x30);
  if (iVar9 <= iVar6) {
    iVar6 = iVar9 + -1;
  }
  do {
    if (iVar6 < iVar5) {
      return;
    }
    if (local_28 <= local_2c) {
      iVar9 = local_28 * 0x124;
      local_1c = (local_2c - local_28) + 1;
      do {
        EnterCriticalSection
                  ((LPCRITICAL_SECTION)
                   (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar5 * 4) + 8 + iVar9));
        iVar1 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar5 * 4);
        iVar2 = *(int *)(iVar1 + iVar9);
        iVar8 = *(int *)(iVar2 + 0xc);
        if (iVar8 == 0) {
          iVar8 = 0;
        }
        else {
          iVar8 = iVar8 + -8;
        }
        *(int *)(iVar1 + iVar9 + 4) = iVar8;
        if (iVar8 != iVar2) {
          do {
            if (iVar8 == 0) break;
            fVar3 = *(float *)(iVar8 + 0xd0) - *(float *)(unaff_ESI + 0x7c);
            fVar4 = *(float *)(iVar8 + 0xd8) - *(float *)(unaff_ESI + 0x84);
            fVar10 = (float10)FUN_0041b8a0(fVar3 * fVar3 + fVar4 * fVar4);
            if (fVar10 <= (float10)param_1) {
              FUN_004ed0e0(&local_10,8);
            }
            iVar1 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar5 * 4);
            iVar8 = *(int *)(*(int *)(iVar1 + 4 + iVar9) + 0xc);
            piVar7 = (int *)(iVar1 + iVar9);
            if (iVar8 == 0) {
              iVar8 = 0;
            }
            else {
              iVar8 = iVar8 + -8;
            }
            piVar7[1] = iVar8;
          } while (iVar8 != *piVar7);
        }
        LeaveCriticalSection
                  ((LPCRITICAL_SECTION)
                   (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x8c) + 0x34) + iVar5 * 4) + 8 + iVar9));
        iVar9 = iVar9 + 0x124;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

