#include "treenode.hpp"
#include <vector>

std::vector<std::vector<TreeNode*>> tree;
bool isCompleteTree(TreeNode* root) {
    helper(root);
    tree.pop_back();
    int height = tree.size() - 1 ;
    int node_nb = 1;
    for (int i = 0; i < height ; i++, node_nb <<= 1) {
        if (tree[i].size() != node_nb) return false;
        for (TreeNode* node : tree[i]) {
            if (node == nullptr) return false;
        }
    }
    while (tree.back().back() == nullptr) tree.back().pop_back();
    for (TreeNode* node : tree.back()) {
        if (node == nullptr) return false;
    }
    return true;
}
void helper(TreeNode* root, int h = 0) {
    if (h >= tree.size()) {
        tree.push_back(std::vector<TreeNode*>());
    }
    tree[h].push_back(root);
    if (root == nullptr) return;
    helper(root->left, h + 1);
    helper(root->right, h + 1);
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
