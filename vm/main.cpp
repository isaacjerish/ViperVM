#include<iostream>
#include <cstdint>
#include <fstream> 
uint8_t memory[1024];
uint8_t registers[8];
uint16_t pc = 0;
uint16_t cir = 0;
uint16_t size = 0;
bool load_file(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        return false;
    } else {
        uint8_t byte;
        while (in.read(reinterpret_cast<char*>(&byte), 1)) {
            memory[pc++] = byte;
        }
    }
    size = pc;
    pc = 0;
    return true;
}
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Please provide a .bin file for Viper to run.";
        return 1;
    }
    load_file(argv[1]);
    bool running = true;
    bool zero_flag = false;
    while (running) {
        if (pc >= size) {
            break;
        }
        uint8_t arg1;
        uint8_t arg2;
        cir = memory[pc++];
        //Decode + Execute
        switch (cir) {
            case (0x01):
                arg1 = memory[pc++];
                arg2 = memory[pc++];
                registers[arg1] = arg2;
                break;
            case (0x02):
                arg1 = memory[pc++];
                arg2 = memory[pc++];
                registers[arg1] += registers[arg2];
                break;
            case (0x03):
                arg1 = memory[pc++];
                arg2 = memory[pc++];
                registers[arg1] -= registers[arg2];
                break;
            case (0x04):
                arg1 = memory[pc++];
                arg2 = memory[pc++];
                (registers[arg1] == registers[arg2]) ? (zero_flag = true) : (zero_flag = false);
                break;
            case (0x05):
                arg1 = memory[pc++];
                arg2 = memory[pc++];
                if (zero_flag){
                    pc = (arg1 << 8) + arg2;
                }
                break;
            case(0xFF):
                running = false;
                break;
            default:
                printf("Error when decoding. The fetched opcode was %u", cir);
        }
        
    }
}