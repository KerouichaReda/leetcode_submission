#include <vector>
#include <set>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::size_t row = matrix.size();
    std::size_t col = matrix[0].size();
    std::set<std::size_t> row_set, col_set;
    for (std::size_t i = 0; i < row; ++i) {
        for (std::size_t j = 0; j < col; ++j) {
            if (!matrix[i][j]) {
                row_set.insert(i);
                col_set.insert(j);
            }
        }
    }
    for (int i : row_set) {
        for (std::size_t j = 0; j < col; ++j) {
            matrix[i][j] = 0;
        }
    }
    for (int j : col_set) {
        for (std::size_t i = 0; i < row; ++i) {
            matrix[i][j] = 0;
        }
    }
}

int main(int argc, char const* argv[]) {
    /* code */
    std::vector<std::vector<int>>  matrix = {{0,1},{1,1}};
    setZeroes(matrix);
    return 0;
}
