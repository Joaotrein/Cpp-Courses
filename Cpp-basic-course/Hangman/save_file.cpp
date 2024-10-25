#include <iostream>
#include <vector>
#include <fstream>


void save_file(std::vector<std::string> new_list) {
    std::ofstream file;
    file.open("words.txt");

    if (file.is_open()) {
        file << new_list.size() << std::endl;  
        for (std::string word : new_list) {
            file << word << std::endl;  
        }

        file.close();
    } else {
        std::cout << "Error: Unable to open the file." << std::endl;
        exit(1);
    }
}