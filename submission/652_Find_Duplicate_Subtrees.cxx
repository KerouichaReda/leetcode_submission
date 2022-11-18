#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "treenode.hpp"
std::unordered_map<int, std::vector<TreeNode*>> m_;
std::unordered_set<TreeNode*> h_;
std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    std::vector<TreeNode*> solution;
    helper(root, solution);
    return solution;
}
void helper(TreeNode* root, std::vector<TreeNode*>& solution) {
    if (root == nullptr) return;
    if (m_.count(root->val)) {
        for (TreeNode* temp : m_[root->val]) {
            if (same_tree(temp, root)) {
                if (!h_.count(temp)) {
                    solution.push_back(root);
                }
                h_.insert(temp);
                h_.insert(root);
            }
        }
    }
    m_[root->val].push_back(root);
    helper(root->left, solution);
    helper(root->right, solution);
}
bool same_tree(TreeNode* root_1, TreeNode* root_2) {
    if (root_1 == nullptr && root_2 == nullptr) return true;
    if (root_1 == nullptr || root_2 == nullptr) return false;
    return root_1->val == root_2->val &&
           same_tree(root_1->left, root_2->left) &&
           same_tree(root_1->right, root_2->right);
}
int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
