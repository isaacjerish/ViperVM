# ViperVM

**ViperVM** is a custom-built virtual machine written in C++ with its own assembly language and assembler. It simulates a basic CPU, executes binary machine code, and supports a hand-crafted instruction set.

---

## Features

- Custom instruction set architecture (ISA)
- Register-based virtual CPU with 8 general-purpose registers
- Stack operations (`PUSH`, `POP`, `CALL`, `RET`)
- Arithmetic, logical, and control flow instructions
- Python-based assembler to translate `.asm` into bytecode
- Easy to extend with more instructions, I/O, or debugging tools

---

##  Project Structure
vipervm/
├── vm/           # C++ Virtual Machine source
├── assembler/    # Python Assembler
├── programs/     # .asm test programs
├── docs/         # ISA reference, bytecode format, etc.
├── Makefile
└── README.md