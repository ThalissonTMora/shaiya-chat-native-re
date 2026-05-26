/*
 * server/ps_game.exe — SendQueue_Mode5_NpcTable
 * VA solicitado: 0x00427F80
 * Entry Ghidra:  00427f80
 * Ghidra name:   FUN_00427f80
 * MD5: 91b212afbe6623382713772489dc82ce
 * ImageBase: 0x00400000
 * Categoria: queue
 * Regenerar: tools/ghidra/decompile-psgame-chat.sh
 */


void __fastcall FUN_00427f80(undefined4 param_1_00,undefined4 param_2,int param_1)

{
  int iVar1;
  char cVar2;
  short *psVar3;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined2 local_110;
  undefined local_10e;
  char local_10d [255];
  undefined local_e;
  uint local_4;
  
  local_4 = DAT_0057f7c4 ^ (uint)&local_11c;
  iVar1 = *(int *)(param_1 + 4);
  local_11c = *(undefined4 *)(iVar1 + 9);
  local_118 = *(undefined4 *)(iVar1 + 0xd);
  local_114 = *(undefined4 *)(iVar1 + 0x11);
  if (((((int)(uint)*(ushort *)(iVar1 + 4) < DAT_01009674) &&
       (psVar3 = (short *)(DAT_01009678 + (uint)*(ushort *)(iVar1 + 4) * 0x10c), *psVar3 != 0)) &&
      (*(int *)(psVar3 + 0x18) != 0)) &&
     (((psVar3[0x11] != 0 && (psVar3 != (short *)0x0)) &&
      (cVar2 = FUN_004245a0(param_2), cVar2 != '\0')))) {
    local_10e = 0;
    local_10d[0] = '\0';
    local_e = 0;
    local_110 = 0x80e;
    _sprintf(local_10d,"gm cmd mmakeall ok : %s, %d",psVar3 + 1,(uint)*(byte *)(iVar1 + 6));
    local_10e = 0;
    FUN_004ed2d0(&local_110,0x103);
  }
  ___security_check_cookie_4();
  return;
}

