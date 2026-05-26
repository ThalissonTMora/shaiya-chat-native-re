#!/usr/bin/env python3
"""Scan PE32 binary for SConnection_Send @ 0x4ED0E0 with size arg len+0x18."""

from __future__ import annotations

import re
import subprocess
import sys

SEND_VA = 0x4ED0E0
CHAT_OPCODES = {0x1103, 0x1104, 0x1108, 0x1111, 0xF103, 0xF104, 0x812}


def disasm(path: str) -> list[str]:
    return subprocess.check_output(["objdump", "-d", path], text=True, stderr=subprocess.DEVNULL).splitlines()


def scan(lines: list[str]) -> None:
    hits = [i for i, l in enumerate(lines) if re.search(rf"call\s+0x{SEND_VA:x}", l)]
    print(f"SConnection_Send @ 0x{SEND_VA:08X}: {len(hits)} call sites")

    pattern_b: list[tuple[int, set[int], bool, bool]] = []
    for idx in hits:
        ctx = lines[max(0, idx - 80) : idx + 1]
        ctxs = "\n".join(ctx)
        if not re.search(r"add\s+.*0x18", ctxs):
            continue

        ops: set[int] = set()
        for l in ctx:
            for m in re.finditer(r"mov\s+\$0x(11[0-9a-f]{2}|f10[0-9a-f]|812)", l, re.I):
                ops.add(int(m.group(1), 16))

        addr = int(re.match(r"\s*([0-9a-f]+):", lines[idx]).group(1), 16)
        memset21 = bool(re.search(r"push\s+\$0x15", ctxs) and re.search(r"push\s+\$0x0", ctxs))
        rep_stos = "rep stos" in ctxs
        pattern_b.append((addr, ops, memset21, rep_stos))

    chat = [(a, o, m, r) for a, o, m, r in pattern_b if o & CHAT_OPCODES]
    print(f"Pattern B (add +0x18): {len(pattern_b)} total, {len(chat)} chat-tagged")
    print(f"Chat sites with memset(21)/rep stos in 80-insn window: {sum(1 for *_, m, r in chat if m or r)}")

    for addr, ops, m, r in sorted(chat):
        op_s = ",".join(f"0x{o:04X}" for o in sorted(ops)) or "?"
        print(f"  0x{addr:08X} op=[{op_s}] memset21={m} rep_stos={r}")


def main() -> int:
    path = sys.argv[1] if len(sys.argv) > 1 else "bin/ps_game.exe"
    scan(disasm(path))
    return 0


if __name__ == "__main__":
    sys.exit(main())
