/*
 * 1325_Delete_Leaves_With_a_Given_Value.cxx
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
TreeNode* removeLeafNodes(TreeNode* root,const int &target) {
	if(root == nullptr){
		root = nullptr;
	}else  {
		if(root->left != nullptr){                
			root->left = removeLeafNodes(root->left, target);
		}            
		if(root->right != nullptr){
			root->right = removeLeafNodes(root->right, target);            
		}
	}
	return isLeaf(root,target) ? nullptr : root;        
}    
constexpr bool isLeaf(TreeNode* root,const int &target){
	return root == nullptr ? false : root->left == nullptr && root->right == nullptr && root->val == target;
}
int main(int argc, char **argv)
{
	
	return 0;
}

