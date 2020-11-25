/*
 * 617_Merge_Two_Binary_Trees.cxx
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
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if(t1 == nullptr && t2 == nullptr)
		return nullptr;
	if(t1 == nullptr || t2 == nullptr)
		return t1 == nullptr ? t2 : t1;
   
	TreeNode* newNode = new TreeNode(
	( t1->val +  t2->val),
	mergeTrees( t1->left, t2->left),
	mergeTrees( t1->right, t2->right)
	);
	return newNode;  
}
int main(int argc, char **argv)
{
	
	return 0;
}

