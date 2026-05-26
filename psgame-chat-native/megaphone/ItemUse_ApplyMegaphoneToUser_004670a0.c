/*
 * server/ps_game.exe — ItemUse_ApplyMegaphoneToUser
 * Requested VA: 0x004670A0
 * Entry Ghidra:  004670a0
 * Ghidra name:   FUN_004670a0
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: megaphone
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void ** FUN_004670a0(void **param_1,int param_2)

{
  short sVar1;
  int iVar2;
  void *pvVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  void **ppvVar7;
  void **extraout_EAX;
  undefined4 *puVar8;
  int iVar9;
  void **ppvVar10;
  void **ppvVar11;
  void *pvVar12;
  int iVar13;
  void *pvVar14;
  int local_150;
  int local_14c;
  undefined2 local_144;
  void *local_142;
  int aiStack_130 [10];
  int aiStack_108 [10];
  int aiStack_e0 [26];
  undefined4 auStack_78 [27];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00552bcb;
  local_c = ExceptionList;
  uVar5 = DAT_0057f7c4 ^ (uint)&stack0xfffffea0;
  ppvVar7 = &local_c;
  if (10 < *(ushort *)((int)param_1 + 0x136)) {
    ExceptionList = ppvVar7;
    if (param_1[0x1657] == (void *)0x0) {
      if (*(byte *)(param_1 + 0x1602) < 0xb) {
        iVar6 = _rand();
        ppvVar7 = (void **)(iVar6 / 3);
        local_150 = iVar6 % 3 + 1;
        if (0 < local_150) {
          do {
            iVar6 = 1;
            iVar13 = 0;
            if (0 < (int)param_1[0x4c3]) {
              ppvVar11 = param_1 + 0x88;
              do {
                ppvVar7 = (void **)0x0;
                ppvVar10 = ppvVar11;
                do {
                  if ((*ppvVar10 != (void *)0x0) &&
                     (*(char *)(*(int *)((int)*ppvVar10 + 0x30) + 0x24) != '^')) {
                    aiStack_e0[iVar13] = iVar6;
                    auStack_78[iVar13] = ppvVar7;
                    iVar13 = iVar13 + 1;
                    if (0x18 < iVar13) goto LAB_0046716c;
                  }
                  ppvVar7 = (void **)((int)ppvVar7 + 1);
                  ppvVar10 = ppvVar10 + 1;
                } while ((int)ppvVar7 < 0x18);
                iVar6 = iVar6 + 1;
                ppvVar11 = ppvVar11 + 0x18;
              } while (iVar6 <= (int)param_1[0x4c3]);
LAB_0046716c:
              if (0 < iVar13) {
                iVar6 = _rand();
                ppvVar7 = (void **)FUN_004674f0(aiStack_e0[iVar6 % iVar13],param_2);
              }
            }
            local_150 = local_150 + -1;
          } while (local_150 != 0);
        }
      }
      else {
        sVar1 = *(short *)((int)param_1 + 0x166);
        if ((sVar1 < -0xbe) || (0xbe < sVar1)) {
          iVar6 = 0x41;
        }
        else if ((sVar1 < -0xaa) || (0xaa < sVar1)) {
          iVar6 = 0x46;
        }
        else if ((sVar1 < -0x8c) || (0x8c < sVar1)) {
          iVar6 = 0x50;
        }
        else if ((sVar1 < -100) || (100 < sVar1)) {
          iVar6 = 0x55;
        }
        else if ((sVar1 < -0x32) || (0x32 < sVar1)) {
          iVar6 = 0x5a;
        }
        else if ((sVar1 < -10) || (10 < sVar1)) {
          iVar6 = 0x5f;
        }
        else {
          iVar6 = 100;
        }
        iVar13 = _rand();
        ppvVar7 = (void **)(iVar13 / 100);
        if (iVar13 % 100 < iVar6) {
          iVar6 = 1;
          iVar13 = 0;
          if (0 < (int)param_1[0x4c3]) {
            ppvVar11 = param_1 + 0x88;
            do {
              iVar9 = 0;
              ppvVar10 = ppvVar11;
              do {
                pvVar14 = *ppvVar10;
                if ((((pvVar14 != (void *)0x0) &&
                     (iVar2 = *(int *)(*(int *)((int)pvVar14 + 0x30) + 0xa0), 0 < iVar2)) &&
                    (iVar2 < 0x1a)) &&
                   ((ppvVar7 = *(void ***)((int)pvVar14 + 0x30),
                    *(char *)((int)ppvVar7 + 0x31) == '\0' && (*(char *)(ppvVar7 + 9) != '^')))) {
                  aiStack_108[iVar13] = iVar6;
                  aiStack_130[iVar13] = iVar9;
                  iVar13 = iVar13 + 1;
                  if (9 < iVar13) goto LAB_004672c7;
                }
                iVar9 = iVar9 + 1;
                ppvVar10 = ppvVar10 + 1;
              } while (iVar9 < 0x18);
              iVar6 = iVar6 + 1;
              ppvVar11 = ppvVar11 + 0x18;
              ppvVar7 = param_1;
            } while (iVar6 <= (int)param_1[0x4c3]);
LAB_004672c7:
            if (0 < iVar13) {
              iVar6 = _rand();
              ppvVar7 = (void **)FUN_004674f0(aiStack_108[iVar6 % iVar13],param_2);
            }
          }
        }
      }
    }
    pvVar14 = (void *)0x0;
    if ((param_1[0x1657] == (void *)0x0) && (param_1[0x50] != (void *)0x0)) {
      iVar6 = _rand();
      ppvVar7 = (void **)(iVar6 / 100);
      if (iVar6 % 100 < 0x1e) {
        iVar6 = _rand();
        pvVar3 = param_1[0x50];
        pvVar12 = (void *)(iVar6 % (int)((uint)*(ushort *)((int)param_1 + 0x136) * 5) + 1);
        if (pvVar3 < pvVar12) {
          param_1[0x50] = (void *)0x0;
          pvVar12 = pvVar3;
        }
        else {
          param_1[0x50] = (void *)((int)pvVar3 - (int)pvVar12);
        }
        FUN_0047aae0(uVar5);
        local_142 = param_1[0x50];
        local_144 = 0x213;
        FUN_004ed0e0(&local_144,6);
        if (param_2 != 0) {
          FUN_0044e110();
          iVar13 = 0;
          local_4 = 0;
          iVar6 = *(int *)(param_2 + 0x17f4);
          if (iVar6 != 0) {
            iVar9 = *(int *)(iVar6 + 0x10);
            FUN_005250c0();
            if (0 < iVar9) {
              do {
                cVar4 = FUN_0046ad40(100);
                if (cVar4 != '\0') {
                  FUN_0046bba0();
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 < *(int *)(iVar6 + 0x10));
            }
            if (local_14c == 0) {
              ExceptionList = local_c;
              return (void **)0x0;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(local_14c + 0x118));
            ExceptionList = local_c;
            return extraout_EAX;
          }
          pvVar14 = *(void **)(param_2 + 0xdc);
          local_4 = 0xffffffff;
          if (local_14c != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)(local_14c + 0x118));
          }
        }
        ppvVar7 = (void **)FUN_004116d0();
        if (ppvVar7 != (void **)0x0) {
          ppvVar7[0x1c] = pvVar14;
          ppvVar7[0xc] = (void *)0x0;
          *(undefined *)(ppvVar7 + 0x10) = 0x1a;
          *(undefined *)((int)ppvVar7 + 0x41) = 0;
          *(undefined *)((int)ppvVar7 + 0x42) = 1;
          *(undefined2 *)(ppvVar7 + 0x11) = 0;
          *(undefined *)(ppvVar7 + 0x1a) = 0x55;
          puVar8 = (undefined4 *)FUN_0049b080();
          ppvVar7[2] = (void *)*puVar8;
          ppvVar7[3] = (void *)puVar8[1];
          ppvVar7[4] = (void *)puVar8[2];
          *(undefined *)(ppvVar7 + 0x1e) = 3;
          ppvVar7[0x1f] = param_1[0x37];
          ppvVar7[0x1d] = (void *)0x0;
          ppvVar7[0x20] = pvVar12;
          FUN_004d2470();
          ppvVar7 = (void **)FUN_0041d9b0(1);
        }
      }
    }
  }
  ExceptionList = local_c;
  return ppvVar7;
}

