#pragma once
#include <string>
#include <vector>


void lecture(std::string name_file);
void init(std::string index_file);
void ecriture(int bit, int index);
void debug_tab();
void create_file();
uint8_t encode(int size, std::string text, std::string key, std::string encryptext, int keysize, std::vector<std::vector<int>>& value);
uint8_t encryption(char cara, char cle);
bool GetBit(std::uint8_t value, unsigned int index);
void decode(int size, std::string key, int keysize, std::vector<std::vector<int>>& value, std::string nextext, std::string newtext);
void readFile(std::string readfile, std::vector<std::vector<int>>& value, int size);


extern std::vector<uint8_t> cfile;