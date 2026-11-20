#include <bitset>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include "lecture.h"




bool GetBit(std::uint8_t value, unsigned int index)
{
    return (value >> index) & 1u;
}

std::uint8_t SetBit(std::uint8_t value, unsigned int index)
{
    return value | (1u << index);
}

std::uint8_t ClearBit(std::uint8_t value, unsigned int index)
{
    return value & ~(1u << index);
}

void PrintBits(std::uint8_t value)
{
    for (int i = 7; i >= 0; --i)
    {
        std::cout << (GetBit(value, i) ? "1" : "0");
    }
}

std::uint8_t ToggleBit(std::uint8_t value, unsigned int index)
{
    std::uint8_t mask = 1u << index;

    std::uint8_t result = value ^ mask;

    return result;
}

std::uint8_t ToggleBitShort(std::uint8_t value, unsigned int index)
{
    return static_cast<std::uint8_t>(value ^ (1u << index));
}




void ecriture(int bit, int index) {
    if (bit == 1) {
        (cfile)[53+index] = SetBit((cfile)[53+index], 0);
        std::cout << "+1";
    }
    else if (bit == 0) {
        (cfile)[53+index] = ClearBit((cfile)[53+index], 0);
        std::cout << "-1";
    }
}

void create_file() {
    std::ofstream file("Images/Newimage.bmp", std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file");
    }


    for (size_t index = 0; index < cfile.size(); index++)
    {
        char byte = cfile[index];
        file.write(&byte, 1);
    }


    if (!file) {
        std::cerr << "Erreur lors de l'écriture dans le fichier.\n";
    } 
    file.close();
}

