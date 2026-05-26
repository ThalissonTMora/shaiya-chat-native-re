/*
 * Game.exe — PacketDispatcher_Fallback
 * Requested VA: 0x005F3A3B
 * Entry Ghidra:  005f1e10
 * Ghidra name:   FUN_005f1e10
 * NOTE: VA is inside the function (landmark/hook), not the entry point.
 * MD5: c1edd96639ad81835624b9c4516ac781
 * ImageBase: 0x00400000
 * Category: recv
 * Regenerate: tools/ghidra/decompile-game-chat.sh
 */


void FUN_005f1e10(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff;
  if (uVar1 < 0xc02) {
    if (uVar1 == 0xc01) {
      FUN_005e4600(param_2,0);
      return;
    }
    if (uVar1 < 0x502) {
      if (uVar1 == 0x501) {
        FUN_005e0b90(param_2);
        return;
      }
      if (uVar1 < 0x202) {
        if (uVar1 == 0x201) {
          FUN_005df7d0(param_2);
          return;
        }
        if (uVar1 < 0x102) {
          if (uVar1 == 0x101) {
            FUN_005deec0(param_2);
            return;
          }
          if (uVar1 == 2) {
            FUN_005de880(param_2);
            return;
          }
          if (uVar1 == 4) {
            FUN_005dee90(param_2);
            return;
          }
        }
        else {
          switch(uVar1) {
          case 0x102:
            FUN_005df1d0(param_2);
            return;
          case 0x103:
            FUN_005df230(param_2);
            return;
          case 0x104:
            FUN_005df270(param_2);
            return;
          case 0x105:
            FUN_005df2b0(param_2);
            return;
          case 0x106:
            FUN_005df440(param_2);
            return;
          case 0x107:
            FUN_005de890(param_2);
            return;
          case 0x108:
            FUN_005df580(param_2);
            return;
          case 0x109:
            FUN_005df660(param_2);
            return;
          case 0x10a:
            FUN_005e3960(param_2);
            return;
          case 0x10b:
            FUN_005e39c0(param_2);
            return;
          case 0x10d:
            FUN_005de8b0(param_2);
            return;
          case 0x10e:
            FUN_005df710(param_2);
            return;
          case 0x10f:
            FUN_005e3a20(param_2);
            return;
          case 0x110:
            FUN_005df6e0(param_2);
            return;
          case 0x111:
            goto switchD_005f1e99_caseD_111;
          case 0x112:
            FUN_005df6a0(param_2);
            return;
          case 0x113:
            FUN_005de8c0(param_2);
            return;
          case 0x116:
            FUN_005df770(param_2);
            return;
          case 0x117:
            FUN_005e7160(param_2);
            return;
          case 0x119:
            FUN_005df200(param_2);
            return;
          }
        }
      }
      else if (uVar1 < 0x302) {
        if (uVar1 == 0x301) {
          FUN_005e0760(param_2);
          return;
        }
        switch(uVar1) {
        case 0x202:
          FUN_005df890(param_2);
          return;
        case 0x204:
          FUN_005dfac0(param_2);
          return;
        case 0x205:
          FUN_005e0180(param_2);
          return;
        case 0x206:
          FUN_005e0300(param_2);
          return;
        case 0x207:
          FUN_005e0380(param_2);
          return;
        case 0x208:
          FUN_005e03d0(param_2);
          return;
        case 0x209:
          FUN_005e0460(param_2);
          return;
        case 0x20a:
          FUN_005ea380(param_2);
          return;
        case 0x20b:
          FUN_005e0590(param_2);
          return;
        case 0x20c:
          FUN_005e7ba0(param_2);
          return;
        case 0x20d:
          FUN_005e0620(param_2);
          return;
        case 0x20e:
          FUN_005e0670(param_2);
          return;
        case 0x20f:
          FUN_005e06c0(param_2);
          return;
        case 0x210:
          FUN_005e04d0(param_2);
          return;
        case 0x211:
          FUN_005e0500(param_2);
          return;
        case 0x212:
          FUN_005de8d0(param_2);
          return;
        case 0x213:
          FUN_005e0560(param_2);
          return;
        case 0x214:
          FUN_005e7bf0(param_2);
          return;
        case 0x215:
          FUN_005e7cb0(param_2);
          return;
        case 0x216:
          FUN_005e81a0(param_2);
          return;
        case 0x217:
          FUN_005e81f0(param_2);
          return;
        case 0x218:
          FUN_005e82d0(param_2);
          return;
        case 0x219:
          FUN_005e8320(param_2);
          return;
        case 0x21a:
          FUN_005e8370(param_2);
          return;
        case 0x21b:
          FUN_005e86b0(param_2);
          return;
        case 0x21c:
          FUN_005e8220(param_2);
          return;
        case 0x21d:
          FUN_005e8270(param_2);
          return;
        case 0x21e:
          FUN_005e82a0(param_2);
          return;
        case 0x220:
          FUN_005e8700(param_2);
          return;
        case 0x221:
          FUN_005e87a0(param_2);
          return;
        case 0x222:
          FUN_005e87d0(param_2);
          return;
        case 0x223:
          FUN_005e8820(param_2);
          return;
        case 0x224:
          FUN_005e8850(param_2);
          return;
        case 0x225:
          FUN_005e8f70(param_2);
          return;
        case 0x226:
          FUN_005e1330(param_2);
          return;
        case 0x228:
          FUN_005de8e0(param_2);
          return;
        case 0x229:
          FUN_005e0710(param_2);
          return;
        case 0x22e:
          FUN_005e2aa0(param_2);
          return;
        case 0x22f:
          FUN_005e2b50(param_2);
          return;
        case 0x230:
          FUN_005df740(param_2);
          return;
        }
      }
      else if (uVar1 < 0x402) {
        if (uVar1 == 0x401) {
          FUN_005e09c0(param_2);
          return;
        }
        switch(uVar1) {
        case 0x302:
          FUN_005e08a0(param_2);
          return;
        case 0x303:
          FUN_005df8c0(param_2);
          return;
        case 0x304:
          FUN_005e0900(param_2);
          return;
        case 0x305:
          FUN_005e0970(param_2);
          return;
        case 0x307:
          FUN_005e07e0(param_2);
          return;
        }
      }
      else {
        switch(uVar1) {
        case 0x402:
          FUN_005e0a80(param_2);
          return;
        case 0x403:
          FUN_005e0ab0(param_2);
          return;
        case 0x404:
          FUN_005e0b00(param_2);
          return;
        case 0x405:
          FUN_005e3a60(param_2);
          return;
        case 0x406:
          FUN_005e3bc0(param_2);
          return;
        case 0x451:
          FUN_005e0b30(param_2);
          return;
        }
      }
    }
    else if (uVar1 < 0x602) {
      if (uVar1 == 0x601) {
        FUN_005e2280(param_2);
        return;
      }
      switch(uVar1) {
      case 0x502:
        FUN_005e0cf0(param_2);
        return;
      case 0x503:
        FUN_005e0d80(param_2);
        return;
      case 0x504:
        FUN_005e0e10(param_2);
        return;
      case 0x505:
        FUN_005e0e70(param_2);
        return;
      case 0x506:
        FUN_005e0ee0(param_2);
        return;
      case 0x507:
        FUN_005e1040(param_2);
        return;
      case 0x508:
        FUN_005e10f0(param_2);
        return;
      case 0x509:
        goto switchD_005f1e99_caseD_111;
      case 0x50a:
        FUN_005e12a0(param_2);
        return;
      case 0x50b:
        FUN_005e13b0(param_2);
        return;
      case 0x50c:
        FUN_005e1410(param_2);
        return;
      case 0x50d:
        FUN_005e1460(param_2);
        return;
      case 0x50e:
        FUN_005e14c0(param_2);
        return;
      case 0x50f:
        FUN_005e14f0(param_2);
        return;
      case 0x510:
        FUN_005e1580(param_2);
        return;
      case 0x511:
        FUN_005e15f0(param_2);
        return;
      case 0x512:
        FUN_005e1720(param_2);
        return;
      case 0x513:
        FUN_005e1810(param_2);
        return;
      case 0x514:
        FUN_005e18d0(param_2);
        return;
      case 0x515:
        FUN_005e1980(param_2);
        return;
      case 0x516:
        FUN_005e1a00(param_2);
        return;
      case 0x517:
        FUN_005e1a70(param_2);
        return;
      case 0x518:
        FUN_005e1b30(param_2);
        return;
      case 0x519:
        FUN_005e1c20(param_2);
        return;
      case 0x51a:
        FUN_005e1ce0(param_2);
        return;
      case 0x51b:
        FUN_005e1d90(param_2);
        return;
      case 0x51c:
        FUN_005e35c0(param_2);
        return;
      case 0x51d:
        FUN_005e3bf0(param_2);
        return;
      case 0x51e:
        FUN_005e1190(param_2);
        return;
      case 0x51f:
        FUN_005e1230(param_2);
        return;
      case 0x520:
        FUN_005e1e10(param_2);
        return;
      case 0x521:
        FUN_005e7560(param_2);
        return;
      case 0x522:
        FUN_005e75c0(param_2);
        return;
      case 0x523:
        FUN_005e7d30(param_2);
        return;
      case 0x524:
        FUN_005e3c60(param_2);
        return;
      case 0x525:
        FUN_005e88a0(param_2);
        return;
      case 0x526:
        FUN_005e0f30(param_2);
        return;
      case 0x527:
        FUN_005dec40(param_2);
        return;
      case 0x531:
        FUN_005e4a90(param_2);
        return;
      case 0x532:
        FUN_005e4a30(param_2);
        return;
      case 0x551:
        FUN_005e3cc0(param_2);
        return;
      case 0x554:
        FUN_005e0c60(param_2);
        return;
      case 0x555:
        FUN_005e0cc0(param_2);
        return;
      case 0x558:
        FUN_005e16c0(param_2);
        return;
      }
    }
    else if (uVar1 < 0x702) {
      if (uVar1 == 0x701) {
        FUN_005e25d0(param_2);
        return;
      }
      switch(uVar1) {
      case 0x602:
        FUN_005e2310(param_2);
        return;
      case 0x603:
        FUN_005e2340(param_2);
        return;
      case 0x604:
        FUN_005e23c0(param_2);
        return;
      case 0x605:
        FUN_005e23f0(param_2);
        return;
      case 0x606:
        FUN_005e2480(param_2);
        return;
      case 0x607:
        FUN_005e2540(param_2);
        return;
      case 0x608:
        FUN_005e24e0(param_2);
        return;
      case 0x609:
        FUN_005e3620(param_2);
        return;
      case 0x60b:
        FUN_005e1eb0(param_2);
        return;
      case 0x60c:
        FUN_005e1f80(param_2);
        return;
      case 0x60d:
        FUN_005e2090(param_2);
        return;
      case 0x60e:
        FUN_005e2150(param_2);
        return;
      case 0x60f:
        FUN_005e2200(param_2);
        return;
      case 0x610:
        FUN_005e1e60(param_2);
        return;
      }
    }
    else if (uVar1 < 0xa02) {
      if (uVar1 == 0xa01) {
        FUN_005e4b10(param_2);
        return;
      }
      if (uVar1 < 0x712) {
        if (uVar1 == 0x711) {
          FUN_005e2920(param_2);
          return;
        }
        if (uVar1 == 0x702) {
          FUN_005e2660(param_2);
          return;
        }
        if (uVar1 == 0x703) {
          FUN_005e2710(param_2);
          return;
        }
      }
      else if (uVar1 < 0x831) {
        if (uVar1 == 0x830) {
          FUN_005e27c0(param_2);
          return;
        }
        switch(uVar1) {
        case 0x714:
          FUN_005e2af0(param_2);
          return;
        case 0x801:
          FUN_005e32b0(param_2);
          return;
        case 0x802:
          FUN_005e34e0(param_2);
          return;
        case 0x803:
          FUN_005e94f0(param_2);
          return;
        case 0x804:
          FUN_005e9590(param_2);
          return;
        case 0x805:
          FUN_005e33d0(param_2);
          return;
        case 0x806:
          FUN_005e2bc0(param_2);
          return;
        case 0x807:
          FUN_005e2c40(param_2);
          return;
        case 0x808:
          FUN_005e3200(param_2);
          return;
        case 0x80b:
        case 0x80c:
          FUN_005e2db0(param_2);
          return;
        case 0x80d:
          FUN_005e2f20(param_2);
          return;
        case 0x80e:
          FUN_005e3090(param_2);
          return;
        }
      }
      else {
        switch(uVar1) {
        case 0x831:
          FUN_005e2850(param_2);
          return;
        case 0x832:
        case 0x833:
          FUN_005e28f0(param_2);
          return;
        case 0x901:
          FUN_005e36e0(param_2);
          return;
        case 0x902:
          FUN_005e3760(param_2);
          return;
        case 0x903:
          FUN_005e37b0(param_2);
          return;
        case 0x905:
          FUN_005e38d0(param_2);
          return;
        case 0x906:
          FUN_005e3680(param_2);
          return;
        case 0x907:
          FUN_005e3930(param_2);
          return;
        case 0x909:
          FUN_005e38a0(param_2);
          return;
        }
      }
    }
    else if (uVar1 < 0xb02) {
      if (uVar1 == 0xb01) {
        FUN_005e41d0(param_2);
        return;
      }
      switch(uVar1) {
      case 0xa03:
        FUN_005e4b40(param_2);
        return;
      case 0xa04:
        FUN_005e4b90(param_2);
        return;
      case 0xa05:
        FUN_005e9660(param_2);
        return;
      case 0xa06:
        FUN_005e96b0(param_2);
        return;
      case 0xa07:
        FUN_005e4cf0(param_2);
        return;
      case 0xa08:
        FUN_005e4d40(param_2);
        return;
      case 0xa09:
        FUN_005e4c10(param_2);
        return;
      case 0xa0a:
        FUN_005e4bc0(param_2);
        return;
      }
    }
    else {
      switch(uVar1) {
      case 0xb02:
        FUN_005e4390(param_2);
        return;
      case 0xb03:
      case 0xb15:
        FUN_005e43c0(param_2);
        return;
      case 0xb04:
        FUN_005e4410(param_2);
        return;
      case 0xb05:
        FUN_005e4570(param_2);
        return;
      case 0xb06:
        FUN_005e45a0(param_2);
        return;
      case 0xb07:
        FUN_005e45d0(param_2);
        return;
      case 0xb08:
        FUN_005e4970(param_2,0);
        return;
      case 0xb09:
        FUN_005de900(param_2);
        return;
      case 0xb0b:
        FUN_005e8d40(param_2);
        return;
      case 0xb0c:
        FUN_005e8bd0(param_2);
        return;
      case 0xb0d:
        FUN_005e89e0(param_2);
        return;
      case 0xb0e:
        FUN_005e8960(param_2);
        return;
      case 0xb0f:
        FUN_005e8a10(param_2);
        return;
      case 0xb10:
        FUN_005e8a40(param_2);
        return;
      case 0xb12:
        FUN_005e8a70(param_2);
        return;
      case 0xb13:
        FUN_005e8b10(param_2);
        return;
      case 0xb14:
        FUN_005e8ba0(param_2);
        return;
      case 0xb16:
        FUN_005debd0(param_2);
        return;
      case 0xb17:
        FUN_005e8ae0(param_2);
        return;
      case 0xb18:
        FUN_005debf0(param_2);
        return;
      case 0xb19:
        FUN_005e8b70(param_2);
        return;
      case 0xb1a:
        FUN_005e8b40(param_2);
        return;
      case 0xb1b:
        FUN_005f1b50(param_2);
        return;
      case 0xb1c:
        FUN_005e49d0(param_2);
        return;
      }
    }
  }
  else if (uVar1 < 0xd02) {
    if (uVar1 == 0xd01) {
      FUN_005e69c0(param_2);
      return;
    }
    switch(uVar1) {
    case 0xc02:
      FUN_005e4660(param_2,0);
      return;
    case 0xc03:
      FUN_005e46c0(param_2,0);
      return;
    case 0xc04:
      FUN_005e4730(param_2,0);
      return;
    case 0xc05:
      FUN_005e4790(param_2,0);
      return;
    case 0xc06:
      FUN_005e47f0(param_2,0);
      return;
    case 0xc07:
      FUN_005e4820(param_2,0);
      return;
    case 0xc08:
      FUN_005e48b0(param_2,0);
      return;
    case 0xc09:
      FUN_005e4920(param_2,0);
      return;
    case 0xc0a:
      FUN_005e4600(param_2,1);
      return;
    case 0xc0b:
      FUN_005e4660(param_2,1);
      return;
    case 0xc0c:
      FUN_005e46c0(param_2,1);
      return;
    case 0xc0d:
      FUN_005e48b0(param_2,1);
      return;
    case 0xc0e:
      FUN_005e4730(param_2,1);
      return;
    case 0xc10:
      FUN_005e4790(param_2,1);
      return;
    case 0xc11:
      FUN_005e47f0(param_2,1);
      return;
    case 0xc12:
      FUN_005e4820(param_2,1);
      return;
    case 0xc13:
      FUN_005e4920(param_2,1);
      return;
    case 0xc14:
      FUN_005e4970(param_2,1);
      return;
    }
  }
  else if (uVar1 < 0xe02) {
    if (uVar1 == 0xe01) {
      FUN_005e4e60(param_2);
      return;
    }
    switch(uVar1) {
    case 0xd02:
    case 0xd22:
      FUN_005e6940(param_2);
      return;
    case 0xd03:
      FUN_005e6a90(param_2);
      return;
    case 0xd04:
      FUN_005e6a60(param_2);
      return;
    case 0xd05:
      FUN_005e6ac0(param_2);
      return;
    case 0xd06:
      FUN_005e6af0(param_2);
      return;
    case 0xd07:
      FUN_005e6b40(param_2);
      return;
    case 0xd08:
      FUN_005e6b70(param_2);
      return;
    case 0xd09:
      FUN_005e6bf0(param_2);
      return;
    case 0xd0a:
      FUN_005e6c20(param_2);
      return;
    case 0xd0b:
      FUN_005e6c70(param_2);
      return;
    case 0xd0c:
      FUN_005e6d10(param_2);
      return;
    case 0xd0d:
      FUN_005dea90(param_2);
      return;
    case 0xd0e:
      FUN_005deaa0(param_2);
      return;
    case 0xd0f:
      FUN_005e6d60(param_2);
      return;
    case 0xd10:
      FUN_005e6dd0(param_2);
      return;
    case 0xd11:
      FUN_005e6e30(param_2);
      return;
    case 0xd12:
      FUN_005e6ed0(param_2);
      return;
    case 0xd13:
      FUN_005e6f40(param_2);
      return;
    case 0xd14:
      FUN_005e6fb0(param_2);
      return;
    case 0xd15:
      FUN_005e7020(param_2);
      return;
    case 0xd16:
      FUN_005e7050(param_2);
      return;
    case 0xd17:
      FUN_005e70d0(param_2);
      return;
    case 0xd18:
      FUN_005e7130(param_2);
      return;
    case 0xd19:
      FUN_005e6e60(param_2);
      return;
    case 0xd20:
      FUN_005ea1b0(param_2);
      return;
    case 0xd21:
      FUN_005e9e90(param_2);
      return;
    case 0xd23:
      FUN_005ea210(param_2);
      return;
    case 0xd24:
      FUN_005ea0f0(param_2);
      return;
    case 0xd25:
      FUN_005ea290(param_2);
      return;
    case 0xd26:
      FUN_005e9fb0(param_2);
      return;
    case 0xd27:
      FUN_005e9f20(param_2);
      return;
    case 0xd28:
      FUN_005ea300(param_2);
      return;
    case 0xd29:
      FUN_005e9ae0(param_2);
      return;
    case 0xd2f:
      FUN_005ea000(param_2);
      return;
    case 0xd30:
      FUN_005ea150(param_2);
      return;
    case 0xd31:
      FUN_005e9c30(param_2);
      return;
    case 0xd32:
      FUN_005e9d60(param_2);
      return;
    case 0xd34:
      FUN_005ea240(param_2);
      return;
    case 0xd35:
      FUN_005ea080(param_2);
      return;
    case 0xd36:
      FUN_005e9f80(param_2);
      return;
    case 0xd37:
      FUN_005ea3d0(param_2);
      return;
    case 0xd38:
      FUN_005ea350(param_2);
      return;
    }
  }
  else if (uVar1 < 0xf02) {
    if (uVar1 == 0xf01) {
      FUN_005e4d90(param_2);
      return;
    }
    switch(uVar1) {
    case 0xe02:
      FUN_005e4f10(param_2);
      return;
    case 0xe03:
      FUN_005e4f40(param_2);
      return;
    case 0xe04:
      FUN_005e4fd0(param_2);
      return;
    case 0xe05:
      FUN_005e5000(param_2);
      return;
    case 0xe06:
      FUN_005e5070(param_2);
      return;
    }
  }
  else if (uVar1 < 0x2702) {
    if (uVar1 == 0x2701) {
      FUN_005ea460(param_2);
      return;
    }
    if (uVar1 < 0x2302) {
      if (uVar1 == 0x2301) {
        FUN_005deb50(param_2);
        return;
      }
      if (uVar1 < 0x2102) {
        if (uVar1 == 0x2101) {
          FUN_005e71c0(param_2);
          return;
        }
        if (uVar1 < 0x1102) {
          if (uVar1 == 0x1101) {
            FUN_005e50e0(param_2);
            return;
          }
          if (uVar1 == 0xf02) {
            FUN_005e4e30(param_2);
            return;
          }
        }
        else {
          switch(uVar1) {
          case 0x1102:
            FUN_005e5180(param_2);
            return;
          case 0x1103:
            FUN_005e5250(param_2);
            return;
          case 0x1104:
            FUN_005e5310(param_2);
            return;
          case 0x1105:
            FUN_005e53d0(param_2);
            return;
          case 0x1106:
            FUN_005e5470(param_2);
            return;
          case 0x1107:
            FUN_005e54a0(param_2);
            return;
          case 0x1108:
            FUN_005e5540(param_2);
            return;
          case 0x1109:
            FUN_005e5600(param_2);
            return;
          case 0x110a:
            FUN_005e56f0(param_2);
            return;
          case 0x110b:
            FUN_005e5740(param_2);
            return;
          case 0x1111:
            FUN_005e57d0(param_2);
            return;
          case 0x1112:
            goto switchD_005f2f4e_caseD_1112;
          }
        }
      }
      else if (uVar1 < 0x2202) {
        if (uVar1 == 0x2201) {
          FUN_005e7610(param_2);
          return;
        }
        if (uVar1 == 0x2102) {
          FUN_005e7230(param_2);
          return;
        }
        if (uVar1 == 0x2103) {
          FUN_005e7280(param_2);
          return;
        }
        if (uVar1 == 0x2104) {
          FUN_005e72e0(param_2);
          return;
        }
      }
      else {
        switch(uVar1) {
        case 0x2202:
          FUN_005deb00(param_2);
          return;
        case 0x2203:
          FUN_005e76f0(param_2);
          return;
        case 0x2204:
          FUN_005e7720(param_2);
          return;
        case 0x2205:
          FUN_005e7790(param_2);
          return;
        case 0x2206:
          FUN_005e77c0(param_2);
          return;
        case 0x2207:
          FUN_005e7850(param_2);
          return;
        case 0x2208:
          FUN_005e78a0(param_2);
          return;
        case 0x2209:
          FUN_005e7960(param_2);
          return;
        case 0x220a:
          FUN_005e79c0(param_2);
          return;
        case 0x220b:
          FUN_005e79f0(param_2);
          return;
        case 0x220c:
          FUN_005e7ab0(param_2);
          return;
        case 0x220d:
          FUN_005e7ae0(param_2);
          return;
        case 0x220e:
          FUN_005e7a80(param_2);
          return;
        }
      }
    }
    else if (uVar1 < 0x2402) {
      if (uVar1 == 0x2401) {
        FUN_005e83c0(param_2);
        return;
      }
      switch(uVar1) {
      case 0x2302:
        FUN_005deb60(param_2);
        return;
      case 0x2303:
        FUN_005deb70(param_2);
        return;
      case 0x2304:
        FUN_005deb80(param_2);
        return;
      case 0x2305:
        FUN_005e7dd0(param_2);
        return;
      case 0x2306:
        FUN_005e7e40(param_2);
        return;
      case 0x2307:
        FUN_005e7e70(param_2);
        return;
      case 0x2308:
        FUN_005e7ec0(param_2);
        return;
      case 0x2309:
        FUN_005e7f20(param_2);
        return;
      case 0x230a:
        FUN_005deb90(param_2);
        return;
      case 0x230b:
        FUN_005e7f70(param_2);
        return;
      case 0x230c:
        FUN_005deba0(param_2);
        return;
      case 0x230d:
        FUN_005e7fe0(param_2);
        return;
      case 0x230e:
        FUN_005e8150(param_2);
        return;
      }
    }
    else if (uVar1 < 0x2502) {
      if (uVar1 == 0x2501) {
        FUN_005e8530(param_2);
        return;
      }
      switch(uVar1) {
      case 0x2402:
        FUN_005e8410(param_2);
        return;
      case 0x2403:
        FUN_005e8460(param_2);
        return;
      case 0x2404:
        FUN_005debb0(param_2);
        return;
      case 0x2405:
        FUN_005e84b0(param_2);
        return;
      case 0x2406:
        FUN_005e84e0(param_2);
        return;
      case 0x2407:
        FUN_005e95e0(param_2);
        return;
      case 0x2408:
        FUN_005e9630(param_2);
        return;
      case 0x2409:
        FUN_005e9660(param_2);
        return;
      case 0x240a:
        FUN_005e96b0(param_2);
        return;
      case 0x240b:
        FUN_005e4cf0(param_2);
        return;
      case 0x240c:
        FUN_005e4d40(param_2);
        return;
      case 0x240d:
        FUN_005e4c10(param_2);
        return;
      }
    }
    else if (uVar1 < 0x2602) {
      if (uVar1 == 0x2601) {
        FUN_005e9720(param_2);
        return;
      }
      switch(uVar1) {
      case 0x2502:
        FUN_005e8580(param_2);
        return;
      case 0x2503:
        FUN_005e85d0(param_2);
        return;
      case 0x2504:
        FUN_005debc0(param_2);
        return;
      case 0x2505:
        FUN_005e8630(param_2);
        return;
      case 0x2506:
        FUN_005e8660(param_2);
        return;
      }
    }
    else {
      switch(uVar1) {
      case 0x2602:
        FUN_005e97c0(param_2);
        return;
      case 0x2603:
        FUN_005e91b0(param_2);
        return;
      case 0x2604:
        FUN_005e9260(param_2);
        return;
      case 0x2605:
        FUN_005e9ab0(param_2);
        return;
      case 0x2606:
        FUN_005e90c0(param_2);
        return;
      case 0x2607:
        FUN_005e9150(param_2);
        return;
      case 0x2609:
        FUN_005e9360(param_2);
        return;
      case 0x260c:
        FUN_005e9950(param_2);
        return;
      case 0x260d:
        FUN_005e9920(param_2);
        return;
      case 0x260e:
        FUN_005e99f0(param_2);
        return;
      case 0x2610:
        FUN_005e98a0(param_2);
        return;
      case 0x2611:
        FUN_005e9a20(param_2);
        return;
      case 0x2612:
        FUN_005e9a80(param_2);
        return;
      }
    }
  }
  else if (uVar1 < 0xf102) {
    if (uVar1 == 0xf101) {
      FUN_005e5880(param_2);
      return;
    }
    if (uVar1 < 0xa102) {
      if (uVar1 == 0xa101) {
        FUN_005e3d60(param_2);
        return;
      }
      if (uVar1 < 0x3102) {
        if (uVar1 == 0x3101) {
          FUN_005e7340(param_2);
          return;
        }
        if (uVar1 < 0x2705) {
          if (uVar1 == 0x2704) {
            FUN_005ea430(param_2);
            return;
          }
          if (uVar1 == 0x2702) {
            FUN_005ea5b0(param_2);
            return;
          }
          if (uVar1 == 0x2703) {
            FUN_005ea6d0(param_2);
            return;
          }
        }
        else if (uVar1 == 0x2802) {
          FUN_005e4ae0(param_2);
          return;
        }
      }
      else {
        switch(uVar1) {
        case 0x3102:
          FUN_005e7370(param_2);
          return;
        case 0x3103:
          FUN_005e73d0(param_2);
          return;
        case 0x3104:
          FUN_005e7470(param_2);
          return;
        case 0x3105:
          FUN_005deab0(param_2);
          return;
        case 0x3106:
          FUN_005e74a0(param_2);
          return;
        case 0x3107:
          FUN_005e74d0(param_2);
          return;
        case 0x3108:
          FUN_005e7530(param_2);
          return;
        case 0x3109:
          FUN_005deac0(param_2);
          return;
        case 0x3110:
          FUN_005dead0(param_2);
          return;
        }
      }
    }
    else if (uVar1 < 0xa202) {
      if (uVar1 == 0xa201) {
        FUN_005e3f10(param_2);
        return;
      }
      switch(uVar1) {
      case 0xa102:
        FUN_005e3e10(param_2);
        return;
      case 0xa104:
        FUN_005e3fe0(param_2);
        return;
      case 0xa105:
        FUN_005e3fb0(param_2);
        return;
      case 0xa107:
        FUN_005de8f0(param_2);
        return;
      case 0xa108:
        FUN_005e40b0(param_2);
        return;
      case 0xa109:
        FUN_005e3e90(param_2);
        return;
      }
    }
    else if (uVar1 < 0xb102) {
      if (uVar1 == 0xb101) {
        FUN_005e8fd0(param_2);
        return;
      }
      if (uVar1 < 0xa302) {
        if (uVar1 == 0xa301) {
          FUN_005e4150(param_2);
          return;
        }
        if (uVar1 == 0xa202) {
          FUN_005e4100(param_2);
          return;
        }
      }
      else {
        if (uVar1 == 0xa302) {
          FUN_005ded60(param_2);
          return;
        }
        if (uVar1 == 0xa303) {
          FUN_005dedb0(param_2);
          return;
        }
        if (uVar1 == 0xa305) {
          FUN_005dee20(param_2);
          return;
        }
      }
    }
    else {
      switch(uVar1) {
      case 0xb102:
        FUN_005e9060(param_2);
        return;
      case 0xb103:
        FUN_005e93c0(param_2);
        return;
      case 0xb104:
        FUN_005e9410(param_2);
        return;
      case 0xb105:
        FUN_005e9440(param_2);
        return;
      case 0xb106:
        FUN_005e9470(param_2);
        return;
      }
    }
  }
  else if (uVar1 < 0xf202) {
    if (uVar1 == 0xf201) {
      FUN_005e5c90(param_2);
      return;
    }
    switch(uVar1) {
    case 0xf102:
      FUN_005e5920(param_2);
      return;
    case 0xf103:
      FUN_005e59f0(param_2);
      return;
    case 0xf104:
      FUN_005e5ab0(param_2);
      return;
    case 0xf105:
      FUN_005e5b70(param_2);
      return;
    case 0xf106:
      FUN_005e5c10(param_2);
      return;
    case 0xf107:
      FUN_005de950(param_2);
      return;
    case 0xf109:
      FUN_005de9b0(param_2);
      return;
    case 0xf10a:
switchD_005f2f4e_caseD_1112:
      FUN_005e88d0(param_2);
      return;
    }
  }
  else if (uVar1 < 0xf902) {
    if (uVar1 == 0xf901) {
      FUN_005e6090(param_2);
      return;
    }
    if (uVar1 < 0xf803) {
      if (uVar1 == 0xf802) {
        FUN_005dea50(param_2);
        return;
      }
      if (uVar1 < 0xf604) {
        if (uVar1 == 0xf603) {
          FUN_005e68c0(param_2);
          return;
        }
        if (uVar1 < 0xf602) {
          if (uVar1 == 0xf601) {
            FUN_005e6860(param_2);
            return;
          }
          if (uVar1 == 0xf204) {
            FUN_005e5d80(param_2);
            return;
          }
          if (uVar1 == 0xf501) {
            FUN_005e5db0(param_2);
            return;
          }
        }
        else if (uVar1 == 0xf602) {
          FUN_005e6890(param_2);
          return;
        }
      }
      else {
        if (uVar1 == 0xf701) {
          FUN_005e67e0(param_2);
          return;
        }
        if (uVar1 == 0xf709) {
          FUN_005dea80(param_2);
          return;
        }
        if (uVar1 == 0xf70a) {
          FUN_005e6830(param_2);
          return;
        }
      }
    }
    else {
      switch(uVar1) {
      case 0xf803:
        FUN_005dea60(param_2);
        return;
      case 0xf804:
        FUN_005dea70(param_2);
        return;
      case 0xf805:
        FUN_005e66f0(param_2);
        return;
      case 0xf80b:
        FUN_005e6720(param_2);
        return;
      case 0xf80c:
        FUN_005e6750(param_2);
        return;
      case 0xf80f:
        FUN_005e6780(param_2);
        return;
      case 0xf810:
        FUN_005e67b0(param_2);
        return;
      }
    }
  }
  else if (uVar1 < 0xfa08) {
    if (uVar1 == 0xfa07) {
      FUN_005e5de0(param_2);
      return;
    }
    switch(uVar1) {
    case 0xf904:
      FUN_005e6240(param_2);
      return;
    case 0xf905:
      FUN_005e62d0(param_2);
      return;
    case 0xf906:
      FUN_005e63f0(param_2);
      return;
    case 0xf907:
      FUN_005e6470(param_2);
      return;
    case 0xf908:
      FUN_005e64f0(param_2);
      return;
    case 0xf909:
      FUN_005e6570(param_2);
      return;
    case 0xf90a:
      FUN_005e65f0(param_2);
      return;
    case 0xf90b:
      FUN_005e6670(param_2);
      return;
    case 0xf90c:
      FUN_005e6360(param_2);
      return;
    }
  }
  else {
    switch(uVar1) {
    case 0xfa08:
      FUN_005e5e60(param_2);
      return;
    case 0xfa09:
      FUN_005e5ee0(param_2);
      return;
    case 0xfa0a:
      FUN_005e5f70(param_2);
      return;
    case 0xfa0d:
      FUN_005dea10(param_2);
      return;
    case 0xfa0e:
      FUN_005dea20(param_2);
      return;
    case 0xfa0f:
      FUN_005dea30(param_2);
      return;
    case 0xfa10:
      FUN_005dea40(param_2);
      return;
    case 0xfa11:
      FUN_005e6000(param_2);
      return;
    case 0xfa12:
      FUN_005e6000(param_2);
      return;
    }
  }
  (**(code **)(*DAT_022fa2f0 + 0x684))(param_1,param_2);
switchD_005f1e99_caseD_111:
  return;
}

