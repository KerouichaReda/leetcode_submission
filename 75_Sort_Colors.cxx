/*
 * 75_Sort_Colors.cxx
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
 * https://leetcode.com/problems/sort-colors/
 */


#include <iostream>
#include <vector>
#include <algorithm>

void sortColors(std::vector<int>& nums) 
    {
        int begin=0;
        int end=nums.size()-1;
        int max=0,min=2;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=min)
            {
                min=nums[i];
            }
            if(nums[i]>=max)
            {
                max=nums[i];
            }
        }
        if(max>min)
        {
        for(int i=0;i<nums.size();i++)
        {
            //std::cout<<begin<<" "<<end<<std::endl;
            if(nums[i]==max && i<end)
            {
                for(;nums[end]==max && i<end;end--);
                std::swap(nums[i],nums[end]);
                end--;
            }
            if(nums[i]==min)
            {
               // for(;nums[begin]==min;begin++);
                std::swap(nums[i],nums[begin]);
                begin++;
            }   
            }
        }
    }
    


int main(int argc, char **argv)
{
	
	return 0;
}

