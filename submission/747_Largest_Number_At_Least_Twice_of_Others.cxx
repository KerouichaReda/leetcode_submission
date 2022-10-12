#include <vector>
#include <iostream>

int dominantIndex(std::vector<int>& nums) {
    int max_val[2] = {0, 0};
    int solution{0};
    for (int index = 0, end = nums.size(); index < end; ++index) {
        if (nums[index] > max_val[0]) {
            max_val[1] = max_val[0];
            max_val[0] = nums[index];
            solution = index;
        } else if (nums[index] > max_val[1]) {
            max_val[1] = nums[index];
        }
    }
    return max_val[0] >= max_val[1] * 2 ? solution : -1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {0, 0, 0, 1};
    std::cout << dominantIndex(nums) << std::endl;
    return 0;
}
