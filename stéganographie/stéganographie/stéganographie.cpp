#include <bitset>
#include <cstdint>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include "lecture.h"

void debug_encode(std::string text, std::string key) {
    std::cout << "-----------" << text << "-----------" << std::endl;
    for (int i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(encryption(text[i], key[i])) << std::endl;
    }
    std::cout << "--------encode--------\n\n\n";
}

void debug_original(std::string text, std::string key) {
    std::cout << "-----------" << text << "-----------" << std::endl;
    for (int i = 0; i < text.size(); ++i) {
        std::cout << std::bitset<8>(text[i]) << std::endl;
    }
    std::cout << "--------original--------\n\n\n";
}

void teste_modification() {
    int choixbit[5] = { 1,0,1,0,0 };
}

int main(int argc, char* argv[])
{
    std::string key = "aierre";
    std::string text = "wallah";
    int keysize = 0;
    std::string encryptext = "";
    std::string nextext = "";
    std::string newtext = "";
    int size = text.length();
    std::vector<std::vector<int>> value(size, std::vector<int>(8));
    encryptext.reserve(text.size());
    newtext.reserve(text.size());
    int bit = 0;
    int bitcount = 0;
    std::string command = argv[1];
    //std::string writefile = argv[3];
    if (argc < 2)
    {
        std::cerr << "Missing command\n";
        return 1;
    }
    else if (command == "encode")
    {
        if (argc != 5)
        {
            std::cerr << "Invalid encode arguments\n";
            return 1;
        }
        encode(size, text, key, encryptext, keysize, value);
        init("Images/image1.bmp");
        lecture("images/image1.bmp");
        //debug_tab();
        for (int i = 0; i < size; ++i) {
			for (int j = 0; j < 8; ++j) {
				bit = value[i][j];
                ecriture(bit, i, bitcount);
                bitcount++;
			}   
            std::cout << "\n";
        }
        create_file();
    }
    else if (command == "decode")
    {
        if (argc != 3)
        {
            std::cerr << "Invalid decode arguments\n";
            return 1;
        }
        std::string readfile = argv[2];
        readFile(readfile, value, size);
        decode(size, key, keysize, value, nextext, newtext);
    }
    else
    {
        std::cerr << "Wrong command\n";
        return 1;
    }
    //encode(size, text, key, encryptext, keysize, value);
    //init("Images/image1.bmp");
    //lecture("images/image1.bmp");

    //debug_tab();
    //for (int i = 0; i < 5; ++i) {
    //    ecriture(, i);
    //}
    //decode(size, key, keysize, value, nextext, newtext);
    //debug_tab();
    //create_file();
    //debug_tab();
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
