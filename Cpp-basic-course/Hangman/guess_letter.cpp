#include <iostream>
#include <vector>
#include <map>
#include <letter_exists.hpp> 

extern std::vector<char> wrong_guesses;
extern std::map<char, bool> guessed; 


void guess_letter() {
    std::cout << "Your guess: ";
    char guess;
    std::cin >> guess;

    guessed[guess] = true;

    if (letter_exists(guess)) {
        std::cout << "You got it right! The letter is in the word." << std::endl;
    } else {
        std::cout << "Wrong! The letter is not in the word." << std::endl;
        wrong_guesses.push_back(guess);
    }
    std::cout << std::endl;
}