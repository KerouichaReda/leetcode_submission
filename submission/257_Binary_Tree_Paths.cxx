/*
 * 257_Binary_Tree_Paths.cxx
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

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> solution;
    if (root->left == nullptr && root->right == nullptr) {
        solution.push_back(to_string(root->val));
        return solution;
    }
    if (root->left != nullptr) binaryTreePaths_helper(root->left, to_string(root->val), solution);
    if (root->right != nullptr) binaryTreePaths_helper(root->right, to_string(root->val), solution);
    return solution;
}

void binaryTreePaths_helper(TreeNode* root, string s, vector<string>& solution) {
    if (root->left == nullptr && root->right == nullptr) {
        solution.push_back(s + "->" + to_string(root->val));
        return;
    }
    if (root->left != nullptr) binaryTreePaths_helper(root->left, s + "->" + to_string(root->val), solution);
    if (root->right != nullptr) binaryTreePaths_helper(root->right, s + "->" + to_string(root->val), solution);
}

int main(int argc, char** argv) { return 0; }
