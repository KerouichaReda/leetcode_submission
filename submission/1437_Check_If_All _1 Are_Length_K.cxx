/*
 * 1437_Check_If_All _1 Are_Length_K.cxx
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

bool kLengthApart(std::vector<int>& nums, int k) {        
	int p = -1;        
	for (int i = 0 ; i < (int) nums.size();i++){
		if(p < 0 && nums[i]){
			p = i;                
		}else if(nums[i]){
			if(i - p <= k)
				return false;
			p = i;
		}
	}        
	return true ;
}

int main(int argc, char **argv)
{
	std::vector<int> nums = {0,0,0,0,0,1,0,0,1,0,0,0,1};
	int k = 2;
	std::cout << kLengthApart(nums,k) << std::endl;
	
	
	return 0;
}

