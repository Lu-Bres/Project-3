#include <bitset>
#include <cstdint>
#include <filesystem>
#include <fstream>

#include <string>
#include <stdexcept>
#include <iostream>

std::vector<uint8_t> cfile = {};
uintmax_t size = 0;


void init(std::string index_file) {
    size = std::filesystem::file_size(index_file);
    cfile.reserve(size);
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





void lecture(std::string name_file) {
    std::ifstream file(name_file, std::ios::binary);

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
    file.seekg(0, std::ios::beg);
    char byte_c;
    //std::uintmax_t bsize = std::filesystem::file_size(name_file);
    for(int i = 0; i < size; ++i) {
        file.read(&byte_c, 1);
        uint8_t byte = byte_c;
        //debug_bit(i,byte);
        (cfile).push_back(byte);
        file.seekg(i + 1, std::ios::beg);
    }
    file.close();
    //debug_tab();
}