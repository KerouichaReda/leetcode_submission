#include <vector>
#include <algorithm>
#include <iostream>

int hIndex(std::vector<int>& citations) {
    std::sort(citations.rbegin(), citations.rend());
    int solution;
    for (solution = 0;
         solution < citations.size() && solution < citations[solution];
         solution++) {
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> citations({
        1, 1, 1, 1, 1, 1,
    });
    std::cout << hIndex(citations);
    return 0;
}
