#include <set>
#include <string>
#include <iostream>

const std::set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
bool halvesAreAlike(string str) {
    int counter[2] = {};
    for (int i = 0, size = str.size(); i < size; ++i) {
        counter[vowels.count(str[i])] += i < size / 2 ? 1 : -1;
    }
    return counter[0] == 0 && counter[1] == 0;
}

int main(int argc, char const* argv[]) {
    std::string str = "book";
    std::cout << halvesAreAlike(str) << std::endl;
    return 0;
}
