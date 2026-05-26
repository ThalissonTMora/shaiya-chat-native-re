#!/usr/bin/env python3
"""
Scan a binary blob (or raw TCP payload dump) for Shaiya chat-related opcodes.

Use after decrypting game traffic to plaintext, or on login socket before XOR
(0xA101 is plaintext on login per WIRE_CRYPTO.md).

Usage:
  python3 extract_plaintext_opcodes.py --file capture.bin
  python3 extract_plaintext_opcodes.py --file capture.bin --opcodes 1104,A101,F108
  python3 extract_plaintext_opcodes.py --hex 041104...
"""
from __future__ import annotations

import argparse
import struct
import sys

DEFAULT_OPCODES = {
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


def iter_u16le_hits(buf: bytes, opcodes: set[int]) -> list[tuple[int, int]]:
    hits = []
    for i in range(0, max(0, len(buf) - 1)):
        op = struct.unpack_from("<H", buf, i)[0]
        if op in opcodes:
            hits.append((i, op))
    return hits


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--file", help="Binary file to scan")
    ap.add_argument("--hex", help="Hex string to scan")
    ap.add_argument(
        "--opcodes",
        help="Comma-separated hex opcodes (default: chat + admin + A101)",
    )
    ap.add_argument("--context", type=int, default=32, help="Hex dump bytes after hit")
    args = ap.parse_args()

    if args.file:
        buf = open(args.file, "rb").read()
    elif args.hex:
        buf = bytes.fromhex(args.hex.replace(" ", ""))
    else:
        ap.print_help()
        return 1

    if args.opcodes:
        opcodes = {int(x.strip(), 16) for x in args.opcodes.split(",")}
    else:
        opcodes = DEFAULT_OPCODES

    hits = iter_u16le_hits(buf, opcodes)
    if not hits:
        print("No opcode hits.")
        return 0

    for off, op in hits:
        end = min(len(buf), off + 2 + args.context)
        snippet = buf[off:end]
        print(f"offset={off:#x} opcode={op:#06x} next={snippet.hex()}")
        if op == 0x1104 and off + 25 <= len(buf):
            name = buf[off + 2 : off + 23]
            nul = name.find(0)
            tail = name[nul + 1 :] if nul >= 0 else b""
            print(f"  char[21] name={name!r} tail_after_nul={tail.hex() if tail else '(none)'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
