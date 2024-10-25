#include <string>
#include <map>

extern std::string secret_word;
extern std::map<char, bool> guessed; 

bool not_guessed_correctly() {
    for (char letter : secret_word) {
        if (!guessed[letter]) {
            return true;
        }
    }
    return false;
}
