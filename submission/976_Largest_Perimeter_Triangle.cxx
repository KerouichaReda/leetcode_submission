// https://leetcode.com/problems/largest-perimeter-triangle/

// Given an integer array nums, return the largest perimeter of a triangle with
// a non-zero area, formed from three of these lengths. If it is impossible to
// form any triangle of a non-zero area, return 0.

#include <iostream>
#include <vector>
#include <algorithm>
int largestPerimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), std::greater());
    for (size_t i = 0, size = nums.size() - 2; i < size; ++i) {
        if (nums[i] < (nums[i + 1] + nums[i + 2])) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums{1, 2, 1, 4};
    std::cout << largestPerimeter(nums) << std::endl;
    return 0;
}
