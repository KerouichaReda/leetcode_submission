/*
 * 1315_Sum_of_Nodes_with_Even_Valued_Grandparent.cxx
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

int sumEvenGrandparent(TreeNode* root) { return sumEvenGrandparent_util(root, nullptr, nullptr); }
int sumEvenGrandparent_util(TreeNode* root, TreeNode* parent, TreeNode* grand_parent) {
    if (root == nullptr) {
        return 0;
    }
    return sumEvenGrandparent_util(root->left, root, parent) + sumEvenGrandparent_util(root->right, root, parent) +
           ((grand_parent != nullptr && !(grand_parent->val & 1)) ? root->val : 0);
}

int main(int argc, char** argv) { return 0; }
