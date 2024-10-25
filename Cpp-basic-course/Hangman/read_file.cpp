#include <vector>
#include <iostream>
#include <fstream>
#include <string>

std::vector<std::string> read_file() {
    std::ifstream file;
    file.open("words.txt");

    if (!file.is_open()) {
        std::cout << "Error: Unable to open the file." << std::endl;
        exit(1);
    }

    int amount_words;
    file >> amount_words;

    std::vector<std::string> file_words;

    for (int i = 0; i < amount_words; i++) {
        std::string word_read;
        file >> word_read;
        file_words.push_back(word_read);
    }

    file.close();
    return file_words;
}