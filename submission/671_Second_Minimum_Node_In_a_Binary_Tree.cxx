/*
 * 671_Second_Minimum_Node_In_a_Binary_Tree.cxx
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

int findSecondMinimumValue(TreeNode* root) {          
	set<int> s;
	queue<TreeNode *> q;
	TreeNode * curr = root;
	q.push(curr);
	while(!q.empty()){
		curr = q.front();
		s.insert(curr->val);
		q.pop();
		if(curr->left != nullptr){
			q.push(curr->left);
		}
		if(curr->right != nullptr){
			q.push(curr->right);
		}
	}
	if(s.size() < 2){
		return -1;
	}
	set<int>::iterator itr = s.begin();
	itr++;
	return *p;        
}

int main(int argc, char **argv)
{
	
	return 0;
}

