#include <iostream>
#include <algorithm>
#include <vector>

int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
    auto chebyshev_distance = [](std::vector<int>& point_1,
                                 std::vector<int>& point_2) {
        return std::max(std::abs(point_1[0] - point_2[0]),
                        std::abs(point_1[1] - point_2[1]));
    };
    int solution{0};
    for (int i = 1, size = points.size(); i < size; ++i) {
        solution += chebyshev_distance(points[i - 1], points[i]);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
