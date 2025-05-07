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

Running TODO List ✅
	•	✅ Basic memory and register setup (uint8_t memory[1024], registers[8])
	•	✅ Implemented load_file() to read binary file into memory
	•	✅ Built FDE loop in main() using switch-case
	•	✅ Implemented MOV, ADD, SUB, CMP, JZ, and HALT instructions
	•	✅ Zero flag added and functioning with conditional jumps
	•	✅ Verified instruction decoding and program counter updates
Coming Next
	•	☐ Add support for memory access instructions (LOAD, STORE)
	•	☐ Create an assembler or helper script to write .bin files easily
	•	☐ Implement a debugging mode to inspect register/memory state
	•	☐ Add unit tests or example programs