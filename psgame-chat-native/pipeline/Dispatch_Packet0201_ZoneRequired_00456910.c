/*
 * server/ps_game.exe — Dispatch_Packet0201_ZoneRequired
 * Requested VA: 0x00456910
 * Entry Ghidra:  00456910
 * Ghidra name:   FUN_00456910
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: pipeline
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00456910(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int local_4;
  
  iVar1 = *(int *)(in_EAX + 0xe0);
  if (iVar1 == 0) {
    FUN_004efdc0(DAT_00587970 + 0xe0,"CUser::ZoneEnterUserMove() m_pZone == NULL, m_nWhere=%d %d",
                 *(undefined4 *)(in_EAX + 0x57f4),*(undefined4 *)(in_EAX + 0x582c));
    FUN_004ec760(9,0);
    return;
  }
  iVar3 = *(int *)(*(int *)(iVar1 + 0x28) + 0x1a4);
  if (iVar3 != 3) {
    if (iVar3 == 5) {
      if ((*(byte *)(in_EAX + 0x5808) < 0xb) && (*(int *)(in_EAX + 0x5588) != 0)) {
        *(undefined4 *)(in_EAX + 0x5588) = 0;
      }
      iVar3 = FUN_0042f770(*(undefined4 *)(iVar1 + 0x28),&local_4);
      if (iVar3 != 0) {
        *(int *)(in_EAX + 0x5584) = local_4;
        FUN_00431eb0();
        if (*(int *)(in_EAX + 0x1810) != 0) {
          InterlockedIncrement((LONG *)(*(int *)(in_EAX + 0x1810) + 0xa0));
        }
        if (local_4 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)(local_4 + 0x5cc));
        }
      }
      goto LAB_00456a04;
    }
    if (iVar3 != 6) goto LAB_00456a04;
  }
  if ((*(byte *)(in_EAX + 0x5808) < 0xb) && (*(int *)(in_EAX + 0x5588) != 0)) {
    *(undefined4 *)(in_EAX + 0x5588) = 0;
  }
LAB_00456a04:
  lpCriticalSection = (LPCRITICAL_SECTION)(in_EAX + 0x6284);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(in_EAX + 0x57f4) != 3) {
    FUN_004efdc0(DAT_00587970 + 0xe0,"CUser::ZoneEnterUserMove() !pUser->m_nWhere=%d %d",
                 *(int *)(in_EAX + 0x57f4),*(undefined4 *)(in_EAX + 0x582c));
    FUN_004ec760(9,0);
    LeaveCriticalSection(lpCriticalSection);
    return;
  }
  local_4 = iVar1 + 0x38;
  FUN_00415160();
  cVar2 = FUN_0041c700(iVar1);
  if (cVar2 == '\0') {
    FUN_004150d0();
    LeaveCriticalSection(lpCriticalSection);
    return;
  }
  *(undefined4 *)(in_EAX + 0x57f4) = 4;
  LeaveCriticalSection(lpCriticalSection);
  return;
}

