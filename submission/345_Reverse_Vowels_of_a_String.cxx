#include <string>
#include <set>
#include <iostream>
const std::set<char> v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
std::string reverseVowels(std::string s) {
    std::string stack;
    for (char& c : s) {
        if (v.count(c)) stack.push_back(c);
    }
    for (int i = 0, size = s.size(); i < size; i++) {
        if (v.count(s[i])) {
            s[i] = stack.back();
            stack.pop_back();
        }
    }
    return s;
}

int main(int argc, char const* argv[]) {
    std::string s{"hello"};
    std::cout << reverseVowels(s) << std::endl;
    return 0;
}
