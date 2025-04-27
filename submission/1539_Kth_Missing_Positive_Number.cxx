#include <vector>
#include <functional>
#include <iostream>

int findKthPositive(std::vector<int>& arr, int k) {
    for (int i = 1, size = arr.back(), index = 0; i < size; ++i) {
        if (arr[index] != i) {
            if (!--k) return i;
        } else {
            index++;
        }
    }
    return arr.back() + k;
}

int main(int argc, char const* argv[]) {
    std::vector<int> arr{1, 2, 3, 4, 5};
    int k = 5;
    std::cout << findKthPositive(arr, k) << std::endl;
    return 0;
}
