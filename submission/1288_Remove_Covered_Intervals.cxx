#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    for (std::vector<int>& interval : intervals) {
        std::cout << interval[0] << " " << interval[1] << std::endl;
    }

    return intervals.size();
}

int main(int argc, char const* argv[]) {
    std::vector<std::vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    std::cout << "remaining intervals : " << removeCoveredIntervals(intervals) << std::endl;
    return 0;
}
