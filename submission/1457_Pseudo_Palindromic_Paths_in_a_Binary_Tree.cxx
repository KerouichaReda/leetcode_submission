#include <iostream>
#include <functional>
#include <algorithm>
#include <unordered_map>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
int helper(TreeNode* root, std::unordered_map<int, int>& m) {
    if (root == nullptr) return 0;

    m[root->val]++;

    if (root->left == nullptr && root->right == nullptr) {
        int sum{0};
        for (std::pair<int, int> p : m) {
            sum += (p.second % 2);
        }
        m[root->val]--;
        return sum < 2;
    }
    int solution = helper(root->left, m) + helper(root->right, m);
    m[root->val]--;
    return solution;
}
int pseudoPalindromicPaths(TreeNode* root) {}