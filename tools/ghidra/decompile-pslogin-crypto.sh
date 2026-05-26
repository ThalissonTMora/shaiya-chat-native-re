#!/usr/bin/env bash
# Export ps_login.exe key-path / crypto-wire functions (fast subset)
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
BINARY="${ROOT}/../.features/Shaiya-Core-V7/server/ps_login.exe"
MANIFEST="${SCRIPT_DIR}/pslogin-crypto-functions.manifest"
PROJECT_DIR="${SCRIPT_DIR}/project-pslogin-crypto"
OUTPUT_DIR="${ROOT}/pslogin-chat-native"
GHIDRA_HOME="${GHIDRA_HOME:-$HOME/tools/ghidra_11.2.1_PUBLIC}"
JAVA_HOME="${JAVA_HOME:-$HOME/tools/jdk-21.0.6+7}"

export JAVA_HOME="$JAVA_HOME"
export PATH="$JAVA_HOME/bin:$PATH"
export DISPLAY="${DISPLAY:-}"
export JAVA_TOOL_OPTIONS="-Djava.awt.headless=true"

[[ -f "$BINARY" ]] || { echo "Missing: $BINARY" >&2; exit 1; }
[[ -f "$MANIFEST" ]] || { echo "Missing: $MANIFEST" >&2; exit 1; }

find "$GHIDRA_HOME" -type f \( -name "decompile" -o -name "*.sh" \) -exec chmod +x {} \; 2>/dev/null || true
rm -rf "${PROJECT_DIR}.lock" 2>/dev/null || true
mkdir -p "$PROJECT_DIR" "$OUTPUT_DIR"

echo "==> [ps_login] $(basename "$BINARY") → $OUTPUT_DIR"
"$GHIDRA_HOME/support/analyzeHeadless" \
  "$PROJECT_DIR" PsLoginCrypto \
  -scriptPath "$SCRIPT_DIR/scripts" \
  -import "$BINARY" \
  -processor "x86:LE:32:default" \
  -overwrite -deleteProject \
  -analysisTimeoutPerFile 600 \
  -postScript ExportDecompileByAddress.java "$OUTPUT_DIR" "$MANIFEST"

echo "==> Done: $(find "$OUTPUT_DIR" -name '*.c' 2>/dev/null | wc -l) arquivos .c"
