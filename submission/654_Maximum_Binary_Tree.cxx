/*
 * 654_Maximum_Binary_Tree.cxx
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

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	return constructMaximumBinaryTree_util(nums,0,nums.size()-1);        
}

TreeNode* constructMaximumBinaryTree_util(vector<int>& nums,int start, int end){
	if(start > end ){
		return nullptr;
	}
	int max_index = start;
	int max_value = 0;        
	for(int i = start ; i <= end ; i++){
		if(nums[i]>max_value){
			max_value = nums[i];
			max_index = i;
		}
	}
	return new TreeNode(nums[max_index],
					  constructMaximumBinaryTree_util(nums,start , max_index-1), 
					  constructMaximumBinaryTree_util(nums,max_index+1 , end));        
}   

int main(int argc, char **argv)
{
	
	return 0;
}

