#include <iostream>
#include <string>

std::string truncateSentence(std::string s, int k) {
    for (int i = 0, size = s.size(); i < size && k; ++i) {
        if (s[i] == ' ' && !--k) return s.substr(0, i);
    }
    return s;
}

int main(int argc, char const* argv[]) {
    std::string str{"Hello how are you Contestant"};
    int k = 4;
    std::cout << truncateSentence(str, k) << std::endl;
    return 0;
}
