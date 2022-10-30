#include <string>
#include <iostream>
int balancedStringSplit(std::string s) {
    int counter[2] = {};
    int solution = 0;
    for (char& c : s) {
        counter[c == 'L']++;
        if (counter[0] == counter[1]) {
            solution++;
            counter[0] = counter[1] = 0;
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::string s{"LLRR"};
    std::cout << balancedStringSplit( s) << std::endl; 
    return 0;
}
