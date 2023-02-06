#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> findAnagrams(std::string s, std::string p) {
    if (p.length() > s.length()) {
        return std::vector<int>();
    }
    int p_hist[26] = {};
    int s_hist[26] = {};
    std::vector<int> solution;
    for (char& c : p) {
        p_hist[c - 'a']++;
    }
    for (int i = 0, s_size = s.size(), p_size = p.size(); i < s_size; ++i) {
        if (i < p_size) {
            s_hist[s[i] - 'a']++;
        } else {
            if (std::equal(s_hist, s_hist + 26, p_hist)) {
                solution.push_back(i - p_size);
            }
            s_hist[s[i] - 'a']++;
            s_hist[s[i - p_size] - 'a']--;
        }
    }
    if (std::equal(s_hist, s_hist + 26, p_hist)) {
        solution.push_back(s.size() - p.size());
    }
    return solution;
}