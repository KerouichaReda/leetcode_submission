#include <string>

std::string removeStars(const std::string& s) {
    std::string solution;
    for (const char& c : s) {
        if (c == '*') {
            solution.pop_back();
        } else {
            solution.push_back(c);
        }
    }
    return solution;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
