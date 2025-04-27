#include "treenode.hpp"
struct temp {
    temp() {}
    temp(temp left, temp right, int& val)
        : sum(left.sum + right.sum + val),
          count(left.count + right.count + 1),
          solution(left.solution + right.solution + (val == (sum / count))) {}
    int sum{0};
    int count{0};
    int solution{0};
};
int averageOfSubtree(TreeNode* root) { return helper(root).solution; }
temp helper(TreeNode* root) {
    return root == nullptr ? temp() : temp(helper(root->left), helper(root->right), root->val);
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
