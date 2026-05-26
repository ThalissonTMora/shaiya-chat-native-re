/*
 * server/ps_login.exe — KeyTable_GlobalInit
 * Requested VA: 0x00406380
 * Entry Ghidra:  00406380
 * Ghidra name:   FUN_00406380
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: keypath
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406380(void)

{
  bool bVar1;
  char cVar2;
  DWORD DVar3;
  long lVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined extraout_DL;
  undefined *puVar7;
  char *pcVar8;
  long local_208;
  CHAR local_204 [256];
  undefined local_104 [256];
  int local_4;
  
  local_4 = DAT_0044c528;
  DVar3 = GetPrivateProfileStringA
                    ("SERVER","MaxConnection",(LPCSTR)0x0,local_204,0xff,".\\Config\\ps_login.ini");
  if (DVar3 == 0) {
    DAT_0044dae4 = 0x7fff;
  }
  else {
    lVar4 = _atol(local_204);
    DAT_0044dae4 = (ushort)lVar4;
  }
  DVar3 = GetPrivateProfileStringA
                    ("SERVER","ServerPort",(LPCSTR)0x0,local_204,0xff,".\\Config\\ps_login.ini");
  if (DVar3 == 0) {
    uVar5 = 0x7850;
  }
  else {
    uVar5 = _atol(local_204);
  }
  _DAT_0044dae2 = (undefined2)uVar5;
  bVar1 = FUN_00401770(uVar5 & 0xffff,(uint)DAT_0044dae4);
  if (!bVar1) {
    FUN_00412270((int)DAT_0044e7b4 + 0xe0,"main thread init failed");
    FUN_0042e427(local_4);
    return;
  }
  DVar3 = GetPrivateProfileStringA
                    ("CONNECTION","Session",(LPCSTR)0x0,local_204,0xff,".\\Config\\ps_login.ini");
  if (DVar3 != 0) {
    FUN_00407e50(local_204,':',&local_208);
    if (local_208 == 0) {
      local_208 = 0x78b4;
    }
    cVar2 = FUN_00410380(0x4782f8,extraout_DL,local_104);
    if ((cVar2 == '\0') || (uVar6 = FUN_004119a0(&DAT_00477d30,&DAT_004782f8), (char)uVar6 == '\0'))
    {
      pcVar8 = "session connect failed";
    }
    else {
      FUN_00405680(DAT_0044e7b0,&DAT_0044dae6);
      DVar3 = GetPrivateProfileStringA
                        ("CONNECTION","UserLog",(LPCSTR)0x0,local_204,0xff,".\\Config\\ps_login.ini"
                        );
      if (DVar3 == 0) goto LAB_00406595;
      FUN_00407e50(local_204,':',&local_208);
      cVar2 = FUN_004019b0();
      if (cVar2 != '\0') {
        FUN_004079b0(DAT_0044e7b4,2,&DAT_0044dae6);
        puVar7 = &DAT_00454c74;
        do {
          FUN_00409ae0(0x400,0);
          DAT_00454c70 = DAT_00454c70 + 1;
          puVar7 = puVar7 + 0x84;
        } while ((int)puVar7 < 0x4554b4);
        FUN_004112e0(&DAT_00454c60);
        uVar6 = FUN_00414440(0x477ea0);
        if ((char)uVar6 == '\0') {
          FUN_00412270((int)DAT_0044e7b4 + 0xe0,"InitServer():g_Server.StartAcception");
          FUN_0042e427(local_4);
          return;
        }
        FUN_00405700(DAT_0044e7b0);
        DAT_0047857c = 0;
        FUN_0042e427(local_4);
        return;
      }
      pcVar8 = "userlog connect failed";
    }
    FUN_00412270((int)DAT_0044e7b4 + 0xe0,pcVar8);
    FUN_00411110(0x478568);
    FUN_004136e0(0x476520);
    FUN_004183a0(0x4784e0);
  }
LAB_00406595:
  FUN_0042e427(local_4);
  return;
}

