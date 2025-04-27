#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) s.erase(nums[i - k - 1]);
        if (s.count(nums[i])) return true;
        s.insert(nums[i]);
    }
    return false;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
