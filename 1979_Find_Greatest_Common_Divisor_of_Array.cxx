#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

int findGCD(std::vector<int>& nums) {
    auto[min_itr, max_itr] = std::minmax_element(nums.begin(), nums.end());
    return std::gcd(*max_itr, *min_itr);
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {2, 3, 5, 10};
    std::cout << findGCD(nums) << std::endl;
    return 0;
}
