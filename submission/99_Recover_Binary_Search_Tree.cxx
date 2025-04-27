/*
 * 99_Recover_Binary_Search_Tree.cxx
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
 * https://leetcode.com/problems/recover-binary-search-tree/
 */

#include <iostream>

void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
    if (!root) return;
    markTree(root->left, prev, first, end);
    if (prev) {
        if (root->val < prev->val) {
            if (!first) {
                first = prev;
            }
            end = root;
        }
    }
    prev = root;
    markTree(root->right, prev, first, end);
}
void recoverTree(TreeNode* root) {
    TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
    markTree(root, prev, first, end);
    swap(first->val, end->val);
    return;
}

int main(int argc, char** argv) { return 0; }
