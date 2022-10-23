/*
 * 543_Diameter_of_Binary_Tree.cxx
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

int height(TreeNode* root, int &solution) {
	if(root == nullptr)
		return 0;
	int L = height(root->left, solution);
	int R = height(root->right, solution);
	solution = max(solution,L+R+1);
	return 1 + max(L,R);
}
int diameterOfBinaryTree(TreeNode* root) {
	int solution = 1 ;
	height(root,solution);
	return solution - 1;  
}


int main(int argc, char **argv)
{
	
	return 0;
}

