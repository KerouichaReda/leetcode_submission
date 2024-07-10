#include <iostream>
#include <set>
#include <string>
int numberOfSpecialChars(std::string word) {
    std::set<char> s(word.begin(), word.end());
    int solution{};
    for (int i = 0, size = 26; i < size; ++i) {
        solution += s.count('a' + i) && s.count('A' + i);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::string word{"abc"};
    std::cout << numberOfSpecialChars(word) << std::endl;
    return 0;
}
