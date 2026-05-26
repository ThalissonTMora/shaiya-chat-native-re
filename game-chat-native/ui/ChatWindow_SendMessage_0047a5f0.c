/*
 * Game.exe — ChatWindow_SendMessage
 * Requested VA: 0x0047A5F0
 * Entry Ghidra:  0047a5f0
 * Ghidra name:   FUN_0047a5f0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void __thiscall FUN_0047a5f0(int param_1_00,char *param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  byte bVar5;
  char local_118 [16];
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_118;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  bVar2 = (char)pcVar3 - ((char)param_1 + '\x01');
  if ((bVar2 != 0) && (bVar2 != 0)) {
    bVar5 = 0;
    do {
      if (param_1[bVar5] != ' ') {
        if (0 < *(int *)(param_1_00 + 0x75c8)) {
          pcVar3 = param_1;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          _sprintf(local_118,"<<%03dc%02d",(int)pcVar3 - (int)(param_1 + 1),
                   *(int *)(param_1_00 + 0x75c8));
          _sprintf(local_108,"%s%s",local_118,param_1);
          FUN_00420c10(param_1,local_108);
          param_1[0x103] = '\0';
          pcVar3 = param_1;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          if ((0x80 < (byte)((int)pcVar3 - (int)(param_1 + 1))) &&
             (uVar4 = (int)pcVar3 - (int)(param_1 + 1) & 0xff, 0x7f < uVar4)) {
            param_1[uVar4] = '\0';
          }
          param_1[0x7f] = '\0';
          pcVar3 = param_1;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          bVar2 = (char)pcVar3 - ((char)param_1 + '\x01');
        }
        switch(*(undefined4 *)(param_1_00 + 0x194)) {
        case 0:
          FUN_005ed060((undefined)DAT_0090d1d8,0,bVar2 + 1,param_1);
          break;
        case 1:
          FUN_005ed160((undefined)DAT_0090d1d8,param_1_00 + 0x198,bVar2 + 1,param_1);
          break;
        case 2:
          FUN_005ed060((undefined)DAT_0090d1d8,3,bVar2 + 1,param_1);
          break;
        case 3:
          FUN_005ed220((undefined)DAT_0090d1d8,3,bVar2 + 1,param_1);
          break;
        case 4:
          FUN_005ed2b0((undefined)DAT_0090d1d8,3,bVar2 + 1,param_1);
          break;
        case 5:
          FUN_005ed340((undefined)DAT_0090d1d8,0,bVar2 + 1,param_1);
        }
        break;
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < bVar2);
  }
  ___security_check_cookie_4();
  return;
}

