#include <vector>
#include <map>
#include <iostream>

std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
    std::map<int, int> players;
    for (std::vector<int>& matche : matches) {
        int win = matche[0];
        int lose = matche[1];
        players[win] += 0;
        players[lose]++;
    }
    std::vector<std::vector<int>> solution(2, std::vector<int>());
    for (std::pair<int, int> p : players) {
        if (p.second > 1) continue;
        solution[p.second].push_back(p.first);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
