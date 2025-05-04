# ViperVM Instruction Set Architecture (ISA)

## Overview
This document defines the base instruction set for the ViperVM virtual machine. Each instruction is encoded in binary and executed sequentially from memory, unless modified by a jump.

---

## Registers
- **General Purpose**: `R0` to `R7` (8 total)
  - Each register is 8 bits wide.
  - Encoded as values `0x00` to `0x07`.

---

## Memory Model
- **Memory Size**: 1024 bytes (1 KB)
- **Instruction Pointer**: `PC` (program counter)
- **Stack Pointer** *(future use)*: `SP`

---

## Instruction Encoding Format

All instructions begin with a **1-byte opcode**. Additional bytes depend on the instruction type (e.g., registers, immediate values, addresses). All multi-byte values are **big-endian** (high byte first).

---

## Instructions

### 1. `MOV R, IMM`  
- **Opcode**: `0x01`  
- **Format**: `[0x01][reg][imm8]`  
- **Size**: 3 bytes  
- **Description**: Loads the 8-bit immediate value into the specified register.

> Example: `MOV R0, 10` → `0x01 0x00 0x0A`

---

### 2. `ADD R1, R2`  
- **Opcode**: `0x02`  
- **Format**: `[0x02][reg1][reg2]`  
- **Size**: 3 bytes  
- **Description**: Adds the value in `reg2` to `reg1`, result stored in `reg1`.

> Example: `ADD R0, R1` → `0x02 0x00 0x01`

---

### 3. `SUB R1, R2`  
- **Opcode**: `0x03`  
- **Format**: `[0x03][reg1][reg2]`  
- **Size**: 3 bytes  
- **Description**: Subtracts `reg2` from `reg1`, result stored in `reg1`.

> Example: `SUB R0, R1` → `0x03 0x00 0x01`

---

### 4. `CMP R1, R2`  
- **Opcode**: `0x05`  
- **Format**: `[0x05][reg1][reg2]`  
- **Size**: 3 bytes  
- **Description**: Compares values in `reg1` and `reg2`.  
  - Sets the **Zero Flag (ZF)** if they are equal.  
  - No registers are modified.

> Example: `CMP R0, R1` → `0x05 0x00 0x01`

---

### 5. `JE ADDR` (Jump if Equal)  
- **Opcode**: `0x06`  
- **Format**: `[0x06][addr_hi][addr_lo]`  
- **Size**: 3 bytes  
- **Description**: If Zero Flag is set, jump to the absolute address.

> Example: `JE 0x0020` → `0x06 0x00 0x20`

---

### 6. `HLT`  
- **Opcode**: `0xFF`  
- **Format**: `[0xFF]`  
- **Size**: 1 byte  
- **Description**: Halts execution immediately.

> Example: `HLT` → `0xFF`

---

## Notes

- All register IDs are 1 byte (`0x00` for R0, `0x01` for R1, ..., `0x07` for R7).
- Instructions that reference memory addresses use two bytes (big-endian).
- Arithmetic instructions do **not** currently set flags—only `CMP` does.
- No stack or function calls are supported yet (future phase).

---