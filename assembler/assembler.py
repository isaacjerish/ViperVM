import sys
import struct
import re

OPCODE_TABLE = {
    "MOV": 0x01,
    "ADD": 0x02,
    "SUB": 0x03,
    "CMP": 0x04,
    "JE": 0x05,
    "HLT": 0xFF,
}
REGISTER_TABLE = {
    "R0": 0x00,
    "R1": 0x01,
    "R2": 0x02,
    "R3": 0x03,
    "R4": 0x04,
    "R5": 0x05,
    "R6": 0x06,
    "R7": 0x07,
}
with open("/Users/isaacjerish/Documents/ViperVM/programs/test.asm", "r") as f:
    lines = f.readlines()
    for line in lines:
        
    print(lines)
