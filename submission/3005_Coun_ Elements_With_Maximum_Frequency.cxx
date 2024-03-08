
#include <vector>
#include <iostream>

int maxFrequencyElements(std::vector<int>& nums) {
    int freq[100] = {};
    int solution{0};
    int max_freq = {};
    for (int& e : nums) {
        if (++freq[e - 1] > max_freq) {
            solution = freq[e - 1];
            max_freq = freq[e - 1];
        } else if (max_freq == freq[e - 1]) {
            solution += freq[e - 1];
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 2, 5};
    std::cout << maxFrequencyElements(nums) << std::endl;
    return 0;
}
