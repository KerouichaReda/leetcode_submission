#include <iostream>
#include <vector>
#include <algorithm>

int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    int solution{0};
    for (size_t i = 0, size = seats.size(); ++i) {
        solution += std::abs(seats[i] - students[i]);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
