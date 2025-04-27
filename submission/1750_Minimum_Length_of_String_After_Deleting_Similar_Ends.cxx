#include <string>
#include <iostream>

int minimumLength(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    for (; i < j && s[i] == s[j];) {
        char c = s[i];
        for (; i <= j && s[i] == c; i++)
            ;
        for (; i <= j && s[j] == c; j--)
            ;
    }
    return j - i + 1;
}

int main(int argc, char const* argv[]) {
    std::string s = "aba";
    std::cout << minimumLength(s) << std::endl;
    return 0;
}
