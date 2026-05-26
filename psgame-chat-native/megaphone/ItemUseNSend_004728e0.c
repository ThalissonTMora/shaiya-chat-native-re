/*
 * server/ps_game.exe — ItemUseNSend
 * VA solicitado: 0x004728E0
 * Entry Ghidra:  004728e0
 * Ghidra name:   FUN_004728e0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: megaphone
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004728e0(int param_1_00,int param_1,int param_2,char param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined2 local_d4;
  undefined4 local_d2;
  undefined local_ce;
  undefined local_cd;
  undefined local_cc;
  undefined local_cb;
  undefined local_ca;
  undefined2 local_c8;
  undefined4 local_c6;
  undefined local_c2;
  undefined local_c1;
  undefined local_c0;
  undefined4 *local_bc;
  undefined2 local_b8 [43];
  undefined4 local_61;
  undefined4 local_5d;
  undefined4 local_59;
  char local_55 [32];
  undefined4 local_35;
  undefined2 local_31;
  undefined4 local_2f;
  undefined local_2b;
  undefined local_16;
  undefined local_15;
  uint local_c;
  
  local_c = DAT_0057f7c4 ^ (uint)&local_d4;
  iVar1 = param_2 + param_1 * 0x18;
  iVar3 = *(int *)(param_1_00 + 0x1c0 + iVar1 * 4);
  local_bc = (undefined4 *)(param_1_00 + 0x1c0 + iVar1 * 4);
  if (iVar3 != 0) {
    if (((99 < *(byte *)(iVar3 + 0x40)) && (*(byte *)(iVar3 + 0x40) < 0x68)) ||
       ((0xaca0 < **(uint **)(iVar3 + 0x30) && (**(uint **)(iVar3 + 0x30) < 0xaca8)))) {
      local_2b = 0;
      FUN_00467f60();
      local_5d = *(undefined4 *)(iVar3 + 0x3c);
      local_61 = *(undefined4 *)(iVar3 + 0x38);
      local_b8[0] = 0x40e;
      local_59 = **(undefined4 **)(iVar3 + 0x30);
      pcVar4 = (char *)(*(undefined4 **)(iVar3 + 0x30) + 1);
      iVar1 = -(int)pcVar4;
      do {
        cVar2 = *pcVar4;
        pcVar4[(int)(local_55 + iVar1)] = cVar2;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      local_35 = *(undefined4 *)(iVar3 + 0x46);
      local_16 = (undefined)param_1;
      local_31 = *(undefined2 *)(iVar3 + 0x4a);
      local_15 = (undefined)param_2;
      local_2f = *(undefined4 *)(iVar3 + 100);
      FUN_004ed210(local_b8,0xa5);
    }
    local_c0 = 1;
    local_c2 = (undefined)param_1;
    local_c1 = (undefined)param_2;
    if (*(byte *)(iVar3 + 0x42) < 2) {
      *local_bc = 0;
      *(char *)(iVar3 + 0x42) = *(char *)(iVar3 + 0x42) + -1;
      local_c8 = 0x702;
      local_c6 = *(undefined4 *)(param_1_00 + 0x582c);
      FUN_004ed2d0(&local_c8,9);
      local_d2 = *(undefined4 *)(param_1_00 + 0xdc);
      local_ce = (undefined)param_1;
      local_cc = *(undefined *)(iVar3 + 0x40);
      local_ca = *(undefined *)(iVar3 + 0x42);
      local_d4 = 0x50a;
      local_cd = (undefined)param_2;
      local_cb = *(undefined *)(iVar3 + 0x41);
      if (*(int *)(param_1_00 + 0xe0) != 0) {
        FUN_00427cf0(*(int *)(param_1_00 + 0xe0),&local_d4,0xb,param_1_00 + 0xd0,_DAT_00574168,
                     local_d2,0,5);
      }
      if (param_3 != '\0') {
        FUN_004ed0e0(&local_d4,0xb);
      }
      FUN_00411710();
      ___security_check_cookie_4();
      return;
    }
    *(byte *)(iVar3 + 0x42) = *(byte *)(iVar3 + 0x42) - 1;
    local_c8 = 0x702;
    local_c6 = *(undefined4 *)(param_1_00 + 0x582c);
    FUN_004ed2d0(&local_c8,9);
    local_d2 = *(undefined4 *)(param_1_00 + 0xdc);
    local_ce = (undefined)param_1;
    local_cc = *(undefined *)(iVar3 + 0x40);
    local_ca = *(undefined *)(iVar3 + 0x42);
    local_d4 = 0x50a;
    local_cd = (undefined)param_2;
    local_cb = *(undefined *)(iVar3 + 0x41);
    if (*(int *)(param_1_00 + 0xe0) != 0) {
      FUN_00427cf0(*(int *)(param_1_00 + 0xe0),&local_d4,0xb,param_1_00 + 0xd0,_DAT_00574168,
                   local_d2,0,5);
    }
    if (param_3 != '\0') {
      FUN_004ed0e0(&local_d4,0xb);
    }
  }
  ___security_check_cookie_4();
  return;
}

