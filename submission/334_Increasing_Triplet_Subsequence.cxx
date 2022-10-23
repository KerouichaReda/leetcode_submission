#include <iostream>
#include <vector>

bool increasingTriplet(std::vector<int>& nums) {
    int seq_size{2};
    std::vector<int> seq(seq_size, std::numeric_limits<int>::max());
    int index{0};
    for (int x : nums) {
        for (index = 0; index < seq_size; ++index) {
            if (x <= seq[index]) {
                seq[index] = x;
                break;
            }
        }
        if (index >= seq_size) return true;
    }
    return false;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {2, 1, 5, 0, 4, 6};
    std::cout << increasingTriplet(nums) << std::endl;
    return 0;
}
