#include <vector>
#include <numeric>
#include <string>
#include <iostream>
int numberOfBeams(std::vector<std::string>& bank) {
    int solution{0};
    int pre{0};
    for (std::string& s : bank) {
        int curr = std::accumulate(s.begin(), s.end(), 0, [](int sum, char c) { return sum + (c == '1'); });
        solution += curr * pre;
        pre = curr ? curr : pre;
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
