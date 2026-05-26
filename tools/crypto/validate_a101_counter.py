#!/usr/bin/env python3
"""
Recompute Game.exe recv-path AES counter material from a captured 0xA101 body.

Formula (static CONFIRMED — see docs/CRYPTO_COUNTER.md, docs/LOGIN_A101_BODY_MAP.md):
  prng = LCG_fill_128(seed)   # seed not on wire — must be captured at handshake
  digest = HMAC_SHA256(SHA256(prng), block_b[0:field_2], key=sha256(prng))
  counter_src = digest[0:16]    # before dword permute @ Crypto_CounterLoad

Without runtime PRNG seed, only the *layout* check runs (field sizes vs blocks).

Usage:
  python3 validate_a101_counter.py --hex <197-byte plaintext hex>
  python3 validate_a101_counter.py --file capture.bin --offset 0
"""
from __future__ import annotations

import argparse
import hashlib
import hmac
import struct
import sys


def parse_a101_plaintext(buf: bytes) -> dict:
    if len(buf) < 197:
        raise ValueError(f"need 197 bytes plaintext, got {len(buf)}")
    opcode = struct.unpack_from("<H", buf, 0)[0]
    if opcode != 0xA101:
        raise ValueError(f"opcode {opcode:#06x} != 0xA101")
    field_0 = buf[2]
    field_1 = buf[3]
    field_2 = buf[4]
    block_a = buf[5:69]
    block_b = buf[69:197]
    return {
        "opcode": opcode,
        "field_0": field_0,
        "field_1": field_1,
        "field_2": field_2,
        "block_a": block_a,
        "block_b": block_b,
    }


def permute_counter_dwords(counter16: bytes) -> bytes:
    """Crypto_CounterLoad dword permute @ 0x40468D (Game.exe)."""
    if len(counter16) != 16:
        raise ValueError("need 16 bytes")
    out = bytearray(16)
    for i in range(4):
        x = struct.unpack_from("<I", counter16, i * 4)[0]
        t = ((x >> 8) & 0xFF00FF00) | ((x << 8) & 0x00FF00FF)
        struct.pack_into("<I", out, i * 4, t & 0xFFFFFFFF)
    return bytes(out)


def derive_digest(prng128: bytes, block_b: bytes, hmac_len: int) -> bytes:
    if len(prng128) != 128:
        raise ValueError("PRNG buffer must be 128 bytes")
    key = hashlib.sha256(prng128).digest()
    msg = block_b[:hmac_len]  # hmac_len = wire field_2
    return hmac.new(key, msg, hashlib.sha256).digest()


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--hex", help="197-byte plaintext as hex (no spaces)")
    ap.add_argument("--file", help="Binary file containing plaintext")
    ap.add_argument("--offset", type=int, default=0, help="Offset in --file")
    ap.add_argument("--prng-hex", help="128-byte PRNG captured at handshake (hex)")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()

    if args.hex:
        buf = bytes.fromhex(args.hex.replace(" ", ""))
    elif args.file:
        data = open(args.file, "rb").read()
        buf = data[args.offset : args.offset + 197]
    else:
        ap.print_help()
        return 1

    pkt = parse_a101_plaintext(buf)
    issues = []
    if pkt["field_0"] != 0:
        issues.append(f"field_0={pkt['field_0']} (expected 0 for recv CounterLoad path)")
    if pkt["field_1"] > 128:
        issues.append(f"field_1={pkt['field_1']} > 128 (block_b append cap)")
    if pkt["field_2"] > 128:
        issues.append(f"field_2={pkt['field_2']} > 128 (HMAC inner cap)")
    if pkt["field_1"] and pkt["block_b"][: pkt["field_1"]] == bytes(pkt["field_1"]):
        issues.append("block_b prefix all-zero (unusual)")

    result = {"packet": {k: (v.hex() if isinstance(v, bytes) else v) for k, v in pkt.items()}, "issues": issues}

    if args.prng_hex:
        prng = bytes.fromhex(args.prng_hex.replace(" ", ""))
        digest = derive_digest(prng, pkt["block_b"], pkt["field_2"])
        result["digest_hex"] = digest.hex()
        result["counter_src_hex"] = digest[:16].hex()
        result["counter_permuted_hex"] = permute_counter_dwords(digest[:16]).hex()
        result["key_seed_hex"] = digest[16:32].hex()
    else:
        result["note"] = "Pass --prng-hex (128 B from BP @ Crypto_PRNGFill) to compute digest/counter"

    if args.json:
        import json

        print(json.dumps(result, indent=2))
    else:
        print("0xA101 plaintext parse:")
        print(f"  field_0={pkt['field_0']} field_1={pkt['field_1']} field_2={pkt['field_2']}")
        print(f"  block_a[0:8]={pkt['block_a'][:8].hex()} …")
        print(f"  block_b[0:8]={pkt['block_b'][:8].hex()} …")
        if issues:
            print("  issues:", "; ".join(issues))
        if "digest_hex" in result:
            print(f"  digest={result['digest_hex']}")
            print(f"  counter_src={result['counter_src_hex']}")
            print(f"  counter_permuted={result['counter_permuted_hex']}")
        else:
            print(f"  {result.get('note', '')}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
