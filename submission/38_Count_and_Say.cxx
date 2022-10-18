#include <string>
#include <iostream>

std::string countAndSay(int n) {
    if (n == 1) return "1";
    std::string temp = countAndSay(n - 1);
    std::string solution;
    for (int i = 0; i < temp.size(); i++) {
        char c = temp[i];
        int count = 0;
        while (temp[i] == c) {
            count++;
            i++;
        }
        i--;
        solution += std::to_string(count) + c;
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::cout << countAndSay(8) << std::endl;
    return 0;
}
