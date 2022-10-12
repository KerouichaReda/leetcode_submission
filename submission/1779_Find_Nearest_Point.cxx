#include <iostream>
#include <vector>
#include <algorithm>

int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
    int solution{-1}, max_dist{INT32_MAX};
    for (int i = 0, size = points.size(); i < size; i++) {
        if (points[i][0] == x || points[i][1] == y) {
            int manhattan_dist =
                std::abs(points[i][0] - x) + std::abs(points[i][1] - y);
            if (manhattan_dist < max_dist) {
                max_dist = manhattan_dist;
                solution = i;
            }
        }
    }
    return solution;
}

int main() {
    int x = 3;
    int y = 4;
    std::vector<std::vector<int>> points = {
        {1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};

    std::cout << nearestValidPoint(x, y, points) << std::endl;
    return EXIT_SUCCESS;
}