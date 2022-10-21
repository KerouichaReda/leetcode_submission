#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <functional>
bool equalFrequency(std::string word) {
    std::unordered_map<uint8_t, int> m, f;
    for (char& c : word) m[c]++;
    for (auto p : m) f[p.second]++;
    if (f.size() == 1) return f.begin()->first == 1 || f.begin()->second == 1;
    if (f.size() == 2) {
        int min = f.begin()->first;
        int max = std::next(f.begin())->first;
        if(min > max) std::swap(min,max);
        return (min + 1 == max && f[max] == 1) || (min == 1 && f[min] == 1);
    }
    return false;
}