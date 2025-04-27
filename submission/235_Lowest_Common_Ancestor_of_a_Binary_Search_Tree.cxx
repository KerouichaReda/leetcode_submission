struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > q->val) std::swap(p, q);
    return helper(root, p, q);
}

TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    return root->val >= p->val && root->val <= q->val ? root : root->val > q->val ? helper(root->left, p, q)
                                                                                  : helper(root->right, p, q);
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
