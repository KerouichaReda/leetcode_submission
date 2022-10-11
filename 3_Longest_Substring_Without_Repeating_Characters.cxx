#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> m;
    int solution{0}, start{-1};
    for (int i = 0, size = s.size(); i < size; ++i) {
        char c = s[i];
        if (m.count(c) && m[c] > start) {
            start = m[c];
        }
        m[c] = i;
        solution = std::max(solution, i - start);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::string str{"absdwk"};
    std::cout << lengthOfLongestSubstring(str) << std::endl;
    return 0;
}
