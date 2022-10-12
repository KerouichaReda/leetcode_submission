    struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr && t2 == nullptr)
        return nullptr;  
    
    TreeNode* newNode = new TreeNode(
    (t1 == nullptr ? 0 : t1->val) + (t2 == nullptr ? 0 : t2->val),
    mergeTrees((t1 == nullptr ? nullptr : t1->left) ,(t2 == nullptr ? nullptr : t2->left)),
    mergeTrees((t1 == nullptr ? nullptr : t1->right),(t2 == nullptr ? nullptr : t2->right))
    );
    return newNode;  
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr && t2 == nullptr)
        return nullptr;
    if(t1 == nullptr || t2 == nullptr)
        return t1 == nullptr ? t2 : t1;
    
    TreeNode* newNode = new TreeNode(
    (   t1->val +  t2->val),
        mergeTrees( t1->left , t2->left ),
        mergeTrees( t1->right, t2->right)
    );
    return newNode;  
}