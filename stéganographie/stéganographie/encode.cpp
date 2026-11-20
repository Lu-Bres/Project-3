#include <bitset>
#include <cstdint>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <sstream>
#include "lecture.h"

uint8_t encryption(char cara, char cle)
{
    std::uint8_t message = cara;
    std::uint8_t key = cle;
    return message ^ key;
}

uint8_t encode(int size, std::string text, std::string key, std::string encryptext, int keysize, std::vector<std::vector<int>>& value)
{
    for (int i = 0; i < size; ++i)
    {
        if (keysize > key.size())
        {
            keysize = 0;
        }
        encryptext += encryption(text[i], key[keysize]);
        keysize += 1;
    }
    keysize = 0;
    std::cout << "Encrypted text : " << encryptext << std::endl;
    for (int j = 0; j < size; ++j)
    {
        int a = 7;
        for (int i = 0; i < 8; ++i)
        {
            value[j][i] = GetBit(encryptext[j], a);
            a -= 1;
        }
    }
    std::cout << "\n";
    return 0;
}


void decode(int size, std::string key, int keysize, std::vector<std::vector<int>>& value, std::string nextext, std::string newtext)

{
    std::string decryptext = "";
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            std::string octet = std::to_string(value[i][j]);
            decryptext += octet;
        }
    }
    for (size_t i = 0; i < decryptext.length(); i += 8)
    {
        std::string octet = decryptext.substr(i, 8);
        char caractere = static_cast<char>(std::bitset<8>(octet).to_ulong());
        nextext += caractere;
    }
    std::cout << "Encrypted text : " << nextext << std::endl;
    for (int i = 0; i < size; ++i)
    {
        if (keysize > key.size())
        {
            keysize = 0;
        }
        newtext += encryption(nextext[i], key[keysize]);
        keysize += 1;
    }
    std::cout << "Decrypted text : " << newtext << std::endl;

}


void readFile(std::string readfile, std::vector<std::vector<int>>& value, int size)
{
    std::ifstream file(readfile, std::ios::binary);
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
    std::vector<int> cryptedtext[4];
    std::uint8_t uncryptedtext[4];
    std::uint8_t byte;
    for (int j = 0; j < size; ++j)
    {
        int a = 7;
        for (int i = 0; i < 8; ++i)
        {
            file >> byte;
            value[j][i] = GetBit(byte, a);
            a -= 1;
        }
    }
}