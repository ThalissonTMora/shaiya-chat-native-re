#!/usr/bin/env bash
# Decompile a subset manifest into an output dir (one binary).
# Usage: ./decompile-mini.sh <game|psgame|pslogin> <manifest-path>
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
TARGET="${1:?usage: decompile-mini.sh game|psgame|pslogin <manifest>}"
MANIFEST="${2:?manifest path required}"

case "$TARGET" in
  game)
    BINARY="${ROOT}/bin/Game.exe"
    OUTPUT_DIR="${ROOT}/game-chat-native"
    PROJECT_DIR="${SCRIPT_DIR}/project-mini-game"
    ;;
  psgame)
    BINARY="${ROOT}/bin/ps_game.exe"
    OUTPUT_DIR="${ROOT}/psgame-chat-native"
    PROJECT_DIR="${SCRIPT_DIR}/project-mini-psgame"
    ;;
  pslogin)
    BINARY="${ROOT}/bin/ps_login.exe"
    OUTPUT_DIR="${ROOT}/pslogin-chat-native"
    PROJECT_DIR="${SCRIPT_DIR}/project-mini-pslogin"
    ;;
  *) echo "Unknown target: $TARGET" >&2; exit 1 ;;
esac

[[ -f "$MANIFEST" ]] || MANIFEST="${SCRIPT_DIR}/${MANIFEST}"
[[ -f "$MANIFEST" ]] || { echo "Missing manifest: $MANIFEST" >&2; exit 1; }

GHIDRA_HOME="${GHIDRA_HOME:-$HOME/tools/ghidra_11.2.1_PUBLIC}"
JAVA_HOME="${JAVA_HOME:-$HOME/tools/jdk-21.0.6+7}"
export JAVA_HOME PATH="$JAVA_HOME/bin:$PATH"
export JAVA_TOOL_OPTIONS="-Djava.awt.headless=true"

[[ -f "$BINARY" ]] || { echo "Missing: $BINARY" >&2; exit 1; }

find "$GHIDRA_HOME" -type f \( -name "decompile" -o -name "*.sh" \) -exec chmod +x {} \; 2>/dev/null || true
rm -rf "${PROJECT_DIR}.lock" 2>/dev/null || true
mkdir -p "$PROJECT_DIR" "$OUTPUT_DIR"

echo "==> [mini/$TARGET] $(basename "$BINARY") manifest=$(basename "$MANIFEST")"
"$GHIDRA_HOME/support/analyzeHeadless" \
  "$PROJECT_DIR" "Mini${TARGET}" \
  -scriptPath "$SCRIPT_DIR/scripts" \
  -import "$BINARY" \
  -processor "x86:LE:32:default" \
  -overwrite -deleteProject \
  -analysisTimeoutPerFile 600 \
  -postScript ExportDecompileByAddress.java "$OUTPUT_DIR" "$MANIFEST"

echo "==> Done"
