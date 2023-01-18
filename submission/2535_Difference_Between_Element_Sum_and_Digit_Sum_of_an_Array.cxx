#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

int differenceOfSum(std::vector<int>& nums) {
    std::pair<int, int> pair_sum = std::accumulate(
        nums.begin(), nums.end(), std::make_pair(0, 0),
        [](std::pair<int, int> sum, int& e) {
            int digit_sum{0};
            for (int temp = e; temp > 0; digit_sum += (temp % 10), temp /= 10)
                ;
            return std::make_pair(sum.first + e, sum.second + digit_sum);
        });
    return std::abs(pair_sum.first - pair_sum.second);
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
