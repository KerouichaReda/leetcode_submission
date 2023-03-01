#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "treenode.hpp"
std::hash<int> hasher_;
std::unordered_map<std::size_t, std::vector<TreeNode*>> m_;

std::size_t hash_combine(std::size_t seed, std::size_t h) {
    seed ^= h + 0x517cc1b727220a95 + (seed << 6) + (seed >> 2);
    return seed * 3;
}

std::size_t helper(TreeNode* root) {
    if (root == nullptr) return hasher_(-1024);
    std::size_t l = helper(root->left);
    std::size_t v = hasher_(root->val);
    std::size_t r = helper(root->right);
    std::size_t h = hash_combine(hash_combine(l, v), r);
    m_[h].push_back(root);
    return h;
}
std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    std::vector<TreeNode*> solution;
    helper(root);
    for (auto p : m_) {
        if (p.second.size() > 1) {
            solution.push_back(*p.second.begin());
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
