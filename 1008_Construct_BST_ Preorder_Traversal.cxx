/*
 * 1008_Construct_BST_ Preorder_Traversal.cxx
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


TreeNode* bstFromPreorder(vector<int>& preorder) {
	int index = 0;
	return  bstFromPreorder_util(preorder, index, INT_MAX );
	
}
TreeNode* bstFromPreorder_util(vector<int>& preorder, int &index ,int highest) {
	if(index >= preorder.size() || preorder[index] > highest){
		return nullptr;
	}
	TreeNode* root = new TreeNode(preorder[index++]);
	root->left = bstFromPreorder_util(preorder, index,root->val);
	root->right = bstFromPreorder_util(preorder, index , highest);         
	return root;
	
}

int main(int argc, char **argv)
{
	
	return 0;
}

