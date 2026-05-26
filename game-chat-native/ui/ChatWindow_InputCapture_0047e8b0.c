/*
 * Game.exe — ChatWindow_InputCapture
 * Requested VA: 0x0047E8B0
 * Entry Ghidra:  0047e8b0
 * Ghidra name:   FUN_0047e8b0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __fastcall FUN_0047e8b0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  size_t _Count;
  char *pcVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int local_210;
  char local_20c [260];
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_210;
  if (((*(char *)(param_1 + 0x75b4) == '\x01') || (DAT_022b24d0 != 1)) || (DAT_022b24d4 != 0)) {
    ___security_check_cookie_4();
    return;
  }
  local_210 = (*(byte *)(param_1 + 0x3b4) + 2) * 0x10;
  if (((*(int *)(param_1 + 4) + 0x19 <= DAT_007c3c0c) &&
      (DAT_007c3c0c <= *(int *)(param_1 + 4) + 0x15e)) &&
     (*(int *)(param_1 + 8) + 0x24 + local_210 <= DAT_007c3c10)) {
    iVar3 = FUN_00420bf0(0);
    puVar7 = (undefined4 *)**(undefined4 **)(DAT_007c06f8 + iVar3 * 0xc + 4);
    iVar3 = FUN_00631be0();
    if (0 < iVar3) {
      do {
        iVar3 = iVar3 + -1;
        puVar7 = (undefined4 *)*puVar7;
      } while (iVar3 != 0);
    }
    iVar6 = 0;
    _memset(local_20c,0,0x104);
    iVar3 = FUN_00420bf0(0);
    if (puVar7 != *(undefined4 **)(DAT_007c06f8 + 4 + iVar3 * 0xc)) {
      do {
        pcVar4 = (char *)puVar7[2];
        iVar3 = ((uint)*(byte *)(param_1 + 0x3cc) - iVar6) * 0x10 + *(int *)(param_1 + 8) + 0x5e +
                local_210;
        if ((iVar3 <= DAT_007c3c10) && (DAT_007c3c10 < iVar3 + 0x10)) {
          _Count = 0;
          do {
            if (pcVar4[_Count] == ':') {
              _strncpy(local_20c,pcVar4,_Count);
              iVar3 = FUN_00420bf0(0);
              puVar7 = *(undefined4 **)(DAT_007c06f8 + 4 + iVar3 * 0xc);
              _Count = 0x104;
            }
            _Count = _Count + 1;
          } while ((int)_Count < 0x104);
        }
        puVar7 = (undefined4 *)*puVar7;
        iVar6 = iVar6 + 1;
        iVar3 = FUN_00420bf0(0);
      } while (puVar7 != *(undefined4 **)(DAT_007c06f8 + 4 + iVar3 * 0xc));
    }
    pcVar4 = local_20c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar3 = FUN_00575740(local_20c,(int)pcVar4 - (int)(local_20c + 1),0);
    if (DAT_007c3c0c <= iVar3 + 0x19) {
      _memset(local_108,0,0x104);
      if (local_20c[0] == '[') {
        piVar8 = &local_210;
        local_210 = 0;
        uVar5 = FUN_00420db0(0x1501,piVar8);
        FUN_0047c190(local_20c + 1,uVar5,piVar8);
        piVar8 = &local_210;
        uVar5 = FUN_00420db0(0x13df,piVar8);
        FUN_0047c190(local_20c + 1,uVar5,piVar8);
        piVar8 = &local_210;
        uVar5 = FUN_00420db0(0x13e0,piVar8);
        FUN_0047c190(local_20c + 1,uVar5,piVar8);
        piVar8 = &local_210;
        uVar5 = FUN_00420db0(0x13e1,piVar8);
        FUN_0047c190(local_20c + 1,uVar5,piVar8);
        piVar8 = &local_210;
        uVar5 = FUN_00420db0(0x150c,piVar8);
        FUN_0047c190(local_20c + 1,uVar5,piVar8);
        iVar3 = local_210;
        if ((local_210 == 0) ||
           (iVar6 = FUN_00575740(&DAT_0074d57c,2,0),
           DAT_007c3c0c < iVar6 + iVar3 + 0x19 + *(int *)(param_1 + 4))) goto LAB_0047ec1d;
        pcVar4 = local_20c;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        iVar6 = (int)pcVar4 - (int)(local_20c + 1);
        iVar3 = 1;
        if (1 < iVar6) {
          do {
            if (local_20c[iVar3] == ']') {
              pcVar4 = local_20c + iVar3 + 1;
              iVar2 = -(int)pcVar4;
              do {
                cVar1 = *pcVar4;
                pcVar4[(int)(local_108 + iVar2)] = cVar1;
                pcVar4 = pcVar4 + 1;
                iVar3 = iVar6;
              } while (cVar1 != '\0');
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
      }
      else {
        iVar3 = 0;
        do {
          pcVar4 = local_20c + iVar3;
          local_108[iVar3] = *pcVar4;
          iVar3 = iVar3 + 1;
        } while (*pcVar4 != '\0');
      }
      FUN_0047c1e0(1);
      pcVar4 = local_108;
      iVar3 = extraout_ECX - (int)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[iVar3 + 0x198] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_0047a4b0();
      ___security_check_cookie_4();
      return;
    }
  }
LAB_0047ec1d:
  ___security_check_cookie_4();
  return;
}

