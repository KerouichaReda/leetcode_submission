#include <iostream>
#include <vector>

std::vector<int> runningSum(std::vector<int>& nums) {
    std::vector<int> solution(nums.begin(), nums.end());
    for (std::vector<int>::iterator itr = solution.begin() + 1, end = solution.end(); itr != end; ++itr) {
        *itr += *(itr - 1);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */

    return 0;
}
