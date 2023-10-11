#include <algorithm>
#include <vector>
#include <iostream>

int findContentChildren(std::vector<int>& greed, std::vector<int>& cookies) {
    int solution{0};
    std::sort(greed.begin(), greed.end());
    std::sort(cookies.begin(), cookies.end());
    for (std::size_t i = 0, j = 0, greed_size = greed.size(),
                     cookies_size = cookies.size();
         i < greed_size && j < cookies_size; ++i) {
        while (j < cookies_size && cookies[j++] < greed[i]) {
        }
        solution += cookies[j - 1] >= greed[i];
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    std::vector<int> greed = {1, 2};
    std::vector<int> cookies = {1, 1};
    std::cout << findContentChildren(greed, cookies) << std::endl;
    return 0;
}
