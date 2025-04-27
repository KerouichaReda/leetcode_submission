/*
 * 655_Print_Binary_Tree.cxx
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
vector<vector<string>> printTree(TreeNode* root) {
    int h = height(root);
    int w = pow(2, h) - 1;
    vector<vector<string>> solution(h, vector<string>(l, ""));
    printTree_util(root, 0, w, 0, solution);
    return solution;
}

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
void printTree_util(TreeNode* root, int left, int right, int depth, vector<vector<string>>& solution) {
    if (root == nullptr) {
        return;
    }
    int mid = (right + left) / 2;
    solution[depth][mid] = to_string(root->val);
    printTree_util(root->left, left, mid - 1, depth + 1, solution);
    printTree_util(root->right, mid + 1, right, depth + 1, solution);
}
int main(int argc, char** argv) { return 0; }
