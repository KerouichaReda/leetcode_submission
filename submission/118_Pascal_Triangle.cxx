#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> solution{{1}};
    for (int i = 1; i < numRows; i++) {
        std::vector<int> row = {1};
        for (int j = 1; j < i; j++) {
            row.push_back(solution.back()[j - 1] + solution.back()[j]);
        }
        row.push_back(1);
        solution.push_back(row);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
