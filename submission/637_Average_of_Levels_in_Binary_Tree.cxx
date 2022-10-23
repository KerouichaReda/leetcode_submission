#include <iostream>
#include <vector>
#include <functional>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

void averageOfLevels_helper(TreeNode* root,
                            std::vector<std::pair<int, int>>& records,
                            int level = 0) {
    if (root == nullptr) return;
    if (records.size() <= level) records.push_back(std::make_pair(0, 0));
    records[level].first += root->val;
    records[level].second++;
    averageOfLevels_helper(root->left, records, level + 1);
    averageOfLevels_helper(root->right, records, level + 1);
}

std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<std::pair<int, int>> records;
    averageOfLevels_helper(root, records);
    std::vector<double> solution;
    for (std::pair<int, int>& p : records) {
        solution.push_back((double)p.first / p.second);
    }
    return solution;
}