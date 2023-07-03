
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
std::string mostCommonWord(std::string paragraph,
                           std::vector<std::string>& banned) {
    const std::string delimiter = " !?',;.";
    const std::unordered_set<char> del(delimiter.begin(), delimiter.end());
    paragraph.push_back(' ');
    std::unordered_set<std::string> set_banned(banned.begin(), banned.end());
    std::unordered_map<std::string, int> m_;
    std::string temp;
    std::pair<std::string, int> solution = {std::string{}, 0};
    for (char& c : paragraph) {
        if (del.count(c)) {
            if (!temp.empty() && !set_banned.count(temp) &&
                ++m_[temp] > solution.second) {
                solution.first = temp;
                solution.second = m_[temp];
            }
            temp.clear();
        } else {
            temp.push_back(std::tolower(c));
        }
    }
    return solution.first;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
