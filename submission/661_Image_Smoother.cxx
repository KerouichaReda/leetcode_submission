#include <vector>
#include <iostream>
std::vector<std::vector<int>> imageSmoother(
    std::vector<std::vector<int>>& img) {
    std::vector<std::vector<int>> solution(img.size(),
                                           std::vector<int>(img[0].size(), 0));
    for (int i = 0, row = img.size(), col = img[0].size(); i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int sum = 0;
            int counter = 0;
            for (int k = -1; k < 2; ++k) {
                for (int l = -1; l < 2; ++l) {
                    if (i + k < 0 || i + k >= row || j + l < 0 || j + l >= col)
                        continue;
                    sum += img[i + k][j + l];
                    counter++;
                }
            }
            solution[i][j] = sum / counter;
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    imageSmoother({{1, 1}, {1, 1}});
    return 0;
}
