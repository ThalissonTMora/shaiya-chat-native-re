#!/usr/bin/env python3
"""
Scan ShaiyaServer MITM/session logs and hex dumps for native chat opcodes.

Usage:
  python3 scan_capture_logs.py /mnt/c/ShaiyaServer/ps_session_redis/captures
  python3 scan_capture_logs.py /path/to/new_capture.log
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

CHAT_OPS = {
    0x1101,
    0x1102,
    0x1103,
    0x1104,
    0x1105,
    0x1107,
    0x1108,
    0x1109,
    0x110A,
    0x110B,
    0x1111,
    0xA101,
    0xA102,
    0xF102,
    0xF107,
    0xF108,
    0xF109,
}


def scan_text(path: Path) -> list[str]:
    out = []
    text = path.read_text(errors="replace")
    for m in re.finditer(r"opcode=0x([0-9A-Fa-f]+)", text):
        op = int(m.group(1), 16)
        if op in CHAT_OPS:
            out.append(f"  opcode {op:#06x} @ {m.group(0)}")
    # Pattern B guild hint in raw hex: 04 11 after length header
    for m in re.finditer(r"raw=([0-9a-fA-F]+)", text):
        h = m.group(1)
        for off in range(0, min(len(h), 200), 2):
            if off + 8 > len(h):
                break
            # u16le 0x1104 = 0411
            if h[off : off + 4].lower() == "0411":
                name_hex = h[off + 4 : off + 4 + 42]
                out.append(f"  possible 0x1104 @ raw+{off//2}: name_hex={name_hex[:42]}...")
                break
    return out


def main() -> int:
    roots = [Path(p) for p in sys.argv[1:]] or [
        Path("/mnt/c/ShaiyaServer/ps_session_redis/captures"),
    ]
    any_hit = False
    for root in roots:
        if not root.exists():
            print(f"missing: {root}")
            continue
        files = [root] if root.is_file() else sorted(root.glob("*.log"))
        for f in files:
            hits = scan_text(f)
            if hits:
                any_hit = True
                print(f"\n=== {f} ===")
                for line in hits[:20]:
                    print(line)
    if not any_hit:
        print("No chat opcodes in scanned logs.")
        print("While playing: capture game port 30800 or hook SConnection_Send @ 0x004ED0E0.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
