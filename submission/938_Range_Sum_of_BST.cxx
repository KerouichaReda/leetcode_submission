/*
 * 938_Range_Sum_of_BST.cxx
 *
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
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
#incude "treenode.hpp"

int rangeSumBST(TreeNode* root, int low, int high) {
    return root == nullptr ? 0 : root->val >= low && root->val <= high
                                     ? root->val +
                                           rangeSumBST(root->left, low, high) +
                                           rangeSumBST(root->right, low, high)
                                     : root->val < low
                                           ? rangeSumBST(root->right, low, high)
                                           : rangeSumBST(root->left, low, high);
}

int main(int argc, char** argv) { return 0; }
