#!/usr/bin/env python3
"""
Emit chat_capture_live.log from static RE (Pattern B stock tail) for a UI test session.

Used when live x64dbg capture is unavailable: packets match scan_pattern_b_sends.py +
build_pattern_b_packet.py --tail stock (MSVC uninit stack approximation 0xCC).

Usage:
  python3 emit_session_capture.py --name JACKSON --text teste -o test/captures/ui_session.log
  python3 emit_session_capture.py --deploy /mnt/c/ShaiyaServer/PSM_Client/Bin/chat_capture_live.log
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BUILD = ROOT / "tools" / "padding" / "build_pattern_b_packet.py"

# UI session (May 2026) — RX Pattern B from server echo; TX sizes from PACKET_SPEC
SESSION = [
    ("TX", 0x1101, "C→S normal (opcode + charId + len + text) — not Pattern B"),
    ("RX", 0x1101, "S→C normal echo"),
    ("TX", 0x1102, "C→S whisper (21 B target + len + text)"),
    ("RX", 0x1102, "S→C whisper Pattern C"),
    ("RX", 0x1103, "trade", "trade"),
    ("RX", 0x1111, "area", "area"),
    ("RX", 0x1104, "guild", "guild"),
]


def run_build(opcode_key: str, name: str, text: str) -> tuple[bytes, int]:
    cmd = [
        sys.executable,
        str(BUILD),
        "--opcode",
        opcode_key,
        "--name",
        name,
        "--text",
        text,
        "--tail",
        "stock",
        "--hex",
    ]
    out = subprocess.check_output(cmd, text=True, cwd=ROOT)
    hex_line = next(l for l in out.splitlines() if l.startswith("packet_hex:"))
    raw = bytes.fromhex(hex_line.split(":", 1)[1].strip())
    size = len(raw)
    return raw, size


def line_tx_1101(text: str) -> str:
    # Minimal stock C→S: u16 0x1101 + u32 charId placeholder + u8 len + text
    body = text.encode("utf-8")
    char_id = (0x00000001).to_bytes(4, "little")
    pkt = (0x1101).to_bytes(2, "little") + char_id + bytes([len(body)]) + body
    return f"TX opcode=0x1101 len={len(pkt)} source=static_infer raw={pkt.hex()}"


def line_rx_1101(name: str, text: str) -> str:
    # Pattern A recv: opcode + u32 id + u8 len + text (no char[21])
    body = text.encode("utf-8")
    char_id = (0x00000001).to_bytes(4, "little")
    pkt = (0x1101).to_bytes(2, "little") + char_id + bytes([len(body)]) + body
    return f"RX opcode=0x1101 len={len(pkt)} name={name} source=static_infer raw={pkt.hex()}"


def line_tx_1102(name: str, text: str) -> str:
    # Whisper send: 21 B field (5 dwords + byte) — zeros in static infer for target slot
    body = text.encode("utf-8")
    name_field = bytearray(21)
    raw_name = name.encode("ascii", errors="replace")[:20]
    name_field[: len(raw_name)] = raw_name
    pkt = (0x1102).to_bytes(2, "little") + bytes(name_field) + bytes([len(body)]) + body
    return f"TX opcode=0x1102 len={len(pkt)} source=static_infer raw={pkt.hex()}"


def line_rx_1102(name: str, text: str) -> str:
    body = text.encode("utf-8")
    name_field = bytearray(21)
    raw_name = name.encode("ascii", errors="replace")[:20]
    name_field[: len(raw_name)] = raw_name
    # Pattern C: opcode + u8 dir + name[21] + len + text
    pkt = (0x1102).to_bytes(2, "little") + bytes([1]) + bytes(name_field) + bytes([len(body)]) + body
    return f"RX opcode=0x1102 len={len(pkt)} dir=1 source=static_infer raw={pkt.hex()}"


def emit(name: str, text: str, extra_text: str | None = None) -> list[str]:
    lines = [
        "# shaiya-chat-native-re static session capture",
        "# source: emit_session_capture.py + build_pattern_b_packet.py --tail stock",
        f"# player={name!r} text={text!r} ui_channels=normal,whisper,trade,area,guild",
        "# D1: guild/trade/area name[21] tail = 0xCC.. (not zeroed) per ps_game.exe RE",
        "",
    ]
    t2 = extra_text or text
    lines.append(line_tx_1101("olá" if text == "teste" else text))
    lines.append(line_rx_1101(name, "olá" if text == "teste" else text))
    lines.append(line_tx_1101(text))
    lines.append(line_rx_1101(name, text))
    lines.append(line_tx_1102(name, text))
    lines.append(line_rx_1102(name, text))

    for op_key, label in [("trade", "trade"), ("area", "area"), ("guild", "guild")]:
        raw, size = run_build(op_key, name, text)
        op = int.from_bytes(raw[:2], "little")
        tail = raw[2 + len(name) + 1 : 2 + 21]
        lines.append(
            f"RX opcode=0x{op:04X} len={size} channel={label} "
            f"name_tail={tail.hex()} source=static_stock raw={raw.hex()}"
        )

    return lines


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--name", default="JACKSON")
    ap.add_argument("--text", default="teste")
    ap.add_argument("-o", "--output", type=Path, default=ROOT / "test/captures/ui_session_20260526_static.log")
    ap.add_argument("--deploy", type=Path, help="Also write to live path (e.g. ShaiyaServer Bin)")
    args = ap.parse_args()

    lines = emit(args.name, args.text)
    body = "\n".join(lines) + "\n"
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(body, encoding="utf-8")
    print(f"wrote {args.output} ({len(lines)} lines)")

    if args.deploy:
        args.deploy.parent.mkdir(parents=True, exist_ok=True)
        args.deploy.write_text(body, encoding="utf-8")
        print(f"deployed {args.deploy}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
