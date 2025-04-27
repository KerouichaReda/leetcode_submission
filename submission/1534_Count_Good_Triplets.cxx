#include <iostream>
#include <vector>
#include <algorithm>

int countGoodTriplets(const std::vector<int>& arr, const int a, const int b, const int c) {
    int solution{0};
    for (int i = 0, size = arr.size(); i < size - 2; ++i) {
        for (int j = i + 1; j < size - 1; ++j) {
            for (int k = j + 1; k < size; ++k) {
                solution +=
                    std::abs(arr[i] - arr[j]) <= a && std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c;
            }
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
