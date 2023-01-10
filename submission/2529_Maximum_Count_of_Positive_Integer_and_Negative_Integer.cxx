#include <vector>
#include <algorithm>

int maximumCount(std::vector<int>& nums) {
    return std::max(
        std::distance(nums.begin(),
                      std::lower_bound(nums.begin(), nums.end(), 0)),
        std::distance(std::upper_bound(nums.begin(), nums.end(), 0),
                      nums.end()));
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
