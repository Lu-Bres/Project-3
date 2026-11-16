#include <bitset>
#include <cstdint>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>

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

uint8_t encode(char cara, char cle)
{
    std::uint8_t message = cara;
    std::uint8_t key = cle;
    return message ^ key;
}

int main()
{/*
    std::uint8_t value_decimal = 1234;
    std::uint8_t value_binary = 0b01010101;
    std::uint8_t value_hex = 0x12AF;

    std::uint8_t value1 = 0b01010101;
    std::uint8_t value2 = 0b11111111;

    std::uint8_t result_and = value1 & value2; // 0b01010101
    std::uint8_t result_or = value1 | value2; // 0b11111111
    std::uint8_t result_xor = value1 ^ value2; // 0b10101010
    std::uint8_t result_not = ~value1; // 0b10101010
    std::uint8_t result_shift = value1 << 1; // 0b01010100
    std::uint8_t result_mask = 1 << 6; // 0b01000000

    std::cout << "Decimal : " << std::dec << +result_and << std::endl;
    std::cout << "Hexadecimal : " << std::hex << +result_and << std::endl;
    std::cout << "Binary : " << std::bitset<8>(result_and) << std::endl;

    std::cout << "Binary custom : ";
    PrintBits(result_and);*/


    std::string key = "aierre";
    std::string text = "yolo";
    /*for (std::size_t i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(text.c_str()[i]) << std::endl;
    }*/
    /*std::cout << text[0] << std::endl;
    std::cout << std::bitset<8>(text[0]) << std::endl;
    std::cout << std::bitset<8>(key[0]) << std::endl;*/
    for (int i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(encode(text[i], key[i])) << std::endl;
    }
    std::cout << "\n\n\n";
    for (int i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(text[i]) << std::endl;
    }

    std::ifstream file("Images/Image1.bmp", std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }

    constexpr std::size_t buffer_size = 500;
    char buffer[buffer_size];

    file.read(buffer, buffer_size);

    std::streamsize bytes_read = file.gcount();
    std::string result(
        buffer,
        static_cast<std::size_t>(bytes_read)
    );

    file.clear();
    file.seekg(53, std::ios::beg);
    std::uint8_t byte;
    file >> byte;
	std::cout << std::bitset<8>(byte) << std::endl;
}