#include "treenode.hpp"

bool evaluateTree(TreeNode* root) {
    return root == nullptr ? true : (root->left == nullptr && root->right == nullptr)
                                        ? root->val == 1
                                        : root->val == 2 ? evaluateTree(root->left) || evaluateTree(root->right)
                                                         : evaluateTree(root->left) && evaluateTree(root->right);
}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode();
    std::cout << evaluateTree(root) << std::endl;
    return 0;
}
