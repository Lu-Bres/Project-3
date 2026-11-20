#include <bitset>
#include <cstdint>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include "lecture.h"






uint8_t encode(char cara, char cle)
{
    std::uint8_t message = cara;
    std::uint8_t key = cle;
    return message ^ key;
}



int main()
{
    std::string key = "aierre";
    std::string text = "yolo";
    init("images/image1.bmp");


    std::cout << "-----------" << text << "-----------" << std::endl;
    for (int i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(encode(text[i], key[i])) << std::endl;
    }
    std::cout << "--------encode--------\n\n\n";


    std::cout << "-----------" << text << "-----------" << std::endl;
    for (int i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(text[i]) << std::endl;
    }
    std::cout << "--------original--------\n\n\n";

    lecture("images/image1.bmp");
}



































/*
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
