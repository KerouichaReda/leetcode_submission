/*
 * 1302_Deepest_Leaves_Sum.cxx
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


int deepestLeavesSum(TreeNode* root) {
	int sum  = 0 ;
	int max_level = 0;
	deepestLeavesSum_util(root ,0 ,max_level, sum);
	return sum;        
}

void deepestLeavesSum_util(TreeNode* root , int level ,int &max_level, int &sum){
	if(root == nullptr){
		return ;            
	}
	if(level > max_level){
		sum = root->val;
		max_level = level;
	}else if( level == max_level){
		sum+= root->val;
	}
	deepestLeavesSum_util(root->left ,level+1 ,max_level, sum);
	deepestLeavesSum_util(root->right ,level+1 ,max_level, sum);  
} 
int main(int argc, char **argv)
{
	
	return 0;
}

