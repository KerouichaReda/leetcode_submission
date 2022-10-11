#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}
TreeNode* helper(std::vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    return new TreeNode(nums[mid], helper(nums, left, mid - 1),
                        helper(nums, mid + 1, right));
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
