/*
 * server/ps_game.exe — SendQueue_Mode5_CanNpcHear
 * VA solicitado: 0x004245A0
 * Entry Ghidra:  004245a0
 * Ghidra name:   FUN_004245a0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


undefined4 __thiscall FUN_004245a0(int param_1_00,int param_1)

{
  undefined2 *puVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *unaff_EBX;
  float local_1c;
  float local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar6 = 0;
  if ((((-1 < param_1_00) && (param_1_00 < DAT_01009674)) &&
      (puVar1 = (undefined2 *)(param_1_00 * 0x10c + DAT_01009678),
      *(short *)(param_1_00 * 0x10c + DAT_01009678) != 0)) &&
     (((*(int *)(puVar1 + 0x18) != 0 && (puVar1[0x11] != 0)) && (puVar1 != (undefined2 *)0x0)))) {
    local_10 = 0;
    local_c = 0;
    local_14 = in_EAX;
    if (0 < in_EAX) {
      do {
        iVar6 = iVar6 + 1;
        if (in_EAX * 10 < iVar6) break;
        iVar3 = _rand();
        local_1c = (float)(iVar3 % 0x14 + -10) + *unaff_EBX;
        iVar3 = _rand();
        local_18 = (float)(iVar3 % 0x14 + -10) + unaff_EBX[2];
        iVar4 = FUN_005250c0();
        iVar5 = FUN_005250c0();
        iVar3 = *(int *)(param_1 + 0x28);
        if (((iVar5 < 0) || (*(int *)(iVar3 + 4) <= iVar5)) ||
           ((iVar4 < 0 ||
            ((*(int *)(iVar3 + 4) <= iVar4 || (cVar2 = FUN_00422410(iVar3 + 8), cVar2 != '\0'))))))
        {
          local_1c = *unaff_EBX;
          local_18 = unaff_EBX[2];
          iVar4 = FUN_005250c0();
          iVar5 = FUN_005250c0();
          if ((-1 < iVar5) &&
             ((((iVar5 < *(int *)(iVar3 + 4) && (-1 < iVar4)) && (iVar4 < *(int *)(iVar3 + 4))) &&
              (cVar2 = FUN_00422410(iVar3 + 8), cVar2 == '\0')))) goto LAB_004246de;
          local_14 = local_14 + 1;
        }
        else {
LAB_004246de:
          iVar3 = FUN_00411760();
          if (iVar3 != 0) {
            *(undefined2 **)(iVar3 + 0xd4) = puVar1;
            FUN_004a0af0(*puVar1,0);
            *(float *)(iVar3 + 0x7c) = local_1c;
            *(float *)(iVar3 + 0x84) = local_18;
            *(float *)(iVar3 + 0x80) = unaff_EBX[1];
            FUN_0041cff0();
            local_10 = local_10 + 1;
          }
        }
        local_c = local_c + 1;
      } while (local_c < local_14);
      if (local_10 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

