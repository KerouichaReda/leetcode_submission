
#include <vector>
#include <algorithm>
int smallestRangeI(std::vector<int>& nums, int k) {
    const auto[min_itr, max_itr] = std::minmax_element(nums.begin(), nums.end());
    return std::max(0, (*max_itr - *min_itr) - 2 * k);
}

int main(int argc, char const* argv[]) { return 0; }
