/*
 * 114_Flatten_Binary_Tree_to_Linked_List.cxx
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

void flatten(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    vector<TreeNode*> vec;
    flatten_helper(root, vec);
    for (int i = 0; i < vec.size() - 1; i++) {
        vec[i]->left = nullptr;
        vec[i]->right = vec[i + 1];
    }
}

void flatten_helper(TreeNode* root, vector<TreeNode*>& vec) {
    if (root == nullptr) {
        return;
    }
    vec.push_back(root);
    flatten_helper(root->left, vec);
    flatten_helper(root->right, vec);
}

int main(int argc, char** argv) { return 0; }
