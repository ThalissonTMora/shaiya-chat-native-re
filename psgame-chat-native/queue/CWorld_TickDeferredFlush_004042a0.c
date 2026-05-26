/*
 * server/ps_game.exe — CWorld_TickDeferredFlush
 * VA solicitado: 0x004042A0
 * Entry Ghidra:  004042a0
 * Ghidra name:   FUN_004042a0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_004042a0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int in_EAX;
  LPCRITICAL_SECTION unaff_EBX;
  code *pcVar2;
  
  pcVar2 = EnterCriticalSection_exref;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x1c));
  lpCriticalSection = (LPCRITICAL_SECTION)(in_EAX + 0xc4);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(in_EAX + 0xb8) == 0) {
    if (*(int *)(in_EAX + 0xb0) != 0) {
      FUN_00404480();
      EnterCriticalSection(lpCriticalSection);
      InterlockedExchange((LONG *)(in_EAX + 0xb0),0);
      goto LAB_0040434e;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x14) + 4);
    *(int *)(in_EAX + 0x18) = iVar1;
    if (iVar1 != *(int *)(in_EAX + 0x14)) {
      do {
        if (iVar1 == 0) break;
        FUN_004298a0(0);
        iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + 4);
        *(int *)(in_EAX + 0x18) = iVar1;
        pcVar2 = EnterCriticalSection_exref;
      } while (iVar1 != *(int *)(in_EAX + 0x14));
    }
    FUN_00404480();
    (*pcVar2)(lpCriticalSection);
    InterlockedExchange((LONG *)(in_EAX + 0xb8),0);
    LeaveCriticalSection(lpCriticalSection);
    (*pcVar2)(lpCriticalSection);
    InterlockedExchange((LONG *)(in_EAX + 0xb0),0);
LAB_0040434e:
    LeaveCriticalSection(lpCriticalSection);
  }
  if (*(int *)(in_EAX + 0xbc) == 0) {
    if (*(int *)(in_EAX + 0xb4) == 0) goto LAB_004043f3;
    FUN_00404480();
    (*pcVar2)(lpCriticalSection);
    InterlockedExchange((LONG *)(in_EAX + 0xb4),0);
  }
  else {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x14) + 4);
    *(int *)(in_EAX + 0x18) = iVar1;
    if (iVar1 != *(int *)(in_EAX + 0x14)) {
      do {
        if (iVar1 == 0) break;
        FUN_004298a0(1);
        iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + 4);
        *(int *)(in_EAX + 0x18) = iVar1;
        pcVar2 = EnterCriticalSection_exref;
      } while (iVar1 != *(int *)(in_EAX + 0x14));
    }
    FUN_00404480();
    (*pcVar2)(lpCriticalSection);
    InterlockedExchange((LONG *)(in_EAX + 0xbc),0);
    LeaveCriticalSection(lpCriticalSection);
    (*pcVar2)(lpCriticalSection);
    InterlockedExchange((LONG *)(in_EAX + 0xb4),0);
  }
  LeaveCriticalSection(lpCriticalSection);
LAB_004043f3:
  if (*(int *)(in_EAX + 0xc0) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x1c));
    return;
  }
  iVar1 = *(int *)(*(int *)(in_EAX + 0x14) + 4);
  *(int *)(in_EAX + 0x18) = iVar1;
  if (iVar1 != *(int *)(in_EAX + 0x14)) {
    do {
      if (iVar1 == 0) break;
      if (*(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x28) + 0x1a4) == 0) {
        FUN_00431240();
      }
      iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + 4);
      *(int *)(in_EAX + 0x18) = iVar1;
    } while (iVar1 != *(int *)(in_EAX + 0x14));
  }
  (*pcVar2)(lpCriticalSection);
  InterlockedExchange((LONG *)(in_EAX + 0xc0),0);
  LeaveCriticalSection(lpCriticalSection);
  LeaveCriticalSection(lpCriticalSection);
  LeaveCriticalSection(unaff_EBX);
  return;
}

