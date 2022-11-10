#include <string>
#include <iostream>
std::string removeDuplicates(std::string& s) {
    std::string solution;
    for (char& c : s) {
        if (solution.empty() || solution.back() != c) {
            solution.push_back(c);
        } else {
            solution.pop_back();
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::string s = "abba";

    std::cout << removeDuplicates(s) << std::endl;

    return 0;
}
