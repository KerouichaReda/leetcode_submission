#include <iostream>
#include <vector>
#include <algorithm>

int maxProductDifference(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return *nums.rbegin() * (*(nums.rbegin() + 1)) - *nums.begin() * (*(nums.begin() + 1));
}
int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
