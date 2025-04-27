#include <vector>
#include <iostream>
#include <algorithm>

int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
    int size = distance.size();
    int move[2] = {};
    int solution[2] = {};

    for (int i = 0; i < size; ++i) {
        int lr = (start + i) % size;
        int rl = (start - i + size) % size;
        std::cout << distance[lr] << " " << distance[rl] << std::endl;
        move[0] += distance[lr];
        move[1] += distance[rl];
        if (lr == destination) solution[0] = move[0];
        if (rl == destination) solution[1] = move[1];
    }
    return std::min(solution[0], solution[1]);
}

int main(int argc, char const* argv[]) {
    std::vector<int> distance{1, 2, 3, 4};
    int start = 0;
    int destination = 1;
    std::cout << distanceBetweenBusStops(distance, start, destination) << std::endl;

    return 0;
}
