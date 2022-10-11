#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> targetIndices(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    auto itr = std::lower_bound(nums.begin(), nums.end(), target);
    std::vector<int> solution;
    while (itr != nums.end() && *itr == target) {
        solution.push_back(itr - nums.begin());
        ++itr;
    }
    return solution;
}
std::vector<int> targetIndices(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    int count_smaller{0};
    int count_target{0};
    for (int e : nums) {
        count_smaller += e < target;
        count_target += e == target;
    }
    for (int i = 0; i < count_target; ++i) {
        solution.push_back(count_smaller + i);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    std::vector<int> solution = targetIndices(nums, target);
    return 0;
}
