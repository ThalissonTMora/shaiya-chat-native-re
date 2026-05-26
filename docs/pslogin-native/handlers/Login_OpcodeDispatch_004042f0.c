/*
 * server/ps_login.exe — Login_OpcodeDispatch
 * Requested VA: 0x004042F0
 * Entry Ghidra:  004042f0
 * Ghidra name:   FUN_004042f0
 * MD5: de5b348cca36e0585f06be93f013fa6d
 * ImageBase: 0x00400000
 * Category: handlers
 * Regenerate: tools/ghidra/decompile-pslogin-crypto.sh
 */


void __thiscall FUN_004042f0(void *this,int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  void *this_00;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined2 uStack_1c;
  undefined uStack_1a;
  undefined4 uStack_19;
  undefined2 uStack_14;
  undefined4 uStack_12;
  undefined uStack_e;
  undefined uStack_d;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0043eb28;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x404));
  uStack_4 = 0;
  if (*(char *)((int)this + 0x150) != '\0') {
    FUN_0040b5e0(*(ushort **)(param_1 + 4) + 1,**(ushort **)(param_1 + 4) - 2);
  }
  cVar4 = FUN_00410360(this,param_1);
  if (cVar4 != '\0') goto LAB_0040455a;
  iVar2 = *(int *)(param_1 + 4);
  sVar1 = *(short *)(iVar2 + 2);
  if (sVar1 == -0x5eff) {
    if (*(char *)((int)this + 0x150) == '\0') {
      if (*(char *)((int)this + 0x151) == '\0') goto LAB_0040455a;
      if (*(char *)(iVar2 + 4) == -0x80) {
        FUN_00404e60((int)this + 0x13c,(byte *)(iVar2 + 5));
        goto LAB_0040455a;
      }
    }
  }
  else if (sVar1 == -0x5efe) {
    if (*(char *)((int)this + 0x150) != '\0') {
      if (*(int *)((int)this + 0x134) == 0) {
        *(undefined4 *)((int)this + 0x134) = 1;
        pcVar7 = (char *)(iVar2 + 4);
        *(undefined *)(iVar2 + 0x23) = 0;
        *(undefined *)(iVar2 + 0x33) = 0;
        iVar3 = 0x3c0 - (int)pcVar7;
        do {
          cVar4 = *pcVar7;
          pcVar7[(int)this + iVar3] = cVar4;
          pcVar7 = pcVar7 + 1;
        } while (cVar4 != '\0');
        pcVar7 = (char *)(iVar2 + 0x24);
        iVar2 = 0x3e0 - (int)pcVar7;
        do {
          cVar4 = *pcVar7;
          pcVar7[(int)this + iVar2] = cVar4;
          pcVar7 = pcVar7 + 1;
        } while (cVar4 != '\0');
        FUN_00414090((void *)((int)this + 0xd0),2);
      }
      goto LAB_0040455a;
    }
  }
  else if (((sVar1 == -0x5dfe) && (*(int *)((int)this + 0x134) == 3)) &&
          (*(char *)((int)this + 0x138) == -1)) {
    uVar5 = FUN_00407430(&DAT_0044ec50,(int *)&uStack_1c);
    if ((char)uVar5 == '\0') {
      uStack_1a = 0xfe;
    }
    else {
      uVar5 = FUN_004073b0(&DAT_0044ec50);
      if ((char)uVar5 == '\0') {
        uStack_1c = 0xa202;
        uStack_1a = 0xfe;
        uStack_19 = 0;
        FUN_00410ae0(this,(undefined4 *)&uStack_1c,7);
        goto LAB_0040455a;
      }
      uVar6 = FUN_004073d0(&DAT_0044ec50,*(byte *)((int)this + 0x104) < 0xb);
      if ((char)uVar6 == '\0') {
        uStack_1a = 0xfc;
      }
      else {
        uVar6 = FUN_00407400(*(int *)(iVar2 + 5),0x44ec50);
        this_00 = DAT_0044e7b0;
        if ((char)uVar6 != '\0') {
          uStack_12 = *(undefined4 *)((int)this + 0x100);
          *(undefined *)((int)this + 0x138) = 0xfe;
          uStack_14 = 0x703;
          uStack_e = (undefined)param_1;
          uStack_d = (undefined)uStack_1c;
          FUN_00410c10(this_00,(undefined4 *)&uStack_14,8);
          goto LAB_0040455a;
        }
        uStack_1a = 0xfd;
      }
    }
    uStack_1c = 0xa202;
    uStack_19 = 0;
    FUN_00410ae0(this,(undefined4 *)&uStack_1c,7);
    goto LAB_0040455a;
  }
  FUN_00410190(this,9,0);
LAB_0040455a:
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x404));
  ExceptionList = pvStack_c;
  return;
}

