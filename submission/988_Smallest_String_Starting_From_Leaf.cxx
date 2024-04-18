#include "treenode.hpp"
#include <string>

std::string smallestFromLeaf(TreeNode* root, std::string temp = "") {
    if (root == nullptr) return temp;
    temp = std::string(1, root->val + 'a') + temp;
    if (root->left == nullptr && root->right == nullptr) return temp;
    std::string l = smallestFromLeaf(root->left, temp);
    std::string r = smallestFromLeaf(root->right, temp);
    return root->left != nullptr && root->right != nullptr
               ? std::min(l, r)
               : root->right != nullptr ? r : l;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
