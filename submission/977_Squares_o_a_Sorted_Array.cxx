#include <vector>
#include <iostream>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> solution(nums.size());
    for (std::size_t i = 0, j = nums.size() - 1, k = nums.size() - 1; i <= j;) {
        if (std::abs(nums[j]) > std::abs(nums[i])) {
            solution[k--] = (nums[j] * nums[j--]);
        } else {
            solution[k--] = (nums[i] * nums[i++]);
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {-2, -1, 0, 1, 2};
    std::vector<int> solution = sortedSquares(nums);
    return 0;
}
