#include <string>
#include <vector>
std::vector<int> divisibilityArray(std::string word, int m) {
    std::vector<int> solution;
    int64_t rem = 0;
    for (int i = 0, size = word.size(); i < size; ++i) {
        rem = (rem * 10 + word[i] - '0') % m;
        solution.push_back(!rem);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
