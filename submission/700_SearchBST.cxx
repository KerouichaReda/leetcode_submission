/*
 * 700_SearchBST.cxx
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

TreeNode* searchBST(TreeNode* root, int val) {
	if(root != nullptr ){
		if(root->val == val)
			return root;
		else if (root->val < val){
			return searchBST(root->right, val) ;
		}
		else {
			return searchBST(root->left, val) ;
		}
	}
	return nullptr;        
}

int main(int argc, char **argv)
{
	
	return 0;
}

