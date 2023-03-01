
#include <vector>
#include <numeric>
std::vector<int> leftRigthDifference(std::vector<int>& nums) {
    std::vector<int> solution;
    int l = std::accumulate(nums.begin(), nums.end(), 0);
    int r = 0;
    for (int i = 0, size = nums.size(); i < size; ++i) {
        l -= nums[i];
        solution.push_back(std::abs(l - r));
        r += nums[i];
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
