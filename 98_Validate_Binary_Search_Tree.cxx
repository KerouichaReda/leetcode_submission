struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    return isGreater(root->left, root->val) &&
           isLesser(root->right, root->val) && isValidBST(root->left) &&
           isValidBST(root->right);
}

bool isGreater(TreeNode* root, const int val) {
    return root == nullptr ? true : root->right == nullptr
                                        ? val > root->val
                                        : isGreater(root->right, val);
}
bool isLesser(TreeNode* root, const int val) {
    return root == nullptr ? true : root->left == nullptr
                                        ? val < root->val
                                        : isLesser(root->left, val);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
