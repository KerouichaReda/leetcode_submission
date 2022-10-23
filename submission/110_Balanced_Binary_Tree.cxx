/*
 * 110_Balanced_Binary_Tree.cxx
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
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

    bool isBalanced(TreeNode* root) {
    if(root!=nullptr){     
            return isBalanced(root->left) and isBalanced(root->right) and std::abs(getHeight(root->left)-getHeight(root->right))<=1;
        }
        return true;
    }
    
int getHeight(TreeNode *root){	
	if(root!=nullptr){		
		return 1+ std::max(getHeight(root->left),getHeight(root->right));
	}
	return 0;
}


int main(int argc, char **argv)
{

	return 0;
}

