#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
    std::unordered_set<char> a(allowed.begin(), allowed.end());
    int solution = words.size();
    for (std::string w : words) {
        for (char c : w) {
            if (!a.count(c)) {
                solution--;
                break;
            }
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::string allowed = "abc";
    std::vector<std::string> words = {"abc", "abw", "a", "e"};

    std::cout << countConsistentStrings(allowed, words) << std::endl;
    return 0;
}
