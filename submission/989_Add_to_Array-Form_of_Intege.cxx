#include <vector>
#include <numeric>
std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
    std::vector<int> solution;
    for (int i = 0, carry = 0; k || !num.empty() || carry; k /= 10) {
        int digit = 0;
        if (!num.empty()) {
            digit = num.back();
            num.pop_back();
        }
        int temp = digit + carry + (k % 10);
        solution.push_back(temp % 10);
        carry = temp / 10;
    }
    std::reverse(solution.begin(), solution.end());
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> num{
        1, 2, 3, 4,
    };
    int k = 4;
    std::vector<int> solution = addToArrayForm(num, k);
    return 0;
}
