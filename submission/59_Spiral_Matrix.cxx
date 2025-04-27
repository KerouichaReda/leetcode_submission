#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    int size = n * n;
    std::vector<std::vector<int>> solution(n, std::vector<int>(n, 0));
    int x{0}, y{0}, dx{0}, dy{1}, temp;
    for (int i = 0; i < size; i++) {
        solution[x][y] = i + 1;
        if (solution[(x + dx + n) % n][(y + dy + n) % n]) {
            temp = dx;
            dx = dy;
            dy = -temp;
        }
        x += dx;
        y += dy;
    }
    return solution;
}

int main() {
    int n = 14;
    std::vector<std::vector<int>> solution{generateMatrix(n)};

    for (std::vector<int> v : solution) {
        for (int e : v) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
