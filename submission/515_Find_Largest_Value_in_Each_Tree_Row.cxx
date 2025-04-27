/*
 * 515_Find_Largest_Value_in_Each_Tree_Row.cxx
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
#include

vector<int> largestValues(TreeNode* root) {
    vector<int> solution;
    largestValues_util(root, 0, solution);
    return solution;
}
void largestValues_util(TreeNode* root, int level, vector<int>& solution) {
    if (root == nullptr) {
        return;
    }
    if (level >= solution.size()) {
        solution.push_back(root->val);
    } else {
        solution[level] = max(solution[level], root->val);
    }
    largestValues_util(root->left, level + 1, solution);
    largestValues_util(root->right, level + 1, solution);
}

int main(int argc, char** argv) { return 0; }
