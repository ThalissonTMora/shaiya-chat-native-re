/*
 * Game.exe — OptionsMenu_WriteTalkBalloonStrings
 * VA solicitado: 0x0051B220
 * Entry Ghidra:  0051b220
 * Ghidra name:   FUN_0051b220
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0051b220(int param_1_00,undefined4 param_1)

{
  int iVar1;
  LPCSTR lpString;
  char *pcVar2;
  char local_20c [260];
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_007b4dd0 ^ (uint)local_20c;
  _memset(local_20c,0,0x104);
  switch(param_1) {
  case 1:
    break;
  case 2:
    DAT_007c0e28 = DAT_022b03dc;
    DAT_007c0e2c = DAT_022b0568;
    DAT_007c0e24 = DAT_022b022c;
    DAT_007c0e30 = (uint)(*(char *)(param_1_00 + 0xbbf3) == '\x01');
    DAT_007c0e34 = (uint)(*(char *)(param_1_00 + 0xc1cb) == '\x01');
    DAT_007c0e38 = (uint)(*(char *)(param_1_00 + 0xc7a3) == '\x01');
    _sprintf(local_20c,"%d",DAT_022b022c);
    WritePrivateProfileStringA("SOUND","VOL_BGM",local_20c,&DAT_007c0720);
    _sprintf(local_20c,"%d",DAT_007c0e28);
    WritePrivateProfileStringA("SOUND","VOL_EFFECT",local_20c,&DAT_007c0720);
    _sprintf(local_20c,"%d",DAT_007c0e2c);
    WritePrivateProfileStringA("SOUND","VOL_WORLD",local_20c,&DAT_007c0720);
    if (DAT_007c0e30 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("SOUND","VOICE_CHAR",pcVar2,&DAT_007c0720);
    if (DAT_007c0e34 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("SOUND","VOICE_NPC",pcVar2,&DAT_007c0720);
    if (DAT_007c0e38 == 0) {
      WritePrivateProfileStringA("SOUND","DANGER_DETECT","FALSE",&DAT_007c0720);
    }
    else {
      WritePrivateProfileStringA("SOUND","DANGER_DETECT","TRUE",&DAT_007c0720);
    }
    goto switchD_0051b25e_caseD_5;
  case 3:
    DAT_007c0e48 = DAT_022b0280;
    DAT_007c0e3c = (uint)(*(char *)(param_1_00 + 0xbbf3) == '\x01');
    DAT_007c0e40 = (uint)(*(char *)(param_1_00 + 0xc1cb) == '\x01');
    DAT_007c0e44 = (uint)(*(char *)(param_1_00 + 0xc7a3) == '\x01');
    DAT_007c0e4c = (uint)(*(char *)(param_1_00 + 0xcd7b) == '\x01');
    DAT_007c0e50 = (uint)(*(char *)(param_1_00 + 0xd353) == '\x01');
    DAT_007c0e54 = (uint)(*(char *)(param_1_00 + 0xd92b) == '\x01');
    DAT_007c0e58 = (uint)(*(char *)(param_1_00 + 0xdf03) == '\x01');
    if (((DAT_007ab0d4 == 0xb) || (DAT_007ab0d4 == 2)) || (DAT_007ab0d4 == 0x11)) {
      DAT_007c0e58 = 1;
    }
    DAT_007c0e5c = (uint)(*(char *)(param_1_00 + 0xe4db) == '\x01');
    DAT_007c0e64 = (uint)(*(char *)(param_1_00 + 0xeab3) == '\x01');
    DAT_007c0e68 = (uint)(*(char *)(param_1_00 + 0xf08b) == '\x01');
    DAT_007c0e6c = (uint)(*(char *)(param_1_00 + 0xf663) == '\x01');
    DAT_007c0e70 = (uint)(*(char *)(param_1_00 + 0xfc3b) == '\x01');
    DAT_007c0e74 = (uint)(*(char *)(param_1_00 + 0x10213) == '\x01');
    DAT_007c0e78 = (uint)(*(char *)(param_1_00 + 0x107eb) == '\x01');
    DAT_007c0e7c = (uint)(*(char *)(param_1_00 + 0x10dc3) == '\x01');
    DAT_007c0e80 = (uint)(*(char *)(param_1_00 + 0x1139b) == '\x01');
    if (DAT_007c0e3c == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","USE_MOUSE",pcVar2,&DAT_007c0720);
    if (DAT_007c0e40 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","INV_MOUSE",pcVar2,&DAT_007c0720);
    if (DAT_007c0e44 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","INV_MOUSE_UPDOWN",pcVar2,&DAT_007c0720);
    _sprintf(local_20c,"%d",DAT_007c0e48);
    WritePrivateProfileStringA("USER","MOUSE_SENSITIVITY",local_20c,&DAT_007c0720);
    if (DAT_007c0e4c == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","MY_NAME",pcVar2,&DAT_007c0720);
    if (DAT_007c0e50 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","USER_NAME",pcVar2,&DAT_007c0720);
    if (DAT_007c0e54 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","MONSTER_NAME",pcVar2,&DAT_007c0720);
    if (DAT_007c0e58 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","USE_FILTER",pcVar2,&DAT_007c0720);
    if (DAT_007c0e5c == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","SHOW_INTERFACE",pcVar2,&DAT_007c0720);
    DAT_007c0de4 = DAT_007c0e5c;
    if (DAT_007c0e64 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","REJECT_FIGHT",pcVar2,&DAT_007c0720);
    if (DAT_007c0e68 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","REJECT_PARTY",pcVar2,&DAT_007c0720);
    if (DAT_007c0e6c == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","WARNING_MSG",pcVar2,&DAT_007c0720);
    if (DAT_007c0e70 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","REJECT_TRADE",pcVar2,&DAT_007c0720);
    if (DAT_007c0e74 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","UI_REOPEN",pcVar2,&DAT_007c0720);
    if (DAT_007c0e78 == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","SCREEN_SWING",pcVar2,&DAT_007c0720);
    if (DAT_007c0e7c == 0) {
      pcVar2 = "FALSE";
    }
    else {
      pcVar2 = "TRUE";
    }
    WritePrivateProfileStringA("USER","TALK_BALLOON",pcVar2,&DAT_007c0720);
    if (DAT_007c0e80 == 0) {
      WritePrivateProfileStringA("USER","HIDE_DAMAGE","FALSE",&DAT_007c0720);
    }
    else {
      WritePrivateProfileStringA("USER","HIDE_DAMAGE","TRUE",&DAT_007c0720);
    }
    goto switchD_0051b25e_caseD_5;
  case 4:
    iVar1 = 0;
    do {
      (&DAT_007c0e8c)[iVar1] = (&DAT_022b0430)[iVar1];
      _sprintf(local_108,"ADD_KEY%d",iVar1);
      _sprintf(local_20c,"%d",(&DAT_007c0e8c)[iVar1]);
      WritePrivateProfileStringA("OPTION",local_108,local_20c,&DAT_007c0720);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    goto switchD_0051b25e_caseD_5;
  case 5:
    iVar1 = 0;
    do {
      (&DAT_007c0eb4)[iVar1] = (&DAT_022b0230)[iVar1];
      _sprintf(local_108,"KEY%d",iVar1);
      _sprintf(local_20c,"%d",(&DAT_007c0eb4)[iVar1]);
      WritePrivateProfileStringA("OPTION",local_108,local_20c,&DAT_007c0720);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x14);
  default:
    goto switchD_0051b25e_caseD_5;
  }
  DAT_007c0d9c = DAT_022b06a4;
  DAT_007c0e00 = DAT_022b0674;
  DAT_007c0e08 = DAT_022b0458;
  DAT_007c0e04 = DAT_022b03d8;
  DAT_007c0e0c = DAT_022b0220;
  DAT_007c0dfc = DAT_022b0224;
  DAT_007c0d90 = (uint)(*(char *)(param_1_00 + 0xbbf3) == '\x01');
  DAT_007c0d8c = (uint)(*(char *)(param_1_00 + 0xc1cb) == '\x01');
  DAT_007c0e10 = (uint)(*(char *)(param_1_00 + 0xc7a3) == '\x01');
  DAT_007c0e14 = (uint)(*(char *)(param_1_00 + 0xcd7b) == '\x01');
  DAT_007c0e18 = (uint)(*(char *)(param_1_00 + 0xd353) == '\x01');
  switch(DAT_022b0224) {
  case 0:
    WritePrivateProfileStringA("VIDEO","SIZE_X","800",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","600",&DAT_007c0720);
    DAT_007ab0e8 = 800;
    DAT_007ab0ec = 600;
    goto LAB_0051b351;
  case 1:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1024",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","768",&DAT_007c0720);
    DAT_007ab0e8 = 0x400;
    DAT_007ab0ec = 0x300;
    goto LAB_0051b351;
  case 2:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1280",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","1024",&DAT_007c0720);
    DAT_007ab0e8 = 0x500;
    goto LAB_0051b667;
  case 3:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1360",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","768",&DAT_007c0720);
    DAT_007ab0ec = 0x300;
    DAT_007ab0e8 = 0x550;
    goto LAB_0051b351;
  case 4:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1920",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","1200",&DAT_007c0720);
    DAT_007ab0e8 = 0x780;
    DAT_007ab0ec = 0x4b0;
    break;
  case 5:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1680",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","1050",&DAT_007c0720);
    DAT_007ab0e8 = 0x690;
    DAT_007ab0ec = 0x41a;
    goto LAB_0051b351;
  case 6:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1280",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","720",&DAT_007c0720);
    DAT_007ab0e8 = 0x500;
    DAT_007ab0ec = 0x2d0;
    break;
  case 7:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1600",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","900",&DAT_007c0720);
    DAT_007ab0e8 = 0x640;
    DAT_007ab0ec = 900;
    break;
  case 8:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1152",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","864",&DAT_007c0720);
    DAT_007ab0e8 = 0x480;
    DAT_007ab0ec = 0x360;
LAB_0051b351:
    if (DAT_007c13a4 != 0) {
      DAT_007ab0d8 = DAT_007ab0e8;
      DAT_007ab0dc = DAT_007ab0ec;
      _DAT_007ab0e0 = DAT_007ab0e8;
      _DAT_007ab0e4 = DAT_007ab0ec;
    }
    goto switchD_0051b314_caseD_e;
  case 9:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1280",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","960",&DAT_007c0720);
    DAT_007ab0e8 = 0x500;
    DAT_007ab0ec = 0x3c0;
    break;
  case 10:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1600",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","1200",&DAT_007c0720);
    DAT_007ab0ec = 0x4b0;
    DAT_007ab0e8 = 0x640;
    break;
  case 0xb:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1920",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","1080",&DAT_007c0720);
    DAT_007ab0e8 = 0x780;
    DAT_007ab0ec = 0x438;
    break;
  case 0xc:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1280",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","800",&DAT_007c0720);
    DAT_007ab0ec = 800;
    DAT_007ab0e8 = 0x500;
    break;
  case 0xd:
    WritePrivateProfileStringA("VIDEO","SIZE_X","1600",&DAT_007c0720);
    WritePrivateProfileStringA("VIDEO","SIZE_Y","1024",&DAT_007c0720);
    DAT_007ab0e8 = 0x640;
LAB_0051b667:
    DAT_007ab0ec = 0x400;
    break;
  default:
    goto switchD_0051b314_caseD_e;
  }
  if (DAT_007c13a4 != 0) {
    DAT_007ab0d8 = DAT_007ab0e8;
    DAT_007ab0dc = DAT_007ab0ec;
    _DAT_007ab0e0 = DAT_007ab0e8;
    _DAT_007ab0e4 = DAT_007ab0ec;
  }
switchD_0051b314_caseD_e:
  if (DAT_007c0d9c == 0) {
    lpString = "16";
  }
  else {
    lpString = "32";
  }
  WritePrivateProfileStringA("VIDEO","COLOR",lpString,&DAT_007c0720);
  _sprintf(local_20c,"%d",DAT_007c0e00);
  WritePrivateProfileStringA("VIDEO","GLOW_LEVEL",local_20c,&DAT_007c0720);
  _sprintf(local_20c,"%d",DAT_007c0e08);
  WritePrivateProfileStringA("VIDEO","GAMMA",local_20c,&DAT_007c0720);
  if (DAT_007c0e04 == 0) {
    pcVar2 = "LOW";
LAB_0051b74c:
    WritePrivateProfileStringA("VIDEO","RANGE",pcVar2,&DAT_007c0720);
  }
  else {
    if (DAT_007c0e04 == 1) {
      pcVar2 = "MIDDLE";
      goto LAB_0051b74c;
    }
    if (DAT_007c0e04 == 2) {
      pcVar2 = "HIGH";
      goto LAB_0051b74c;
    }
  }
  if (DAT_007c0e0c == 0) {
    pcVar2 = "LOW";
LAB_0051b78c:
    WritePrivateProfileStringA("VIDEO","TEXTURE",pcVar2,&DAT_007c0720);
  }
  else {
    if (DAT_007c0e0c == 1) {
      pcVar2 = "MIDDLE";
      goto LAB_0051b78c;
    }
    if (DAT_007c0e0c == 2) {
      pcVar2 = "HIGH";
      goto LAB_0051b78c;
    }
  }
  if (DAT_007c0d90 == 0) {
    pcVar2 = "FALSE";
  }
  else {
    pcVar2 = "TRUE";
  }
  WritePrivateProfileStringA("VIDEO","SHADOW",pcVar2,&DAT_007c0720);
  if (DAT_007c0d8c == 0) {
    pcVar2 = "FALSE";
  }
  else {
    pcVar2 = "TRUE";
  }
  WritePrivateProfileStringA("VIDEO","WATER",pcVar2,&DAT_007c0720);
  if (DAT_007c0e10 == 0) {
    pcVar2 = "FALSE";
  }
  else {
    pcVar2 = "TRUE";
  }
  WritePrivateProfileStringA("VIDEO","CLOAK",pcVar2,&DAT_007c0720);
  if (DAT_007c0e14 == 0) {
    pcVar2 = "FALSE";
  }
  else {
    pcVar2 = "TRUE";
  }
  WritePrivateProfileStringA("VIDEO","HELMET",pcVar2,&DAT_007c0720);
  if (DAT_007c0e18 == 0) {
    WritePrivateProfileStringA("VIDEO","WEAPONEFF","FALSE",&DAT_007c0720);
  }
  else {
    WritePrivateProfileStringA("VIDEO","WEAPONEFF","TRUE",&DAT_007c0720);
  }
switchD_0051b25e_caseD_5:
  ___security_check_cookie_4();
  return;
}

