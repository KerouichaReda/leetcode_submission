#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root) {
    std::vector<uint64_t> prev;
    uint64_t solution{};
    util(root, solution, prev);
    return solution + 1;
}
void util(TreeNode* root, uint64_t& solution, std::vector<uint64_t>& prev, int level = 0, uint64_t index = 0) {
    if (root == nullptr) return;
    if (level >= prev.size()) {
        prev.push_back(index);
    }
    solution = std::max(solution, index - prev[level]);
    util(root->left, solution, prev, level + 1, index * 2);
    util(root->right, solution, prev, level + 1, index * 2 + 1);
}

int main() { return EXIT_SUCCESS; }
