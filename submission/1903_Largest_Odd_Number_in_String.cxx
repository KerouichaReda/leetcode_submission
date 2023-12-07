#include <string>
#include <iostream>

std::string largestOddNumber(std::string num) {
    while (!num.empty() && !((num.back() - '0') & 1)) {
        num.pop_back();
    }
    return num;
}

int main(int argc, char const* argv[]) {
    std::cout << largestOddNumber("100000000000000000000000001000")
              << std::endl;
    return 0;
}
