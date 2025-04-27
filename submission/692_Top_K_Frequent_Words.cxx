#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> m;
    std::vector<std::string> solution;
    for (std::string w : words) {
        u[w]++;
    }
    std::vector<std::pair<std::string, int>> hist;
    for (std::pair<std::string, int> h : m) {
        hist.push_back(h);
    }
    std::sort(hist.begin(), hist.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    for (int i = 0; i < k; i++) {
        solution.push_back(hist[i].first);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
