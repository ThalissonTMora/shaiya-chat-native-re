#!/usr/bin/env bash
# Server: export ps_game.exe chat → psgame-chat-native/
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
BINARY="${ROOT}/bin/ps_game.exe"
MANIFEST="${SCRIPT_DIR}/psgame-chat-functions.manifest"
PROJECT_DIR="${SCRIPT_DIR}/project-psgame"
OUTPUT_DIR="${ROOT}/psgame-chat-native"
GHIDRA_HOME="${GHIDRA_HOME:-$HOME/tools/ghidra_11.2.1_PUBLIC}"
JAVA_HOME="${JAVA_HOME:-$HOME/tools/jdk-21.0.6+7}"

export JAVA_HOME="$JAVA_HOME"
export PATH="$JAVA_HOME/bin:$PATH"
export DISPLAY="${DISPLAY:-}"
export JAVA_TOOL_OPTIONS="-Djava.awt.headless=true"

[[ -f "$BINARY" ]] || { echo "Missing: $BINARY (see bin/README.md)" >&2; exit 1; }
[[ -f "$MANIFEST" ]] || { echo "Missing: $MANIFEST" >&2; exit 1; }

find "$GHIDRA_HOME" -type f \( -name "decompile" -o -name "*.sh" \) -exec chmod +x {} \; 2>/dev/null || true
mkdir -p "$PROJECT_DIR" "$OUTPUT_DIR"

echo "==> [SERVER] ps_game.exe → $OUTPUT_DIR"
"$GHIDRA_HOME/support/analyzeHeadless" \
  "$PROJECT_DIR" PsGameChat \
  -scriptPath "$SCRIPT_DIR/scripts" \
  -import "$BINARY" \
  -processor "x86:LE:32:default" \
  -overwrite -deleteProject \
  -analysisTimeoutPerFile 900 \
  -postScript ExportDecompileByAddress.java "$OUTPUT_DIR" "$MANIFEST"

cp "$MANIFEST" "$OUTPUT_DIR/psgame-chat-functions.manifest"
echo "==> Done: $(find "$OUTPUT_DIR" -name '*.c' | wc -l) .c files"
