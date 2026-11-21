#include <bitset>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <iostream>

std::vector<uint8_t> cfile = {};
uintmax_t csize = 0;

void init(std::string index_file) {
    csize = std::filesystem::file_size(index_file);
    cfile.reserve(csize);

}

void debug_bit(int i, uint8_t byte) {
    std::cout << "octet " << std::dec << i << " de l'image :" << std::bitset<8>(byte)
        << "  :  " << std::hex << +byte << "  :  " << std::bitset<1>(byte) << std::endl << std::endl;
}
void debug_tab() {
    std::cout << "\n\n\n";
    for (int i = 0; i < 100; ++i) {
        std::cout << "\"" << std::bitset<8>(cfile[i]) << "\"" << " => " << cfile[i] << ";\n";
    }
}

void lecture(std::string name_file, int sizebit) {
    std::ifstream file(name_file, std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }
    else if (sizebit > csize)
    {
        throw std::runtime_error("Text too long");
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
    file.seekg(0, std::ios::beg);
    char byte_c;
    for(int i = 0; i < csize; ++i) {
        file.read(&byte_c, 1);
        uint8_t byte = byte_c;
        (cfile).push_back(byte);
        file.seekg(i + 1, std::ios::beg);
    }
    file.close();
}