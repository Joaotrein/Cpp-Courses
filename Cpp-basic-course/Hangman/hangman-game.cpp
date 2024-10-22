#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

string secret_word;
map<char, bool> guessed; 
vector<char> wrong_guesses;

bool letter_exists(char guess) {
    for (char letter : secret_word) {
        if (guess == letter) {
            return true;
        }
    }
    return false;
}

bool not_guessed_correctly() {
    for (char letter : secret_word) {
        if (!guessed[letter]) {
            return true;
        }
    }
    return false;
}

bool not_hanged() {
    return wrong_guesses.size() < 5;
}

void print_message() {
    cout << "*********************" << endl;
    cout << "*** Hangman Game ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void print_wrong_guesses() {
    cout << "Wrong guesses: ";
    for (char letter : wrong_guesses) {
        cout << letter << " ";
    }
    cout << endl;
}

void print_word() {
    for (char letter : secret_word) {
        if (guessed[letter]) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void guess_letter() {
    cout << "Your guess: ";
    char guess;
    cin >> guess;

    guessed[guess] = true;

    if (letter_exists(guess)) {
        cout << "You got it right! The letter is in the word." << endl;
    } else {
        cout << "Wrong! The letter is not in the word." << endl;
        wrong_guesses.push_back(guess);
    }
    cout << endl;
}

vector<string> read_file() {
    ifstream file;
    file.open("words.txt");

    if (!file.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        exit(1);
    }

    int amount_words;
    file >> amount_words;

    vector<string> file_words;

    for (int i = 0; i < amount_words; i++) {
        string word_read;
        file >> word_read;
        file_words.push_back(word_read);
    }

    file.close();
    return file_words;
}

void choose_word() {
    vector<string> words = read_file();

    srand(time(NULL));
    int sorted_index = rand() % words.size();

    secret_word = words[sorted_index];
}

void save_file(vector<string> new_list) {
    ofstream file;
    file.open("words.txt");

    if (file.is_open()) {
        file << new_list.size() << endl;  
        for (string word : new_list) {
            file << word << endl;  
        }

        file.close();
    } else {
        cout << "Error: Unable to open the file." << endl;
        exit(1);
    }
}

void add_word() {
    cout << "Add a new word, using uppercase letters" << endl;

    string new_word;
    cin >> new_word;

    vector<string> words_list = read_file();
    words_list.push_back(new_word);

    save_file(words_list);
}

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
