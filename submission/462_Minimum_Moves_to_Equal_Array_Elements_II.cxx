/*
 * 462_Minimum_Moves_to_Equal_Array_Elements_II.cxx
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

int minMoves2(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int solution = 0;
	for(int i = 0 , j = nums.size()-1;j>i; i++,j--){
		solution+= nums[j] - nums[i];
	}
	return solution;
}

int main(int argc, char **argv)
{
	
	return 0;
}

