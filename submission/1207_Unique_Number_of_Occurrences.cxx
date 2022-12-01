#include <vector>
#include <iostream>
#include <unordered_set>

bool uniqueOccurrences(std::vector<int>& arr) {
    int m[2001] = {0};
    for (int e : arr) m[e + 1001]++;
    std::unordered_set<int> s;
    for (int i = 0; i < 2001; i++) {
        if (m[i] > 0 && s.count(m[i])) return false;
        if (m[i] > 0) s.insert(m[i]);
    }
    return true;
}

int main(int argc, char const* argv[]) {
    std::vector<int> arr{1, 2, 2, 3, 3, 3};
    std::cout << uniqueOccurrences(arr) << std::endl;
    return 0;
}
