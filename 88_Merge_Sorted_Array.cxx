#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // reduce m and n by 1 to be used as a merging indexes
    for (int i = --m + --n + 1; i >= 0; --i) {
        nums1[i] = m < 0 ? nums2[n--] : n < 0 ? nums1[m--] : nums1[m] > nums2[n]
                                                                 ? nums1[m--]
                                                                 : nums2[n--];
    }
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    for (int i = --m + --n + 1; n >= 0; --i) {
        nums1[i] =
            m < 0 ? nums2[n--] : nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
}
int main(int argc, char const* argv[]) {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {4, 5, 6};
    int n = 3;
    merge(nums1, m, nums2, n);
    return 0;
}
