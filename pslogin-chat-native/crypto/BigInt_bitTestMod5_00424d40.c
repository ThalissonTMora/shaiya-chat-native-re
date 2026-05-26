/*
 * server/ps_login.exe — BigInt_bitTestMod5
 * Requested VA: 0x00424D40
 * Entry Ghidra:  00424d40
 * Ghidra name:   FUN_00424d40
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: crypto
 * Regenerate: tools/ghidra/decompile.sh
 */


uint __cdecl FUN_00424d40(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint uVar4;
  undefined3 extraout_var_00;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint local_58;
  uint local_54;
  int local_50;
  int local_48 [3];
  uint auStack_3c [15];
  
  iVar2 = FUN_00421e00((int)param_1,1000000);
  if (iVar2 < 1) {
    if (param_1[1] < 0) {
      FUN_00421dd0(local_48);
      FUN_00429d70(local_48,param_1);
      uVar3 = FUN_00424d40(local_48,param_2);
      FUN_00422750(local_48);
      return uVar3;
    }
    uVar3 = FUN_00429d50((int)param_1);
    bVar1 = FUN_00425010(uVar3);
    return -(uint)(CONCAT31(extraout_var,bVar1) != 0) & 2;
  }
  uVar3 = FUN_00429d50((int)param_1);
  if (((((((uVar3 & 1) != 0) &&
         (uVar3 = FUN_004294c0((uint *)param_1[2],(uint *)param_1[1],0xc0cfd797), uVar3 % 3 != 0))
        && (uVar3 % 5 != 0)) && ((uVar3 % 7 != 0 && (uVar3 % 0xb != 0)))) &&
      ((uVar3 % 0xd != 0 && ((uVar3 % 0x11 != 0 && (uVar3 % 0x13 != 0)))))) &&
     ((uVar3 % 0x17 != 0 && (uVar3 % 0x1d != 0)))) {
    uVar3 = 1;
    local_50 = 0;
    local_58 = 1;
    uVar4 = FUN_00429ca0((int)param_1,2);
    uVar4 = (uVar4 / 0x1e) * (uVar4 / 0x1e);
    local_54 = 0x1f;
    if (0x1f < uVar4) {
      do {
        bVar1 = FUN_00425010(local_54);
        if (CONCAT31(extraout_var_00,bVar1) != 0) {
          uVar5 = (local_54 & 0xffff) * (uVar3 >> 0x10);
          uVar6 = (local_54 & 0xffff) * (uVar3 & 0xffff);
          iVar2 = (local_54 >> 0x10) * (uVar3 >> 0x10);
          uVar3 = (uVar6 >> 0x10) + uVar5 + (local_54 >> 0x10) * (uVar3 & 0xffff);
          if (uVar3 < uVar5) {
            iVar2 = iVar2 + 0x10000;
          }
          uVar5 = uVar3 * 0x10000 + (uVar6 & 0xffff);
          if ((uVar3 >> 0x10) + iVar2 != 0) {
            uVar3 = FUN_004294c0((uint *)param_1[2],(uint *)param_1[1],local_58);
            local_50 = local_50 + -1;
            if (-1 < local_50) {
              puVar7 = auStack_3c + local_50;
              do {
                if (uVar3 % *puVar7 == 0) {
                  uVar3 = FUN_004294c0((uint *)param_1[2],(uint *)param_1[1],auStack_3c[local_50]);
                  if (uVar3 == 0) {
                    return 0;
                  }
                  FUN_00429a70(s_C__cygwin_home_D6VAA1_dev_new_co_0044c10c,0x75,
                               s___gmpn_mod_1____n__>_mp_d_____n__0044c14c);
                  return 0;
                }
                local_50 = local_50 + -1;
                puVar7 = puVar7 + -1;
              } while (-1 < local_50);
            }
            local_58 = local_54;
            local_50 = 0;
            uVar5 = local_58;
          }
          local_58 = uVar5;
          auStack_3c[local_50] = local_54;
          local_50 = local_50 + 1;
          uVar3 = local_58;
        }
        local_54 = local_54 + 2;
      } while (local_54 < uVar4);
    }
    uVar3 = FUN_00429aa0((int)param_1,param_2);
    return uVar3;
  }
  return 0;
}

