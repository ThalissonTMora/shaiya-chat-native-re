/*
 * Game.exe — ChatWindow_ToggleOpenLayout
 * Requested VA: 0x0047D1F0
 * Entry Ghidra:  0047d1f0
 * Ghidra name:   FUN_0047d1f0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047d1f0(int *param_1)

{
  byte bVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  *(undefined *)(param_1 + 0xed) = 5;
  *(undefined *)(param_1 + 0xf3) = 5;
  pcVar2 = *(code **)(*param_1 + 0xc);
  param_1[0xf5] = 0;
  (*pcVar2)();
  FUN_0054f100();
  bVar1 = *(byte *)(param_1 + 0xed);
  param_1[1] = 0;
  param_1[2] = DAT_007ab0dc + (uint)*(byte *)(param_1 + 0xf3) * -0x10 + (bVar1 + 2) * -0x10 + -0xbc;
  param_1[3] = 0x200;
  param_1[4] = 0x80;
  FUN_0057b560("data/interface","chat.tga",0x200,0x100);
  FUN_0057b560("data/interface","chat_check.tga",0x10,0x10);
  FUN_0057b560("data/interface","chat_icon.tga",0x80,0x40);
  DAT_0090c988 = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  _memset(param_1 + 0x24,0,0x104);
  FUN_0047c1e0(0);
  FUN_00551860(0,0xf,0,0xf,0x40,0x20,0x40,0x16,0,"chat.tga",0x200,0x100,1,0,_DAT_0074a888,0,
               _DAT_0074a888,0,_DAT_0074a888,_DAT_0074a888,_DAT_0074815c,0,_DAT_0074a888,
               _DAT_0074815c,_DAT_0074a88c,0,_DAT_0074a888,_DAT_0074815c,_DAT_0074a88c,0,
               _DAT_0074a888,_DAT_0074a88c,_DAT_00748160,0);
  FUN_00551860(0,0xf,0,0xf,0x10,0x10,0x10,0x10,0,"chat.tga",0x200,0x100,1,0,_DAT_0074d554,
               _DAT_0074a890,_DAT_0074d55c,_DAT_0074d554,_DAT_0074c1dc,_DAT_0074a890,_DAT_0074d55c,
               _DAT_0074c1dc,_DAT_0074d558,_DAT_0074a890,_DAT_0074d55c,_DAT_0074c1dc,_DAT_0074d558,
               _DAT_0074a890,_DAT_0074d55c,_DAT_0074d558,_DAT_0074a888,_DAT_0074a890,_DAT_0074d55c,0
              );
  *(undefined *)(param_1 + 0x1d6d) = 0;
  param_1[0x1d70] = 0;
  *(undefined *)((int)param_1 + 0x75b5) = 0;
  param_1[0x1d71] = -1;
  *(undefined *)((int)param_1 + 0x75b6) = 0;
  *(undefined *)((int)param_1 + 0x75b7) = 0;
  *(undefined *)(param_1 + 0x1d6e) = 0;
  piVar3 = (int *)param_1[0x1d6b];
  iVar4 = *piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(param_1[0x1d6b] + 4) = param_1[0x1d6b];
  param_1[0x1d6c] = 0;
  if (iVar4 != param_1[0x1d6b]) {
                    /* WARNING: Subroutine does not return */
    FUN_006307cd(iVar4);
  }
  _memset(param_1 + 0x66,0,0x104);
  _memset(param_1 + 0xa7,0,0x104);
  uVar5 = _DAT_00748418;
  param_1[0xf4] = 0;
  FUN_00555b70(param_1[1],param_1[2] + 0x20,4,4,0x10,(*(byte *)(param_1 + 0xed) + 2) * 0x10,0x10,
               0x20,0xd,0x13,1,0,_DAT_007483e8,_DAT_007484dc,
               (float)(int)((uint)*(byte *)(param_1 + 0xed) * 0x10 + -6),"scrollbar.tga",0x80,0x40,0
               ,_DAT_0074a888,0,_DAT_00748160,_DAT_0074a888,_DAT_0074815c,0,_DAT_00748160,
               _DAT_0074815c,_DAT_0074a88c,0,_DAT_00748160,0,_DAT_0074a888,_DAT_00748160,0x3f800000,
               _DAT_0074a888,_DAT_0074815c,_DAT_00748160,0x3f800000,_DAT_0074815c,_DAT_0074a88c,
               _DAT_00748160,0x3f800000,_DAT_0074a88c,_DAT_00748160,0,_DAT_00748160,_DAT_0074a88c,
               _DAT_00748160,_DAT_00748160,_DAT_00748160,_DAT_00748160,_DAT_0074a890,0,_DAT_00748160
               ,uVar5,uVar5,0);
  FUN_00554210(0xc);
  FUN_00554250((float)*(int *)(DAT_007c06f8 + 0x18),(float)(*(byte *)(param_1 + 0xed) + 2));
  uVar5 = _DAT_00748418;
  param_1[0xa69] = (uint)*(byte *)(param_1 + 0xed);
  FUN_00555b70(param_1[1],param_1[2] + 0x20,4,(bVar1 + 2) * 0x10 + 0xc,0x10,
               (*(byte *)(param_1 + 0xf3) + 2) * 0x10,0x10,0x20,0xd,0x13,1,0,_DAT_007483e8,
               _DAT_007484dc,(float)(int)((uint)*(byte *)(param_1 + 0xf3) * 0x10 + -6),
               "scrollbar.tga",0x80,0x40,0,_DAT_0074a888,0,_DAT_00748160,_DAT_0074a888,_DAT_0074815c
               ,0,_DAT_00748160,_DAT_0074815c,_DAT_0074a88c,0,_DAT_00748160,0,_DAT_0074a888,
               _DAT_00748160,0x3f800000,_DAT_0074a888,_DAT_0074815c,_DAT_00748160,0x3f800000,
               _DAT_0074815c,_DAT_0074a88c,_DAT_00748160,0x3f800000,_DAT_0074a88c,_DAT_00748160,0,
               _DAT_00748160,_DAT_0074a88c,_DAT_00748160,_DAT_00748160,_DAT_00748160,_DAT_00748160,
               _DAT_0074a890,0,_DAT_00748160,uVar5,uVar5,0);
  FUN_00554210(0xc);
  FUN_00554250((float)*(int *)(DAT_007c06f8 + 0x1c),(float)(*(byte *)(param_1 + 0xf3) + 4));
  uVar5 = _DAT_00748160;
  param_1[0xa6a] = (uint)*(byte *)(param_1 + 0xf3);
  FUN_00551860(0,0,0,0,0x20,0x20,0x16,0x16,0,"chat_icon.tga",0x80,0x40,0,0,_DAT_0074815c,0,uVar5,0,
               _DAT_0074815c,0,uVar5,0,_DAT_0074815c,0,uVar5,0,_DAT_0074815c,0,uVar5,0,_DAT_0074815c
               ,0,uVar5,0);
  FUN_00551860(0,0,0,0,0x20,0x20,0x16,0x16,0,"chat_icon.tga",0x80,0x40,0,_DAT_0074815c,_DAT_00748160
               ,0,_DAT_00748160,_DAT_0074815c,_DAT_00748160,0,_DAT_00748160,_DAT_0074815c,
               _DAT_00748160,0,_DAT_00748160,_DAT_0074815c,_DAT_00748160,0,_DAT_00748160,
               _DAT_0074815c,_DAT_00748160,0,_DAT_00748160,0);
  FUN_00551860(0,0,0,0,0x20,0x20,0x16,0x16,0,"talk1_close_button.tga",0x80,0x20,1,0,_DAT_0074815c,0,
               0x3f800000,_DAT_0074815c,_DAT_00748160,0,0x3f800000,_DAT_00748160,_DAT_00748164,0,
               0x3f800000,0,0,0,0,0,0,0,0,0);
  GetAsyncKeyState(0xd);
  GetAsyncKeyState(0x20);
  param_1[0x1d6f] = 0;
  param_1[0x1d72] = 0;
  param_1[0xf6] = 0;
  FUN_00420ca0(0);
  param_1[0x1d73] = -1;
  piVar3 = (int *)param_1[0x1d6b];
  iVar4 = *piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(param_1[0x1d6b] + 4) = param_1[0x1d6b];
  param_1[0x1d6c] = 0;
  if (iVar4 != param_1[0x1d6b]) {
                    /* WARNING: Subroutine does not return */
    FUN_006307cd(iVar4);
  }
  return;
}

