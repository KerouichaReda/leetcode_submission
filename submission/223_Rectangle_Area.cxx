
#include <algorithm>
#include <functional>
#include <iostream>
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    bool is_overlaped = std::max(ax1, bx1) < std::min(ax2, bx2) && std::max(ay1, by1) < std::min(ay2, by2);
    int rect_a = (ax2 - ax1) * (ay2 - ay1);
    int rect_b = (bx2 - bx1) * (by2 - by1);
    int overlap = (std::min(ax2, bx2) - std::max(ax1, bx1)) * (std::min(ay2, by2) - std::max(ay1, by1));
    return rect_a + rect_b - is_overlaped * overlap;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
