/*
 * 116_Populating_Next_Right_Pointers_in_Each_Node.cxx
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
 * TODO:
 * | | -
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/935195/c-bfs-vs-dfs-solutions-compared-and-explained-90-time-60-space
 *
 */

#include <iostream>
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    // leaving if `root` is empty or has no children
    if (!root || !root->left) return root;
    Node* left = connect(root->left);
    Node* right = connect(root->right);
    while (left) {
        // merging the left and right branch
        left->next = right;
        // moving to the rightmost node on the left branch and the other way around
        left = left->right;
        right = right->left;
    }
    return root;
}

int main(int argc, char** argv) { return 0; }
