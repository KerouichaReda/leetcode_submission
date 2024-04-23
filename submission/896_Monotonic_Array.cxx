#include <vector>

bool isMonotonic(std::vector<int>& nums) {
    auto sgn = [](int e) { return e > 0 ? 1 : e < 0 ? -1 : 0; };
    int dir = 0;
    int pre = *nums.begin();
    for (int e : nums) {
        int div = sgn(e - pre);
        pre = e;
        if (!div) continue;
        if (dir && div != dir) return false;
        dir = div;
    }
    return true;
}

int main(int argc, char const* argv[]) {
    std::vector<int> nums{1, 2, 2, 4};
    return 0;
}
