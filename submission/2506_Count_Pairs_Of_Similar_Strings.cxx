#include <string>
#include <set>
#include <map>
#include <vector>

int similarPairs(std::vector<std::string>& words) {
    int solution{0};
    std::map<std::string, int> m;
    for (std::string& w : words) {
        std::set<char> s(w.begin(), w.end());
        std::string key(s.begin(), s.end());
        solution += m[key]++;
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
