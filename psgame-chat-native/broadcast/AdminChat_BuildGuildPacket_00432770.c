/*
 * server/ps_game.exe — AdminChat_BuildGuildPacket
 * VA solicitado: 0x00432770
 * Entry Ghidra:  00432770
 * Ghidra name:   FUN_00432770
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: broadcast
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_00432770(int param_1_00,void *param_2_00,char *param_1,byte param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined auStack_154 [4];
  uint local_150;
  int local_14c;
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
  
  local_8 = DAT_0057f7c4 ^ (uint)auStack_154;
  local_a4 = 0xf104;
  pcVar5 = param_1;
  do {
    cVar2 = *pcVar5;
    pcVar5[(int)(local_a2 + -(int)param_1)] = cVar2;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  local_150 = (uint)param_2;
  local_8d = param_2;
  local_14c = param_1_00;
  local_148 = param_2_00;
  _memcpy(local_8c,param_2_00,local_150);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1_00 + 0x4f4));
  iVar6 = FUN_0043a7a0();
  if (iVar6 != 0) {
    piVar1 = (int *)(param_1_00 + 0x534);
    do {
      if (*(int *)(iVar6 + 0x30) != 0) {
        FUN_004ed0e0(&local_a4,local_150 + 0x18);
      }
      FUN_0043dc50();
      iVar6 = *(int *)(param_1_00 + 0x524);
      if ((*piVar1 == 0) || (*piVar1 != *(int *)(param_1_00 + 0x50c))) {
        FUN_0051b1ad();
      }
      if (*(int *)(param_1_00 + 0x538) == iVar6) break;
      piVar7 = (int *)*piVar1;
      if (piVar7 == (int *)0x0) {
        FUN_0051b1ad();
        piVar7 = (int *)*piVar1;
        if (piVar7 != (int *)0x0) goto LAB_0043284d;
        iVar6 = 0;
      }
      else {
LAB_0043284d:
        iVar6 = *piVar7;
      }
      if (*(int *)(param_1_00 + 0x538) == *(int *)(iVar6 + 0x18)) {
        FUN_0051b1ad();
      }
      iVar6 = *(int *)(*(int *)(param_1_00 + 0x538) + 0x10);
    } while (iVar6 != 0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1_00 + 0x4f4));
  uVar3 = local_150;
  uStack_144 = 0x814;
  iVar6 = -(int)param_1;
  do {
    cVar2 = *param_1;
    param_1[(int)(acStack_13e + iVar6)] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  bStack_129 = param_2;
  _memcpy(auStack_128,local_148,local_150);
  iVar4 = local_14c;
  lpCriticalSection = (LPCRITICAL_SECTION)(local_14c + 0x53c);
  EnterCriticalSection(lpCriticalSection);
  iVar6 = FUN_0043a7a0();
  if (iVar6 != 0) {
    piVar1 = (int *)(iVar4 + 0x57c);
    do {
      if (*(int *)(iVar6 + 0x34) != 0) {
        iStack_142 = *(int *)(iVar6 + 0x34);
        FUN_004ed2d0(&uStack_144,uVar3 + 0x1c);
      }
      FUN_0043dc50();
      iVar6 = *(int *)(iVar4 + 0x56c);
      if ((*piVar1 == 0) || (*piVar1 != *(int *)(iVar4 + 0x554))) {
        FUN_0051b1ad();
      }
      if (*(int *)(iVar4 + 0x580) == iVar6) break;
      piVar7 = (int *)*piVar1;
      if (piVar7 == (int *)0x0) {
        FUN_0051b1ad();
        piVar7 = (int *)*piVar1;
        if (piVar7 != (int *)0x0) goto LAB_00432923;
        iVar6 = 0;
      }
      else {
LAB_00432923:
        iVar6 = *piVar7;
      }
      if (*(int *)(iVar4 + 0x580) == *(int *)(iVar6 + 0x18)) {
        FUN_0051b1ad();
      }
      iVar6 = *(int *)(*(int *)(iVar4 + 0x580) + 0x10);
    } while (iVar6 != 0);
  }
  LeaveCriticalSection(lpCriticalSection);
  ___security_check_cookie_4();
  return;
}

