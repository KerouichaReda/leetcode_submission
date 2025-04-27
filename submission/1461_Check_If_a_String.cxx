#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

bool hasAllCodes(std::string s, int k) {
    int power = std::pow(2, k);
    int mask = power - 1;  // OxFF to only keep k bits
    std::vector<bool> m(power, false);
    for (int i = k - 1, temp, size = s.size(); i < size; ++i) {
        temp = i == k - 1 ? std::stoi(s.substr(0, k), nullptr, 2) : ((temp << 1) & mask) + (s[i] - '0');
        m[temp] = true;
    }
    return std::all_of(m.begin(), m.end(), [](bool e) { return e; });
}

bool hasAllCodes(std::string s, int k) {
    int power = std::pow(2, k);
    std::vector<bool> m(power, 0);
    for (int i = 0, size = s.size() - k + 1; i < size; ++i) {
        m[stoi(s.substr(i, k), nullptr, 2)] = true;  // base 2 conversion
    }
    return std::accumulate(m.begin(), m.end(), 0) == power;
}

int main(int argc, char const* argv[]) {
    /* code */
    std::string str{"00110110"};
    int k = 2;
    std::cout << hasAllCodes(str, k) << std::endl;
    return EXIT_SUCCESS;
}
