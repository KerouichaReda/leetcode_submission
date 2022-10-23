/*
 * 993_Cousins_in_Binary_Tree.cxx
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

bool isCousins(TreeNode* root, int x, int y) {
	pair<int,int> x_level = height (root,0 ,x, 0);
	pair<int,int> y_level = height (root,0 ,y, 0 );        
	return x_level.first == y_level.first &&  x_level.second != y_level.second;
}
pair<int,int> height (TreeNode* root ,int parent,int val, int level){
	if(root == nullptr){
		return make_pair(-1,parent);
	}
	if(root->val == val ){
		return make_pair(level,parent);
	}
	pair<int,int> left = height (root->left ,root->val,val, level+1) ;
	pair<int,int> right = height (root->right ,root->val,val, level+1) ;
	return (left.first >=0 ) ? left: right;
}

int main(int argc, char **argv)
{
	
	return 0;
}

