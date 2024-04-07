#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::string getSmallestString(std::string s, int k) {
    for (int i = 0, size = s.size(); i < size && k; i++) {
        int t = std::min(k, std::min(s[i] - 'a', 123 - s[i]));        
        s[i] =
            s[i] + t < 123 ? s[i] - t : (s[i] + t - 'a') % 26 + 'a';
        k -= t;
    }
    return s;
}

int main(int argc, char const* argv[]) {
    std::string s = "zbbk";
    int k = 3;

    std::cout << getSmallestString(s,k) << std:: endl;
    return 0;
}