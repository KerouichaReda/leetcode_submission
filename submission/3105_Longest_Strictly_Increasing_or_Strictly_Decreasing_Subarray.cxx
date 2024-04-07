#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int longestMonotonicSubarray(std::vector<int>& nums) {
    int in{1}, de{1};
    int solution{1};
    for (int i = 1, size = nums.size(); i < size; i++) {
        in = nums[i] > nums[i - 1] ? in + 1 : 1;
        de = nums[i] < nums[i - 1] ? de + 1 : 1;
        solution = std::max(solution, std::max(in, de));
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
