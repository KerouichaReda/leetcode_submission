#include <iostream>
#include <vector>
#include <string>

int minDeletionSize(std::vector<std::string>& strs) {
    int solution{0};
    int row = strs.size();
    int col = strs[0].size();
    for (std::size_t i = 0; i < col; ++i) {
        char pre{'a'};
        std::size_t j = 0;
        for (; j < row && strs[j][i] >= pre; pre = strs[j][i], ++j)
            ;
        solution += j != row;
    }
    return solution;
}
int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
