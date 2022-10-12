/*
 * 1389_Create_Target_Array_in_the_Given_Order.cxx
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
#include <vector>


std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
   std::vector<int> solution;
	for(int i = 0;(unsigned) i<nums.size() ; i++){
		solution.insert(solution.begin()+index[i],nums[i]);
	}
	
	return solution;
}

int main(int argc, char **argv)
{
	std::vector<int> nums = {0,1,2,3,4};
	std::vector<int> index = {0,1,2,2,1};
	
	std::vector<int> solution  =createTargetArray( nums,index);
	for (int n : solution){
		std::cout << n << " " ;
	}
	std::cout << std::endl;
	return 0;
}

