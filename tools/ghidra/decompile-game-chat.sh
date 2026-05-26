#!/usr/bin/env bash
# Client: export Game.exe chat → game-chat-native/
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
BINARY="${ROOT}/bin/Game.exe"
MANIFEST="${SCRIPT_DIR}/game-chat-functions.manifest"
PROJECT_DIR="${SCRIPT_DIR}/project-game"
OUTPUT_DIR="${ROOT}/game-chat-native"
GHIDRA_HOME="${GHIDRA_HOME:-$HOME/tools/ghidra_11.2.1_PUBLIC}"
JAVA_HOME="${JAVA_HOME:-$HOME/tools/jdk-21.0.6+7}"

export JAVA_HOME="$JAVA_HOME"
export PATH="$JAVA_HOME/bin:$PATH"
export DISPLAY="${DISPLAY:-}"
export JAVA_TOOL_OPTIONS="-Djava.awt.headless=true"

[[ -f "$BINARY" ]] || { echo "Missing: $BINARY (see docs/BINARIES.md)" >&2; exit 1; }
[[ -f "$MANIFEST" ]] || { echo "Missing: $MANIFEST" >&2; exit 1; }

find "$GHIDRA_HOME" -type f \( -name "decompile" -o -name "*.sh" \) -exec chmod +x {} \; 2>/dev/null || true
rm -rf "${PROJECT_DIR}.lock" 2>/dev/null || true
mkdir -p "$PROJECT_DIR" "$OUTPUT_DIR"

echo "==> [CLIENT] Game.exe → $OUTPUT_DIR"
"$GHIDRA_HOME/support/analyzeHeadless" \
  "$PROJECT_DIR" GameChat \
  -scriptPath "$SCRIPT_DIR/scripts" \
  -import "$BINARY" \
  -processor "x86:LE:32:default" \
  -overwrite -deleteProject \
  -analysisTimeoutPerFile 900 \
  -postScript ExportDecompileByAddress.java "$OUTPUT_DIR" "$MANIFEST"

cp "$MANIFEST" "$OUTPUT_DIR/game-chat-functions.manifest"
echo "==> Done: $(find "$OUTPUT_DIR" -name '*.c' | wc -l) .c files"
