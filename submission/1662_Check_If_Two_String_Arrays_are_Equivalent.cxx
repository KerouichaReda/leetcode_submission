#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
    return std::accumulate(word1.begin(), word1.end(), std::string{}) ==
           std::accumulate(word2.begin(), word2.end(), std::string{});
}