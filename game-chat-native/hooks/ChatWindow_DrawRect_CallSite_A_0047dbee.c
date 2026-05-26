/*
 * Game.exe — ChatWindow_DrawRect_CallSite_A
 * VA solicitado: 0x0047DBEE
 * Entry Ghidra:  0047db70
 * Ghidra name:   FUN_0047db70
 * NOTA: VA dentro da função (landmark/hook), não é entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: hooks
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047db70(int param_1)

{
  char cVar1;
  undefined uVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  char *_Size;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined auStack_5c4 [7];
  undefined local_5bd;
  char *local_5bc;
  int *local_5b8;
  undefined4 *local_5b4;
  uint local_5b0;
  char *local_5ac;
  int local_5a8;
  int local_5a4;
  int local_5a0;
  uint3 local_59c;
  undefined uStack_599;
  uint local_598;
  undefined2 local_594;
  char local_592;
  undefined local_591;
  int local_590 [2];
  byte local_588 [7];
  undefined local_581;
  undefined local_580;
  char local_57f;
  undefined local_57e;
  undefined local_57d;
  undefined local_57c;
  undefined local_57b;
  char local_57a;
  undefined local_579;
  undefined local_578;
  char local_577;
  undefined local_576;
  undefined local_575;
  undefined local_574;
  undefined local_573;
  char local_572;
  undefined local_571;
  undefined local_570;
  char local_56f;
  undefined local_56e;
  undefined local_56d;
  undefined local_56c;
  undefined local_56b;
  undefined local_56a [66];
  char local_528 [264];
  char local_420 [264];
  char local_318 [780];
  uint local_c;
  
  local_c = DAT_007b4dd0 ^ (uint)auStack_5c4;
  if (*(int *)(param_1 + 0x20) == 0) goto LAB_0047e871;
  iVar12 = *(byte *)(param_1 + 0x3cc) + 4;
  iVar9 = *(byte *)(param_1 + 0x3b4) + 2;
  *(undefined4 *)(param_1 + 4) = 0;
  iVar10 = iVar9 * 0x10;
  iVar9 = DAT_007ab0dc + iVar12 * -0x10 + iVar9 * -0x10;
  *(int *)(param_1 + 8) = iVar9 + -0x7c;
  local_5a8 = iVar10;
  if (*(int *)(param_1 + 0x3d0) != 0) {
    FUN_005388e0(0,iVar9 + -0x5c,0x15e,iVar10,0x9a1d1f24,0xff101010,0);
    FUN_005388e0(*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 0x28 + iVar10,0x15e,
                 iVar12 * 0x10,0x9a1d1f24,0xff101010,0);
    FUN_00538c60(1,*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 0x28 + iVar10);
    FUN_00538c60(0,*(int *)(param_1 + 4) + 0x162,*(int *)(param_1 + 8) + 0x28 + iVar10);
  }
  if (*(int *)(param_1 + 0x84) != 0) {
    local_5b0 = DAT_007ab0dc - 0x128;
    _local_59c = *(int *)(param_1 + 4) + 0x17c;
    FUN_0057bd90(0xffffffff,_local_59c,local_5b0);
    local_5b8 = (int *)(param_1 + 0x3a8);
    iVar9 = 0;
    do {
      if (iVar9 < 4) {
        iVar12 = local_5b8[-2];
      }
      else {
        iVar12 = *local_5b8;
      }
      if (iVar12 != 0) {
        FUN_0057bd90(0xffffffff,(&DAT_007ac138)[iVar9 * 2] + _local_59c,
                     (&DAT_007ac13c)[iVar9 * 2] + local_5b0);
      }
      iVar9 = iVar9 + 1;
      local_5b8 = local_5b8 + 1;
    } while (iVar9 < 8);
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    local_5b4 = (undefined4 *)(DAT_007ab0dc + -0x128);
    iVar12 = *(int *)(param_1 + 4) + 0x17c;
    FUN_0057bd90(0xffffffff,iVar12,local_5b4);
    iVar9 = *(int *)(param_1 + 0x194);
    if ((-1 < iVar9) && (iVar9 < 5)) {
      FUN_0057bd90(0xffffffff,(&DAT_007ac178)[iVar9 * 2] + iVar12,
                   (&DAT_007ac17c)[iVar9 * 2] + (int)local_5b4);
    }
    if (*(int *)(param_1 + 0x3d4) != 0) {
      FUN_0057bd90(0xffffffff,DAT_007ac1a0 + iVar12,DAT_007ac1a4 + (int)local_5b4);
    }
  }
  FUN_00551b40(*(undefined4 *)(param_1 + 4),
               (uint)*(byte *)(param_1 + 0x3cc) * 0x10 + *(int *)(param_1 + 8) + 0x4c + iVar10);
  FUN_00551b40(*(undefined4 *)(param_1 + 4),
               (uint)*(byte *)(param_1 + 0x3cc) * 0x10 + *(int *)(param_1 + 8) + 0x5c + iVar10);
  if (*(int *)(param_1 + 0x84) == 1) {
    iVar9 = *(int *)(param_1 + 4);
LAB_0047ddeb:
    local_5b0 = iVar9 + 0x17c;
    iVar9 = DAT_007ab0dc + -0x127;
    uVar4 = FUN_00631be0(iVar9);
    FUN_00551b40(uVar4,iVar9);
  }
  else if (*(int *)(param_1 + 0x80) == 1) {
    iVar9 = *(int *)(param_1 + 4);
    goto LAB_0047ddeb;
  }
  uVar13 = 2;
  do {
    FUN_00555690();
    uVar13 = uVar13 - 1;
  } while (uVar13 != 0);
  FUN_0040fde0();
  local_598 = uVar13;
  iVar9 = FUN_00420be0();
  if (0 < iVar9) {
    local_5b8 = (int *)0x0;
    do {
      iVar9 = FUN_00420c70(local_598);
      if (iVar9 != 0) {
        puVar11 = *(undefined4 **)((int)local_5b8 + DAT_007c06f8 + 4);
        puVar14 = (undefined4 *)*puVar11;
        local_5b0 = local_598 & 0x80000001;
        if ((int)local_5b0 < 0) {
          local_5b0 = (local_5b0 - 1 | 0xfffffffe) + 1;
        }
        local_5b4 = puVar14;
        iVar9 = FUN_00631be0();
        if (0 < iVar9) {
          do {
            iVar9 = iVar9 + -1;
            puVar14 = (undefined4 *)*puVar14;
            local_5b4 = puVar14;
          } while (iVar9 != 0);
        }
        local_5a4 = 0;
        if (puVar14 != puVar11) {
          do {
            pcVar7 = (char *)puVar14[2];
            if (local_5b0 == 0) {
              local_5a0 = ((uint)*(byte *)(param_1 + 0x3b4) - local_5a4) * 0x10 + 0x35 +
                          *(int *)(param_1 + 8);
            }
            else {
              local_5a0 = ((uint)*(byte *)(param_1 + 0x3cc) - local_5a4) * 0x10 +
                          *(int *)(param_1 + 8) + 0x5e + local_5a8;
            }
            iVar9 = FUN_00420750(*(undefined4 *)(pcVar7 + 0x104));
            if (iVar9 != 0) {
              _Size = (char *)0x0;
              pcVar5 = pcVar7;
              do {
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
              } while (cVar1 != '\0');
              pcVar6 = local_5bc;
              if (pcVar5 != pcVar7 + 1) {
LAB_0047df30:
                if (pcVar7[(int)_Size] != '<') goto LAB_0047df55;
                pcVar5 = pcVar7;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if ((pcVar5 + (-1 - (int)(pcVar7 + 1)) <= _Size) ||
                   (pcVar7[(int)(_Size + 1)] != '<')) goto LAB_0047df55;
                pcVar5 = pcVar7;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 + (-1 - (int)(pcVar7 + 1)) < _Size + 7) goto LAB_0047df6d;
                local_588[0] = 0xff;
                local_588[1] = 0xff;
                local_588[2] = 0xff;
                local_588[3] = 0x80;
                local_588[4] = 0xff;
                local_588[5] = 0xff;
                local_581 = 0x80;
                local_580 = 0xff;
                local_57e = 0xff;
                local_57d = 0x40;
                local_57c = 0xff;
                local_57b = 0xff;
                local_579 = 0xff;
                local_578 = 0x80;
                local_576 = 200;
                local_575 = 200;
                local_574 = 0xff;
                local_573 = 0xff;
                local_571 = 0xff;
                local_570 = 0x80;
                local_56e = 0xff;
                local_56d = 0xff;
                local_56c = 0x80;
                local_56b = 0xff;
                local_588[6] = cVar1;
                local_57f = cVar1;
                local_57a = cVar1;
                local_577 = cVar1;
                local_572 = cVar1;
                local_56f = cVar1;
                _memset(local_56a,0,0x3c);
                local_594 = *(undefined2 *)(pcVar7 + (int)(_Size + 2));
                local_592 = pcVar7[(int)(_Size + 4)];
                local_5bc = _Size + 2;
                local_591 = 0;
                local_5ac = (char *)FUN_00631bbc(&local_594);
                pcVar6 = local_5bc;
                if (((int)local_5ac < 1) || (pcVar6 = local_5bc + 3, pcVar7[(int)pcVar6] != 'c'))
                goto LAB_0047df6d;
                local_59c = (uint3)*(ushort *)(pcVar7 + (int)(local_5bc + 4));
                local_5bc = pcVar6;
                local_5bc = (char *)FUN_00631bbc(&local_59c);
                _memset(local_318,0,0x104);
                _memset(local_420,0,0x104);
                _memset(local_528,0,0x104);
                _memcpy(local_318,pcVar7,(size_t)_Size);
                _memcpy(local_420,pcVar7 + (int)(_Size + 8),(size_t)local_5ac);
                pcVar5 = pcVar7;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                uVar8 = extraout_var;
                if (pcVar5 + ((-(int)_Size - (int)(pcVar7 + 1)) - (int)local_5ac) != (char *)0x8 &&
                    -1 < (int)(pcVar5 + ((-(int)_Size - (int)(pcVar7 + 1)) - (int)local_5ac) + -8))
                {
                  pcVar5 = pcVar7;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  _memcpy(local_528,local_5ac + (int)(_Size + 8) + (int)pcVar7,
                          (size_t)(pcVar5 + ((-(int)_Size - (int)(pcVar7 + 1)) - (int)local_5ac) +
                                            -8));
                  uVar8 = extraout_var_00;
                }
                uVar13 = (((byte)pcVar7[0x108] | 0xffffff00) << 8 | (uint)(byte)pcVar7[0x109]) << 8
                         | (uint)(byte)pcVar7[0x10a];
                if (0 < *(int *)(param_1 + 0x75c8)) {
                  iVar9 = (int)local_5bc * 3;
                  uVar13 = ((local_588[iVar9] | 0xffffff00) << 8 | (uint)local_588[iVar9 + 1]) << 8
                           | (uint)local_588[iVar9 + 2];
                }
                local_5bc = (char *)(*(int *)(param_1 + 4) + 0x19);
                pcVar5 = local_318;
                local_5ac = local_318 + 1;
                local_590[0] = 0;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 != local_5ac) {
                  FUN_00573d70(local_5bc,local_5a0,CONCAT31(uVar8,pcVar7[0x108]),pcVar7[0x109],
                               pcVar7[0x10a],local_318,0);
                  pcVar5 = local_318;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  FUN_00575610(local_318,(int)pcVar5 - (int)(local_318 + 1),local_590,0);
                  local_5bc = local_5bc + local_590[0];
                }
                pcVar5 = local_420;
                local_590[0] = 0;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 != local_420 + 1) {
                  FUN_00573e20(local_5bc,local_5a0,uVar13,local_420,0);
                  pcVar5 = local_420;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  FUN_00575610(local_420,(int)pcVar5 - (int)(local_420 + 1),local_590,0);
                  local_5bc = local_5bc + local_590[0];
                }
                pcVar5 = local_528;
                local_590[0] = 0;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if (pcVar5 != local_528 + 1) {
                  FUN_00573d70(local_5bc,local_5a0,pcVar7[0x108],pcVar7[0x109],pcVar7[0x10a],
                               local_528,0);
                  pcVar7 = local_528;
                  do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar1 != '\0');
                  FUN_00575610(local_528,(int)pcVar7 - (int)(local_528 + 1),local_590,0);
                }
                goto LAB_0047df9e;
              }
LAB_0047df6d:
              local_5bc = pcVar6;
              FUN_00573d70(*(int *)(param_1 + 4) + 0x19,local_5a0,pcVar7[0x108],pcVar7[0x109],
                           pcVar7[0x10a],pcVar7,0);
LAB_0047df9e:
              local_5a4 = local_5a4 + 1;
              puVar14 = local_5b4;
            }
            if (local_5b0 == 0) {
              iVar9 = *(byte *)(param_1 + 0x3b4) + 2;
            }
            else {
              iVar9 = *(byte *)(param_1 + 0x3cc) + 4;
            }
          } while ((local_5a4 < iVar9) &&
                  (puVar14 = (undefined4 *)*puVar14, local_5b4 = puVar14,
                  puVar14 != *(undefined4 **)((int)local_5b8 + DAT_007c06f8 + 4)));
        }
      }
      local_5b8 = local_5b8 + 3;
      uVar13 = local_598 + 1;
      local_598 = uVar13;
      iVar9 = FUN_00420be0();
    } while ((int)uVar13 < iVar9);
  }
  iVar9 = local_5a8;
  if ((DAT_0090c988 != 0) && (*(int *)(param_1 + 0x8c) == 0)) {
    FUN_0057b990(0xffffffff,*(int *)(param_1 + 4) + 0x40,
                 (*(byte *)(param_1 + 0x3cc) + 7) * 0x10 + *(int *)(param_1 + 8) + local_5a8,0x200,
                 0x20,0,0x3f800000,_DAT_00748160,_DAT_0074a890);
    uVar15 = _DAT_00748160;
    uVar4 = _DAT_0074815c;
    if (DAT_022b3f4c == 1) {
      uVar15 = _DAT_0074815c;
      uVar4 = 0;
    }
    FUN_0057b990(0xffffffff,*(int *)(param_1 + 4) + 0x14e,
                 (uint)*(byte *)(param_1 + 0x3cc) * 0x10 + *(int *)(param_1 + 8) + 0x6f + iVar9,0x20
                 ,0x20,uVar4,uVar15,_DAT_00748160,0x3f800000);
  }
  if (*(char *)(param_1 + 0x75b6) == '\0') {
    if (DAT_0090c988 != 0) {
      if (*(int *)(param_1 + 0x8c) == 0) {
        FUN_00577860(*(int *)(param_1 + 4) + 0x45,
                     (uint)*(byte *)(param_1 + 0x3cc) * 0x10 + *(int *)(param_1 + 8) + 0x76 + iVar9,
                     0,0,0);
        uVar4 = FUN_00565430();
        uVar4 = FUN_00565350(uVar4);
        _sprintf((char *)(param_1 + 0x90),"%s%s",uVar4);
      }
      goto LAB_0047e51b;
    }
  }
  else {
LAB_0047e51b:
    if ((DAT_0090c988 != 0) && (*(int *)(param_1 + 0x8c) == 0)) {
      local_5bd = 0;
      if (DAT_007ab0d4 == 3) {
        local_5bd = 3;
      }
      FUN_00551b40(*(undefined4 *)(param_1 + 4),
                   (uint)*(byte *)(param_1 + 0x3cc) * 0x10 + *(int *)(param_1 + 8) + 0x61 + iVar9);
      uVar2 = local_5bd;
      uVar4 = FUN_0047a420(*(undefined4 *)(param_1 + 0x194));
      FUN_00575e90(*(int *)(param_1 + 0x6a10) + 7,*(int *)(param_1 + 0x6a14) + 6,0xff,0xff,0xff,
                   uVar2,0x5a,uVar4);
      if (*(char *)(param_1 + 0x75b4) != '\0') {
        FUN_005388e0(*(undefined4 *)(param_1 + 0x6a10),*(int *)(param_1 + 0x6a14) + -0x61,
                     *(int *)(param_1 + 0x6a20) + -6,0x5a,0xcd1d1f24,0xff101010,0);
        iVar10 = *(int *)(param_1 + 0x6a14) + -0x5a;
        iVar9 = 0;
        do {
          if (iVar9 == *(int *)(param_1 + 0x75c0)) {
            uVar4 = FUN_0047a420(iVar9);
            iVar12 = *(int *)(param_1 + 0x6a10);
            uVar15 = 0;
          }
          else {
            uVar4 = FUN_0047a420(iVar9);
            iVar12 = *(int *)(param_1 + 0x6a10);
            uVar15 = 0xff;
          }
          FUN_00575e90(iVar12 + 7,iVar10,0xff,0xff,uVar15,local_5bd,0x5a,uVar4);
          iVar9 = iVar9 + 1;
          iVar10 = iVar10 + 0xf;
        } while (iVar9 < 6);
      }
      if (*(int *)(param_1 + 0x194) == 1) {
        FUN_0057b990(0xffffffff,*(undefined4 *)(param_1 + 0x6a10),*(int *)(param_1 + 0x6a14) + 0x16,
                     0xc0,0x20,_DAT_0074a888,_DAT_00748160,0,_DAT_0074a888);
        if (*(char *)(param_1 + 0x75b6) == '\0') {
          FUN_00575e90(*(int *)(param_1 + 0x6a10) + 0x1c,*(int *)(param_1 + 0x6a14) + 0x1c,0xff,0xff
                       ,0xff,0,0x5a,param_1 + 0x198);
        }
        else {
          FUN_00577860(*(int *)(param_1 + 0x6a10) + 0x1c,*(int *)(param_1 + 0x6a14) + 0x1c,0,0,0);
          uVar4 = FUN_00565430();
          uVar4 = FUN_00565350(uVar4);
          _sprintf((char *)(param_1 + 0x198),"%s%s",uVar4);
        }
        FUN_00551b40(*(int *)(param_1 + 0x6a10) + 0x76,*(int *)(param_1 + 0x6a14) + 0xb);
        if (*(char *)(param_1 + 0x75b5) != '\0') {
          FUN_005388e0(*(undefined4 *)(param_1 + 0x6a10),
                       *(int *)(param_1 + 0x6a14) + *(int *)(param_1 + 0x75b0) * -0xf + 0xf,0x83,
                       *(int *)(param_1 + 0x75b0) * 0xf,0xcd1d1f24,0xff101010,0);
          local_5b0 = *(uint *)(param_1 + 0x75b0);
          local_5b4 = (undefined4 *)**(undefined4 **)(param_1 + 0x75ac);
          local_5a8 = 0;
          piVar3 = (int *)(*(int *)(param_1 + 0x6a14) + local_5b0 * -0xf + 0x16);
          if (0 < (int)local_5b0) {
            do {
              local_5b8 = piVar3;
              iVar9 = *(int *)(param_1 + 0x75c4);
              iVar10 = *(int *)(param_1 + 0x6a10);
              puVar11 = local_5b4 + 2;
              pcVar7 = local_528;
              for (iVar12 = 0x41; iVar12 != 0; iVar12 = iVar12 + -1) {
                *(undefined4 *)pcVar7 = *puVar11;
                puVar11 = puVar11 + 1;
                pcVar7 = pcVar7 + 4;
              }
              if (local_5a8 == iVar9) {
                uVar4 = 0;
              }
              else {
                uVar4 = 0xff;
              }
              FUN_00575e90(iVar10 + 0x1c,local_5b8,0xff,0xff,uVar4,0,0x5a,local_528);
              local_5b8 = (int *)((int)local_5b8 + 0xf);
              local_5b4 = (undefined4 *)*local_5b4;
              local_5a8 = local_5a8 + 1;
              piVar3 = local_5b8;
            } while (local_5a8 < (int)local_5b0);
          }
        }
      }
    }
  }
  FUN_0040fde0();
LAB_0047e871:
  ___security_check_cookie_4();
  return;
LAB_0047df55:
  _Size = _Size + 1;
  pcVar5 = pcVar7;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (pcVar5 + -(int)(pcVar7 + 1) <= _Size) goto LAB_0047df6d;
  goto LAB_0047df30;
}

