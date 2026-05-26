/*
 * server/ps_game.exe — CUser_SendBackpressure
 * Requested VA: 0x004F6F00
 * Entry Ghidra:  004f6f00
 * Ghidra name:   FUN_004f6f00
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: network
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void __thiscall FUN_004f6f00(int *param_1,uint param_2,int param_3,uint param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  uint *puVar2;
  LONG LVar3;
  int *piVar4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 3);
  EnterCriticalSection(lpCriticalSection);
  if (*param_1 == 0) {
    puVar2 = (uint *)FUN_004f6e20();
    if (puVar2 != (uint *)0x0) {
      puVar2[1] = param_2;
      *puVar2 = param_3 << 0x10 | param_4;
      puVar2[2] = 0;
      param_1[1] = (int)puVar2;
LAB_004f6fee:
      *param_1 = (int)puVar2;
      goto LAB_004f6ff0;
    }
  }
  else {
    puVar2 = (uint *)FUN_004f6e20();
    if (puVar2 != (uint *)0x0) {
      param_4 = param_3 << 0x10 | param_4;
      puVar2[1] = param_2;
      *puVar2 = param_4;
      piVar4 = (int *)*param_1;
      if ((int)param_4 < *piVar4) {
        puVar2[2] = (uint)piVar4;
        goto LAB_004f6fee;
      }
      if (piVar4[2] == 0) {
        *(uint **)(param_1[1] + 8) = puVar2;
        puVar2[2] = 0;
        param_1[1] = (int)puVar2;
      }
      else {
        do {
          piVar1 = (int *)piVar4[2];
          if ((int)param_4 < *piVar1) {
            puVar2[2] = (uint)piVar1;
            piVar4[2] = (int)puVar2;
            goto LAB_004f6ff0;
          }
          piVar4 = piVar1;
        } while (piVar1[2] != 0);
        *(uint **)(param_1[1] + 8) = puVar2;
        puVar2[2] = 0;
        param_1[1] = (int)puVar2;
      }
LAB_004f6ff0:
      param_1[2] = param_1[2] + (uint)**(ushort **)(param_2 + 4);
      param_1[9] = param_1[9] + 1;
      goto LAB_004f6ffc;
    }
  }
  LVar3 = InterlockedDecrement((LONG *)(param_2 + 8));
  if (LVar3 == 0) {
    FUN_004f33a0(param_2);
    LeaveCriticalSection(lpCriticalSection);
    return;
  }
LAB_004f6ffc:
  LeaveCriticalSection(lpCriticalSection);
  return;
}

