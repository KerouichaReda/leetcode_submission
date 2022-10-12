#include <iostream>
#include <vector>
#include <unordered_map>

int countPairs(std::vector<int>& nums, int k) {
    std::unordered_map<int, std::vector<int>> m;
    int solution{0};
    for (int i = nums.size() - 1; i >= 0; --i) {
        for (int index : m[nums[i]]) {
            solution += ((i * index) % k == 0);
        }
        m[nums[i]].push_back(i);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
     