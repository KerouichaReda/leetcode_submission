/*
 * 26_Remove_Duplicates.cxx
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
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int i = !nums.empty();    
    for (int n : nums)
        if (n > nums[i-1])
            nums[i++] = n;
    return i;
}

int main(int argc, char **argv)
{
	std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
	int result = removeDuplicates(nums);
	
	for(int i=0 ;i<result;++i){
		std::cout<<nums[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}

