/*
 * 590_N-ary_Tree_Postorder_Traversal.cxx
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

vector<int> postorder(Node* root) {
	vector<int> solution;
	postorder_util(root,solution);
	return solution;
}
void postorder_util(Node* root,vector<int> &solution){
	if(root == nullptr)
		return ;        
	for(Node* n : root->children){
		postorder_util(n,solution);
	}
	solution.push_back(root->val);
} 

int main(int argc, char **argv)
{
	
	return 0;
}

