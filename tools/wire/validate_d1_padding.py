#!/usr/bin/env python3
"""Validate D1: Pattern B name[21] tail in capture logs is non-zero (stock static)."""

from __future__ import annotations

import re
import sys
from pathlib import Path

PATTERN_B = {0x1103, 0x1104, 0x1108, 0x1111, 0xF104}


def check_line(line: str) -> str | None:
    m = re.search(r"opcode=0x([0-9A-Fa-f]+).*raw=([0-9a-fA-F]+)", line)
    if not m:
        return None
    op = int(m.group(1), 16)
    if op not in PATTERN_B:
        return None
    raw = bytes.fromhex(m.group(2))
    if len(raw) < 2 + 21:
        return f"0x{op:04X}: packet too short"
    name = raw[2 : 2 + 21]
    nul = name.find(0)
    if nul < 0:
        return f"0x{op:04X}: no NUL in name field"
    tail = name[nul + 1 :]
    if not tail:
        return f"0x{op:04X}: no tail bytes after NUL"
    if all(b == 0 for b in tail):
        return f"0x{op:04X}: tail all zeros (emulator pad, not stock)"
    return f"0x{op:04X}: OK tail={tail.hex()} ({len(tail)} B)"


def main() -> int:
    paths = [Path(p) for p in sys.argv[1:]] or [Path("test/captures/ui_session_20260526_static.log")]
    ok = 0
    fail = 0
    for path in paths:
        if not path.exists():
            print(f"missing: {path}")
            fail += 1
            continue
        for line in path.read_text(errors="replace").splitlines():
            if line.startswith("#") or not line.strip():
                continue
            r = check_line(line)
            if r:
                print(f"{path.name}: {r}")
                if "OK tail" in r:
                    ok += 1
                else:
                    fail += 1
    if fail:
        return 1
    print(f"D1 validation: {ok} Pattern B packet(s) with non-zero tail")
    return 0


if __name__ == "__main__":
    sys.exit(main())
