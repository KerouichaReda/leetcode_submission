#include <string>
#include <algorithm>
bool detectCapitalUse(std::string word) {
    bool all_lower = std::islower(word[0]);
    bool all_upper = std::isupper(word[0]);
    bool is_capital = std::isupper(word[0]);
    for (std::size_t i = 1, size = word.size(); i < size; ++i) {
        all_lower = all_lower && std::islower(word[i]);
        all_upper = all_upper && std::isupper(word[i]);
        is_capital = is_capital && std::islower(word[i]);
    }
    return all_lower || all_upper || is_capital;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
