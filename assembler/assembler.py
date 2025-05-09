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
vals = []
tokens = []
with open("/Users/isaacjerish/Documents/ViperVM/programs/test.asm", "r") as f:
    lines = f.readlines()
    for line in lines:
        vals.append(line.strip().replace(",", "").split(" "))
    for token_list in vals:
        for token in token_list:
            tokens.append(token)
    print(tokens)
bin_vals = []
count = 0
for token in tokens:
    if count == 0:
        if token in OPCODE_TABLE:
            bin_vals.append(hex(OPCODE_TABLE[token]))
            count += 1
        else:
            print(f"Unidentified opcode {token}")
            break
    elif count == 1:
        if token in REGISTER_TABLE:
            bin_vals.append(hex(REGISTER_TABLE[token]))
            count += 1
        else:
            print(f"Unidentified register {token}")
            break
    elif count == 2:
        if token in REGISTER_TABLE:
            bin_vals.append(hex(REGISTER_TABLE[token]))
            count = 0
        elif str(token).isnumeric():
            bin_vals.append(hex(int(token)))
            count = 0
        else:
            print(f"Error with arg 2 parsing. Registered token was {token}")
            break
    else:
        print(
            "Error in logic for deciding what part of the instruction should be operated upon."
        )
print(bin_vals)
