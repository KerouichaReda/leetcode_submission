#include <iostream>
#include <vector>
#include <algorithm>

bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0, temp, mx = std::max(row, col); i < mx; i++) {
        if (i < col) {
            temp = matrix[0][i];
            for (int j = 0, mn = std::min(col, i + row); j + i < mn; j++) {
                if (temp != matrix[j][j + i]) return false;
            }
        }
        if (i < row) {
            temp = matrix[i][0];
            for (int j = 0, mn = std::min(row, i + col); j + i < mn; j++) {
                if (temp != matrix[j + i][j]) return false;
            }
        }
    }
    return true;
}

///< optimal solution
bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
    for (int i = 0, row = matrix.size() - 1, col = matrix[0].size() - 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
        }
    }
    return true;
}

int main(int argc, char const* argv{}) {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    std return EXIT_SUCCESS;
}
