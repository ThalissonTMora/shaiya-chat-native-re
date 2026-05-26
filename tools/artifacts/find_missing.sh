#!/usr/bin/env bash
# Search user-supplied paths for chat RE missing artifacts (D1–D5).
# Usage: ./find_missing.sh [dir1 dir2 ...]
set -euo pipefail

if [[ $# -eq 0 ]]; then
  echo "Usage: $0 /path/to/server/data [/mnt/c/Server ...]"
  exit 1
fi

echo "==> Searching for cn_string.DB, sysmsg-uni.txt, pcaps..."
found=0
for root in "$@"; do
  [[ -e "$root" ]] || { echo "skip (missing): $root"; continue; }
  echo "--- $root ---"
  find "$root" -type f \
    \( -path '*/.git/*' -o -path '*/node_modules/*' -o -path '*/target/*' \) -prune -o \
    \( \
      -iname 'cn_string.db' -o -iname 'cn_string.DB' \
      -o -iname 'sysmsg-uni.txt' -o -iname 'sysmsg-uni.TXT' \
      -o -iname '*.pcap' -o -iname '*.pcapng' \
    \) -print 2>/dev/null | while read -r f; do
    echo "FOUND: $f ($(wc -c <"$f") bytes)"
    found=1
  done
done

if [[ "$found" == "0" ]]; then
  echo "No target artifacts under given paths."
  echo "See docs/MISSING_ARTIFACTS_SEARCH.md for what to capture in-game."
fi
