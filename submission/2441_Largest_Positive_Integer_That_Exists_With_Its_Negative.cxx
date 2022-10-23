#include <vector>
#include <set>
#include <iostream>

int findMaxK(std::vector<int>& nums) {
    std::set<int> s(nums.begin(), nums.end());
    for (auto itr = s.rbegin(), end = s.rend(); itr != end && *itr > 0; ++itr) {
        if (s.count(-(*itr))) {
            return *itr;
        }
    }
    return -1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {-1,0,1};
    std::cout << findMaxK(nums) << std::endl;
    return 0;
}
