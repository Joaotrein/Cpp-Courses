#include <iostream>
#include <string>
#include <map>

extern std::string secret_word;
extern std::map<char, bool> guessed; 

void print_word() {
    for (char letter : secret_word) {
        if (guessed[letter]) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}