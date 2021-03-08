/*
 * 31_Next_Permutation.cxx
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
 * https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 */


#include <iostream>

void nextPermutation(vector<int>& nums) {
	int n = nums.size(), k, l;
	for (k = n - 2; k >= 0; k--) {
		if (nums[k] < nums[k + 1]) {
			break;
		}
	}
	if (k < 0) {
		reverse(nums.begin(), nums.end());
	} else {
		for (l = n - 1; l > k; l--) {
			if (nums[l] > nums[k]) {
				break;
			}
		} 
		swap(nums[k], nums[l]);
		reverse(nums.begin() + k + 1, nums.end());
	}
}

int main(int argc, char **argv)
{
	
	return 0;
}

