#include <string>
#include <functional>
#include <iostream>


int myAtoi(std::string s) {
    std::reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == ' ') s.pop_back();
    int sign{1};
    if (!s.empty() && (s.back() == '-' || s.back() == '+')) {
        sign -= 2 * (s.back() == '-');
        s.pop_back();
    }
    int solution{0};
    while (!s.empty() && isdigit(s.back())) {
        if (solution > INT_MAX / 10 ||
            solution == INT_MAX / 10 && (s.back() > '7')) {
            return sign < 0 ? INT_MIN : INT_MAX;
        }
        solution = solution * 10 + (s.back() - '0');
        s.pop_back();
    }
    return solution * sign;
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
