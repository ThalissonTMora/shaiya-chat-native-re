/*
 * Game.exe — UIShell_CinematicPrecheck
 * Requested VA: 0x005705A0
 * Entry Ghidra:  005705a0
 * Ghidra name:   FUN_005705a0
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: ui
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


bool __fastcall FUN_005705a0(int param_1)

{
  int iVar1;
  
  if (DAT_022b69a8 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_022b69a8 + 0x98))(DAT_022b69a8,0);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*(int *)(param_1 + 0x10) + 0x48))
                        ((int *)(param_1 + 0x10),0,(undefined4 *)(param_1 + 0x2d8));
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*DAT_022b69a8 + 0x94))(DAT_022b69a8,0,*(undefined4 *)(param_1 + 0x2d8))
        ;
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*DAT_022b69a8 + 0xa0))(DAT_022b69a8,param_1 + 0x14);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*DAT_022b69a8 + 0x9c))
                              (DAT_022b69a8,*(undefined4 *)(param_1 + 0xf0));
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*DAT_022b69a8 + 0xac))
                                (DAT_022b69a8,0,0,7,0xffffffff,0x3f800000,0);
              return -1 < iVar1;
            }
          }
        }
      }
      return false;
    }
  }
  return false;
}

