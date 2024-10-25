#include <vector>

extern std::vector<char> wrong_guesses;

bool not_hanged() {
    return wrong_guesses.size() < 5;
}