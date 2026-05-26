/*
 * server/ps_game.exe — Chat_BroadcastGuild
 * Requested VA: 0x00432530
 * Entry Ghidra:  00432530
 * Ghidra name:   FUN_00432530
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: broadcast
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_00432530(void *param_1_00,int param_1,char *param_2,byte param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  uint local_14c;
  void *local_148;
  undefined2 uStack_144;
  int iStack_142;
  char acStack_13e [21];
  byte bStack_129;
  undefined auStack_128 [132];
  undefined2 local_a4;
  char local_a2 [21];
  byte local_8d;
  undefined local_8c [132];
  uint local_8;
  
  local_8 = DAT_0057f7c4 ^ (uint)&local_14c;
  local_148 = param_1_00;
  if (((param_4 == 0) || (iVar3 = FUN_0043a700(&param_4), iVar3 != 0)) ||
     (iVar3 = FUN_0043a700(&param_4), iVar3 != 0)) {
    local_a4 = 0x1104;
    pcVar4 = param_2;
    do {
      cVar2 = *pcVar4;
      pcVar4[(int)(local_a2 + -(int)param_2)] = cVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    local_14c = (uint)param_3;
    local_8d = param_3;
    _memcpy(local_8c,param_1_00,local_14c);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4f4));
    iVar3 = FUN_0043a7a0();
    if (iVar3 != 0) {
      piVar1 = (int *)(param_1 + 0x534);
      do {
        if (*(int *)(iVar3 + 0x30) != 0) {
          FUN_004ed0e0(&local_a4,local_14c + 0x18);
        }
        FUN_0043dc50();
        iVar3 = *(int *)(param_1 + 0x524);
        if ((*piVar1 == 0) || (*piVar1 != *(int *)(param_1 + 0x50c))) {
          FUN_0051b1ad();
        }
        if (*(int *)(param_1 + 0x538) == iVar3) break;
        piVar5 = (int *)*piVar1;
        if (piVar5 == (int *)0x0) {
          FUN_0051b1ad();
          piVar5 = (int *)*piVar1;
          if (piVar5 != (int *)0x0) goto LAB_0043264a;
          iVar3 = 0;
        }
        else {
LAB_0043264a:
          iVar3 = *piVar5;
        }
        if (*(int *)(param_1 + 0x538) == *(int *)(iVar3 + 0x18)) {
          FUN_0051b1ad();
        }
        iVar3 = *(int *)(*(int *)(param_1 + 0x538) + 0x10);
      } while (iVar3 != 0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4f4));
    uStack_144 = 0x812;
    iVar3 = -(int)param_2;
    do {
      cVar2 = *param_2;
      param_2[(int)(acStack_13e + iVar3)] = cVar2;
      param_2 = param_2 + 1;
    } while (cVar2 != '\0');
    bStack_129 = param_3;
    _memcpy(auStack_128,local_148,local_14c);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x53c));
    iVar3 = FUN_0043a7a0();
    if (iVar3 != 0) {
      piVar1 = (int *)(param_1 + 0x57c);
      do {
        if (*(int *)(iVar3 + 0x34) != 0) {
          iStack_142 = *(int *)(iVar3 + 0x34);
          FUN_004ed2d0(&uStack_144,local_14c + 0x1c);
        }
        FUN_0043dc50();
        iVar3 = *(int *)(param_1 + 0x56c);
        if ((*piVar1 == 0) || (*piVar1 != *(int *)(param_1 + 0x554))) {
          FUN_0051b1ad();
        }
        if (*(int *)(param_1 + 0x580) == iVar3) break;
        piVar5 = (int *)*piVar1;
        if (piVar5 == (int *)0x0) {
          FUN_0051b1ad();
          piVar5 = (int *)*piVar1;
          if (piVar5 != (int *)0x0) goto LAB_00432723;
          iVar3 = 0;
        }
        else {
LAB_00432723:
          iVar3 = *piVar5;
        }
        if (*(int *)(param_1 + 0x580) == *(int *)(iVar3 + 0x18)) {
          FUN_0051b1ad();
        }
        iVar3 = *(int *)(*(int *)(param_1 + 0x580) + 0x10);
      } while (iVar3 != 0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x53c));
  }
  ___security_check_cookie_4();
  return;
}

