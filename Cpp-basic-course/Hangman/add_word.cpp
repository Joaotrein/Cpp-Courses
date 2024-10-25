#include <iostream>
#include <string>
#include <vector>
#include <save_file.hpp>
#include <read_file.hpp>

void add_word() {
    std::cout << "Add a new word, using uppercase letters" << std::endl;

    std::string new_word;
    std::cin >> new_word;

    std::vector<std::string> words_list = read_file();
    words_list.push_back(new_word);
 
    save_file(words_list);
}