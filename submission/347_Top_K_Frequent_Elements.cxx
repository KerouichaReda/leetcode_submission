#include <vector>
#include <map>
#include <unordered_map>
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> counter_;
    std::map<int, std::vector<int>> freq_;
    std::vector<int> solution;
    for (int& e : nums) counter_[e]++;
    for (std::pair<int, int> p : counter_) freq_[p.second].push_back(p.first);
    for (auto itr = freq_.rbegin(), end = freq_.rend(); itr != end && solution.size() < k; ++itr) {
        for (auto i = (*itr).second.begin(), e = (*itr).second.end(); i != e && solution.size() < k; i++) {
            solution.push_back(*i);
        }
    }
    return solution;
}