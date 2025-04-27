/*
 * 153_Find_Minimum_in_Rotated_Sorted_Array.cxx
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

int findMin(std::vector<int>& nums) {
    int left, right, mid;
    left = 0;
    right = nums.size() - 1;
    while (left < right) {
        if (nums[left] < nums[right]) return left;
        mid = (left + right) / 2;
        if (nums[left] <= nums[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3};
    std::cout << findMin(nums) << std::endl;
    return 0;
}
