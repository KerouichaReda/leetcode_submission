#include <map>
#include <vector>

#include <iostream>

std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
    std::map<int, int> m;
    for (int& e : nums) {
        m[e]++;
    }
    std::vector<std::vector<int>> solution;
    while (!m.empty()) {
        solution.push_back(std::vector<int>());
        for (std::pair<int, int> p : m) {
            solution.back().push_back(p.first);
        }
        for (int& e : solution.back()) {
            if (--m[e] == 0) {
                m.erase(e);
            }
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {1, 2, 3, 1, 4, 1, 3};
    std::vector<std::vector<int>> solution = findMatrix(nums);
    return 0;
}
