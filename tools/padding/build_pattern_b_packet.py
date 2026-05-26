#!/usr/bin/env python3
"""Build Pattern B chat plaintext (opcode + name[21] + u8 len + text).

Simulates stock send layout for guild/trade/megaphone/area S→C packets.
Use --tail to compare zero-pad vs garbage vs static stock approximation.
"""

from __future__ import annotations

import argparse
import struct
import sys

NAME_LEN = 21
OPCODES = {
    "guild": 0x1104,
    "trade": 0x1103,
    "megaphone": 0x1108,
    "area": 0x1111,
    "admin_guild": 0xF104,
}


def build_name_field(name: str, tail: str, seed: int) -> bytes:
    raw = name.encode("ascii", errors="replace")
    if len(raw) >= NAME_LEN:
        raise ValueError(f"name max {NAME_LEN - 1} ASCII bytes (+NUL), got {len(raw)}")

    field = bytearray(NAME_LEN)
    field[: len(raw)] = raw
    field[len(raw)] = 0  # copy loop writes trailing NUL from source

    tail_start = len(raw) + 1
    if tail_start >= NAME_LEN:
        return bytes(field)

    if tail == "zero":
        pass  # already zero
    elif tail == "garbage":
        state = seed & 0xFFFFFFFF
        for i in range(tail_start, NAME_LEN):
            state = (state * 1103515245 + 12345) & 0xFFFFFFFF
            field[i] = state & 0xFF
    elif tail == "stock":
        # MSVC debug-fill approximation; real stock = prior stack frame bytes
        for i in range(tail_start, NAME_LEN):
            field[i] = 0xCC
    else:
        raise ValueError(f"unknown tail mode: {tail}")

    return bytes(field)


def build_packet(opcode: int, name: str, text: str, tail: str, seed: int) -> bytes:
    body = text.encode("utf-8", errors="replace")
    if not body:
        raise ValueError("text must be non-empty")
    if len(body) > 0x80:
        raise ValueError("text len > 0x80 rejected by stock server")

    name_field = build_name_field(name, tail, seed)
    pkt = struct.pack("<H", opcode) + name_field + struct.pack("B", len(body)) + body
    return pkt


def main() -> int:
    p = argparse.ArgumentParser(description="Build Pattern B chat plaintext packet")
    p.add_argument("--opcode", default="guild", choices=list(OPCODES.keys()))
    p.add_argument("--name", required=True, help="Sender name (ASCII)")
    p.add_argument("--text", required=True, help="Chat message body")
    p.add_argument(
        "--tail",
        default="stock",
        choices=["zero", "garbage", "stock"],
        help="Fill mode for name[strlen+1..20]",
    )
    p.add_argument("--seed", type=lambda x: int(x, 0), default=0xDEADBEEF)
    p.add_argument("--hex", action="store_true", help="Print full packet hex")
    args = p.parse_args()

    opcode = OPCODES[args.opcode]
    pkt = build_packet(opcode, args.name, args.text, args.tail, args.seed)

    name_off = 2
    name_field = pkt[name_off : name_off + NAME_LEN]
    text_len = pkt[name_off + NAME_LEN]
    text_off = name_off + NAME_LEN + 1

    print(f"opcode:     0x{opcode:04X}")
    print(f"plain_size: {len(pkt)} (= len + 0x18 = {text_len} + 24)")
    print(f"name:       {name_field!r}")
    print(f"tail bytes: {name_field[len(args.name)+1:].hex() or '(empty)'}")
    print(f"text:       {pkt[text_off:].decode('utf-8', errors='replace')!r}")

    if args.hex:
        print(f"packet_hex: {pkt.hex()}")

    # Stock static expectation
    if args.tail == "zero":
        print("\nverdict: emulator-safe padding; NOT stock send path")
    elif args.tail in ("garbage", "stock"):
        print("\nverdict: matches static stock inference (uninit tail on wire)")

    return 0


if __name__ == "__main__":
    sys.exit(main())
