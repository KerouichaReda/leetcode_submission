/*
 * 637_Average_of_Levels_in_Binary_Tree.cxx
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

void averageOfLevelsUtil(TreeNode* root, int level, vector<pair<long,int>> &tree) {
	if(root == nullptr){
		return ;
	}        
	if(level >= tree.size()){             
		tree.push_back(pair<long,int>{});
	}        
	tree[level].first += root->val;  
	tree[level].second++;
	averageOfLevelsUtil( root->left,  level +1 , tree);
	averageOfLevelsUtil( root->right,  level +1 , tree);
}
vector<double> averageOfLevels(TreeNode* root) {        
	vector<double> solution;
	vector<pair<long,int>> tree;
	averageOfLevelsUtil( root,  0 , tree);
	for(pair<long,int> p : tree){
		solution.push_back((double)p.first/p.second);
	}
	return solution;
	
}

int main(int argc, char **argv)
{
	
	return 0;
}

