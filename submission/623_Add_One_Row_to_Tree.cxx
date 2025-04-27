/*
 * 623_Add_One_Row_to_Tree.cxx
 *
 * Copyright 2021 RedaKerouicha <redakerouicha@localhost>
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

TreeNode* addOneRow(TreeNode* root, int v, int d, int level = 2) {
    if (root == nullptr) return nullptr;
    if (d == 1) {
        root = new TreeNode(v, root, nullptr);
    } else if (d == level) {
        root->left = new TreeNode(v, root->left, nullptr);
        root->right = new TreeNode(v, nullptr, root->right);
    } else {
        root->left = addOneRow(root->left, v, d, level + 1);
        root->right = addOneRow(root->right, v, d, level + 1);
    }
    return root;
}

int main(int argc, char** argv) { return 0; }
