#include <vector>
#include <iterator>
#include <iostream>
bool canPlaceFlowers(const std::vector<int>& flowerbed, int n) {
    std::vector<int> temp = {0};
    std::copy(flowerbed.begin(), flowerbed.end(), std::back_inserter(temp));
    temp.push_back(0);
    for (int i = 2, size = temp.size(); i < size && n > 0; ++i) {
        if ((temp[i] + temp[i - 1] + temp[i - 2]) == 0) {
            n--;
            i++;
        }
    }
    return n == 0;
}
int main(int argc, char const* argv[]) {
    std::vector<int> flowerbed = {0};
    std::cout << canPlaceFlowers(flowerbed, 1) << std::endl;
    return 0;
}
