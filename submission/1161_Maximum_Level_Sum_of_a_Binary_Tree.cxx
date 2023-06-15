#include "treenode.hpp"

#include <vector>

std::vector<int> sum_;

int maxLevelSum(TreeNode* root) {
    int solution{-1};
    int temp_ = std::numeric_limits<int>::min();
    helper(root);
    for (int i = 0, size = sum_.size(); i < size; ++i) {
        if (temp_ < sum_[i]) {
            temp_ = sum_[i];
            solution = i + 1;
        }
    }
    return solution;
}

void helper(TreeNode* root, int level = 0) {
    if (root == nullptr) return;
    if (level >= sum_.size()) {
        sum_.push_back(0);
    }
    sum_[level] += root->val;
    helper(root->left, level + 1);
    helper(root->right, level + 1);
}