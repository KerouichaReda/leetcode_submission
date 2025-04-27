/*
 * 653_Two_Sum_IV.cxx
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

bool findTarget(TreeNode* root, int k) {
    if (root == nullptr) {
        return false;
    }
    return findTarget_helper(root, k, root);  // calling the helper
}
// inorder Travesal and searching for k - root->val in the BST
bool findTarget_helper(TreeNode* temp, int k, TreeNode* root) {
    if (temp == nullptr) {
        return false;
    }
    if (search(root, k - temp->val, temp)) {
        return true;
    }
    return findTarget_helper(temp->left, k, root) || findTarget_helper(temp->right, k, root);
}
// BST search function
bool search(TreeNode* root, int k, TreeNode* current) {
    if (root == nullptr) {
        return false;
    }
    if (current != root && root->val == k) {  // avoiding the current node in the search
        return true;
    }
    return (k < root->val) ? search(root->left, k, current) : search(root->right, k, current);
}

int main(int argc, char** argv) { return 0; }
