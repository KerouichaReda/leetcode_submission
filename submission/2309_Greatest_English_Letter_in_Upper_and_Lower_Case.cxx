
#include <string>
#include <iostream>
std::string greatestLetter(std::string s) {
    bool t[2][26] = {};
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') t[0][c - 'A'] = 1;
        if (c >= 'a' && c <= 'z') t[1][c - 'a'] = 1;
    }
    std::string solution;
    for (int i = 25; solution.empty() && i >= 0; --i) {
        if (t[0][i] && t[1][i]) solution.push_back(i + 'A');
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::cout << greatestLetter(std::string{"LeetCodE"}) << std::endl;
    return 0;
}
