/*
 * 199_Binary_Tree_Right_Side_View.cxx
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
vector<int> rightSideView(TreeNode* root) {
    vector<int> solution;
    rightSideViewHelper(root, solution, 0);
    return solution;
}
void rightSideViewHelper(TreeNode* root, vector<int>& solution, int level = 0) {
    if (root == nullptr) {
        return;
    }
    if (solution.size() <= level) solution.push_back(root->val);
    rightSideViewHelper(root->right, solution, level + 1);
    rightSideViewHelper(root->left, solution, level + 1);
}
int main(int argc, char** argv) { return 0; }
