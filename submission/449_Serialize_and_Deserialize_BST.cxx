/*
 * 449_Serialize_and_Deserialize_BST.cxx
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

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (root == nullptr) return "#";
    return to_string(root->val) + "|" + serialize(root->left) + "|" + serialize(root->right) + "|";
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    string intermediate, solution;
    stringstream check(data);
    queue<string> l;
    while (getline(check, intermediate, '|')) {
        if (intermediate != "") l.push(intermediate);
    }
    return deserializeHelper(l);
}
TreeNode* deserializeHelper(queue<string>& l) {
    if (l.empty()) return nullptr;
    if (l.front() == "#") {
        l.pop();
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(l.front()));
    l.pop();
    root->left = deserializeHelper(l);
    root->right = deserializeHelper(l);
    return root;
}

int main(int argc, char** argv) { return 0; }
