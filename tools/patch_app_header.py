#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Patch last364 Intel HEX: fill Appl_BootHeader length + crc32 to match Boot.

Boot (Boot_App_IsImageValid):
  - Image at 0x80020000, little-endian header
  - CRC = AUTOSAR / IEEE-802.3 CRC32 over [base, base+length)
    with header crc32 field forced to 0 while computing
  - length must be >= 32 and multiple of 32
  - Unprogrammed bytes inside length are treated as erased PFlash 0x00 (TC3xx)
  - Optional intVec/trapVec (header +16/+20): if non-zero, both set, in APP,
    trap 256-aligned, int 8KB-aligned

Usage (from Debug/ or Release/ after link):
  python ..\\Tools\\patch_app_header.py last364.hex
  python ..\\Tools\\patch_app_header.py last364.hex -o last364_app.hex
"""
from __future__ import annotations

import argparse
import binascii
import sys
from pathlib import Path

APP_START = 0x80020000
APP_END = 0x801FFFFF
HDR_SIZE = 32
ALIGN = 32
MAGIC = 0xA5C3B007
# TC3xx PFlash erase state is 0x00 (not classic NOR 0xFF).
ERASE_BYTE = 0x00


def crc32_autosar(data: bytes, seed: int | None = None) -> int:
    """IEEE-802.3 / AUTOSAR Crc_CalculateCRC32 (matches Infineon CRC32B)."""
    if seed is None:
        return binascii.crc32(data) & 0xFFFFFFFF
    return binascii.crc32(data, seed) & 0xFFFFFFFF


def parse_ihex(text: str) -> dict[int, int]:
    mem: dict[int, int] = {}
    base = 0
    for lineno, raw in enumerate(text.splitlines(), 1):
        line = raw.strip()
        if not line:
            continue
        if not line.startswith(":"):
            raise ValueError(f"line {lineno}: not Intel HEX")
        payload = bytes.fromhex(line[1:])
        if len(payload) < 5:
            raise ValueError(f"line {lineno}: short record")
        count, addr_hi, addr_lo, rtype = payload[0], payload[1], payload[2], payload[3]
        addr = (addr_hi << 8) | addr_lo
        data = payload[4 : 4 + count]
        csum = payload[4 + count]
        if ((sum(payload[: 4 + count]) + csum) & 0xFF) != 0:
            raise ValueError(f"line {lineno}: checksum")
        if rtype == 0x00:
            abs_addr = base + addr
            for i, b in enumerate(data):
                mem[abs_addr + i] = b
        elif rtype == 0x01:
            break
        elif rtype == 0x02:
            if count != 2:
                raise ValueError(f"line {lineno}: bad ESA")
            base = ((data[0] << 8) | data[1]) << 4
        elif rtype == 0x04:
            if count != 2:
                raise ValueError(f"line {lineno}: bad ELA")
            base = ((data[0] << 8) | data[1]) << 16
        elif rtype in (0x03, 0x05):
            continue
        else:
            raise ValueError(f"line {lineno}: unsupported type {rtype:#x}")
    return mem


def u32_le(mem: dict[int, int], addr: int) -> int:
    return (
        mem.get(addr, ERASE_BYTE)
        | (mem.get(addr + 1, ERASE_BYTE) << 8)
        | (mem.get(addr + 2, ERASE_BYTE) << 16)
        | (mem.get(addr + 3, ERASE_BYTE) << 24)
    )


def put_u32_le(mem: dict[int, int], addr: int, value: int) -> None:
    mem[addr] = value & 0xFF
    mem[addr + 1] = (value >> 8) & 0xFF
    mem[addr + 2] = (value >> 16) & 0xFF
    mem[addr + 3] = (value >> 24) & 0xFF


def build_image(mem: dict[int, int]) -> tuple[int, bytearray]:
    app_addrs = [a for a in mem if APP_START <= a <= APP_END]
    if not app_addrs:
        raise SystemExit(f"no bytes in APP window {APP_START:#x}..{APP_END:#x}")

    magic = u32_le(mem, APP_START)
    if magic != MAGIC:
        raise SystemExit(
            f"APP header magic at {APP_START:#x} is {magic:#010x}, expected {MAGIC:#010x}"
        )

    last = max(app_addrs)
    length = last - APP_START + 1
    rem = length % ALIGN
    if rem:
        length += ALIGN - rem
    if length < HDR_SIZE:
        length = HDR_SIZE
    if APP_START + length - 1 > APP_END:
        raise SystemExit("aligned length exceeds APP flash window")

    buf = bytearray(length)
    for i in range(length):
        buf[i] = mem.get(APP_START + i, ERASE_BYTE)
    return length, buf


def compute_crc(buf: bytearray) -> int:
    tmp = bytearray(buf)
    tmp[12] = tmp[13] = tmp[14] = tmp[15] = 0
    return crc32_autosar(bytes(tmp))


def emit_ihex(mem: dict[int, int], path: Path) -> None:
    """Rewrite full HEX from sparse mem (sorted), 16-byte records."""
    if not mem:
        raise SystemExit("empty image")
    addrs = sorted(mem)
    lines: list[str] = []
    cur_ela = None
    i = 0
    n = len(addrs)
    while i < n:
        addr = addrs[i]
        ela = (addr >> 16) & 0xFFFF
        if ela != cur_ela:
            cur_ela = ela
            rec = bytes([0x02, 0x00, 0x00, 0x04, (ela >> 8) & 0xFF, ela & 0xFF])
            csum = ((-(sum(rec))) & 0xFF)
            lines.append(":" + rec.hex().upper() + f"{csum:02X}")
        # pack contiguous run within same 64K page, up to 16 bytes, same high 16 of offset
        page_base = addr & ~0xFFFF
        off = addr & 0xFFFF
        chunk = bytearray()
        a = addr
        while (
            i < n
            and addrs[i] == a
            and (a & ~0xFFFF) == page_base
            and len(chunk) < 16
        ):
            chunk.append(mem[a])
            a += 1
            i += 1
        rec = bytes([len(chunk), (off >> 8) & 0xFF, off & 0xFF, 0x00]) + bytes(chunk)
        csum = ((-(sum(rec))) & 0xFF)
        lines.append(":" + rec.hex().upper() + f"{csum:02X}")
    lines.append(":00000001FF")
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


def patch_hex_in_place(src: Path, dst: Path) -> None:
    text = src.read_text(encoding="ascii", errors="strict")
    mem = parse_ihex(text)
    length, buf = build_image(mem)

    # Boot CRCs the header with length already filled and crc32 forced to 0.
    put_u32_le(mem, APP_START + 8, length)
    for i in range(4):
        buf[8 + i] = (length >> (8 * i)) & 0xFF
    buf[12] = buf[13] = buf[14] = buf[15] = 0
    crc = compute_crc(buf)
    put_u32_le(mem, APP_START + 12, crc)

    buf2 = bytearray(length)
    for i in range(length):
        buf2[i] = mem.get(APP_START + i, ERASE_BYTE)
    if compute_crc(buf2) != crc:
        raise SystemExit("internal CRC verify failed")
    if u32_le(mem, APP_START + 8) != length or u32_le(mem, APP_START + 12) != crc:
        raise SystemExit("header write verify failed")

    emit_ihex(mem, dst)
    entry = u32_le(mem, APP_START + 4)
    print(f"[patch_app_header] {src.name}")
    print(f"  magic  = {MAGIC:#010x}")
    print(f"  entry  = {entry:#010x}")
    print(f"  length = {length:#x} ({length} bytes)")
    print(f"  crc32  = {crc:#010x}")
    print(f"  out    = {dst}")


def main() -> int:
    ap = argparse.ArgumentParser(description="Patch APP header length/crc32 into Intel HEX")
    ap.add_argument(
        "hexfile",
        nargs="?",
        default="last364.hex",
        help="input Intel HEX (default: last364.hex in cwd)",
    )
    ap.add_argument(
        "-o",
        "--output",
        help="output HEX (default: overwrite input)",
    )
    args = ap.parse_args()
    src = Path(args.hexfile)
    if not src.is_file():
        print(f"error: not found: {src.resolve()}", file=sys.stderr)
        return 1
    dst = Path(args.output) if args.output else src
    patch_hex_in_place(src, dst)
    return 0


if __name__ == "__main__":
    sys.exit(main())
