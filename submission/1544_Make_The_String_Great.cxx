
#include <string>
#include <iostream>
#include <numeric>
bool is_same(char& a, char& b) { return std::abs(a - b) == 32; }
std::string makeGood(std::string s) {
    std::string stack;
    for (char& c : s) {
        if (stack.empty() || !is_same(stack.back(), c)) {
            stack.push_back(c);
        } else {
            stack.pop_back();
        }
    }
    return stack;
}
int main(int argc, char const* argv[]) {
    std::string s = "leeEetcode";
    std::cout << makeGood(s) << std::endl;
    return 0;
}
