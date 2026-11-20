#pragma once
#include <string>
#include <vector>


void lecture(std::string name_file);
void init(std::string index_file);
void ecriture(int bit, int index);
void debug_tab();
void create_file();

extern std::vector<uint8_t> cfile;