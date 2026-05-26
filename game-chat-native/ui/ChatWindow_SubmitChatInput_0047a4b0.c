/*
 * Game.exe — ChatWindow_SubmitChatInput
 * VA solicitado: 0x0047A4B0
 * Entry Ghidra:  0047a4b0
 * Ghidra name:   FUN_0047a4b0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Categoria: ui
 * Regenerar: tools/ghidra/decompile-game-chat.sh
 */


void __fastcall FUN_0047a4b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  FUN_00564b60(1);
  FUN_005662f0();
  uVar2 = FUN_00565430();
  uVar2 = FUN_00565350(uVar2);
  _sprintf((char *)(param_1 + 0x90),"%s%s",uVar2);
  DAT_0090c988 = 1;
  DAT_007c13c0 = 1;
  FUN_00564b40(0xfa,DAT_007ab0dc + -200);
  switch(*(undefined4 *)(param_1 + 0x194)) {
  case 1:
    break;
  case 2:
    FUN_005663b0(&DAT_022b291c,&DAT_0074d338);
    return;
  case 3:
    FUN_005663b0(&DAT_022b291c,&DAT_0074d334);
    return;
  case 4:
    FUN_005663b0(&DAT_022b291c,&DAT_0074d330);
    return;
  case 5:
    FUN_005663b0(&DAT_022b291c,&DAT_0074d32c);
  default:
    return;
  }
  pcVar3 = (char *)(param_1 + 0x198);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (pcVar3 == (char *)(param_1 + 0x199)) {
    FUN_005663b0(&DAT_022b291c,&DAT_0074d33c);
    return;
  }
  FUN_005663b0(&DAT_022b291c,"! %s ",(char *)(param_1 + 0x198));
  return;
}

