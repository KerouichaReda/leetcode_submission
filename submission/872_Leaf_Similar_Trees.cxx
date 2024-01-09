#include "treenode.hpp"
#include <vector>
#include <iostream>
void helper(TreeNode* root, std::vector<int>& leafs) {
    if (root == nullptr) return;
    helper(root->left, leafs);
    helper(root->right, leafs);
    if (root->left == nullptr && root->right == nullptr) {
        leafs.push_back(root->val);
    }
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::vector<int> l1, l2;
    helper(root1, l1);
    helper(root2, l2);
    return l1 == l2;
}
int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
