/*
 * server/ps_game.exe — ZoneChat_TableLoader
 * Requested VA: 0x00408C70
 * Entry Ghidra:  00408c70
 * Ghidra name:   FUN_00408c70
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Category: lookup
 * Regenerate: tools/ghidra/decompile-psgame-chat.sh
 */


void FUN_00408c70(void)

{
  char cVar1;
  FILE *_File;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 *local_420;
  undefined local_418 [12];
  char local_40c [127];
  char local_38d;
  uint local_8;
  
  local_8 = DAT_0057f7c4 ^ (uint)&local_428;
  _File = _fopen("data/cn_string.DB","rt");
  if (_File == (FILE *)0x0) {
    ___security_check_cookie_4();
    return;
  }
  while( true ) {
    iVar2 = FID_conflict__fscanf(_File,"%d\n",&local_428);
    if (iVar2 == -1) break;
    _memset(local_40c,0x400,0);
    _fgets(local_40c,0x400,_File);
    pcVar3 = local_40c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (pcVar3 != local_40c + 1) {
      local_38d = cVar1;
      puVar4 = (undefined4 *)operator_new(0x84);
      _memset(puVar4 + 1,0,0x80);
      *puVar4 = local_428;
      pcVar3 = local_40c;
      iVar2 = (int)(puVar4 + 1) - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_424 = local_428;
      local_420 = puVar4;
      FUN_0040dce0(local_418,&local_424);
    }
  }
  _fclose(_File);
  ___security_check_cookie_4();
  return;
}

