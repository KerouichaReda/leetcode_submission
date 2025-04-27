#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
    const std::vector<std::pair<int, std::string>> m = {{3, "Fizz"}, {5, "Buzz"}};
    std::vector<std::string> solution;
    for (int i = 1; i <= n; ++i) {
        std::string temp;
        for (const std::pair<int, std::string>& p : m) {
            if (i % p.first == 0) {
                temp += p.second;
            }
        }
        solution.push_back(temp.empty() ? std::to_string(i) : temp);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    int n = 30;
    std::vector<std::string> solution = fizzBuzz(n);

    return 0;
}
