#!/usr/bin/env bash
# Export crypto/wire functions only (fast subset)
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
GHIDRA_HOME="${GHIDRA_HOME:-$HOME/tools/ghidra_11.2.1_PUBLIC}"
JAVA_HOME="${JAVA_HOME:-$HOME/tools/jdk-21.0.6+7}"

export JAVA_HOME="$JAVA_HOME"
export PATH="$JAVA_HOME/bin:$PATH"
export DISPLAY="${DISPLAY:-}"
export JAVA_TOOL_OPTIONS="-Djava.awt.headless=true"

GAME_BIN="${ROOT}/bin/Game.exe"
PS_BIN="${ROOT}/bin/ps_game.exe"
GAME_OUT="${ROOT}/game-chat-native"
PS_OUT="${ROOT}/psgame-chat-native"

for b in "$GAME_BIN" "$PS_BIN"; do
  [[ -f "$b" ]] || { echo "Missing: $b (see docs/BINARIES.md)" >&2; exit 1; }
done

find "$GHIDRA_HOME" -type f \( -name "decompile" -o -name "*.sh" \) -exec chmod +x {} \; 2>/dev/null || true

run_one() {
  local name="$1" binary="$2" manifest="$3" out="$4"
  local proj="${SCRIPT_DIR}/project-crypto-${name}"
  rm -rf "${proj}.lock" 2>/dev/null || true
  mkdir -p "$proj" "$out"
  echo "==> [$name] $(basename "$binary") → $out/crypto"
  "$GHIDRA_HOME/support/analyzeHeadless" \
    "$proj" "Crypto${name}" \
    -scriptPath "$SCRIPT_DIR/scripts" \
    -import "$binary" \
    -processor "x86:LE:32:default" \
    -overwrite -deleteProject \
    -analysisTimeoutPerFile 600 \
    -postScript ExportDecompileByAddress.java "$out" "$manifest"
  echo "==> [$name] $(find "$out/crypto" -name '*.c' 2>/dev/null | wc -l) files"
}

run_one CLIENT "$GAME_BIN" "${SCRIPT_DIR}/crypto-functions.manifest" "$GAME_OUT"
run_one SERVER "$PS_BIN" "${SCRIPT_DIR}/crypto-server-functions.manifest" "$PS_OUT"
echo "==> Done"
