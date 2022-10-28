#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(
    std::vector<std::string>& strs) {
    std::unordered_map<std::string, unsigned short> m;
    std::vector<std::vector<std::string>> solution;

    for (std::string str : strs) {
        std::string temp(str);
        std::sort(str.begin(), str.end());
        if (!m.count(str)) {
            solution.push_back(std::vector<std::string>());
            m[str] = solution.size() - 1;
        }
        solution[m[str]].push_back(temp);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
