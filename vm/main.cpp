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
    while (true) {
        //Fetch
        cir = memory[pc++];
        //Decode
        switch (cir) {
            case (0x01):
                uint8_t reg_count = memory[pc++];
                uint8_t val = memory[pc++];
                break;
            case (0x02):
            break;
            case (0x03):
            break;
            case (0x04):
            break;
            case (0x05):
            break;
            case (0x06):
            break;
            case(0xFF):
            break;
            default:
                printf("Error when decoding. The fetched opcode was %u", cir);
        }
        
    }
}