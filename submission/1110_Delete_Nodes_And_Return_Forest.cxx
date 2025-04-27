/*
 * 1110_Delete_Nodes_And_Return_Forest.cxx
 *
 * Copyright 2024 - present RedaKerouicha
 * <redakerouicha@kerouicha.reda@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <set>
#include <vector>
#include <iostream>
#include "treenode.hpp"
TreeNode* post_order(TreeNode* root, std::set<int>& s, std::vector<TreeNode*>& solution) {
    if (root == nullptr) return nullptr;
    root->left = post_order(root->left, s, solution);
    root->right = post_order(root->right, s, solution);

    if (s.count(root->val)) {
        if (root->left != nullptr) solution.push_back(root->left);
        if (root->right != nullptr) solution.push_back(root->right);
        return nullptr;
    }
    return root;
}

std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
    std::set<int> s(to_delete.begin(), to_delete.end());
    std::vector<TreeNode*> solution;
    root = post_order(root, s, solution);
    if (root != nullptr) solution.push_back(root);
    return solution;
}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode(1);
    std::vector<TreeNode*> solution = delNodes(root, {1, 2, 3});
    return 0;
}
