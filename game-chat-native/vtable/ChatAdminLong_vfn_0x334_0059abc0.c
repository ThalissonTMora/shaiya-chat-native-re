/*
 * Game.exe — ChatAdminLong_vfn_0x334
 * Requested VA: 0x0059ABC0
 * Entry Ghidra:  0059abc0
 * Ghidra name:   FUN_0059abc0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: vtable
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_0059abc0(undefined4 param_1,char *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  bool bVar6;
  char local_408;
  undefined local_407 [1027];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)&local_408;
  local_408 = '\0';
  _memset(local_407,0,0x400);
  _strncpy(&local_408,param_2,0x400);
  pbVar2 = (byte *)_strtok(&local_408,"-");
  pcVar5 = "EVENTMSG";
  do {
    bVar1 = *pbVar2;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_0059ac40:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_0059ac45;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar6 = bVar1 < ((byte *)pcVar5)[1];
    if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_0059ac40;
    pbVar2 = pbVar2 + 2;
    pcVar5 = (char *)((byte *)pcVar5 + 2);
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0059ac45:
  if (iVar3 == 0) {
    pcVar5 = _strtok((char *)0x0,"-");
    uVar4 = FUN_00631bbc(pcVar5);
    pcVar5 = _strtok((char *)0x0,"-");
    if (pcVar5 != (char *)0x0) {
      iVar3 = FUN_00631bbc(pcVar5);
      if (iVar3 != 0) {
        DAT_007c273c = iVar3;
      }
    }
    uVar4 = FUN_00420db0(uVar4);
    FUN_00420c10(&DAT_007c1d38,uVar4);
    FUN_00423150(0x17,0x164,10);
    ___security_check_cookie_4();
    return;
  }
  FUN_00420c10(&DAT_007c1d38,param_2);
  FUN_00423150(0x17,0x164,10);
  ___security_check_cookie_4();
  return;
}

