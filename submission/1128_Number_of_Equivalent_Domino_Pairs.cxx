
#include <vector>
#include <unordered_map>
int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
    std::unordered_map<int, int> m;
    int solution{0};
    for (std::vector<int>& dom : dominoes) {
        if (dom[0] > dom[1]) std::swap(dom[0], dom[1]);
        solution += m[dom[0] * 10 + dom[1]]++;
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
