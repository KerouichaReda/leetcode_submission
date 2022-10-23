#include <iostream>
#include <vector>

int minOperations(std::vector<int>& nums) {
    int solution{0}, pre{0};
    for (int& e : nums) {
        if (pre >= e) {
            solution += ++pre - e;
        } else {
            pre = e;
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
