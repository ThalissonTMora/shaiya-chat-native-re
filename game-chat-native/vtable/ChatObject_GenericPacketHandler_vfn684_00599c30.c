/*
 * Game.exe — ChatObject_GenericPacketHandler_vfn684
 * Requested VA: 0x00599C30
 * Entry Ghidra:  00599c30
 * Ghidra name:   FUN_00599c30
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: vtable
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00599c30(int *param_1_00,uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  short *psVar5;
  ushort in_FPUControlWord;
  longlong lVar6;
  undefined4 uVar7;
  uint uVar8;
  short local_20 [2];
  longlong local_1c;
  undefined local_14 [4];
  undefined local_10;
  undefined uStack_f;
  char cStack_e;
  undefined uStack_d;
  undefined4 uStack_c;
  DWORD DStack_8;
  undefined4 local_4;
  
  uVar2 = param_1 & 0xffff;
  if ((param_1 & 0xff00) == 0x1c00) {
    FUN_005a5c60(param_1,param_2);
    return;
  }
  if ((param_1 & 0xff00) == 0x1d00) {
    FUN_005a49e0(param_1,param_2);
    return;
  }
  if (uVar2 < 0x30d) {
    if (uVar2 != 0x30c) {
      if (uVar2 < 0x119) {
        if (uVar2 == 0x118) {
          (**(code **)(*param_1_00 + 0x68c))(param_2);
          return;
        }
        if (uVar2 == 0x114) {
          param_1 = 0;
          __time64(&local_1c);
          FUN_005f4700(&param_1,4);
          _DAT_022aff1a = 0;
          _DAT_022aff1e = 0;
          _DAT_022aff22 = 0;
          _DAT_022aff26 = 0;
          FUN_004603a0(param_1,&DAT_022aff1a);
          lVar6 = FUN_004c5860(&DAT_022aff1a);
          DAT_022aff30 = (undefined4)(lVar6 - local_1c);
          _DAT_022aff34 = (undefined4)((ulonglong)(lVar6 - local_1c) >> 0x20);
          DAT_022aff38 = DAT_022aff30;
          DAT_022aff3c = _DAT_022aff34;
          return;
        }
        if (uVar2 == 0x115) {
          __time64(&local_1c);
          param_1 = 0;
          FUN_005f4700(&param_1,4);
          local_10 = 0;
          uStack_f = 0;
          cStack_e = '\0';
          uStack_d = 0;
          uStack_c._0_2_ = 0;
          uStack_c._2_2_ = 0;
          DStack_8 = 0;
          local_4 = 0;
          FUN_004603a0(param_1,&local_10);
          lVar6 = FUN_004c5860(&local_10);
          DAT_022aff38 = (int)(lVar6 - local_1c);
          DAT_022aff3c = (int)((ulonglong)(lVar6 - local_1c) >> 0x20);
          return;
        }
      }
      else if (uVar2 == 0x30b) {
        param_1 = param_1 & 0xffffff00;
        FUN_004ee9f0();
        FUN_005f4700(&DAT_022b01b8,1);
        FUN_005f4700(&DAT_022b01b4,4);
        FUN_005f4700(&param_1,1);
        DVar3 = timeGetTime();
        param_2 = param_2 & 0xffffff00;
        if ((byte)param_1 == '\0') {
          return;
        }
        do {
          FUN_005f4700(&local_10,2);
          FUN_005f4700(&cStack_e,1);
          FUN_005f4700(&uStack_c,4);
          uStack_c = uStack_c * 1000;
          uVar7 = CONCAT22((undefined2)uStack_c,CONCAT11(uStack_d,cStack_e));
          if (cStack_e == 'd') {
            uVar7 = 1;
          }
          DStack_8 = DVar3;
          iVar4 = FUN_0046cda0(CONCAT13(uStack_d,CONCAT12(cStack_e,CONCAT11(uStack_f,local_10))),
                               uVar7);
          if ((iVar4 != 0) && (*(char *)(iVar4 + 0xe) == '\x01')) {
            local_4 = 1;
          }
          iVar4 = FUN_0046cda0(CONCAT13(uStack_d,CONCAT12(cStack_e,CONCAT11(uStack_f,local_10))),
                               CONCAT22((undefined2)uStack_c,CONCAT11(uStack_d,cStack_e)));
          if ((iVar4 == 0) || (*(short *)(iVar4 + 0x20) != 0x96)) {
            FUN_005997f0(&local_10);
          }
          bVar1 = (char)param_2 + 1;
          param_2 = CONCAT31(param_2._1_3_,bVar1);
        } while (bVar1 < (byte)param_1);
        return;
      }
LAB_00599fe1:
      uVar2 = param_1;
      uVar8 = param_2;
      FUN_005bd6f0(param_1,param_2);
      FUN_005bd700(uVar2,uVar8);
      return;
    }
    FUN_005f4700(&param_2,1);
    FUN_005f4700(&param_1,4);
    if ((DAT_022b01b8 == (char)param_2) && (DAT_022b01b4 == param_1)) {
      FUN_005f4700(&local_10,2);
      FUN_005f4700(&cStack_e,1);
      uVar7 = CONCAT22((undefined2)uStack_c,CONCAT11(uStack_d,cStack_e));
      if (cStack_e == 'd') {
        uVar7 = 1;
      }
      iVar4 = FUN_0046cda0(CONCAT13(uStack_d,CONCAT12(cStack_e,CONCAT11(uStack_f,local_10))),uVar7);
      if (iVar4 != 0) {
        uStack_c = (uint)*(ushort *)(iVar4 + 0x48) * 1000;
        DStack_8 = timeGetTime();
        if (*(char *)(iVar4 + 0xe) == '\x01') {
          local_4 = 1;
        }
        if (DAT_022b01c0 != DAT_022b01c4) {
          psVar5 = DAT_022b01c0;
          do {
            if ((*psVar5 == CONCAT11(uStack_f,local_10)) && (*(char *)(psVar5 + 1) == cStack_e)) {
              *(uint *)(psVar5 + 2) = (uint)*(ushort *)(iVar4 + 0x48) * 1000;
              return;
            }
            psVar5 = psVar5 + 8;
          } while (psVar5 != DAT_022b01c4);
        }
        if (*(short *)(iVar4 + 0x20) != 0x96) {
          FUN_005997f0(&local_10);
          return;
        }
      }
    }
  }
  else if (uVar2 == 0x30d) {
    FUN_005f4700(&param_2,1);
    FUN_005f4700(&local_1c,4);
    FUN_005f4700(local_20,2);
    FUN_005f4700(&param_1,1);
    if (((DAT_022b01b8 == (char)param_2) && (DAT_022b01b4 == (uint)local_1c)) &&
       (DAT_022b01c0 != DAT_022b01c4)) {
      psVar5 = DAT_022b01c0;
      while ((*psVar5 != local_20[0] || (*(char *)(psVar5 + 1) != (byte)param_1))) {
        psVar5 = psVar5 + 8;
        if (psVar5 == DAT_022b01c4) {
          return;
        }
      }
      FUN_00598810(local_14,psVar5);
      return;
    }
  }
  else if (uVar2 == 0x809) {
    FUN_005f4700(&local_10,0xd);
    if (((*DAT_007c4918 != 0) && (*(int *)(*DAT_007c4918 + 0x380) != 0)) &&
       (*(int *)(*(int *)(*DAT_007c4918 + 0x380) + 0x20) != 0)) {
      param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
      param_1 = in_FPUControlWord | 0xc00;
      local_1c = (longlong)
                 ROUND((double)CONCAT17((undefined)DStack_8,
                                        CONCAT25(uStack_c._2_2_,
                                                 CONCAT23((undefined2)uStack_c,
                                                          CONCAT12(uStack_d,CONCAT11(cStack_e,
                                                  uStack_f))))));
      FUN_004a7010(1,CONCAT13(uStack_d,CONCAT12(cStack_e,CONCAT11(uStack_f,local_10))),
                   (uint)local_1c,CONCAT13((undefined)local_4,DStack_8._1_3_));
      return;
    }
  }
  else {
    if (uVar2 != 0x80a) goto LAB_00599fe1;
    FUN_005f4700(&local_10,0xd);
    if (((*DAT_007c4918 != 0) && (*(int *)(*DAT_007c4918 + 0x380) != 0)) &&
       (*(int *)(*(int *)(*DAT_007c4918 + 0x380) + 0x20) != 0)) {
      param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
      param_1 = in_FPUControlWord | 0xc00;
      local_1c = (longlong)
                 ROUND((double)CONCAT17((undefined)DStack_8,
                                        CONCAT25(uStack_c._2_2_,
                                                 CONCAT23((undefined2)uStack_c,
                                                          CONCAT12(uStack_d,CONCAT11(cStack_e,
                                                  uStack_f))))));
      FUN_004a7010(0,CONCAT13(uStack_d,CONCAT12(cStack_e,CONCAT11(uStack_f,local_10))),
                   (uint)local_1c,CONCAT13((undefined)local_4,DStack_8._1_3_));
    }
  }
  return;
}

