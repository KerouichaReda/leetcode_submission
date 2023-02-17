#include "treenode.hpp"
#include <algorithm>

int pre{-1000000};
int solution{1000000};
int minDiffInBST(TreeNode* root) {
    minDiffInBST_util(root);
    return solution;
}
void minDiffInBST_util(TreeNode* root) {
    if (root == nullptr) return;
    minDiffInBST_util(root->left);
    solution = std::min(solution, root->val - pre);
    pre = root->val;
    minDiffInBST_util(root->right);
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
