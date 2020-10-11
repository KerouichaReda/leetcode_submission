/*
 * 704_Binary_Search.cxx
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
int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        if(nums.size()==1)
            return(nums[0]==target)?0:-1;
        int index,pr1,pr2,pr3,size;
        index=nums.size()/2;
        size=index;
        pr1=0;
        pr2=nums.size();
        pr3=index;
        while(index >=0 && index<nums.size() && pr1!=pr3)
        {
            pr1=pr2;
            pr2=pr3;
            pr3=index;    
            size = (size+1) / 2;            
            if (nums[index]==target)
            {
                return index;
            }
            
            if (nums[index] < target)
            {
                index = index + size;
            }
            else 
            {
                index = index - size;
            }
           //std::cout<<index<<" "<<size<<std::endl;
        }
        
        return -1;
    }
    
 int binary_search(std::vector<int>& nums, int target) { 
	if(nums.empty())
		return -1;
	if(nums.size()==1)
		return(nums[0]==target)?0:-1; 

	int left,right,number,middle;
	number=nums.size();
	left=0;
	right=number-1;
	while(right>=left){
	middle=(right+left)/2;
		if(nums[middle]>target){
			right=middle-1;
		}
		else if(nums[middle]<target){
			left=middle+1;
		}
		else {
			return middle;
		}
	}
	return -1;
}
int main(int argc, char **argv)
{
	
	return 0;
}

