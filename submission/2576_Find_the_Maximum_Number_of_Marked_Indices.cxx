#include <vector>
#include <algorithm>

int maxNumOfMarkedIndices(std::vector<int>& nums) {
    int i = 0, n = nums.size();
    std::sort(begin(nums), end(nums));
    for (int j = n - n / 2; j < n; ++j) {
        i += 2 * nums[i] <= nums[j];
    }
    return i * 2;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
