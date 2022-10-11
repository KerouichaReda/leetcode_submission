string tree2str(TreeNode* root) {
    if (root == nullptr) return std::string{};
    if (root->left == nullptr && root->right == nullptr)
        return to_string(root->val);
    return to_string(root->val) + ((root->right == nullptr)
                                       ? "(" + tree2str(root->left) + ")"
                                       : "(" + tree2str(root->left) + ")(" +
                                             tree2str(root->right) + ")");
}

