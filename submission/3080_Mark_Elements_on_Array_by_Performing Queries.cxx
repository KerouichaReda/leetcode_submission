#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>

std::vector<long long> unmarkedSumArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    std::map<int, std::vector<int>> m;
    std::set<int> marked;
    std::int64_t sum{0};
    std::vector<long long> solution;
    for (int i = nums.size() - 1; i >= 0; --i) {
        m[nums[i]].push_back(i);
        sum += nums[i];
    };
    for (std::vector<int>& q : queries) {
        int index = q[0];
        int k = q[1];
        if (!marked.count(index)) {
            sum -= nums[index];
            marked.insert(index);
        }
        for (int i = 0; !m.empty() && i < k; i++) {
            int k_index = (*m.begin()).second.back();
            (*m.begin()).second.pop_back();
            if ((*m.begin()).second.empty()) {
                m.erase(m.begin());
            }
            if (marked.count(k_index)) {
                i--;
                continue;
            }
            marked.insert(k_index);
            sum -= nums[k_index];
        }
        solution.push_back(sum);
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
