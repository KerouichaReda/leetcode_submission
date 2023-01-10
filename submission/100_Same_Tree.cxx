// https://leetcode.com/problems/same-tree/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
bool isSameTree(TreeNode* rootP, TreeNode* rootQ) {
    return rootP == nullptr || rootQ == nullptr
               ? rootQ == rootP
               : rootP->val == rootQ->val &&
                     isSameTree(rootP->left, rootQ->left) &&
                     isSameTree(rootP->right, rootQ->right);
}