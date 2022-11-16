
#include <vector>

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> solution;
    std::vector<int> temp;
    for (int i = 1; i <= n; i++) {
        helper(i, n, k, temp, solution);
    }
    return solution;
}
void helper(int e, int n, int k, std::vector<int>& temp,
            std::vector<std::vector<int>>& solution) {
    temp.push_back(e);
    if (temp.size() >= k) {
        solution.push_back(temp);
        temp.pop_back();
        return;
    }
    for (int i = e + 1; i <= n; i++) {
        helper(i, n, k, temp, solution);
    }
    temp.pop_back();
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
