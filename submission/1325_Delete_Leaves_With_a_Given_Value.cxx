/*
 * 1325_Delete_Leaves_With_a_Given_Value.cxx
 *
 * Copyright 2024 RedaKerouicha <redakerouicha@localhost>
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

#include <iostream>
#include "treenode.hpp"
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (root == nullptr) return root;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    return (root->left == root->right && root->val == target) ? nullptr : root;
}
int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    removeLeafNodes(root, 1);
    return 0;
}
