#include <string>
#include <iostream>

int countHomogenous(std::string s) {
    const std::int64_t mod{0x3B9ACA07};
    std::int64_t solution{0};
    char pre = 0;
    std::int64_t counter{0};
    s.push_back(0xAA);
    for (char& c : s) {
        if (pre != c) {
            pre = c;
            solution = (solution + counter * (counter + 1) / 2) % mod;
            counter = 0;
        }
        counter++;
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::cout << countHomogenous(std::string{"aaaaaaa"}) << std::endl;
    return 0;
}
