#include <iostream>
#include <functional>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode* root, int max_val = INT_MIN) {
    return root == nullptr ? 0 : (root->val >= max_val) + goodNodes(root->left, std::max(root->val, max_val)) +
                                     goodNodes(root->right, std::max(root->val, max_val));
}

int main(int argc, char const* argv[]) {
    TreeNode* root = nullptr;
    std::cout << goodNodes(root) << std::endl;
    return 0;
}
