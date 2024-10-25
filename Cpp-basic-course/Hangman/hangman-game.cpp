#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <not_guessed_correctly.hpp>
#include <letter_exists.hpp>
#include <not_hanged.hpp>
#include <print_message.hpp>
#include <print_wrong_guesses.hpp>
#include <print_word.hpp>
#include <guess_letter.hpp>
#include <read_file.hpp>
#include <choose_word.hpp>
#include <save_file.hpp>
#include <add_word.hpp>

using namespace std;

string secret_word;
map<char, bool> guessed; 
vector<char> wrong_guesses;

int main() {
    print_message();
    choose_word();  

    while (not_guessed_correctly() && not_hanged()) {
        print_wrong_guesses();
        print_word();
        guess_letter();
    }

    if (not_guessed_correctly()) {
        cout << "Game over! The secret word was: " << secret_word << endl;
        cout << "You lost! Try again!" << endl;
    } else {
        cout << "Congratulations! You guessed the secret word: " << secret_word << endl;

        cout << "Want to add a new word to the database? (Y/N)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'Y') {
            add_word();
        }
    }

    return 0;
}
