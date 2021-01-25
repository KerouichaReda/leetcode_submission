/*
 * 88_Merge_Sorted_Array.cxx
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

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n>0){
        for(int i = 0;i<n ; i++){
            nums1[m+i]=nums2[i];
        }
        
        std::sort(nums1.begin(),nums1.end());
        }
    }

int main(int argc, char **argv)
{
	
	return 0;
}

