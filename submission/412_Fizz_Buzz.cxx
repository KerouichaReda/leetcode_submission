#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> solution;
    for (int i = 1; i <= n; ++i) {
        std::string temp{};
        if (i % 3 == 0) temp += "Fizz";
        if (i % 5 == 0) temp += "Buzz";
        if (temp.empty()) temp = std::to_string(i);
        solution.push_back(temp);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    int n = 30;
    std::vector<std::string> solution = fizzBuzz(n);
    
    return 0;
}
