import sys
import struct
import re

OPCODE_TABLE = {
    0x01: "MOV",
    0x02: "ADD",
    0x03: "SUB",
    0x04: "CMP",
    0x05: "JE",
    0xFF: "HLT",
}

with open("test.asm", "r") as f:
    lines = f.readlines
