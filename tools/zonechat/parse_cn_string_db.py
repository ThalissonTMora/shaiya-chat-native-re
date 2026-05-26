#!/usr/bin/env python3
"""Parse ps_game data/cn_string.DB into (message_id, text) pairs.

Format recovered from ZoneChat_TableLoader @ 0x00408C70 (ps_game.exe):
  - fscanf(fp, "%d\\n", &message_id)
  - fgets(buf, 0x400, fp); skip lines whose trimmed length is 0
  - stored text capped at 0x80 bytes (loader zero-fills 0x80 then strcpy)

This tool does not ship cn_string.DB; point it at a copy from your server tree.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

FGETS_MAX = 0x400  # CONFIRMED @ 0x00408CE2
STORED_TEXT_MAX = 0x80  # CONFIRMED @ 0x00408D31 (memset length before copy)
FSCANF_LINE = "%d\n"  # CONFIRMED string @ VA 0x0056F424


class ParseError(Exception):
    pass


def _read_id_line(raw: str, line_no: int) -> int:
    s = raw.strip()
    if not s:
        raise ParseError(f"line {line_no}: expected decimal message_id, got blank line")
    try:
        return int(s, 10)
    except ValueError as exc:
        raise ParseError(f"line {line_no}: invalid message_id {s!r}") from exc


def _read_text_line(raw: str, line_no: int) -> str:
    # fgets keeps trailing newline unless file ends without one
    text = raw.rstrip("\r\n")
    if len(text.encode("utf-8", errors="replace")) > STORED_TEXT_MAX:
        raise ParseError(
            f"line {line_no}: text exceeds loader cap of {STORED_TEXT_MAX} bytes "
            f"(got {len(text.encode('utf-8', errors='replace'))})"
        )
    if not text:
        raise ParseError(
            f"line {line_no}: empty text line (loader skips zero-length fgets rows)"
        )
    return text


def parse_cn_string_db(path: Path) -> list[tuple[int, str]]:
    """Return ordered (message_id, text) pairs matching server load semantics."""
    entries: list[tuple[int, str]] = []
    lines = path.read_bytes().splitlines(keepends=True)
    i = 0
    line_no = 1

    while i < len(lines):
        message_id = _read_id_line(lines[i].decode("utf-8", errors="replace"), line_no)
        i += 1
        line_no += 1

        if i >= len(lines):
            raise ParseError(f"line {line_no - 1}: message_id {message_id} missing text line")

        text = _read_text_line(lines[i].decode("utf-8", errors="replace"), line_no)
        i += 1
        line_no += 1

        entries.append((message_id, text))

        # Loader continues until fscanf returns EOF; tolerate trailing blank lines.
        while i < len(lines) and not lines[i].strip():
            i += 1
            line_no += 1

    return entries


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("path", type=Path, help="Path to cn_string.DB")
    ap.add_argument(
        "--format",
        choices=("text", "json", "tsv"),
        default="text",
        help="Output format (default: text)",
    )
    ap.add_argument("--limit", type=int, default=0, help="Max entries to print (0 = all)")
    args = ap.parse_args()

    if not args.path.is_file():
        print(f"error: file not found: {args.path}", file=sys.stderr)
        return 2

    try:
        entries = parse_cn_string_db(args.path)
    except ParseError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1

    if args.limit > 0:
        entries = entries[: args.limit]

    if args.format == "json":
        print(json.dumps([{"id": i, "text": t} for i, t in entries], ensure_ascii=False, indent=2))
    elif args.format == "tsv":
        for i, t in entries:
            print(f"{i}\t{t}")
    else:
        print(f"# entries: {len(entries)} (fgets max {FGETS_MAX}, stored max {STORED_TEXT_MAX})")
        for i, t in entries:
            print(f"{i}: {t}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
