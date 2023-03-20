#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    flowerbed.push_back(0);
    flowerbed.insert(flowerbed.begin(), 0);
    for (int i = 2, size = flowerbed.size(); i < size && n > 0; ++i) {
        n -= ((flowerbed[i] + flowerbed[i - 1] + flowerbed[i - 2]) == 0);
        flowerbed[i - 1] |=
            (flowerbed[i] + flowerbed[i - 1] + flowerbed[i - 2]) == 0;
    }
    return n <= 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}