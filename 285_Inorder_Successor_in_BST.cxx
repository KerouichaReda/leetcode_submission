/*
 * 285_Inorder_Successor_in_BST.cxx
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
#include <vector>

#include "treenode.hpp"

TreeNode* inorderSeccessor_util(TreeNode *root, int target,bool &flag){
	if(root == nullptr){
		return nullptr;
	}
	TreeNode * left = inorderSeccessor_util(root->left, target,flag);
	if( left != nullptr)	return left;
	if(flag == true) 		return root;	
	flag = root->val == target	;
	TreeNode * right = inorderSeccessor_util(root->right, target,flag);
	return right;
}

TreeNode* inorderSeccessor(TreeNode *root, int target){
	if(root == nullptr)
	return nullptr;
	bool flag = false; 
	return inorderSeccessor_util(root, target,flag);
	
}

int main(int argc, char **argv)
{
	int size = 5000000;
	std::vector<int> array;
	for(int i = 1 ; i < size ; i++){
		array.push_back(i);
	}
	
	TreeNode * root = createTreeNodeFromSortedArray(array);
	int target = 25698;
	TreeNode * result = inorderSeccessor(root,  target);
	
	
	std::cout << ((result != nullptr) ? result->val : -1) << std::endl;
	
	return 0;
}

