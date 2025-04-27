/*
 * 965_Univalued_Binary_Tree.cxx
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
#include "treenode.hpp"
bool isUnivalTree(TreeNode* root) { return isSameValue(root, root->val); }
bool isSameValue(TreeNode* root, const int& value) {
    return root != nullptr ? root->val == value && isSameValue(root->left, value) && isSameValue(root->right, value)
                           : true;
}
int main(int argc, char** argv) { return 0; }
