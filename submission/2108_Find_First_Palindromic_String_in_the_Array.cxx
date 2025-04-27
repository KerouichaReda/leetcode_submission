#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string firstPalindrome(std::vector<std::string>& words) {
    for (std::string& str : words) {
        if (std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin())) return str;
    }
    return std::string{};
}

int main(int argc, char const* argv[]) {
    std::vector<std::string> words = {"ada", "bobo", "love"};
    std::cout << firstPalindrome(words) << std::endl;
    return 0;
}
