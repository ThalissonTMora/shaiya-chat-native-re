/*
 * server/ps_game.exe — Chat_PacketBuilder_1109_A
 * Requested VA: 0x004C6A80
 * Entry Ghidra:  004c6a80
 * Ghidra name:   FUN_004c6a80
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: send
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004c6a80(int param_1_00,undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  undefined auStack_9c [4];
  undefined2 local_98;
  undefined local_96;
  undefined4 local_95;
  undefined local_91;
  char local_90 [132];
  uint local_c;
  
  local_c = DAT_0057f7c4 ^ (uint)auStack_9c;
  iVar2 = FUN_004c6970(param_1);
  if ((iVar2 != 0) && (pcVar3 = (char *)(iVar2 + 4), pcVar3 != (char *)0x0)) {
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar2 = (int)pcVar5 - (iVar2 + 5);
    if (iVar2 - 1U < 0x7f) {
      local_95 = *(undefined4 *)(param_1_00 + 0x88);
      local_98 = 0x1109;
      local_96 = 0;
      local_91 = (undefined)iVar2;
      iVar4 = -(int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[(int)(local_90 + iVar4)] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (*(int *)(param_1_00 + 0x8c) != 0) {
        iVar4 = FUN_0041c6e0(*(undefined4 *)(param_1_00 + 0x1b0));
        if (iVar4 != 0) {
          if (*(int *)(iVar4 + 0x17f4) != 0) {
            EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar4 + 0x17f4) + 0x118));
            FUN_0044e950();
            LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar4 + 0x17f4) + 0x118));
            ___security_check_cookie_4();
            return;
          }
          FUN_004ed0e0(&local_98,iVar2 + 8);
        }
      }
    }
  }
  ___security_check_cookie_4();
  return;
}

