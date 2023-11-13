#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

std::string sortVowels(std::string str) {
    std::vector<std::size_t> indx;
    std::string temp;
    const std::set<char> v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (std::size_t i = 0, size = str.size(); i < size; ++i) {
        if (v.count(str[i])) {
            indx.push_back(i);
            temp.push_back(str[i]);
        }
    }
    std::sort(temp.begin(), temp.end());
    for (std::size_t i = 0, size = temp.size(); i < size; ++i) {
        str[indx[i]] = temp[i];
    }
    return str;
}

int main(int argc, char const* argv[]) {
    std::cout << sortVowels(std::string{"LeetCode"}) << std::endl;
    return 0;
}
