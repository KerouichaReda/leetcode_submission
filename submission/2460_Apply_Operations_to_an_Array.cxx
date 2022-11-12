/*
 * 2460_Apply_Operations_to_an_Array.cxx
 * 
 * Copyright 2022 RedaKerouicha <redakerouicha@localhost>
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
#include <vector>

std::vector<int> applyOperations(std::vector<int>& nums) {
	for(int i = 0 , size = nums.size() - 1 ; i < size ; i++){
		if(nums[i] == nums[i+1]){
			nums[i] *= 2;
			nums[i + 1 ] = 0;
		}            
	}
	int index{0};
	for(int& n : nums){
		if(n) nums[index++] = n; 
	}
	for(int size = nums.size() ; index < size ; index++){
		nums[index] = 0;
	}
	return nums;        
}
int main(int argc, char **argv)
{
	std::vector<int> nums = {1,2,2,1,1,0};
	std::vector<int> vec = applyOperations(nums);
	return 0;
}

