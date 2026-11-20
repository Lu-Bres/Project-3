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




void ecriture(bool bit, int index) {
	if (bit) {
		(*cfile)[index] = SetBit((*cfile)[index], 0);
	}
	else {
		(*cfile)[index] = ClearBit((*cfile)[index], 0);
	}
}
