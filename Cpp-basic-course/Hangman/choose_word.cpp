#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <read_file.hpp>

extern std::string secret_word;


void choose_word() {
    std::vector<std::string> words = read_file();

    srand(time(NULL));
    int sorted_index = rand() % words.size();

    secret_word = words[sorted_index];
}