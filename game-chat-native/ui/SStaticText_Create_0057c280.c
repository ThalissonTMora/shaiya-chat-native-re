/*
 * Game.exe — SStaticText_Create
 * VA solicitado: 0x0057C280
 * Entry Ghidra:  0057c280
 * Ghidra name:   FUN_0057c280
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0057c280(int *param_1_00,char *param_1)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  size_t _Size;
  uint *puVar10;
  uint *puVar11;
  int *unaff_EBP;
  int unaff_ESI;
  int *piStack_580;
  float fStack_570;
  char *pcStack_56c;
  int iStack_568;
  int *piStack_564;
  int *piStack_560;
  undefined4 local_54c;
  float local_548;
  int *local_53c;
  int iStack_538;
  int iStack_534;
  int iStack_530;
  char acStack_448 [260];
  char acStack_344 [832];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_54c;
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iStack_568 = (int)pcVar5 - (int)(param_1 + 1);
  piStack_560 = (int *)0x0;
  piStack_564 = &local_54c;
  pcStack_56c = param_1;
  fStack_570 = 8.059568e-39;
  local_53c = param_1_00;
  FUN_00575610();
  piVar8 = DAT_022b69a8;
  piStack_560 = (int *)0x0;
  piStack_564 = param_1_00 + 3;
  pcStack_56c = (char *)param_1_00[4];
  iStack_568 = 2;
  local_54c = local_54c + 2;
  fStack_570 = (float)((int)local_548 + 2);
  local_548 = fStack_570;
  iVar6 = (**(code **)(*DAT_022b69a8 + 0x90))();
  if (-1 < iVar6) {
    piStack_580 = param_1_00 + 1;
    iVar6 = (**(code **)(*DAT_022b69a8 + 0x70))
                      (DAT_022b69a8,iStack_568,piStack_564,param_1_00[4],0,0,0);
    if (-1 < iVar6) {
      piStack_580 = (int *)0x0;
      iVar6 = (**(code **)(*DAT_022b69a8 + 0x98))(DAT_022b69a8);
      if (-1 < iVar6) {
        if (param_1_00[1] != 0) {
          piStack_580 = (int *)0x0;
          iVar6 = (**(code **)(*DAT_022b69a8 + 0x94))(DAT_022b69a8);
          if (-1 < iVar6) {
            piStack_580 = (int *)0x57c38f;
            (**(code **)(*DAT_022b69a8 + 0xa4))();
            piStack_580 = (int *)0x0;
            iVar6 = (**(code **)(*DAT_022b69a8 + 0xac))(DAT_022b69a8,0,0,1,0xff0000ff,0);
            if (-1 < iVar6) {
              pcVar5 = param_1;
              do {
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
              } while (cVar1 != '\0');
              param_1_00 = piVar8;
              if (pcVar5 != param_1 + 1) {
                pcVar5 = (char *)0x0;
LAB_0057c3d0:
                if (param_1[(int)pcVar5] != '<') goto LAB_0057c3f8;
                pcVar7 = param_1;
                do {
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar7 + 1;
                } while (cVar1 != '\0');
                if ((pcVar7 + (-1 - (int)(param_1 + 1)) <= pcVar5) ||
                   (param_1[(int)(pcVar5 + 1)] != '<')) goto LAB_0057c3f8;
                pcVar7 = param_1;
                do {
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar7 + 1;
                } while (cVar1 != '\0');
                if (((pcVar7 + (-1 - (int)(param_1 + 1)) < pcVar5 + 7) ||
                    (_Size = FUN_00631bbc(&stack0xfffffa84), (int)_Size < 1)) ||
                   (param_1[(int)(pcVar5 + 5)] != 'c')) goto LAB_0057c40d;
                piStack_580._0_3_ = (uint3)*(ushort *)(param_1 + (int)(pcVar5 + 6));
                FUN_00631bbc(&piStack_580);
                _memset(&local_54c,0,0x104);
                _memset(acStack_448,0,0x104);
                _memset(acStack_344,0,0x104);
                _memcpy(&local_54c,param_1,(size_t)pcVar5);
                _memcpy(acStack_448,param_1 + (int)(pcVar5 + 8),_Size);
                pcVar7 = param_1;
                do {
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar7 + 1;
                } while (cVar1 != '\0');
                if (pcVar7 + ((-(int)pcVar5 - (int)(param_1 + 1)) - _Size) != (char *)0x8 &&
                    -1 < (int)(pcVar7 + ((-(int)pcVar5 - (int)(param_1 + 1)) - _Size) + -8)) {
                  pcVar7 = param_1;
                  do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar1 != '\0');
                  _memcpy(acStack_344,param_1 + (int)(pcVar5 + _Size + 8),
                          (size_t)(pcVar7 + ((-(int)pcVar5 - (int)(param_1 + 1)) - _Size) + -8));
                }
                pcVar5 = (char *)&local_54c;
                fStack_570 = 0.0;
                iVar6 = 1;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 != (char *)((int)&local_54c + 1)) {
                  FUN_00573e20(1,0,0xff000000,&local_54c,0);
                  FUN_00573e20(1,2,0xff000000,&local_54c,0);
                  FUN_00573e20(0,1,0xff000000,&local_54c,0);
                  FUN_00573e20(2,1,0xff000000,&local_54c,0);
                  FUN_00573e20(1,1,0xffffffff,&local_54c,0);
                  pcVar5 = (char *)&local_54c;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  FUN_00575610(&local_54c,(int)pcVar5 - ((int)&local_54c + 1),&fStack_570,0);
                  iVar6 = (int)fStack_570 + 1;
                }
                pcVar5 = acStack_448;
                fStack_570 = 0.0;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 != acStack_448 + 1) {
                  FUN_00573e20(iVar6,0,0xff000000,acStack_448,0);
                  FUN_00573e20(iVar6,2,0xff000000,acStack_448,0);
                  FUN_00573e20(iVar6 + -1,1,0xff000000,acStack_448,0);
                  FUN_00573e20(iVar6 + 1,1,0xff000000,acStack_448,0);
                  FUN_00573e20(iVar6,1,0xffffffff,acStack_448,0);
                  pcVar5 = acStack_448;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  FUN_00575610(acStack_448,(int)pcVar5 - (int)(acStack_448 + 1),&fStack_570,0);
                  iVar6 = iVar6 + (int)fStack_570;
                }
                pcVar5 = acStack_344;
                fStack_570 = 0.0;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 != acStack_344 + 1) {
                  FUN_00573e20(iVar6,0,0xff000000,acStack_344,0);
                  FUN_00573e20(iVar6,2,0xff000000,acStack_344,0);
                  FUN_00573e20(iVar6 + -1,1,0xff000000,acStack_344,0);
                  FUN_00573e20(iVar6 + 1,1,0xff000000,acStack_344,0);
                  FUN_00573e20(iVar6,1,0xffffffff,acStack_344,0);
                  pcVar5 = acStack_344;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  FUN_00575610(acStack_344,(int)pcVar5 - (int)(acStack_344 + 1),&fStack_570,0);
                }
                goto LAB_0057c47c;
              }
LAB_0057c40d:
              FUN_00573e20(1,0,0xff000000,param_1,0);
              FUN_00573e20(1,2,0xff000000,param_1,0);
              FUN_00573e20(0,1,0xff000000,param_1,0);
              FUN_00573e20(2,1,0xff000000,param_1,0);
              FUN_00573e20(1,1,0xffffffff,param_1,0);
            }
LAB_0057c47c:
            (**(code **)(*DAT_022b69a8 + 0xa8))(DAT_022b69a8);
          }
        }
        piStack_580 = (int *)0x0;
        iVar6 = (**(code **)(*DAT_022b69a8 + 0x94))(DAT_022b69a8);
        if (-1 < iVar6) {
          if (unaff_EBP != (int *)0x0) {
            piStack_580 = (int *)0x57c4bb;
            (**(code **)(*unaff_EBP + 8))();
          }
          piStack_580 = (int *)0x57c4ca;
          piVar8 = (int *)operator_new(0xc);
          iVar6 = 0;
          if (piVar8 != (int *)0x0) {
            *piVar8 = 0;
            piVar8[1] = 0;
            piVar8[2] = 0;
            piVar8[1] = iStack_568;
            piVar8[2] = (int)piStack_564;
            piStack_580 = piVar8;
            iVar9 = (**(code **)(*DAT_022b69a8 + 0x5c))
                              (DAT_022b69a8,iStack_568,piStack_564,1,0,0x15,1);
            if (-1 < iVar9) {
              piVar8 = (int *)*piVar8;
              piStack_580 = (int *)param_1_00[1];
              iVar9 = (**(code **)(*DAT_022b69a8 + 0x80))(DAT_022b69a8);
              if (-1 < iVar9) {
                piStack_580 = (int *)0x0;
                iVar9 = (**(code **)(*piVar8 + 0x4c))(piVar8,0,&iStack_534);
                if (-1 < iVar9) {
                  piStack_580 = (int *)0x0;
                  iVar9 = (**(code **)(*(int *)param_1_00[3] + 0x34))
                                    ((int *)param_1_00[3],&local_53c);
                  fVar4 = _DAT_00748160;
                  if (-1 < iVar9) {
                    if (0 < (int)piStack_564) {
                      fVar3 = (float)_DAT_0074a038;
                      do {
                        puVar10 = (uint *)(iStack_534 * iVar6 + iStack_530);
                        puVar11 = (uint *)((int)local_53c * iVar6 + iStack_538);
                        iVar9 = 0;
                        if (0 < iStack_568) {
                          do {
                            uVar2 = *puVar11;
                            piStack_560 = (int *)(uVar2 & 0xff);
                            local_548 = (float)(int)piStack_560 * fVar3;
                            if ((fVar4 <= (float)(uVar2 >> 0x10 & 0xff) * fVar3) ||
                               (fVar4 < local_548 == (NAN(fVar4) || NAN(local_548)))) {
                              *puVar10 = uVar2 | 0xff000000;
                            }
                            else {
                              *puVar10 = 0;
                            }
                            iVar9 = iVar9 + 1;
                            puVar10 = puVar10 + 1;
                            puVar11 = puVar11 + 1;
                          } while (iVar9 < iStack_568);
                        }
                        iVar6 = iVar6 + 1;
                      } while (iVar6 < (int)piStack_564);
                    }
                    piStack_580 = (int *)0x57c9e2;
                    (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x38))();
                    piStack_580 = (int *)0x0;
                    (**(code **)(*piStack_560 + 0x50))(piStack_560);
                  }
                }
              }
              FUN_0057c210();
              goto LAB_0057c9f9;
            }
          }
        }
      }
    }
  }
  FUN_0057c210();
LAB_0057c9f9:
  pcStack_56c = (char *)0x57ca0b;
  ___security_check_cookie_4();
  return;
LAB_0057c3f8:
  pcVar5 = pcVar5 + 1;
  pcVar7 = param_1;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  if (pcVar7 + -(int)(param_1 + 1) <= pcVar5) goto LAB_0057c40d;
  goto LAB_0057c3d0;
}

